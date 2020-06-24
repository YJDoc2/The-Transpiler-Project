/*
 * Contains funtions related to filenames that are scanned in transpilation
 */
#include "filenames.h"

#include <string.h>
Linked_list names, temp;

// Helper function to delete the linkedlist
void del_ll(void *val) { free(val); }

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_files__() { names = make_linkedlist(); }

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_files__() {
  ll_delete(&names, del_ll);
  ll_delete(&temp, del_ll);
}

/*
 * Function to insert a name in the list, does not check if name already exists
 *
 * Params :
 * name : name of the file, duplicated inside so can be freed after call
 *
 * Returns : pointer to the duplicated file name
 */
char *insert_filename(char *name) {
  char *t = strdup(name);
  ll_add(&names, t);
  return t;
}

/*
 * Function to check if the filename is in the list or not
 * Params :
 * name : name of file to check
 *
 * Returns : true if the name is already in the list
 *           false if the name is not in the list
 */
bool is_visited(char *name) {
  ll_link *iter = names.start;

  while (iter != NULL) {
    if (strcmp(iter->data, name) == 0) {
      return true;
    }
    iter = iter->next;
  }
  return false;
}

/*
 * This function in made so that after preparsing we can switch the list, and
 * the pointers to filenames in the method which were created in preparsing
 * would still be valid until end of program
 *
 * Parmas : none
 * Returns : void
 *
 */
void switch_list() {
  temp = names;
  names = make_linkedlist();
}