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
    extern Hashmap pre_class_map;
    //!TODO maybe combine in_fn and pre_in_class
    static void pre_add_class(char *);
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
%token <s> CLASSNAME
%type <t> type
%type <m> modifier
%type <s> ident
%type <s> clsname

%%

program : stmtlist

stmtlist :/*nothing*/
    | stmtlist fndeclaration
    | stmtlist error
    | stmtlist vardecl
    | stmtlist classdecl

classdecl : CLASS ident '{' {pre_add_class($2);pre_in_class = true;} '}' {pre_in_class = false;free($2);}

fndeclaration : FNDECL ident '(' paramlist ')' "->" modifier type {fnlineno=prelineno;}'{'{in_fn = true;}'}' {if(!pre_in_class)add_function($7,$8,$2,$2,fnlineno);free($2);in_fn=false;}

vardecl: modifier type IDENTIFIER 
    | modifier CLASSNAME IDENTIFIER 

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type ident    {if(!pre_in_class)add_param($1,$2,false,$3); free($3);}      
    | modifier type ident '[' ']' {if(!pre_in_class)add_param($1,$2,true,$3);free($3);}    
    | modifier clsname ident {if(!pre_in_class)add_class_param($1, $2, false,$3);free($2);free($3);}    
    | modifier clsname ident '[' ']' {if(!pre_in_class)add_class_param($1, $2, true,$3);free($2),free($3);}           

;
ident : IDENTIFIER {$$ = strdup($1);}
;
clsname : CLASSNAME    {$$ = strdup($1);}
;
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

void pre_add_class(char *name){
    // must use a temp, otherwise the pointer defaults to null somehow in next call
    void * temp = strdup(name);
    hm_add(&pre_class_map,temp,temp);
}

void pre_class_clean(void *key,void*val){
    // key and val are same pointer
    free(key);
}