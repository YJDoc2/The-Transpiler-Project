#include "functions.h"

#define FNAMP_INIT_SIZE 50  // initial size for fnmap hashmap

extern char *type_arr[], *mod_arr[];

Hashmap fnmap;

// A temporary LL to store the params of the function declaration
Linked_list* temp_list = NULL;

char* fncall_incorrect_arg_num_msg =
    "incorrect %s function call on line %d :\n\texpected %d params as "
    "per function delcaration in %s line %d,but got %d\n\n ";

char* fncall_incorrect_arg_type_msg =
    "incorrect argument type in function call on line %d :\n\tfor "
    "argument %d expected type %s as per declaration in %s line %d, got %s\n\n";
char* fncall_incorrect_arr_msg =
    "incorrect argument type in function call on line %d :\n\tfor "
    "argument %d expected type %s %s as per declaration in %s line %d, got %s "
    "%s\n\n";

char* fncall_incorrect_const_type_msg =
    "incorrect argument type in function call on line %d :\n\tfor "
    "argument %d expected non-const argument as per declaration in %s line %d, "
    "got const.\n\n";

/*
 * A helper function to delete the paramlist in each Function struct
 */
void __paramlist_del_fn__(void* a) {
  Param* p = (Param*)a;
  if (p->is_class) {
    free(p->t.class);
  }
  free(p->name);
  free(a);
}

/*
 * A helper function to delete fnmap
 */
void __fnmap_del_fn__(void* a, void* b) {
  free(a);  // free the key,which is char * to name
  Function* f = (Function*)b;
  free(f->print_name);  // free the name which is actually to be printed in
                        // generated code
  if (f->param_list != NULL) {  // if it had any params, free the paramlist
    ll_delete(f->param_list, __paramlist_del_fn__);
  }
  if (f->is_ret_class) {
    free(f->ret_t.class);
  }
  free(f->param_list);  // free the memory allocated to paramlist LL struct
  free(b);              // free the memory allocated to Function struct
  return;
}

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_functions__() {
  fnmap = make_hashmap(50, __hash_str__, __compair__str__);
}
/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_functions__() {
  hm_delete(fnmap, __fnmap_del_fn__);
  if (temp_list != NULL) {  // if templist has anything
    ll_delete(temp_list, __paramlist_del_fn__);
    free(temp_list);
  }
}

/*
 * Add Function definition Parameter
 *
 * Params :
 * m : modifier of Param
 * t : type of Param
 * is_arr : is the param of array type
 * param_name : name of params, is duplicated inside so can be freed outside
 *
 * Returns : void
 */
void add_param(modifier m, type t, bool is_arr, char* param_name) {
  // in case this is the first parameter of the function, temp_list will be null
  // so allocate memory and make the LL
  if (temp_list == NULL) {
    temp_list = calloc(1, sizeof(Linked_list));
    *temp_list = make_linkedlist();
  }
  Param* p = calloc(1, sizeof(Param));
  p->is_class = false;
  p->m = m;
  p->t.t = t;
  p->name = strdup(param_name);
  p->is_arr = is_arr;
  ll_add(temp_list, p);
  return;
}

/*
 * Adds function definition parameter of class type
 * Params :
 * m : modifier of paramis duplicated inside so can be freed outside
 * classname : name of the class, is duplicated inside so can be freed outside
 * is_arr : is the param of array type
 * param_name : name of param, is duplicated inside so can be freed outside
 *
 * returns : void
 */
void add_class_param(modifier m, char* classname, bool is_arr,
                     char* param_name) {
  // in case this is the first parameter of the function, temp_list will be null
  // so allocate memory and make the LL
  if (temp_list == NULL) {
    temp_list = calloc(1, sizeof(Linked_list));
    *temp_list = make_linkedlist();
  }
  Param* p = calloc(1, sizeof(Param));
  p->m = m;
  p->is_class = true;
  p->t.class = strdup(classname);
  p->name = strdup(param_name);
  p->is_arr = is_arr;
  ll_add(temp_list, p);
  return;
}

/*
 * Function to add a function structure in fnmap
 *
 * calls yyerror if function is already declared
 *
 * Params :
 * m : function return modifer eg static in static int a(){}
 * t : function return type  eg int in static int a(){}
 *
 * fnname : name to map the function structure, duplicated in function so can be
 *          freed outside
 * printname : name of function that is to be actually printed in generated
 *             code, duplicated in function so can be freed outside
 *  lineno : line on which
 * the function is defined
 *
 * Returns : void
 */
void add_function(modifier m, type t, char* fnname, char* printname,
                  int lineno) {
  void* fn = hm_get(&fnmap, fnname);
  if (fn != NULL) {  // if function is already declared
    yyerror(
        "Redefination of function %s on line %d : previously defined on line "
        "%d",
        printname, yylineno, ((Function*)fn)->declaration);
    return;
  }
  Function* f = calloc(1, sizeof(Function));
  f->declaration = lineno;
  // set param_list pointer to memory allocated to templist
  f->param_list = temp_list;
  temp_list = NULL;  // clear the templist itself to NULL
  f->is_ret_class = false;
  f->print_name = strdup(printname);
  f->ret_t.t = t;
  f->ret_m = m;
  f->decl_file = crr_file_name;  // as this points to entry in filenames list,
                                 // this should be valid until end of program
  hm_add(&fnmap, strdup(fnname), f);
}

/*
 * Function to add a function with return type of class
 *
 * calls yyerror if function is already declared
 *
 * Params :
 * m : function return modifer eg static in static int a(){}
 * classname: name of class the function returns, duplicated inside, so can be
 *            freed after call
 *
 * fnname : name to map the function structure, duplicated in function so can be
 *          freed outside
 * printname : name of function that is to be actually printed in generated
 *             code, duplicated in function so can be freed outside
 * lineno : line on which
 * the function is defined
 *
 * Returns : void
 */
void add_class_ret_function(modifier m, char* classname, char* fnname,
                            char* printname, int lineno) {
  void* fn = hm_get(&fnmap, fnname);
  if (fn != NULL) {  // if function is already declared
    yyerror(
        "Redefination of function %s on line %d : previously defined on line "
        "%d",
        printname, yylineno, ((Function*)fn)->declaration);
    return;
  }
  Function* f = calloc(1, sizeof(Function));
  f->declaration = lineno;
  // set param_list pointer to memory allocated to templist
  f->param_list = temp_list;
  temp_list = NULL;  // clear the templist itself to NULL
  f->is_ret_class = true;
  f->print_name = strdup(printname);
  f->ret_t.class = strdup(classname);
  f->ret_m = m;
  f->decl_file = crr_file_name;  // as this points to entry in filenames list,
                                 // this should be valid until end of program
  hm_add(&fnmap, strdup(fnname), f);
}

// Helper function to print a single Param in function declaration
static inline void print_param(Param* p) {
  printcode("%s %s %s", mod_arr[p->m],
            p->is_class ? p->t.class : type_arr[p->t.t], p->name);
  if (p->is_arr) {
    printcode("[] ");
  } else {
    printcode(" ");
  }
}

/*
 * Helper function to print parameters of the function in function declarations
 *
 */
static void print_params(Linked_list* paramlist) {
  // if function does not take any Param paramlist will be empty
  if (paramlist == NULL) return;

  ll_link* iter = paramlist->start;

  // print first param, this is done outside the loop as after this each param
  // must be preceeded with a ','
  print_param((Param*)iter->data);
  // if function has only one param
  if (iter->next == NULL) return;
  iter = iter->next;
  // print rest of the prams
  while (iter != NULL) {
    printcode(",");
    print_param((Param*)iter->data);
    iter = iter->next;
  }
  return;
}

/*
 * A function to print the stating of function definition including the params
 * eg for function 'int a(int k){...}' this will print 'int a(int k){\n'
 * The '{' must be closed from the calling code after printing the statements in
 *the function
 *
 *The function must be already added in fnmap by using add_function
 *
 * Params :
 * name : name of the function to be printed
 *
 * Returns : void
 */
void print_fn_delc(char* name) {
  Function* f = (Function*)hm_get(&fnmap, name);
  if (f == NULL) {
    yyerror(
        "Internal Error : trying to print declration of non-existent "
        "function %s\n",
        name);
    return;
  }
  // start by printing return modifier, return type , function name and '('
  printcode("%s %s %s ( ", mod_arr[f->ret_m],
            f->is_ret_class ? f->ret_t.class : type_arr[f->ret_t.t],
            f->print_name);
  // print param list
  print_params(f->param_list);
  // close the '(' bracket and open '{' this must be closed after printing
  // statements in the function from the calling code
  printcode(" ) {");
  return;
}

/*
 * Function to find Function Structure corrusponding to  given function name
 *
 * Params :
 * fnname : name of function to find
 *
 * Returns : Function pointer corresponding to the given name in fnmap
 */
Function* find_fn(char* fnname) { return (Function*)hm_get(&fnmap, fnname); }

/*
 * Function to verify types of argument with function definition.
 * The function must be already created with add_function
 *
 * calls yyerror if number of params is any param type is
 * incorrect
 *
 * Params :
 * fnname : name of the function to verify
 * fn : Function structure pointer corresponding to the function
 * lineno : line on which the functioncall is done
 *
 * Returns : 0 if all argument types match
 *           1 : if there is any error in argument type
 */
int verify_call(char* fnname, Function* fn, int lineno) {
  int params =
      fn->param_list == NULL
          ? 0
          : fn->param_list->size;  // if no param_list , no arg is needed

  // different number of arguments means incorrect call
  if (arglist->size != params) {
    yyerror(fncall_incorrect_arg_num_msg, fnname, lineno, params, fn->decl_file,
            fn->declaration, arglist->size);
    return 1;
  }
  // if no param the the call is correct, as we have checked for correct number
  // of args
  if (arglist->size == 0) return 0;
  // check type of each argument
  int argnum = 1;

  ll_link* fn_params_itr = fn->param_list->start;
  ll_link* arglist_itr = arglist->start;

  while (arglist_itr != NULL) {
    Variable* arg = (Variable*)arglist_itr->data;
    Param* p = (Param*)fn_params_itr->data;

    // if types are different incorrect call but check for rest of arg types
    // anyway
    if (p->is_class) {
      // param expects class type
      if (arg->is_class) {
        // we got class type arg
        if (strcmp(p->t.class, arg->t.class) != 0) {
          // the classes of both are not same
          yyerror(fncall_incorrect_arg_type_msg, lineno, argnum, p->t.class,
                  fn->decl_file, fn->decl_file, fn->declaration, arg->t.class);
        }
      } else {
        // we got non-class type
        yyerror(fncall_incorrect_arg_type_msg, lineno, argnum, p->t.class,
                fn->decl_file, fn->declaration, type_arr[arg->t.t]);
      }
    } else {
      // Param expects non-class type
      if (arg->is_class) {
        // we got class type
        yyerror(fncall_incorrect_arg_type_msg, lineno, argnum, type_arr[p->t.t],
                fn->decl_file, fn->declaration, arg->t.class);
      } else {
        // we got non-class type
        if (p->t.t != arg->t.t) {
          // we got mis-matching types
          yyerror(fncall_incorrect_arg_type_msg, lineno, argnum,
                  type_arr[p->t.t], fn->decl_file, fn->decl_file,
                  fn->declaration, type_arr[arg->t.t]);
        }
      }
    }
    if (p->is_arr != arg->is_arr) {
      yyerror(fncall_incorrect_arr_msg, lineno, argnum,
              p->is_class ? p->t.class : type_arr[p->t.t],
              p->is_arr ? "array" : "", fn->decl_file, fn->declaration,
              arg->is_class ? arg->t.class : type_arr[arg->t.t],
              arg->is_arr ? "array" : "");
    }
    if (arg->m == CONST_TYPE && p->m != CONST_TYPE) {
      yyerror(fncall_incorrect_const_type_msg, lineno, argnum, fn->declaration);
    }

    fn_params_itr = fn_params_itr->next;
    arglist_itr = arglist_itr->next;

    ++argnum;
  }
  // correct fncall
  return 0;
}

/*
 * A function that return string of the function call with all the arguments etc
 * in it. This is used to get the string to be printed without semicolon
 * Does not clear the arglist
 * Does not check if the function is declared or not as the function called may
 * as well be C function like printf etc.
 *
 * Params : fnname : name of function to be
 * printed
 *
 * Returns : string , memory allocated of the complete function call.
 *
 */
char* get_fncall_str(char* fnname) {
  ll_link* iter = arglist->start;
  Variable* var;
  int len = strlen(fnname) + 2;  // one for '(' and one for end of string
  // We initially calculate the space required for arr arguments so we can get
  // it in a single calloc call
  while (iter != NULL) {
    var = (Variable*)iter->data;
    len += strlen(var->name) + 1;  // one extra for possible ','
    iter = iter->next;
  }
  void* ret =
      calloc(1, len + 2);  // one extra for end of string and one for ')'

  strcat(ret, fnname);
  strcat(ret, "(");

  iter = arglist->start;
  // Actually copy the argument string to call string
  while (iter != NULL) {
    var = (Variable*)iter->data;
    strcat(ret, var->name);
    if (iter->next != NULL) {  // if there is another arg, put a ','
      strcat(ret, ",");
    }
    iter = iter->next;
  }
  strcat(ret, ")");  // put the closing ')'
  return ret;
}
