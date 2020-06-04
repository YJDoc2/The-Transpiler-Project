/*
 * Contains functions for the literal data
 */

#ifndef __LITERAL__
#define __LITERAL__

#include <stdlib.h>

#include "linkedlist.h"
#include "variables.h"

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_literals__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_literals__();

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
void *add_literal(modifier m, type t, char *ident);

/*
 * This function clears the current literals list
 *
 * Params : none
 *
 * Returns : void
 */
void clear_literals();

#endif