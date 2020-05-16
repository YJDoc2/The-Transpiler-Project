#include "variables.h"

#include <string.h>

#include "parserfn.h"

// Largest prime below 5000 4931
#define VAR_HM_INIT_SIZE 10

int __hash(void* s) {
  char* t = (char*)s;
  int hash = 0;
  int c = 1;
  while (*t != '\0') {
    hash += c * (*t);
    ++t;
    ++c;
  }
  return hash;
}

int __compair(void* a, void* b) { return strcmp((char*)a, (char*)b) == 0; }

char* type_arr[] = {
    "int", "float", "double", "bool", "float complex", "long", "short", "void",
};

char* mod_arr[] = {"", "const", "static"};

void __init_vars__() {
  varmap = make_hashmap(VAR_HM_INIT_SIZE, __hash, __compair);
}

void __del_var__(void* a, void* b) { free(a); }

void __cleanup_vars__() { delete_hashmap(varmap, __del_var__); }

void create_var(modifier m, type t, char* ident, int line) {
  char* _t =
      strdup(ident);  // MUST duplicate as Parser discards ident ptr after call
  Variable* v = (Variable*)malloc(sizeof(Variable));
  v->name = _t;
  v->m = m;
  v->t = t;
  v->declaration = line;
  hm_add(&varmap, _t, v);
}

void add_var(modifier m, type t, char* ident, int line) {
  Variable* look = lookup(ident);
  if (look == NULL) {
    create_var(m, t, ident, line);
    printcode("%s %s %s;\n", mod_arr[m], type_arr[t], ident);
  } else {
    yyerror("Variable %s already delcared on line %d", ident,
            look->declaration);
  }
}

void add_var_assg(modifier m, type t, char* ident, char* val, int line) {
  Variable* look = lookup(ident);
  if (look == NULL) {
    create_var(m, t, ident, line);
    printcode("%s %s %s = %s;\n", mod_arr[m], type_arr[t], ident, val);
  } else {
    yyerror("Variable %s already delcared on line %d", ident,
            look->declaration);
  }
}

Variable* lookup(char* ident) {
  void* look = hm_get(&varmap, ident);
  return (Variable*)look;
}