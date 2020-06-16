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

void create_class_var(modifier m, char *classname, char *name, bool is_array,
                      int line);

#endif