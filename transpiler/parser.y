%{
    #include<stdio.h> 
    #include<stdlib.h>   
    #include<string.h>
    #include "variables.h"
    #include "parserfn.h"
    
%}

%union{
    char *s;
    type t;
    modifier m;
}

%token <t> BOOL COMPLEX
%token <m> CONST STATIC
%token <t> DOUBLE FLOAT LONG SHORT VOID INT

%token BREAK CONTINUE ELSE FOR IF
%token RETURN WHILE

%token TRUE FALSE I
%token IN NOT RAW USE
%token DECL 
%token <s> IDENTIFIER

%token <s> INTNUM FLOATNUM

%token RAWSTART "<{"
%token <s> RAWEND "}>"
%token <s> RAWLINE

%type <t> type
%type <m> modifier

%type <s> value

%%
program : stmtlist
;

stmtlist :/* nothing */
    | stmtlist error
    | stmtlist stmt
;

stmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | declaration ';'
    | declaration {yyerror("missing ;");}
;

rawlist : /* nothing */
    | rawlist RAWLINE   {printcode("%s",$2);}

type : INT
    | LONG
    | SHORT
    | FLOAT
    | DOUBLE
    | BOOL
    | COMPLEX
    | VOID

modifier : /* nothing */ {$$ = NONE_TYPE; }
    | CONST
    | STATIC


declaration : DECL modifier type IDENTIFIER {/*decl_var($2,$3,$4); ONLY ADD NO DECLARATION */}
    | modifier type IDENTIFIER    {decl_var($1,$2,$3);}
    | assignment

assignment : modifier type IDENTIFIER '=' value {assg_decl_var($1,$2,$3,$5);}

value : INTNUM
    | FLOATNUM
    | IDENTIFIER


%%

void main(int argc , char **argv){

    __init_io__("./test.t",NULL);
    yyparse();
    __close_io__();
}
