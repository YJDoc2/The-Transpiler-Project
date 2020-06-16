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
    #include "forloop.h"
    #include "classes.h"

    void preparse(); // as preparse is a macro from preparser.l must be given here
    
    bool print_lineno = false;

    extern char *type_arr[],*mod_arr[];
    extern Linked_list *temp_list;
    
    bool is_in_fn = false;
    bool has_returned = false;
    
    type fn_type = VOID_TYPE;
    type arg_type;
    type expr_type = VOID_TYPE;
    type arr_type = VOID_TYPE;
    modifier char_buf_mod = NONE_TYPE;
    
    bool is_composite_val = false;
    bool is_in_fncall = false;
    int is_in_loop  =   0;
    
    Class * current_class = NULL;
    bool is_static_method;

%}

%union{
    char *s;
    type t;
    modifier m;
}


%nonassoc LEAST
%left EQL
%left AND OR
%left LTE GTE '<' '>'
%left '+' '-'

%left '*' '/' MOD
%nonassoc UMINUS NOT

%token <t> BOOL COMPLEX
%token <m> CONST STATIC
%token <t> DOUBLE FLOAT LONG SHORT VOID INT
%token <t> STRING
%token CHARBUF

%token BREAK CONTINUE FOR IF ELSE
%token RETURN WHILE

%token IN RAW
%token DECL LET
%token <s> IDENTIFIER BOOLVAL STRINGVAL
%token FNDECL 
%token RETTYPE "->"
%token <s> INTNUM FLOATNUM

%token RAWSTART "<{"
%token <s> RAWEND "}>"
%token <s> RAWLINE

%token BEGINCOMMENT ENDCOMMENT 
%token <s> COMMENTLINE

%token CLASS STATICMETHOD THIS

%type <t> type
%type <m> modifier
%type <s> assgtype
%type <s> value cmplxnum expr fncall
%type <s> letarrvals

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
    | classdef

rawlist : /* nothing */
    | rawlist RAWLINE   {printcode("%s",$2); free($2);}
;


classdef : CLASS IDENTIFIER '{' {current_class = add_class($2,yylineno);start_class_definition($2);} attrlist {end_attr_list($2);} methodlist '}'   {end_class_definition();printcode("#include \"class_%s.h\"",$2);free($2);current_class = NULL;}

attrlist: /*nothing*/
    | attrlist error ';'
    | attrlist type IDENTIFIER ';' {add_attr(current_class,NONE_TYPE,$2,$3,false,yylineno);printcode("%s %s;\n",type_arr[$2],$3);free($3);}
    | attrlist CONST type IDENTIFIER ';' {add_attr(current_class,CONST_TYPE,$3,$4,false,yylineno);printcode("const %s %s;\n",type_arr[$3],$4);free($4);}
    | attrlist type IDENTIFIER '[' expr arraysizedummy ']' ';' {add_attr(current_class,NONE_TYPE,$2,$3,true,yylineno);printcode("%s %s[%s];\n",type_arr[$2],$3,$5);free($3);free($5);}
    | attrlist CONST type IDENTIFIER '[' expr arraysizedummy ']' ';' {add_attr(current_class,CONST_TYPE,$3,$4,true,yylineno);printcode("const %s %s[%s];\n",type_arr[$3],$4,$6);free($4);free($6);}
    | attrlist RAW "<{" rawlist "}>" {printcode("%s",$5);}
    | attrlist DECL type IDENTIFIER ';'  {add_attr(current_class,NONE_TYPE,$3,$4,false,yylineno);free($4);}
    | attrlist DECL CONST type IDENTIFIER ';' {add_attr(current_class,CONST_TYPE,$4,$5,false,yylineno);free($5);}
    | attrlist DECL type IDENTIFIER '[' ']' ';' {add_attr(current_class,NONE_TYPE,$3,$4,true,yylineno);free($4);}
    | attrlist DECL CONST type IDENTIFIER '[' ']' ';'  {add_attr(current_class,CONST_TYPE,$4,$5,true,yylineno);free($5);}

methodlist : /*nothing*/
    | methodlist FNDECL IDENTIFIER '(' {pushscope();} methodparamlist ')' "->" type methoddummy '{' stmtlist'}' {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$3,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($3);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;
                                                                                                    }
    | methodlist staticdummy FNDECL IDENTIFIER '(' {pushscope();} methodparamlist ')' "->" type methoddummy'{' stmtlist'}' {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$4,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($4);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;
                                                                                                    }

;

methodparamlist : /*nothing*/
    | methodparamlist methodparam
    | methodparamlist ',' methodparam 

methodparam : modifier type IDENTIFIER  {add_param($1,$2,false,$3); create_var($1,$2,$3,yylineno);free($3);}
    | modifier type IDENTIFIER '[' ']'  {add_param($1,$2,true,$3); add_array($1,$2,$3,yylineno);free($3);}

staticdummy : STATICMETHOD {is_static_method = true;}

;

methoddummy : /*nothing*/ {add_method(current_class, $<s>-6, $<t>0, is_static_method,temp_list, yylineno);
                            print_method(current_class,$<s>-6);
                            temp_list = NULL;
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;}
;

fndeclaration : FNDECL IDENTIFIER '(' {pushscope();} paramlist ')' "->" modifier type fndecldummy'{' stmtlist'}' {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$2,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($2);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }

fndecldummy : /* nothing */ {print_fn_delc($<s>-7);
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;} 

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,false,$3);create_var($1,$2,$3,yylineno); free($3);}
    | modifier type IDENTIFIER '[' ']' {add_param($1,$2,true,$3);add_array($1,$2,$3,yylineno); free($3);}

stmtlist :/* nothing */
    | stmtlist RAW "<{" rawlist "}>" {printcode("%s",$5);}
    | stmtlist error ';' {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
    | stmtlist error '}' {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
    | stmtlist error '{' {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
    | stmtlist stmt ';' {expr_type= VOID_TYPE;}
    | stmtlist stmt {yyerror("missing ;");expr_type =  VOID_TYPE;}
    | stmtlist comment
    | stmtlist ifstmt
    | stmtlist whilestmt
    | stmtlist forstmt
;

stmt : vardeclaration
    | fncall {printcode("%s",$1);if(strcmp($1,"")!=0)printcode(";");free($1);}
    | returnstmt
    | assignstmt
    | BREAK {printcode("break;");}
    | CONTINUE  {printcode("continue;");}
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
            | RETURN  {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
            | DECL RETURN {has_returned = true;}
;

vardeclaration : DECL modifier type decllist
    | modifier type { printcode("%s %s ",mod_arr[$1],type_arr[$2]); arr_type = $2;} varlist {printcode(" ;");arr_type=VOID_TYPE;}
    | modifier CHARBUF {printcode("%s char ",mod_arr[$1]); char_buf_mod = $1;} chararrdecllist {printcode(" ;");char_buf_mod = NONE_TYPE;}
    | LET IDENTIFIER '=' expr {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",$2);
            }else{
                add_var(NONE_TYPE,expr_type,$2,yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],$2,$4);
            }
            free($2);free($4);}
    | LET letarraydecl

;

decllist: IDENTIFIER {create_var($<m>-1,$<t>0,$1,yylineno); free($1); }
    | decllist ',' IDENTIFIER {create_var($<m>-1,$<t>0,$3,yylineno); free($3); }
;

varlist : IDENTIFIER {add_var($<m>-2,$<t>-1,$1,yylineno); 
                        printcode("%s ",$1);
                        free($1); }
    | IDENTIFIER '=' expr {  //asm("int3");
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
    | '[' expr ']' '=' '{' arraysizedummy {printcode("%s[%s] = { ",$<s>-1,$2);free($2);} arrayvallist '}' {printcode(" }");}

;

arraysizedummy : /*nothing*/ {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}

letarraydecl :IDENTIFIER '[' ']' '=' '{' letarrvals '}' {if(arr_type == VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",$1);
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, $1, yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],$1,$6);
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free($1);free($6);}
    | IDENTIFIER '[' expr arraysizedummy ']' '=' '{' letarrvals '}' {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",$1);
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, $1, yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],$1,$3,$8);
                                                            }expr_type = VOID_TYPE;
                                                            free($1);free($3);free($8);}

letarrvals : expr           {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}}
    | letarrvals ',' expr   {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE)expr_type = VOID_TYPE;
                            $$=join($1,",",$3);free($1);free($3);}

chararrdecllist: IDENTIFIER {printcode("%s",$1);}strdecl {free($1);expr_type = VOID_TYPE;}
    | chararrdecllist ',' IDENTIFIER {printcode(" ,%s",$3);} strdecl {free($3);expr_type = VOID_TYPE;}


strdecl :'[' expr ']'  arraysizedummy {printcode("[%s]",$2);add_var(char_buf_mod,STRING_TYPE,$<s>-1,yylineno);free($2);}
    | '[' expr ']' arraysizedummy '=' expr {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",$2,$6);add_var(char_buf_mod,STRING_TYPE,$<s>-1,yylineno);}free($2);free($6);}
    | '[' ']' '=' expr {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",$4);add_var(char_buf_mod,STRING_TYPE,$<s>-1,yylineno);}free($4);}
    | '['expr ']'arraysizedummy '[' expr ']' arraysizedummy '=' '{' {printcode("[%s][%s] = {",$2,$6);arr_type = STRING_TYPE;} arrayvallist '}' {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, $<s>-1, yylineno);
                                                                                                                free($2);free($6);}
    | '[' ']' '[' expr ']' arraysizedummy '=' '{' {printcode("[][%s] = { ",$4);arr_type = STRING_TYPE;} arrayvallist '}' {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, $<s>-1, yylineno);
                                                                                                free($4);}
    | '['expr ']'arraysizedummy '[' expr ']' arraysizedummy {printcode("[%s][%s]",$2,$6);add_array(char_buf_mod,  STRING_TYPE, $<s>-1, yylineno);}

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
                                            pop_expr_and_args();
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
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free($1);expr_type = VOID_TYPE;is_composite_val = false;}
;

assignstmt : IDENTIFIER assgtype expr {Variable *var = lookup_var($1);
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",$1);
                                    }else if(var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else if(var->t == COMPLEX_TYPE && strcmp($2,"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }else{
                                        printcode("%s %s %s;",$1,$2,$3);
                                    }
                                    // No need to free $2, its const char *
                                    free($1);free($3);
                                    expr_type = VOID_TYPE;
                                    }
            | IDENTIFIER '[' expr arraysizedummy']' assgtype expr {Variable *var = lookup_var($1);
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",$1);
                                    }else if(!var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else if((var->t == COMPLEX_TYPE || var->t == FLOAT || var->t == DOUBLE_TYPE) && strcmp($6,"%=")==0){
                                        yyerror("Cannot use mod on %s type",type_arr[var->t]);
                                    }else{
                                        printcode("%s[%s] %s %s;",$1,$3,$6,$7);
                                    }
                                    expr_type = VOID_TYPE;
                                    // No need to free $2, its const char *
                                    free($1);free($3);free($7);}

;
assgtype : '='  {$$ = "=";}
    | '+' '=' {$$ = "+=";}
    | '-' '=' {$$ = "-=";}
    | '*' '=' {$$ = "*=";}
    | '/' '=' {$$ = "/=";}
    | MOD '=' {$$ = "%=";}
;

ifstmt: IF expr '{' ifdummy stmtlist '}' {popscope();printcode("}\n");}
    | IF expr '{' ifdummy stmtlist '}' ELSE '{' elsedummy stmtlist '}' {printcode("}\n");popscope();}
    | IF expr '{' ifdummy stmtlist '}' ELSE {popscope();printcode("}else ");} ifstmt
;

ifdummy :/* nothing */  {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",$<s>-1);free($<s>-1);}

;

elsedummy : /* nothing */   {popscope();pushscope();printcode("}else{");}

;

whilestmt : WHILE expr '{' {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",$2);pushscope();free($2);} stmtlist '}' {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
;

forstmt : FOR IDENTIFIER IN expr '.' '.' expr rangecheckdummy {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,$2,yylineno);print_simple_range_loop($2,$4,$7,expr_type);free($2);free($4);free($7);}'{' stmtlist '}' {printcode("}");popscope();--is_in_loop;}
    | FOR IDENTIFIER IN expr '.' '.' expr '.' '.' expr rangecheckdummy {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,$2,yylineno);print_step_range_loop($2,$4,$7,$10,expr_type);free($2);free($4);free($7);free($10);} '{' stmtlist '}' {printcode("}");popscope();--is_in_loop;}
    | FOR IDENTIFIER IN IDENTIFIER simplearraydummy {++is_in_loop;free($2);free($4);} '{' stmtlist '}' {printcode("}");popscope();--is_in_loop;}
    | FOR IDENTIFIER ',' IDENTIFIER IN IDENTIFIER iterarraydummy {++is_in_loop;free($2);free($4);free($6);} '{' stmtlist '}' {printcode("}");popscope();--is_in_loop;}
;

rangecheckdummy : /*nothing*/ {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}

;

simplearraydummy : /*nothing*/ {Variable *v = lookup_var($<s>0);
                                    pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",$<s>0);
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,v->t,$<s>-2,yylineno);
                                        print_array_loop($<s>-2,$<s>0,v->t);
                                    }
                                }

;

iterarraydummy : /*nothing*/ {Variable *v = lookup_var($<s>0);
                                        pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",$<s>0);
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,INT_TYPE,$<s>-4,yylineno);
                                        add_var(NONE_TYPE,v->t,$<s>-2,yylineno);
                                        print_enumeration_loop($<s>-4,$<s>-2,$<s>0,v->t);
                                    }}

;
expr: expr '+' expr  {$$=join($1,"+",$3); free($1);free($3); is_composite_val =false;}
    | expr '-' expr  {$$=join($1,"-",$3); free($1);free($3); is_composite_val =false;}
    | expr '*' expr  {$$=join($1,"*",$3); free($1);free($3); is_composite_val =false;}
    | expr '/' expr  {$$=join($1,"/",$3); free($1);free($3); is_composite_val =false;}
    | expr MOD expr  {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        $$=join($1,"%",$3); free($1);free($3); is_composite_val =false;}
    | '(' type ')' expr  %prec UMINUS    {void * v = calloc(1,3+strlen(type_arr[$2])); // 2 for '()' one for end-of-string 0
                                sprintf(v,"(%s) ",type_arr[$2]);
                                char * t = join("(",$4,")");
                                $$ = join(v,"",t);
                                 is_composite_val =false;
                                free(v);
                                free(t);
                                free($4);
                                expr_type = $2;
                            }
    | '(' expr ')'   {$$=join("( ",$2," )"); free($2); is_composite_val =false;}
    | '-' expr %prec UMINUS {$$=join("-","",$2); free($2); is_composite_val =false;}
    | expr '<' expr   {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with complex type");}$$= join($1,"<",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr '>' expr   {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use > with complex type");}$$= join($1,">",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr LTE expr          {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use <= with complex type");}$$= join($1,"<=",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr  GTE expr          {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with complex type");}$$= join($1,">=",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr  EQL expr %prec LEAST        {$$= join($1,"==",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr  NOT EQL expr  %prec LEAST     {$$= join($1,"!=",$4);free($1);free($4);expr_type = BOOL_TYPE;}
    | expr AND expr {$$= join($1," && ",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr OR expr    {$$= join($1," || ",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | NOT expr   {char * t =join("(",$2,")");
                            $$ = join("!",t,"");free(t);free($2);expr_type = BOOL_TYPE;}
    | value

value : cmplxnum {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
    | INTNUM {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
    | FLOATNUM { if( expr_type == STRING_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
    | IDENTIFIER { Variable *_t = lookup_var($1);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$1);
                    }else if(_t->is_arr && !is_in_fncall){
                        yyerror("cannot use arrray without subscript.");
                    }else if(expr_type == STRING_TYPE){
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
                }else if(expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
    | STRINGVAL {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
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
                                                        is_composite_val = true;
                                                        pop_expr_and_args();
                                                        free(t);
                                                        if(v != NULL){
                                                            if( expr_type == STRING_TYPE){
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
                                            $$ = (char*)_t;free($2);free($4);}
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
    __init_classes__();

    preparse();
    printcode("\n#line 1 \"%s\"\n\n","./test.ttp");
    yyparse();
    print_code_header();

    __cleanup_classes__();
    __cleanup_expr__();
    __cleanup_scopes__();
    __cleanup_functions__();
    __cleanup_actions__();
    __cleanup_vars__();
    __cleanup_literals__();
    __cleanup_io__();
}
