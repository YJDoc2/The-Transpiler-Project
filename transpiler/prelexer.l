%{
    #include<stdio.h>
    #include <stdbool.h>
    #include <errno.h>
    #include "variables.h"
    #include "preparser.h"
    #include "filenames.h"
    int preerror(char *);
    extern bool in_fn;
    int nbrack = 0;
    extern int errs;
    extern bool pre_in_class;
    Hashmap pre_class_map;
    extern char * crr_file_name;

    static bool pre_is_class(char *);

    struct bufstack{
        struct bufstack *prev;
        YY_BUFFER_STATE bs;
        int lineno;
        char * filename;
        FILE *f;
    };
    static struct bufstack *crrbs = NULL;

    static int push_file(char*name);
    static int pop_file();
%}

%option noyywrap nodefault yylineno
%option prefix="pre"
%option outfile="prelex.c"

%x RAWSTATE
%x COMMENT
%x USE

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


use                                     {BEGIN USE;}
<USE>[ \n\t"]*                                 {}
<USE>(\\.|[^\"\n])*                      {if(!push_file(pretext)){yyterminate();}BEGIN INITIAL;char c = input();if(c != '"')unput(c);}

"/*"                                { BEGIN COMMENT;}
<COMMENT>"*/"                       {BEGIN 0;}
<COMMENT>([^*]|\n)+|.               {}
<COMMENT><<EOF>>                    {preerror("Unterminated multiline comment.");if(!pop_file()){yyterminate();}}

"//".*\n                            {}

class                               {return CLASS;}

fn                                  {if(!pre_in_class)return FNDECL;}

"->"                                {if(!in_fn && !pre_in_class)return RETTYPE;}

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

const                               { prelval.m = CONST_TYPE; if(!in_fn && !pre_in_class)return CONST; }
static                              { prelval.m = STATIC_TYPE; if(!in_fn && !pre_in_class)return STATIC; }

<<EOF>>                             {if(!pop_file()){yyterminate();}char c = input();if(c != '"')unput(c);}

\"(\\.|[^\"\n])*\"                      {}
\"(\\.|[^\"\n])*$                       {preerror("unterminated string ");}

__temp[0-9]+                            {preerror("Invalid variable name : Variable name format '__temp(number)' is reserved.");}

[_a-zA-Z][_a-zA-Z0-9]*           {if(!in_fn && !pre_in_class){prelval.s = yytext;if(pre_is_class(yytext)){return CLASSNAME;}else{return IDENTIFIER;}}}

.                                   {}

%%

static bool pre_is_class(char *name){
    void* v = hm_get(&pre_class_map,name);
    return v != NULL;
}

int preerror(char *s){
    ++errs;
    if(s == NULL)return 0;
    if(in_fn)fprintf(stderr,"Syntax error on line %d : %s\n",prelineno,s);
    return 0;
}

static int push_file(char *name){
    if(is_visited(name)){
        return 1;
    }
    FILE * f=fopen(name,"r");
    struct bufstack *bs = (struct bufstack*)calloc(1,sizeof(struct bufstack));
    if(f == NULL){
        ++errs;
        perror("cannot open file :");
        return 0;
    }
    if(crrbs == NULL){
        crrbs = (struct bufstack*)calloc(1,sizeof(struct bufstack));
        crrbs->prev = NULL;
        crrbs->lineno = prelineno;
        crrbs->filename = crr_file_name;
        crrbs->bs = YY_CURRENT_BUFFER;
        crrbs->f = prein;
    }
    crr_file_name = insert_filename(name);
    bs->prev = crrbs;
    bs->bs = yy_create_buffer(f,YY_BUF_SIZE);
    bs->f = f;
    bs->filename = crr_file_name;
    yy_switch_to_buffer(bs->bs);
    crrbs = bs;
    prelineno = 1;
    return 1;
}

static int pop_file(){
    struct bufstack *bs = crrbs;
    if(!bs)return 0;
    struct bufstack *prev = crrbs->prev;
    if(prev == NULL)return 0;
    if(prev->prev != NULL){
        fclose(bs->f);
    }
    yy_delete_buffer(bs->bs);
    free(bs);
    yy_switch_to_buffer(prev->bs);
    crrbs = prev;
    prelineno = crrbs->lineno;
    crr_file_name = crrbs->filename;
    return 1;
}