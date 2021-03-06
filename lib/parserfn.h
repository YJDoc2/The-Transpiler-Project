/*
 * This contains functions that are required by lexer and parser
 */
#ifndef __PARSERFN__
#define __PARSERFN__

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin, *prein;  // Flex - Bison file pointers
                            // yyin is for main parser, prein is for pre-parser
                            // which scans the file for function declarations
extern int yylineno;
extern char* yytext;

// Just a declrarion of Flex and bison functions
extern int yylex();
extern int prelex();

extern char* crr_file_name;

/*
 * Initialized required Variables And Opens the required files
 * MUST be called before calling other function in this module
 * Note this exits the program if cannot open the files, thus should be called
 * before any other init functions
 */
int __init_io__(char* infile, char* outfile);

/*
 * Cleans up the memory allocated and Closed the Files opened in this module
 * Should be called before exiting the program
 */
int __cleanup_io__();

/*
 * Function that removes code files that are created in transpilateion
 * Parmas : none
 * Returns : void
 */
void rm_files();

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
void yyerror(char* s, ...);

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
void printcode(char* s, ...);

/*
 * Prints all function declarations and required header inclusions
 * should be called after the parsing is completed
 * Also print glabal non-static variables as extern vars
 * Params : None
 *
 */
void print_code_header();

#endif