/*
 * This contains Functions related to operations with classes such as checking
 * if it has attribute or checking if the class exists or it has method and
 * verifying calls to it etc.
 */
#include "class_decl.h"
#ifndef __CLASS_ACCESS__
#define __CLASS_ACCESS__

/*
 * Checks if the class with given name exits or not
 * Params :
 * name : name of the class to search
 *
 * Returns : true if class with given name exists
 *           false if no such class is declared
 */
bool is_class(char *name);

/*
 * Checks if the given attribute is present in the class or not
 * Params :
 * classname : name of the class to find attribute in
 * attrname : name of attribute to find
 *
 * Returns : pointer to attr if found
 *           NULL if no such attribute is declared in given class
 */
attr *find_attr(char *classname, char *attrname);

/*
 * Checks if the given method is present in the class or not
 * Params :
 * classname : name of the class to find attribute in
 * methodname : name of method to find
 *
 * Returns : pointer to method if found
 *           NULL if no such method is declared in given class
 */
method *find_method(char *classname, char *methodname);

/*
 * Creates a variable of class type
 * yyerrors error if the variable is already existing
 * Parmas :
 * m : modifier of variable
 * classname : class of the variable
 * name : name of the variable;
 * is_array : is the variable of array type
 * line : line on which the variable is declared
 *
 * Returns : void
 */
void create_class_var(modifier m, char *classname, char *name, bool is_array,
                      int line);

/*
 * Function to find if a declared variable of a class is assignable or not.
 * value cannot be assigned to a struct if it or any of its members contains
 * const values This recursively checks for any const attributes and if found
 * any, returns false
 *
 * Param :
 * name : name of the class to find if its variable is assignable or not
 *
 * returns : true, if the class variables can be assigned after declaration
 *           false, if the class or its members contain any const members
 */
bool is_assignable_class(char *name);

#endif