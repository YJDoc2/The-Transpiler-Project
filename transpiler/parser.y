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

    extern char *type_arr[],*mod_arr[];
    bool is_in_fn = false;
    bool has_returned = false;
    type fn_type = VOID_TYPE;

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

%type <s> value cmplxnum intnum floatnum endval

%%
program : topstmtlist
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


topstmtlist :  /* nothin */
    | topstmtlist error {yyerror("unknown token %s\n",yytext);}
    | topstmtlist topstmt


topstmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | vardeclaration ';'
    | vardeclaration {yyerror("missing ;");}
    | fndeclaration

rawlist : /* nothing */
    | rawlist RAWLINE   {printcode("%s",$2); free($2);}
;

fndeclaration : FNDECL IDENTIFIER '(' paramlist ')' "->" modifier type fndecldummy'{' stmtlist'}' {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$2,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($2);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    }

fndecldummy : /* nothing */ {add_function($<m>-1,$<t>0,$<s>-6,$<s>-6,yylineno);
                            print_fn_delc($<s>-6);
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;
                            pushscope();} 

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,$3);create_var($1,$2,$3,yylineno); free($3);}

stmtlist :/* nothing */
    | stmtlist error ';'
    | stmtlist stmt ';'
    | stmtlist stmt {yyerror("missing ;");}
;

stmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | vardeclaration
    | fncall
    | returnstmt
;

returnstmt : RETURN value { if(rhst != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[rhst]);
                            }else{
                                printcode("return %s;\n",$2);
                                has_returned = true;
                            }}
            | RETURN    {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;\n");
                            has_returned = true;
                        }}


fncall : IDENTIFIER '(' arglist ')' {if(find_action($1)){
                                        perform_action($1);
                                    }else{
                                        Function *fn = find_fn($1);
                                        if(fn == NULL){
                                            add_call($1,yylineno);
                                            print_call($1);
                                            arglist.end = arglist.start = NULL;
                                            arglist.size = 0;
                                        }else{
                                            verify_call($1,fn,yylineno);
                                            print_call($1);
                                            ll_clear(&arglist);
                                        }
                                    }
                                    free($1);}
;

arglist : /* nothing */
    | arglist arg
    | arglist ',' arg
;

arg : IDENTIFIER  {Variable *v = lookup_var($1);
                    if(v == NULL){
                        yyerror("Undefined variable %s",$1);
                    }else{
                        ll_add(&arglist,v);
                    }
                    free($1);}
        | intnum {void* v = add_literal(NONE_TYPE,INT_TYPE,$1);
                    ll_add(&arglist,v);free($1);}
        | floatnum {void* v = add_literal(NONE_TYPE,DOUBLE_TYPE,$1);
                    ll_add(&arglist,v);free($1);}
        | cmplxnum {void* v = add_literal(NONE_TYPE,COMPLEX_TYPE,$1);
                    ll_add(&arglist,v);free($1);}
        | BOOLVAL {void* v = add_literal(NONE_TYPE,BOOL_TYPE,$1);
                    ll_add(&arglist,v);free($1);}
        | STRINGVAL   {void *v = add_literal(NONE_TYPE,STRING_TYPE,$1);ll_add(&arglist,v);free($1);}

vardeclaration : DECL modifier type decllist
    | modifier type {printcode("%s %s ",mod_arr[$1],type_arr[$2]);} varlist {printcode(" ;\n");}
;

decllist: IDENTIFIER {create_var($<m>-1,$<t>0,$1,yylineno); free($1); }
    | decllist ',' IDENTIFIER {create_var($<m>-1,$<t>0,$3,yylineno); free($3); }
;

varlist : IDENTIFIER {add_var($<m>-2,$<t>-1,$1,yylineno); 
                        printcode("%s ",$1);
                        free($1); }
    | IDENTIFIER '=' value {lhst = $<t>0;verify_types();
                                add_var($<m>-2,$<t>-1,$1,yylineno);
                                printcode("%s = %s",$1,$3);
                                free($1);free($3);}
    | varlist ',' IDENTIFIER {add_var($<m>-2,$<t>-1,$3,yylineno); 
                                printcode(",%s ",$3);
                                free($3);}
    | varlist ',' IDENTIFIER '=' value {lhst = $<t>0;verify_types();
                                        add_var($<m>-2,$<t>-1,$3,yylineno);
                                        printcode(",%s = %s",$3,$5);
                                        free($3);free($5);}

value : cmplxnum {rhst = COMPLEX_TYPE;}
    | endval
    | BOOLVAL   {rhst = BOOL_TYPE;}
    | STRINGVAL {rhst = STRING_TYPE;}
;

cmplxnum : endval '+' endval '*' I {void *_t = calloc(1,strlen($1)+strlen($3)+1); 
                                    strcat(_t,$1);strcat(_t,"+");strcat(_t,$3);strcat(_t,"*I");
                                    $$ = (char*)_t;}
    | endval '-' endval '*' I      {void *_t = calloc(1,strlen($1)+strlen($3)+1); 
                                    strcat(_t,$1);strcat(_t,"-");strcat(_t,$3);strcat(_t,"*I");
                                    $$ = (char*)_t;}
;

endval : intnum {rhst = INT_TYPE;}
    | floatnum {rhst = FLOAT_TYPE;}
    | IDENTIFIER { Variable *_t = lookup_var($$);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$$);
                    }else{
                        rhst = _t->t;
                    }}

intnum : INTNUM
    | '-' INTNUM {char *_s = calloc(1,strlen($2)+2); strcpy(_s,"-"); strcat(_s,$2); $$ = _s; free($2);}
floatnum : FLOATNUM 
    | '-' FLOATNUM {char *_s = calloc(1,strlen($2)+2); strcpy(_s,"-"); strcat(_s,$2); $$ = _s; free($2);}

%%

void main(int argc , char **argv){

    __init_io__("./test.ttp",NULL);
    __init_literals__();
    __init_vars__();
    __init_actions__();
    __init_functions__();
    __init_scopes__();
    yyparse();
    __cleanup_scopes__();
    __cleanup_functions__();
    __cleanup_actions__();
    __cleanup_vars__();
    __cleanup_literals__();
    __cleanup_io__();
}
