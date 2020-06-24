/*
 * This contains functions that are required by lexer and parser
 */
#include "parserfn.h"

#include <errno.h>
#include <libgen.h>
#include <string.h>

#include "class_decl.h"
#include "functions.h"

extern char *type_arr[], *mod_arr[];
extern Hashmap classmap;
extern Hashmap varmap;

int errs = 0;  // number or errors in input, if non-zero at end of
               // parsing, delete the temp file

// way to skip the extra 'Syntax error' message of Bison
static int last_err = -1;

char *crr_file_name;
char *main_file_headname;

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
  crr_file_name = infile;
  char *out = outfile == NULL ? infile : outfile;
  // 3 =  two for '.' and ext one for end-of-string 0
  char codename[strlen(out) + 3];
  char headname[strlen(out) + 3];
  strcpy(codename, out);
  strcpy(headname, out);
  for (int i = strlen(out) - 1; i > 0; --i) {
    if (codename[i] == '.') {
      strcpy(codename + i, ".c\0");
      strcpy(headname + i, ".h\0");
      break;
    }
  }

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
  main_file_headname = (char *)calloc(1, strlen(headname));
  strcpy(main_file_headname, headname);
  printcode("#include \"%s\"\n\n", headname);
  return 0;
}

/*
 * Cleans up the memory allocated and Closed the Files opened in this module
 * Should be called before exiting the program
 */
int __cleanup_io__() {
  free(main_file_headname);
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
  // if (last_err == yylineno && strcmp(s, "syntax error") == 0) return;

  last_err = yylineno;
  ++errs;

  // set up variable arg structs etc
  va_list ap;
  va_start(ap, s);

  // print ther error to stderr
  fprintf(stderr, "%s : line %d : error : ", crr_file_name, yylineno);
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

// Helper function to print a single Param in function declaration
static inline void print_param(Param *p) {
  fprintf(header, "%s %s %s", mod_arr[p->m],
          p->is_class ? p->t.class : type_arr[p->t.t], p->name);
  if (p->is_arr) {
    fprintf(header, "[] ");
  } else {
    fprintf(header, " ");
  }
}

// Helper function to print parameters of the function in function declarations
static void print_params(Linked_list *paramlist) {
  // if function does not take any Param paramlist will be empty
  if (paramlist == NULL) return;

  ll_link *iter = paramlist->start;

  // print first param, this is done outside the loop as after this each param
  // must be preceeded with a ','
  print_param((Param *)iter->data);
  // if function has only one param
  if (iter->next == NULL) return;
  iter = iter->next;
  // print rest of the prams
  while (iter != NULL) {
    fprintf(header, ",");
    print_param((Param *)iter->data);
    iter = iter->next;
  }
  return;
}

/*
 * Prints all function declarations and required header inclusions
 * should be called after the parsing is completed
 * Also print glabal non-static variables as extern vars
 *
 * Params : None
 *
 */
void print_code_header() {
  fprintf(header,
          "#include<stdio.h>\n#include<stdlib.h>\n#include<stdbool.h>\n#"
          "include<complex.h>\n\n");
  char *name = basename(main_file_headname);
  name[strlen(name) - 2] = '\0';
  fprintf(header, "#ifndef __%s__ \n", name);
  fprintf(header, "#define __%s__ \n", name);

  hashpair *iter = classmap.start;
  hashpair *end = classmap.start + classmap.size;

  while (iter <= end) {
    if (iter->key != NULL || iter->value != NULL) {
      Class *c = iter->value;
      fprintf(header, "#include \"class_%s.h\"\n", c->name);
    }
    ++iter;
  }
  iter = fnmap.start;
  end = fnmap.start + fnmap.size;
  while (iter <= end) {
    if (iter->key != NULL || iter->value != NULL) {
      Function *f = (Function *)iter->value;
      fprintf(header, "%s %s %s(", mod_arr[f->ret_m],
              f->is_ret_class ? f->ret_t.class : type_arr[f->ret_t.t],
              f->print_name);
      print_params(f->param_list);
      fprintf(header, " );\n\n");
    }
    ++iter;
  }

  iter = varmap.start;
  end = varmap.start + varmap.size;
  while (iter <= end) {
    if (iter->key != NULL || iter->value != NULL) {
      Variable *v = (Variable *)iter->value;
      if (v->m != STATIC_TYPE) {
        fprintf(header, "extern %s %s;\n", type_arr[v->t.t], v->name);
      }
    }
    ++iter;
  }

  fprintf(header, "\n\n#endif\n");
}
