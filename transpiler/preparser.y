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

%type <t> type
%type <m> modifier

%%
fndecllist :/*nothing*/
    | fndecllist fndeclaration
    | fndecllist error {printf("text = %s on line %d\n",yytext,yylineno);}

fndeclaration : FNDECL IDENTIFIER '(' paramlist ')' "->" modifier type '{'{in_fn = true;}'}' {add_function($7,$8,$2,$2,yylineno);free($2);in_fn=false;}


paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,$3); free($3);}                  


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