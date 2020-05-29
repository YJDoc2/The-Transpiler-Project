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

    extern char *type_arr[],*mod_arr[];
    bool is_in_fn = false;
    bool has_returned = false;
    type rhst = VOID_TYPE, lhst = VOID_TYPE;
    type fn_type = VOID_TYPE;

%}

%union{
    char *s;
    type t;
    modifier m;
}


%left '+' '-'
    /* I'm not sure of MOD yet...*/
%left '*' '/' MOD
%nonassoc UMINUS

%token <t> BOOL COMPLEX
%token <m> CONST STATIC
%token <t> DOUBLE FLOAT LONG SHORT VOID INT
%token <t> STRING

%token BREAK CONTINUE ELSE FOR IF
%token RETURN WHILE

%token I MOD
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

%type <s> value cmplxnum expr

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
    | stmtlist error ';' {rhst = VOID_TYPE;}
    | stmtlist stmt ';' {rhst = VOID_TYPE;}
    | stmtlist stmt {yyerror("missing ;");rhst = VOID_TYPE;}
;

stmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | vardeclaration
    | fncall
    | returnstmt
;

vardeclaration : DECL modifier type decllist
    | modifier type {printcode("%s %s ",mod_arr[$1],type_arr[$2]);} varlist {printcode(" ;\n");}
;

decllist: IDENTIFIER {create_var($<m>-1,$<t>0,$1,yylineno); free($1); }
    | decllist ',' IDENTIFIER {create_var($<m>-1,$<t>0,$3,yylineno); free($3); }
;

varlist : IDENTIFIER {add_var($<m>-2,$<t>-1,$1,yylineno); 
                        printcode("%s ",$1);
                        free($1); }
    | IDENTIFIER '=' expr {lhst = $<t>-1;
                                if(verify_types(lhst,rhst))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[rhst], type_arr[lhst]);
                                add_var($<m>-2,$<t>-1,$1,yylineno);
                                printcode("%s = %s",$1,$3);
                                free($1);free($3);}
    | varlist ',' IDENTIFIER {add_var($<m>-2,$<t>-1,$3,yylineno); 
                                printcode(",%s ",$3);
                                free($3);}
    | varlist ',' IDENTIFIER '=' expr {lhst = $<t>-1;
                                        if(verify_types(lhst,rhst))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[rhst], type_arr[lhst]);
                                        add_var($<m>-2,$<t>-1,$3,yylineno);
                                        printcode(",%s = %s",$3,$5);
                                        free($3);free($5);}
;

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
    | arglist arg {rhst = VOID_TYPE;}
    | arglist ',' arg {rhst = VOID_TYPE;}
;

arg : expr  {void *v = add_literal(NONE_TYPE,rhst,$1);ll_add(&arglist,v);free($1);}
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
;

expr: expr '+' expr  {$$=join($1,"+",$3); free($1);free($3);}
    | expr '-' expr  {$$=join($1,"-",$3); free($1);free($3);}
    | expr '*' expr  {$$=join($1,"*",$3); free($1);free($3);}
    | expr '/' expr  {$$=join($1,"/",$3); free($1);free($3);}
    | expr MOD expr  {$$=join($1,"%",$3); free($1);free($3);}
    | '(' expr ')'   {$$=join("( ",$2," )"); free($2);}
    | '-' expr %prec UMINUS {$$=join("-","",$2); free($2);}
    | value 

value : cmplxnum {if(rhst == BOOL_TYPE || rhst == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[rhst]);;
                }else{
                    rhst = COMPLEX_TYPE;
                }}
    | INTNUM {if(rhst == BOOL_TYPE || rhst == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[rhst]);;
                }else if(!(rhst == FLOAT_TYPE || rhst == DOUBLE_TYPE || rhst == COMPLEX_TYPE)){
                    rhst = INT_TYPE;
                }}
    | FLOATNUM { if(rhst == BOOL_TYPE || rhst == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[rhst]);;
                }else if(rhst != COMPLEX_TYPE){
                    rhst = FLOAT_TYPE;
                }}
    | IDENTIFIER { Variable *_t = lookup_var($$);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$$);
                    }else if(rhst == BOOL_TYPE || rhst == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[_t->t],type_arr[rhst]);;
                    }else if(_t->t ==COMPLEX_TYPE){
                        rhst = COMPLEX_TYPE;
                    }else if(_t->t == FLOAT_TYPE && rhst != COMPLEX_TYPE){
                        rhst = FLOAT_TYPE;
                    }else if(rhst != COMPLEX_TYPE && rhst != FLOAT_TYPE){
                        rhst = _t->t;
                    }}
    | BOOLVAL   {if(rhst == VOID_TYPE){
                    rhst = BOOL_TYPE;
                }else if(rhst != BOOL_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[rhst],type_arr[BOOL_TYPE]);;
                    rhst = BOOL_TYPE;
                    
                }}
    | STRINGVAL {if(rhst != VOID_TYPE){yyerror("Cannot combine string type with any type.");}rhst = STRING_TYPE;}
;

cmplxnum : '(' expr ',' expr ')' {void* _t = calloc(1, strlen($2) + strlen($4) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, $2);strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, $4);strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            $$ = (char*)_t;}
;
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
