/*
 * This contains functions that are required by lexer and parser
 */
#include "parserfn.h"

#include <errno.h>
#include <string.h>

int errs = 0;  // number or errors in input, if non-zero at end of parsing,
               // delete the temp file

// way to skip the extra 'Syntax error' message of Bison
static int last_err = -1;

char *crr_file_name;

//! TODO Both says current as for generating classes if implemented these
//! can be switched to different files
FILE *code = NULL;  // current file in generated code is to be written

FILE *header = NULL;  // currenet file in which header stuff ( function
                      // declaration ) are to be written

/*
 * Initialized required Variables And Opens the required files
 * MUST be called before calling other function in this module
 * Note this exits the program if cannot open the files, thus should be called
 * before any other init functions
 */
int __init_io__(char *infile, char *outfile) {
  if (infile == NULL) {
    fprintf(stderr, "No input file found. exiting...\n");
    __cleanup_io__();
    exit(1);
  }

  // even though same file is opened, open it twice as otherwise prin consumes
  // the whole file and main parser doesn't get anything
  yyin = fopen(infile, "r");
  prein = fopen(infile, "r");

  if (yyin == NULL || prein == NULL) {
    perror("cannot open given codefile");
    __cleanup_io__();
    exit(EXIT_FAILURE);
  }
  //! TODO temporary hack
  if (outfile == NULL) {
    code = stdout;
    header = stdout;
    return 0;
  }
  // get the basename of fle
  char tok[2] = ".";
  crr_file_name = strtok(infile, tok);

  // 3 =  two for '.' and ext one for end-of-string 0
  char codename[strlen(crr_file_name) + 3];
  char headname[strlen(crr_file_name) + 3];
  strcpy(codename, crr_file_name);
  strcpy(headname, crr_file_name);
  strcat(codename, ".c");
  strcat(headname, ".h");  //! TODO use this
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

/*
 * Cleans up the memory allocated and Closed the Files opened in this module
 * Should be called before exiting the program
 */
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
  if (prein != NULL) {
    fclose(prein);
  }

  return 0;
}

/*
 * A function to print errors to stderr according to given format string
 *
 * Params :
 * s : the format string
 * ... : the optional arguments that are to be substituted in the format
 *       specifiers in the format string
 *
 * Returns : void
 */
void yyerror(char *s, ...) {
  // if the error is on same line as previously given, and is equal to
  //'syntax error',return without adoing anything
  if (last_err == yylineno && strcmp(s, "syntax error") == 0) return;

  last_err = yylineno;
  ++errs;

  // set up variable arg structs etc
  va_list ap;
  va_start(ap, s);

  // print ther error to stderr
  fprintf(stderr, "line %d : error : ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");

  if (errs > ERR_LIM) {
    __cleanup_io__();  //! TODO change to GLOBAL_EXIT, which will call all
                       //! cleanup functions
    exit(EXIT_FAILURE);
  }
}

/*
 * A function that actually prints the code to the output files
 *
 * Params :
 * s : the format string
 * ... : the optional arguments that are to be substituted in the format
 *       specifiers in the format string
 *
 * Returns : void
 */
void printcode(char *s, ...) {
  va_list ap;
  va_start(ap, s);
  vfprintf(code, s, ap);
}
