%{
    #include<stdio.h>
    #include <stdbool.h>
    #include "variables.h"
    #include "parser.h"
    #include "class_decl.h"
    int lastState = 0;
    extern void printcode(char *,...);
    extern bool print_lineno;
    extern bool is_in_fn;
    extern int is_in_loop;
    extern char *crr_file_name;
    extern Class *current_class;
    extern bool is_static_method;
    bool is_class(char *);
%}

%option noyywrap nodefault yylineno

%x RAWSTATE
%x COMMENT

%%
                        /* GENERAL SYMBOL LIST */
\{|\}|!|=|"+"|"-"|"*"|"/"|;                   {return yytext[0];}

"("|")"|","|"["|"]"                              {return yytext[0];}
"<"|">"|"."                                         {return yytext[0];}
"<="                                        {return LTE;}
">="                                        {return GTE;}
"::"                                        {return DCOLON;}

                                /* RULES FOR RAW input*/
                                /* In code, this expects Syntax RAW <{...}>
                                    anything inside <{}> will be copied verbatim to the generated code.
                                    No text inside will be processes. Hence the variables 
                                    declared inside must be declared explicityly outside.
                                */
RAW                               { return RAW; } /* Start of the RAW direction, but we do not switch to RAWSTAE.
                                                    As it is allowed to have spcaes and tabs between RAW and <{,
                                                    if RAWSTATE begin here, they will be processes ad RAWLINE instead of <{ toknen
                                                    As normal syntax of C or this does not use <{ normally anyway, we can put that
                                                    in INITIAL state.
                                                */
[ \t]*"<{"[ \t]*                { lastState = YY_START; BEGIN RAWSTATE; return RAWSTART; } /* check for space  <{  space pattern
                                                                                             as well starts the RAWSTATE.
                                                                                            */
<RAWSTATE>[ \t]*"}>"[ \t]*      { BEGIN lastState;yylval.s = ""; return RAWEND; } /* Ending brackets for RAW syntax. Allows for space - }> space
                                                                    */
<RAWSTATE>[ \t]		                {}
<RAWSTATE>\}                        { char c = input(); if(c != '>'){yylval.s = strdup(yytext);unput(c);return RAWLINE;}
                                        else{yylval.s = ""; BEGIN lastState;return RAWEND;}}/* Check if the } is follwed by a >
                                                                                                    if it is that means it the end of RAW syntax
                                                                                                    else its just a normal closing bracket.
                                                                                                */
<RAWSTATE>[\n]*                         { yylval.s = strdup(yytext);if(print_lineno)printcode("\n#line %d \"%s\"\n",yylineno,crr_file_name); return RAWLINE; }                                                                                                                                                                                                    
<RAWSTATE>[^}]*       	            { yylval.s = strdup(yytext); return RAWLINE; } /* Match All pattern for the internal text of RAW syntax.
                                                                                        except }, used to match the content inside the <{...}>*/
"/*"                                {lastState = YY_START; BEGIN COMMENT;return BEGINCOMMENT;}
<COMMENT>"*/"                       {BEGIN lastState; return ENDCOMMENT;}
<COMMENT>([^*]|\n)+|.              {yylval.s = strdup(yytext);return COMMENTLINE;}
<COMMENT><<EOF>>                    {yyerror("Unterminated multiline comment.");return 0;}

"//".*$                         {yylval.s = strdup(yytext);return COMMENTLINE;}


[ \t]*                              {}
[\n]*                               {printcode("\n");if(print_lineno)printcode("\n#line %d \"%s\"\n",yylineno,crr_file_name);}
                        /* Rules of declarations */
@decl                               {return DECL;} /* Explicit declaration , used to declare the variables that are declared in RAW code*/

fn                                  {return FNDECL;}

"->"                                {return RETTYPE;}

class                               {return CLASS;}
@static                             {return STATICMETHOD;}

this                                {if(current_class == NULL || is_static_method){yyerror("Canot use this outside class mthods or inside static methods.");}else{return THIS;}}

bool                                { yylval.t = BOOL_TYPE; return BOOL; }
complex                             { yylval.t = COMPLEX_TYPE; return COMPLEX; }
int                                 { yylval.t = INT_TYPE;return INT; }
double                              { yylval.t = DOUBLE_TYPE;return DOUBLE; }
float                               { yylval.t = FLOAT_TYPE;return FLOAT; }
long                                { yylval.t = LONG_TYPE;return LONG; }
short                               { yylval.t = SHORT_TYPE;return SHORT; }
void                                { yylval.t = VOID_TYPE;return VOID; }
string                              { yylval.t = STRING_TYPE; return STRING; }
charbuf                             {return CHARBUF;}
let                                 {return LET;}

const                               { yylval.m = CONST_TYPE; return CONST; }
static                              { yylval.m = STATIC_TYPE; return STATIC; }

mod                                  { return MOD;}

eql                                   {return EQL;}
and                                     {return AND;}
or                                      {return OR;}
not                                     {return NOT;}

if                                   {return IF;}
else                                 {return ELSE;}

while                               {return WHILE;}
for                                 {return FOR;}
in                                 {return IN;}

break                               {if(is_in_loop <= 0){yyerror("Cannot use break outside a Loop.");}else{return BREAK;}}
continue                            {if(is_in_loop <= 0){yyerror("Cannot use continue outside a Loop.");}else{return CONTINUE;}}

true|false                           {yylval.s = strdup(yytext);return BOOLVAL;}

return                               { if(is_in_fn){return RETURN;}else{yyerror("Cannot use return outside function.\n");} }

auto|char|enum|extern|inline|register   {yyerror("Keyword %s is not support, consider using RAW<{..}>",yytext);}
restrict|signed|struct|typedef|union    {yyerror("Keyword %s is not support, consider using RAW<{..}>",yytext);}
unsigned|volatile|switch|case|default   {yyerror("Keyword %s is not support, consider using RAW<{..}>",yytext);}
do|goto|sizeof|I                          {yyerror("Keyword %s is not support, consider using RAW<{..}>",yytext);}

\"(\\.|[^\"\n])*\"                      {yylval.s = strdup(yytext);return STRINGVAL;}
\"(\\.|[^\"\n])*$                       {yyerror("unterminated string "); yylval.s = strdup(yytext);return ';';}

0[0-7]*|[0-9]*|0[Xx][0-9a-fA-f]+      { yylval.s = strdup(yytext); return INTNUM; }

([0-9]*\.[0-9]+|[0-9]*\.[0-9]+([Ee][-+]?[0-9]+)?)       { yylval.s = strdup(yytext); return FLOATNUM; }

__temp[0-9]+                                        {yyerror("Invalid variable name : Variable name format '__temp(number)' is reserved.");}

[_a-zA-Z][_a-zA-Z0-9]*           {yylval.s = strdup(yytext); if(is_class(yytext)){return CLASSNAME;}else{return IDENTIFIER;}}

.                               {fprintf(stderr,"unknown token '%s'\n",yytext);}
%%
