/*
 * This contains functions related to variables defined in input code
 */
#include "variables.h"

#include <string.h>

#include "parserfn.h"
#include "scope.h"

// Keep this a prime as it usually lessens the number of collisions occuring
// Largest prime below 250
#define VAR_HM_INIT_SIZE 241

//! The order MUST be same as the order of types in the type enum
char* type_arr[] = {"int",  "float", "double", "bool", "float complex",
                    "long", "short", "char *", "void", "class"};

//! The order MUST be same as the order of modifiers in the modifier enum
char* mod_arr[] = {"", "const", "static"};

// For global variables, other are stored in scopes
Hashmap varmap;  // stores variable name -> Variable struct *

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_vars__() {
  varmap = make_hashmap(VAR_HM_INIT_SIZE, __hash_str__, __compair__str__);
}

// helper function to delete the variables in varmap
void __del_var__(void* a, void* b) {
  free(a);
  free(b);  // b is Variable *
  // We do not free the b->name, as that and key (a) is the same.
}

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_vars__() { hm_delete(varmap, __del_var__); }

/*
 * A function to create the Variable structure and store it in varmap/ current
 * scope
 * Does not check if the variable is already defined
 * Params :
 * m : modifier of variable to be created
 * t : type of variable to be created
 * ident : name of the variable, duplicated inside,so can be deleted outside
 *        later
 * line : line on which variable is defined
 *
 * Returns : Pointer to created variable
 */
Variable* create_var(modifier m, type t, char* ident, int line) {
  char* _name =
      strdup(ident);  // MUST duplicate as Parser discards ident ptr after call
  Variable* v = (Variable*)calloc(1, sizeof(Variable));
  v->name = _name;
  v->m = m;
  v->t.t = t;
  v->declaration = line;
  v->is_raw = false;
  v->is_arr = false;
  // If there is no current scope, variable is global so store in varamp, else
  // store it in the current scope
  Hashmap* hm = scopelist.top == NULL ? &varmap : (Hashmap*)scopelist.top->data;
  hm_add(hm, _name, v);
  return v;
}

/*
 * Creates the variable if not previously declared in same scope, otherwise
 * yyerror the error message Does not print the variable
 *
 * Params :
 * m : modifier of variable to be created
 * t : type of variable to be created
 * ident : name of the variable, duplicated inside,so can be deleted outside
 *        later
 * line : line on which variable is defined
 *
 * Returns : void
 */
void add_var(modifier m, type t, char* ident, int line) {
  Hashmap* hm = scopelist.top == NULL ? &varmap : (Hashmap*)scopelist.top->data;
  Variable* look = hm_get(hm, ident);
  if (look == NULL) {
    create_var(m, t, ident, line);
  } else {
    yyerror("Variable %s already delcared on line %d", ident,
            look->declaration);
  }
}

/*
 * Creates the variable of array type if not previously declared  in same scope,
 * otherwise yyerror the error message Does not print the variable
 *
 * Params :
 * m : modifier of variable to be created
 * t : type of variable to be created
 * ident : name of the variable, duplicated inside,so can be deleted outside
 *        later
 * line : line on which variable is defined
 *
 * Returns : Pointer to created variable
 */
Variable* add_array(modifier m, type t, char* ident, int line) {
  Hashmap* hm = scopelist.top == NULL ? &varmap : (Hashmap*)scopelist.top->data;
  Variable* look = hm_get(hm, ident);
  if (look == NULL) {
    create_var(m, t, ident, line);
    look = (Variable*)hm_get(hm, ident);
    look->is_arr = true;

  } else {
    yyerror("Variable %s already delcared on line %d", ident,
            look->declaration);
  }
  return look;
}

/*
 * Searches for the given variable name starting from the topmost ( current )
 * scope in scopelist, to the outermost (global) scope which is varmap
 *
 * Params :
 * ident : name of the variable to search for
 *
 * Returns : Pointer to variable if found
 *           NULL pointer if variable was not found
 */
Variable* lookup_var(char* ident) {
  stack_link* _sc = scopelist.top;
  void* look = NULL;

  // start searching in scopes stack from the top
  while (_sc != NULL && look == NULL) {
    Hashmap* hm = (Hashmap*)_sc->data;
    look = hm_get(hm, ident);
    if (look != NULL) break;  // break if the variable is found
    _sc = _sc->next;
  }
  // if variable is not found in any of the scopes, search in global and return
  // the result
  if (look == NULL) look = hm_get(&varmap, ident);
  return (Variable*)look;
}
