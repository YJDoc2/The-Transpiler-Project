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
    type temp_type;
    char * temp_class;
    bool is_assignable = false;
    bool is_static_method;


#line 115 "parser.tab.c"

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
#line 46 "parser.y"

    char *s;
    type t;
    modifier m;
    bool b;

#line 226 "parser.tab.c"

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
#define YYLAST   1159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  420

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
       0,    98,    98,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   112,   113,   114,   118,   119,   120,   123,   124,
     125,   126,   127,   128,   130,   131,   135,   135,   135,   137,
     138,   139,   143,   146,   154,   162,   163,   166,   169,   171,
     172,   174,   175,   175,   185,   185,   198,   199,   200,   202,
     203,   205,   209,   217,   217,   227,   232,   233,   234,   236,
     237,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   252,   253,   254,   255,   256,   257,   260,   260,
     261,   263,   264,   266,   273,   280,   283,   283,   284,   284,
     285,   285,   286,   286,   287,   287,   288,   299,   302,   303,
     309,   309,   310,   311,   317,   317,   323,   324,   325,   326,
     329,   330,   333,   336,   340,   340,   341,   344,   349,   349,
     352,   358,   359,   359,   360,   360,   364,   366,   377,   388,
     389,   400,   400,   401,   401,   404,   405,   407,   409,   409,
     412,   412,   415,   417,   421,   427,   432,   432,   467,   468,
     469,   472,   480,   505,   511,   512,   513,   514,   515,   516,
     519,   520,   521,   521,   524,   528,   532,   532,   535,   535,
     536,   536,   537,   537,   538,   538,   541,   545,   559,   572,
     573,   574,   575,   576,   580,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   603,   606,   611,   616,
     622,   627,   628,   629,   632,   641,   663,   663,   690,   711,
     711,   740
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
  "$@7", "$@8", "$@9", "$@10", "$@11", "classvarlist", "$@12", "$@13",
  "decllist", "classdecllist", "varlist", "$@14", "$@15", "arraydecl",
  "$@16", "$@17", "arraysizedummy", "letarraydecl", "letarrvals",
  "chararrdecllist", "$@18", "$@19", "strdecl", "$@20", "$@21",
  "arrayvallist", "fncall", "$@22", "arglist", "arg", "assignstmt",
  "assigndummy", "assgtype", "ifstmt", "$@23", "ifdummy", "elsedummy",
  "whilestmt", "$@24", "forstmt", "$@25", "$@26", "$@27", "$@28",
  "rangecheckdummy", "simplearraydummy", "iterarraydummy", "expr", "value",
  "cmplxnum", "varvals", "$@29", "$@30", "classcheckdummy", YY_NULLPTR
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

#define YYPACT_NINF (-274)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-178)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -274,    26,   924,  -274,  -274,  -274,  -274,    -7,    71,     5,
      23,  -274,  -274,    63,   338,  -274,  -274,  -274,  -274,    21,
    -274,   157,   -42,  -274,    36,  -274,    49,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
     195,  -274,  -274,    73,  1053,  -274,   194,  -274,    76,    96,
     109,  -274,  -274,   114,   126,  1053,  1053,   -45,  -274,  -274,
    -274,  -274,   106,   998,  -274,  1123,  -274,  -274,   111,  1123,
    -274,  -274,  -274,  -274,  -274,   123,   -26,   146,   -23,   148,
     154,   165,   180,   187,   256,   256,  -274,  -274,   221,   222,
     257,  1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,
    1053,  1053,  1053,   284,   228,  -274,     7,   780,   231,   254,
    1053,   235,   261,  1053,   235,   267,   248,  -274,   271,   255,
     279,  1053,  -274,  1053,  1053,  -274,  1053,  1123,   225,   225,
     178,   178,   178,   178,   149,   149,   280,   280,   280,  1053,
     232,   282,   281,    71,  1131,  -274,   266,   277,    71,   910,
    -274,  -274,   272,  -274,  -274,  1123,  1016,  -274,     2,  1123,
    -274,    27,  -274,   154,  -274,   268,   837,   236,   -18,  1123,
     256,   335,  1123,   269,   270,    71,  -274,   286,  -274,  -274,
    1095,   289,   292,   -21,    28,   851,   231,   287,   865,  1053,
     235,  1053,   235,  -274,   274,  -274,  -274,  1053,  -274,  1123,
    -274,  1053,  -274,  1053,  -274,  1131,   276,   205,   313,   314,
      81,   151,   317,  -274,  -274,   340,  1026,  1053,  -274,  -274,
     328,   326,  1123,  -274,  1123,  -274,  -274,  -274,  1123,    38,
    1053,  -274,   331,  -274,   154,   154,  -274,  1053,  -274,  1053,
     333,   356,  -274,   879,  1123,    39,  -274,   339,  -274,  1123,
     341,  -274,   344,   346,  1123,  1123,  -274,   342,  -274,  1053,
    1053,  1053,  -274,   347,  -274,  -274,  -274,   365,   368,  -274,
    -274,   369,   897,  1123,    46,  1123,  -274,  -274,   350,   348,
     378,    10,  -274,   349,  -274,  -274,  1053,  1053,    69,  -274,
    -274,   397,  1053,  1053,  1053,   391,     1,  -274,   382,  -274,
    -274,  -274,  -274,  -274,  -274,  -274,  -274,   111,  -274,  -274,
     396,    71,  1131,  -274,    12,  -274,   376,  1123,    47,  -274,
    -274,  -274,   -20,   978,  1123,   992,  -274,  -274,  -274,    -4,
    1131,  -274,   402,   400,  1053,   388,  -274,  1063,   407,  -274,
    -274,   209,   383,   385,   386,   404,   412,  -274,  1053,  -274,
     418,  1131,    58,  -274,    86,   193,   444,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,  1123,   414,   420,  -274,  -274,
    1053,  -274,   416,   443,   393,   436,  -274,  -274,   426,    66,
     427,  1053,  -274,   454,  -274,   479,  -274,  -274,  -274,   214,
    -274,   431,  -274,   522,   565,   424,  -274,   433,  -274,   461,
    -274,  -274,  1053,   457,  -274,  -274,  -274,  1123,  -274,   608,
     651,  -274,   694,  -274,  -274,   462,  -274,  -274,   737,  -274
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    78,    80,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,    97,     0,    81,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    94,    90,    92,    19,
       0,    88,    86,     0,     0,    53,     0,    26,     0,     0,
       0,    18,    25,     0,     0,     0,     0,   205,   200,   201,
     198,   199,     0,     0,   202,   126,   196,   197,   203,    96,
      56,    79,    82,    29,   131,    95,    98,    91,   112,    93,
      39,    89,   106,    87,   186,   195,   206,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,     0,
       0,     0,   148,     0,     0,   185,     0,   191,   193,   194,
     189,   190,   187,   188,   179,   180,   181,   182,   183,     0,
       0,     0,     0,    12,     0,    57,     0,     0,    12,     0,
      41,    38,     0,   132,   133,    99,     0,   101,   102,   113,
     115,   116,    40,    39,   107,   108,     0,     0,     0,   129,
     184,     0,   192,     0,   208,    12,    58,     0,    30,    24,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,     0,     0,   111,     0,   207,   147,     0,   149,   151,
     127,     0,   204,     0,   209,     0,    59,     0,     0,     0,
       0,     0,     0,    51,    28,     0,     0,     0,   126,   134,
       0,   120,   103,   105,   117,   119,   109,   150,   130,     0,
       0,    55,     0,    35,    39,    39,    33,     0,    31,     0,
       0,     0,   143,     0,   137,   135,   122,     0,   128,   126,
       0,    60,     0,     0,   126,   126,    42,     0,   126,     0,
       0,     0,   126,     0,    61,    37,    36,     0,     0,    46,
      44,     0,     0,   136,     0,   144,   124,   210,     0,     0,
       0,    12,    46,     0,   126,   123,     0,     0,     0,    76,
      77,     0,     0,    84,     0,     0,    12,    54,    67,    68,
      74,    72,    73,    75,    69,    70,    71,   153,    34,    32,
       0,    12,     0,    47,    12,   140,   142,   145,     0,    63,
      65,    64,     0,     0,    83,     0,    24,    85,    66,     0,
       0,    48,     0,     0,     0,     0,   125,     0,     0,   164,
     166,     0,     0,     0,     0,     0,     0,   154,     0,    52,
      49,     0,     0,   138,   205,     0,     0,    61,    61,    62,
     155,   156,   157,   158,   159,   152,     0,     0,    52,   141,
       0,   172,     0,     0,     0,     0,    61,    50,     0,     0,
       0,     0,   178,   160,   167,     0,    61,   139,    61,   176,
     174,   162,    43,     0,     0,     0,   168,     0,   165,     0,
      45,   173,     0,     0,    61,    61,   163,   176,    61,     0,
       0,   170,     0,   175,   161,     0,   169,    61,     0,   171
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -274,  -274,   -19,    -5,  -274,  -274,  -175,  -274,  -274,  -274,
    -274,  -148,  -274,  -274,  -274,   213,   202,  -274,   156,  -274,
    -274,  -274,  -274,   379,  -101,  -274,     3,  -274,  -274,  -274,
     523,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -108,  -274,  -274,  -189,  -274,   323,
    -274,  -274,  -274,   343,  -274,  -274,  -273,  -253,  -274,  -274,
     330,  -274,  -274,  -274,   129,  -274,  -274,  -274,  -274,  -274,
    -274,  -274,  -274,  -274,  -274,   124,  -274,  -274,   -43,  -274,
    -274,  -241,  -274,  -274,  -274
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    73,   150,
     107,   117,   183,   269,   282,   281,   313,   215,   366,    17,
      70,   250,   106,   145,   278,   298,   299,    25,    46,   300,
     301,    54,    53,    49,    50,    48,    77,   111,   190,    83,
      81,    79,   114,   192,   157,   261,   287,   104,    23,   168,
      75,   108,   186,   153,   370,   334,   274,    64,   122,   167,
     198,   303,   329,   348,   304,   399,   357,   405,   305,   358,
     306,   403,   415,   380,   397,   396,   371,   390,   275,    66,
      67,    68,   121,   230,   141
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    69,    42,    21,   207,    18,   160,   342,   343,   344,
     345,   346,    84,    85,   318,   193,    86,   337,    87,    43,
      90,     5,     6,   212,    44,   302,     3,     5,     6,   245,
       5,     6,     5,     6,   213,  -100,   327,   307,  -114,   214,
     110,    20,   200,   113,    89,   338,    22,   201,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     263,   352,   347,  -104,    24,   267,   268,   155,   189,   271,
     159,   142,   143,   276,   310,   311,   333,   311,   166,    39,
     169,   170,   223,   171,   225,    55,   252,   253,  -118,   216,
      56,     5,     6,   191,   217,   316,   172,   379,   248,    45,
     259,   144,   149,   201,    26,   260,   285,   336,    47,   185,
     151,   286,   286,   188,    57,    58,    59,    74,   369,    60,
      61,   302,   302,   286,   199,   177,   387,   319,   320,   321,
     182,   286,   302,   307,   307,    62,    63,    76,   144,   236,
     302,   302,   237,   180,   307,  -177,   222,    86,   224,    87,
      78,   341,   307,   307,   199,    80,   302,   302,   228,   302,
     169,   209,   100,   101,   102,   302,   103,    82,   307,   307,
     205,   307,    88,   243,   244,    27,    28,   307,   105,    29,
      30,    31,    32,    33,    34,    35,   231,   249,   109,    98,
      99,   100,   101,   102,   254,   103,   255,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   238,
     103,   112,   239,   115,    41,   116,   272,   273,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     118,   103,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   119,   103,   317,    51,    52,    71,    72,    55,   323,
     324,   325,   120,    56,   233,    52,   374,   375,   359,    52,
     372,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,  -178,   103,   385,   312,    57,    58,    59,
     123,   395,    60,    61,    55,   393,   124,   394,   139,    56,
     140,    21,   152,   332,   355,   154,   156,   103,   173,    63,
     196,   197,   158,   409,   410,   365,   312,   412,   161,   312,
     162,   349,   163,    57,    58,    59,   418,   164,    60,    61,
     165,   125,   126,   174,   178,   179,   175,   206,   203,   194,
     210,   204,   368,   211,   184,    63,   226,   232,   389,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   288,   103,   220,   234,   235,    27,    28,   240,   407,
      29,    30,    31,    32,    33,    34,    35,    36,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     289,   290,   291,   292,   241,   293,   294,   246,   295,   296,
       9,    57,   247,   251,   288,    37,   256,   257,   262,   202,
     264,    11,   265,    12,   266,   270,   308,   -12,   315,   277,
     297,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   289,   290,   291,   292,   279,   293,   294,
     280,   295,   296,     9,    57,   283,   309,   288,   322,   326,
     328,   330,   335,   350,    11,   351,    12,   353,   356,   360,
     -12,   361,   362,   383,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   289,   290,   291,   292,
     363,   293,   294,   376,   295,   296,     9,    57,   364,   367,
     288,   373,   377,   381,   382,   386,   388,    11,   391,    12,
     398,   402,   404,   -12,   292,   314,   384,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   289,
     290,   291,   292,   331,   293,   294,   408,   295,   296,     9,
      57,   417,   176,   288,   378,    19,   229,   227,   406,   219,
      11,   411,    12,     0,     0,     0,   -12,     0,     0,   392,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   289,   290,   291,   292,     0,   293,   294,     0,
     295,   296,     9,    57,     0,     0,   288,     0,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,   -12,
       0,     0,   400,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   289,   290,   291,   292,     0,
     293,   294,     0,   295,   296,     9,    57,     0,     0,   288,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,   -12,     0,     0,   401,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   289,   290,
     291,   292,     0,   293,   294,     0,   295,   296,     9,    57,
       0,     0,   288,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,     0,   -12,     0,     0,   413,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   289,   290,   291,   292,     0,   293,   294,     0,   295,
     296,     9,    57,     0,     0,   288,     0,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,   -12,     0,
       0,   414,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   289,   290,   291,   292,     0,   293,
     294,     0,   295,   296,     9,    57,     0,     0,   288,     0,
       0,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,   -12,     0,     0,   416,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   289,   290,   291,
     292,     0,   293,   294,     0,   295,   296,     9,    57,     0,
       0,   146,     0,     0,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,   -12,     0,     0,   419,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   148,
       0,     0,     0,     0,   -27,     0,     0,     0,     0,     0,
       0,    11,     0,    12,     0,   -27,     0,   -12,     0,     0,
     -27,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,     0,   103,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,   103,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,     0,     0,   195,
       0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   218,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -2,     4,     0,   221,    27,    28,
       0,     0,    29,    30,    31,    32,    33,    34,    35,     0,
       0,   258,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,     0,     0,     0,     0,     0,   284,
       0,     0,     7,     8,     9,     0,     0,   181,    10,     0,
       0,     0,     0,     0,     0,    11,     0,    12,    13,     0,
       0,   -12,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,   103,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
      55,     0,     0,     0,     0,    56,    27,    28,     0,     0,
      29,    30,    31,    32,    33,    34,    35,     0,    55,     0,
       0,     0,     0,    56,     0,     0,     0,   339,    55,    57,
      58,    59,     0,    56,    60,    61,     0,     0,     0,     0,
       0,   340,     0,     0,     0,     0,     0,    57,    58,    59,
       0,    63,    60,    61,     0,    55,     0,    57,    58,    59,
      56,     0,    60,    61,     0,    55,     0,     0,   187,    63,
      56,     0,     0,     0,     0,     0,     0,     0,   242,    63,
       0,     0,     0,     0,    57,    58,    59,     0,     0,    60,
      61,     0,     0,     0,   354,    58,    59,     0,     0,    60,
      61,     0,     0,    27,    28,     0,    63,    29,    30,    31,
      32,    33,    34,    35,     0,     0,    63,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     0,   208,    29,    30,    31,    32,    33,    34,    35
};

static const yytype_int16 yycheck[] =
{
      43,    44,    21,     8,   179,     2,   114,    11,    12,    13,
      14,    15,    55,    56,   287,   163,    61,    37,    63,    61,
      63,    20,    21,    44,    66,   278,     0,    20,    21,   218,
      20,    21,    20,    21,    55,    61,    35,   278,    61,    60,
      66,    48,    60,    66,    63,    65,    41,    65,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     249,   334,    66,    61,    41,   254,   255,   110,    66,   258,
     113,    64,    65,   262,    64,    65,    64,    65,   121,    58,
     123,   124,   190,   126,   192,    12,   234,   235,    61,    61,
      17,    20,    21,    66,    66,   284,   139,   370,    60,    63,
      61,   106,   107,    65,    41,    66,    60,    60,    59,   152,
     107,    65,    65,   156,    41,    42,    43,    41,    60,    46,
      47,   374,   375,    65,   167,   144,    60,    58,    59,    60,
     149,    65,   385,   374,   375,    62,    63,    41,   143,    58,
     393,   394,    61,   148,   385,    59,   189,    61,   191,    63,
      41,   326,   393,   394,   197,    41,   409,   410,   201,   412,
     203,   180,    13,    14,    15,   418,    17,    41,   409,   410,
     175,   412,    66,   216,   217,    18,    19,   418,    67,    22,
      23,    24,    25,    26,    27,    28,   205,   230,    65,    11,
      12,    13,    14,    15,   237,    17,   239,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    58,
      17,    65,    61,    65,    57,    61,   259,   260,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      65,    17,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    61,    17,   286,    49,    50,    52,    53,    12,   292,
     293,   294,    65,    17,    49,    50,   357,   358,    49,    50,
      67,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    17,   376,   281,    41,    42,    43,
      59,    67,    46,    47,    12,   386,    64,   388,     4,    17,
      62,   296,    61,   312,   337,    41,    61,    17,    66,    63,
      64,    65,    41,   404,   405,   348,   311,   408,    41,   314,
      62,   330,    41,    41,    42,    43,   417,    62,    46,    47,
      41,    64,    65,    41,    58,    48,    45,    41,    59,    61,
      41,    61,   351,    41,    62,    63,    62,    61,   381,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     1,    17,    66,    41,    41,    18,    19,    41,   402,
      22,    23,    24,    25,    26,    27,    28,    29,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    44,    35,    36,    59,    38,    39,
      40,    41,    66,    62,     1,    57,    63,    41,    59,    64,
      59,    51,    58,    53,    58,    63,    58,    57,    59,    62,
      60,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    62,    35,    36,
      62,    38,    39,    40,    41,    66,    58,     1,    41,    48,
      58,    45,    66,    41,    51,    45,    53,    59,    41,    66,
      57,    66,    66,    60,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      66,    35,    36,    59,    38,    39,    40,    41,    66,    61,
       1,    37,    62,    67,    41,    59,    59,    51,    34,    53,
      59,    67,    59,    57,    33,   282,    60,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,   311,    35,    36,    59,    38,    39,    40,
      41,    59,   143,     1,   368,     2,   203,   197,   399,   186,
      51,   407,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,
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
      20,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    -1,    55,    -1,    57,    -1,    -1,
      60,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    62,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    62,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    62,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    62,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    38,    39,    40,    -1,    -1,    57,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,    -1,
      -1,    57,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      12,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    12,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    59,    12,    41,
      42,    43,    -1,    17,    46,    47,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,
      -1,    63,    46,    47,    -1,    12,    -1,    41,    42,    43,
      17,    -1,    46,    47,    -1,    12,    -1,    -1,    62,    63,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    -1,    18,    19,    -1,    63,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    63,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    -1,    57,    22,    23,    24,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    72,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    71,    73,    75,    87,    94,    98,
      48,    71,    41,   116,    41,    95,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    57,    70,    58,
      74,    57,    70,    61,    66,    63,    96,    59,   103,   101,
     102,    49,    50,   100,    99,    12,    17,    41,    42,    43,
      46,    47,    62,    63,   125,   146,   147,   148,   149,   146,
      88,    52,    53,    76,    41,   118,    41,   104,    41,   109,
      41,   108,    41,   107,   146,   146,    61,    63,    66,    70,
     146,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,   115,    67,    90,    78,   119,    65,
      66,   105,    65,    66,   110,    65,    61,    79,    65,    61,
      65,   150,   126,    59,    64,    64,    65,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,     4,
      62,   152,    64,    65,    71,    91,     1,    38,    39,    71,
      77,    94,    61,   121,    41,   146,    61,   112,    41,   146,
     112,    41,    62,    41,    62,    41,   146,   127,   117,   146,
     146,   146,   146,    66,    41,    45,    91,    70,    58,    48,
      71,    57,    70,    80,    62,   146,   120,    62,   146,    66,
     106,    66,   111,    79,    61,    62,    64,    65,   128,   146,
      60,    65,    64,    59,    61,    71,    41,    74,    57,    70,
      41,    41,    44,    55,    60,    85,    61,    66,    62,   121,
      66,    62,   146,   112,   146,   112,    62,   128,   146,   117,
     151,    70,    61,    49,    41,    41,    58,    61,    58,    61,
      41,    44,    62,   146,   146,   115,    59,    66,    60,   146,
      89,    62,    79,    79,   146,   146,    63,    41,    62,    61,
      66,   113,    59,   115,    59,    58,    58,   115,   115,    81,
      63,   115,   146,   146,   124,   146,   115,    62,    92,    62,
      62,    83,    82,    66,    62,    60,    65,   114,     1,    30,
      31,    32,    33,    35,    36,    38,    39,    60,    93,    94,
      97,    98,   125,   129,   132,   136,   138,   149,    58,    58,
      64,    65,    71,    84,    83,    59,   115,   146,   124,    58,
      59,    60,    41,   146,   146,   146,    48,    35,    58,   130,
      45,    84,    70,    64,   123,    66,    60,    37,    65,    59,
      59,    74,    11,    12,    13,    14,    15,    66,   131,    70,
      41,    45,   124,    59,    41,   146,    41,   134,   137,    49,
      66,    66,    66,    66,    66,   146,    86,    61,    70,    60,
     122,   144,    67,    37,    92,    92,    59,    62,    86,   124,
     141,    67,    41,    60,    60,    92,    59,    60,    59,   146,
     145,    34,    60,    92,    92,    67,   143,   142,    59,   133,
      60,    60,    67,   139,    59,   135,   132,   146,    59,    92,
      92,   143,    92,    60,    60,   140,    60,    59,    92,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    76,    77,    75,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      79,    80,    81,    80,    82,    80,    83,    83,    83,    84,
      84,    85,    86,    88,    87,    89,    90,    90,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    95,    94,
      94,    96,    96,    97,    97,    97,    99,    98,   100,    98,
     101,    98,   102,    98,   103,    98,    98,    98,   104,   104,
     105,   104,   104,   104,   106,   104,   107,   107,   107,   107,
     108,   108,   109,   109,   110,   109,   109,   109,   111,   109,
     112,   112,   113,   112,   114,   112,   115,   116,   116,   117,
     117,   119,   118,   120,   118,   121,   121,   121,   122,   121,
     123,   121,   121,   121,   124,   124,   126,   125,   127,   127,
     127,   128,   129,   130,   131,   131,   131,   131,   131,   131,
     132,   132,   133,   132,   134,   135,   137,   136,   139,   138,
     140,   138,   141,   138,   142,   138,   143,   144,   145,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   147,
     147,   147,   147,   147,   148,   149,   150,   149,   149,   151,
     149,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     5,     9,     5,     9,     5,     7,     7,     2,     0,
       2,     0,     0,    13,     0,    14,     0,     2,     3,     3,
       5,     1,     0,     0,    13,     0,     0,     2,     3,     3,
       5,     0,     5,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     2,     2,     1,     2,     0,     5,     0,     5,
       0,     4,     0,     4,     0,     4,     4,     2,     1,     3,
       0,     3,     3,     5,     0,     5,     1,     3,     3,     5,
       2,     4,     1,     3,     0,     3,     3,     5,     0,     5,
       3,     2,     0,     7,     0,     9,     0,     7,     9,     1,
       3,     0,     3,     0,     5,     4,     6,     4,     0,    13,
       0,    11,     8,     4,     1,     3,     0,     5,     0,     2,
       3,     1,     4,     0,     1,     2,     2,     2,     2,     2,
       6,    11,     0,     9,     0,     0,     0,     6,     0,    12,
       0,    15,     0,     9,     0,    11,     0,     0,     0,     3,
       3,     3,     3,     3,     4,     3,     2,     3,     3,     3,
       3,     3,     4,     3,     3,     2,     1,     1,     1,     1,
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
#line 112 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1852 "parser.tab.c"
    break;

  case 16:
#line 119 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1858 "parser.tab.c"
    break;

  case 18:
#line 123 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1864 "parser.tab.c"
    break;

  case 19:
#line 124 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1870 "parser.tab.c"
    break;

  case 20:
#line 125 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1876 "parser.tab.c"
    break;

  case 21:
#line 126 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1882 "parser.tab.c"
    break;

  case 23:
#line 128 "parser.y"
               {expr_type =VOID_TYPE;}
#line 1888 "parser.tab.c"
    break;

  case 25:
#line 131 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1894 "parser.tab.c"
    break;

  case 26:
#line 135 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1900 "parser.tab.c"
    break;

  case 27:
#line 135 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1906 "parser.tab.c"
    break;

  case 28:
#line 135 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1912 "parser.tab.c"
    break;

  case 31:
#line 139 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1921 "parser.tab.c"
    break;

  case 32:
#line 143 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1929 "parser.tab.c"
    break;

  case 33:
#line 146 "parser.y"
                                                  {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    } 
                                                    if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);
                                                    printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 1942 "parser.tab.c"
    break;

  case 34:
#line 154 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }
                                                    if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,yylineno);
                                                    printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 1955 "parser.tab.c"
    break;

  case 35:
#line 162 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1961 "parser.tab.c"
    break;

  case 36:
#line 163 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 1969 "parser.tab.c"
    break;

  case 37:
#line 166 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 1977 "parser.tab.c"
    break;

  case 39:
#line 171 "parser.y"
                        {(yyval.b)= false;}
#line 1983 "parser.tab.c"
    break;

  case 40:
#line 172 "parser.y"
                {(yyval.b) = true;}
#line 1989 "parser.tab.c"
    break;

  case 42:
#line 175 "parser.y"
                                       {pushscope();}
#line 1995 "parser.tab.c"
    break;

  case 43:
#line 175 "parser.y"
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
#line 2010 "parser.tab.c"
    break;

  case 44:
#line 185 "parser.y"
                                                   {pushscope();}
#line 2016 "parser.tab.c"
    break;

  case 45:
#line 185 "parser.y"
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
#line 2031 "parser.tab.c"
    break;

  case 49:
#line 202 "parser.y"
                                        {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s)); add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno);free((yyvsp[0].s));/*duplicated as paramlist does not create var*/}
#line 2037 "parser.tab.c"
    break;

  case 50:
#line 203 "parser.y"
                                        {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s)); add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2043 "parser.tab.c"
    break;

  case 51:
#line 205 "parser.y"
                           {is_static_method = true;}
#line 2049 "parser.tab.c"
    break;

  case 52:
#line 209 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2060 "parser.tab.c"
    break;

  case 53:
#line 217 "parser.y"
                                      {pushscope();}
#line 2066 "parser.tab.c"
    break;

  case 54:
#line 217 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2080 "parser.tab.c"
    break;

  case 55:
#line 227 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2089 "parser.tab.c"
    break;

  case 59:
#line 236 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2095 "parser.tab.c"
    break;

  case 60:
#line 237 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2101 "parser.tab.c"
    break;

  case 62:
#line 240 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2107 "parser.tab.c"
    break;

  case 63:
#line 241 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2113 "parser.tab.c"
    break;

  case 64:
#line 242 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2119 "parser.tab.c"
    break;

  case 65:
#line 243 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2125 "parser.tab.c"
    break;

  case 66:
#line 244 "parser.y"
                        {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2131 "parser.tab.c"
    break;

  case 67:
#line 245 "parser.y"
                    {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2137 "parser.tab.c"
    break;

  case 69:
#line 247 "parser.y"
                      {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2143 "parser.tab.c"
    break;

  case 70:
#line 248 "parser.y"
                         {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2149 "parser.tab.c"
    break;

  case 71:
#line 249 "parser.y"
                       {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2155 "parser.tab.c"
    break;

  case 73:
#line 253 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2161 "parser.tab.c"
    break;

  case 76:
#line 256 "parser.y"
            {printcode("break;");}
#line 2167 "parser.tab.c"
    break;

  case 77:
#line 257 "parser.y"
                {printcode("continue;");}
#line 2173 "parser.tab.c"
    break;

  case 78:
#line 260 "parser.y"
                       {printcode("/*");}
#line 2179 "parser.tab.c"
    break;

  case 79:
#line 260 "parser.y"
                                                                 {printcode("*/");}
#line 2185 "parser.tab.c"
    break;

  case 80:
#line 261 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2191 "parser.tab.c"
    break;

  case 82:
#line 264 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2197 "parser.tab.c"
    break;

  case 83:
#line 266 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2209 "parser.tab.c"
    break;

  case 84:
#line 273 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2221 "parser.tab.c"
    break;

  case 85:
#line 280 "parser.y"
                          {has_returned = true;}
#line 2227 "parser.tab.c"
    break;

  case 86:
#line 283 "parser.y"
                                    {temp_type = (yyvsp[0].t);}
#line 2233 "parser.tab.c"
    break;

  case 87:
#line 283 "parser.y"
                                                               {temp_type = VOID_TYPE;}
#line 2239 "parser.tab.c"
    break;

  case 88:
#line 284 "parser.y"
                              {temp_type = CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2245 "parser.tab.c"
    break;

  case 89:
#line 284 "parser.y"
                                                                                    {temp_type = VOID_TYPE;temp_class=NULL;free((yyvsp[-2].s));}
#line 2251 "parser.tab.c"
    break;

  case 90:
#line 285 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));arr_type=temp_type=CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2257 "parser.tab.c"
    break;

  case 91:
#line 285 "parser.y"
                                                                                                                        {printcode(" ;");free((yyvsp[-2].s));arr_type=temp_type=VOID_TYPE;temp_class= NULL;}
#line 2263 "parser.tab.c"
    break;

  case 92:
#line 286 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2269 "parser.tab.c"
    break;

  case 93:
#line 286 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2275 "parser.tab.c"
    break;

  case 94:
#line 287 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2281 "parser.tab.c"
    break;

  case 95:
#line 287 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2287 "parser.tab.c"
    break;

  case 96:
#line 288 "parser.y"
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
#line 2303 "parser.tab.c"
    break;

  case 98:
#line 302 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2309 "parser.tab.c"
    break;

  case 99:
#line 303 "parser.y"
                          {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2320 "parser.tab.c"
    break;

  case 100:
#line 309 "parser.y"
                 {/*nothing dummymust be kept to maintain arraydecl*/}
#line 2326 "parser.tab.c"
    break;

  case 101:
#line 309 "parser.y"
                                                                                 {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2332 "parser.tab.c"
    break;

  case 102:
#line 310 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2338 "parser.tab.c"
    break;

  case 103:
#line 311 "parser.y"
                                           {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2349 "parser.tab.c"
    break;

  case 104:
#line 317 "parser.y"
                                  {printcode(", ");}
#line 2355 "parser.tab.c"
    break;

  case 105:
#line 317 "parser.y"
                                                               {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2361 "parser.tab.c"
    break;

  case 106:
#line 323 "parser.y"
                     {add_var((yyvsp[(-1) - (1)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2367 "parser.tab.c"
    break;

  case 107:
#line 324 "parser.y"
                         {add_array((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2373 "parser.tab.c"
    break;

  case 108:
#line 325 "parser.y"
                              {add_var((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2379 "parser.tab.c"
    break;

  case 109:
#line 326 "parser.y"
                                      {add_array((yyvsp[(-1) - (5)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2385 "parser.tab.c"
    break;

  case 110:
#line 329 "parser.y"
                                     {create_class_var((yyvsp[(-2) - (2)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2391 "parser.tab.c"
    break;

  case 111:
#line 330 "parser.y"
                                            {create_class_var((yyvsp[(-2) - (4)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2397 "parser.tab.c"
    break;

  case 112:
#line 333 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2405 "parser.tab.c"
    break;

  case 113:
#line 336 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2414 "parser.tab.c"
    break;

  case 114:
#line 340 "parser.y"
                {/*nothing dummy*/}
#line 2420 "parser.tab.c"
    break;

  case 115:
#line 340 "parser.y"
                                              {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2426 "parser.tab.c"
    break;

  case 116:
#line 341 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2434 "parser.tab.c"
    break;

  case 117:
#line 344 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2444 "parser.tab.c"
    break;

  case 118:
#line 349 "parser.y"
                             {printcode(", ");}
#line 2450 "parser.tab.c"
    break;

  case 119:
#line 349 "parser.y"
                                                          {add_array((yyvsp[(-2) - (5)].m),  (yyvsp[(-1) - (5)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2456 "parser.tab.c"
    break;

  case 120:
#line 352 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2467 "parser.tab.c"
    break;

  case 121:
#line 358 "parser.y"
                      {yyerror("Array size missing");}
#line 2473 "parser.tab.c"
    break;

  case 122:
#line 359 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2479 "parser.tab.c"
    break;

  case 123:
#line 359 "parser.y"
                                                                         {printcode(" }");}
#line 2485 "parser.tab.c"
    break;

  case 124:
#line 360 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2491 "parser.tab.c"
    break;

  case 125:
#line 360 "parser.y"
                                                                                                          {printcode(" }");}
#line 2497 "parser.tab.c"
    break;

  case 126:
#line 364 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2503 "parser.tab.c"
    break;

  case 127:
#line 366 "parser.y"
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
#line 2519 "parser.tab.c"
    break;

  case 128:
#line 377 "parser.y"
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
#line 2534 "parser.tab.c"
    break;

  case 129:
#line 388 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
#line 2540 "parser.tab.c"
    break;

  case 130:
#line 389 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2554 "parser.tab.c"
    break;

  case 131:
#line 400 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2560 "parser.tab.c"
    break;

  case 132:
#line 400 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2566 "parser.tab.c"
    break;

  case 133:
#line 401 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2572 "parser.tab.c"
    break;

  case 134:
#line 401 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2578 "parser.tab.c"
    break;

  case 135:
#line 404 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2584 "parser.tab.c"
    break;

  case 136:
#line 405 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2591 "parser.tab.c"
    break;

  case 137:
#line 407 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2598 "parser.tab.c"
    break;

  case 138:
#line 409 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2604 "parser.tab.c"
    break;

  case 139:
#line 409 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2612 "parser.tab.c"
    break;

  case 140:
#line 412 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2618 "parser.tab.c"
    break;

  case 141:
#line 412 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2626 "parser.tab.c"
    break;

  case 142:
#line 415 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2632 "parser.tab.c"
    break;

  case 143:
#line 417 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2638 "parser.tab.c"
    break;

  case 144:
#line 421 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}

                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2649 "parser.tab.c"
    break;

  case 145:
#line 427 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2658 "parser.tab.c"
    break;

  case 146:
#line 432 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2664 "parser.tab.c"
    break;

  case 147:
#line 432 "parser.y"
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
#line 2702 "parser.tab.c"
    break;

  case 151:
#line 472 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2713 "parser.tab.c"
    break;

  case 152:
#line 480 "parser.y"
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
#line 2740 "parser.tab.c"
    break;

  case 153:
#line 505 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 2749 "parser.tab.c"
    break;

  case 154:
#line 511 "parser.y"
                {(yyval.s) = "=";}
#line 2755 "parser.tab.c"
    break;

  case 155:
#line 512 "parser.y"
              {(yyval.s) = "+=";}
#line 2761 "parser.tab.c"
    break;

  case 156:
#line 513 "parser.y"
              {(yyval.s) = "-=";}
#line 2767 "parser.tab.c"
    break;

  case 157:
#line 514 "parser.y"
              {(yyval.s) = "*=";}
#line 2773 "parser.tab.c"
    break;

  case 158:
#line 515 "parser.y"
              {(yyval.s) = "/=";}
#line 2779 "parser.tab.c"
    break;

  case 159:
#line 516 "parser.y"
              {(yyval.s) = "%=";}
#line 2785 "parser.tab.c"
    break;

  case 160:
#line 519 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2791 "parser.tab.c"
    break;

  case 161:
#line 520 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2797 "parser.tab.c"
    break;

  case 162:
#line 521 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2803 "parser.tab.c"
    break;

  case 164:
#line 524 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2809 "parser.tab.c"
    break;

  case 165:
#line 528 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2815 "parser.tab.c"
    break;

  case 166:
#line 532 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2821 "parser.tab.c"
    break;

  case 167:
#line 532 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2827 "parser.tab.c"
    break;

  case 168:
#line 535 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2833 "parser.tab.c"
    break;

  case 169:
#line 535 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2839 "parser.tab.c"
    break;

  case 170:
#line 536 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2845 "parser.tab.c"
    break;

  case 171:
#line 536 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2851 "parser.tab.c"
    break;

  case 172:
#line 537 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2857 "parser.tab.c"
    break;

  case 173:
#line 537 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2863 "parser.tab.c"
    break;

  case 174:
#line 538 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2869 "parser.tab.c"
    break;

  case 175:
#line 538 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2875 "parser.tab.c"
    break;

  case 176:
#line 541 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2881 "parser.tab.c"
    break;

  case 177:
#line 545 "parser.y"
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
#line 2897 "parser.tab.c"
    break;

  case 178:
#line 559 "parser.y"
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
#line 2913 "parser.tab.c"
    break;

  case 179:
#line 572 "parser.y"
                     { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2919 "parser.tab.c"
    break;

  case 180:
#line 573 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2925 "parser.tab.c"
    break;

  case 181:
#line 574 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2931 "parser.tab.c"
    break;

  case 182:
#line 575 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2937 "parser.tab.c"
    break;

  case 183:
#line 576 "parser.y"
                     {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2946 "parser.tab.c"
    break;

  case 184:
#line 580 "parser.y"
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
#line 2962 "parser.tab.c"
    break;

  case 185:
#line 591 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 2968 "parser.tab.c"
    break;

  case 186:
#line 592 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_composite_val =false;}
#line 2974 "parser.tab.c"
    break;

  case 187:
#line 593 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2980 "parser.tab.c"
    break;

  case 188:
#line 594 "parser.y"
                      {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use > with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2986 "parser.tab.c"
    break;

  case 189:
#line 595 "parser.y"
                            {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use <= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2992 "parser.tab.c"
    break;

  case 190:
#line 596 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2998 "parser.tab.c"
    break;

  case 191:
#line 597 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3004 "parser.tab.c"
    break;

  case 192:
#line 598 "parser.y"
                                         {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3010 "parser.tab.c"
    break;

  case 193:
#line 599 "parser.y"
                     {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3016 "parser.tab.c"
    break;

  case 194:
#line 600 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3022 "parser.tab.c"
    break;

  case 195:
#line 601 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3029 "parser.tab.c"
    break;

  case 197:
#line 606 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 3039 "parser.tab.c"
    break;

  case 198:
#line 611 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 3049 "parser.tab.c"
    break;

  case 199:
#line 616 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 3060 "parser.tab.c"
    break;

  case 200:
#line 622 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 3070 "parser.tab.c"
    break;

  case 201:
#line 627 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 3076 "parser.tab.c"
    break;

  case 204:
#line 632 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3088 "parser.tab.c"
    break;

  case 205:
#line 641 "parser.y"
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
#line 3115 "parser.tab.c"
    break;

  case 206:
#line 663 "parser.y"
                     {push_expr_and_args();}
#line 3121 "parser.tab.c"
    break;

  case 207:
#line 663 "parser.y"
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
#line 3153 "parser.tab.c"
    break;

  case 208:
#line 690 "parser.y"
                                             { attr* a = NULL;
                                        if(expr_type == CLASS_TYPE)a = find_attr(expr_class,(yyvsp[0].s));
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[-3].s),(yyvsp[0].s));
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
#line 3179 "parser.tab.c"
    break;

  case 209:
#line 711 "parser.y"
                                                 {push_expr_and_args();}
#line 3185 "parser.tab.c"
    break;

  case 210:
#line 711 "parser.y"
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
#line 3218 "parser.tab.c"
    break;

  case 211:
#line 740 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3224 "parser.tab.c"
    break;


#line 3228 "parser.tab.c"

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
#line 742 "parser.y"


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
