#ifndef __ACTIONS__
#define __ACTIONS__

#include "common.h"
#include "hashmap.h"
#include "linkedlist.h"
#include "parserfn.h"
#include "tempvar.h"
#include "variables.h"

extern Linked_list arglist;

void __init_actions__();
void __cleanup_actions__();
int find_action(char* s);
void perform_action(char* s);

#endif