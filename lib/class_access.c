/*
 * This contains Functions related to operations with classes such as checking
 * if it has attribute or checking if the class exists or it has method and
 * verifying calls to it etc.
 */
#include "class_access.h"

extern Hashmap classmap;
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