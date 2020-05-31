#ifndef __PARSERFN__
#define __PARSERFN__

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define ERR_LIM 10

extern FILE *yyin, *prein;
extern int yylineno;
extern char* yytext;

extern int yylex();

void yyerror(char* s, ...);

int printcode(char* s, ...);
// int printheader();  //! ???ARGS???

int __init_io__(char* infile, char* outfile);
int __cleanup_io__();

#endif