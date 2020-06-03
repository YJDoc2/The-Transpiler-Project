/*
 * This is an implementation of HashMap Data structure
 */
#include "hashmap.h"

#include <stdlib.h>
#define HM_REHASH_LIM(x) (x / 2)
#define HM_REHASH_FAC 3

/*
 * Function to create Hashmap structure
 * the structure received should be deleted after use by
 * using function hm_delete
 * Params :
 * size : Initial size allocated to hasmap
 * hashfn : A function which takes in a void pointer (key)
 *          and returns an int representing the hash of that key
 * compair : A function which takes two void pointers (two keys)
 *          and returns if the keys are same or not.
 *          0 : if different
 *          1 : if same
 * Returns : A struct Hashmap.
 *
 * This allocates the given size from heap memory using calloc, and stores its
 * pointer,as well as the compair function and hash function in the returning
 * structure
 */

Hashmap make_hashmap(int size, int (*hashfn)(void *),
                     int (*compairfn)(void *, void *)) {
  Hashmap ret = {
      .size = size,
      .used = 0,
      .start = (hashpair *)calloc(
          size, sizeof(Hashmap)), /* Use calloc so the returned memory will be
                                   * zeroed and if any errors or invalid access,
                                   * will be caught */
      .compair = compairfn,
      .hash = hashfn};
  return ret;
}

/*
 * Internal function to rehash a Hashmap and reallocate the keys and values
 * Should not be exposed
 *
 * this increases the current size of hashmap by HM_REHASH_FAC factor,
 * and then rehashes all keys and puts then in this newly allocated memory
 * then frees the old memory
 */
static void rehash(Hashmap *hm) {
  int size = hm->size;
  hashpair *temp = (hashpair *)calloc(size * HM_REHASH_FAC, sizeof(hashpair));
  if (temp == NULL) {  // If cannot allocate memory , just return
    return;
  }
  hashpair *newstart = temp;
  hashpair *oldstart = hm->start;
  // Change the HM info
  hm->start = newstart;
  hm->size = size * HM_REHASH_FAC;
  hm->used = 0;

  hashpair *iter = oldstart;

  // move all key-value pairs to new locations, using the hm_add function
  while (iter < oldstart + size) {
    // As we have calloc-ed the memory, both key and value being zero
    // means that the location was not allocated
    if (iter->key != NULL || iter->value != NULL) {
      // If either is non-zero, add it to the new memory
      hm_add(hm, iter->key, iter->value);
    }
    ++iter;
  }
  free(oldstart);
}

/*
 * Function to add key value pair to hashmap
 * Note that once the hashmap reaches its max used capacity,
 * this internally rehashes and reallocates the whole hashmap
 *
 * Params :
 * hm : pointer to the hasmmap in which the pair is to be added
 * key : pointer to the key / key (must be typecasted to void *)
 * value : pointer to value / value (must be typecasted to void *)
 *
 * Returns : int : 0 if succeeded
 *                 -1 if failed
 */
int hm_add(Hashmap *hm, void *key, void *value) {
  int hash = hm->hash(key) % hm->size;  // bound the hash inside the size

  // If the used capacity of HM is more than max used allowed, reshah
  if (hm->used >= HM_REHASH_LIM(hm->size)) {
    rehash(hm);
  }
  // Start searching empty space at offset of hash
  hashpair *search = hm->start + hash;
  // loop until we find an empty space or we get to end of memory
  while (search->key != NULL && search->value != NULL &&
         search < hm->start + hm->size) {
    ++search;
  }

  if (search >= hm->start + hm->size) {
    return -1;  // Failed to add
  } else {
    search->key = key;
    search->value = value;
    ++hm->used;
  }
  return 0;
}

/*
 * Function to get value corresponding to given key in given hashmap\
 *
 * Params :
 * hm : pointer to the hashmap from which the value is to be retrieved
 * key : key to which the corresponding value is to be found
 *
 * Returns : NULL if key is not found in given hashmap
 *           value that was given in hm_add as void *
 */
void *hm_get(Hashmap *hm, void *key) {
  hashpair *start = hm->start;
  int hash = (hm->hash(key) % hm->size);  // bound the hash in memory size

  // start searching for key at offset of hash
  hashpair *search = start + hash;

  // As we have calloc-ed the memory, both key and value being zero
  // means that the location was not allocated
  while (search->key != NULL && search->value != NULL &&
         search < start + hm->size) {
    // Compair the found and required key using the compair function,
    // if it returns 1, we have found the key , return the corresponding value
    if (hm->compair(key, search->key)) {
      return search->value;
    }
    ++search;
  }
  return NULL;
}

/*
 * A function to delete a perticular key-value pair from given hashmap
 * Note : This only removes the key-value pair from hashmap.
 *        this returns the key-value pair as given to hm_add,
 *        which if were manually allocated, must be manually freed by user.
 *
 * Params :
 * hm : A pointer to hashmap from which value is to be deleted
 * key : the key as void *, which is to be removed
 *
 * Returns : if key is found : hashpair struct containing the key and value
 *                             corresponding to it , as given to hm_add
 *            if key is not found : hashpair struct containing NULL for both key
 *                                  and value
 */
hashpair hm_delete_key(Hashmap *hm, void *key) {
  hashpair *start = hm->start;
  int hash = (hm->hash(key) % hm->size);  // bound the hash in memory size

  // start searching for key at offset of hash
  hashpair *search = start + hash;

  // As we have calloc-ed the memory, both key and value being zero
  // means that the location was not allocated
  while (search->key != NULL && search->value != NULL &&
         search < start + hm->size) {
    if (hm->compair(key, search->key)) {
      // if we found the key, save the key and value in structure
      // and set both in the HM to NULL
      hashpair ret = {.key = search->key, .value = search->value};
      search->key = NULL;
      search->value = NULL;
      --hm->used;
      return ret;
    }
    ++search;
  }
  // We did not find the required key, so return NULL in structure
  hashpair ret = {NULL, NULL};
  return ret;
}

/*
 * A function to delete the hashmap
 * frees the memory allocated to the hashmap
 * Params :
 * hm : Hashmap structure as returned by the make_hashmap function
 * delfn : A function which takes in two void pointers (key and value)
 *         This will be called on each key-value pair in Hashmap.
 *         Should be used to free the memory allocated to key and value, if
 *         required
 *
 */
void hm_delete(Hashmap hm, void (*delfn)(void *, void *)) {
  hashpair *start = hm.start;
  hashpair *iter = start;

  while (iter < start + hm.size) {
    // As we have calloc-ed the memory, both key and value being zero
    // means that the location was not allocated
    if (iter->key != NULL || iter->value != NULL) {
      // call delfn on giving the key and value
      delfn(iter->key, iter->value);
    }
    ++iter;
  }
  // Finally free the memory that was allocated to the HM
  free(start);
}