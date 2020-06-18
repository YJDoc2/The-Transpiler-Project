/*
 * This contains functions related to variables defined in input code
 */

#ifndef __VARIABLES__
#define __VARIABLES__
#include "common.h"
#include "hashmap.h"
#include "stdbool.h"

// Enum for type of variables
typedef enum {
  INT_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  BOOL_TYPE,
  COMPLEX_TYPE,
  LONG_TYPE,
  SHORT_TYPE,
  STRING_TYPE,
  VOID_TYPE,
  CLASS_TYPE
} type;

// Enum for variable modifiers
typedef enum { NONE_TYPE, CONST_TYPE, STATIC_TYPE } modifier;

// Union to store either type or the classname
typedef union type_u {
  type t;
  char *class;
} type_u;

// Structure to store information about the variable
typedef struct {
  bool is_raw;
  char *name;
  type_u t;
  modifier m;
  bool is_arr;
  bool is_class;
  int declaration;
} Variable;

extern Hashmap varmap;  // For global variables, other are stored in scopes

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_vars__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_vars__();

/*
 * A function to create the Variable structure and store it in varmap/ current
 * scope
 * Does not check if the variable is already defined
 * Params :
 * m : modifier of variable to be created
 * t : type of variable to be created
 * ident : name of the variable, duplicated inside,so can be deleted outside
 *        later
 * line : line on which variable is defined
 *
 * Returns : void
 */
Variable *create_var(modifier m, type t, char *ident, int line);

/*
 * Creates the variable if not previously declared  in same scope, otherwise
 * yyerror the error message Does not print the variable
 *
 * Params :
 * m : modifier of variable to be created
 * t : type of variable to be created
 * ident : name of the variable, duplicated inside,so can be deleted outside
 *        later
 * line : line on which variable is defined
 *
 * Returns : void
 */
void add_var(modifier m, type t, char *ident, int line);

/*
 * Creates the variable of array type if not previously declared  in same scope,
 * otherwise yyerror the error message
 * Does not print the variable
 * Params :
 * m : modifier of variable to be created
 * t : type of variable to be created
 * ident : name of the variable, duplicated inside,so can be deleted outside
 *        later
 * line : line on which variable is defined
 *
 * Returns : void
 */
Variable *add_array(modifier m, type t, char *ident, int line);

/*
 * Searches for the given variable name starting from the topmost ( current )
 * scope in scopelist, to the outermost (global) scope which is varmap
 *
 * Params :
 * ident : name of the variable to search for
 *
 * Returns : Pointer to variable if found
 *           NULL pointer if variable was not found
 */
Variable *lookup_var(char *ident);
#endif