#include "common.h"

Linked_list* arglist;  // init is done in actions.c

/*
 * A function used to make hash of strings
 *
 * This calculates a weighted sum of all characters in the string
 * thus even two strings containing same characters can have different hashes if
 * the position of characters is different
 *
 * Params :
 * s : pointer to the string whose hash is to be calculated
 * Returns : an int representing hash of the string
 */
int __hash_str__(void* s) {
  char* t = (char*)s;
  int hash = 0;
  int c = 1;  // started form one so even the first char makes the contribution
  while (*t != '\0') {
    hash += c * (*t);  // multiply ascii value of character by the position
    ++t;
    ++c;
  }
  return hash;
}

/*
 * A function used to compair two strings
 * This is used for hashmap compair function
 * Params : two void pointers which point to strings
 *
 * Returns : 1 if strings are equal
 *           0 if strings are unequal
 */
inline int __compair__str__(void* a, void* b) {
  return strcmp((char*)a, (char*)b) == 0;
}