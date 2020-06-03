#include "functions.h"
#define FNAMP_INIT_SIZE 50
#define CALLMAP_INIT_SIZE 50

extern char *type_arr[], *mod_arr[];
Hashmap fnmap;
Hashmap callmap;

Linked_list* temp_list = NULL;

char* fncall_incorrect_arg_num_msg =
    "incorrect %s function call on line %d :\n\texpected %d params as "
    "per function delcaration on line %d,but got %d\n ";

char* fncall_incorrect_arg_type_msg =
    "incorrect argument type in function call on line %d :\n\tfor "
    "argument %d expected tpe %s as per declaration on line %d, got %s";

char* fncall_incorrect_ret_tpe_msg =
    "incorrect return type in function call on line %d :\n\texpected %s but "
    "found %s as per declaration on line %d";

void __paramlist_del_fn__(void* a) {
  Param* p = (Param*)a;
  free(p->name);
  free(a);
}

void __fnmap_del_fn__(void* a, void* b) {
  free(a);
  Function* f = (Function*)b;
  free(f->print_name);
  if (f->param_list != NULL) {
    ll_delete(f->param_list, __paramlist_del_fn__);
  }
  free(f->param_list);
  free(b);
  return;
}

void __del_fncall__(void* c) {
  Fncall* _c = (Fncall*)c;
  ll_clear(_c->arglist);
  free(c);
}

void __callmap_del_fn__(void* a, void* b) {
  free(a);
  Linked_list* _ll = (Linked_list*)b;
  ll_delete(_ll, __del_fncall__);
  free(_ll);
  return;
}
void __init_functions__() {
  fnmap = make_hashmap(50, __hash_str__, __compair__str__);
  callmap = make_hashmap(50, __hash_str__, __compair__str__);
}
void __cleanup_functions__() {
  hm_delete(fnmap, __fnmap_del_fn__);
  hm_delete(callmap, __callmap_del_fn__);
  if (temp_list != NULL) {
    ll_delete(temp_list, __paramlist_del_fn__);
    free(temp_list);
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

void verify_previous_calls(char* fnname, Function* f) {
  Linked_list* call_list = (Linked_list*)hm_get(&callmap, fnname);
  if (call_list == NULL) return;
  ll_link* call_list_itr = call_list->start;
  ll_link* fn_params_itr;
  int num_params = f->param_list->size;
  int argnum;
  while (call_list_itr != NULL) {
    Fncall* call = (Fncall*)call_list_itr->data;
    if (call->arglist->size != num_params) {
      yyerror(fncall_incorrect_arg_num_msg, fnname, call->declaration,
              num_params, f->declaration, call->arglist->size);
      call_list_itr = call_list_itr->next;
      continue;
    }
    argnum = 1;
    fn_params_itr = f->param_list->start;
    ll_link* arglist_itr = call->arglist->start;
    while (arglist_itr != NULL) {
      Variable* arg = (Variable*)arglist_itr->data;
      Param* p = (Param*)fn_params_itr->data;
      if (p->t != arg->t) {
        yyerror(fncall_incorrect_arg_type_msg, call->declaration, argnum,
                type_arr[p->t], f->declaration, type_arr[arg->t]);
      }
      fn_params_itr = fn_params_itr->next;
      arglist_itr = arglist_itr->next;
      ++argnum;
    }
    call_list_itr = call_list_itr->next;
  }
  hashpair hp = hm_delete_key(&callmap, fnname);
  __callmap_del_fn__(hp.key, hp.value);
}

void add_function(modifier m, type t, char* fnname, char* printname,
                  int lineno) {
  void* _t = hm_get(&fnmap, fnname);
  if (_t != NULL) {
    yyerror(
        "Redefination of function %s on line %d : previously defined on line "
        "%d",
        printname, yylineno, ((Function*)_t)->declaration);
    return;
  }
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
  ll_link* _l = ll->start;
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
        "Internal Error : trying to print declration of non-existent "
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

Function* find_fn(char* fnname) { return (Function*)hm_get(&fnmap, fnname); }

char* get_fncall_str(char* fnname) {
  ll_link* _t = arglist->start;
  Variable* _var;
  int len = strlen(fnname) + 2;
  while (_t != NULL) {
    _var = (Variable*)_t->data;
    len += strlen(_var->name) + 1;
    _t = _t->next;
  }
  void* ret = calloc(1, len + 1);
  strcat(ret, fnname);
  strcat(ret, "(");
  _t = arglist->start;
  while (_t != NULL) {
    _var = (Variable*)_t->data;
    strcat(ret, _var->name);
    if (_t->next != NULL) {
      strcat(ret, ",");
    }
    _t = _t->next;
  }
  strcat(ret, ")");
  return ret;
}

int verify_call(char* fnname, Function* fn, int lineno) {
  int params = fn->param_list == NULL ? 0 : fn->param_list->size;
  if (arglist->size != params) {
    yyerror(fncall_incorrect_arg_num_msg, fnname, lineno, params,
            fn->declaration, arglist->size);
    return 1;
  }
  if (arglist->size == 0) return 0;
  int argnum = 1;
  ll_link* fn_params_itr = fn->param_list->start;
  ll_link* arglist_itr = arglist->start;
  while (arglist_itr != NULL) {
    Variable* arg = (Variable*)arglist_itr->data;
    Param* p = (Param*)fn_params_itr->data;
    if (p->t != arg->t) {
      yyerror(fncall_incorrect_arg_type_msg, lineno, argnum, type_arr[p->t],
              fn->declaration, type_arr[arg->t]);
    }
    fn_params_itr = fn_params_itr->next;
    arglist_itr = arglist_itr->next;
    ++argnum;
  }

  return 0;
}