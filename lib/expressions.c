#include "expressions.h"

#include <stdlib.h>
#include <string.h>

#include "stack.h"

// stacks for expr_type and arglist pointers
Stack exprt_st, args_st;

/*
 * initializes all DS required in this module
 * Must be called before any other function call in this module
 */
void __init_expr__() {
  exprt_st = make_stack();
  args_st = make_stack();
}

/*
 * Helper function to clean up the stacks
 */
void __clean_args_st__(void *a) {
  if (a == NULL)
    return;  // the data can be empty if push is called with un-initialized
             // arglist
  Linked_list *l = (Linked_list *)a;
  ll_clear(l);  // as arglist contains only references no
                // need to free those
  free(a);      // free the memory allocated for the arglist struct
}

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_expr__() {
  st_delete(&exprt_st, ll_nullfn);  // expr_type are only ints/enum value so
                                    // nothing special is needed
  st_delete(&args_st, __clean_args_st__);
}

/*
 * A function to push the current arglist pointer and expression type and
 * allocate memory for new arglist
 * This is used while parsing nested function calls eg :
 * fn1 ( fn2 ( fn3 () ),fn4 ( a,b,c ) )
 *
 * Params : none
 * Returns : void
 */
void push_expr_and_args() {
  st_push(&exprt_st, (void *)expr_type);  // push the current expr_type
  st_push(&args_st, (void *)arglist);     // push the current arglist pointer
  arglist = (Linked_list *)calloc(
      1, sizeof(Linked_list));  // allocate memory for a new arglist
  *arglist = make_linkedlist();
  expr_type = VOID_TYPE;  // set the expr_type to void
}

/*
 * A function to clear and free the current arglist, and then pop the arglist
 * and expr type that is in the stack
 *
 * Params : none
 * Returns : void
 */
void pop_expr_and_args() {
  ll_clear(arglist);  // as arglist contain only references no need for any
                      // specail clearing function
  free(arglist);      // free memory
  void *_t = st_pop(&exprt_st);  // get last expr_type from stack
  expr_type = _t == (void *)-1
                  ? VOID_TYPE
                  : (type)_t;  // if stack was empty set type as VOID_TYPE
  arglist = (Linked_list *)st_pop(&args_st);
}

/*
 * Joins all three of given strings.
 * Note that this does not modify or free the input strings, and allocates
 * memory for joined string
 * Used to join expressions by operations sign eg : a +
 * b This will be given "a","+" and "b" and will return "a+b"
 *
 * Params :
 * three pointers to strings to be joined, in order to be joined
 *
 * Returns : concatenated string pointer
 */
char *join(char *start, char *middle, char *end) {
  void *_t = calloc(1, strlen(start) + strlen(middle) + strlen(end) + 1);
  strcat(_t, start);
  strcat(_t, middle);
  strcat(_t, end);
  return (char *)_t;
}

/*
 * A function to verify if the combining_type type can be  combined with
 * combining_type.
 * This is used for checking compatible types in variable assignments
 * This should be replaced with better implementation
 * Params :
 * combining_with : type to which value is assigned
 * combining_type : type of value to be assigned
 *
 * Returns : 1 if types are incompatible
 *          0 if types can be combined
 *
 */
int verify_types(type combining_with, type combining_type) {
  if (combining_type == CLASS_TYPE && combining_with != CLASS_TYPE ||
      combining_type != CLASS_TYPE && combining_with == CLASS_TYPE) {
    return 1;
  }
  if (combining_type == VOID_TYPE || combining_with == VOID_TYPE)
    return 1;  // if either was void its incorrect

  if (combining_with == STRING_TYPE) {  // only string can be assigned to string
    if (combining_type != STRING_TYPE) return 1;
  }
  if (combining_with == FLOAT_TYPE || combining_with == DOUBLE_TYPE) {
    // other than bool, string and comlex others can be assigned to float/double
    if (combining_type == BOOL_TYPE || combining_type == STRING_TYPE ||
        combining_type == COMPLEX_TYPE) {
      return 1;
    }
  }

  if (combining_with == INT_TYPE || combining_with == SHORT_TYPE ||
      combining_with == LONG_TYPE) {
    // only int like can be assigned to in like
    if (!(combining_type == INT_TYPE || combining_type == SHORT_TYPE ||
          combining_type == LONG_TYPE)) {
      return 1;
    }
  }

  if (combining_with == BOOL_TYPE)  // bool only with bool
    if (combining_type != BOOL_TYPE) return 1;

  if (combining_with ==
      COMPLEX_TYPE)  // complex can take anything except bool and string
    if (combining_type == BOOL_TYPE || combining_type == STRING_TYPE) return 1;

  return 0;
}
