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
  if (st->start == NULL) return (void *)-1;

  stack_link *temp = st->start;
  st->start = st->start->next;
  --st->size;
  void *ret = temp->data;
  free(temp);

  return ret;
}

void st_delete(Stack *st, void (*delfn)(void *)) {
  stack_link *_sl = st->start;
  stack_link *_t;
  while (_sl != NULL) {
    delfn(_sl->data);
    _t = _sl;
    _sl = _sl->next;
    free(_t);
  }
  return;
}