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
    bool is_static_method;


#line 112 "parser.tab.c"

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
#line 43 "parser.y"

    char *s;
    type t;
    modifier m;
    bool b;

#line 223 "parser.tab.c"

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
#define YYLAST   1109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  412

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
       0,    94,    94,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   108,   109,   110,   114,   115,   116,   119,   120,
     121,   122,   123,   124,   126,   127,   131,   131,   131,   133,
     134,   135,   139,   142,   149,   156,   157,   160,   164,   165,
     167,   168,   168,   178,   178,   191,   192,   193,   195,   196,
     198,   202,   210,   210,   220,   225,   226,   227,   229,   230,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   245,   246,   247,   248,   249,   250,   253,   253,   254,
     256,   257,   259,   266,   273,   276,   277,   278,   278,   279,
     279,   280,   280,   281,   288,   292,   293,   294,   295,   297,
     298,   301,   304,   308,   308,   309,   312,   317,   317,   320,
     326,   327,   327,   328,   328,   332,   334,   342,   350,   351,
     359,   359,   360,   360,   363,   364,   366,   368,   368,   371,
     371,   374,   376,   380,   385,   390,   390,   425,   426,   427,
     430,   438,   463,   489,   490,   491,   492,   493,   494,   497,
     498,   499,   499,   502,   506,   510,   510,   513,   513,   514,
     514,   515,   515,   516,   516,   519,   523,   537,   550,   551,
     552,   553,   554,   558,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   581,   584,   589,   594,   600,
     605,   606,   607,   627,   627,   653,   672,   672,   701,   704
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
  "$@4", "methodparamlist", "methodparam", "staticdummy", "methoddummy",
  "fndeclaration", "$@5", "fndecldummy", "paramlist", "param", "stmtlist",
  "stmt", "comment", "$@6", "commentlist", "returnstmt", "vardeclaration",
  "$@7", "$@8", "$@9", "classvarlist", "decllist", "varlist", "$@10",
  "$@11", "arraydecl", "$@12", "$@13", "arraysizedummy", "letarraydecl",
  "letarrvals", "chararrdecllist", "$@14", "$@15", "strdecl", "$@16",
  "$@17", "arrayvallist", "fncall", "$@18", "arglist", "arg", "assignstmt",
  "assgtype", "ifstmt", "$@19", "ifdummy", "elsedummy", "whilestmt",
  "$@20", "forstmt", "$@21", "$@22", "$@23", "$@24", "rangecheckdummy",
  "simplearraydummy", "iterarraydummy", "expr", "value", "$@25", "$@26",
  "classcheckdummy", "cmplxnum", YY_NULLPTR
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

#define YYPACT_NINF (-270)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-167)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -270,    10,   865,  -270,  -270,  -270,  -270,   -44,    23,   -14,
      16,  -270,  -270,    24,  1039,  -270,  -270,  -270,  -270,    51,
    -270,   322,   -58,  -270,    52,  -270,    15,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,
     122,    84,    88,   274,    77,  -270,   123,  -270,   106,   113,
     115,  -270,  -270,  -270,  -270,   103,    77,    77,    38,  -270,
    -270,  -270,  -270,   112,   947,  -270,  1077,   107,  -270,  1077,
    -270,  -270,  -270,  -270,  -270,   117,   135,   152,   -55,   167,
     159,   217,   217,  -270,  -270,   176,   182,   199,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
     240,   186,  -270,    -4,   232,   188,   220,    77,   221,    77,
     204,   225,  -270,    77,  -270,    77,    77,  -270,    77,  1077,
     756,   756,   228,   228,   228,   228,   138,   138,   250,   250,
     250,    77,   202,   231,   229,    23,  1079,  -270,   215,   227,
      23,   853,  -270,   979,  -270,  -270,  1077,   222,  1077,   988,
    -270,   -54,   778,   939,    18,  1077,   217,   214,  1077,   223,
     224,    23,  -270,   249,  -270,  -270,  1052,   253,   255,    27,
      30,   792,   188,   235,    77,   234,   806,    77,   204,  -270,
    -270,    77,  -270,  1077,  -270,    77,  -270,    77,  -270,  1079,
     237,   131,   260,   262,    85,   108,   263,  -270,  -270,   261,
     997,    77,  -270,  -270,  -270,  1077,   248,   243,  1077,  -270,
    -270,  1077,    33,    77,  -270,   251,  -270,   258,   258,  -270,
      77,  -270,    77,   247,   270,  -270,   820,  1077,    36,   252,
    -270,   264,  -270,  1077,   265,  -270,   268,   254,   269,  1077,
    1077,  -270,   259,  -270,    77,    77,  -270,    77,  -270,   271,
    -270,  -270,  -270,  -270,   272,   280,  -270,  -270,   277,   838,
    1077,    43,  1077,  -270,  -270,   334,   273,   310,    -2,  -270,
     312,  -270,  -270,    77,    77,    26,  -270,  -270,   335,    77,
      77,    77,   329,    60,   845,  -270,   323,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,   337,    23,  1079,
    -270,    47,  -270,   314,  1077,    56,  -270,  -270,  -270,     4,
     919,  1077,   933,  -270,  -270,   317,   318,   320,   324,   326,
      77,  -270,    77,  -270,  1079,  -270,   347,   344,    77,   352,
    -270,  1006,   373,  -270,  -270,   149,  -270,  -270,  -270,  -270,
    -270,  1077,  1077,  -270,   332,  1079,    68,  -270,   100,    25,
     382,  -270,  -270,  -270,   358,   363,   361,  -270,  -270,    77,
    -270,   357,   384,   377,   420,    11,  -270,  -270,   367,    72,
     368,    77,  -270,   395,  -270,    77,   463,  -270,  -270,  -270,
     180,  -270,   372,  1077,  -270,   506,   549,   365,  -270,   374,
    -270,   402,  -270,  -270,    77,   398,  -270,  -270,  -270,  1077,
    -270,   592,   635,  -270,   678,  -270,  -270,   403,  -270,  -270,
     721,  -270
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    77,    79,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,    94,     0,    80,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    91,    87,    89,    19,
       0,     0,     0,     0,     0,    52,     0,    26,     0,     0,
       0,    18,    25,    86,    99,    85,     0,     0,   192,   189,
     190,   187,   188,     0,     0,   191,   115,   185,   186,    93,
      55,    78,    81,    29,   120,    92,    95,    88,   101,    90,
       0,   175,   184,   193,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,    12,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   137,     0,     0,   174,     0,   180,
     182,   183,   178,   179,   176,   177,   168,   169,   170,   171,
     172,     0,     0,     0,     0,    12,     0,    56,     0,     0,
      12,     0,    40,     0,   121,   122,   115,    97,   102,     0,
     104,   105,     0,     0,     0,   118,   173,     0,   181,     0,
     195,    12,    57,     0,    30,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,     0,     0,     0,   194,
     136,     0,   138,   140,   116,     0,   199,     0,   196,     0,
      58,     0,     0,     0,     0,     0,     0,    50,    28,     0,
       0,     0,   115,   123,    96,   115,     0,   109,   106,   108,
     139,   119,     0,     0,    54,     0,    35,    38,    38,    33,
       0,    31,     0,     0,     0,   132,     0,   126,   124,     0,
     111,     0,   117,   115,     0,    59,     0,     0,     0,   115,
     115,    41,     0,   115,     0,     0,    98,     0,   115,     0,
      60,    39,    37,    36,     0,     0,    45,    43,     0,     0,
     125,     0,   133,   113,   197,     0,     0,     0,    12,    45,
       0,   115,   112,     0,     0,     0,    75,    76,     0,     0,
      83,     0,     0,    12,     0,    53,    66,    67,    73,    71,
      72,    74,    68,    69,    70,    34,    32,     0,    12,     0,
      46,    12,   129,   131,   134,     0,    62,    64,    63,     0,
       0,    82,     0,    24,    84,     0,     0,     0,     0,     0,
       0,   143,     0,    65,     0,    47,     0,     0,     0,     0,
     114,     0,     0,   153,   155,     0,   144,   145,   146,   147,
     148,   115,   141,    51,    48,     0,     0,   127,   192,     0,
       0,    60,    60,    61,     0,     0,     0,    51,   130,     0,
     161,     0,     0,     0,     0,     0,    60,    49,     0,     0,
       0,     0,   167,   149,   156,     0,     0,    60,   128,    60,
     165,   163,   151,   142,    42,     0,     0,     0,   157,     0,
     154,     0,    44,   162,     0,     0,    60,    60,   152,   165,
      60,     0,     0,   159,     0,   164,   150,     0,   158,    60,
       0,   160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -270,  -270,    -6,     1,  -270,  -270,  -163,  -270,  -270,  -270,
    -270,   218,  -270,  -270,  -270,   185,   165,  -270,   109,  -270,
    -270,  -270,  -270,   330,   -71,  -270,   465,  -270,  -270,  -270,
     466,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,   291,
    -270,  -270,  -126,  -270,   283,  -270,  -270,  -270,   300,  -270,
    -270,  -269,  -237,  -270,  -270,   293,  -270,   110,    87,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,    80,
    -270,  -270,   -43,  -270,  -270,  -270,  -270,  -270
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    73,   142,
     104,   237,   169,   256,   269,   268,   300,   199,   355,    17,
      70,   234,   103,   137,   265,   286,   287,    25,    46,   288,
     289,    49,    50,    48,    77,    55,    79,   110,   178,   150,
     247,   274,   101,    23,   154,    75,   105,   172,   144,   359,
     328,   261,    65,   114,   153,   182,   291,   322,   292,   391,
     351,   397,   293,   352,   294,   395,   407,   370,   389,   388,
     360,   381,   262,    67,   113,   213,   133,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    69,   191,    43,    20,   305,  -103,  -107,    44,    21,
       3,   109,   177,    81,    82,    42,     5,     6,     5,     6,
     173,    87,   315,   316,   317,   318,   319,    22,   290,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   331,   100,     5,     6,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    24,    86,   346,
     134,   135,   297,   298,   146,    26,   148,     5,     6,   332,
     152,   196,   155,   156,    47,   157,   228,   321,   184,   229,
       5,     6,   197,   185,   306,   307,   308,   198,   158,    56,
     369,   200,   361,   232,    57,   314,   201,   244,   185,    83,
     171,    84,   245,   272,   136,   141,   176,   249,   273,    39,
     183,   327,   298,   254,   255,    45,   330,   258,    58,    59,
      60,   273,   263,    61,    62,    53,   290,   290,   358,    54,
     163,   205,   378,   273,   208,   168,   136,   273,   183,   290,
      64,   166,   211,   219,   155,   303,   220,    74,   290,   290,
     335,    97,    98,    99,    76,   100,    78,   226,   227,  -166,
     193,    83,   189,    84,   290,   290,   221,   290,    80,   222,
     233,    51,    52,   290,   102,    71,    72,   239,    85,   240,
     216,    52,   106,   214,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   107,   100,   353,    52,
     112,   259,   260,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   354,   100,   108,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     304,   100,   111,   138,  -167,   115,   310,   311,   312,    95,
      96,    97,    98,    99,   131,   100,   116,   387,   132,   143,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   145,   147,   117,   118,   149,   151,   100,   159,   299,
     139,   140,   160,   164,   161,   165,   -27,   341,   186,   342,
     363,   364,   187,   174,    21,   188,    56,   -27,   349,   -12,
     190,    57,   -27,   326,   194,   376,   195,   204,   215,   299,
     206,   217,   299,   218,   223,   224,   385,   230,   386,   231,
     241,   242,   252,   235,   246,    58,    59,    60,   343,   236,
      61,    62,   257,   248,   250,   401,   402,   253,   380,   404,
     251,   295,   383,   264,   266,   275,    63,    64,   410,   357,
      27,    28,   267,   270,    29,    30,    31,    32,    33,    34,
      35,   399,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   276,   277,   278,   279,   296,   280,
     281,   302,   282,   283,     9,   284,   309,   313,   275,    41,
     329,   323,   324,   336,   337,    11,   338,    12,   344,   345,
     339,   -12,   340,   356,   285,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   276,   277,   278,
     279,   347,   280,   281,   350,   282,   283,     9,   284,   362,
     365,   275,   366,   367,   371,   372,   377,   379,    11,   382,
      12,   390,   394,   396,   -12,   279,   238,   373,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     276,   277,   278,   279,   301,   280,   281,   400,   282,   283,
       9,   284,   409,   325,   275,   162,   368,    18,    19,   209,
     212,    11,   203,    12,   210,   375,     0,   -12,   398,   403,
     374,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   276,   277,   278,   279,     0,   280,   281,
       0,   282,   283,     9,   284,     0,     0,   275,     0,     0,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
     -12,     0,     0,   384,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   276,   277,   278,   279,
       0,   280,   281,     0,   282,   283,     9,   284,     0,     0,
     275,     0,     0,     0,     0,     0,     0,    11,     0,    12,
       0,     0,     0,   -12,     0,     0,   392,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   276,
     277,   278,   279,     0,   280,   281,     0,   282,   283,     9,
     284,     0,     0,   275,     0,     0,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,   -12,     0,     0,   393,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   276,   277,   278,   279,     0,   280,   281,     0,
     282,   283,     9,   284,     0,     0,   275,     0,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,   -12,
       0,     0,   405,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   276,   277,   278,   279,     0,
     280,   281,     0,   282,   283,     9,   284,     0,     0,   275,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,   -12,     0,     0,   406,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   276,   277,
     278,   279,     0,   280,   281,     0,   282,   283,     9,   284,
       0,     0,   275,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,     0,   -12,     0,     0,   408,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   276,   277,   278,   279,     0,   280,   281,     0,   282,
     283,     9,   284,    91,    92,    93,    94,    95,    96,    97,
      98,    99,    11,   100,    12,     0,     0,     0,   -12,     0,
       0,   411,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,     0,   100,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     0,   100,     0,     0,
     179,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   202,   100,   315,   316,   317,   318,
     319,     0,     0,     0,     0,    -2,     4,     0,   207,     0,
       0,    27,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,   243,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,     0,     0,     0,     0,     0,
     271,     0,     0,     7,     8,     9,   320,     0,    84,    10,
     167,   321,     0,     0,     0,     0,    11,     0,    12,    13,
       0,     0,   -12,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,     0,
     100,    56,     0,     0,     0,     0,    57,     0,     0,    56,
       0,     0,     0,     0,    57,    27,    28,     0,     0,    29,
      30,    31,    32,    33,    34,    35,     0,     0,   333,     0,
      58,    59,    60,     0,     0,    61,    62,     0,    58,    59,
      60,    56,   334,    61,    62,     0,    57,     0,     0,     0,
      56,     0,    64,   180,   181,    57,     0,     0,     0,    56,
      64,     0,     0,     0,    57,     0,     0,     0,    56,     0,
      58,    59,    60,    57,     0,    61,    62,     0,     0,    58,
      59,    60,     0,     0,    61,    62,     0,     0,    58,    59,
      60,   170,    64,    61,    62,     0,     0,   348,    59,    60,
     175,    64,    61,    62,     0,     0,     0,    27,    28,   225,
      64,    29,    30,    31,    32,    33,    34,    35,    36,    64,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,     0,   100,     0,    37,    27,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,     0,   192
};

static const yytype_int16 yycheck[] =
{
      43,    44,   165,    61,    48,   274,    61,    61,    66,     8,
       0,    66,    66,    56,    57,    21,    20,    21,    20,    21,
     146,    64,    11,    12,    13,    14,    15,    41,   265,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    37,    17,    20,    21,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,    41,    64,   328,
      64,    65,    64,    65,   107,    41,   109,    20,    21,    65,
     113,    44,   115,   116,    59,   118,   202,    66,    60,   205,
      20,    21,    55,    65,    58,    59,    60,    60,   131,    12,
     359,    61,    67,    60,    17,    35,    66,    61,    65,    61,
     143,    63,    66,    60,   103,   104,   149,   233,    65,    58,
     153,    64,    65,   239,   240,    63,    60,   243,    41,    42,
      43,    65,   248,    46,    47,    41,   363,   364,    60,    41,
     136,   174,    60,    65,   177,   141,   135,    65,   181,   376,
      63,   140,   185,    58,   187,   271,    61,    41,   385,   386,
     313,    13,    14,    15,    41,    17,    41,   200,   201,    59,
     166,    61,   161,    63,   401,   402,    58,   404,    65,    61,
     213,    49,    50,   410,    67,    52,    53,   220,    66,   222,
      49,    50,    65,   189,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    61,    17,    49,    50,
      41,   244,   245,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,   341,    17,    65,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
     273,    17,    65,     1,    17,    59,   279,   280,   281,    11,
      12,    13,    14,    15,     4,    17,    64,    67,    62,    61,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    41,    41,    64,    65,    61,    41,    17,    66,   268,
      38,    39,    41,    58,    45,    48,    44,   320,    64,   322,
     351,   352,    59,    61,   283,    61,    12,    55,   331,    57,
      41,    17,    60,   299,    41,   366,    41,    62,    61,   298,
      66,    41,   301,    41,    41,    44,   377,    59,   379,    66,
      63,    41,    58,    62,    62,    41,    42,    43,   324,    61,
      46,    47,    63,    59,    59,   396,   397,    58,   371,   400,
      62,    58,   375,    62,    62,     1,    62,    63,   409,   345,
      18,    19,    62,    66,    22,    23,    24,    25,    26,    27,
      28,   394,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    58,    35,
      36,    59,    38,    39,    40,    41,    41,    48,     1,    57,
      66,    58,    45,    66,    66,    51,    66,    53,    41,    45,
      66,    57,    66,    61,    60,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    59,    35,    36,    41,    38,    39,    40,    41,    37,
      62,     1,    59,    62,    67,    41,    59,    59,    51,    34,
      53,    59,    67,    59,    57,    33,   218,    60,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,   269,    35,    36,    59,    38,    39,
      40,    41,    59,   298,     1,   135,   357,     2,     2,   178,
     187,    51,   172,    53,   181,   365,    -1,    57,   391,   399,
      60,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      57,    -1,    -1,    60,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    -1,    -1,    57,    -1,    -1,    60,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      -1,    -1,    60,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    -1,    -1,    60,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    51,    17,    53,    -1,    -1,    -1,    57,    -1,
      -1,    60,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      62,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    62,    17,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,     0,     1,    -1,    62,    -1,
      -1,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    62,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    38,    39,    40,    61,    -1,    63,    44,
      57,    66,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,
      -1,    -1,    57,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    12,    -1,    -1,    -1,    -1,    17,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    59,    -1,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    41,    42,
      43,    12,    59,    46,    47,    -1,    17,    -1,    -1,    -1,
      12,    -1,    63,    64,    65,    17,    -1,    -1,    -1,    12,
      63,    -1,    -1,    -1,    17,    -1,    -1,    -1,    12,    -1,
      41,    42,    43,    17,    -1,    46,    47,    -1,    -1,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    41,    42,
      43,    62,    63,    46,    47,    -1,    -1,    41,    42,    43,
      62,    63,    46,    47,    -1,    -1,    -1,    18,    19,    62,
      63,    22,    23,    24,    25,    26,    27,    28,    29,    63,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    57,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    72,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    71,    73,    75,    87,    94,    98,
      48,    71,    41,   111,    41,    95,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    57,    70,    58,
      74,    57,    70,    61,    66,    63,    96,    59,   101,    99,
     100,    49,    50,    41,    41,   103,    12,    17,    41,    42,
      43,    46,    47,    62,    63,   120,   140,   141,   145,   140,
      88,    52,    53,    76,    41,   113,    41,   102,    41,   104,
      65,   140,   140,    61,    63,    66,    70,   140,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      17,   110,    67,    90,    78,   114,    65,    61,    65,    66,
     105,    65,    41,   142,   121,    59,    64,    64,    65,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,     4,    62,   144,    64,    65,    71,    91,     1,    38,
      39,    71,    77,    61,   116,    41,   140,    41,   140,    61,
     107,    41,   140,   122,   112,   140,   140,   140,   140,    66,
      41,    45,    91,    70,    58,    48,    71,    57,    70,    80,
      62,   140,   115,   110,    61,    62,   140,    66,   106,    62,
      64,    65,   123,   140,    60,    65,    64,    59,    61,    71,
      41,    74,    57,    70,    41,    41,    44,    55,    60,    85,
      61,    66,    62,   116,    62,   140,    66,    62,   140,   107,
     123,   140,   112,   143,    70,    61,    49,    41,    41,    58,
      61,    58,    61,    41,    44,    62,   140,   140,   110,   110,
      59,    66,    60,   140,    89,    62,    61,    79,    79,   140,
     140,    63,    41,    62,    61,    66,    62,   108,    59,   110,
      59,    62,    58,    58,   110,   110,    81,    63,   110,   140,
     140,   119,   140,   110,    62,    92,    62,    62,    83,    82,
      66,    62,    60,    65,   109,     1,    30,    31,    32,    33,
      35,    36,    38,    39,    41,    60,    93,    94,    97,    98,
     120,   124,   126,   130,   132,    58,    58,    64,    65,    71,
      84,    83,    59,   110,   140,   119,    58,    59,    60,    41,
     140,   140,   140,    48,    35,    11,    12,    13,    14,    15,
      61,    66,   125,    58,    45,    84,    70,    64,   118,    66,
      60,    37,    65,    59,    59,    74,    66,    66,    66,    66,
      66,   140,   140,    70,    41,    45,   119,    59,    41,   140,
      41,   128,   131,    49,   110,    86,    61,    70,    60,   117,
     138,    67,    37,    92,    92,    62,    59,    62,    86,   119,
     135,    67,    41,    60,    60,   125,    92,    59,    60,    59,
     140,   139,    34,   140,    60,    92,    92,    67,   137,   136,
      59,   127,    60,    60,    67,   133,    59,   129,   126,   140,
      59,    92,    92,   137,    92,    60,    60,   134,    60,    59,
      92,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    76,    77,    75,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    81,    80,    82,    80,    83,    83,    83,    84,    84,
      85,    86,    88,    87,    89,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    95,    94,    94,
      96,    96,    97,    97,    97,    98,    98,    99,    98,   100,
      98,   101,    98,    98,    98,   102,   102,   102,   102,   103,
     103,   104,   104,   105,   104,   104,   104,   106,   104,   107,
     107,   108,   107,   109,   107,   110,   111,   111,   112,   112,
     114,   113,   115,   113,   116,   116,   116,   117,   116,   118,
     116,   116,   116,   119,   119,   121,   120,   122,   122,   122,
     123,   124,   124,   125,   125,   125,   125,   125,   125,   126,
     126,   127,   126,   128,   129,   131,   130,   133,   132,   134,
     132,   135,   132,   136,   132,   137,   138,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     140,   140,   140,   140,   140,   140,   141,   141,   141,   141,
     141,   141,   141,   142,   141,   141,   143,   141,   144,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     5,     9,     5,     9,     5,     7,     7,     0,     2,
       0,     0,    13,     0,    14,     0,     2,     3,     3,     5,
       1,     0,     0,    13,     0,     0,     2,     3,     3,     5,
       0,     5,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       0,     2,     2,     1,     2,     4,     4,     0,     4,     0,
       4,     0,     4,     4,     2,     1,     5,     3,     7,     1,
       3,     1,     3,     0,     3,     3,     5,     0,     5,     3,
       2,     0,     7,     0,     9,     0,     7,     9,     1,     3,
       0,     3,     0,     5,     4,     6,     4,     0,    13,     0,
      11,     8,     4,     1,     3,     0,     5,     0,     2,     3,
       1,     3,     7,     1,     2,     2,     2,     2,     2,     6,
      11,     0,     9,     0,     0,     0,     6,     0,    12,     0,
      15,     0,     9,     0,    11,     0,     0,     0,     3,     3,
       3,     3,     3,     4,     3,     2,     3,     3,     3,     3,
       3,     4,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     4,     0,     9,     0,     5
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
#line 108 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1830 "parser.tab.c"
    break;

  case 16:
#line 115 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1836 "parser.tab.c"
    break;

  case 18:
#line 119 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1842 "parser.tab.c"
    break;

  case 19:
#line 120 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1848 "parser.tab.c"
    break;

  case 20:
#line 121 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1854 "parser.tab.c"
    break;

  case 21:
#line 122 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1860 "parser.tab.c"
    break;

  case 25:
#line 127 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1866 "parser.tab.c"
    break;

  case 26:
#line 131 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1872 "parser.tab.c"
    break;

  case 27:
#line 131 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1878 "parser.tab.c"
    break;

  case 28:
#line 131 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1884 "parser.tab.c"
    break;

  case 31:
#line 135 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;\n",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1893 "parser.tab.c"
    break;

  case 32:
#line 139 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];\n",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1901 "parser.tab.c"
    break;

  case 33:
#line 142 "parser.y"
                                                  {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    }else if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);
                                                    printcode("%s %s %s;\n",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 1913 "parser.tab.c"
    break;

  case 34:
#line 149 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }else if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,yylineno);
                                                    printcode("%s %s %s[%s];\n",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 1925 "parser.tab.c"
    break;

  case 35:
#line 156 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1931 "parser.tab.c"
    break;

  case 36:
#line 157 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 1939 "parser.tab.c"
    break;

  case 37:
#line 160 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 1947 "parser.tab.c"
    break;

  case 38:
#line 164 "parser.y"
                        {(yyval.b)= false;}
#line 1953 "parser.tab.c"
    break;

  case 39:
#line 165 "parser.y"
                {(yyval.b) = true;}
#line 1959 "parser.tab.c"
    break;

  case 41:
#line 168 "parser.y"
                                       {pushscope();}
#line 1965 "parser.tab.c"
    break;

  case 42:
#line 168 "parser.y"
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
#line 1980 "parser.tab.c"
    break;

  case 43:
#line 178 "parser.y"
                                                   {pushscope();}
#line 1986 "parser.tab.c"
    break;

  case 44:
#line 178 "parser.y"
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
#line 2001 "parser.tab.c"
    break;

  case 48:
#line 195 "parser.y"
                                        {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s)); create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno);free((yyvsp[0].s));}
#line 2007 "parser.tab.c"
    break;

  case 49:
#line 196 "parser.y"
                                        {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s)); add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2013 "parser.tab.c"
    break;

  case 50:
#line 198 "parser.y"
                           {is_static_method = true;}
#line 2019 "parser.tab.c"
    break;

  case 51:
#line 202 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2030 "parser.tab.c"
    break;

  case 52:
#line 210 "parser.y"
                                      {pushscope();}
#line 2036 "parser.tab.c"
    break;

  case 53:
#line 210 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2050 "parser.tab.c"
    break;

  case 54:
#line 220 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2059 "parser.tab.c"
    break;

  case 58:
#line 229 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2065 "parser.tab.c"
    break;

  case 59:
#line 230 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2071 "parser.tab.c"
    break;

  case 61:
#line 233 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2077 "parser.tab.c"
    break;

  case 62:
#line 234 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2083 "parser.tab.c"
    break;

  case 63:
#line 235 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2089 "parser.tab.c"
    break;

  case 64:
#line 236 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2095 "parser.tab.c"
    break;

  case 65:
#line 237 "parser.y"
                        {expr_type= VOID_TYPE;}
#line 2101 "parser.tab.c"
    break;

  case 66:
#line 238 "parser.y"
                    {yyerror("missing ;");expr_type =  VOID_TYPE;}
#line 2107 "parser.tab.c"
    break;

  case 72:
#line 246 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2113 "parser.tab.c"
    break;

  case 75:
#line 249 "parser.y"
            {printcode("break;");}
#line 2119 "parser.tab.c"
    break;

  case 76:
#line 250 "parser.y"
                {printcode("continue;");}
#line 2125 "parser.tab.c"
    break;

  case 77:
#line 253 "parser.y"
                       {printcode("/*");}
#line 2131 "parser.tab.c"
    break;

  case 78:
#line 253 "parser.y"
                                                                 {printcode("*/");}
#line 2137 "parser.tab.c"
    break;

  case 79:
#line 254 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2143 "parser.tab.c"
    break;

  case 81:
#line 257 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2149 "parser.tab.c"
    break;

  case 82:
#line 259 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2161 "parser.tab.c"
    break;

  case 83:
#line 266 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2173 "parser.tab.c"
    break;

  case 84:
#line 273 "parser.y"
                          {has_returned = true;}
#line 2179 "parser.tab.c"
    break;

  case 86:
#line 277 "parser.y"
                                         {create_class_var((yyvsp[-2].m),(yyvsp[-1].s),(yyvsp[0].s),false,yylineno);}
#line 2185 "parser.tab.c"
    break;

  case 87:
#line 278 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));}
#line 2191 "parser.tab.c"
    break;

  case 88:
#line 278 "parser.y"
                                                                            {printcode(" ;");free((yyvsp[-2].s));}
#line 2197 "parser.tab.c"
    break;

  case 89:
#line 279 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2203 "parser.tab.c"
    break;

  case 90:
#line 279 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2209 "parser.tab.c"
    break;

  case 91:
#line 280 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2215 "parser.tab.c"
    break;

  case 92:
#line 280 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2221 "parser.tab.c"
    break;

  case 93:
#line 281 "parser.y"
                              {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",(yyvsp[-2].s));
            }else{
                add_var(NONE_TYPE,expr_type,(yyvsp[-2].s),yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],(yyvsp[-2].s),(yyvsp[0].s));
            }
            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2233 "parser.tab.c"
    break;

  case 95:
#line 292 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2239 "parser.tab.c"
    break;

  case 96:
#line 293 "parser.y"
                                             {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-4].s),true,yylineno);printcode("%s[%s]",(yyvsp[-4].s),(yyvsp[-2].s));free((yyvsp[-4].s));free((yyvsp[-2].s));}
#line 2245 "parser.tab.c"
    break;

  case 97:
#line 294 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2251 "parser.tab.c"
    break;

  case 98:
#line 295 "parser.y"
                                                              {create_class_var((yyvsp[(-2) - (7)].m),(yyvsp[(-1) - (7)].s),(yyvsp[-4].s),true,yylineno);printcode(", %s[%s]",(yyvsp[-4].s),(yyvsp[-2].s));free((yyvsp[-4].s));free((yyvsp[-2].s));}
#line 2257 "parser.tab.c"
    break;

  case 99:
#line 297 "parser.y"
                     {create_var((yyvsp[(-1) - (1)].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2263 "parser.tab.c"
    break;

  case 100:
#line 298 "parser.y"
                              {create_var((yyvsp[(-1) - (3)].m),(yyvsp[-3].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2269 "parser.tab.c"
    break;

  case 101:
#line 301 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2277 "parser.tab.c"
    break;

  case 102:
#line 304 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2286 "parser.tab.c"
    break;

  case 103:
#line 308 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 2292 "parser.tab.c"
    break;

  case 104:
#line 308 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 2298 "parser.tab.c"
    break;

  case 105:
#line 309 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2306 "parser.tab.c"
    break;

  case 106:
#line 312 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2316 "parser.tab.c"
    break;

  case 107:
#line 317 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 2322 "parser.tab.c"
    break;

  case 108:
#line 317 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 2328 "parser.tab.c"
    break;

  case 109:
#line 320 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2339 "parser.tab.c"
    break;

  case 110:
#line 326 "parser.y"
                      {yyerror("Array size missing");}
#line 2345 "parser.tab.c"
    break;

  case 111:
#line 327 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2351 "parser.tab.c"
    break;

  case 112:
#line 327 "parser.y"
                                                                         {printcode(" }");}
#line 2357 "parser.tab.c"
    break;

  case 113:
#line 328 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2363 "parser.tab.c"
    break;

  case 114:
#line 328 "parser.y"
                                                                                                          {printcode(" }");}
#line 2369 "parser.tab.c"
    break;

  case 115:
#line 332 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2375 "parser.tab.c"
    break;

  case 116:
#line 334 "parser.y"
                                                        {if(arr_type == VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-6].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-6].s), yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2388 "parser.tab.c"
    break;

  case 117:
#line 342 "parser.y"
                                                                    {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-8].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-8].s), yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }expr_type = VOID_TYPE;
                                                            free((yyvsp[-8].s));free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2400 "parser.tab.c"
    break;

  case 118:
#line 350 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}}
#line 2406 "parser.tab.c"
    break;

  case 119:
#line 351 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2418 "parser.tab.c"
    break;

  case 120:
#line 359 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2424 "parser.tab.c"
    break;

  case 121:
#line 359 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2430 "parser.tab.c"
    break;

  case 122:
#line 360 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2436 "parser.tab.c"
    break;

  case 123:
#line 360 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2442 "parser.tab.c"
    break;

  case 124:
#line 363 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2448 "parser.tab.c"
    break;

  case 125:
#line 364 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2455 "parser.tab.c"
    break;

  case 126:
#line 366 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2462 "parser.tab.c"
    break;

  case 127:
#line 368 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2468 "parser.tab.c"
    break;

  case 128:
#line 368 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2476 "parser.tab.c"
    break;

  case 129:
#line 371 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2482 "parser.tab.c"
    break;

  case 130:
#line 371 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2490 "parser.tab.c"
    break;

  case 131:
#line 374 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2496 "parser.tab.c"
    break;

  case 132:
#line 376 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2502 "parser.tab.c"
    break;

  case 133:
#line 380 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2512 "parser.tab.c"
    break;

  case 134:
#line 385 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2521 "parser.tab.c"
    break;

  case 135:
#line 390 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2527 "parser.tab.c"
    break;

  case 136:
#line 390 "parser.y"
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
#line 2565 "parser.tab.c"
    break;

  case 140:
#line 430 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2576 "parser.tab.c"
    break;

  case 141:
#line 438 "parser.y"
                                      {Variable *var = lookup_var((yyvsp[-2].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-2].s));
                                    }else if(var->is_arr){
                                        yyerror("Cannot assign to base of an array");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(var->is_class){
                                        if(expr_type != CLASS_TYPE ){
                                            yyerror("cannot assign %s to class type variable",type_arr[expr_type]);
                                        }else if(expr_class != var->t.class){
                                            yyerror("cannot assign class %s value to class %s variable",expr_class,var->t.class);
                                        }else if(strcmp((yyvsp[-1].s),"=") != 0){
                                            yyerror("cannot perform compund operations on class type variables");
                                        }
                                    }else if(verify_types(var->t.t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t.t],type_arr[expr_type]);
                                    }else if(var->t.t == COMPLEX_TYPE && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }
                                    printcode("%s %s %s;",(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    // No need to free $2, its const char *
                                    free((yyvsp[-2].s));free((yyvsp[0].s));
                                    expr_type = VOID_TYPE;expr_class = NULL;
                                    }
#line 2606 "parser.tab.c"
    break;

  case 142:
#line 463 "parser.y"
                                                                  {Variable *var = lookup_var((yyvsp[-6].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-6].s));
                                    }else if(!var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(var->is_class){
                                        if(expr_type != CLASS_TYPE ){
                                            yyerror("cannot assign %s to class type variable",type_arr[expr_type]);
                                        }else if(expr_class!=var->t.class){
                                            yyerror("cannot assign class %s value to class %s variable",expr_class,var->t.class);
                                        }else if(strcmp((yyvsp[-1].s),"=") != 0){
                                            yyerror("cannot perform compund operations on class type variables");
                                        }
                                    }else if(verify_types(var->t.t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t.t],type_arr[expr_type]);
                                    }else if((var->t.t == COMPLEX_TYPE || var->t.t == FLOAT || var->t.t == DOUBLE_TYPE) && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on %s type",type_arr[var->t.t]);
                                    }
                                    printcode("%s[%s] %s %s;",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    expr_type = VOID_TYPE;expr_class = NULL;
                                    // No need to free $2, its const char *
                                    free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2635 "parser.tab.c"
    break;

  case 143:
#line 489 "parser.y"
                {(yyval.s) = "=";}
#line 2641 "parser.tab.c"
    break;

  case 144:
#line 490 "parser.y"
              {(yyval.s) = "+=";}
#line 2647 "parser.tab.c"
    break;

  case 145:
#line 491 "parser.y"
              {(yyval.s) = "-=";}
#line 2653 "parser.tab.c"
    break;

  case 146:
#line 492 "parser.y"
              {(yyval.s) = "*=";}
#line 2659 "parser.tab.c"
    break;

  case 147:
#line 493 "parser.y"
              {(yyval.s) = "/=";}
#line 2665 "parser.tab.c"
    break;

  case 148:
#line 494 "parser.y"
              {(yyval.s) = "%=";}
#line 2671 "parser.tab.c"
    break;

  case 149:
#line 497 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2677 "parser.tab.c"
    break;

  case 150:
#line 498 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2683 "parser.tab.c"
    break;

  case 151:
#line 499 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2689 "parser.tab.c"
    break;

  case 153:
#line 502 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2695 "parser.tab.c"
    break;

  case 154:
#line 506 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2701 "parser.tab.c"
    break;

  case 155:
#line 510 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2707 "parser.tab.c"
    break;

  case 156:
#line 510 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2713 "parser.tab.c"
    break;

  case 157:
#line 513 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2719 "parser.tab.c"
    break;

  case 158:
#line 513 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2725 "parser.tab.c"
    break;

  case 159:
#line 514 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2731 "parser.tab.c"
    break;

  case 160:
#line 514 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2737 "parser.tab.c"
    break;

  case 161:
#line 515 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2743 "parser.tab.c"
    break;

  case 162:
#line 515 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2749 "parser.tab.c"
    break;

  case 163:
#line 516 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2755 "parser.tab.c"
    break;

  case 164:
#line 516 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2761 "parser.tab.c"
    break;

  case 165:
#line 519 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2767 "parser.tab.c"
    break;

  case 166:
#line 523 "parser.y"
                               {Variable *v = lookup_var((yyvsp[0].s));
                                    pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",(yyvsp[0].s));
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,v->t.t,(yyvsp[(-2) - (0)].s),yylineno);
                                        print_array_loop((yyvsp[(-2) - (0)].s),(yyvsp[0].s),v->t.t);
                                    }
                                }
#line 2783 "parser.tab.c"
    break;

  case 167:
#line 537 "parser.y"
                             {Variable *v = lookup_var((yyvsp[0].s));
                                        pushscope(); // must be done here, as the popscope occurs irrespective of existance of arr
                                    if(v == NULL){
                                        yyerror("Undefined variable %s",(yyvsp[0].s));
                                    }else if(!(v->is_arr)){
                                        yyerror("Cannot iterate over non-array Variables");
                                    }else{
                                        add_var(NONE_TYPE,INT_TYPE,(yyvsp[(-4) - (0)].s),yylineno);
                                        add_var(NONE_TYPE,v->t.t,(yyvsp[(-2) - (0)].s),yylineno);
                                        print_enumeration_loop((yyvsp[(-4) - (0)].s),(yyvsp[(-2) - (0)].s),(yyvsp[0].s),v->t.t);
                                    }}
#line 2799 "parser.tab.c"
    break;

  case 168:
#line 550 "parser.y"
                     { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2805 "parser.tab.c"
    break;

  case 169:
#line 551 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2811 "parser.tab.c"
    break;

  case 170:
#line 552 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2817 "parser.tab.c"
    break;

  case 171:
#line 553 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2823 "parser.tab.c"
    break;

  case 172:
#line 554 "parser.y"
                     {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2832 "parser.tab.c"
    break;

  case 173:
#line 558 "parser.y"
                                         {
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
#line 2848 "parser.tab.c"
    break;

  case 174:
#line 569 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 2854 "parser.tab.c"
    break;

  case 175:
#line 570 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_composite_val =false;}
#line 2860 "parser.tab.c"
    break;

  case 176:
#line 571 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2866 "parser.tab.c"
    break;

  case 177:
#line 572 "parser.y"
                      {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use > with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2872 "parser.tab.c"
    break;

  case 178:
#line 573 "parser.y"
                            {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use <= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2878 "parser.tab.c"
    break;

  case 179:
#line 574 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2884 "parser.tab.c"
    break;

  case 180:
#line 575 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2890 "parser.tab.c"
    break;

  case 181:
#line 576 "parser.y"
                                         {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2896 "parser.tab.c"
    break;

  case 182:
#line 577 "parser.y"
                     {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2902 "parser.tab.c"
    break;

  case 183:
#line 578 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2908 "parser.tab.c"
    break;

  case 184:
#line 579 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2915 "parser.tab.c"
    break;

  case 186:
#line 584 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2925 "parser.tab.c"
    break;

  case 187:
#line 589 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 2935 "parser.tab.c"
    break;

  case 188:
#line 594 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 2946 "parser.tab.c"
    break;

  case 189:
#line 600 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 2956 "parser.tab.c"
    break;

  case 190:
#line 605 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 2962 "parser.tab.c"
    break;

  case 192:
#line 607 "parser.y"
                 { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
                    }else if(_t->is_class){
                        if(expr_type == CLASS_TYPE){
                            yyerror("Cannot combine class type with anything else");
                        }
                        expr_type = CLASS_TYPE;
                        expr_class = _t->t.class;
                    }else if(_t->is_arr && !is_in_fncall){
                        yyerror("cannot use arrray without subscript.");
                    }else if(expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[_t->t.t],type_arr[expr_type]);;
                    }else if(_t->t.t ==COMPLEX_TYPE){
                        expr_type = COMPLEX_TYPE;
                    }else if(_t->t.t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                        expr_type = FLOAT_TYPE;
                    }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                        expr_type = _t->t.t;
                    }}
#line 2987 "parser.tab.c"
    break;

  case 193:
#line 627 "parser.y"
                     {push_expr_and_args();}
#line 2993 "parser.tab.c"
    break;

  case 194:
#line 627 "parser.y"
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
#line 3024 "parser.tab.c"
    break;

  case 195:
#line 653 "parser.y"
                                           { attr* a = find_attr(expr_class,(yyvsp[0].s));    
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[-3].s),(yyvsp[0].s));
                                        }else{
                                            if(a->is_class){
                                                expr_type = CLASS_TYPE;
                                                expr_class = a->t.class;
                                            }else if(a->is_arr && !is_in_fncall){
                                                yyerror("cannot use arrray without subscript.");
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
#line 3048 "parser.tab.c"
    break;

  case 196:
#line 672 "parser.y"
                                               {push_expr_and_args();}
#line 3054 "parser.tab.c"
    break;

  case 197:
#line 672 "parser.y"
                                                                                                { attr* a = find_attr(expr_class,(yyvsp[-5].s));  
                                                                                                pop_expr_and_args();  
                                                                                    if(a== NULL){
                                                                                        yyerror("No attribute %s declared on class %s",(yyvsp[-8].s),(yyvsp[-5].s));
                                                                                    }else{
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
#line 3085 "parser.tab.c"
    break;

  case 198:
#line 701 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3091 "parser.tab.c"
    break;

  case 199:
#line 704 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3103 "parser.tab.c"
    break;


#line 3107 "parser.tab.c"

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
#line 712 "parser.y"


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
