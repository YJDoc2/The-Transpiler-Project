%{
    #include<stdio.h>
    #include <stdbool.h>
    #include "variables.h"
    #include "preparser.h"
    int preerror(char *);
    extern bool in_fn;
    int nbrack = 0;
%}

%option noyywrap nodefault yylineno
%option prefix="pre"
%option outfile="prelex.c"

%x RAWSTATE

%%

\{                   {if(!in_fn)return pretext[0]; ++nbrack;}
\}                   {if(nbrack ==0)return pretext[0]; --nbrack;}
"("|")"|","                                {if(!in_fn)return pretext[0];}


RAW                               { } 
[ \t]*"<{"[ \t]*                { BEGIN RAWSTATE;  } 
<RAWSTATE>[ \t]*"}>"[ \t]*      { BEGIN 0; } 
<RAWSTATE>[ \t]		                {}
<RAWSTATE>\}                        { char c = input(); if(c != '>'){}else{BEGIN 0;}}                                                                                           
<RAWSTATE>[^}]*       	            { }

fn                                  {return FNDECL;}

"->"                                {return RETTYPE;}

[ \t\n]*                              {}

bool                                { prelval.t = BOOL_TYPE; if(!in_fn)return BOOL; }
complex                             { prelval.t = COMPLEX_TYPE; if(!in_fn)return COMPLEX; }
int                                 { prelval.t = INT_TYPE;if(!in_fn)return INT; }
double                              { prelval.t = DOUBLE_TYPE;if(!in_fn)return DOUBLE; }
float                               { prelval.t = FLOAT_TYPE;if(!in_fn)return FLOAT; }
long                                { prelval.t = LONG_TYPE;if(!in_fn)return LONG; }
short                               { prelval.t = SHORT_TYPE;if(!in_fn)return SHORT; }
void                                { prelval.t = VOID_TYPE;if(!in_fn)return VOID; }
string                              { prelval.t = STRING_TYPE; if(!in_fn)return STRING; }

const                               { prelval.m = CONST_TYPE; if(!in_fn)return CONST; }
static                              { prelval.m = STATIC_TYPE; if(!in_fn)return STATIC; }


__temp[0-9]+                                        {preerror("Invalid variable name : Variable name format '__temp(number)' is reserved.");}

[_a-zA-Z][_a-zA-Z0-9]*           {if(!in_fn){prelval.s = strdup(yytext);return IDENTIFIER;}}

.                                   {}

%%

int preerror(char *s){
    printf("%s\n",s);

}