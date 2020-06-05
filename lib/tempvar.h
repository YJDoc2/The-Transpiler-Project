/*
 * File containing function related to creating temporary variable names that
 * are required to be put in generated code as helper variables
 * eg for input-ing complex or bool etc
 */
#ifndef __TEMPVAR__
#define __TEMPVAR__

#include <stdio.h>
#include <string.h>

/*
 * Function to get a temporary varable name
 *
 * Creates names in __temp(number) format, where (number) is number
 * Params : None
 *
 * Returns : char * to allocated memory, in which the name available for temp
 *           var is stored, and should be freed after use
 */
char* get_temp_var();

#endif