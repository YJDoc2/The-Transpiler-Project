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
    #include "classes.h"

    void preparse(); // as preparse is a macro from preparser.l must be given here
    extern char *type_arr[],*mod_arr[];
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


#line 101 "parser.tab.c"

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
    CLASS = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

    char *s;
    type t;
    modifier m;

#line 208 "parser.tab.c"

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
#define YYLAST   962

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  356

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


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
      60,    61,    13,    11,    62,    12,    64,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       9,    63,    10,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    94,    95,    96,   100,   101,   102,   105,   106,
     107,   108,   109,   110,   112,   113,   117,   117,   117,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     131,   134,   134,   144,   149,   150,   151,   153,   154,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     169,   170,   171,   172,   173,   174,   177,   177,   178,   180,
     181,   183,   190,   197,   200,   201,   201,   202,   202,   203,
     210,   214,   215,   218,   221,   226,   226,   227,   230,   235,
     235,   238,   244,   245,   245,   246,   246,   250,   252,   260,
     268,   269,   277,   277,   278,   278,   281,   282,   284,   286,
     286,   289,   289,   292,   294,   298,   303,   308,   308,   343,
     344,   345,   348,   356,   374,   393,   394,   395,   396,   397,
     398,   401,   402,   403,   403,   406,   410,   414,   414,   417,
     417,   418,   418,   419,   419,   420,   420,   423,   427,   441,
     454,   455,   456,   457,   458,   462,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   484,   486,   491,
     496,   502,   516,   521,   522,   523,   523,   552
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
  "COMMENTLINE", "CLASS", "';'", "'{'", "'}'", "'['", "']'", "'('", "')'",
  "','", "'='", "'.'", "$accept", "program", "type", "modifier",
  "topstmtlist", "topstmt", "rawlist", "classdef", "$@1", "$@2",
  "attrlist", "methodlist", "fndeclaration", "$@3", "fndecldummy",
  "paramlist", "param", "stmtlist", "stmt", "comment", "$@4",
  "commentlist", "returnstmt", "vardeclaration", "$@5", "$@6", "decllist",
  "varlist", "$@7", "$@8", "arraydecl", "$@9", "$@10", "arraysizedummy",
  "letarraydecl", "letarrvals", "chararrdecllist", "$@11", "$@12",
  "strdecl", "$@13", "$@14", "arrayvallist", "fncall", "$@15", "arglist",
  "arg", "assignstmt", "assgtype", "ifstmt", "$@16", "ifdummy",
  "elsedummy", "whilestmt", "$@17", "forstmt", "$@18", "$@19", "$@20",
  "$@21", "rangecheckdummy", "simplearraydummy", "iterarraydummy", "expr",
  "value", "$@22", "cmplxnum", YY_NULLPTR
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
     299,   300,   301,   302,   303,    59,   123,   125,    91,    93,
      40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF (-247)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-149)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -247,    55,   746,  -247,  -247,  -247,  -247,   -39,    67,    17,
      23,  -247,  -247,    48,   136,  -247,  -247,  -247,  -247,    73,
    -247,   148,   -50,  -247,    93,  -247,   100,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,   -18,
     128,   822,   881,  -247,    50,  -247,   151,   163,  -247,  -247,
    -247,   115,   881,   881,   -20,  -247,  -247,  -247,  -247,   131,
     802,  -247,   945,  -247,  -247,   945,  -247,  -247,  -247,  -247,
    -247,   143,   -30,   159,   194,   221,   221,  -247,  -247,   183,
     185,   219,   881,   881,   881,   881,   881,   881,   881,   881,
     881,   881,   881,   881,   240,   186,    16,   612,   203,   222,
     881,   206,   224,  -247,   881,  -247,   881,   881,  -247,   881,
     945,   611,   611,   184,   184,   184,   184,   260,   260,   253,
     253,   253,   881,   213,   237,    67,   148,  -247,   223,   148,
     236,    86,   247,  -247,   829,  -247,  -247,   945,   844,  -247,
     -29,   648,   225,     0,   945,   221,   245,   945,   238,    67,
    -247,   251,  -247,   254,  -247,   148,   255,    18,   241,     9,
     666,   203,   239,   680,   881,   206,  -247,  -247,   881,  -247,
     945,  -247,   881,  -247,   881,   148,   242,    81,    68,   258,
      92,  -247,   881,  -247,   866,   881,  -247,  -247,   248,   263,
     945,  -247,  -247,   945,    13,  -247,   244,  -247,   881,  -247,
      94,  -247,   246,   945,  -247,   704,   945,    33,  -247,   267,
    -247,   276,  -247,   945,  -247,   274,   279,   277,  -247,   881,
     881,   881,  -247,  -247,   278,   280,  -247,   283,   281,   723,
     945,    63,   945,  -247,   289,   284,  -247,  -247,   285,  -247,
    -247,   881,   881,   -40,  -247,  -247,   302,   881,   881,   881,
     297,   -14,    11,  -247,   292,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,   301,   945,    78,  -247,  -247,
    -247,   -35,   745,   945,   798,  -247,  -247,   304,   310,   311,
     312,   313,   881,  -247,   881,  -247,   881,   321,  -247,   888,
     337,  -247,  -247,   153,  -247,  -247,  -247,  -247,  -247,   945,
     945,    80,  -247,   233,   176,   264,  -247,  -247,  -247,   320,
    -247,   881,  -247,   316,   341,   330,   371,    71,    89,   328,
     881,  -247,   351,  -247,   881,  -247,  -247,   205,  -247,   332,
     945,   412,   322,  -247,   349,  -247,   375,  -247,   881,   358,
    -247,  -247,  -247,   945,  -247,   453,   494,  -247,   535,  -247,
    -247,   359,  -247,  -247,   576,  -247
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    66,    68,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,    80,     0,    69,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    77,    75,    19,     0,
       0,     0,     0,    41,     0,    26,     0,     0,    18,    25,
      81,    74,     0,     0,   171,   172,   173,   169,   170,     0,
       0,   174,    97,   167,   168,    79,    44,    67,    70,    29,
     102,    78,    83,    76,     0,   157,   166,   175,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,    82,     0,   119,     0,     0,   156,     0,
     162,   164,   165,   160,   161,   158,   159,   150,   151,   152,
     153,   154,     0,     0,     0,    12,     0,    45,     0,     0,
       0,     0,     0,    40,     0,   103,   104,    84,     0,    86,
      87,     0,     0,     0,   100,   155,     0,   163,     0,    12,
      46,     0,    30,     0,    24,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,   176,   118,     0,   120,
     122,    98,     0,   177,     0,     0,    47,     0,     0,     0,
       0,    31,     0,    28,     0,     0,    97,   105,     0,    91,
      88,    90,   121,   101,     0,    43,     0,    32,     0,    35,
       0,    36,     0,    97,   114,     0,   108,   106,    93,     0,
      99,     0,    48,    97,    37,     0,     0,     0,    97,     0,
       0,     0,    97,    49,     0,     0,    38,     0,     0,     0,
     107,     0,   115,    95,     0,     0,    39,    33,     0,    97,
      94,     0,     0,     0,    64,    65,     0,     0,    72,     0,
       0,    12,     0,    42,    55,    56,    62,    60,    61,    63,
      57,    58,    59,    34,   111,   113,   116,     0,    51,    53,
      52,     0,     0,    71,     0,    24,    73,     0,     0,     0,
       0,     0,     0,   125,     0,    54,     0,     0,    96,     0,
       0,   135,   137,     0,   126,   127,   128,   129,   130,    97,
     123,     0,   109,   171,     0,     0,    49,    49,    50,     0,
     112,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,   149,   131,   138,     0,   110,    49,   147,   145,   133,
     124,     0,     0,   139,     0,   136,     0,   144,     0,     0,
      49,    49,   134,   147,    49,     0,     0,   141,     0,   146,
     132,     0,   140,    49,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,    -7,    -4,  -247,  -247,  -149,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,   291,  -246,  -247,   415,
    -247,  -247,  -247,   416,  -247,  -247,  -247,  -247,  -247,  -247,
     256,  -247,  -247,  -183,  -247,   249,  -247,  -247,  -247,   259,
    -247,  -247,  -232,  -216,  -247,  -247,   257,  -247,   102,    90,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
      84,  -247,  -247,   -41,  -247,  -247,  -247
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    37,    14,     2,    15,    39,    16,    69,   133,
      97,   158,    17,    66,   211,    96,   127,   234,   254,   255,
      25,    44,   256,   257,    47,    46,    51,    73,   101,   165,
     139,   221,   242,    95,    23,   143,    71,    98,   161,   135,
     311,   286,   231,    61,   105,   142,   169,   259,   284,   260,
     336,   306,   341,   261,   307,   262,   339,   351,   319,   334,
     333,   312,   328,   232,    63,   104,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,    65,   289,   207,    21,   178,     5,     6,    41,    20,
     267,    75,    76,    42,    40,   268,   269,   270,   258,    81,
     217,   276,   277,   278,   279,   280,   281,   290,   -85,   -89,
     224,    48,    49,   100,   164,   228,     5,     6,    77,   233,
      78,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    80,   301,     3,   265,   171,    22,   137,
     315,   316,   172,   141,    24,   144,   145,   184,   146,   282,
     210,    78,   185,   181,   283,   172,   182,   124,   125,   318,
     331,   147,   277,   278,   279,   280,   281,     5,     6,    26,
     132,   219,   126,   160,   345,   346,   220,   163,   348,   258,
     258,   170,    67,    68,    27,    28,   155,   354,    29,    30,
      31,    32,    33,    34,    35,   258,   309,   199,    49,   151,
     240,   126,   153,   190,   156,   241,   293,   170,    38,   258,
     258,   193,   258,   144,   283,   288,   197,   310,   258,   198,
     241,   203,   241,   205,   206,   175,   325,   201,   179,   214,
     202,   241,   215,    43,    27,    28,    45,   213,    29,    30,
      31,    32,    33,    34,    35,    36,    27,    28,   195,    50,
      29,    30,    31,    32,    33,    34,    35,    74,   229,   230,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    70,    94,    79,    89,    90,    91,    92,    93,
     266,    94,   308,    49,    72,    99,   272,   273,   274,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   102,    94,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   103,    94,    52,  -149,   106,
     313,   299,    53,   300,   122,   123,   107,    21,   304,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   134,    94,   136,   138,   140,    54,    55,    56,   332,
      94,    57,    58,    91,    92,    93,   148,    94,   152,   327,
     108,   109,   149,   330,   154,    60,   167,   168,   157,  -148,
     243,    77,   176,    78,   174,   177,   180,   343,   183,   200,
     196,   314,   188,   212,   208,   216,   173,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   244,
     245,   246,   247,   222,   248,   249,   209,   250,   251,     9,
     252,   243,   223,   225,   226,   236,   227,   235,   237,   263,
      11,   264,    12,   271,   238,   275,   253,   285,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     244,   245,   246,   247,   287,   248,   249,   294,   250,   251,
       9,   252,   243,   295,   296,   297,   298,   302,   305,   317,
     320,    11,   321,    12,   326,   329,   338,   322,   335,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   244,   245,   246,   247,   340,   248,   249,   247,   250,
     251,     9,   252,   243,   344,   353,   150,    18,    19,   324,
     187,   191,    11,   194,    12,   192,   342,   347,   323,     0,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   244,   245,   246,   247,     0,   248,   249,     0,
     250,   251,     9,   252,   243,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,   337,
       0,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   244,   245,   246,   247,     0,   248,   249,
       0,   250,   251,     9,   252,   243,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
     349,     0,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   244,   245,   246,   247,     0,   248,
     249,     0,   250,   251,     9,   252,   243,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,   350,     0,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   244,   245,   246,   247,     0,
     248,   249,     0,   250,   251,     9,   252,   243,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,   352,     0,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   244,   245,   246,   247,
       0,   248,   249,   128,   250,   251,     9,   252,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    11,    94,    12,
      27,    28,   129,   355,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,    94,     0,     0,     0,   -27,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,     0,    94,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
       0,    94,     0,     0,     0,   186,     0,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,   189,
      94,     0,     0,     0,     0,     0,    -2,     4,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     0,    94,   218,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,     0,     0,     0,     0,
       0,     0,   239,     0,     7,     8,     9,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,    11,     0,    12,
      13,   291,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    52,    94,     0,     0,     0,    53,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    52,     0,     0,     0,     0,    53,
       0,    52,     0,    54,    55,    56,    53,     0,    57,    58,
       0,     0,     0,     0,   292,     0,    52,     0,     0,     0,
       0,    53,    60,    54,    55,    56,     0,     0,    57,    58,
      54,    55,    56,     0,     0,    57,    58,     0,    52,     0,
       0,    59,    60,    53,     0,    54,    55,    56,   159,    60,
      57,    58,     0,    52,     0,     0,     0,     0,    53,     0,
      52,     0,     0,   162,    60,    53,     0,    54,    55,    56,
       0,     0,    57,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    55,    56,   204,    60,    57,    58,   303,
      55,    56,     0,     0,    57,    58,     0,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,    60,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     0,    94
};

static const yytype_int16 yycheck[] =
{
      41,    42,    37,   186,     8,   154,    20,    21,    58,    48,
     242,    52,    53,    63,    21,    55,    56,    57,   234,    60,
     203,    35,    11,    12,    13,    14,    15,    62,    58,    58,
     213,    49,    50,    63,    63,   218,    20,    21,    58,   222,
      60,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    60,   286,     0,   239,    57,    41,   100,
     306,   307,    62,   104,    41,   106,   107,    58,   109,    58,
      57,    60,    63,    55,    63,    62,    58,    61,    62,   311,
     326,   122,    11,    12,    13,    14,    15,    20,    21,    41,
      97,    58,    96,   134,   340,   341,    63,   138,   344,   315,
     316,   142,    52,    53,    18,    19,    20,   353,    22,    23,
      24,    25,    26,    27,    28,   331,   299,    49,    50,   126,
      57,   125,   129,   164,   131,    62,   275,   168,    55,   345,
     346,   172,   348,   174,    63,    57,    55,    57,   354,    58,
      62,   182,    62,   184,   185,   149,    57,    55,   155,    55,
      58,    62,    58,    60,    18,    19,    56,   198,    22,    23,
      24,    25,    26,    27,    28,    29,    18,    19,   175,    41,
      22,    23,    24,    25,    26,    27,    28,    62,   219,   220,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    41,    17,    63,    11,    12,    13,    14,    15,
     241,    17,    49,    50,    41,    62,   247,   248,   249,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    62,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    41,    17,    12,    17,    56,
      64,   282,    17,   284,     4,    59,    61,   251,   289,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    58,    17,    41,    58,    41,    41,    42,    43,    64,
      17,    46,    47,    13,    14,    15,    63,    17,    55,   320,
      61,    62,    45,   324,    48,    60,    61,    62,    41,    56,
       1,    58,    41,    60,    56,    41,    41,   338,    57,    41,
      58,    37,    63,    59,    56,    59,    61,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    56,    35,    36,    63,    38,    39,    40,
      41,     1,    56,    59,    55,    55,    59,    59,    55,    55,
      51,    56,    53,    41,    63,    48,    57,    55,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    63,    35,    36,    63,    38,    39,
      40,    41,     1,    63,    63,    63,    63,    56,    41,    59,
      64,    51,    41,    53,    56,    34,    64,    57,    56,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    56,    35,    36,    33,    38,
      39,    40,    41,     1,    56,    56,   125,     2,     2,   317,
     161,   165,    51,   174,    53,   168,   336,   343,    57,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      57,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    57,    -1,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,     1,    38,    39,    40,    41,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    51,    17,    53,
      18,    19,    20,    57,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    39,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    57,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    -1,    59,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    59,
      17,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    59,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    38,    39,    40,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      54,    56,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    12,    17,    -1,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    17,
      -1,    12,    -1,    41,    42,    43,    17,    -1,    46,    47,
      -1,    -1,    -1,    -1,    56,    -1,    12,    -1,    -1,    -1,
      -1,    17,    60,    41,    42,    43,    -1,    -1,    46,    47,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    12,    -1,
      -1,    59,    60,    17,    -1,    41,    42,    43,    59,    60,
      46,    47,    -1,    12,    -1,    -1,    -1,    -1,    17,    -1,
      12,    -1,    -1,    59,    60,    17,    -1,    41,    42,    43,
      -1,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    59,    60,    46,    47,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    -1,    -1,    60,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    69,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    68,    70,    72,    77,    84,    88,
      48,    68,    41,    99,    41,    85,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    67,    55,    71,
      67,    58,    63,    60,    86,    56,    90,    89,    49,    50,
      41,    91,    12,    17,    41,    42,    43,    46,    47,    59,
      60,   108,   128,   129,   131,   128,    78,    52,    53,    73,
      41,   101,    41,    92,    62,   128,   128,    58,    60,    63,
      67,   128,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    17,    98,    80,    75,   102,    62,
      63,    93,    62,    41,   130,   109,    56,    61,    61,    62,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,     4,    59,    61,    62,    68,    81,     1,    20,
      38,    39,    67,    74,    58,   104,    41,   128,    58,    95,
      41,   128,   110,   100,   128,   128,   128,   128,    63,    45,
      81,    67,    55,    67,    48,    20,    67,    41,    76,    59,
     128,   103,    59,   128,    63,    94,    59,    61,    62,   111,
     128,    57,    62,    61,    56,    68,    41,    41,    71,    67,
      41,    55,    58,    57,    58,    63,    59,   104,    63,    59,
     128,    95,   111,   128,   100,    67,    58,    55,    58,    49,
      41,    55,    58,   128,    59,   128,   128,    98,    56,    63,
      57,    79,    59,   128,    55,    58,    59,    98,    59,    58,
      63,    96,    56,    56,    98,    59,    55,    59,    98,   128,
     128,   107,   128,    98,    82,    59,    55,    55,    63,    59,
      57,    62,    97,     1,    30,    31,    32,    33,    35,    36,
      38,    39,    41,    57,    83,    84,    87,    88,   108,   112,
     114,   118,   120,    55,    56,    98,   128,   107,    55,    56,
      57,    41,   128,   128,   128,    48,    35,    11,    12,    13,
      14,    15,    58,    63,   113,    55,   106,    63,    57,    37,
      62,    56,    56,    71,    63,    63,    63,    63,    63,   128,
     128,   107,    56,    41,   128,    41,   116,   119,    49,    98,
      57,   105,   126,    64,    37,    82,    82,    59,   107,   123,
      64,    41,    57,    57,   113,    57,    56,   128,   127,    34,
     128,    82,    64,   125,   124,    56,   115,    57,    64,   121,
      56,   117,   114,   128,    56,    82,    82,   125,    82,    57,
      57,   122,    57,    56,    82,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    71,    71,    73,    74,    72,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      76,    78,    77,    79,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      83,    83,    83,    83,    83,    83,    85,    84,    84,    86,
      86,    87,    87,    87,    88,    89,    88,    90,    88,    88,
      88,    91,    91,    92,    92,    93,    92,    92,    92,    94,
      92,    95,    95,    96,    95,    97,    95,    98,    99,    99,
     100,   100,   102,   101,   103,   101,   104,   104,   104,   105,
     104,   106,   104,   104,   104,   107,   107,   109,   108,   110,
     110,   110,   111,   112,   112,   113,   113,   113,   113,   113,
     113,   114,   114,   115,   114,   116,   117,   119,   118,   121,
     120,   122,   120,   123,   120,   124,   120,   125,   126,   127,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   130,   129,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     4,     5,     8,     9,     5,     5,     6,     7,     8,
       0,     0,    13,     0,     0,     2,     3,     3,     5,     0,
       5,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     4,     1,     0,
       2,     2,     1,     2,     4,     0,     4,     0,     4,     4,
       2,     1,     3,     1,     3,     0,     3,     3,     5,     0,
       5,     3,     2,     0,     7,     0,     9,     0,     7,     9,
       1,     3,     0,     3,     0,     5,     4,     6,     4,     0,
      13,     0,    11,     8,     4,     1,     3,     0,     5,     0,
       2,     3,     1,     3,     7,     1,     2,     2,     2,     2,
       2,     6,    11,     0,     9,     0,     0,     0,     6,     0,
      12,     0,    15,     0,     9,     0,    11,     0,     0,     0,
       3,     3,     3,     3,     3,     4,     3,     2,     3,     3,
       3,     3,     3,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     5
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
#line 94 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1759 "parser.tab.c"
    break;

  case 16:
#line 101 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1765 "parser.tab.c"
    break;

  case 18:
#line 105 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1771 "parser.tab.c"
    break;

  case 19:
#line 106 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1777 "parser.tab.c"
    break;

  case 20:
#line 107 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1783 "parser.tab.c"
    break;

  case 21:
#line 108 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1789 "parser.tab.c"
    break;

  case 25:
#line 113 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1795 "parser.tab.c"
    break;

  case 26:
#line 117 "parser.y"
                                {current_class = add_class((yyvsp[-1].s));start_class_definition((yyvsp[-1].s));}
#line 1801 "parser.tab.c"
    break;

  case 27:
#line 117 "parser.y"
                                                                                                     {end_attr_list((yyvsp[-3].s));}
#line 1807 "parser.tab.c"
    break;

  case 28:
#line 117 "parser.y"
                                                                                                                                           {end_class_definition();free((yyvsp[-6].s));current_class = NULL;}
#line 1813 "parser.tab.c"
    break;

  case 31:
#line 121 "parser.y"
                                   {add_attr(current_class,NONE_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false);printcode("%s %s;\n",type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1819 "parser.tab.c"
    break;

  case 32:
#line 122 "parser.y"
                                         {add_attr(current_class,CONST_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false);printcode("const %s %s;\n",type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1825 "parser.tab.c"
    break;

  case 33:
#line 123 "parser.y"
                                                               {add_attr(current_class,NONE_TYPE,(yyvsp[-6].t),(yyvsp[-5].s),true);printcode("%s %s[%s];\n",type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1831 "parser.tab.c"
    break;

  case 34:
#line 124 "parser.y"
                                                                     {add_attr(current_class,CONST_TYPE,(yyvsp[-6].t),(yyvsp[-5].s),true);printcode("const %s %s[%s];\n",type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1837 "parser.tab.c"
    break;

  case 35:
#line 125 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1843 "parser.tab.c"
    break;

  case 36:
#line 126 "parser.y"
                                         {add_attr(current_class,NONE_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false);}
#line 1849 "parser.tab.c"
    break;

  case 37:
#line 127 "parser.y"
                                              {add_attr(current_class,CONST_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false);}
#line 1855 "parser.tab.c"
    break;

  case 38:
#line 128 "parser.y"
                                                {add_attr(current_class,NONE_TYPE,(yyvsp[-4].t),(yyvsp[-3].s),true);}
#line 1861 "parser.tab.c"
    break;

  case 39:
#line 129 "parser.y"
                                                       {add_attr(current_class,CONST_TYPE,(yyvsp[-4].t),(yyvsp[-3].s),true);}
#line 1867 "parser.tab.c"
    break;

  case 41:
#line 134 "parser.y"
                                      {pushscope();}
#line 1873 "parser.tab.c"
    break;

  case 42:
#line 134 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 1887 "parser.tab.c"
    break;

  case 43:
#line 144 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 1896 "parser.tab.c"
    break;

  case 47:
#line 153 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 1902 "parser.tab.c"
    break;

  case 48:
#line 154 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 1908 "parser.tab.c"
    break;

  case 50:
#line 157 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1914 "parser.tab.c"
    break;

  case 51:
#line 158 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1920 "parser.tab.c"
    break;

  case 52:
#line 159 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1926 "parser.tab.c"
    break;

  case 53:
#line 160 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1932 "parser.tab.c"
    break;

  case 54:
#line 161 "parser.y"
                        {expr_type= VOID_TYPE;}
#line 1938 "parser.tab.c"
    break;

  case 55:
#line 162 "parser.y"
                    {yyerror("missing ;");expr_type =  VOID_TYPE;}
#line 1944 "parser.tab.c"
    break;

  case 61:
#line 170 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 1950 "parser.tab.c"
    break;

  case 64:
#line 173 "parser.y"
            {printcode("break;");}
#line 1956 "parser.tab.c"
    break;

  case 65:
#line 174 "parser.y"
                {printcode("continue;");}
#line 1962 "parser.tab.c"
    break;

  case 66:
#line 177 "parser.y"
                       {printcode("/*");}
#line 1968 "parser.tab.c"
    break;

  case 67:
#line 177 "parser.y"
                                                                 {printcode("*/");}
#line 1974 "parser.tab.c"
    break;

  case 68:
#line 178 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 1980 "parser.tab.c"
    break;

  case 70:
#line 181 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 1986 "parser.tab.c"
    break;

  case 71:
#line 183 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 1998 "parser.tab.c"
    break;

  case 72:
#line 190 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2010 "parser.tab.c"
    break;

  case 73:
#line 197 "parser.y"
                          {has_returned = true;}
#line 2016 "parser.tab.c"
    break;

  case 75:
#line 201 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2022 "parser.tab.c"
    break;

  case 76:
#line 201 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2028 "parser.tab.c"
    break;

  case 77:
#line 202 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2034 "parser.tab.c"
    break;

  case 78:
#line 202 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2040 "parser.tab.c"
    break;

  case 79:
#line 203 "parser.y"
                              {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",(yyvsp[-2].s));
            }else{
                add_var(NONE_TYPE,expr_type,(yyvsp[-2].s),yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],(yyvsp[-2].s),(yyvsp[0].s));
            }
            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2052 "parser.tab.c"
    break;

  case 81:
#line 214 "parser.y"
                     {create_var((yyvsp[(-1) - (1)].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2058 "parser.tab.c"
    break;

  case 82:
#line 215 "parser.y"
                              {create_var((yyvsp[(-1) - (3)].m),(yyvsp[-3].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2064 "parser.tab.c"
    break;

  case 83:
#line 218 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2072 "parser.tab.c"
    break;

  case 84:
#line 221 "parser.y"
                          {  //asm("int3");
                                if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2082 "parser.tab.c"
    break;

  case 85:
#line 226 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 2088 "parser.tab.c"
    break;

  case 86:
#line 226 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 2094 "parser.tab.c"
    break;

  case 87:
#line 227 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2102 "parser.tab.c"
    break;

  case 88:
#line 230 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2112 "parser.tab.c"
    break;

  case 89:
#line 235 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 2118 "parser.tab.c"
    break;

  case 90:
#line 235 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 2124 "parser.tab.c"
    break;

  case 91:
#line 238 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2135 "parser.tab.c"
    break;

  case 92:
#line 244 "parser.y"
                      {yyerror("Array size missing");}
#line 2141 "parser.tab.c"
    break;

  case 93:
#line 245 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2147 "parser.tab.c"
    break;

  case 94:
#line 245 "parser.y"
                                                                         {printcode(" }");}
#line 2153 "parser.tab.c"
    break;

  case 95:
#line 246 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2159 "parser.tab.c"
    break;

  case 96:
#line 246 "parser.y"
                                                                                                          {printcode(" }");}
#line 2165 "parser.tab.c"
    break;

  case 97:
#line 250 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2171 "parser.tab.c"
    break;

  case 98:
#line 252 "parser.y"
                                                        {if(arr_type == VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-6].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-6].s), yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2184 "parser.tab.c"
    break;

  case 99:
#line 260 "parser.y"
                                                                    {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-8].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-8].s), yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }expr_type = VOID_TYPE;
                                                            free((yyvsp[-8].s));free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2196 "parser.tab.c"
    break;

  case 100:
#line 268 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}}
#line 2202 "parser.tab.c"
    break;

  case 101:
#line 269 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2214 "parser.tab.c"
    break;

  case 102:
#line 277 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2220 "parser.tab.c"
    break;

  case 103:
#line 277 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2226 "parser.tab.c"
    break;

  case 104:
#line 278 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2232 "parser.tab.c"
    break;

  case 105:
#line 278 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2238 "parser.tab.c"
    break;

  case 106:
#line 281 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2244 "parser.tab.c"
    break;

  case 107:
#line 282 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2251 "parser.tab.c"
    break;

  case 108:
#line 284 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2258 "parser.tab.c"
    break;

  case 109:
#line 286 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2264 "parser.tab.c"
    break;

  case 110:
#line 286 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2272 "parser.tab.c"
    break;

  case 111:
#line 289 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2278 "parser.tab.c"
    break;

  case 112:
#line 289 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2286 "parser.tab.c"
    break;

  case 113:
#line 292 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2292 "parser.tab.c"
    break;

  case 114:
#line 294 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2298 "parser.tab.c"
    break;

  case 115:
#line 298 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2308 "parser.tab.c"
    break;

  case 116:
#line 303 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2317 "parser.tab.c"
    break;

  case 117:
#line 308 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2323 "parser.tab.c"
    break;

  case 118:
#line 308 "parser.y"
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
                                    free((yyvsp[-4].s));}
#line 2361 "parser.tab.c"
    break;

  case 122:
#line 348 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2372 "parser.tab.c"
    break;

  case 123:
#line 356 "parser.y"
                                      {Variable *var = lookup_var((yyvsp[-2].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-2].s));
                                    }else if(var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else if(var->t == COMPLEX_TYPE && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }else{
                                        printcode("%s %s %s;",(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    }
                                    // No need to free $2, its const char *
                                    free((yyvsp[-2].s));free((yyvsp[0].s));
                                    expr_type = VOID_TYPE;
                                    }
#line 2395 "parser.tab.c"
    break;

  case 124:
#line 374 "parser.y"
                                                                  {Variable *var = lookup_var((yyvsp[-6].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-6].s));
                                    }else if(!var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else if((var->t == COMPLEX_TYPE || var->t == FLOAT || var->t == DOUBLE_TYPE) && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on %s type",type_arr[var->t]);
                                    }else{
                                        printcode("%s[%s] %s %s;",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    }
                                    expr_type = VOID_TYPE;
                                    // No need to free $2, its const char *
                                    free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2417 "parser.tab.c"
    break;

  case 125:
#line 393 "parser.y"
                {(yyval.s) = "=";}
#line 2423 "parser.tab.c"
    break;

  case 126:
#line 394 "parser.y"
              {(yyval.s) = "+=";}
#line 2429 "parser.tab.c"
    break;

  case 127:
#line 395 "parser.y"
              {(yyval.s) = "-=";}
#line 2435 "parser.tab.c"
    break;

  case 128:
#line 396 "parser.y"
              {(yyval.s) = "*=";}
#line 2441 "parser.tab.c"
    break;

  case 129:
#line 397 "parser.y"
              {(yyval.s) = "/=";}
#line 2447 "parser.tab.c"
    break;

  case 130:
#line 398 "parser.y"
              {(yyval.s) = "%=";}
#line 2453 "parser.tab.c"
    break;

  case 131:
#line 401 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2459 "parser.tab.c"
    break;

  case 132:
#line 402 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2465 "parser.tab.c"
    break;

  case 133:
#line 403 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2471 "parser.tab.c"
    break;

  case 135:
#line 406 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2477 "parser.tab.c"
    break;

  case 136:
#line 410 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2483 "parser.tab.c"
    break;

  case 137:
#line 414 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2489 "parser.tab.c"
    break;

  case 138:
#line 414 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2495 "parser.tab.c"
    break;

  case 139:
#line 417 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2501 "parser.tab.c"
    break;

  case 140:
#line 417 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2507 "parser.tab.c"
    break;

  case 141:
#line 418 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2513 "parser.tab.c"
    break;

  case 142:
#line 418 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2519 "parser.tab.c"
    break;

  case 143:
#line 419 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2525 "parser.tab.c"
    break;

  case 144:
#line 419 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2531 "parser.tab.c"
    break;

  case 145:
#line 420 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2537 "parser.tab.c"
    break;

  case 146:
#line 420 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2543 "parser.tab.c"
    break;

  case 147:
#line 423 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2549 "parser.tab.c"
    break;

  case 148:
#line 427 "parser.y"
                               {Variable *v = lookup_var((yyvsp[0].s));
                                    pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",(yyvsp[0].s));
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,v->t,(yyvsp[(-2) - (0)].s),yylineno);
                                        print_array_loop((yyvsp[(-2) - (0)].s),(yyvsp[0].s),v->t);
                                    }
                                }
#line 2565 "parser.tab.c"
    break;

  case 149:
#line 441 "parser.y"
                             {Variable *v = lookup_var((yyvsp[0].s));
                                        pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",(yyvsp[0].s));
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,INT_TYPE,(yyvsp[(-4) - (0)].s),yylineno);
                                        add_var(NONE_TYPE,v->t,(yyvsp[(-2) - (0)].s),yylineno);
                                        print_enumeration_loop((yyvsp[(-4) - (0)].s),(yyvsp[(-2) - (0)].s),(yyvsp[0].s),v->t);
                                    }}
#line 2581 "parser.tab.c"
    break;

  case 150:
#line 454 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2587 "parser.tab.c"
    break;

  case 151:
#line 455 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2593 "parser.tab.c"
    break;

  case 152:
#line 456 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2599 "parser.tab.c"
    break;

  case 153:
#line 457 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2605 "parser.tab.c"
    break;

  case 154:
#line 458 "parser.y"
                     {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2614 "parser.tab.c"
    break;

  case 155:
#line 462 "parser.y"
                                         {void * v = calloc(1,3+strlen(type_arr[(yyvsp[-2].t)])); // 2 for '()' one for end-of-string 0
                                sprintf(v,"(%s) ",type_arr[(yyvsp[-2].t)]);
                                char * t = join("(",(yyvsp[0].s),")");
                                (yyval.s) = join(v,"",t);
                                 is_composite_val =false;
                                free(v);
                                free(t);
                                free((yyvsp[0].s));
                                expr_type = (yyvsp[-2].t);
                            }
#line 2629 "parser.tab.c"
    break;

  case 156:
#line 472 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 2635 "parser.tab.c"
    break;

  case 157:
#line 473 "parser.y"
                            {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_composite_val =false;}
#line 2641 "parser.tab.c"
    break;

  case 158:
#line 474 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with complex type");}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2647 "parser.tab.c"
    break;

  case 159:
#line 475 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use > with complex type");}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2653 "parser.tab.c"
    break;

  case 160:
#line 476 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use <= with complex type");}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2659 "parser.tab.c"
    break;

  case 161:
#line 477 "parser.y"
                              {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with complex type");}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2665 "parser.tab.c"
    break;

  case 162:
#line 478 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2671 "parser.tab.c"
    break;

  case 163:
#line 479 "parser.y"
                                          {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2677 "parser.tab.c"
    break;

  case 164:
#line 480 "parser.y"
                    {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2683 "parser.tab.c"
    break;

  case 165:
#line 481 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2689 "parser.tab.c"
    break;

  case 166:
#line 482 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2696 "parser.tab.c"
    break;

  case 168:
#line 486 "parser.y"
                 {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2706 "parser.tab.c"
    break;

  case 169:
#line 491 "parser.y"
             {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 2716 "parser.tab.c"
    break;

  case 170:
#line 496 "parser.y"
               { if( expr_type == STRING_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 2727 "parser.tab.c"
    break;

  case 171:
#line 502 "parser.y"
                 { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
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
#line 2746 "parser.tab.c"
    break;

  case 172:
#line 516 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 2756 "parser.tab.c"
    break;

  case 173:
#line 521 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 2762 "parser.tab.c"
    break;

  case 175:
#line 523 "parser.y"
                     {push_expr_and_args();}
#line 2768 "parser.tab.c"
    break;

  case 176:
#line 523 "parser.y"
                                                      { Variable *v = lookup_var((yyvsp[-4].s));
                                                        if(v == NULL){
                                                            yyerror("Undefined variable %s",(yyval.s));
                                                        }else if(!v->is_arr && v->t != STRING_TYPE){
                                                            yyerror("Subscripted object must be of array or string type. got %s type",type_arr[v->t]);
                                                        }else if(expr_type != INT_TYPE){
                                                            yyerror("Subscript must be of int type got %s type",type_arr[expr_type]);
                                                        }
                                                        char *t = join((yyvsp[-4].s),"[",(yyvsp[-1].s));
                                                        
                                                        (yyval.s) = join(t,"]","");
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
                                                        free((yyvsp[-4].s));free((yyvsp[-1].s));
                                                        }
#line 2800 "parser.tab.c"
    break;

  case 177:
#line 552 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2812 "parser.tab.c"
    break;


#line 2816 "parser.tab.c"

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
#line 560 "parser.y"


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
