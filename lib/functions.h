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
  Linked_list* arglist;
  int declaration;
  type ret_type;
} Fncall;

void __init_functions__();
void __cleanup_functions__();

void add_call(char* fn, type t, int lineno);
char* get_fncall_str(char* fnname);

int verify_call(char* fnname, type t, Function* fn, int lineno);

void add_param(modifier m, type t, char* param_name);

Function* find_fn(char* fnname);
void add_function(modifier m, type t, char* fnname, char* printname,
                  int lineno);
void print_fn_delc(char* name);
#endif