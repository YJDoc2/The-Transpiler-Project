#include "classes.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#define CLASSMAP_INIT_SIZE 20
#define ATTRMAP_INIT_SIZE 20
#define METHODMAP_INIT_SIZE 20

Hashmap classmap;

FILE* tempcode = NULL;
FILE* temphead = NULL;
extern FILE *code, *header;
extern char* main_file_headname;

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_classes__() {
  classmap = make_hashmap(CLASSMAP_INIT_SIZE, __hash_str__, __compair__str__);
}

// helper functions to free classmap

void __delete_attr__(void* key, void* val) {
  free(key);
  free(val);
}

void __delete_paramlist__(void* val) {}

void __delete_method__(void* key, void* value) {
  free(key);
  method* fn = (method*)value;
  free(fn->print_name);
  ll_delete(fn->param_list, __delete_paramlist__);
  free(fn->param_list);
  free(fn);
}
void __delete_classmap__(void* key, void* val) {
  free(key);
  Class* c = (Class*)val;
  hm_delete(*(c->attr), __delete_attr__);
  free(c->attr);
  hm_delete(*(c->methods), __delete_method__);
  free(c->methods);
  // no need to free name in class as it is the key as well
  free(val);
}

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_classes__() { hm_delete(classmap, __delete_classmap__); }

/*
 * Function to create and add a class struct in classmap
 * gives error is class already exists
 * Params :
 * name : name of the class
 * Returns : Pointer to the new class
 */
Class* add_class(char* name) {
  char* temp = strdup(name);
  Class* c = (Class*)calloc(1, sizeof(Class));
  c->name = name;
  c->attr = (Hashmap*)calloc(1, sizeof(Hashmap));
  c->methods = (Hashmap*)calloc(1, sizeof(Hashmap));
  *(c->attr) = make_hashmap(ATTRMAP_INIT_SIZE, __hash_str__, __compair__str__);
  *(c->methods) =
      make_hashmap(METHODMAP_INIT_SIZE, __hash_str__, __compair__str__);
  hm_add(&classmap, temp, c);
  return c;
}

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
void add_attr(Class* class, modifier m, type t, char* name, bool is_arr) {
  char* temp = strdup(name);
  attr* a = (attr*)calloc(1, sizeof(attr));
  a->is_arr = is_arr;
  a->m = m;
  a->t = t;
  a->name = temp;
  hm_add(class->attr, temp, a);
}

/*
 * A function to add a method to th class
 *
 * Params :
 * class : pointer to the class
 * name : name of the method to be added, duplicated inside
 *        so can be freed after call
 * ret_t : return type of method
 * is_static : is the method static
 * paramlist : linedlist pointer of the parmalist of methods,
 *              must persist after call till end of program
 *              will be freed in __cleanup_classes__()
 *
 * Returns : void
 */
void add_method(Class* class, char* name, type ret_t, bool is_static,
                Linked_list* paramlist) {
  char* keyname = strdup(name);

  char* printname =
      (char*)calloc(1, strlen(keyname) + strlen(class->name) +
                           2);  // 1 ofr _ after classname, 1 for \0
  sprintf(printname, "%s_%s", class->name, keyname);
  method* fn = (method*)calloc(1, sizeof(method));
  fn->is_static_method = is_static;
  fn->param_list = paramlist;
  fn->print_name = printname;
  fn->ret_t = ret_t;
  hm_add(class->methods, keyname, fn);
}

//! TODO
void print_header_start() {}

/*
 * A function that switches codefile and header file in parserfn to a new files
 * named as name.c and name.h
 * Also start printing definition of class :
 *  typedef struct name{
 *  the closing '}' will be done in end_class_definition
 * Params :
 * name : name of the class
 */
void start_class_definition(char* name) {
  int name_len = strlen(name);
  // 1 for _ 5 for class
  // 3 =  two for '.' and ext one for end-of-string 0
  char codename[name_len + 1 + 5 + 3];
  char headname[name_len + 1 + 5 + 3];
  sprintf(codename, "%s_%s", "class", name);
  sprintf(headname, "%s_%s", "class", name);
  strcpy(codename + name_len + 6, ".c\0");
  strcpy(headname + name_len + 6, ".h\0");
  FILE* tc = fopen(codename, "w");
  FILE* th = fopen(headname, "w");
  if (tc == NULL || th == NULL) {
    perror("cannot open file for writing.");
    //! TODO GLOBAL EXIT
    exit(EXIT_FAILURE);
  }
  tempcode = code;
  temphead = header;
  code = th;  // this is intentional, as the first things declrared must be
              // attributes, so the code must be pointing to header file
              // these will be switched to correct ones in end_attr_list
  header = tc;
  print_header_start();
  fprintf(code, "\ntypedef struct %s {\n", name);
}

void print_class_header(char* name) {
  //! TODO print methods
}

/*
 * prints the class's remaining headerfile
 * closes th '{' started in start_class_definition
 */
void end_class_definition(char* name) {
  print_class_header(name);
  fclose(code);
  fclose(header);
  code = tempcode;
  header = temphead;
  tempcode = temphead = NULL;
}

/*
 * closes th '{' started in start_class_definition
 * Parmas :
 * name L name of the class
 */
void end_attr_list(char* name) {
  fprintf(code, "\n} %s ;\n\n", name);
  // switching the files
  FILE* t = header;
  header = code;
  code = t;
}