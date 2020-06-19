/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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
    type temp_type;
    char * temp_class;
    bool is_assignable = false;
    bool is_static_method;


#line 117 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    LEAST = 258,
    EQL = 259,
    AND = 260,
    OR = 261,
    LTE = 262,
    GTE = 263,
    MOD = 264,
    UMINUS = 265,
    NOT = 266,
    BOOL = 267,
    COMPLEX = 268,
    CONST = 269,
    STATIC = 270,
    DOUBLE = 271,
    FLOAT = 272,
    LONG = 273,
    SHORT = 274,
    VOID = 275,
    INT = 276,
    STRING = 277,
    CHARBUF = 278,
    BREAK = 279,
    CONTINUE = 280,
    FOR = 281,
    IF = 282,
    ELSE = 283,
    RETURN = 284,
    WHILE = 285,
    IN = 286,
    RAW = 287,
    DECL = 288,
    LET = 289,
    IDENTIFIER = 290,
    BOOLVAL = 291,
    STRINGVAL = 292,
    FNDECL = 293,
    RETTYPE = 294,
    INTNUM = 295,
    FLOATNUM = 296,
    RAWSTART = 297,
    RAWEND = 298,
    RAWLINE = 299,
    BEGINCOMMENT = 300,
    ENDCOMMENT = 301,
    COMMENTLINE = 302,
    CLASS = 303,
    STATICMETHOD = 304,
    THIS = 305,
    CLASSNAME = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 48 "parser.y"

    char *s;
    type t;
    modifier m;
    bool b;

#line 228 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  221
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  429

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      63,    64,    13,    11,    65,    12,    67,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    58,
       9,    66,    10,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   100,   100,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   114,   115,   116,   120,   121,   122,   125,   126,
     127,   128,   129,   130,   132,   133,   137,   137,   137,   139,
     140,   141,   145,   148,   156,   164,   165,   168,   171,   173,
     174,   176,   177,   177,   187,   187,   200,   204,   212,   212,
     222,   227,   228,   229,   231,   232,   233,   234,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   249,
     250,   251,   252,   253,   254,   257,   257,   258,   260,   261,
     263,   270,   277,   280,   280,   281,   281,   282,   282,   283,
     283,   284,   284,   285,   296,   299,   300,   306,   306,   307,
     308,   314,   314,   320,   321,   322,   323,   326,   327,   330,
     333,   337,   337,   338,   341,   346,   346,   349,   355,   356,
     356,   357,   357,   361,   363,   374,   385,   386,   397,   397,
     398,   398,   401,   402,   404,   406,   406,   409,   409,   412,
     414,   418,   424,   429,   429,   471,   472,   473,   476,   484,
     509,   515,   516,   517,   518,   519,   520,   523,   524,   525,
     525,   528,   532,   536,   536,   539,   539,   540,   540,   541,
     541,   542,   542,   545,   549,   571,   592,   592,   596,   596,
     599,   599,   602,   602,   605,   605,   609,   621,   622,   625,
     625,   629,   629,   633,   633,   637,   637,   641,   641,   644,
     644,   647,   647,   650,   650,   653,   656,   659,   664,   669,
     675,   680,   681,   682,   685,   694,   716,   716,   743,   764,
     764,   793
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LEAST", "EQL", "AND", "OR", "LTE",
  "GTE", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "MOD", "UMINUS", "NOT",
  "BOOL", "COMPLEX", "CONST", "STATIC", "DOUBLE", "FLOAT", "LONG", "SHORT",
  "VOID", "INT", "STRING", "CHARBUF", "BREAK", "CONTINUE", "FOR", "IF",
  "ELSE", "RETURN", "WHILE", "IN", "RAW", "DECL", "LET", "IDENTIFIER",
  "BOOLVAL", "STRINGVAL", "FNDECL", "\"->\"", "INTNUM", "FLOATNUM",
  "\"<{\"", "\"}>\"", "RAWLINE", "BEGINCOMMENT", "ENDCOMMENT",
  "COMMENTLINE", "CLASS", "STATICMETHOD", "THIS", "CLASSNAME", "';'",
  "'{'", "'}'", "'['", "']'", "'('", "')'", "','", "'='", "'.'", "$accept",
  "program", "type", "modifier", "topstmtlist", "topstmt", "rawlist",
  "classdef", "$@1", "$@2", "attrlist", "arraysign", "methodlist", "$@3",
  "$@4", "staticdummy", "methoddummy", "fndeclaration", "$@5",
  "fndecldummy", "paramlist", "param", "stmtlist", "stmt", "comment",
  "$@6", "commentlist", "returnstmt", "vardeclaration", "$@7", "$@8",
  "$@9", "$@10", "$@11", "classvarlist", "$@12", "$@13", "decllist",
  "classdecllist", "varlist", "$@14", "$@15", "arraydecl", "$@16", "$@17",
  "arraysizedummy", "letarraydecl", "letarrvals", "chararrdecllist",
  "$@18", "$@19", "strdecl", "$@20", "$@21", "arrayvallist", "fncall",
  "$@22", "arglist", "arg", "assignstmt", "assigndummy", "assgtype",
  "ifstmt", "$@23", "ifdummy", "elsedummy", "whilestmt", "$@24", "forstmt",
  "$@25", "$@26", "$@27", "$@28", "rangecheckdummy", "simplearraydummy",
  "iterarraydummy", "expr", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34",
  "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "value",
  "cmplxnum", "varvals", "$@42", "$@43", "classcheckdummy", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    60,
      62,    43,    45,    42,    47,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,    59,   123,
     125,    91,    93,    40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF (-299)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-175)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -299,    17,   953,  -299,  -299,  -299,  -299,    20,    37,    35,
      38,  -299,  -299,    55,   347,  -299,  -299,  -299,  -299,    40,
    -299,   172,   -52,  -299,    58,  -299,    45,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
      90,  -299,  -299,   984,   258,  -299,   103,  -299,    73,    86,
     123,  -299,  -299,   125,   135,   258,   258,   -21,  -299,  -299,
    -299,  -299,    57,   920,  -299,  1163,  -299,  -299,    79,  1163,
    -299,  -299,  -299,  -299,  -299,   127,   -50,   141,   -25,   143,
     148,   146,   164,   162,   214,   214,  -299,  -299,   188,   122,
     273,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,   254,   202,  -299,    -2,   789,   204,   228,
     258,   210,   232,   258,   210,   233,   229,  -299,   252,   234,
     256,   258,  -299,   258,   258,  -299,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,  -299,
     206,   261,   250,    37,  1087,  -299,   245,   260,    37,  1098,
    -299,  -299,   991,  -299,  -299,  1163,  1027,  -299,    -1,  1163,
    -299,    64,  -299,   148,  -299,   248,   846,   277,   -26,  1163,
     214,   344,  1163,   242,   242,   121,   121,   121,   121,   190,
     190,   293,   293,   293,   258,   253,   255,    37,  -299,   270,
     272,  -299,  -299,  1109,   274,   284,    62,    82,   860,   204,
     262,   874,   258,   210,   258,   210,  -299,   265,  -299,  -299,
     258,  -299,  1163,  -299,   258,  -299,  1163,   258,  -299,  1123,
     268,   269,   130,   290,   291,     8,    47,   292,  -299,  -299,
     295,  1038,   258,  -299,  -299,   275,   279,  1163,  -299,  1163,
    -299,  -299,  -299,  1163,    89,   258,  -299,   281,   300,  -299,
     148,   148,  -299,   258,  -299,   258,   251,   294,  -299,   888,
    1163,    96,  -299,   287,  -299,  1163,   304,  -299,  -299,   278,
     306,  1163,  1163,  -299,   330,  -299,   258,   258,   258,  -299,
     305,  -299,  -299,  -299,   334,   339,  -299,  -299,   336,   906,
    1163,    98,  1163,  -299,  -299,   359,   348,   349,    51,  -299,
     346,  -299,  -299,   258,   258,   203,  -299,  -299,   368,   258,
     258,   258,   363,    29,  -299,   355,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,    79,  -299,  -299,   369,    54,  -299,
     351,  1163,   105,  -299,  -299,  -299,   -27,    18,  1163,  1007,
    -299,  -299,  -299,    41,  1123,   370,   258,   377,  -299,  1045,
     398,  -299,  -299,   133,   352,   378,   379,   381,   382,  -299,
     258,  -299,  1123,   112,  -299,   169,   209,   412,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  1163,   391,  -299,  -299,
     258,  -299,   384,   411,   402,   445,  -299,   395,   113,   397,
     258,  -299,   423,  -299,   488,  -299,  -299,  -299,   231,  -299,
     399,  -299,   531,   574,   393,  -299,   420,  -299,   428,  -299,
    -299,   258,   429,  -299,  -299,  -299,  1163,  -299,   617,   660,
    -299,   703,  -299,  -299,   431,  -299,  -299,   746,  -299
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    75,    77,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,    94,     0,    78,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    91,    87,    89,    19,
       0,    85,    83,     0,     0,    48,     0,    26,     0,     0,
       0,    18,    25,     0,     0,     0,     0,   215,   210,   211,
     208,   209,     0,     0,   212,   123,   206,   207,   213,    93,
      51,    76,    79,    29,   128,    92,    95,    88,   109,    90,
      39,    86,   103,    84,   188,   205,   216,   143,     0,     0,
       0,   197,   201,   203,   193,   195,   189,   191,   176,   178,
     180,   182,   184,     0,     0,   221,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,   145,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,     0,     0,    12,     0,    52,     0,     0,    12,     0,
      41,    38,     0,   129,   130,    96,     0,    98,    99,   110,
     112,   113,    40,    39,   104,   105,     0,     0,     0,   126,
     186,     0,   198,   202,   204,   194,   196,   190,   192,   177,
     179,   181,   183,   185,     0,     0,   218,    12,    53,     0,
       0,    30,    24,     0,     0,     0,     0,     0,     0,     0,
     118,     0,     0,     0,     0,     0,   108,     0,   217,   144,
       0,   146,   148,   124,     0,   214,   200,     0,   219,     0,
      56,    54,     0,     0,     0,     0,     0,     0,    46,    28,
       0,     0,     0,   123,   131,     0,   117,   100,   102,   114,
     116,   106,   147,   127,     0,     0,    50,     0,     0,    35,
      39,    39,    33,     0,    31,     0,     0,     0,   140,     0,
     134,   132,   119,     0,   125,   123,     0,    57,    55,     0,
       0,   123,   123,    42,     0,   123,     0,     0,     0,   123,
       0,    58,    37,    36,     0,     0,    51,    44,     0,     0,
     133,     0,   141,   121,   220,     0,     0,     0,    12,    51,
       0,   123,   120,     0,     0,     0,    73,    74,     0,     0,
      81,     0,     0,    12,    49,    64,    65,    71,    69,    70,
      72,    66,    67,    68,   150,    34,    32,     0,    12,   137,
     139,   142,     0,    60,    62,    61,     0,     0,    80,     0,
      24,    82,    63,     0,     0,     0,     0,     0,   122,     0,
       0,   161,   163,     0,     0,     0,     0,     0,     0,   151,
       0,    47,     0,     0,   135,   215,     0,     0,    58,    58,
      59,   152,   153,   154,   155,   156,   149,     0,    47,   138,
       0,   169,     0,     0,     0,     0,    58,     0,     0,     0,
       0,   175,   157,   164,     0,    58,   136,    58,   173,   171,
     159,    43,     0,     0,     0,   165,     0,   162,     0,    45,
     170,     0,     0,    58,    58,   160,   173,    58,     0,     0,
     167,     0,   172,   158,     0,   166,    58,     0,   168
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -299,  -299,   -18,    -6,  -299,  -299,  -188,  -299,  -299,  -299,
    -299,  -148,  -299,  -299,  -299,  -299,   104,  -299,  -299,  -299,
    -240,   350,   538,  -299,     5,  -299,  -299,  -299,   485,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -106,  -299,  -299,  -228,  -299,   280,  -299,  -299,
    -299,   296,  -299,  -299,  -298,  -274,  -299,  -299,   282,  -299,
    -299,  -299,    83,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -299,    78,  -299,  -299,   -43,  -299,  -299,  -299,
    -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,  -299,
    -299,  -299,  -234,  -299,  -299,  -299
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    73,   150,
     107,   117,   196,   286,   299,   230,   377,    17,    70,   266,
     106,   145,   295,   315,   316,    25,    46,   317,   318,    54,
      53,    49,    50,    48,    77,   111,   203,    83,    81,    79,
     114,   205,   157,   278,   304,   104,    23,   168,    75,   108,
     199,   153,   380,   346,   291,    64,   122,   167,   211,   320,
     343,   360,   321,   408,   368,   414,   322,   369,   323,   412,
     424,   389,   406,   405,   381,   399,   292,   134,   135,   136,
     137,   138,   132,   133,   130,   131,   127,   184,   128,   129,
      66,    67,    68,   121,   245,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    69,    21,    42,   222,   261,   332,    18,   160,    43,
     349,   -97,    84,    85,    44,   206,   110,     3,     5,     6,
      90,   319,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   213,   103,  -111,   280,   350,   214,
      86,   113,    87,   284,   285,    89,   298,   288,   363,     5,
       6,   293,   354,   355,   356,   357,   358,     5,     6,   328,
    -101,   324,   142,   143,   341,   202,   252,   155,    20,   253,
     159,     5,     6,   330,     5,     6,    22,   351,   166,    24,
     169,   170,   388,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    26,   238,    39,   240,
     144,   149,   269,   270,    47,   254,   227,   359,   255,   198,
     319,   319,   151,   201,    74,   327,   143,   228,   345,   143,
     319,    45,   229,    88,   212,  -115,   190,    76,   319,   319,
     204,   195,    98,    99,   100,   101,   102,   144,   103,    51,
      52,   216,   193,   231,   319,   319,   105,   319,   232,   264,
     324,   324,   353,   319,   214,    71,    72,   276,   302,   237,
     324,   239,   277,   303,    78,   348,    80,   212,   324,   324,
     303,   243,   379,   396,   169,   224,    82,   303,   303,   249,
      52,   219,   370,    52,   324,   324,   124,   324,   259,   260,
      27,    28,   109,   324,    29,    30,    31,    32,    33,    34,
      35,   246,   265,   100,   101,   102,   112,   103,   115,   116,
     271,   118,   272,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   119,   103,   120,  -174,    41,
      86,  -175,    87,   289,   290,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   123,   103,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   139,   103,
     331,   333,   334,   335,   140,   152,   337,   338,   339,   154,
      55,   156,   185,   158,   161,    56,   382,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    55,
     103,   162,   144,   163,    56,   187,   164,   165,   404,    57,
      58,    59,   186,   191,    60,    61,   366,    21,   192,   207,
     103,   220,   217,   221,   273,   225,   218,   376,    57,    58,
      59,    63,   144,    60,    61,   226,   361,   241,   235,   247,
     248,   250,   251,   256,   262,   274,   282,   125,   126,   257,
      63,   209,   210,   267,   378,   263,   279,   398,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     305,   103,   268,   281,   283,    27,    28,   294,   416,    29,
      30,    31,    32,    33,    34,    35,    36,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   306,
     307,   308,   309,   287,   310,   311,   296,   312,   313,     9,
      57,   297,   300,   305,    37,   329,   325,   326,   215,   336,
      11,   340,    12,   342,   344,   362,   -12,   347,   371,   314,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   306,   307,   308,   309,   364,   310,   311,   367,
     312,   313,     9,    57,   372,   373,   305,   374,   375,   383,
     386,   390,   391,    11,   395,    12,   397,   400,   407,   -12,
     411,   309,   392,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   306,   307,   308,   309,   413,
     310,   311,   387,   312,   313,     9,    57,    19,   417,   305,
     426,   415,   242,   188,   420,   234,    11,   244,    12,     0,
       0,     0,   -12,     0,     0,   393,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   306,   307,
     308,   309,     0,   310,   311,     0,   312,   313,     9,    57,
       0,     0,   305,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,     0,   -12,     0,     0,   401,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   306,   307,   308,   309,     0,   310,   311,     0,   312,
     313,     9,    57,     0,     0,   305,     0,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,   -12,     0,
       0,   409,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   306,   307,   308,   309,     0,   310,
     311,     0,   312,   313,     9,    57,     0,     0,   305,     0,
       0,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,   -12,     0,     0,   410,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   306,   307,   308,
     309,     0,   310,   311,     0,   312,   313,     9,    57,     0,
       0,   305,     0,     0,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,   -12,     0,     0,   422,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     306,   307,   308,   309,     0,   310,   311,     0,   312,   313,
       9,    57,     0,     0,   305,     0,     0,     0,     0,     0,
       0,    11,     0,    12,     0,     0,     0,   -12,     0,     0,
     423,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   306,   307,   308,   309,     0,   310,   311,
       0,   312,   313,     9,    57,     0,     0,   305,     0,     0,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
     -12,     0,     0,   425,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   306,   307,   308,   309,
       0,   310,   311,     0,   312,   313,     9,    57,     0,     0,
     146,     0,     0,     0,     0,     0,     0,    11,     0,    12,
       0,     0,     0,   -12,     0,     0,   428,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,     0,
       0,     0,     0,   -27,     0,     0,     0,     0,     0,     0,
      11,     0,    12,     0,   -27,     0,   -12,     0,     0,   -27,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,   103,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,   103,   384,   385,   208,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   233,   103,   394,     0,     0,     0,     0,     0,
       0,     0,    55,   402,     0,   403,   236,    56,    27,    28,
       0,     0,    29,    30,    31,    32,    33,    34,    35,     0,
     275,   418,   419,    -2,     4,   421,     0,     0,     0,     0,
       0,    57,    58,    59,   427,     0,    60,    61,   301,     0,
       0,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,    63,     0,     0,     0,     0,     0,     0,
       0,     7,     8,     9,     0,     0,    55,    10,     0,     0,
       0,    56,     0,    55,    11,     0,    12,    13,    56,     0,
     -12,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,    57,    58,    59,     0,     0,
      60,    61,    57,    58,    59,     0,     0,    60,    61,    55,
       0,     0,     0,     0,    56,     0,    62,    63,     0,     0,
      55,     0,     0,   197,    63,    56,     0,    55,     0,     0,
       0,     0,    56,     0,     0,     0,   352,     0,    57,    58,
      59,     0,     0,    60,    61,     0,     0,     0,     0,    57,
      58,    59,     0,     0,    60,    61,   365,    58,    59,   200,
      63,    60,    61,     0,     0,     0,     0,     0,     0,     0,
     258,    63,     0,     0,     0,    27,    28,     0,    63,    29,
      30,    31,    32,    33,    34,    35,    27,    28,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    27,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,    27,    28,     0,   189,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   223,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103
};

static const yytype_int16 yycheck[] =
{
      43,    44,     8,    21,   192,   233,   304,     2,   114,    61,
      37,    61,    55,    56,    66,   163,    66,     0,    20,    21,
      63,   295,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    60,    17,    61,   265,    65,    65,
      61,    66,    63,   271,   272,    63,   286,   275,   346,    20,
      21,   279,    11,    12,    13,    14,    15,    20,    21,   299,
      61,   295,    64,    65,    35,    66,    58,   110,    48,    61,
     113,    20,    21,   301,    20,    21,    41,    59,   121,    41,
     123,   124,   380,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    41,   203,    58,   205,
     106,   107,   250,   251,    59,    58,    44,    66,    61,   152,
     384,   385,   107,   156,    41,    64,    65,    55,    64,    65,
     394,    63,    60,    66,   167,    61,   144,    41,   402,   403,
      66,   149,    11,    12,    13,    14,    15,   143,    17,    49,
      50,   184,   148,    61,   418,   419,    67,   421,    66,    60,
     384,   385,   340,   427,    65,    52,    53,    61,    60,   202,
     394,   204,    66,    65,    41,    60,    41,   210,   402,   403,
      65,   214,    60,    60,   217,   193,    41,    65,    65,    49,
      50,   187,    49,    50,   418,   419,    64,   421,   231,   232,
      18,    19,    65,   427,    22,    23,    24,    25,    26,    27,
      28,   219,   245,    13,    14,    15,    65,    17,    65,    61,
     253,    65,   255,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    61,    17,    65,    59,    57,
      61,    17,    63,   276,   277,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    59,    17,     7,
       8,     9,    10,    11,    12,    13,    14,    15,     4,    17,
     303,    58,    59,    60,    62,    61,   309,   310,   311,    41,
      12,    61,    66,    41,    41,    17,    67,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    12,
      17,    62,   298,    41,    17,    45,    62,    41,    67,    41,
      42,    43,    41,    58,    46,    47,   349,   313,    48,    61,
      17,    41,    59,    41,    63,    41,    61,   360,    41,    42,
      43,    63,   328,    46,    47,    41,   344,    62,    66,    61,
      61,    41,    41,    41,    59,    41,    58,    64,    65,    44,
      63,    64,    65,    62,   362,    66,    59,   390,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
       1,    17,    62,    59,    58,    18,    19,    62,   411,    22,
      23,    24,    25,    26,    27,    28,    29,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    63,    35,    36,    62,    38,    39,    40,
      41,    62,    66,     1,    57,    59,    58,    58,    64,    41,
      51,    48,    53,    58,    45,    45,    57,    66,    66,    60,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    59,    35,    36,    41,
      38,    39,    40,    41,    66,    66,     1,    66,    66,    37,
      59,    67,    41,    51,    59,    53,    59,    34,    59,    57,
      67,    33,    60,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    59,
      35,    36,   378,    38,    39,    40,    41,     2,    59,     1,
      59,   408,   210,   143,   416,   199,    51,   217,    53,    -1,
      -1,    -1,    57,    -1,    -1,    60,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,    -1,
      -1,    60,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    57,    -1,    -1,    60,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    60,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,
      60,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      57,    -1,    -1,    60,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    -1,    -1,    57,    -1,    -1,    60,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    -1,    55,    -1,    57,    -1,    -1,    60,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,   368,   369,    62,    -1,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    62,    17,   386,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,   395,    -1,   397,    62,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      62,   413,   414,     0,     1,   417,    -1,    -1,    -1,    -1,
      -1,    41,    42,    43,   426,    -1,    46,    47,    62,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    12,    44,    -1,    -1,
      -1,    17,    -1,    12,    51,    -1,    53,    54,    17,    -1,
      57,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    41,    42,    43,    -1,    -1,
      46,    47,    41,    42,    43,    -1,    -1,    46,    47,    12,
      -1,    -1,    -1,    -1,    17,    -1,    62,    63,    -1,    -1,
      12,    -1,    -1,    62,    63,    17,    -1,    12,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    59,    -1,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    41,
      42,    43,    -1,    -1,    46,    47,    41,    42,    43,    62,
      63,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    18,    19,    -1,    63,    22,
      23,    24,    25,    26,    27,    28,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    18,    19,    -1,    57,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    72,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    71,    73,    75,    85,    92,    96,
      48,    71,    41,   114,    41,    93,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    57,    70,    58,
      74,    57,    70,    61,    66,    63,    94,    59,   101,    99,
     100,    49,    50,    98,    97,    12,    17,    41,    42,    43,
      46,    47,    62,    63,   123,   144,   158,   159,   160,   144,
      86,    52,    53,    76,    41,   116,    41,   102,    41,   107,
      41,   106,    41,   105,   144,   144,    61,    63,    66,    70,
     144,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,   113,    67,    88,    78,   117,    65,
      66,   103,    65,    66,   108,    65,    61,    79,    65,    61,
      65,   161,   124,    59,    64,    64,    65,   154,   156,   157,
     152,   153,   150,   151,   145,   146,   147,   148,   149,     4,
      62,   163,    64,    65,    71,    89,     1,    38,    39,    71,
      77,    92,    61,   119,    41,   144,    61,   110,    41,   144,
     110,    41,    62,    41,    62,    41,   144,   125,   115,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   155,    66,    41,    45,    89,    57,
      70,    58,    48,    71,    57,    70,    80,    62,   144,   118,
      62,   144,    66,   104,    66,   109,    79,    61,    62,    64,
      65,   126,   144,    60,    65,    64,   144,    59,    61,    71,
      41,    41,    74,    57,    70,    41,    41,    44,    55,    60,
      83,    61,    66,    62,   119,    66,    62,   144,   110,   144,
     110,    62,   126,   144,   115,   162,    70,    61,    61,    49,
      41,    41,    58,    61,    58,    61,    41,    44,    62,   144,
     144,   113,    59,    66,    60,   144,    87,    62,    62,    79,
      79,   144,   144,    63,    41,    62,    61,    66,   111,    59,
     113,    59,    58,    58,   113,   113,    81,    63,   113,   144,
     144,   122,   144,   113,    62,    90,    62,    62,    88,    82,
      66,    62,    60,    65,   112,     1,    30,    31,    32,    33,
      35,    36,    38,    39,    60,    91,    92,    95,    96,   123,
     127,   130,   134,   136,   160,    58,    58,    64,    88,    59,
     113,   144,   122,    58,    59,    60,    41,   144,   144,   144,
      48,    35,    58,   128,    45,    64,   121,    66,    60,    37,
      65,    59,    59,    74,    11,    12,    13,    14,    15,    66,
     129,    70,    45,   122,    59,    41,   144,    41,   132,   135,
      49,    66,    66,    66,    66,    66,   144,    84,    70,    60,
     120,   142,    67,    37,    90,    90,    59,    84,   122,   139,
      67,    41,    60,    60,    90,    59,    60,    59,   144,   143,
      34,    60,    90,    90,    67,   141,   140,    59,   131,    60,
      60,    67,   137,    59,   133,   130,   144,    59,    90,    90,
     141,    90,    60,    60,   138,    60,    59,    90,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    76,    77,    75,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    81,    80,    82,    80,    83,    84,    86,    85,
      87,    88,    88,    88,    89,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    93,    92,    92,    94,    94,
      95,    95,    95,    97,    96,    98,    96,    99,    96,   100,
      96,   101,    96,    96,    96,   102,   102,   103,   102,   102,
     102,   104,   102,   105,   105,   105,   105,   106,   106,   107,
     107,   108,   107,   107,   107,   109,   107,   110,   110,   111,
     110,   112,   110,   113,   114,   114,   115,   115,   117,   116,
     118,   116,   119,   119,   119,   120,   119,   121,   119,   119,
     119,   122,   122,   124,   123,   125,   125,   125,   126,   127,
     128,   129,   129,   129,   129,   129,   129,   130,   130,   131,
     130,   132,   133,   135,   134,   137,   136,   138,   136,   139,
     136,   140,   136,   141,   142,   143,   145,   144,   146,   144,
     147,   144,   148,   144,   149,   144,   144,   144,   144,   150,
     144,   151,   144,   152,   144,   153,   144,   154,   144,   155,
     144,   156,   144,   157,   144,   144,   144,   158,   158,   158,
     158,   158,   158,   158,   159,   160,   161,   160,   160,   162,
     160,   163
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     5,     9,     5,     9,     5,     7,     7,     2,     0,
       2,     0,     0,    13,     0,    14,     1,     0,     0,    13,
       0,     0,     2,     3,     3,     5,     3,     5,     0,     5,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     0,     2,
       2,     1,     2,     0,     5,     0,     5,     0,     4,     0,
       4,     0,     4,     4,     2,     1,     3,     0,     3,     3,
       5,     0,     5,     1,     3,     3,     5,     2,     4,     1,
       3,     0,     3,     3,     5,     0,     5,     3,     2,     0,
       7,     0,     9,     0,     7,     9,     1,     3,     0,     3,
       0,     5,     4,     6,     4,     0,    13,     0,    11,     8,
       4,     1,     3,     0,     5,     0,     2,     3,     1,     4,
       0,     1,     2,     2,     2,     2,     2,     6,    11,     0,
       9,     0,     0,     0,     6,     0,    12,     0,    15,     0,
       9,     0,    11,     0,     0,     0,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     4,     3,     2,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       5,     0,     4,     0,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     0,     5,     4,     0,
       9,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 12:
#line 114 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1869 "parser.tab.c"
    break;

  case 16:
#line 121 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1875 "parser.tab.c"
    break;

  case 18:
#line 125 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1881 "parser.tab.c"
    break;

  case 19:
#line 126 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1887 "parser.tab.c"
    break;

  case 20:
#line 127 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1893 "parser.tab.c"
    break;

  case 21:
#line 128 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1899 "parser.tab.c"
    break;

  case 23:
#line 130 "parser.y"
               {expr_type =VOID_TYPE;}
#line 1905 "parser.tab.c"
    break;

  case 25:
#line 133 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1911 "parser.tab.c"
    break;

  case 26:
#line 137 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1917 "parser.tab.c"
    break;

  case 27:
#line 137 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1923 "parser.tab.c"
    break;

  case 28:
#line 137 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1929 "parser.tab.c"
    break;

  case 31:
#line 141 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1938 "parser.tab.c"
    break;

  case 32:
#line 145 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1946 "parser.tab.c"
    break;

  case 33:
#line 148 "parser.y"
                                                  {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    } 
                                                    if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);
                                                    printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 1959 "parser.tab.c"
    break;

  case 34:
#line 156 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }
                                                    if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,yylineno);
                                                    printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 1972 "parser.tab.c"
    break;

  case 35:
#line 164 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1978 "parser.tab.c"
    break;

  case 36:
#line 165 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 1986 "parser.tab.c"
    break;

  case 37:
#line 168 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 1994 "parser.tab.c"
    break;

  case 39:
#line 173 "parser.y"
                        {(yyval.b)= false;}
#line 2000 "parser.tab.c"
    break;

  case 40:
#line 174 "parser.y"
                {(yyval.b) = true;}
#line 2006 "parser.tab.c"
    break;

  case 42:
#line 177 "parser.y"
                                       {pushscope();}
#line 2012 "parser.tab.c"
    break;

  case 43:
#line 177 "parser.y"
                                                                                                          {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;
                                                                                                    }
#line 2027 "parser.tab.c"
    break;

  case 44:
#line 187 "parser.y"
                                                   {pushscope();}
#line 2033 "parser.tab.c"
    break;

  case 45:
#line 187 "parser.y"
                                                                                                                     {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;
                                                                                                    }
#line 2048 "parser.tab.c"
    break;

  case 46:
#line 200 "parser.y"
                           {is_static_method = true;}
#line 2054 "parser.tab.c"
    break;

  case 47:
#line 204 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2065 "parser.tab.c"
    break;

  case 48:
#line 212 "parser.y"
                                      {pushscope();}
#line 2071 "parser.tab.c"
    break;

  case 49:
#line 212 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2085 "parser.tab.c"
    break;

  case 50:
#line 222 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2094 "parser.tab.c"
    break;

  case 54:
#line 231 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2100 "parser.tab.c"
    break;

  case 55:
#line 232 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2106 "parser.tab.c"
    break;

  case 56:
#line 233 "parser.y"
                                        {add_class_param((yyvsp[-2].m), (yyvsp[-1].s), false,(yyvsp[0].s));create_class_var((yyvsp[-2].m), (yyvsp[-1].s), (yyvsp[0].s), false,yylineno);free((yyvsp[-1].s));free((yyvsp[0].s));}
#line 2112 "parser.tab.c"
    break;

  case 57:
#line 234 "parser.y"
                                            {add_class_param((yyvsp[-4].m), (yyvsp[-3].s), true,(yyvsp[-2].s));create_class_var((yyvsp[-4].m), (yyvsp[-3].s), (yyvsp[-2].s), true,yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2118 "parser.tab.c"
    break;

  case 59:
#line 237 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2124 "parser.tab.c"
    break;

  case 60:
#line 238 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2130 "parser.tab.c"
    break;

  case 61:
#line 239 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2136 "parser.tab.c"
    break;

  case 62:
#line 240 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2142 "parser.tab.c"
    break;

  case 63:
#line 241 "parser.y"
                        {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2148 "parser.tab.c"
    break;

  case 64:
#line 242 "parser.y"
                    {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2154 "parser.tab.c"
    break;

  case 66:
#line 244 "parser.y"
                      {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2160 "parser.tab.c"
    break;

  case 67:
#line 245 "parser.y"
                         {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2166 "parser.tab.c"
    break;

  case 68:
#line 246 "parser.y"
                       {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2172 "parser.tab.c"
    break;

  case 70:
#line 250 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2178 "parser.tab.c"
    break;

  case 73:
#line 253 "parser.y"
            {printcode("break;");}
#line 2184 "parser.tab.c"
    break;

  case 74:
#line 254 "parser.y"
                {printcode("continue;");}
#line 2190 "parser.tab.c"
    break;

  case 75:
#line 257 "parser.y"
                       {printcode("/*");}
#line 2196 "parser.tab.c"
    break;

  case 76:
#line 257 "parser.y"
                                                                 {printcode("*/");}
#line 2202 "parser.tab.c"
    break;

  case 77:
#line 258 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2208 "parser.tab.c"
    break;

  case 79:
#line 261 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2214 "parser.tab.c"
    break;

  case 80:
#line 263 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2226 "parser.tab.c"
    break;

  case 81:
#line 270 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2238 "parser.tab.c"
    break;

  case 82:
#line 277 "parser.y"
                          {has_returned = true;}
#line 2244 "parser.tab.c"
    break;

  case 83:
#line 280 "parser.y"
                                    {temp_type = (yyvsp[0].t);}
#line 2250 "parser.tab.c"
    break;

  case 84:
#line 280 "parser.y"
                                                               {temp_type = VOID_TYPE;}
#line 2256 "parser.tab.c"
    break;

  case 85:
#line 281 "parser.y"
                              {temp_type = CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2262 "parser.tab.c"
    break;

  case 86:
#line 281 "parser.y"
                                                                                    {temp_type = VOID_TYPE;temp_class=NULL;free((yyvsp[-2].s));}
#line 2268 "parser.tab.c"
    break;

  case 87:
#line 282 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));arr_type=temp_type=CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2274 "parser.tab.c"
    break;

  case 88:
#line 282 "parser.y"
                                                                                                                        {printcode(" ;");free((yyvsp[-2].s));arr_type=temp_type=VOID_TYPE;temp_class= NULL;}
#line 2280 "parser.tab.c"
    break;

  case 89:
#line 283 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2286 "parser.tab.c"
    break;

  case 90:
#line 283 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2292 "parser.tab.c"
    break;

  case 91:
#line 284 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2298 "parser.tab.c"
    break;

  case 92:
#line 284 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2304 "parser.tab.c"
    break;

  case 93:
#line 285 "parser.y"
                              {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",(yyvsp[-2].s));
            }else if(expr_type == CLASS_TYPE){
                create_class_var(NONE_TYPE,expr_class,(yyvsp[-2].s),false,yylineno);
                printcode("%s %s = %s;",expr_class,(yyvsp[-2].s),(yyvsp[0].s));
                expr_class = NULL;expr_type = VOID_TYPE;
            }else{
                add_var(NONE_TYPE,expr_type,(yyvsp[-2].s),yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],(yyvsp[-2].s),(yyvsp[0].s));
            }
            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2320 "parser.tab.c"
    break;

  case 95:
#line 299 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2326 "parser.tab.c"
    break;

  case 96:
#line 300 "parser.y"
                          {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2337 "parser.tab.c"
    break;

  case 97:
#line 306 "parser.y"
                 {/*nothing dummymust be kept to maintain arraydecl*/}
#line 2343 "parser.tab.c"
    break;

  case 98:
#line 306 "parser.y"
                                                                                 {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2349 "parser.tab.c"
    break;

  case 99:
#line 307 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2355 "parser.tab.c"
    break;

  case 100:
#line 308 "parser.y"
                                           {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2366 "parser.tab.c"
    break;

  case 101:
#line 314 "parser.y"
                                  {printcode(", ");}
#line 2372 "parser.tab.c"
    break;

  case 102:
#line 314 "parser.y"
                                                               {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2378 "parser.tab.c"
    break;

  case 103:
#line 320 "parser.y"
                     {add_var((yyvsp[(-1) - (1)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2384 "parser.tab.c"
    break;

  case 104:
#line 321 "parser.y"
                         {add_array((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2390 "parser.tab.c"
    break;

  case 105:
#line 322 "parser.y"
                              {add_var((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2396 "parser.tab.c"
    break;

  case 106:
#line 323 "parser.y"
                                      {add_array((yyvsp[(-1) - (5)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2402 "parser.tab.c"
    break;

  case 107:
#line 326 "parser.y"
                                     {create_class_var((yyvsp[(-2) - (2)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2408 "parser.tab.c"
    break;

  case 108:
#line 327 "parser.y"
                                            {create_class_var((yyvsp[(-2) - (4)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2414 "parser.tab.c"
    break;

  case 109:
#line 330 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2422 "parser.tab.c"
    break;

  case 110:
#line 333 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2431 "parser.tab.c"
    break;

  case 111:
#line 337 "parser.y"
                {/*nothing dummy*/}
#line 2437 "parser.tab.c"
    break;

  case 112:
#line 337 "parser.y"
                                              {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2443 "parser.tab.c"
    break;

  case 113:
#line 338 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2451 "parser.tab.c"
    break;

  case 114:
#line 341 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2461 "parser.tab.c"
    break;

  case 115:
#line 346 "parser.y"
                             {printcode(", ");}
#line 2467 "parser.tab.c"
    break;

  case 116:
#line 346 "parser.y"
                                                          {add_array((yyvsp[(-2) - (5)].m),  (yyvsp[(-1) - (5)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2473 "parser.tab.c"
    break;

  case 117:
#line 349 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2484 "parser.tab.c"
    break;

  case 118:
#line 355 "parser.y"
                      {yyerror("Array size missing");}
#line 2490 "parser.tab.c"
    break;

  case 119:
#line 356 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2496 "parser.tab.c"
    break;

  case 120:
#line 356 "parser.y"
                                                                         {printcode(" }");}
#line 2502 "parser.tab.c"
    break;

  case 121:
#line 357 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2508 "parser.tab.c"
    break;

  case 122:
#line 357 "parser.y"
                                                                                                          {printcode(" }");}
#line 2514 "parser.tab.c"
    break;

  case 123:
#line 361 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2520 "parser.tab.c"
    break;

  case 124:
#line 363 "parser.y"
                                                        {if(arr_type == VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-6].s));
                                                            }else if(arr_type == CLASS_TYPE){
                                                                create_class_var(NONE_TYPE,temp_class,(yyvsp[-6].s),true,yylineno);
                                                                printcode("%s %s[] = { %s };",temp_class,(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-6].s), yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2536 "parser.tab.c"
    break;

  case 125:
#line 374 "parser.y"
                                                                    {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-8].s));
                                                            }else if(arr_type == CLASS_TYPE){
                                                                create_class_var(NONE_TYPE,temp_class,(yyvsp[-8].s),true,yylineno);
                                                                printcode("%s %s[%s] = { %s };",temp_class,(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-8].s), yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }expr_type = VOID_TYPE;
                                                            free((yyvsp[-8].s));free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2551 "parser.tab.c"
    break;

  case 126:
#line 385 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
#line 2557 "parser.tab.c"
    break;

  case 127:
#line 386 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2571 "parser.tab.c"
    break;

  case 128:
#line 397 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2577 "parser.tab.c"
    break;

  case 129:
#line 397 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2583 "parser.tab.c"
    break;

  case 130:
#line 398 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2589 "parser.tab.c"
    break;

  case 131:
#line 398 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2595 "parser.tab.c"
    break;

  case 132:
#line 401 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2601 "parser.tab.c"
    break;

  case 133:
#line 402 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2608 "parser.tab.c"
    break;

  case 134:
#line 404 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2615 "parser.tab.c"
    break;

  case 135:
#line 406 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2621 "parser.tab.c"
    break;

  case 136:
#line 406 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2629 "parser.tab.c"
    break;

  case 137:
#line 409 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2635 "parser.tab.c"
    break;

  case 138:
#line 409 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2643 "parser.tab.c"
    break;

  case 139:
#line 412 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2649 "parser.tab.c"
    break;

  case 140:
#line 414 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2655 "parser.tab.c"
    break;

  case 141:
#line 418 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}

                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2666 "parser.tab.c"
    break;

  case 142:
#line 424 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2675 "parser.tab.c"
    break;

  case 143:
#line 429 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2681 "parser.tab.c"
    break;

  case 144:
#line 429 "parser.y"
                                                                                                    {if(!is_in_fn){
                                        yyerror("Function call is not allowed outside a function.");
                                        (yyval.s) = strdup("");
                                    }else if(find_action((yyvsp[-4].s))){
                                        perform_action((yyvsp[-4].s));
                                        (yyval.s) = strdup("");
                                    }else{
                                        Function *fn = find_fn((yyvsp[-4].s));
                                        if(fn == NULL){
                                            (yyval.s) = get_fncall_str((yyvsp[-4].s));
                                            ll_clear(arglist);
                                        }else{
                                            verify_call((yyvsp[-4].s),fn,yylineno);
                                            (yyval.s) = get_fncall_str((yyvsp[-4].s));
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
                                                //? print error or allow?
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
                                    free((yyvsp[-4].s));}
#line 2726 "parser.tab.c"
    break;

  case 148:
#line 476 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2737 "parser.tab.c"
    break;

  case 149:
#line 484 "parser.y"
                                               {
                                    if(temp_type == CLASS_TYPE){
                                        if(expr_type != CLASS_TYPE ){
                                            yyerror("cannot assign %s to class type variable",type_arr[expr_type]);
                                        }else if(strcmp(expr_class,temp_class) != 0){
                                            yyerror("cannot assign class %s value to class %s variable",expr_class,temp_class);
                                        }else if(strcmp((yyvsp[-1].s),"=") != 0){
                                            yyerror("cannot perform compund operations on class type variables");
                                        }else if(!is_assignable_class(temp_class)){
                                            yyerror("cannot perform assignment as class or class members contains constant members");
                                        }
                                    }else if(verify_types(temp_type,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[temp_type],type_arr[expr_type]);
                                    }else if(temp_type == COMPLEX_TYPE&& strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }
                                    printcode("%s %s %s;",(yyvsp[-3].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    // No need to free $2, its const char *
                                    free((yyvsp[-3].s));free((yyvsp[0].s));
                                    expr_type = VOID_TYPE;expr_class = NULL;
                                    temp_class = NULL; temp_type = VOID_TYPE;
                                    }
#line 2764 "parser.tab.c"
    break;

  case 150:
#line 509 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 2773 "parser.tab.c"
    break;

  case 151:
#line 515 "parser.y"
                {(yyval.s) = "=";}
#line 2779 "parser.tab.c"
    break;

  case 152:
#line 516 "parser.y"
              {(yyval.s) = "+=";}
#line 2785 "parser.tab.c"
    break;

  case 153:
#line 517 "parser.y"
              {(yyval.s) = "-=";}
#line 2791 "parser.tab.c"
    break;

  case 154:
#line 518 "parser.y"
              {(yyval.s) = "*=";}
#line 2797 "parser.tab.c"
    break;

  case 155:
#line 519 "parser.y"
              {(yyval.s) = "/=";}
#line 2803 "parser.tab.c"
    break;

  case 156:
#line 520 "parser.y"
              {(yyval.s) = "%=";}
#line 2809 "parser.tab.c"
    break;

  case 157:
#line 523 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2815 "parser.tab.c"
    break;

  case 158:
#line 524 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2821 "parser.tab.c"
    break;

  case 159:
#line 525 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2827 "parser.tab.c"
    break;

  case 161:
#line 528 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2833 "parser.tab.c"
    break;

  case 162:
#line 532 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2839 "parser.tab.c"
    break;

  case 163:
#line 536 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2845 "parser.tab.c"
    break;

  case 164:
#line 536 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2851 "parser.tab.c"
    break;

  case 165:
#line 539 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2857 "parser.tab.c"
    break;

  case 166:
#line 539 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2863 "parser.tab.c"
    break;

  case 167:
#line 540 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2869 "parser.tab.c"
    break;

  case 168:
#line 540 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2875 "parser.tab.c"
    break;

  case 169:
#line 541 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2881 "parser.tab.c"
    break;

  case 170:
#line 541 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2887 "parser.tab.c"
    break;

  case 171:
#line 542 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2893 "parser.tab.c"
    break;

  case 172:
#line 542 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2899 "parser.tab.c"
    break;

  case 173:
#line 545 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2905 "parser.tab.c"
    break;

  case 174:
#line 549 "parser.y"
                               {Variable *v = lookup_var((yyvsp[0].s));
                                    pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",(yyvsp[0].s));
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        if(v->is_class){
                                            expr_class = v->t.class;
                                            print_array_loop((yyvsp[(-2) - (0)].s),(yyvsp[0].s),CLASS_TYPE);
                                            create_class_var(NONE_TYPE, expr_class, (yyvsp[(-2) - (0)].s), false,yylineno);
                                            expr_class = NULL;
                                        }else{
                                            add_var(NONE_TYPE,v->t.t,(yyvsp[(-2) - (0)].s),yylineno);
                                            print_array_loop((yyvsp[(-2) - (0)].s),(yyvsp[0].s),v->t.t);
                                        }
                                        
                                    }
                                }
#line 2929 "parser.tab.c"
    break;

  case 175:
#line 571 "parser.y"
                             {Variable *v = lookup_var((yyvsp[0].s));
                                        pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",(yyvsp[0].s));
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,INT_TYPE,(yyvsp[(-4) - (0)].s),yylineno);
                                        if(v->is_class){
                                            expr_class = v->t.class;
                                            create_class_var(NONE_TYPE, expr_class, (yyvsp[(-2) - (0)].s), false,yylineno);
                                            print_enumeration_loop((yyvsp[(-4) - (0)].s),(yyvsp[(-2) - (0)].s),(yyvsp[0].s),CLASS_TYPE);
                                            expr_class = NULL;
                                        }else{
                                            add_var(NONE_TYPE,v->t.t,(yyvsp[(-2) - (0)].s),yylineno);
                                            print_enumeration_loop((yyvsp[(-4) - (0)].s),(yyvsp[(-2) - (0)].s),(yyvsp[0].s),v->t.t);
                                        }
                                        
                                    }}
#line 2953 "parser.tab.c"
    break;

  case 176:
#line 592 "parser.y"
               {push_expr_type();}
#line 2959 "parser.tab.c"
    break;

  case 177:
#line 592 "parser.y"
                                         { (yyval.s)=join((yyvsp[-3].s),"+",(yyvsp[0].s)); free((yyvsp[-3].s));free((yyvsp[0].s)); 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            is_composite_val =false;}
#line 2968 "parser.tab.c"
    break;

  case 178:
#line 596 "parser.y"
               {push_expr_type();}
#line 2974 "parser.tab.c"
    break;

  case 179:
#line 596 "parser.y"
                                         {(yyval.s)=join((yyvsp[-3].s),"-",(yyvsp[0].s)); free((yyvsp[-3].s));free((yyvsp[0].s)); 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);} is_composite_val =false;}
#line 2982 "parser.tab.c"
    break;

  case 180:
#line 599 "parser.y"
               {push_expr_type();}
#line 2988 "parser.tab.c"
    break;

  case 181:
#line 599 "parser.y"
                                         {(yyval.s)=join((yyvsp[-3].s),"*",(yyvsp[0].s)); free((yyvsp[-3].s));free((yyvsp[0].s)); 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);} is_composite_val =false;}
#line 2996 "parser.tab.c"
    break;

  case 182:
#line 602 "parser.y"
               {push_expr_type();}
#line 3002 "parser.tab.c"
    break;

  case 183:
#line 602 "parser.y"
                                         {(yyval.s)=join((yyvsp[-3].s),"/",(yyvsp[0].s)); free((yyvsp[-3].s));free((yyvsp[0].s)); 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);} is_composite_val =false;}
#line 3010 "parser.tab.c"
    break;

  case 184:
#line 605 "parser.y"
               {push_expr_type();}
#line 3016 "parser.tab.c"
    break;

  case 185:
#line 605 "parser.y"
                                         {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use mod on %s type",type_arr[expr_type]);} 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)=join((yyvsp[-3].s),"%",(yyvsp[0].s)); free((yyvsp[-3].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 3025 "parser.tab.c"
    break;

  case 186:
#line 609 "parser.y"
                                         {
                                if(expr_type == CLASS_TYPE){yyerror("cannot typecast class values");}
                                void * v = calloc(1,3+strlen(type_arr[(yyvsp[-2].t)])); // 2 for '()' one for end-of-string 0
                                sprintf(v,"(%s) ",type_arr[(yyvsp[-2].t)]);
                                char * t = join("(",(yyvsp[0].s),")");
                                (yyval.s) = join(v,"",t);
                                is_composite_val =false;
                                free(v);
                                free(t);
                                free((yyvsp[0].s));
                                expr_type = (yyvsp[-2].t);
                            }
#line 3042 "parser.tab.c"
    break;

  case 187:
#line 621 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 3048 "parser.tab.c"
    break;

  case 188:
#line 622 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s));if(expr_type == CLASS_TYPE){yyerror("Cannot use negetive on class type");}  
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}free((yyvsp[0].s)); is_composite_val =false;}
#line 3056 "parser.tab.c"
    break;

  case 189:
#line 625 "parser.y"
              {push_expr_type();}
#line 3062 "parser.tab.c"
    break;

  case 190:
#line 625 "parser.y"
                                          {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);} 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s),"<",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3071 "parser.tab.c"
    break;

  case 191:
#line 629 "parser.y"
              {push_expr_type();}
#line 3077 "parser.tab.c"
    break;

  case 192:
#line 629 "parser.y"
                                          {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use > with %s type",type_arr[expr_type]);} 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s),">",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3086 "parser.tab.c"
    break;

  case 193:
#line 633 "parser.y"
              {push_expr_type();}
#line 3092 "parser.tab.c"
    break;

  case 194:
#line 633 "parser.y"
                                                {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use <= with %s type",type_arr[expr_type]);} 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s),"<=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3101 "parser.tab.c"
    break;

  case 195:
#line 637 "parser.y"
              {push_expr_type();}
#line 3107 "parser.tab.c"
    break;

  case 196:
#line 637 "parser.y"
                                                 {if(expr_type == COMPLEX_TYPE|| expr_type == CLASS_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);} 
                                            type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s),">=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3116 "parser.tab.c"
    break;

  case 197:
#line 641 "parser.y"
              {push_expr_type();}
#line 3122 "parser.tab.c"
    break;

  case 198:
#line 641 "parser.y"
                                                            { type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s),"==",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3130 "parser.tab.c"
    break;

  case 199:
#line 644 "parser.y"
                  {push_expr_type();}
#line 3136 "parser.tab.c"
    break;

  case 200:
#line 644 "parser.y"
                                                            { type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-4].s),"!=",(yyvsp[0].s));free((yyvsp[-4].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3144 "parser.tab.c"
    break;

  case 201:
#line 647 "parser.y"
              {push_expr_type();}
#line 3150 "parser.tab.c"
    break;

  case 202:
#line 647 "parser.y"
                                         { type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s)," && ",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3158 "parser.tab.c"
    break;

  case 203:
#line 650 "parser.y"
              {push_expr_type();}
#line 3164 "parser.tab.c"
    break;

  case 204:
#line 650 "parser.y"
                                          { type t = pop_expr_type();
                                            if(verify_types(t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[t],type_arr[expr_type]);}
                                            (yyval.s)= join((yyvsp[-3].s)," || ",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3172 "parser.tab.c"
    break;

  case 205:
#line 653 "parser.y"
                 { type _t = pop_expr_type();
                    if(verify_types(_t,expr_type)){yyerror("cannot combine %s type with %s type",type_arr[_t],type_arr[expr_type]);}char * t =join("(",(yyvsp[0].s),")");
                    (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3180 "parser.tab.c"
    break;

  case 207:
#line 659 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 3190 "parser.tab.c"
    break;

  case 208:
#line 664 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 3200 "parser.tab.c"
    break;

  case 209:
#line 669 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 3211 "parser.tab.c"
    break;

  case 210:
#line 675 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 3221 "parser.tab.c"
    break;

  case 211:
#line 680 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 3227 "parser.tab.c"
    break;

  case 214:
#line 685 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3239 "parser.tab.c"
    break;

  case 215:
#line 694 "parser.y"
                     { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
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
#line 3266 "parser.tab.c"
    break;

  case 216:
#line 716 "parser.y"
                     {push_expr_and_args();}
#line 3272 "parser.tab.c"
    break;

  case 217:
#line 716 "parser.y"
                                                      { Variable *v = lookup_var((yyvsp[-4].s));
                                                        if(v == NULL){
                                                            yyerror("Undefined variable %s",(yyval.s));
                                                        }else if(!v->is_arr){
                                                            yyerror("Subscripted object must be of array");
                                                        }else if(expr_type != INT_TYPE){
                                                            yyerror("Subscript must be of int type got %s type",type_arr[expr_type]);
                                                        }
                                                        char *t = join((yyvsp[-4].s),"[",(yyvsp[-1].s));(yyval.s) = join(t,"]","");is_composite_val = true;pop_expr_and_args();free(t);
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
                                                        }free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3304 "parser.tab.c"
    break;

  case 218:
#line 743 "parser.y"
                                             { attr* a = NULL;
                                        if(expr_type == CLASS_TYPE)a = find_attr(expr_class,(yyvsp[0].s));
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[0].s),expr_class);
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
                                        (yyval.s) = join((yyvsp[-3].s),".",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));
                                    }
#line 3330 "parser.tab.c"
    break;

  case 219:
#line 764 "parser.y"
                                                 {push_expr_and_args();}
#line 3336 "parser.tab.c"
    break;

  case 220:
#line 764 "parser.y"
                                                                                                  { attr* a = NULL;
                                                                                                pop_expr_and_args();
                                                                                            if(expr_type == CLASS_TYPE)a = find_attr(expr_class,(yyvsp[-5].s));    
                                                                                            if(a== NULL){
                                                                                                yyerror("No attribute %s declared on class %s",(yyvsp[-8].s),(yyvsp[-5].s));
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
                                                                                            char * t = join((yyvsp[-8].s),".",(yyvsp[-5].s));
                                                                                            char *tt = join(t,"[",(yyvsp[-2].s));
                                                                                            (yyval.s) = join(tt,"]","");
                                                                                            free(t);free(tt);
                                                                                            free((yyvsp[-8].s));free((yyvsp[-5].s));free((yyvsp[-2].s));
                                                                                        }
#line 3369 "parser.tab.c"
    break;

  case 221:
#line 793 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3375 "parser.tab.c"
    break;


#line 3379 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 795 "parser.y"


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
