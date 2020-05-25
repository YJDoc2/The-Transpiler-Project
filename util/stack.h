#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
typedef struct stack_link {
  void *data;
  struct stack_link *next;
} stack_link;

typedef struct {
  int size;
  stack_link *start;
} Stack;

Stack make_stack();
int st_push(Stack *st, void *data);
void *st_pop(Stack *st);
void st_delete(Stack *st, void (*delfn)(void *));

#endif