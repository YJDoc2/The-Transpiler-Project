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

    void preparse();
    extern char *type_arr[],*mod_arr[];
    bool is_in_fn = false;
    bool has_returned = false;
    type fn_type = VOID_TYPE;
    type arg_type;
    type expr_type = VOID_TYPE;

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

%type <s> value cmplxnum expr fncall

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

fndecldummy : /* nothing */ {print_fn_delc($<s>-6);
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;
                            pushscope();} 

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,$3);create_var($1,$2,$3,yylineno); free($3);}

stmtlist :/* nothing */
    | stmtlist error ';' {expr_type = VOID_TYPE;}
    | stmtlist stmt ';' {expr_type= VOID_TYPE;}
    | stmtlist stmt {yyerror("missing ;");expr_type =  VOID_TYPE;}
;

stmt : RAW "<{" rawlist "}>" {printcode("%s\n",$4);}
    | vardeclaration
    | fncall {printcode($1);if(strcmp($1,"")!=0)printcode(";\n");free($1);}
    | returnstmt
;

vardeclaration : DECL modifier type decllist
    | modifier type { printcode("%s %s ",mod_arr[$1],type_arr[$2]);} varlist {printcode(" ;\n");}
;

decllist: IDENTIFIER {create_var($<m>-1,$<t>0,$1,yylineno); free($1); }
    | decllist ',' IDENTIFIER {create_var($<m>-1,$<t>0,$3,yylineno); free($3); }
;

varlist : IDENTIFIER {add_var($<m>-2,$<t>-1,$1,yylineno); 
                        printcode("%s ",$1);
                        free($1); }
    | IDENTIFIER '=' expr {
                                if(verify_types($<t>-1,expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[$<t>-1]);
                                add_var($<m>-2,$<t>-1,$1,yylineno);
                                printcode("%s = %s",$1,$3);
                                free($1);free($3);}
    | varlist ',' IDENTIFIER {add_var($<m>-2,$<t>-1,$3,yylineno); 
                                printcode(",%s ",$3);
                                free($3);}
    | varlist ',' IDENTIFIER '=' expr {
                                        if(verify_types($<t>-1,expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[$<t>-1]);
                                        add_var($<m>-2,$<t>-1,$3,yylineno);
                                        printcode(",%s = %s",$3,$5);
                                        free($3);free($5);}
;

fncall : IDENTIFIER '(' {push_expr_and_args();} arglist ')' {if(!is_in_fn){
                                        yyerror("Function call is not allowed outside a function.");
                                    }else if(find_action($1)){
                                        perform_action($1);
                                        $$ = strdup("");
                                    }else{
                                        Function *fn = find_fn($1);
                                        if(fn == NULL){
                                            $$ = get_fncall_str($1);
                                            ll_clear(arglist);
                                        }else{
                                            verify_call($1,fn,yylineno);
                                            $$ = get_fncall_str($1);
                                            ll_clear(arglist);
                                            pop_expr_and_args();\
                                            // TODOverify error types...
                                            type fn_ret = fn->ret_t;
                                            if(expr_type == STRING_TYPE || fn_ret == STRING_TYPE ){yyerror("Cannot combine string type with any type.");}
                                            if((expr_type == BOOL_TYPE && fn_ret != BOOL_TYPE) ||
                                                (fn_ret ==BOOL_TYPE && expr_type !=BOOL_TYPE)){yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);}
                                            if(expr_type == COMPLEX_TYPE || fn_ret == COMPLEX_TYPE){
                                                expr_type = COMPLEX_TYPE;
                                            }else if(expr_type == FLOAT_TYPE || fn_ret == FLOAT_TYPE || fn_ret == DOUBLE_TYPE){
                                                expr_type = FLOAT_TYPE;
                                            }
                                        }
                                    }
                                    free($1);}
;

arglist : /* nothing */ 
    | arglist arg 
    | arglist ',' arg 
;

arg : expr  {void *v = add_literal(NONE_TYPE,expr_type,$1);ll_add(arglist,v);free($1);expr_type = VOID_TYPE;}
;

returnstmt : RETURN expr { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;\n",$2);
                                has_returned = true;
                            }
                            free($2);}
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

value : cmplxnum {if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
    | INTNUM {if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
    | FLOATNUM { if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
    | IDENTIFIER { Variable *_t = lookup_var($$);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$$);
                    }else if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[_t->t],type_arr[expr_type]);;
                    }else if(_t->t ==COMPLEX_TYPE){
                        expr_type = COMPLEX_TYPE;
                    }else if(_t->t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                        expr_type = FLOAT_TYPE;
                    }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                        expr_type = _t->t;
                    }}
    | BOOLVAL   {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type != BOOL_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
    | STRINGVAL {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
    | fncall    
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
    __init_expr__();
    preparse();
    yyparse();
    __cleanup_expr__();
    __cleanup_scopes__();
    __cleanup_functions__();
    __cleanup_actions__();
    __cleanup_vars__();
    __cleanup_literals__();
    __cleanup_io__();
}
