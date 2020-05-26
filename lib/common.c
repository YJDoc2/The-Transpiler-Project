#include "common.h"

Linked_list arglist;

int __hash_str__(void* s) {
  char* t = (char*)s;
  int hash = 0;
  int c = 1;
  while (*t != '\0') {
    hash += c * (*t);
    ++t;
    ++c;
  }
  return hash;
}

int __compair__str__(void* a, void* b) {
  return strcmp((char*)a, (char*)b) == 0;
}