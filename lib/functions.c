#include "functions.h"
#define FNAMP_INIT_SIZE 50
#define CALLMAP_INIT_SIZE 50

extern char *type_arr[], *mod_arr[];
Hashmap fnmap;
Hashmap callmap;

Linked_list* temp_list = NULL;

void __ll_del_fn__(void* a) {
  Param* p = (Param*)a;
  free(p->name);
  free(a);
}

void __fnmap_del_fn__(void* a, void* b) {
  free(a);
  Function* f = (Function*)b;
  free(f->print_name);
  if (f->param_list != NULL) {
    ll_delete(f->param_list, __ll_del_fn__);
  }
  return;
}

void __callmap_del_fn__(void* a, void* b) {
  free(a);
  Function* f = (Function*)b;
  free(f->print_name);
  return;
}
void __init_functions__() {
  fnmap = make_hashmap(50, __hash_str__, __compair__str__);
  callmap = make_hashmap(50, __hash_str__, __compair__str__);
}
void __cleanup_functions__() {
  delete_hashmap(fnmap, __fnmap_del_fn__);
  delete_hashmap(callmap, __callmap_del_fn__);
  if (temp_list != NULL) {
    ll_delete(temp_list, __ll_del_fn__);
  }
}

void add_param(modifier m, type t, char* param_name) {
  if (temp_list == NULL) {
    temp_list = calloc(1, sizeof(Linked_list));
    *temp_list = make_linkedlist();
  }
  Param* p = calloc(1, sizeof(Param));
  p->m = m;
  p->t = t;
  p->name = strdup(param_name);
  ll_add(temp_list, p);
  return;
}
void add_function(modifier m, type t, char* fnname, char* printname,
                  int lineno) {
  Function* f = calloc(1, sizeof(Function));
  f->declaration = lineno;
  f->param_list = temp_list;
  temp_list = NULL;
  f->print_name = strdup(printname);
  f->ret_t = t;
  f->ret_m = m;
  hm_add(&fnmap, strdup(fnname), f);
}

static void print_param(Param* p) {
  printcode("%s %s %s ", mod_arr[p->m], type_arr[p->t], p->name);
}

static void print_params(Linked_list* ll) {
  if (ll == NULL) return;
  link* _l = ll->start;
  print_param((Param*)_l->data);
  if (_l->next == NULL) return;
  _l = _l->next;
  while (_l != NULL) {
    printcode(",");
    print_param((Param*)_l->data);
    _l = _l->next;
  }
  return;
}

void print_fn_delc(char* name) {
  Function* f = (Function*)hm_get(&fnmap, name);
  if (f == NULL) {
    yyerror(
        "Error : Internal Error : trying to print declration of non-existent "
        "function %s\n",
        name);
    return;
  }
  printcode("%s %s %s ( ", mod_arr[f->ret_m], type_arr[f->ret_t],
            f->print_name);
  print_params(f->param_list);
  printcode(" ) {\n");
  return;
}