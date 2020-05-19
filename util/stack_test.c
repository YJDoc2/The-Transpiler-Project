#include "stack.h"

#include <stdio.h>

void main() {
  Stack s = make_stack();
  st_push(&s, "test1");
  st_push(&s, "test2");
  printf("test2 : %s\n", (char *)st_pop(&s));
  st_push(&s, "test3");
  st_push(&s, "test4");
  printf("size : %d\n", s.size);
  printf("test4 : %s\n", (char *)st_pop(&s));
  printf("test3 : %s\n", (char *)st_pop(&s));
  printf("size : %d\n", s.size);
  printf("test1 : %s\n", (char *)st_pop(&s));
  printf("size : %d\n", s.size);
}