#include "variables.h"

#include <string.h>

#include "parserfn.h"
#include "scope.h"

// Largest prime below 5000
#define VAR_HM_INIT_SIZE 4931

char* type_arr[] = {
    "int",  "float", "double", "bool", "float complex",
    "long", "short", "char *", "void",
};

char* mod_arr[] = {"", "const", "static"};

void __init_vars__() {
  varmap = make_hashmap(VAR_HM_INIT_SIZE, __hash_str__, __compair__str__);
}

void __del_var__(void* a, void* b) { free(a); }

void __cleanup_vars__() { delete_hashmap(varmap, __del_var__); }

void create_var(modifier m, type t, char* ident, int line) {
  char* _name =
      strdup(ident);  // MUST duplicate as Parser discards ident ptr after call
  Variable* v = (Variable*)malloc(sizeof(Variable));
  v->name = _name;
  v->m = m;
  v->t = t;
  v->declaration = line;
  v->is_raw = false;
  Hashmap* hm =
      scopelist.start == NULL ? &varmap : (Hashmap*)scopelist.start->data;
  hm_add(hm, _name, v);
}

void add_var(modifier m, type t, char* ident, int line) {
  Variable* look = lookup_var(ident);
  if (look == NULL) {
    create_var(m, t, ident, line);
    printcode("%s %s %s;\n", mod_arr[m], type_arr[t], ident);
  } else {
    yyerror("Variable %s already delcared on line %d", ident,
            look->declaration);
  }
}

void add_var_assg(modifier m, type t, char* ident, char* val, int line) {
  Variable* look = lookup_var(ident);
  if (look == NULL) {
    create_var(m, t, ident, line);
    printcode("%s %s %s = %s;\n", mod_arr[m], type_arr[t], ident, val);
  } else {
    yyerror("Variable %s already delcared on line %d", ident,
            look->declaration);
  }
}

Variable* lookup_var(char* ident) {
  stack_link* _sc = scopelist.start;
  void* look = NULL;
  while (_sc != NULL && look == NULL) {
    Hashmap* hm = (Hashmap*)_sc->data;
    look = hm_get(hm, ident);
    _sc = _sc->next;
  }
  if (look == NULL) look = hm_get(&varmap, ident);
  return (Variable*)look;
}

int verify_types() {
  if (lhst == INT_TYPE) {
    if (!(rhst == INT_TYPE || rhst == LONG_TYPE || rhst == SHORT_TYPE ||
          rhst == COMPLEX_TYPE)) {
      yyerror("Invalid assignment : %s cannot be assigned to var type %s",
              type_arr[rhst], type_arr[lhst]);
    }
  }
  if (lhst == BOOL_TYPE) {
    if (rhst != BOOL_TYPE) {
      yyerror("Invalid assignment : %s cannot be assigned to var type %s",
              type_arr[rhst], type_arr[lhst]);
    }
  }
  if (lhst == STRING_TYPE) {
    if (rhst != STRING_TYPE) {
      yyerror("Invalid assignment : %s cannot be assigned to var type %s",
              type_arr[rhst], type_arr[lhst]);
    }
  }
  return 0;
}