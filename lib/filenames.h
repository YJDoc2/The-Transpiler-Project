/*
 * Contains funtions related to filenames that are scanned in transpilation
 */

#ifndef __FILE_NAMES__
#define __FILE_NAMES__

#include <stdbool.h>

#include "linkedlist.h"
#include "stdlib.h"

/*
 * initializes all required DS and allocated memory in this module
 * Must be called before any other function call in this module
 */
void __init_files__();

/*
 * cleans up and frees the memory allocated in this module
 * Should be called before exiting the program
 */
void __cleanup_files__();

/*
 * Function to insert a name in the list, does not check if name already exists
 *
 * Params :
 * name : name of the file, duplicated inside so can be freed after call
 *
 * Returns : pointer to the duplicated file name
 */
char* insert_filename(char* name);

/*
 * Function to check if the filename is in the list or not
 * Params :
 * name : name of file to check
 *
 * Returns : true if the name is already in the list
 *           false if the name is not in the list
 */
bool is_visited(char* name);

/*
 * This function in made so that after preparsing we can switch the list, and
 * the pointers to filenames in the method which were created in preparsing
 * would still be valid until end of program
 *
 * Parmas : none
 * Returns : void
 *
 */
void switch_list();

#endif