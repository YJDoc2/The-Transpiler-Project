#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#define ll_clear(ll) ll_delete((ll), ll_nullfn)
typedef struct ll_link {
  void *data;
  struct ll_link *next;
} ll_link;

typedef struct {
  int size;
  ll_link *start;
  ll_link *end;
} Linked_list;

Linked_list make_linkedlist();
int ll_add(Linked_list *ll, void *data);
void ll_for_each(Linked_list *ll, void (*each)(void *));
void ll_delete(Linked_list *ll, void (*delfn)(void *));
void ll_nullfn(void *);

int are_same(Linked_list *l1, Linked_list *l2,
             int (*compairfn)(void *, void *));
#endif