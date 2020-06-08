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

    void preparse(); // as preparse is a macro from preparser.l must be given here
    extern char *type_arr[],*mod_arr[];
    bool is_in_fn = false;
    bool has_returned = false;
    type fn_type = VOID_TYPE;
    type arg_type;
    type expr_type = VOID_TYPE;
    type arr_type = VOID_TYPE;
    modifier char_buf_mod = NONE_TYPE;
    bool is_val_arr = false;
    bool is_in_fncall = false;

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
%token CHARBUF

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

%token BEGINCOMMENT ENDCOMMENT 
%token <s> COMMENTLINE

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


topstmt : RAW "<{" rawlist "}>" {printcode("%s",$4);}
    | vardeclaration ';' {expr_type =VOID_TYPE;}
    | vardeclaration {yyerror("missing ;");expr_type =VOID_TYPE;}
    | fndeclaration {expr_type =VOID_TYPE;}
    | comment

rawlist : /* nothing */
    | rawlist RAWLINE   {printcode("%s",$2); free($2);}
;

fndeclaration : FNDECL IDENTIFIER '(' paramlist ')' "->" modifier type fndecldummy'{' stmtlist'}' {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$2,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($2);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }

fndecldummy : /* nothing */ {print_fn_delc($<s>-6);
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;
                            pushscope();} 

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,false,$3);create_var($1,$2,$3,yylineno); free($3);}
    | modifier type IDENTIFIER '[' ']' {add_param($1,$2,true,$3);add_array($1,$2,$3,yylineno); free($3);}

stmtlist :/* nothing */
    | stmtlist error ';' {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
    | stmtlist stmt ';' {expr_type= VOID_TYPE;}
    | stmtlist stmt {yyerror("missing ;");expr_type =  VOID_TYPE;}
    | stmtlist comment
;

stmt : RAW "<{" rawlist "}>" {printcode("%s",$4);}
    | vardeclaration
    | fncall {printcode($1);if(strcmp($1,"")!=0)printcode(";");free($1);}
    | returnstmt
    | assignstmt
;

comment : BEGINCOMMENT {printcode("/*");} commentlist ENDCOMMENT {printcode("*/");}
    | COMMENTLINE   {printcode("%s",$1);free($1);}

commentlist : /*nothing*/
    | commentlist COMMENTLINE {printcode("%s",$2);free($2);}

returnstmt : RETURN expr { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",$2);
                                has_returned = true;
                            }
                            free($2);}
            | RETURN    {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }}
            | DECL RETURN {has_returned = true;}
;

vardeclaration : DECL modifier type decllist
    | modifier type { printcode("%s %s ",mod_arr[$1],type_arr[$2]); arr_type = $2;} varlist {printcode(" ;");arr_type=VOID_TYPE;}
    | modifier CHARBUF {printcode("%s char ",mod_arr[$1]); char_buf_mod = $1;} chararrdecllist {printcode(" ;");char_buf_mod = NONE_TYPE;}
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
    |IDENTIFIER {add_array($<m>-2,  $<t>-1, $1, yylineno);} arraydecl {free($1);}
    | varlist ',' IDENTIFIER {add_var($<m>-2,$<t>-1,$3,yylineno); 
                                printcode(",%s ",$3);
                                free($3);}
    | varlist ',' IDENTIFIER '=' expr {
                                        if(verify_types($<t>-1,expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[$<t>-1]);
                                        add_var($<m>-2,$<t>-1,$3,yylineno);
                                        printcode(",%s = %s",$3,$5);
                                        free($3);free($5);}
    | varlist ',' IDENTIFIER {add_array($<m>-2,  $<t>-1, $3, yylineno);} arraydecl {free($3);}
;

arraydecl: '[' expr ']'      {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",$<s>-1,$2);
                                            }
                                            free($2);
                                            }
    |  '[' ']'        {yyerror("Array size missing");}
    |  '[' ']' '=' '{' {printcode("%s[] = { ",$<s>-1);} arrayvallist '}' {printcode(" }");}
    | '[' expr ']' '=' '{' arraydecldummy {printcode("%s[%s] = { ",$<s>-1,$2);free($2);} arrayvallist '}' {printcode(" }");}

;

arraydecldummy : /*nothing*/ {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}

chararrdecllist: IDENTIFIER {printcode("%s",$1);}strdecl {free($1);expr_type = VOID_TYPE;}
    | chararrdecllist ',' IDENTIFIER {printcode(" ,%s",$3);} strdecl {free($3);expr_type = VOID_TYPE;}


strdecl :'[' expr ']'  arraydecldummy {printcode("[%s]",$2);add_var(char_buf_mod,STRING_TYPE,$<s>-1,yylineno);free($2);}
    | '[' expr ']' arraydecldummy '=' expr {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",$2,$6);add_var(char_buf_mod,STRING_TYPE,$<s>-1,yylineno);}free($2);free($6);}
    | '[' ']' '=' expr {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",$4);add_var(char_buf_mod,STRING_TYPE,$<s>-1,yylineno);}free($4);}
    | '['expr ']'arraydecldummy '[' expr ']' arraydecldummy '=' '{' {printcode("[%s][%s] = {",$2,$6);arr_type = STRING_TYPE;} arrayvallist '}' {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, $<s>-1, yylineno);
                                                                                                                free($2);free($6);}
    | '[' ']' '[' expr ']' arraydecldummy '=' '{' {printcode("[][%s] = { ",$4);arr_type = STRING_TYPE;} arrayvallist '}' {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, $<s>-1, yylineno);
                                                                                                free($4);}
    | '['expr ']'arraydecldummy '[' expr ']' arraydecldummy {printcode("[%s][%s]",$2,$6);add_array(char_buf_mod,  STRING_TYPE, $<s>-1, yylineno);}

    | '[' ']' '[' ']' {yyerror("Both sizes cannot be empty in a charbuf array");}
;


arrayvallist : expr { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",$1);
                        free($1);
                        }
    | arrayvallist ',' expr { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",$3);
                        free($3);}

fncall : IDENTIFIER '(' {push_expr_and_args();if(find_action($1)==0)is_in_fncall=true;} arglist ')' {if(!is_in_fn){
                                        yyerror("Function call is not allowed outside a function.");
                                        $$ = strdup("");
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
                                            if(expr_type == VOID_TYPE){
                                                expr_type = fn_ret;
                                            }else if(expr_type == STRING_TYPE || expr_type != VOID_TYPE && fn_ret == STRING_TYPE ){
                                                yyerror("Cannot combine string type with any type.");
                                            }else if((expr_type == BOOL_TYPE && fn_ret != BOOL_TYPE) ||
                                                (fn_ret ==BOOL_TYPE && expr_type !=BOOL_TYPE)){
                                                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                                            }else if(expr_type == COMPLEX_TYPE || fn_ret == COMPLEX_TYPE){
                                                expr_type = COMPLEX_TYPE;
                                            }else if(expr_type == FLOAT_TYPE || fn_ret == FLOAT_TYPE || fn_ret == DOUBLE_TYPE){
                                                expr_type = FLOAT_TYPE;
                                            }
                                        }
                                    }
                                    is_in_fncall = false;
                                    free($1);}
;

arglist : /* nothing */ 
    | arglist arg 
    | arglist ',' arg 
;

arg : expr  { void *v = lookup_var($1);
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,$1);
                }
                if(is_val_arr){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free($1);expr_type = VOID_TYPE;is_val_arr = false;}
;

assignstmt : IDENTIFIER '=' expr {Variable *var = lookup_var($1);
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",$1);
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else{
                                        printcode("%s = %s;",$1,$3);
                                    }
                                    free($1);free($3);
                                    }
            | IDENTIFIER '[' expr arraydecldummy']' '=' expr {Variable *var = lookup_var($1);
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",$1);
                                    }else if(!var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else{
                                        printcode("%s[%s] = %s;",$1,$3,$7);
                                    }
                                    free($1);free($3);free($7);}


expr: expr '+' expr  {$$=join($1,"+",$3); free($1);free($3); is_val_arr =false;}
    | expr '-' expr  {$$=join($1,"-",$3); free($1);free($3); is_val_arr =false;}
    | expr '*' expr  {$$=join($1,"*",$3); free($1);free($3); is_val_arr =false;}
    | expr '/' expr  {$$=join($1,"/",$3); free($1);free($3); is_val_arr =false;}
    | expr MOD expr  {$$=join($1,"%",$3); free($1);free($3); is_val_arr =false;}
    | '(' type ')' expr  %prec UMINUS    {void * v = calloc(1,3+strlen(type_arr[$2])); // 2 for '()' one for end-of-string 0
                                sprintf(v,"(%s) ",type_arr[$2]);
                                char * t = join("(",$4,")");
                                $$ = join(v,"",t);
                                 is_val_arr =false;
                                free(v);
                                free(t);
                                free($4);
                                expr_type = $2;
                            }
    | '(' expr ')'   {$$=join("( ",$2," )"); free($2); is_val_arr =false;}
    | '-' expr %prec UMINUS {$$=join("-","",$2); free($2); is_val_arr =false;}
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
    | IDENTIFIER { Variable *_t = lookup_var($1);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$1);
                    }else if(_t->is_arr && !is_in_fncall){
                        yyerror("cannot use arrray without subscript.");
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
    | STRINGVAL {if(expr_type != VOID_TYPE){asm("int3");yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
    | fncall    
    | IDENTIFIER '[' {push_expr_and_args();} expr ']' { Variable *v = lookup_var($1);
                                                        if(v == NULL){
                                                            yyerror("Undefined variable %s",$$);
                                                        }else if(!v->is_arr && v->t != STRING_TYPE){
                                                            yyerror("Subscripted object must be of array or string type. got %s type",type_arr[v->t]);
                                                        }else if(expr_type != INT_TYPE){
                                                            yyerror("Subscript must be of int type got %s type",type_arr[expr_type]);
                                                        }
                                                        char *t = join($1,"[",$4);
                                                        
                                                        $$ = join(t,"]","");
                                                        is_val_arr = true;
                                                        pop_expr_and_args();
                                                        free(t);
                                                        if(v != NULL){
                                                            if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                                                                yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[v->t],type_arr[expr_type]);;
                                                            }else if(v->t ==COMPLEX_TYPE){
                                                                expr_type = COMPLEX_TYPE;
                                                            }else if(v->t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                                                                expr_type = FLOAT_TYPE;
                                                            }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                                                                expr_type = v->t;
                                                            }
                                                        }
                                                        free($1);free($4);
                                                        }
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
