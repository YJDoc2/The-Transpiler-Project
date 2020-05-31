#ifndef __EXPR__
#define __EXPR__
#include "functions.h"
#include "variables.h"
extern type arg_type, expr_type;

char *join(char *, char *, char *);
int verify_types(type combining_with, type combining_type);

void __init_expr__();
void __cleanup_expr__();

void set_arg_iter(char *);

void push_arg_type();
void pop_arg_type();
void push_expr_type();
void pop_expr_type();

#endif