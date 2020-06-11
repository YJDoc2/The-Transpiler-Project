/*
 * Contains function related to printing of for loops
 */
#include "forloop.h"

#include "tempvar.h"
/*
 * This function print loop of the format : for i in a..b{...}
 * increments loopvar in steps of 1
 * Params :
 * loopvar : variable that will iterate through the range
 * start : start of range
 * end : end of range
 * t : type of the loopvar, must be of INT_TYPE or FLOAT_TYPE
 *
 * This should print :
 * for(type loopvar = start;start<end ? loopvar<end:loopvar>end;start <end ?
 * ++loopvar : --loopvar ){
 */
void print_simple_range_loop(char *loopvar, char *start, char *end, type t) {
  printcode(
      "for(%s %s = %s; %s < %s ? %s < %s : %s > %s ; %s < %s ? ++%s : --%s){",
      type_arr[t], loopvar, start, start, end, loopvar, end, loopvar, end,
      start, end, loopvar, loopvar);
}

/*
 * This function print loop of the format : for i in a..b..c{...}
 * Params :
 * loopvar : variable that will iterate through the range
 * start : start of range
 * end : end of range
 * step : steps to increment loop var in
 * t : type of the loopvar, must be of INT_TYPE or FLOAT_TYPE
 *
 *
 * This should print :
 * for(type loopvar = start;start<end ? loopvar<end:loopvar>end;start <end ?
 * loopvar += step : loopvar -= step)
 *
 */
void print_step_range_loop(char *loopvar, char *start, char *end, char *step,
                           type t) {
  printcode(
      "for(%s %s = %s ; %s < %s ? %s < %s : %s > %s ; %s += (%s < %s ? %s : "
      "-%s)){",
      type_arr[t], loopvar, start, start, end, loopvar, end, loopvar, end,
      loopvar, start, end, step, step);
}

/*
 * This function prints loop of format : for i in a, where a is an array
 * Params :
 * loopvar : variable that will store the values in array
 * array : name of the array to iterate through
 * t : type of array
 *
 * this should print :
 * for(int temp =0,;temp < sizeof(array)/sizeof(array[0]);++temp){
 *      type loopvar = array[temp];
 */
void print_array_loop(char *loopvar, char *array, type t) {
  char *temp = get_temp_var();
  printcode(
      "for(int %s = 0; %s < (sizeof(%s)/sizeof(%s[0]));++%s){\n\t%s %s = "
      "%s[%s];",
      temp, temp, array, array, temp, type_arr[t], loopvar, array, temp);
  free(temp);
}

/*
 * This function prints loop of format : for i in a, where a is an array
 * Params :
 * indexvar : variable that will store the indices
 * valvar : variable that will store the values in array
 * array : name of the array to iterate through
 * t : type of array
 *
 * this should print :
 * for(int indexvar =0; indexvar<sizeof(array)/sizeof(array[0]);
 * ++indexvar){
 *  type valvar = array[indexvar]
 */
void print_enumeration_loop(char *indexvar, char *valvar, char *array, type t) {
  printcode(
      "for(int %s = 0 ; %s < (sizeof(%s)/sizeof(%s[0]));++%s){\n\t%s %s = "
      "%s[%s];",
      indexvar, indexvar, array, array, indexvar, type_arr[t], valvar, array,
      indexvar);
}