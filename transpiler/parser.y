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
    #include "class_decl.h"
    #include "class_access.h"

    void preparse(); // as preparse is a macro from preparser.l must be given here
    
    bool print_lineno = false;

    extern char *type_arr[],*mod_arr[];
    extern Linked_list *temp_list;
    extern Hashmap pre_class_map;
    void pre_class_clean(void*,void*);

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
    char *expr_class;
    char * fn_ret_class;
    type temp_type;
    char * temp_class;
    bool is_assignable = false;
    bool is_static_method;

%}

%union{
    char *s;
    type t;
    modifier m;
    bool b;
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
%token <s> CLASSNAME

%type <t> type
%type <m> modifier
%type <s> assgtype
%type <s> value cmplxnum expr fncall
%type <s> letarrvals
%type <b> arraysign
%type <s> varvals

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
    | classdef {expr_type =VOID_TYPE;}

rawlist : /* nothing */
    | rawlist RAWLINE   {printcode("%s",$2); free($2);}
;


classdef : CLASS IDENTIFIER '{' {current_class = add_class($2,yylineno);start_class_definition($2);} attrlist {end_attr_list($2);} methodlist '}'   {end_class_definition();printcode("#include \"class_%s.h\"",$2);free($2);current_class = NULL;}

attrlist: /*nothing*/
    | attrlist error ';'
    | attrlist modifier type IDENTIFIER ';' {if($2 == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");$2 = NONE_TYPE;
                                                }add_attr(current_class,$2,$3,$4,false,yylineno);
                                                printcode("%s %s %s;",mod_arr[$2],type_arr[$3],$4);free($4);}
    | attrlist modifier type IDENTIFIER '[' expr arraysizedummy ']' ';' {if($2 == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");$2 = NONE_TYPE;
                                                                    }add_attr(current_class,$2,$3,$4,true,yylineno);printcode("%s %s %s[%s];",mod_arr[$2],type_arr[$3],$4,$6);free($4);free($6);}
    | attrlist modifier CLASSNAME IDENTIFIER ';'  {if($2 == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");$2 = NONE_TYPE;
                                                    } 
                                                    if(strcmp($3,current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,$2,$3,$4,false,yylineno);
                                                    printcode("%s %s %s;",mod_arr[$2],$3,$4);
                                                    free($3);free($4);}}
    |attrlist modifier CLASSNAME IDENTIFIER '['expr arraysizedummy ']' ';'  {if($2 == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");$2 = NONE_TYPE;
                                                    }
                                                    if(strcmp($3,current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,$2,$3,$4,true,yylineno);
                                                    printcode("%s %s %s[%s];",mod_arr[$2],$3,$4,$6);
                                                    free($3);free($4);free($6);}}
    | attrlist RAW "<{" rawlist "}>" {printcode("%s",$5);}
    | attrlist DECL modifier type IDENTIFIER arraysign ';'  {if($3 == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");$3 = NONE_TYPE;
                                                }add_attr(current_class,$3,$4,$5,$6,yylineno);free($5);}
    | attrlist DECL modifier CLASSNAME IDENTIFIER arraysign ';'  {if($3 == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");$3 = NONE_TYPE;
                                                            }add_class_type_attr(current_class,$3,$4,$5,$6,yylineno);free($4);free($5);}
    | attrlist comment

arraysign : /*nothing*/ {$$= false;}
    | '[' ']'   {$$ = true;}

methodlist : /*nothing*/
    | methodlist FNDECL IDENTIFIER '(' pushscopedummy paramlist ')' "->" type methoddummy '{' stmtlist'}' {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$3,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($3);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
    | methodlist staticdummy FNDECL IDENTIFIER '(' pushscopedummy paramlist ')' "->" type methoddummy'{' stmtlist'}' {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$4,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($4);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
    | methodlist FNDECL IDENTIFIER '(' pushscopedummy paramlist ')' "->" CLASSNAME clsretmethoddummy '{' stmtlist'}' {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){yyerror("function %s require %s return type, corresponding return statement not found",$3,type_arr[fn_type]);}
                                                                                                    free($3);free($9);
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
    | methodlist staticdummy FNDECL IDENTIFIER '(' pushscopedummy paramlist ')' "->" CLASSNAME clsretmethoddummy'{' stmtlist'}' {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){yyerror("function %s require %s return type, corresponding return statement not found",$4,type_arr[fn_type]);}
                                                                                                    free($4);free($10);
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}

;

staticdummy : STATICMETHOD {is_static_method = true;}

;

methoddummy : /*nothing*/ {add_method(current_class, $<s>-6, $<t>0, is_static_method,temp_list, yylineno);
                            print_method(current_class,$<s>-6);
                            temp_list = NULL;
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;}
;

clsretmethoddummy : /*nothing*/ {add_class_ret_method(current_class, $<s>-6, $<s>0, is_static_method,temp_list, yylineno);
                            print_method(current_class,$<s>-6);
                            temp_list = NULL;
                            fn_type = CLASS_TYPE;
                            fn_ret_class = $<s>0;
                            is_in_fn = true;
                            has_returned = false;}

fndeclaration : FNDECL IDENTIFIER '('pushscopedummy paramlist ')' "->" modifier type fndecldummy'{' stmtlist'}' {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",$2,type_arr[fn_type]);
                                                                                                    }
                                                                                                    free($2);
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
            | FNDECL IDENTIFIER '('pushscopedummy paramlist ')' "->" modifier CLASSNAME classfndecldummy'{' stmtlist'}' {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require class %s return type, corresponding return statement not found",$2,$9);
                                                                                                    }
                                                                                                    free($2);free($9);
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
pushscopedummy : /*nothing*/    {pushscope();}
fndecldummy : /* nothing */ {print_fn_delc($<s>-7);
                            fn_type = $<t>0;
                            is_in_fn = true;
                            has_returned = false;} 

classfndecldummy : /*nothing*/  {print_fn_delc($<s>-7);
                                fn_type = CLASS_TYPE;
                                fn_ret_class =$<s>0;
                                is_in_fn = true;
                                has_returned = false;}

paramlist : /* nothing */
    | paramlist param
    | paramlist ','  param

param : modifier type IDENTIFIER    {add_param($1,$2,false,$3);add_var($1,$2,$3,yylineno); free($3);}
    | modifier type IDENTIFIER '[' ']' {add_param($1,$2,true,$3);add_array($1,$2,$3,yylineno); free($3);}
    | modifier CLASSNAME IDENTIFIER     {add_class_param($1, $2, false,$3);create_class_var($1, $2, $3, false,yylineno);free($2);free($3);}
    | modifier CLASSNAME IDENTIFIER '[' ']' {add_class_param($1, $2, true,$3);create_class_var($1, $2, $3, true,yylineno);free($2);free($3);}

stmtlist :/* nothing */
    | stmtlist RAW "<{" rawlist "}>" {printcode("%s",$5);}
    | stmtlist error ';' {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist error '}' {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist error '{' {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist stmt ';' {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist stmt {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist comment
    | stmtlist ifstmt {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist whilestmt {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
    | stmtlist forstmt {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
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
                            }else if(fn_type == CLASS_TYPE && strcmp(expr_class,fn_ret_class) !=0){
                                yyerror("invalid return type : expected class %s found class %s",fn_ret_class,expr_class);
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

vardeclaration : DECL modifier type {temp_type = $3;} decllist {temp_type = VOID_TYPE;}
    | DECL modifier CLASSNAME {temp_type = CLASS_TYPE;temp_class=$3;} classdecllist {temp_type = VOID_TYPE;temp_class=NULL;free($3);}
    | modifier CLASSNAME {printcode("%s %s ",mod_arr[$1],$2);arr_type=temp_type=CLASS_TYPE;temp_class=$2;} classvarlist {printcode(" ;");free($2);arr_type=temp_type=VOID_TYPE;temp_class= NULL;}
    | modifier type { printcode("%s %s ",mod_arr[$1],type_arr[$2]); arr_type = $2;} varlist {printcode(" ;");arr_type=VOID_TYPE;}
    | modifier CHARBUF {printcode("%s char ",mod_arr[$1]); char_buf_mod = $1;} chararrdecllist {printcode(" ;");char_buf_mod = NONE_TYPE;}
    | LET IDENTIFIER '=' expr {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",$2);
            }else if(expr_type == CLASS_TYPE){
                create_class_var(NONE_TYPE,expr_class,$2,false,yylineno);
                printcode("%s %s = %s;",expr_class,$2,$4);
                expr_class = NULL;expr_type = VOID_TYPE;
            }else{
                add_var(NONE_TYPE,expr_type,$2,yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],$2,$4);
            }
            free($2);free($4);}
    | LET letarraydecl
;

classvarlist : IDENTIFIER       {create_class_var($<m>-2,$<s>-1,$1,false,yylineno);printcode("%s",$1);free($1);}
    | IDENTIFIER '=' expr {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",$1,$3);
                            }free($1);free($3);}
    | IDENTIFIER {/*nothing dummymust be kept to maintain arraydecl*/} arraydecl {create_class_var($<m>-2,$<s>-1,$1,true,yylineno);free($1);}
    | classvarlist ',' IDENTIFIER     {create_class_var($<m>-2,$<s>-1,$3,false,yylineno);printcode(", %s",$3);free($3);}
    | classvarlist ',' IDENTIFIER '=' expr {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",$3,$5);
                            }free($3);free($5);}
    | classvarlist ',' IDENTIFIER {printcode(", ");} arraydecl {create_class_var($<m>-2,$<s>-1,$3,true,yylineno);free($3);}

;



decllist: IDENTIFIER {add_var($<m>-1,temp_type,$1,yylineno); free($1); }
    | IDENTIFIER '[' ']' {add_array($<m>-1,temp_type,$1,yylineno);free($1);}
    | decllist ',' IDENTIFIER {add_var($<m>-1,temp_type,$3,yylineno); free($3); }
    | decllist ',' IDENTIFIER '[' ']' {add_array($<m>-1,temp_type,$3,yylineno);free($3);}
;

classdecllist : IDENTIFIER arraysign {create_class_var($<m>-2,temp_class,$1,$2,yylineno);free($1);}
    |classdecllist ',' IDENTIFIER arraysign {create_class_var($<m>-2,temp_class,$3,$4,yylineno);free($3);}

;
varlist : IDENTIFIER {add_var($<m>-2,$<t>-1,$1,yylineno); 
                        printcode("%s ",$1);
                        free($1); }
    | IDENTIFIER '=' expr { if(verify_types($<t>-1,expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[$<t>-1]);
                                add_var($<m>-2,$<t>-1,$1,yylineno);
                                printcode("%s = %s",$1,$3);
                                free($1);free($3);}
    |IDENTIFIER {/*nothing dummy*/} arraydecl {add_array($<m>-2,  $<t>-1, $1, yylineno);free($1);}
    | varlist ',' IDENTIFIER {add_var($<m>-2,$<t>-1,$3,yylineno); 
                                printcode(",%s ",$3);
                                free($3);}
    | varlist ',' IDENTIFIER '=' expr {
                                        if(verify_types($<t>-1,expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[$<t>-1]);
                                        add_var($<m>-2,$<t>-1,$3,yylineno);
                                        printcode(",%s = %s",$3,$5);
                                        free($3);free($5);}
    | varlist ',' IDENTIFIER {printcode(", ");} arraydecl {add_array($<m>-2,  $<t>-1, $3, yylineno);free($3);}
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
                                                            }else if(arr_type == CLASS_TYPE){
                                                                create_class_var(NONE_TYPE,temp_class,$1,true,yylineno);
                                                                printcode("%s %s[] = { %s };",temp_class,$1,$6);
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, $1, yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],$1,$6);
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free($1);free($6);}
    | IDENTIFIER '[' expr arraysizedummy ']' '=' '{' letarrvals '}' {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",$1);
                                                            }else if(arr_type == CLASS_TYPE){
                                                                create_class_var(NONE_TYPE,temp_class,$1,true,yylineno);
                                                                printcode("%s %s[%s] = { %s };",temp_class,$1,$3,$8);
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, $1, yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],$1,$3,$8);
                                                            }expr_type = VOID_TYPE;
                                                            free($1);free($3);free($8);}

letarrvals : expr           {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
    | letarrvals ',' expr   {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            $$=join($1,",",$3);free($1);free($3);}
;

chararrdecllist: IDENTIFIER {printcode("%s",$1);}strdecl {free($1);expr_type = VOID_TYPE;}
    | chararrdecllist ',' IDENTIFIER {printcode(" ,%s",$3);} strdecl {free($3);expr_type = VOID_TYPE;}
;

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
                                                                                                        type fn_ret = fn->ret_t.t;
                                                                                                        if(expr_type == VOID_TYPE){
                                                                                                            if(fn->is_ret_class){
                                                                                                                expr_type = CLASS_TYPE;
                                                                                                                expr_class = fn->ret_t.class;
                                                                                                            }else{
                                                                                                                expr_type = fn_ret;
                                                                                                            }
                                                                                                        }else if(fn->is_ret_class){
                                                                                                            expr_type = CLASS_TYPE;
                                                                                                            expr_class = fn->ret_t.class;
                                                                                                            //!TODO DO we need these clauses now, yeah....we'll see?
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

assignstmt : varvals assigndummy assgtype expr {
                                    if(temp_type == CLASS_TYPE){
                                        if(expr_type != CLASS_TYPE ){
                                            yyerror("cannot assign %s to class type variable",type_arr[expr_type]);
                                        }else if(strcmp(expr_class,temp_class) != 0){
                                            yyerror("cannot assign class %s value to class %s variable",expr_class,temp_class);
                                        }else if(strcmp($3,"=") != 0){
                                            yyerror("cannot perform compund operations on class type variables");
                                        }else if(!is_assignable_class(temp_class)){
                                            yyerror("cannot perform assignment as class or class members contains constant members");
                                        }
                                    }else if(verify_types(temp_type,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[temp_type],type_arr[expr_type]);
                                    }else if(temp_type == COMPLEX_TYPE&& strcmp($3,"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }
                                    printcode("%s %s %s;",$1,$3,$4);
                                    // No need to free $2, its const char *
                                    free($1);free($4);
                                    expr_type = VOID_TYPE;expr_class = NULL;
                                    temp_class = NULL; temp_type = VOID_TYPE;
                                    }

;

assigndummy : /*nothing*/ {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            } 


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
                                        if(v->is_class){
                                            expr_class = v->t.class;
                                            print_array_loop($<s>-2,$<s>0,CLASS_TYPE);
                                            create_class_var(NONE_TYPE, expr_class, $<s>-2, false,yylineno);
                                            expr_class = NULL;
                                        }else{
                                            add_var(NONE_TYPE,v->t.t,$<s>-2,yylineno);
                                            print_array_loop($<s>-2,$<s>0,v->t.t);
                                        }
                                        
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
                                        if(v->is_class){
                                            expr_class = v->t.class;
                                            create_class_var(NONE_TYPE, expr_class, $<s>-2, false,yylineno);
                                            print_enumeration_loop($<s>-4,$<s>-2,$<s>0,CLASS_TYPE);
                                            expr_class = NULL;
                                        }else{
                                            add_var(NONE_TYPE,v->t.t,$<s>-2,yylineno);
                                            print_enumeration_loop($<s>-4,$<s>-2,$<s>0,v->t.t);
                                        }
                                        
                                    }}

;
expr: expr '+'  expr  { $$=join($1,"+",$3); free($1);free($3); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            is_composite_val =false;}
    | expr '-'  expr  {$$=join($1,"-",$3); free($1);free($3); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
    | expr '*'  expr  {$$=join($1,"*",$3); free($1);free($3); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
    | expr '/'  expr  {$$=join($1,"/",$3); free($1);free($3);
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
    | expr MOD  expr  {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use mod on %s type",type_arr[expr_type]);} 
                                            $$=join($1,"%",$3); free($1);free($3); is_composite_val =false;}
    | '(' type ')' expr  %prec UMINUS    {
                                if(expr_type == CLASS_TYPE){yyerror("cannot typecast class values");}
                                void * v = calloc(1,3+strlen(type_arr[$2])); // 2 for '()' one for end-of-string 0
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
    | '-' expr  %prec UMINUS {$$=join("-","",$2);if(expr_type == CLASS_TYPE){yyerror("Cannot use negetive on class type");}}
    | expr '<'  expr   {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);} 
                                            $$= join($1,"<",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr '>'  expr   {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use > with %s type",type_arr[expr_type]);} 
                                            $$= join($1,">",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr LTE expr         {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use <= with %s type",type_arr[expr_type]);} 
                                            $$= join($1,"<=",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr GTE expr          {if(expr_type == COMPLEX_TYPE|| expr_type == CLASS_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);} 
                                            $$= join($1,">=",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr EQL expr  %prec LEAST        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                            $$= join($1,"==",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr NOT EQL expr %prec LEAST     {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                        $$= join($1,"!=",$4);free($1);free($4);expr_type = BOOL_TYPE;}
    | expr AND expr  {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                            $$= join($1," && ",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | expr OR expr    {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");} 
                        $$= join($1," || ",$3);free($1);free($3);expr_type = BOOL_TYPE;}
    | NOT expr   {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                    char * t =join("(",$2,")");$$ = join("!",t,"");free(t);free($2);expr_type = BOOL_TYPE;}
    | value
;

value : cmplxnum {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
    | INTNUM {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
    | FLOATNUM { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
    | BOOLVAL   {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
    | STRINGVAL {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}    
    | varvals
;

cmplxnum : '(' expr ',' expr ')' {void* _t = calloc(1, strlen($2) + strlen($4) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, $2);strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, $4);strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            $$ = (char*)_t;free($2);free($4);}
;

varvals :fncall
    | IDENTIFIER { Variable *_t = lookup_var($1);
                    if(_t == NULL){
                        yyerror("Undefined variable %s",$1);
                    }else {
                    is_assignable = _t->m != CONST_TYPE;
                     if(_t->is_arr && !is_in_fncall){
                        yyerror("cannot use arrray without subscript.");
                    }else if(_t->is_class){
                        if(expr_type == CLASS_TYPE){
                            yyerror("Cannot combine class type with anything else");
                        }
                        expr_type = CLASS_TYPE;
                        expr_class = _t->t.class;
                    }else if(expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[_t->t.t],type_arr[expr_type]);;
                    }else if(_t->t.t ==COMPLEX_TYPE){
                        expr_type = COMPLEX_TYPE;
                    }else if(_t->t.t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                        expr_type = FLOAT_TYPE;
                    }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                        expr_type = _t->t.t;
                    }}}
    | IDENTIFIER '[' {push_expr_and_args();} expr ']' { Variable *v = lookup_var($1);
                                                        if(v == NULL){
                                                            yyerror("Undefined variable %s",$$);
                                                        }else if(!v->is_arr){
                                                            yyerror("Subscripted object must be of array");
                                                        }else if(expr_type != INT_TYPE){
                                                            yyerror("Subscript must be of int type got %s type",type_arr[expr_type]);
                                                        }
                                                        char *t = join($1,"[",$4);$$ = join(t,"]","");is_composite_val = true;pop_expr_and_args();free(t);
                                                        if(v != NULL){
                                                            is_assignable = v->m != CONST_TYPE;
                                                            if(v->is_class){
                                                                if(expr_type == CLASS_TYPE){
                                                                    yyerror("Cannot combine class type with anything else");
                                                                }
                                                                expr_type = CLASS_TYPE;
                                                                expr_class = v->t.class;
                                                            }else if( expr_type == STRING_TYPE){
                                                                yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[v->t.t],type_arr[expr_type]);;
                                                            }else if(v->t.t ==COMPLEX_TYPE){
                                                                expr_type = COMPLEX_TYPE;
                                                            }else if(v->t.t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                                                                expr_type = FLOAT_TYPE;
                                                            }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                                                                expr_type = v->t.t;
                                                            }
                                                        }free($1);free($4);}
    | varvals '.' classcheckdummy IDENTIFIER { attr* a = NULL;
                                        if(expr_type == CLASS_TYPE)a = find_attr(expr_class,$4);
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",$4,expr_class);
                                        }else{
                                            is_assignable = a->m != CONST_TYPE;
                                            if(a->is_arr && !is_in_fncall){
                                                yyerror("cannot use arrray without subscript.");
                                            }else if(a->is_class){
                                                expr_type = CLASS_TYPE;
                                                expr_class = a->t.class;
                                            }else if(a->t.t ==COMPLEX_TYPE){
                                                expr_type = COMPLEX_TYPE;
                                            }else if(a->t.t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                                                expr_type = FLOAT_TYPE;
                                            }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                                                expr_type = a->t.t;
                                            }
                                        }
                                        $$ = join($1,".",$4);free($1);free($4);
                                    }
    | varvals '.' classcheckdummy IDENTIFIER '[' {push_expr_and_args();} expr  arraysizedummy']'  { attr* a = NULL;
                                                                                                pop_expr_and_args();
                                                                                            if(expr_type == CLASS_TYPE)a = find_attr(expr_class,$4);    
                                                                                            if(a== NULL){
                                                                                                yyerror("No attribute %s declared on class %s",$1,$4);
                                                                                            }else{
                                                                                                is_assignable = a->m != CONST_TYPE;
                                                                                                if(!a->is_arr){
                                                                                                    yyerror("Subscripted object must be of array.");
                                                                                                }else if(a->is_class){
                                                                                                    expr_type = CLASS_TYPE;
                                                                                                    expr_class = a->t.class;
                                                                                                }else if( expr_type == STRING_TYPE){
                                                                                                yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[a->t.t],type_arr[expr_type]);
                                                                                                }else if(a->t.t ==COMPLEX_TYPE){
                                                                                                    expr_type = COMPLEX_TYPE;
                                                                                                }else if(a->t.t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                                                                                                    expr_type = FLOAT_TYPE;
                                                                                                }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                                                                                                    expr_type = a->t.t;
                                                                                                }
                                                                                            }
                                                                                            char * t = join($1,".",$4);
                                                                                            char *tt = join(t,"[",$7);
                                                                                            $$ = join(tt,"]","");
                                                                                            free(t);free(tt);
                                                                                            free($1);free($4);free($7);
                                                                                        }
;
classcheckdummy : /*nothing*/ {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
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

    pre_class_map = make_hashmap(20, __hash_str__, __compair__str__);
    preparse();
    hm_delete(pre_class_map, pre_class_clean);
    
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
