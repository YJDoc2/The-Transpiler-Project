%{
    #include<stdio.h> 
    #include<stdlib.h>   
    #include<string.h>
    #include <stdbool.h>
    #include "variables.h"
    #include "parserfn.h"
    #include "actions.h"
    #include "literals.h"
    #include "functions.h"
    #include "scope.h"
    #include "expressions.h"
    bool in_fn = false;
    extern int prelineno;
    int fnlineno = 0;
    bool pre_in_class = false;
    //!TODO maybe combine in_fn and pre_in_class
%}

%union{
    char *s;
    type t;
    modifier m;
}

%define api.prefix {pre}

%token <t> BOOL COMPLEX
%token <m> CONST STATIC
%token <t> DOUBLE FLOAT LONG SHORT VOID INT
%token <t> STRING

%token FNDECL 
%token RETTYPE "->"

%token <s> IDENTIFIER

%token CLASS

%type <t> type
%type <m> modifier
%type <s> ident

%%

program : stmtlist

stmtlist :/*nothing*/
    | stmtlist fndeclaration
    | stmtlist error
    | stmtlist vardecl
    | stmtlist classdecl

classdecl : CLASS IDENTIFIER'{' {pre_in_class = true;} '}' {pre_in_class = false;}

fndeclaration : FNDECL ident '(' paramlist ')' "->" modifier type {fnlineno=prelineno;}'{'{in_fn = true;}'}' {if(!pre_in_class)add_function($7,$8,$2,$2,fnlineno);free($2);in_fn=false;}

vardecl: modifier type ident {free($3);}

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type ident    {if(!pre_in_class)add_param($1,$2,false,$3); free($3);}      
    | modifier type ident '[' ']' {if(!pre_in_class)add_param($1,$2,true,$3);free($3);}            


ident : IDENTIFIER {$$ = strdup($1);}

type : INT
    | LONG
    | SHORT
    | FLOAT
    | DOUBLE
    | BOOL
    | COMPLEX
    | VOID
    | STRING
;

modifier : /* nothing */ {$$ = NONE_TYPE; }
    | CONST
    | STATIC
;

%%