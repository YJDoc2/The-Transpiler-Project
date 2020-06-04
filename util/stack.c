/*
 * This is an implementation of Stack Data structure using Linked-list type
 * arrangement ( Not the Linked_list )
 */

#include "stack.h"

/*
 * Function to create a new Stack structure
 * This should be deleted using st_delete after use
 * Params : none
 * Returns : a Stack structure
 */
Stack make_stack() {
  Stack ret = {.size = 0, .top = NULL};
  return ret;
}

/*
 * A function to insert data in the stack
 * Params :
 * st : pointer to stack in which data is to be inserted
 * data : the data to be inserted as void *
 *
 * Returns : -1 if insertion was unsuccessful
 *            0 : if data was successfully insterted
 */
int st_push(Stack *st, void *data) {
  // allocate memory for a new element in stack.
  // Use calloc so the returned memory will be zeroed and if any errors
  // or invalid access, will be caught
  stack_link *temp = (stack_link *)calloc(1, sizeof(stack_link));
  if (temp == NULL) {
    return -1;  // memory could not be allocated
  }
  // just a different name
  stack_link *nl = temp;
  nl->data = data;
  nl->next = st->top;

  st->top = nl;
  ++st->size;

  return 0;
}

/*
 * A function to pop data from stack
 * Params :
 * st : pointer to stack from which data is to be pop-ed
 *
 * Returns : the void * which was given as data to st_push function in topmost
 *           element
 *          NULL if stack is empty
 */
void *st_pop(Stack *st) {
  if (st->top == NULL)
    return (void *)-1;  // Stack is empty MUST return one as in expression.c
                        // NULL (0) can be confused with incorrect expr_type

  stack_link *temp = st->top;
  st->top = st->top->next;
  --st->size;
  void *ret = temp->data;
  // free memory allocated to the stack_link
  free(temp);
  // return the data in the element
  return ret;
}

/*
 * A function to free the memory allocated to stack
 * Params :
 * st : pointer to stack from which data is to be pop-ed
 * delfn : a function which will be given each data still in the stack
 *        it should take a void * corresponding to the data given in st_push
 */
void st_delete(Stack *st, void (*delfn)(void *)) {
  stack_link *iter = st->top;
  stack_link *temp;
  while (iter != NULL) {
    delfn(iter->data);
    temp = iter;
    iter = iter->next;
    free(temp);
  }
  return;
}