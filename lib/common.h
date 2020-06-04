/*
 * contains code that is required by multiple other modules
 */
#ifndef __COMMON__
#define __COMMON__

#include <string.h>

#include "linkedlist.h"

/*
 * A LL used to store arguments given to functions or actions
 */
extern Linked_list *arglist;

/*
 * A function used to make hash of strings
 * Params :
 * s : pointer to the string whose hash is to be calculated
 * Returns : an int representing hash of the string
 */
int __hash_str__(void *s);

/*
 * A function used to compair two strings
 * This is used for hashmap compair function
 * Params : two void pointers which point to strings
 *
 * Returns : 1 if strings are equal
 *           0 if strings are unequal
 */
int __compair__str__(void *a, void *b);

#endif