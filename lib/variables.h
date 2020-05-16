#ifndef __VARIABLES__
#define __VARIABLES__
#include "hashmap.h"

typedef enum {
  INT_TYPE,
  FLOAT_TYPE,
  DOUBLE_TYPE,
  BOOL_TYPE,
  COMPLEX_TYPE,
  LONG_TYPE,
  SHORT_TYPE,
  VOID_TYPE,
} type;

typedef enum { NONE_TYPE, CONST_TYPE, STATIC_TYPE } modifier;

typedef struct {
  char *name;
  type t;
  modifier m;
} Variable;

Hashmap varmap;

// void __init_vars__();

void decl_var(modifier m, type t, char *ident);
void assg_decl_var(modifier m, type t, char *ident, char *val);

#endif