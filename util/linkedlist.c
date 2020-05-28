#include "linkedlist.h"

#include <stdlib.h>

Linked_list make_linkedlist() {
  Linked_list ret = {.size = 0, .start = NULL, .end = NULL};
  return ret;
}

int ll_add(Linked_list *ll, void *data) {
  ll_link *last = ll->end;
  ll_link *temp = (ll_link *)calloc(1, sizeof(ll_link));
  if (!temp) {
    return -1;
  }

  ll_link *nl = temp;
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
  ll_link *t = ll->start;
  while (t != NULL) {
    each(t->data);
    t = t->next;
  }
}

void ll_delete(Linked_list *ll, void (*delfn)(void *)) {
  if (ll->start == NULL) return;
  ll_link *t = ll->start;
  ll_link *_t = t;
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

int are_same(Linked_list *l1, Linked_list *l2,
             int (*compairfn)(void *, void *)) {
  if (l1->size != l2->size) return 0;
  int i = 0;
  ll_link *t1 = l1->start;
  ll_link *t2 = l2->start;
  while (t1 != NULL && t2 != NULL) {
    ++i;
    if (!compairfn(t1->data, t2->data)) {
      return 0;
    }
    t1 = t1->next;
    t2 = t2->next;
  }
  if (i != l1->size) return 0;
  return 1;
}