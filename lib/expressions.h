#ifndef __EXPR__
#define __EXPR__
#include "functions.h"
#include "variables.h"
extern type arg_type, expr_type;

char *join(char *, char *, char *);
int verify_types(type combining_with, type combining_type);

void __init_expr__();
void __cleanup_expr__();

void push_expr_and_args();
void pop_expr_and_args();

#endif