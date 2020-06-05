/*
 * File containing function related to scope usage in function
 * This allows to set up scope-specific variables etc
 */

#ifndef __SCOPE__
#define __SCOPE__
#include "stack.h"

extern Stack scopelist;

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_scopes__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_scopes__();

/*
 * creates a new scope and puts it to the top of stack
 */
void pushscope();

/*
 * Deletes the topmost scope in stack and sets next scope as the top
 */
void popscope();

#endif