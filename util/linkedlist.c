#include "linkedlist.h"

#include <stdlib.h>

Linked_list make_linkedlist() {
  Linked_list ret = {.size = 0, .start = NULL, .end = NULL};
  return ret;
}

int ll_add(Linked_list *ll, void *data) {
  link *last = ll->end;
  link *temp = (link *)malloc(sizeof(link));
  if (!temp) {
    return -1;
  }

  link *nl = temp;
  nl->data = data;
  nl->next = NULL;
  if (last) {
    last->next = nl;
  } else {
    ll->start = nl;
  }

  ++ll->size;
  ll->end = nl;
  return 0;
}

void ll_for_each(Linked_list *ll, void (*each)(void *)) {
  if (!ll->start) return;
  link *t = ll->start;
  while (t != NULL) {
    each(t->data);
    t = t->next;
  }
}

void ll_delete(Linked_list *ll, void (*delfn)(void *)) {
  if (ll->start == NULL) return;
  link *t = ll->start;
  link *_t = t;
  while (t != NULL) {
    delfn(t->data);
    _t = t->next;
    free(t);
    t = _t;
  }
  ll->start = NULL;
  ll->end = NULL;
  ll->size = 0;
}

void ll_nullfn(void *p) { return; }