#include "hashmap.h"

#include <stdio.h>
#include <string.h>

int hash(void *s) {
  char *t = (char *)s;
  int hash = 0;
  int c = 1;
  while (*t != '\0') {
    hash += c * (*t);
    ++t;
    ++c;
  }
  return hash;
}

int compair(void *a, void *b) { return strcmp((char *)a, (char *)b) == 0; }

void printhm(Hashmap *hm) {
  hashpair *start = hm->start;
  hashpair *t = start;
  while (t < start + hm->size) {
    if (t->key == NULL) {
      printf("---\n");
    } else {
      printf("hash = %d\t", hash(t->key) % 7);
      printf("key :%s ,value:%s\n", (char *)t->key, (char *)t->value);
    }
    ++t;
  }
  printf("\n");
}

void main() {
  Hashmap hm = make_hashmap(7, hash, compair);
  hm_add(&hm, "test1", "value1");
  hm_add(&hm, "test2", "value2");
  printhm(&hm);
  hm_add(&hm, "test3", "value3");
  hm_add(&hm, "test4", "value4");
  printhm(&hm);
  printf("value at key test3 is %s\n", (char *)hm_get(&hm, "test3"));
  printf("value at key test4 is %s\n", (char *)hm_get(&hm, "test4"));
  hm_add(&hm, "test5", "value5");
  hm_add(&hm, "test6", "value6");
  printhm(&hm);
  printf("value at non-existing key is %s\n", (char *)hm_get(&hm, "NULL"));
  printf("used = %d\n", hm.used);
  hashpair hp = hm_delete_key(&hm, "test2");
  printf("used = %d\t\t", hm.used);
  printf("returned : key %s val %s \n", (char *)hp.key, (char *)hp.value);
  printhm(&hm);
}