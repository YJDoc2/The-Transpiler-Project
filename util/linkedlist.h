/*
 * This is an implementation of Linked List Data structure
 */
#ifndef __LINKEDLIST__
#define __LINKEDLIST__
// A short notation to delete Linked list if all elements are statically
// allocated, eg : its , floats etc, or are pointers to other memory
// structures, which will be freed in some other place
#define ll_clear(ll) ll_delete((ll), ll_nullfn)
/*
 * A single link in the linked list
 * data : a void * to data
 * next : pointer to next link
 */
typedef struct ll_link {
  void *data;
  struct ll_link *next;
} ll_link;

/*
 * Linked list structure
 * size : number of links in the LL
 * start : pointer to first link
 * end : pointer to the last link : kept so adding operations can be done in
 *       constant time (without iterating over whole LL)
 */
typedef struct {
  int size;
  ll_link *start;
  ll_link *end;
} Linked_list;

/*
 * A function to make a linked list structure
 * the structure should be deleted using ll_delete after use
 * Params : none
 * Returns : a Linked_list structure
 */
Linked_list make_linkedlist();

/*
 * A function to create a new link in the list and store the data in it
 * Params :
 * ll : pointer to the LL in which link is to be added
 * data : data to be added, as a void *
 *
 * Returns : -1 if new link cannot be added
 *            0 if successful
 */
int ll_add(Linked_list *ll, void *data);

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
void ll_for_each(Linked_list *ll, void (*each)(void *));

/*
 * A function to delete the memory allocated to links in LL
 * Params :
 * ll : pointer to LL which is to be deleted
 * delfn : a function used to delete the data in the LL.
 *          This should take in a void *, corresponding to the data given
 *         in ll_add. This will be applied to data in all links
 */
void ll_delete(Linked_list *ll, void (*delfn)(void *));

/*
 * An empty function which can be used as proxy for delfn when deleting LL which
 * contains references, which will be freed in different manner and no action on
 * them is required here
 */
void ll_nullfn(void *);

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
             int (*compairfn)(void *, void *));
#endif