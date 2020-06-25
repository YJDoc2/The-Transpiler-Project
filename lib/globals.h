/*
 * Defines convenience function to call all init functions
 */
#ifndef __GLOBALS__
#define __GLOBALS__

/*
 * Function which invokes all init functions from library files
 */
void global_init(char *, char *);

/*
 * Function which invokes all cleanup funtions from library files
 */
void global_cleanup();

#endif