/*
 * This is an implementation of HashMap Data structure
 */
#ifndef __HASHMAP__
#define __HASHMAP__

#define ll_clear(ll) ll_delete((ll), ll_nullfn)

/*
 * Individual key-value pair in hashmap
 * both key as well as value are represented as void *
 */
typedef struct {
  void *key;
  void *value;
} hashpair;

/* Hashmap struct
 * size : the maximum amount of elements it can store
 * used : number of elements currently stored
 * start : pointer to start of hashmap
 * hash : function pointer to a function which takes in a void pointer (key) and
 *        return an int (hash) of that key
 * compair : function pointer to a function which takes in
 *          two void pointers (two keys) and returns an int
 *          indicating if they're same or not
 *          0 : if not same
 *          1 : if same
 */
typedef struct {
  int size;
  int used;
  hashpair *start;
  int (*hash)(void *);
  int (*compair)(void *, void *);
} Hashmap;

/*
 * Function to create Hashmap structure
 * the structure received should be deleted after use by
 * using function hm_delete
 *
 * Params :
 * size : Initial size allocated to hasmap
 * hashfn : A function which takes in a void pointer (key)
 *          and returns an int representing the hash of that key
 * compair : A function which takes two void pointers (two keys)
 *          and returns if the keys are same or not.
 *          0 : if different
 *          1 : if same
 * Returns : A struct Hashmap.
 */
Hashmap make_hashmap(int size, int (*hashfn)(void *),
                     int (*compair)(void *, void *));

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
int hm_add(Hashmap *hm, void *key, void *value);

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
void *hm_get(Hashmap *hm, void *key);

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
hashpair hm_delete_key(Hashmap *hm, void *key);

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
void hm_delete(Hashmap hm, void (*delfn)(void *, void *));

#endif
