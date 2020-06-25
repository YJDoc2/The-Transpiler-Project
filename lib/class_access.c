/*
 * This contains Functions related to operations with classes such as checking
 * if it has attribute or checking if the class exists or it has method and
 * verifying calls to it etc.
 */
#include "class_access.h"

#include "expressions.h"
#include "functions.h"

char *mcall_incorrect_arg_num_msg =
    "incorrect %s method call on line %d :\n\texpected %d params as "
    "per method delcaration in %s line %d,but got %d\n\n ";

char *mcall_incorrect_arg_type_msg =
    "incorrect argument type in method call on line %d :\n\tfor "
    "argument %d expected type %s as per declaration in %s line %d, got %s\n\n";
char *mcall_incorrect_arr_msg =
    "incorrect argument type in method call on line %d :\n\tfor "
    "argument %d expected type %s %s as per declaration in %s line %d, got %s "
    "%s\n\n";

char *mcall_incorrect_const_type_msg =
    "incorrect argument type in method call on line %d :\n\tfor "
    "argument %d expected non-const argument as per declaration in %s line %d, "
    "got const.\n\n";

extern Hashmap classmap;
extern char *type_arr[];
/*
 * Checks if the class with given name exits or not
 * Params :
 * name : name of the class to search
 *
 * Returns : true if class with given name exists
 *           false if no such class is declared
 */
bool is_class(char *name) {
  void *t = hm_get(&classmap, name);
  return t != NULL;
}

/*
 * Checks if the given attribute is present in the class or not
 * Params :
 * classname : name of the class to find attribute in
 * attrname : name of attribute to find
 *
 * Returns : pointer to attr if found
 *           NULL if no such attribute is declared in given class
 */
attr *find_attr(char *classname, char *attrname) {
  Class *class = (Class *)hm_get(&classmap, classname);
  if (class == NULL) return NULL;
  Hashmap *attrmap = class->attr;
  void *t = hm_get(attrmap, attrname);
  return (attr *)t;
}

/*
 * Checks if the given method is present in the class or not
 * Params :
 * classname : name of the class to find attribute in
 * methodname : name of method to find
 *
 * Returns : pointer to method if found
 *           NULL if no such method is declared in given class
 */
method *find_method(char *classname, char *methodname) {
  Class *class = (Class *)hm_get(&classmap, classname);
  if (class == NULL) return NULL;
  Hashmap *mmap = class->methods;
  void *t = hm_get(mmap, methodname);
  return (method *)t;
}

/*
 * Creates a variable of class type
 * yyerrors error if the variable is already existing
 * Parmas :
 * m : modifier of variable
 * classname : class of the variable
 * name : name of the variable;
 * is_array : is the variable of array type
 * line : line on which the variable is declared
 *
 * Returns : void
 */
void create_class_var(modifier m, char *classname, char *name, bool is_array,
                      int line) {
  Class *t = (Class *)hm_get(&classmap, classname);
  if (t == NULL) {
    yyerror("No class named %s is found", classname);
    return;
  }
  Variable *v = (Variable *)lookup_var(name);
  if (v != NULL) {
    yyerror("Variable of name %s already declared on line %d", name,
            v->declaration);
    return;
  }
  // CLASS_TYPE is just given as temp placeholder, we overwrite it in class
  // field of enum after creation
  if (is_array) {
    v = add_array(m, CLASS_TYPE, name, line);
  } else {
    v = create_var(m, CLASS_TYPE, name, line);
  }
  v->is_class = true;
  v->t.class = t->name;
}

/*
 * Function to find if a declared variable of a class is assignable or not.
 * value cannot be assigned to a struct if it or any of its members contains
 * const values This recursively checks for any const attributes and if found
 * any, returns false
 *
 * Param :
 * name : name of the class to find if its variable is assignable or not
 *
 * returns : true, if the class variables can be assigned after declaration
 *           false, if the class or its members contain any const members
 */

bool is_assignable_class(char *name) {
  Class *c = (Class *)hm_get(&classmap, name);

  hashpair *iter = c->attr->start;
  hashpair *end = iter + c->attr->size;
  // check for each attribute
  while (iter <= end) {
    if (iter->key != NULL || iter->value != NULL) {
      attr *a = (attr *)iter->value;
      if (a->is_class) {
        // if its a class type attribute check recursively for that class type
        // as we do not allow for variable of a class in itself, this should not
        // go in infinite loop
        bool b = is_assignable_class(a->t.class);
        if (!b) return false;
      } else {
        if (a->m == CONST_TYPE) {
          return false;
        }
      }
    }
    ++iter;
  }
  // as we have checked all attributes, and found none which are const type
  // this is assignable
  return true;
}

/*
 * Function to verify types of argument with method definition.
 *
 * calls yyerror if number of params is any param type is
 * incorrect
 *
 * Params :
 * mname : name of the method to verify
 * m : method structure pointer corresponding to the function
 * lineno : line on which the functioncall is done
 *
 * Returns : 0 if all argument types match
 *           1 : if there is any error in argument type
 */
int verify_method_call(char *mname, method *m, int lineno) {
  int params =
      m->param_list == NULL
          ? 0
          : m->param_list->size;  // if no param_list , no arg is needed

  // different number of arguments means incorrect call
  if (arglist->size != params) {
    yyerror(mcall_incorrect_arg_num_msg, mname, lineno, params, m->decl_file,
            m->declaration, arglist->size);
    return 1;
  }
  // if no param the the call is correct, as we have checked for correct number
  // of args
  if (arglist->size == 0) return 0;
  // check type of each argument
  int argnum = 1;

  ll_link *m_params_itr = m->param_list->start;
  ll_link *arglist_itr = arglist->start;

  while (arglist_itr != NULL) {
    Variable *arg = (Variable *)arglist_itr->data;
    Param *p = (Param *)m_params_itr->data;

    // if types are different incorrect call but check for rest of arg types
    // anyway
    if (p->is_class) {
      // param expects class type
      if (arg->is_class) {
        // we got class type arg
        if (strcmp(p->t.class, arg->t.class) != 0) {
          // the classes of both are not same
          yyerror(mcall_incorrect_arg_type_msg, lineno, argnum, p->t.class,
                  m->decl_file, m->declaration, arg->t.class);
        }
      } else {
        // we got non-class type
        yyerror(mcall_incorrect_arg_type_msg, lineno, argnum, p->t.class,
                m->decl_file, m->declaration, type_arr[arg->t.t]);
      }
    } else {
      // Param expects non-class type
      if (arg->is_class) {
        // we got class type
        yyerror(mcall_incorrect_arg_type_msg, lineno, argnum, type_arr[p->t.t],
                m->decl_file, m->declaration, arg->t.class);
      } else {
        // we got non-class type
        if (p->t.t != arg->t.t && verify_types(p->t.t, arg->t.t)) {
          // we got mis-matching types
          yyerror(mcall_incorrect_arg_type_msg, lineno, argnum,
                  type_arr[p->t.t], m->decl_file, m->declaration,
                  type_arr[arg->t.t]);
        }
      }
    }
    if (p->is_arr != arg->is_arr) {
      yyerror(mcall_incorrect_arr_msg, lineno, argnum,
              p->is_class ? p->t.class : type_arr[p->t.t],
              p->is_arr ? "array" : "", m->decl_file, m->declaration,
              arg->is_class ? arg->t.class : type_arr[arg->t.t],
              arg->is_arr ? "array" : "");
    }
    if (arg->m == CONST_TYPE && p->m != CONST_TYPE) {
      yyerror(mcall_incorrect_const_type_msg, lineno, argnum, m->decl_file,
              m->declaration);
    }

    m_params_itr = m_params_itr->next;
    arglist_itr = arglist_itr->next;

    ++argnum;
  }
  // correct fncall
  return 0;
}

/*
 * A function that return string of the method call with all the arguments etc
 * in it. This is used to get the string to be printed without semicolon
 * Does not clear the arglist
 * yyerrors internal, error if call_var in NULL for non-static method call
 * Params :
 * m: pointer to the fn that is to be printed
 * call_var :in case of non-static method, char * to variable/ value on which
 *            the method is called
 *          can be NULL for static methods
 * Returns : string , memory allocated of the complete
 * function call.
 */
char *get_methodcall_str(method *m, char *call_var) {
  ll_link *iter = arglist->start;
  Variable *var;
  int len = strlen(m->print_name) + 2;  // one for '(' and one for end of string
  // We initially calculate the space required for arr arguments so we can get
  // it in a single calloc call
  while (iter != NULL) {
    var = (Variable *)iter->data;
    len += strlen(var->name) + 1;  // one extra for possible ','
    iter = iter->next;
  }
  if (!m->is_static && call_var == NULL) {
    yyerror(
        "Internal error, trying to print non-static method without the calling "
        "variable");
  }
  if (!m->is_static) {
    len += strlen(call_var) + 2 +
           2;  // 1 for & and 1 for possible ',', 2 for '(' and  ')'
  }
  void *ret = calloc(sizeof(char),
                     len + 2);  // one extra for end of string and one for ')'

  strcat(ret, m->print_name);
  strcat(ret, "(");
  iter = arglist->start;
  if (!m->is_static) {
    strcat(ret, "&(");
    strcat(ret, call_var);
    strcat(ret, ")");
    if (iter != NULL) {
      strcat(ret, ",");
    }
  }
  // Actually copy the argument string to call string
  while (iter != NULL) {
    var = (Variable *)iter->data;
    strcat(ret, var->name);
    if (iter->next != NULL) {  // if there is another arg, put a ','
      strcat(ret, ",");
    }
    iter = iter->next;
  }
  strcat(ret, ")");  // put the closing ')'
  return ret;
}