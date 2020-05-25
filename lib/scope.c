#include "scope.h"

#include <stdlib.h>

#include "common.h"
#include "hashmap.h"

#define SCOPE_INIT_SIZE 20

Stack scopelist;

extern void (*__del_var__)(void *, void *);

void __scopelist_del_fn__(void *a) {
  Hashmap *hm = (Hashmap *)a;
  delete_hashmap(*hm, __del_var__);
}

void __init_scopes__() { scopelist = make_stack(); }
void __cleanup_scopes__() { st_delete(&scopelist, __scopelist_del_fn__); }

void pushscope() {
  Hashmap *hm = calloc(1, sizeof(Hashmap));
  *hm = make_hashmap(SCOPE_INIT_SIZE, __hash_str__, __compair__str__);
  st_push(&scopelist, hm);
}

void popscope() {
  Hashmap *hm = (Hashmap *)st_pop(&scopelist);
  delete_hashmap(*hm, __del_var__);
}