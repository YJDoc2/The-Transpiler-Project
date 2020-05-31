#include "expressions.h"

#include <stdlib.h>
#include <string.h>

#include "stack.h"

Stack expr_t, arg_t;
extern char *type_arr;
ll_link *arg;

void __init_expr__() {
  expr_t = make_stack();
  arg_t = make_stack();
}
void __cleanup_expr__() {
  st_delete(&expr_t, ll_nullfn);
  st_delete(&arg_t, ll_nullfn);
}

void push_arg_type() {
  st_push(&arg_t, arg_type);
  arg_type = VOID_TYPE;
}
void pop_arg_type() {
  void *_t = st_pop(&arg_t);
  if (_t == (void *)-1) {
    arg_type = VOID_TYPE;
  } else {
    arg_type = (type)_t;
  }
}
void push_expr_type() {
  st_push(&expr_t, arg_type);
  expr_type = VOID_TYPE;
}
void pop_expr_type() {
  void *_t = st_pop(&expr_t);
  if (_t == (void *)-1) {
    expr_type = VOID_TYPE;
  } else {
    expr_type = (type)_t;
  }
}

char *join(char *start, char *middle, char *end) {
  void *_t = calloc(1, strlen(start) + strlen(middle) + strlen(end));
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

void set_arg_iter(char *fn) {
  Function *f = find_fn(fn);
  if (fn == NULL) return;
  arg = f->param_list->start;
  arg_type =
}