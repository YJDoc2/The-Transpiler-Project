/*
 * contains all 'actions' related code
 * Here 'actions' mean a special token/function in the transpiler,which
 * generates different required code in the C file
 */
#include "actions.h"

#define ACT_MAP_INIT_SIZE 20

Hashmap act_map;  // maps action
                  // name (str *, Should not be freed, as its harcoded text) ->
                  // function to be called to generate code
extern Linked_list* arglist;  // Linked list * defined in comman.c used to store
                              // arguments to functions and actions

char* complex_format = "crealf(%s),cimagf(%s)>=0 ? \"+\" : \"\\b\",cimagf(%s)";
char* bool_format = "%s ? \"true\":\"false\"";
/*
 *key for the type str array, check variables.c for definition of this
  char* type_arr[] = {
    "int",  "float", "double", "bool", "float complex",
    "long", "short", "char *", "void",
  };
*/

// Array containing type format specifiers corresponding to the data types
char* type_str_arr[] = {
    "%d", "%f", "%lf", "%s", "%f %s %fi", "%ld", "%hd", "%s", "void",
};
//* Internal Functions

/*
 * This is helper function the the print action
 * This prints the format specifiers corresponding to the Variable/Literal
 */
static void __print_var__(void* v) {
  Variable* var = (Variable*)v;
  // If Variable is RAW and of string type
  if (var->is_raw && var->t == STRING_TYPE) {
    printcode("%s", type_str_arr[var->t]);
    return;
  }
  switch (var->t) {
    case VOID_TYPE:  // Should never be reached, but for safety
      yyerror("cannot print value of variable of type void : %s", var->name);
      break;
    default:  // print the format specifyer corrsponding to the varable type
      printcode("%s ", type_str_arr[var->t]);
      break;
  }
}

/*
 * Print action function
 * This prints the required printf format string and arguments
 * This is the actual function registered to the action 'print' in actmap
 */
static void action_print() {
  printcode("printf(\"");
  // call helper function to print the format specifiers for each argument
  ll_for_each(arglist, __print_var__);

  printcode("\"");  // complete the quotation mark
  ll_link* _t = arglist->start;
  // we could have used another ll_for_each here, but that would have required
  // another helper function, so didn't
  while (_t != NULL) {
    // print a comma anyway, as we require one after format string
    printcode(",");

    Variable* var = (Variable*)_t->data;
    if (var->t == COMPLEX_TYPE) {
      // If its complex type print real and img part seperately,
      // also complex doesn't have a default format specifier
      printcode(complex_format, var->name, var->name, var->name);
    } else if (var->t == BOOL_TYPE) {
      // bool doesn't have a format specifier, so we use string here to be
      // little more helpful
      printcode(bool_format, var->name);
    } else {
      // just print the name of variable, if the value is a literal, then the
      // name it the value as string
      printcode("%s", var->name);
    }
    _t = _t->next;
  }

  printcode(");");    // complete printf bracket
  ll_clear(arglist);  // just clear arglist, as data in arglist are just
                      // pointers to structs in variables/literals which will be
                      // taken care of by respective cleanup functions
  return;
}

/*
 * This is helper function the the input action
 * This prints the format specifiers corresponding to the Variable/Literal
 *
 * Note that unlike print, this will print a distinct scanf for each variable
 * Also this prints non-variable values using distinct printf statements
 *
 * Also this can defien some temporary variables as there is no direct way to
 * scanf bool or complex types
 */
static void __input_var__(void* v) {
  Variable* var = (Variable*)v;
  char* _tempname;  // save place on stack in case a temp var is required
  if (var->m == CONST_TYPE) {
    yyerror("cannot change value of constant variable %s", var->name);
    return;
  }
  // print the value if its raw ,i.e an expression
  if (var->is_raw) {
    if (var->t == COMPLEX_TYPE) {
      // print complex numbers
      printcode("printf(\"%s\",", type_str_arr[COMPLEX_TYPE]);
      printcode(complex_format, var->name, var->name, var->name);
      printcode(");\n");
    } else if (var->t == BOOL_TYPE) {
      // print bool values. this is not done as just %s as one can give !true or
      // something which can be handled correctly this way
      printcode("printf(\"%s\",", type_str_arr[BOOL_TYPE]);
      printcode(bool_format, var->name);
      printcode(");\n");
    } else {
      // for other types its just a simple print statement
      printcode("printf(\"%s \",%s);\n", type_str_arr[var->t], var->name);
    }

    return;
  }
  // The given argument was a variable, so we have to take the input in it
  switch (var->t) {
    case VOID_TYPE:
      yyerror("cannot scan value of variable of type void : %s", var->name);
      break;
    case BOOL_TYPE:
      _tempname = get_temp_var();  // create a temporary var, short is used as
                                   // we only want a 0 or 1
      printcode("short %s = 0;\n", _tempname);  // define the var
      printcode("scanf(\"%%hd\",&%s);\n",
                _tempname);  // take input in that var
      printcode("%s = %s;\n", var->name,
                _tempname);  // assign that var to the original bool var
      free(_tempname);       // delete the temporary var from our memory
      break;
    case COMPLEX_TYPE:
      // One can use two different variables for real and img, to take all
      // required input in a single scanf statement, but to save creating extra
      // temp variables the operation is split in two scanf using same temp var.
      // As scanf is buffered, this should not be that big difference
      _tempname = get_temp_var();                     // make a temp var
      printcode("float %s = 0;\n", _tempname);        // define as float
      printcode("scanf(\"%%f\",&%s);\n", _tempname);  // scan the real part
      printcode("%s = %s;\n", var->name, _tempname);  // assign the real part
      printcode("scanf(\"%%f\",&%s);\n",
                _tempname);  // scan the img part in same var
      printcode("%s += %s*I;\n", var->name,
                _tempname);  // add the img part after multiplying by I
      free(_tempname);       // delete temp var from our memory
      break;
    case STRING_TYPE:
      // No need for '&' as string is basically char *
      printcode("scanf(\"%s\",%s);\n", type_str_arr[var->t], var->name);
      break;
    default:
      // for other variables just normal scanf
      printcode("scanf(\"%s\",&%s);\n", type_str_arr[var->t], var->name);
      break;
  }
}

/*
 * Input action function
 * this prints the required scanf functions for variables in arguments and
 * printf for non-variable arguments
 * This is the actual function registered to the action 'input' in actmap
 */
static void action_input() {
  ll_for_each(arglist, __input_var__);
  ll_clear(arglist);
  return;
}

// exposed Interface function from here
/*
 * Initializes all DS and variables required in this module
 * Must be called before using any other functions in this module
 */
void __init_actions__() {
  act_map =
      make_hashmap(ACT_MAP_INIT_SIZE, __hash_str__,
                   __compair__str__);  // create hashmap, which maps action name
                                       // -> actual action function
  arglist = (Linked_list*)calloc(
      1, sizeof(Linked_list));   // allocate initial memory to arglist
  *arglist = make_linkedlist();  // actually create Linked_list struct
  hm_add(&act_map, "print", action_print);  // add the action function
  hm_add(&act_map, "input", action_input);  // add the action function
  //* if any other action is to be added, add here
}

/*
 * Find if there is an action corresponding to given name
 * Params :
 * s : char * to name of the action to be found
 * Returns : 1 if corresponding action exists
 *           0 if no action is found
 */
int find_action(char* s) {
  // we just have to find if the action exists or not
  if (hm_get(&act_map, s) != NULL) {
    return 1;
  } else {
    return 0;
  }
}

/*
 * Perform action corresponding to given name
 * Note that the actions will clear the arglist after using, if the action
 * exists
 * Params : s : name of the action to be performed
 */
void perform_action(char* s) {
  // get the function pointer corresponding to the name
  void (*action)(void) = hm_get(&act_map, s);
  if (action == NULL) return;  // if action does not exist
  action();                    // call the action function
}

/*
 * internal function to be given to hm_delete
 * as the key is hardcoded string no need to free it,
 * as the value is a function pointer , no need to free it
 */
static inline void __del_hm__(void* a, void* b) { return; }

/*
 * cleans up ,and frees memory that was used by this module
 * Should be called before exiting the program
 */
void __cleanup_actions__() {
  hm_delete(act_map, __del_hm__);  // delete hashmap of actions
  ll_clear(
      arglist);  // clear up the arglist if there are still anything in there
                 // as there are only references to things in arglist, no actual
                 // data, so need to free those so we can use ll_clear
  free(arglist);  // free the memory initially allocated to arglist
}