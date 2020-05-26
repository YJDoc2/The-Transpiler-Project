#include "literals.h"

Linked_list literals;

void __init_literals__() { literals = make_linkedlist(); }
void *add_literal(modifier m, type t, char *ident) {
  char *_name =
      strdup(ident);  // MUST duplicate as Parser discards ident ptr after call
  Variable *v = (Variable *)calloc(1, sizeof(Variable));
  v->name = _name;
  v->m = m;
  v->t = t;
  v->declaration = 0;
  v->is_raw = true;
  return (void *)v;
}

void __del__(void *v) {
  Variable *var = (Variable *)v;
  free(var->name);
}
void clear_literals() { ll_delete(&literals, __del__); }
void __cleanup_literals__() { ll_delete(&literals, __del__); }