%{
    #include<stdio.h> 
    #include<stdlib.h>   
    #include<string.h>
    #include "variables.h"
    #include "parserfn.h"
    #include "actions.h"
    #include "literals.h"
    #include "functions.h"
%}

%union{
    char *s;
    type t;
    modifier m;
}

%token <t> BOOL COMPLEX
%token <m> CONST STATIC
%token <t> DOUBLE FLOAT LONG SHORT VOID INT
%token <t> STRING

// temp
%token PRINTACT
%token INPUTACT

%token BREAK CONTINUE ELSE FOR IF
%token RETURN WHILE

%token I
%token IN NOT RAW USE
%token DECL 
%token <s> IDENTIFIER BOOLVAL STRINGVAL
%token FNDECL 
%token RETTYPE "->"
%token <s> INTNUM FLOATNUM

%token RAWSTART "<{"
%token <s> RAWEND "}>"
%token <s> RAWLINE

%type <t> type
%type <m> modifier

%type <s> value cmplxnum

%%
program : topstmtlist
;

topstmtlist :  /* nothin */
    | topstmtlist error {yyerror("unknown token %s\n",yytext);}
    | topstmtlist topstmt


topstmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | vardeclaration ';'
    | vardeclaration {yyerror("missing ;");}
    | fndeclaration

fndeclaration : FNDECL IDENTIFIER '(' paramlist ')' "->" modifier type {add_function($7,$8,$2,$2,yylineno);print_fn_delc($2); free($2);} '{' stmtlist'}' {printcode("}\n");}

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,$3);create_var($1,$2,$3,yylineno); free($3);}

stmtlist :/* nothing */
    | stmtlist error {yyerror("unknown token %s\n",yytext);}
    | stmtlist stmt
;

stmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | vardeclaration ';'
    | vardeclaration {yyerror("missing ;");}
    | printactstmt ';'
    | printactstmt {yyerror("missing ;");}
    | inputactstmt ';'
    | inputactstmt {yyerror("missing ;");}
;

printactstmt : PRINTACT '(' arglist ')' {perform_action("print");clear_literals();}
inputactstmt : INPUTACT '(' arglist ')' {perform_action("input");clear_literals();}

arglist : /* nothing */
    | arglist args
    | arglist ',' args
;

args : IDENTIFIER  {Variable *v = lookup_var($1);
                    if(v == NULL){
                        yyerror("Undefined variable %s",$1);
                    }else{
                        ll_add(&arglist,v);
                    }}
        | INTNUM {void* v = add_literal(NONE_TYPE,INT_TYPE,$1);
                    ll_add(&arglist,v);}
        | FLOATNUM {void* v = add_literal(NONE_TYPE,DOUBLE_TYPE,$1);
                    ll_add(&arglist,v);}
        | cmplxnum {void* v = add_literal(NONE_TYPE,COMPLEX_TYPE,$1);
                    ll_add(&arglist,v);}
        | BOOLVAL {void* v = add_literal(NONE_TYPE,BOOL_TYPE,$1);
                    ll_add(&arglist,v);}
        | STRINGVAL   {void *v = add_literal(NONE_TYPE,STRING_TYPE,$1);ll_add(&arglist,v);}


rawlist : /* nothing */
    | rawlist RAWLINE   {printcode("%s",$2); free($2);}
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

vardeclaration : DECL modifier type IDENTIFIER {create_var($2,$3,$4,yylineno); free($4); }
    | modifier type IDENTIFIER    {add_var($1,$2,$3,yylineno); free($3);}
    | assignment
;
assignment : modifier type IDENTIFIER '=' value {lhst = $2;verify_types();add_var_assg($1,$2,$3,$5,yylineno);free($3);free($5);}
;
value : cmplxnum {rhst = COMPLEX_TYPE;}
    | INTNUM {rhst = INT_TYPE;}
    | FLOATNUM {rhst = FLOAT_TYPE;}
    | IDENTIFIER { Variable *_t = lookup_var($$);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$$);
                    }else{
                        rhst = _t->t;
                    }}
    | BOOLVAL   {rhst = BOOL_TYPE;}
    | STRINGVAL {rhst = STRING_TYPE;}
;

cmplxnum : value '+' value '*' I {void *_t = calloc(1,strlen($1)+strlen($3)+1); 
                                    strcat(_t,$1);strcat(_t,"+");strcat(_t,$3);strcat(_t,"*I");
                                    $$ = (char*)_t;}
    | value '-' value '*' I      {void *_t = calloc(1,strlen($1)+strlen($3)+1); 
                                    strcat(_t,$1);strcat(_t,"-");strcat(_t,$3);strcat(_t,"*I");
                                    $$ = (char*)_t;}
    | value value '*' I{void *_t = calloc(1,strlen($1)+strlen($2)+1); 
                                    strcat(_t,$1);strcat(_t,$2);strcat(_t,"*I");
                                    $$ = (char*)_t;}
;
%%

void printhm(Hashmap *hm) {
  hashpair *start = hm->start;
  hashpair *t = start;
  while (t < start + hm->size) {
    if (t->key == NULL) {
      printf("---\n");
    } else {
      printf("key :%s,value: %s\n", (char *)t->key, ((Variable *)t->value)->name);
    }
    ++t;
  }
  printf("\n");
}

void main(int argc , char **argv){

    __init_io__("./test.ttp",NULL);
    __init_literals__();
    __init_vars__();
    __init_actions__();
    __init_functions__();
    yyparse();
    //printhm(&varmap);
    __cleanup_functions__();
    __cleanup_actions__();
    __cleanup_vars__();
    __cleanup_literals__();
    __cleanup_io__();
}
