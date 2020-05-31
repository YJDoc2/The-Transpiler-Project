/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_PRE_PREPARSER_TAB_H_INCLUDED
# define YY_PRE_PREPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef PREDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PREDEBUG 1
#  else
#   define PREDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PREDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PREDEBUG */
#if PREDEBUG
extern int predebug;
#endif

/* Token type.  */
#ifndef PRETOKENTYPE
# define PRETOKENTYPE
  enum pretokentype
  {
    BOOL = 258,
    COMPLEX = 259,
    CONST = 260,
    STATIC = 261,
    DOUBLE = 262,
    FLOAT = 263,
    LONG = 264,
    SHORT = 265,
    VOID = 266,
    INT = 267,
    STRING = 268,
    FNDECL = 269,
    RETTYPE = 270,
    IDENTIFIER = 271
  };
#endif

/* Value type.  */
#if ! defined PRESTYPE && ! defined PRESTYPE_IS_DECLARED
union PRESTYPE
{
#line 16 "preparser.y"

    char *s;
    type t;
    modifier m;

#line 88 "preparser.tab.h"

};
typedef union PRESTYPE PRESTYPE;
# define PRESTYPE_IS_TRIVIAL 1
# define PRESTYPE_IS_DECLARED 1
#endif


extern PRESTYPE prelval;

int preparse (void);

#endif /* !YY_PRE_PREPARSER_TAB_H_INCLUDED  */
