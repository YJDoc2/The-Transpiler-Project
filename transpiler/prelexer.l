%{
    #include<stdio.h>
    #include <stdbool.h>
    #include "variables.h"
    #include "preparser.h"
    int preerror(char *);
    extern bool in_fn;
    int nbrack = 0;
    extern int errs;
    extern bool pre_in_class;
%}

%option noyywrap nodefault yylineno
%option prefix="pre"
%option outfile="prelex.c"

%x RAWSTATE
%x COMMENT

%%

\{                   {if(!in_fn && !pre_in_class)return pretext[0]; ++nbrack;}
\}                   {if(nbrack ==0)return pretext[0]; --nbrack;}
"("|")"|","|"["|"]"                               {if(!in_fn && !pre_in_class)return pretext[0];}


RAW                               { } 
[ \t]*"<{"[ \t]*                { BEGIN RAWSTATE;  } 
<RAWSTATE>[ \t]*"}>"[ \t]*      { BEGIN 0; } 
<RAWSTATE>[ \t]		                {}
<RAWSTATE>\}                        { char c = input(); if(c != '>'){}else{BEGIN 0;}}                                                                                           
<RAWSTATE>[^}]*       	            { }


"/*"                                { BEGIN COMMENT;}
<COMMENT>"*/"                       {BEGIN 0;}
<COMMENT>([^*]|\n)+|.               {}
<COMMENT><<EOF>>                    {preerror("Unterminated multiline comment.");return 0;}

"//".*\n                            {}

class                               {return CLASS;}

fn                                  {if(!pre_in_class)return FNDECL;}

"->"                                {if(!pre_in_class)return RETTYPE;}

[ \t\n]*                              {}

bool                                { prelval.t = BOOL_TYPE; if(!in_fn && !pre_in_class)return BOOL; }
complex                             { prelval.t = COMPLEX_TYPE; if(!in_fn && !pre_in_class)return COMPLEX; }
int                                 { prelval.t = INT_TYPE;if(!in_fn && !pre_in_class)return INT; }
double                              { prelval.t = DOUBLE_TYPE;if(!in_fn && !pre_in_class)return DOUBLE; }
float                               { prelval.t = FLOAT_TYPE;if(!in_fn && !pre_in_class)return FLOAT; }
long                                { prelval.t = LONG_TYPE;if(!in_fn && !pre_in_class)return LONG; }
short                               { prelval.t = SHORT_TYPE;if(!in_fn && !pre_in_class)return SHORT; }
void                                { prelval.t = VOID_TYPE;if(!in_fn && !pre_in_class)return VOID; }
string                              { prelval.t = STRING_TYPE; if(!in_fn && !pre_in_class)return STRING; }

let                                 {}
class                               {}

const                               { prelval.m = CONST_TYPE; if(!in_fn && !pre_in_class)return CONST; }
static                              { prelval.m = STATIC_TYPE; if(!in_fn && !pre_in_class)return STATIC; }


\"(\\.|[^\"\n])*\"                      {}
\"(\\.|[^\"\n])*$                       {preerror("unterminated string ");}

__temp[0-9]+                                        {preerror("Invalid variable name : Variable name format '__temp(number)' is reserved.");}

[_a-zA-Z][_a-zA-Z0-9]*           {if(!in_fn && !pre_in_class){prelval.s = yytext;return IDENTIFIER;}}

.                                   {}

%%

int preerror(char *s){
    ++errs;
    if(s == NULL)return 0;
    if(in_fn){
        fprintf(stderr,"Syntax error on line %d",prelineno);
    }
    return 0;

}