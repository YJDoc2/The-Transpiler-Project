/*
 * This contains functions related to parsing functions
 */
#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include "common.h"
#include "hashmap.h"
#include "linkedlist.h"
#include "parserfn.h"
#include "variables.h"

extern Hashmap fnmap;  // maps function names to function structs

// Structure to store parameter to function in function definition
typedef struct {
  modifier m;
  type t;
  char* name;
  bool is_arr;
} Param;

// Structure to store information about the function such as function name, its
// printname, its ret type and its params
//! TODO explain why printname is required
typedef struct {
  char* print_name;
  Linked_list* param_list;
  int declaration;
  type ret_t;
  modifier ret_m;
} Function;

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_functions__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_functions__();

/*
 * Add Function definition Parameter
 *
 * Params :
 * m : modifier of Param
 * t : type of Param
 * is_arr : is the param of array type
 * param_name : name of param, is duplicated inside so can be freed outside
 *
 * Returns : void
 */
void add_param(modifier m, type t, bool is_arr, char* param_name);

/*
 * Function to add a function structure in fnmap
 *
 * calls yyerror if function is already declared
 *
 * Params :
 * m : function return modifer eg static in static int a(){}
 * t : function return type  eg int in static int a(){}
 *
 * fnname : name to map the function structure, duplicated in function so can be
 *          freed outside
 * printname : name of function that is to be actually printed in generated
 *             code, duplicated in function so can be freed outside
 *  lineno : line on which
 * the function is defined
 *
 * Returns : void
 */
void add_function(modifier m, type t, char* fnname, char* printname,
                  int lineno);

/*
 * A function to print the stating of function definition including the params
 * eg for function 'int a(int k){...}' this will print 'int a(int k){\n'
 * The '{' must be closed from the calling code after printing the statements
 *in the function
 *
 *The function must be already added in fnmap by using add_function
 *
 * Params :
 * name : name of the function to be printed
 *
 * Returns : void
 */
void print_fn_delc(char* name);

/*
 * Function to find Function Structure corrusponding to  given function name
 *
 * Params :
 * fnname : name of function to find
 *
 * Returns : Function pointer corresponding to the given name in fnmap
 */
Function* find_fn(char* fnname);

/*
 * Function to verify types of argument with function definition.
 * The function must be already created with add_function
 *
 * calls yyerror if number of params is any param type is
 * incorrect
 *
 * Params :
 * fnname : name of the function to verify
 * fn : Function structure pointer corresponding to the function
 * lineno : line on which the functioncall is done
 *
 * Returns : 0 if all argument types match
 *           1 : if there is any error in argument type
 */
int verify_call(char* fnname, Function* fn, int lineno);

/*
 * A function that return string of the function call with all the arguments etc
 * in it. This is used to get the string to be printed without semicolon
 * Does not clear the arglist
 * Does not check if the function is declared or not as the function called
 * may as well be C function like printf etc.
 *
 * Params : fnname : name of function
 * to be printed
 *
 * Returns : string , memory allocated of the complete function call.
 *
 */
char* get_fncall_str(char* fnname);

#endif