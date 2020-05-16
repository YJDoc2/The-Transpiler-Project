#include "hashmap.h"

#include <stdlib.h>

Hashmap make_hashmap(int size, int (*hashfn)(void *),
                     int (*compairfn)(void *, void *)) {
  Hashmap hm = {.size = size,
                .used = 0,
                .start = (hashpair *)calloc(size, sizeof(Hashmap)),
                .compair = compairfn,
                .hash = hashfn};
  return hm;
}

void *hm_get(Hashmap *hm, void *key) {
  hashpair *start = hm->start;
  int hash = (hm->hash(key) % hm->size);
  hashpair *search = start + hash;
  while (search->key != NULL && search->value != NULL &&
         search < start + hm->size) {
    if (hm->compair(key, search->key)) {
      return search->value;
    }
    ++search;
  }
  return NULL;
}

int hm_add(Hashmap *hm, void *key, void *value) {
  int hash = hm->hash(key) % hm->size;
  if (hm->used >= 3 * hm->size / 4) {
    rehash(hm);
  }
  hashpair *search = hm->start + hash;
  while (search->key != NULL && search->value != NULL &&
         search < hm->start + hm->size) {
    ++search;
  }
  if (search >= hm->start + hm->size) {
    return -1;
  } else {
    search->key = key;
    search->value = value;
    ++hm->used;
  }
  return 0;
}

void rehash(Hashmap *hm) {
  int size = hm->size;
  hashpair *temp = (hashpair *)calloc(size * 2, sizeof(hashpair));
  if (!temp) {
    return;
  }
  hashpair *newstart = temp;
  hashpair *oldstart = hm->start;
  hm->start = newstart;
  hm->size = size * 2;
  hm->used = 0;

  hashpair *start = oldstart;

  while (start < oldstart + size) {
    if (start->key != NULL) {
      hm_add(hm, start->key, start->value);
    }
    ++start;
  }
  free(oldstart);
}

hashpair hm_delete(Hashmap *hm, void *key) {
  hashpair *start = hm->start;
  int hash = (hm->hash(key) % hm->size);
  hashpair *search = start + hash;
  while (search->key != NULL && search->value != NULL &&
         search < start + hm->size) {
    if (hm->compair(key, search->key)) {
      hashpair ret = {.key = search->key, .value = search->value};
      search->key = NULL;
      search->value = NULL;
      --hm->used;
      return ret;
    }
    ++search;
  }
  hashpair ret = {NULL, NULL};
  return ret;
}
void delete_hashmap(Hashmap hm) { free(hm.start); }