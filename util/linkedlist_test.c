#include "linkedlist.h"

#include <stdio.h>

void print(void *t) { printf("data : %s\n", (char *)t); }

void main() {
  Linked_list ll = make_linkedlist();

  ll_add(&ll, "test1");
  ll_add(&ll, "test2");
  printf("Now size is %d\n", ll.size);
  ll_for_each(&ll, print);
  ll_add(&ll, "test3");
  ll_add(&ll, "test4");
  printf("Now size is %d\n", ll.size);
  ll_delete(&ll, print);
  printf("Now size is %d\n", ll.size);
  ll = make_linkedlist();
  ll_add(&ll, "test1");
  ll_add(&ll, "test2");
  printf("Now size is %d\n", ll.size);
  ll_clear(&ll);
  printf("Now size is %d\n", ll.size);
}