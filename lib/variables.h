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
  int declaration;
} Variable;

Hashmap varmap;
type rhst, lhst;

void __init_vars__();
void __cleanup_vars__();

void create_var(modifier m, type t, char *ident, int line);
void add_var(modifier m, type t, char *ident, int line);
void add_var_assg(modifier m, type t, char *ident, char *val, int line);

Variable *lookup(char *ident);
int verify_types();

#endif