#ifndef __COMMON__
#define __COMMON__

#include <string.h>

#include "linkedlist.h"

extern Linked_list *arglist;
int __hash_str__(void *s);
int __compair__str__(void *a, void *b);

#endif