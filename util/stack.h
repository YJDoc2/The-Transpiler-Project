/*
 * This is an implementation of Stack Data structure using Linked-list type
 * arrangement ( Not the Linked_list )
 */
#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
/*
 * The stack is implemented using a Linked List type structure
 * (Not the Linked_list )
 * This is structure for individual element in the stack
 * data : a void * to data
 * next : pointer to next element
 */
typedef struct stack_link {
  void *data;
  struct stack_link *next;
} stack_link;

/*
 * The Stack structure
 * size : corrent size of stack
 * top : pointer to top of stack
 */
typedef struct {
  int size;
  stack_link *top;
} Stack;

/*
 * Function to create a new Stack structure
 * This should be deleted using st_delete after use
 * Params : none
 * Returns : a Stack structure
 */
Stack make_stack();

/*
 * A function to insert data in the stack
 * Params :
 * st : pointer to stack in which data is to be inserted
 * data : the data to be inserted as void *
 *
 * Returns : -1 if insertion was unsuccessful
 *            0 : if data was successfully insterted
 */
int st_push(Stack *st, void *data);

/*
 * A function to pop data from stack
 * Params :
 * st : pointer to stack from which data is to be pop-ed
 *
 * Returns : the void * which was given as data to st_push function in topmost
 *           element
 *          NULL if stack is empty
 */
void *st_pop(Stack *st);

/*
 * A function to free the memory allocated to stack
 * Params :
 * st : pointer to stack from which data is to be pop-ed
 * delfn : a function which will be given each data still in the stack
 *        it should take a void * corresponding to the data given in st_push
 */
void st_delete(Stack *st, void (*delfn)(void *));

#endif