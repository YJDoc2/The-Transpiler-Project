#include "stack.h"

Stack make_stack() {
  Stack ret = {.size = 0, .start = NULL};
  return ret;
}

int st_push(Stack *st, void *data) {
  stack_link *temp = (stack_link *)calloc(1, sizeof(stack_link));
  if (temp == NULL) {
    return -1;
  }
  stack_link *nl = temp;
  nl->data = data;
  nl->next = st->start;

  st->start = nl;
  ++st->size;

  return 0;
}
void *st_pop(Stack *st) {
  if (st->start == NULL) return NULL;

  stack_link *temp = st->start;
  st->start = st->start->next;
  --st->size;
  void *ret = temp->data;
  free(temp);

  return ret;
}