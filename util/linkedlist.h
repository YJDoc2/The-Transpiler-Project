#ifndef __LINKEDLIST__
#define __LINKEDLIST__
#define ll_clear(ll) ll_delete((ll), nullfn)
typedef struct link {
  void *data;
  struct link *next;
} link;

typedef struct {
  int size;
  link *start;
  link *end;
} Linked_list;

Linked_list make_linkedlist();
int ll_add(Linked_list *ll, void *data);
void ll_for_each(Linked_list *ll, void (*each)(void *));
void ll_delete(Linked_list *ll, void (*delfn)(void *));
void nullfn(void *);
#endif