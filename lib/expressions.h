/*
 * Contains functions related to expressions
 */

#ifndef __EXPR__
#define __EXPR__
#include "functions.h"
#include "variables.h"

extern type arg_type, expr_type;

/*
 * initializes all DS required in this module
 * Must be called before any other function call in this module
 */
void __init_expr__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_expr__();

/*
 * A function to push the current arglist pointer and expression type and
 * allocate memory for new arglist
 * This is used while parsing nested function calls eg :
 * fn1 ( fn2 ( fn3 () ),fn4 ( a,b,c ) )
 *
 * Params : none
 * Returns : void
 */
void push_expr_and_args();

/*
 * A function to clear and free the current arglist, and then pop the arglist
 * and expr type that is in the stack
 *
 * Params : none
 * Returns : void
 */
void pop_expr_and_args();

/*
 * Joins all three of given strings.
 * Note that this does not modify or free the input strings, and allocates
 * memory for joined string
 * Used to join expressions by operations sign eg : a +
 * b This will be given "a","+" and "b" and will return "a+b"
 *
 * Params :
 * three pointers to strings to be joined, in order to be joined
 *
 * Returns : concatenated string pointer
 */
char *join(char *, char *, char *);

/*
 * A function to verify if the combining_type type can be  combined with
 * combining_type.
 * This is used for checking compatible types in variable assignments
 * This should be replaced with better implementation
 * Params :
 * combining_with : type to which value is assigned
 * combining_type : type of value to be assigned
 *
 * Returns : 1 if types are incompatible
 *          0 if types can be combined
 *
 */
int verify_types(type combining_with, type combining_type);

#endif