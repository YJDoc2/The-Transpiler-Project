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

%type <s> value cmplxnum

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
    | rawlist RAWLINE   {printcode("%s",$2); free($2);}

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


declaration : DECL modifier type IDENTIFIER {create_var($2,$3,$4,yylineno); free($4); }
    | modifier type IDENTIFIER    {add_var($1,$2,$3,yylineno); free($3);}
    | assignment

assignment : modifier type IDENTIFIER '=' value {add_var_assg($1,$2,$3,$5,yylineno);free($3);free($5);}

value : cmplxnum
    | INTNUM
    | FLOATNUM
    | IDENTIFIER

cmplxnum : value '+' value '*' I {void *_t = calloc(1,strlen($1)+strlen($3)+1); 
                                    strcat(_t,$1);strcat(_t,"+");strcat(_t,$3);strcat(_t,"*I");
                                    $$ = (char*)_t;}
    | value '-' value '*' I {void *_t = calloc(1,strlen($1)+strlen($3)+1); 
                                    strcat(_t,$1);strcat(_t,"-");strcat(_t,$3);strcat(_t,"*I");
                                    $$ = (char*)_t;}
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

    __init_io__("./test.t",NULL);
     __init_vars__();
    yyparse();
    //printhm(&varmap);
    __cleanup_vars__();
    __close_io__();
}
