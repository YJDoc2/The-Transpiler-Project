#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include "common.h"
#include "hashmap.h"
#include "linkedlist.h"
#include "parserfn.h"
#include "variables.h"

extern Hashmap fnmap;
extern Hashmap callmap;

typedef struct {
  modifier m;
  type t;
  char* name;
} Param;

typedef struct {
  char* print_name;
  Linked_list* param_list;
  int declaration;
  type ret_t;
  modifier ret_m;
} Function;

typedef struct {
  char* fnname;
  Linked_list* arglist;
  int declaration;
} Fncall;

void __init_functions__();
void __cleanup_functions__();

void add_call(char* fn, Fncall call);
void verify_previous_calls(char* fn);  // Will consume respective callmap

int verify_call(char* fn, Fncall call);

void add_param(modifier m, type t, char* param_name);
void add_function(modifier m, type t, char* fnname, char* printname,
                  int lineno);
void print_fn_delc(char* name);
#endif