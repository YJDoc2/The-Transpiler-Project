#ifndef __LITERAL__
#define __LITERAL__

#include <stdlib.h>

#include "linkedlist.h"
#include "variables.h"

void __init_literals__();
void *add_literal(modifier m, type t, char *ident);
void clear_literals();
void __cleanup_literals__();

#endif