/*
 * File containing function related to creating temporary variable names that
 * are required to be put in generated code as helper variables
 * eg for input-ing complex or bool etc
 */
#include "tempvar.h"

static int __num = 0;  // number to print in variable name

char* __name = "__temp%d";  // format string for variable name

/*
 * Function to get a temporary varable name
 *
 * Params : None
 *
 * Returns : char * to allocated memory, in which the name available for temp
 *           var is stored, and should be freed after use
 */
char* get_temp_var() {
  char* ret = strdup(__name);
  sprintf(ret, ret, __num);
  ++__num;
  return ret;
}