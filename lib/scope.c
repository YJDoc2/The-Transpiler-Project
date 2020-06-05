/*
 * File containing function related to scope usage in function
 * This allows to set up scope-specific variables etc
 */

#include "scope.h"

#include <stdlib.h>

#include "common.h"
#include "hashmap.h"
#include "variables.h"

// Keep this a prime as it usually lessens the number of collisions occuring
// largest prime below 100
#define SCOPE_INIT_SIZE 97

Stack scopelist;  // stack of hashmaps, which contains varables in respective
                  // scope

// Helper function to delete the scope
void __del_scope__(void *a, void *b) {
  free(a);
  free(b);  // be is a Variable *
  // We do not free the b->name, as that and key (a) is the same.
}

// helper function to delete scope
void __scopelist_del_fn__(void *a) {
  Hashmap *hm = (Hashmap *)a;
  hm_delete(*hm, __del_scope__);
  free(a);
}

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_scopes__() { scopelist = make_stack(); }

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_scopes__() { st_delete(&scopelist, __scopelist_del_fn__); }

/*
 * creates a new scope and puts it to the top of stack
 */
void pushscope() {
  Hashmap *hm = calloc(1, sizeof(Hashmap));
  *hm = make_hashmap(SCOPE_INIT_SIZE, __hash_str__, __compair__str__);
  st_push(&scopelist, hm);
}

/*
 * Deletes the topmost scope in stack and sets next scope as the top
 */
void popscope() {
  Hashmap *hm = (Hashmap *)st_pop(&scopelist);
  hm_delete(*hm, __del_scope__);
  free(hm);
}