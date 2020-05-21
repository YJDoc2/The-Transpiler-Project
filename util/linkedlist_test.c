#include "linkedlist.h"

#include <stdio.h>

void print(void *t) { printf("data : %s\n", (char *)t); }

int compairfn(void *a, void *b) { return (int)a == (int)b; }

void main() {
  Linked_list ll = make_linkedlist();
  Linked_list l2 = make_linkedlist();

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
  ll_add(&ll, (void *)1);
  ll_add(&ll, (void *)2);
  ll_add(&ll, (void *)3);

  ll_add(&l2, (void *)1);
  ll_add(&l2, (void *)2);
  ll_add(&l2, (void *)3);

  if (are_same(&ll, &l2, compairfn)) {
    printf("These two are same...\n");
  } else {
    printf("error in first compairison\n");
  }

  ll_clear(&l2);
  ll_add(&l2, (void *)1);
  ll_add(&l2, (void *)2);
  ll_add(&l2, (void *)5);

  if (are_same(&ll, &l2, compairfn)) {
    printf("error in second compairison\n");
  } else {
    printf("These two are different...\n");
  }
  ll_clear(&ll);
  ll_clear(&l2);
}