/*
 * This is an implementation of Linked List Data structure
 */
#include "linkedlist.h"

#include <stdlib.h>

/*
 * A function to make a linked list structure
 * the structure should be deleted using ll_delete after use
 * Params : none
 * Returns : a Linked_list structure
 */
Linked_list make_linkedlist() {
  Linked_list ret = {.size = 0, .start = NULL, .end = NULL};
  return ret;
}

/*
 * A function to create a new link in the list and store the data in it
 * Params :
 * ll : pointer to the LL in which link is to be added
 * data : data to be added, as a void *
 *
 * Returns : -1 if new link cannot be added
 *            0 if successful
 */
int ll_add(Linked_list *ll, void *data) {
  ll_link *last = ll->end;
  /* Use calloc so the returned memory will be zeroed and if any errors
   or invalid access, will be caught */
  ll_link *temp = (ll_link *)calloc(1, sizeof(ll_link));

  if (temp == NULL) {
    return -1;  // Memory cannot be allocated
  }

  // just a better name
  ll_link *nl = temp;
  nl->data = data;
  nl->next = NULL;
  if (last) {  // If we have a last, that is LL already has elements in it
    last->next = nl;
  } else {  // We are adding element for first time, so set the first element
    ll->start = nl;
  }

  ++ll->size;
  ll->end = nl;  // set the new element as the last element
  return 0;
}

/*
 * A function which applies given function to all the data in the LL
 * Note that this does not modify the stored data (void * given to ll_add)
 * itself, but can be used to modify contents pointed by the pointer
 *
 * Params :
 * ll : pointer to the LL in which link is to be added
 * each : A function pointer to function which takes in a void *, corresponding
 *        to data, and has void return type
 */
void ll_for_each(Linked_list *ll, void (*each)(void *)) {
  if (ll->start == NULL) return;
  int i = 1;
  ll_link *iter = ll->start;
  while (iter != NULL &&
         i <= ll->size) {  // condition on i is kept as sanity check, so even if
                           // by mistake a loop is created in LL,it will exit
                           // after expected number of elements in LL
    each(iter->data);
    iter = iter->next;
    ++i;
  }
}

/*
 * A function to delete the memory allocated to links in LL
 * Params :
 * ll : pointer to LL which is to be deleted
 * delfn : a function used to delete the data in the LL.
 *          This should take in a void *, corresponding to the data given
 *         in ll_add. This will be applied to data in all links
 */
void ll_delete(Linked_list *ll, void (*delfn)(void *)) {
  if (ll->start == NULL) return;  // empty list
  ll_link *iter = ll->start;
  ll_link *temp = iter;
  while (iter != NULL) {
    delfn(iter->data);
    temp = iter;        // keep current pointer in temp
    iter = iter->next;  // go to next link
    free(temp);         // free the memory allocated to link
  }
  // clear out the LL data
  ll->start = NULL;
  ll->end = NULL;
  ll->size = 0;
}

/*
 * An empty function which can be used as proxy for delfn when deleting LL which
 * contains references, which will be freed in different manner and no action on
 * them is required here
 */
inline void ll_nullfn(void *p) { return; }

/*
 * A function to check if two LL are same, without manually writing a loop for
 * them
 * Params :
 * l1 : first LL to compair
 * l2 : second LL to compair
 * compairfn : a function used to compair data in individual links. This should
 *             take two void pointer corresponding to data in corresponding
 *             links in both LL.
 *             Should return : 1 if both data are same
 *                             0 if two data are different
 * Returns : 0 if two LL are different
 *           1 if both LL are same (in data, not as a pointer)
 */
int are_same(Linked_list *l1, Linked_list *l2,
             int (*compairfn)(void *, void *)) {
  // if sizes are unequal, then LL cannot be same
  if (l1->size != l2->size) return 0;
  int i = 1;
  int size = l1->size;
  ll_link *t1 = l1->start;
  ll_link *t2 = l2->start;
  while (t1 != NULL && t2 != NULL && i <= size) {
    ++i;
    if (!compairfn(t1->data,
                   t2->data)) {  // if compair fn return 0, which
                                 // means the data was different, return with 0
      return 0;
    }
    // Go to next links of both
    t1 = t1->next;
    t2 = t2->next;
  }
  if (i != l1->size + 1)
    return 0;  // sanity check in case one somehow, 'next' of a link which is
               // not end in any of LL was manually set to NULL
  return 1;
}