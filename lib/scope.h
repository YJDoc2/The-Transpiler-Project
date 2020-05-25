#ifndef __SCOPE__
#define __SCOPE__
#include "stack.h"
extern Stack scopelist;

void __init_scopes__();
void __cleanup_scopes__();

void pushscope();
void popscope();

#endif