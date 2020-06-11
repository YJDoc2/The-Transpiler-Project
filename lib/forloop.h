/*
 * Contains function related to printing of for loops
 */
#include "parserfn.h"
#include "variables.h"
extern char *type_arr[];
#ifndef __FOORLOOP__
#define __FORLOOP__

/*
 * This function print loop of the format : for i in a..b{...}
 * increments loopvar in steps of 1
 * Params :
 * loopvar : variable that will iterate through the range
 * start : start of range
 * end : end of range
 * t : type of the loopvar, must be of INT_TYPE or FLOAT_TYPE
 */
void print_simple_range_loop(char *loopvar, char *start, char *end, type t);

/*
 * This function print loop of the format : for i in a..b..c{...}
 * Params :
 * loopvar : variable that will iterate through the range
 * start : start of range
 * end : end of range
 * step : steps to increment loop var in
 * t : type of the loopvar, must be of INT_TYPE or FLOAT_TYPE
 *
 * returns : void
 */
void print_step_range_loop(char *loopvar, char *start, char *end, char *step,
                           type t);

/*
 * This function prints loop of format : for i in a, where a is an array
 * Params :
 * loopvar : variable that will store the values in array
 * array : name of the array to iterate through
 * t : type of array
 *
 * returns : void
 */
void print_array_loop(char *loopvar, char *array, type t);

/*
 * This function prints loop of format : for i in a, where a is an array
 * Params :
 * indexvar : variable that will store the indices
 * valvar : variable that will store the values in array
 * array : name of the array to iterate through
 * t : type of array
 *
 * returns : void
 */
void print_enumeration_loop(char *indexvar, char *valvar, char *array, type t);

#endif
