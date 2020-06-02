#include "expressions.h"

#include <stdlib.h>
#include <string.h>

#include "stack.h"

Stack exprt_st, args_st;
extern char *type_arr;
ll_link *arg;

void __init_expr__() {
  exprt_st = make_stack();
  args_st = make_stack();
}

void __clean_args_st__(void *a) {
  if (a == NULL) return;
  Linked_list *l = (Linked_list *)a;
  ll_clear(l);
  free(a);
}

void __cleanup_expr__() {
  st_delete(&exprt_st, ll_nullfn);
  st_delete(&args_st, __clean_args_st__);
}

void push_expr_and_args() {
  st_push(&exprt_st, (void *)expr_type);
  st_push(&args_st, (void *)arglist);
  arglist = (Linked_list *)calloc(1, sizeof(Linked_list));
  *arglist = make_linkedlist();
  expr_type = VOID_TYPE;
}

void pop_expr_and_args() {
  ll_clear(arglist);
  free(arglist);
  type _t = (type)st_pop(&exprt_st);
  expr_type = _t == -1 ? VOID_TYPE : _t;
  arglist = (Linked_list *)st_pop(&args_st);
}

char *join(char *start, char *middle, char *end) {
  void *_t = calloc(1, strlen(start) + strlen(middle) + strlen(end) + 1);
  strcat(_t, start);
  strcat(_t, middle);
  strcat(_t, end);
  return (char *)_t;
}

int verify_types(type combining_with, type combining_type) {
  if (combining_type == VOID_TYPE || combining_with == VOID_TYPE) return 1;

  if (combining_with == STRING_TYPE) {
    if (combining_type != STRING_TYPE) return 1;
  }
  if (combining_with == FLOAT_TYPE || combining_with == DOUBLE_TYPE) {
    if (combining_type == BOOL_TYPE || combining_type == STRING_TYPE ||
        combining_type == COMPLEX_TYPE) {
      return 1;
    }
  }

  if (combining_with == INT_TYPE || combining_with == SHORT_TYPE ||
      combining_with == LONG_TYPE) {
    if (!(combining_type == INT_TYPE || combining_type == SHORT_TYPE ||
          combining_type == LONG_TYPE)) {
      return 1;
    }
  }

  if (combining_with == BOOL_TYPE)
    if (combining_type != BOOL_TYPE) return 1;

  if (combining_with == COMPLEX_TYPE)
    if (combining_type == BOOL_TYPE) return 1;

  return 0;
}
