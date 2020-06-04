/*
 * contains all 'actions' related code
 * Here 'actions' mean a special token/function in the transpiler,which
 * generates different required code in the C file
 */
#ifndef __ACTIONS__
#define __ACTIONS__

#include "common.h"
#include "hashmap.h"
#include "linkedlist.h"
#include "parserfn.h"
#include "tempvar.h"
#include "variables.h"

/*
 * Initializes all DS and variables required in this module
 * Must be called before using any other functions in this module
 */
void __init_actions__();

/*
 * cleans up ,and frees memory that was used by this module
 * Should be called before exiting the program
 */
void __cleanup_actions__();
/*
 * Find if there is an action corresponding to given name
 * Params :
 * s : char * to name of the action to be found
 * Returns : 1 if corresponding action exists
 *           0 if no action is found
 */
int find_action(char* s);

/*
 * Perform action corresponding to given name
 * Note that the actions will clear the arglist after using, if the action
 * exists
 * Params : s : name of the action to be performed
 */
void perform_action(char* s);

#endif