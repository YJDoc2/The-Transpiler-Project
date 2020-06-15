#ifndef __CLASSES__
#define __CLASSES__

#include "hashmap.h"
#include "linkedlist.h"
#include "parserfn.h"
#include "variables.h"

extern Hashmap classmap;

typedef struct {
  modifier m;
  type t;
  char* name;
  bool is_arr;
  int declaration;
} attr;

typedef struct {
  char* name;
  Hashmap* methods;
  Hashmap* attr;
  int declaration;
} Class;

typedef struct {
  char* print_name;
  Linked_list* param_list;
  type ret_t;
  bool is_static_method;
  int declaration;
} method;

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_classes__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_classes__();

/*
 * Function to create and add a class struct in classmap
 * gives error is class already exists
 * Params :
 * name : name of the class
 * Returns : Pointer to the new class
 */
Class* add_class(char* name, int line);

/*
 * Function to add an attribute in the class
 * Gives error is the attribute already exists
 * NOTE the modifier must only be NONE_TYPE of CONST_TYPE, static must not be
 * used.
 *  Params :
 * class : pointer to the class m : modifier of the attribute
 * m : modifier of the attr, must be either NONE_TYPE or CONST_TYPE
 * name : name of the attribute, duplicated inside so can be freed after call
 * is_array : is the attribute an array
 *
 * Returns : void
 */
void add_attr(Class* class, modifier m, type t, char* name, bool is_arr,
              int line);

/*
 * A function to add a method to the class
 *
 * Params :
 * class : pointer to the class
 * name : name of the method to be added, duplicated inside
 *        so can be freed after call
 * ret_t : return type of method
 * is_static : is the method static
 * paramlist : linedlist pointer of the parmalist of methods,
 *              must persist after call till end of program
 *              will be freed in __cleanup_classes__
 *
 * Returns : void
 */
void add_method(Class* class, char* name, type ret_t, bool is_static,
                Linked_list* paramlist, int line);

/*
 * Prints a method declaration to code file
 * print in format : type print_name (parmalist){
 * the '{' must be cloed in the calling code
 *
 * Parmas :
 * class : class to which the method belongs,
 * methodname : name of the method without the class
 */
void print_method(Class* class, char* methodname);

/*
 * A function that switches codefile and header file in parserfn to a new
 * files named as name.c and name.h Also start printing definition of class
 * : typedef struct name{ the closing '}' will be done in print_class_header
 * Params :
 * name : name of the class
 */
void start_class_definition(char* name);

/*
 * prints the class's remaining headerfile
 *
 */
void end_class_definition();

/*
 * closes th '{' started in start_class_definition
 * Parmas :
 * name : name of the class
 */
void end_attr_list(char* name);

#endif