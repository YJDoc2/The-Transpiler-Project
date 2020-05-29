#ifndef __VARIABLES__
#define __VARIABLES__
#include "common.h"
#include "hashmap.h"
#include "stdbool.h"

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
} type;

typedef enum { NONE_TYPE, CONST_TYPE, STATIC_TYPE } modifier;

typedef struct {
  bool is_raw;
  char *name;
  type t;
  modifier m;
  int declaration;
} Variable;

Hashmap varmap;

void __init_vars__();
void __cleanup_vars__();

void create_var(modifier m, type t, char *ident, int line);
void add_var(modifier m, type t, char *ident, int line);
void add_var_assg(modifier m, type t, char *ident, char *val, int line);

Variable *lookup_var(char *ident);
#endif