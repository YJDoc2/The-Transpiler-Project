#include "literals.h"

Linked_list literals;

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_literals__() { literals = make_linkedlist(); }

// Helper function for deleting the literals
void __del_literal__(void *v) {
  Variable *var = (Variable *)v;
  free(var->name);
  free(v);
}

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_literals__() { ll_delete(&literals, __del_literal__); }

/*
 * Function to add the literal in the literal list
 *
 * Params :
 * m : modifier of literal to be added usually NONE_TYPE
 * t : type of literal to be added
 * ident : value of the literal in string format, duplicated inside so can be
 *         freed outide
 *
 * Returns : void * to the literal, should be typecasted to Variable * for use
 */
void *add_literal(modifier m, type t, char *ident) {
  char *name =
      strdup(ident);  // MUST duplicate as Parser discards ident ptr after call
  Variable *v = (Variable *)calloc(1, sizeof(Variable));
  v->name = name;
  v->m = m;
  v->t = t;
  v->declaration = 0;
  v->is_raw = true;
  ll_add(&literals, v);
  return (void *)v;
}

/*
 * This function clears the current literals list
 *
 * Params : none
 *
 * Returns : void
 */
void clear_literals() { ll_delete(&literals, __del_literal__); }
