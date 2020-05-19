#include "parserfn.h"

#include <errno.h>
#include <string.h>

static int errs = 0;

FILE *code = NULL;
FILE *header = NULL;

int yyerror(char *s, ...) {
  ++errs;
  va_list ap;
  va_start(ap, s);
  fprintf(stderr, "line %d : error : ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
  if (errs > ERR_LIM) {
    __cleanup_io__();
    exit(EXIT_FAILURE);
  }
}

int __init_io__(char *infile, char *outfile) {
  if (infile == NULL) {
    fprintf(stderr, "No input file found. exiting...\n");
    __cleanup_io__();
    exit(1);
  }
  yyin = fopen(infile, "r");
  if (yyin == NULL) {
    perror("cannot open given codefile");
    __cleanup_io__();
    exit(EXIT_FAILURE);
  }
  if (outfile == NULL) {
    code = stdout;
    header = stdout;
    return 0;
  }
  char tok[2] = ".";
  char *name = strtok(infile, tok);
  char codename[strlen(name) + 3];
  char headname[strlen(name) + 3];
  strcpy(codename, name);
  strcpy(headname, name);
  strcat(codename, ".c");
  strcat(headname, ".h");
  code = fopen(codename, "w");
  if (code == NULL) {
    perror("cannot create new file for compiling");
    __cleanup_io__();
    exit(EXIT_FAILURE);
  }
  header = fopen(headname, "w");
  if (header == NULL) {
    perror("cannot create new file for compiling");
    __cleanup_io__();
    exit(EXIT_FAILURE);
  }
  return 0;
}

int __cleanup_io__() {
  if (code != NULL) {
    fclose(code);
  }
  if (header != NULL) {
    fclose(header);
  }
  if (yyin != NULL) {
    fclose(yyin);
  }
  return 0;
}

int printcode(char *s, ...) {
  va_list ap;
  va_start(ap, s);
  vfprintf(code, s, ap);
}