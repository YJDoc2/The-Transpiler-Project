#ifndef __HASHMAP__
#define __HASHMAP__

typedef struct {
  void *key;
  void *value;
} hashpair;

typedef struct {
  int size;
  int used;
  hashpair *start;
  int (*hash)(void *);
  int (*compair)(void *, void *);
} Hashmap;

Hashmap make_hashmap(int size, int (*hashfn)(void *),
                     int (*compair)(void *, void *));
int hm_add(Hashmap *hm, void *key, void *value);
void *hm_get(Hashmap *hm, void *key);
void rehash(Hashmap *hm);
hashpair hm_delete(Hashmap *hm, void *key);
void delete_hashmap(Hashmap hm);
#endif
