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

/*
 * Function to verify types of argument with method definition.
 *
 * calls yyerror if number of params is any param type is
 * incorrect
 *
 * Params :
 * mname : name of the method to verify
 * m : method structure pointer corresponding to the function
 * lineno : line on which the functioncall is done
 *
 * Returns : 0 if all argument types match
 *           1 : if there is any error in argument type
 */
int verify_method_call(char *mname, method *m, int lineno);

/*
 * A function that return string of the method call with all the arguments etc
 * in it. This is used to get the string to be printed without semicolon
 * Does not clear the arglist
 * yyerrors internal, error if call_var in NULL for non-static method call
 * Params :
 * m: pointer to the fn that is to be printed
 * call_var :in case of non-static method, char * to variable/ value on which
 *            the method is called
 *          can be NULL for static methods
 * Returns : string , memory allocated of the complete
 * function call.
 */
char *get_methodcall_str(method *m, char *call_var);

#endif