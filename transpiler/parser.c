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
    char * classname;
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
    THIS = 305
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

#line 221 "parser.tab.c"

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
#define YYLAST   1087

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  398

#define YYUNDEFTOK  2
#define YYMAXUTOK   305


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
      62,    63,    13,    11,    64,    12,    66,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       9,    65,    10,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    59,     2,     2,     2,     2,
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
      51,    52,    53,    54,    55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    91,    91,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   105,   106,   107,   111,   112,   113,   116,   117,
     118,   119,   120,   121,   123,   124,   128,   128,   128,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   143,   144,   144,   154,   154,   167,   168,   169,   171,
     172,   174,   178,   186,   186,   196,   201,   202,   203,   205,
     206,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   221,   222,   223,   224,   225,   226,   229,   229,
     230,   232,   233,   235,   242,   249,   252,   253,   254,   254,
     255,   255,   256,   263,   267,   268,   271,   274,   279,   279,
     280,   283,   288,   288,   291,   297,   298,   298,   299,   299,
     303,   305,   313,   321,   322,   330,   330,   331,   331,   334,
     335,   337,   339,   339,   342,   342,   345,   347,   351,   356,
     361,   361,   396,   397,   398,   401,   409,   427,   446,   447,
     448,   449,   450,   451,   454,   455,   456,   456,   459,   463,
     467,   467,   470,   470,   471,   471,   472,   472,   473,   473,
     476,   480,   494,   507,   508,   509,   510,   511,   515,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     537,   539,   541,   546,   551,   557,   562,   563,   564,   581,
     581,   601,   615
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
  "COMMENTLINE", "CLASS", "STATICMETHOD", "THIS", "';'", "'{'", "'}'",
  "'['", "']'", "'('", "')'", "','", "'='", "'.'", "$accept", "program",
  "type", "modifier", "topstmtlist", "topstmt", "rawlist", "classdef",
  "$@1", "$@2", "attrlist", "methodlist", "$@3", "$@4", "methodparamlist",
  "methodparam", "staticdummy", "methoddummy", "fndeclaration", "$@5",
  "fndecldummy", "paramlist", "param", "stmtlist", "stmt", "comment",
  "$@6", "commentlist", "returnstmt", "vardeclaration", "$@7", "$@8",
  "decllist", "varlist", "$@9", "$@10", "arraydecl", "$@11", "$@12",
  "arraysizedummy", "letarraydecl", "letarrvals", "chararrdecllist",
  "$@13", "$@14", "strdecl", "$@15", "$@16", "arrayvallist", "fncall",
  "$@17", "arglist", "arg", "assignstmt", "assgtype", "ifstmt", "$@18",
  "ifdummy", "elsedummy", "whilestmt", "$@19", "forstmt", "$@20", "$@21",
  "$@22", "$@23", "rangecheckdummy", "simplearraydummy", "iterarraydummy",
  "expr", "classcheckdummy", "value", "$@24", "cmplxnum", YY_NULLPTR
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
     299,   300,   301,   302,   303,   304,   305,    59,   123,   125,
      91,    93,    40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF (-261)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-162)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -261,     5,   841,  -261,  -261,  -261,  -261,    31,    69,   -22,
      78,  -261,  -261,    96,   154,  -261,  -261,  -261,  -261,   107,
    -261,  1032,    -3,  -261,   112,  -261,   126,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,  -261,    49,
     148,   150,   927,   831,  -261,    97,  -261,   165,   167,  -261,
    -261,  -261,  -261,   157,   831,   831,   -51,  -261,  -261,  -261,
    -261,   162,   910,  -261,  1070,   156,  -261,  1070,  -261,  -261,
    -261,  -261,  -261,   176,    -2,   194,   213,   251,   251,  -261,
    -261,   212,   211,   224,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   831,   831,   273,   215,  -261,    -4,
     272,   220,   240,   831,   222,   243,  -261,   831,  -261,   831,
     831,  -261,   831,  1070,   202,   202,   248,   248,   248,   248,
     173,   173,   268,   268,   268,   831,   228,   261,   258,    69,
     827,  -261,   249,   827,   257,  1021,   276,  -261,   937,  -261,
    -261,  1070,   949,  -261,     4,   755,   266,     7,  1070,   251,
     238,  1070,   256,  -261,    69,  -261,   277,  -261,   279,  -261,
     827,   280,   282,    16,   -41,    22,   769,   220,   259,   783,
     831,   222,  -261,  -261,   831,  -261,  1070,  -261,   831,  -261,
     831,   827,   274,    91,   113,   285,   275,   111,  -261,   831,
     292,  -261,  -261,   291,   959,   831,  -261,  -261,   278,   290,
    1070,  -261,  -261,  1070,    29,  -261,   297,  -261,   831,  -261,
     163,  -261,  -261,   302,  1070,   303,   296,  -261,   797,  1070,
      37,  -261,   308,  -261,   309,  -261,  1070,  -261,   307,   312,
     310,  -261,   311,  -261,   831,   831,   831,  -261,  -261,   314,
     313,  -261,   319,  -261,  -261,   332,   814,  1070,    66,  1070,
    -261,   321,   320,  -261,  -261,    17,  -261,   342,  -261,  -261,
     831,   831,   -18,  -261,  -261,   337,   831,   831,   831,   331,
     -14,    95,  -261,   348,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,   362,    69,   827,  -261,    54,  -261,   343,
    1070,    75,  -261,  -261,  -261,   -29,   892,  1070,   906,  -261,
    -261,   344,   345,   346,   347,   350,   831,  -261,   831,  -261,
     827,  -261,   372,   373,   831,   359,  -261,   991,   378,  -261,
    -261,   120,  -261,  -261,  -261,  -261,  -261,  1070,  1070,  -261,
     360,   827,    81,  -261,   209,    19,   384,  -261,  -261,  -261,
     381,   389,   388,  -261,  -261,   831,  -261,   385,   398,   363,
     405,   100,  -261,  -261,   392,    82,   394,   831,  -261,   419,
    -261,   831,   447,  -261,  -261,  -261,   190,  -261,   396,  1070,
    -261,   489,   531,   391,  -261,   397,  -261,   426,  -261,  -261,
     831,   402,  -261,  -261,  -261,  1070,  -261,   573,   615,  -261,
     657,  -261,  -261,   403,  -261,  -261,   699,  -261
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    78,    80,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,    93,     0,    81,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    90,    88,    19,     0,
       0,     0,     0,     0,    53,     0,    26,     0,     0,    18,
      25,    87,    94,    86,     0,     0,   188,   185,   186,   183,
     184,     0,     0,   187,   110,   180,   182,    92,    56,    79,
      82,    29,   115,    91,    96,    89,     0,   170,   179,   189,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   181,    12,
       0,     0,     0,     0,     0,     0,    95,     0,   132,     0,
       0,   169,     0,   175,   177,   178,   173,   174,   171,   172,
     163,   164,   165,   166,   167,     0,     0,     0,     0,    12,
       0,    57,     0,     0,     0,     0,     0,    41,     0,   116,
     117,    97,     0,    99,   100,     0,     0,     0,   113,   168,
       0,   176,     0,   191,    12,    58,     0,    30,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,   105,     0,
       0,     0,   190,   131,     0,   133,   135,   111,     0,   192,
       0,     0,    59,     0,     0,     0,     0,     0,    31,     0,
       0,    51,    28,     0,     0,     0,   110,   118,     0,   104,
     101,   103,   134,   114,     0,    55,     0,    32,     0,    35,
       0,    40,    36,     0,   110,     0,     0,   127,     0,   121,
     119,   106,     0,   112,     0,    60,   110,    37,     0,     0,
       0,    42,     0,   110,     0,     0,     0,   110,    61,     0,
       0,    38,     0,    46,    44,     0,     0,   120,     0,   128,
     108,     0,     0,    39,    33,    12,    46,     0,   110,   107,
       0,     0,     0,    76,    77,     0,     0,    84,     0,     0,
      12,     0,    54,    67,    68,    74,    72,    73,    75,    69,
      70,    71,    34,     0,    12,     0,    47,    12,   124,   126,
     129,     0,    63,    65,    64,     0,     0,    83,     0,    24,
      85,     0,     0,     0,     0,     0,     0,   138,     0,    66,
       0,    48,     0,     0,     0,     0,   109,     0,     0,   148,
     150,     0,   139,   140,   141,   142,   143,   110,   136,    52,
      49,     0,     0,   122,   188,     0,     0,    61,    61,    62,
       0,     0,     0,    52,   125,     0,   156,     0,     0,     0,
       0,     0,    61,    50,     0,     0,     0,     0,   162,   144,
     151,     0,     0,    61,   123,    61,   160,   158,   146,   137,
      43,     0,     0,     0,   152,     0,   149,     0,    45,   157,
       0,     0,    61,    61,   147,   160,    61,     0,     0,   154,
       0,   159,   145,     0,   153,    61,     0,   155
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,  -261,    -6,     2,  -261,  -261,  -155,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,   206,   179,  -261,   138,  -261,  -261,
    -261,  -261,   355,  -260,  -261,   487,  -261,  -261,  -261,   490,
    -261,  -261,  -261,  -261,  -261,  -261,   322,  -261,  -261,  -142,
    -261,   315,  -261,  -261,  -261,   324,  -261,  -261,  -259,  -229,
    -261,  -261,   323,  -261,   143,   119,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,   114,  -261,  -261,   -42,
    -261,  -261,  -261,  -261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    37,    14,     2,    15,    39,    16,    71,   137,
     100,   164,   243,   256,   255,   286,   193,   341,    17,    68,
     224,    99,   131,   251,   273,   274,    25,    45,   275,   276,
      48,    47,    53,    75,   104,   171,   143,   236,   261,    97,
      23,   147,    73,   101,   167,   139,   345,   314,   248,    63,
     108,   146,   175,   278,   308,   279,   377,   337,   383,   280,
     338,   281,   381,   393,   356,   375,   374,   346,   367,   249,
     127,    65,   107,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    67,   291,   190,   184,     3,     5,     6,   317,    79,
      21,    80,    77,    78,   191,    41,     5,     6,   192,    22,
      83,   300,   277,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   318,    96,     5,     6,   292,
     293,   294,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   220,   332,    82,    42,   -98,   128,
     129,   141,    43,   103,  -102,   145,   177,   148,   149,   170,
     150,   178,   230,   188,     5,     6,   189,   349,   350,    20,
     283,   284,   194,   151,   239,   347,   355,   195,   223,     5,
       6,   245,   362,   178,   136,   250,   166,   234,    49,    50,
     169,   130,   235,   371,   176,   372,   301,   302,   303,   304,
     305,   301,   302,   303,   304,   305,   289,   313,   284,    24,
     277,   277,   387,   388,   156,   259,   390,   158,   200,   162,
     260,   130,   176,   277,   316,   396,   203,    26,   148,   260,
     344,   364,   277,   277,   321,   260,   260,   214,   207,    69,
      70,   208,   218,   219,   185,   306,   181,    80,   277,   277,
     307,   277,   209,    50,    38,   307,   226,   277,   212,   339,
      50,   213,    27,    28,    44,   205,    29,    30,    31,    32,
      33,    34,    35,    36,    46,   340,    93,    94,    95,    51,
      96,    52,   246,   247,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    72,    96,    74,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   290,    96,
     227,    76,    98,   228,   296,   297,   298,    81,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     102,    96,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   106,    96,   373,   285,   105,    91,
      92,    93,    94,    95,   327,    96,   328,  -161,  -162,    79,
     109,    80,    21,   132,   110,   335,   126,   125,    54,   312,
     138,   140,   142,    55,   144,    96,   285,   111,   112,   285,
      27,    28,   133,   152,    29,    30,    31,    32,    33,    34,
      35,   179,   153,   154,   329,   159,   157,    56,    57,    58,
     134,   135,    59,    60,   180,   366,   -27,   163,   182,   369,
     183,   186,   262,   187,   198,   343,   210,   -27,    62,   173,
     174,   -27,   211,   215,   206,   216,   221,   232,   385,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   263,   264,   265,   266,   222,   267,   268,   225,   269,
     270,     9,   271,   229,   262,   231,   237,   238,   240,   241,
     253,   242,    11,   244,    12,   252,   254,   282,   295,   299,
     272,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   263,   264,   265,   266,   257,   267,   268,
     288,   269,   270,     9,   271,   309,   262,   310,   315,   322,
     323,   324,   325,   330,    11,   326,    12,   333,   331,   336,
     342,   348,   359,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   263,   264,   265,   266,   358,
     267,   268,   351,   269,   270,     9,   271,   352,   262,   353,
     363,   357,   365,   368,   376,   382,    11,   380,    12,   266,
     386,   395,   287,   311,   360,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   263,   264,   265,
     266,   354,   267,   268,   155,   269,   270,     9,   271,    18,
     262,   197,    19,   201,   361,   204,   384,   202,    11,   389,
      12,     0,     0,     0,     0,     0,   370,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   263,
     264,   265,   266,     0,   267,   268,     0,   269,   270,     9,
     271,     0,   262,     0,     0,     0,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,     0,     0,   378,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   263,   264,   265,   266,     0,   267,   268,     0,   269,
     270,     9,   271,     0,   262,     0,     0,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,     0,     0,
     379,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   263,   264,   265,   266,     0,   267,   268,
       0,   269,   270,     9,   271,     0,   262,     0,     0,     0,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
       0,     0,   391,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   263,   264,   265,   266,     0,
     267,   268,     0,   269,   270,     9,   271,     0,   262,     0,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,     0,     0,   392,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   263,   264,   265,
     266,     0,   267,   268,     0,   269,   270,     9,   271,     0,
     262,     0,     0,     0,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,     0,     0,   394,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   263,
     264,   265,   266,     0,   267,   268,     0,   269,   270,     9,
     271,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,     0,     0,   397,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,    96,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    96,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
      96,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,    96,     0,   172,     0,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     196,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    -2,     4,    54,   199,    27,    28,     0,    55,    29,
      30,    31,    32,    33,    34,    35,     0,     0,   233,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,     0,    56,    57,    58,   258,     0,    59,    60,     7,
       8,     9,     0,     0,     0,    10,     0,     0,     0,     0,
       0,     0,    11,    62,    12,    13,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    96,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    54,    96,     0,     0,     0,    55,    27,    28,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    54,
       0,     0,     0,     0,    55,     0,     0,     0,     0,    54,
     319,    56,    57,    58,    55,     0,    59,    60,     0,     0,
       0,    54,     0,     0,   320,     0,    55,     0,    56,    57,
      58,    54,    62,    59,    60,     0,    55,     0,    56,    57,
      58,     0,     0,    59,    60,     0,     0,     0,    61,    62,
      56,    57,    58,     0,     0,    59,    60,     0,   165,    62,
      56,    57,    58,    54,     0,    59,    60,     0,    55,     0,
     168,    62,     0,     0,     0,     0,     0,     0,     0,     0,
     217,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   334,    57,    58,     0,     0,    59,    60,    27,
      28,   160,     0,    29,    30,    31,    32,    33,    34,    35,
      27,    28,     0,    62,    29,    30,    31,    32,    33,    34,
      35,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    96
};

static const yytype_int16 yycheck[] =
{
      42,    43,   261,    44,   159,     0,    20,    21,    37,    60,
       8,    62,    54,    55,    55,    21,    20,    21,    59,    41,
      62,    35,   251,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    64,    17,    20,    21,    57,
      58,    59,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   196,   314,    62,    60,    60,    63,
      64,   103,    65,    65,    60,   107,    59,   109,   110,    65,
     112,    64,   214,    57,    20,    21,    60,   337,   338,    48,
      63,    64,    60,   125,   226,    66,   345,    65,    59,    20,
      21,   233,   352,    64,   100,   237,   138,    60,    49,    50,
     142,    99,    65,   363,   146,   365,    11,    12,    13,    14,
      15,    11,    12,    13,    14,    15,   258,    63,    64,    41,
     349,   350,   382,   383,   130,    59,   386,   133,   170,   135,
      64,   129,   174,   362,    59,   395,   178,    41,   180,    64,
      59,    59,   371,   372,   299,    64,    64,   189,    57,    52,
      53,    60,   194,   195,   160,    60,   154,    62,   387,   388,
      65,   390,    49,    50,    57,    65,   208,   396,    57,    49,
      50,    60,    18,    19,    62,   181,    22,    23,    24,    25,
      26,    27,    28,    29,    58,   327,    13,    14,    15,    41,
      17,    41,   234,   235,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    41,    17,    41,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   260,    17,
      57,    64,    66,    60,   266,   267,   268,    65,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      64,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    41,    17,    66,   255,    64,    11,
      12,    13,    14,    15,   306,    17,   308,    58,    17,    60,
      58,    62,   270,     1,    63,   317,    61,     4,    12,   285,
      60,    41,    60,    17,    41,    17,   284,    63,    64,   287,
      18,    19,    20,    65,    22,    23,    24,    25,    26,    27,
      28,    63,    41,    45,   310,    48,    57,    41,    42,    43,
      38,    39,    46,    47,    58,   357,    44,    41,    41,   361,
      41,    41,     1,    41,    65,   331,    41,    55,    62,    63,
      64,    59,    57,    41,    60,    44,    58,    41,   380,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    65,    35,    36,    61,    38,
      39,    40,    41,    61,     1,    62,    58,    58,    61,    57,
      57,    61,    51,    62,    53,    61,    57,    57,    41,    48,
      59,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    65,    35,    36,
      58,    38,    39,    40,    41,    57,     1,    45,    65,    65,
      65,    65,    65,    41,    51,    65,    53,    58,    45,    41,
      60,    37,    59,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    41,
      35,    36,    61,    38,    39,    40,    41,    58,     1,    61,
      58,    66,    58,    34,    58,    58,    51,    66,    53,    33,
      58,    58,   256,   284,    59,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,   343,    35,    36,   129,    38,    39,    40,    41,     2,
       1,   167,     2,   171,   351,   180,   377,   174,    51,   385,
      53,    -1,    -1,    -1,    -1,    -1,    59,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      59,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    59,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    59,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    59,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    -1,    -1,    -1,    -1,    -1,    59,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    61,    -1,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      61,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    12,    61,    18,    19,    -1,    17,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    61,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    41,    42,    43,    61,    -1,    46,    47,    38,
      39,    40,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    62,    53,    54,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    12,    17,    -1,    -1,    -1,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    12,
      58,    41,    42,    43,    17,    -1,    46,    47,    -1,    -1,
      -1,    12,    -1,    -1,    58,    -1,    17,    -1,    41,    42,
      43,    12,    62,    46,    47,    -1,    17,    -1,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    -1,    61,    62,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    61,    62,
      41,    42,    43,    12,    -1,    46,    47,    -1,    17,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    -1,    -1,    46,    47,    18,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      18,    19,    -1,    62,    22,    23,    24,    25,    26,    27,
      28,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    68,    71,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    70,    72,    74,    85,    92,    96,
      48,    70,    41,   107,    41,    93,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    69,    57,    73,
      41,    69,    60,    65,    62,    94,    58,    98,    97,    49,
      50,    41,    41,    99,    12,    17,    41,    42,    43,    46,
      47,    61,    62,   116,   136,   138,   140,   136,    86,    52,
      53,    75,    41,   109,    41,   100,    64,   136,   136,    60,
      62,    65,    69,   136,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    17,   106,    66,    88,
      77,   110,    64,    65,   101,    64,    41,   139,   117,    58,
      63,    63,    64,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,     4,    61,   137,    63,    64,
      70,    89,     1,    20,    38,    39,    69,    76,    60,   112,
      41,   136,    60,   103,    41,   136,   118,   108,   136,   136,
     136,   136,    65,    41,    45,    89,    69,    57,    69,    48,
      20,    41,    69,    41,    78,    61,   136,   111,    61,   136,
      65,   102,    61,    63,    64,   119,   136,    59,    64,    63,
      58,    70,    41,    41,    73,    69,    41,    41,    57,    60,
      44,    55,    59,    83,    60,    65,    61,   112,    65,    61,
     136,   103,   119,   136,   108,    69,    60,    57,    60,    49,
      41,    57,    57,    60,   136,    41,    44,    61,   136,   136,
     106,    58,    65,    59,    87,    61,   136,    57,    60,    61,
     106,    62,    41,    61,    60,    65,   104,    58,    58,   106,
      61,    57,    61,    79,    62,   106,   136,   136,   115,   136,
     106,    90,    61,    57,    57,    81,    80,    65,    61,    59,
      64,   105,     1,    30,    31,    32,    33,    35,    36,    38,
      39,    41,    59,    91,    92,    95,    96,   116,   120,   122,
     126,   128,    57,    63,    64,    70,    82,    81,    58,   106,
     136,   115,    57,    58,    59,    41,   136,   136,   136,    48,
      35,    11,    12,    13,    14,    15,    60,    65,   121,    57,
      45,    82,    69,    63,   114,    65,    59,    37,    64,    58,
      58,    73,    65,    65,    65,    65,    65,   136,   136,    69,
      41,    45,   115,    58,    41,   136,    41,   124,   127,    49,
     106,    84,    60,    69,    59,   113,   134,    66,    37,    90,
      90,    61,    58,    61,    84,   115,   131,    66,    41,    59,
      59,   121,    90,    58,    59,    58,   136,   135,    34,   136,
      59,    90,    90,    66,   133,   132,    58,   123,    59,    59,
      66,   129,    58,   125,   122,   136,    58,    90,    90,   133,
      90,    59,    59,   130,    59,    58,    90,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    73,    73,    75,    76,    74,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    79,    78,    80,    78,    81,    81,    81,    82,
      82,    83,    84,    86,    85,    87,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    93,    92,
      92,    94,    94,    95,    95,    95,    96,    96,    97,    96,
      98,    96,    96,    96,    99,    99,   100,   100,   101,   100,
     100,   100,   102,   100,   103,   103,   104,   103,   105,   103,
     106,   107,   107,   108,   108,   110,   109,   111,   109,   112,
     112,   112,   113,   112,   114,   112,   112,   112,   115,   115,
     117,   116,   118,   118,   118,   119,   120,   120,   121,   121,
     121,   121,   121,   121,   122,   122,   123,   122,   124,   125,
     127,   126,   129,   128,   130,   128,   131,   128,   132,   128,
     133,   134,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   138,   138,   138,   138,   138,   138,   138,   139,
     138,   138,   140
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     4,     5,     8,     9,     5,     5,     6,     7,     8,
       5,     0,     0,    13,     0,    14,     0,     2,     3,     3,
       5,     1,     0,     0,    13,     0,     0,     2,     3,     3,
       5,     0,     5,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     2,     2,     1,     2,     4,     4,     0,     4,
       0,     4,     4,     2,     1,     3,     1,     3,     0,     3,
       3,     5,     0,     5,     3,     2,     0,     7,     0,     9,
       0,     7,     9,     1,     3,     0,     3,     0,     5,     4,
       6,     4,     0,    13,     0,    11,     8,     4,     1,     3,
       0,     5,     0,     2,     3,     1,     3,     7,     1,     2,
       2,     2,     2,     2,     6,    11,     0,     9,     0,     0,
       0,     6,     0,    12,     0,    15,     0,     9,     0,    11,
       0,     0,     0,     3,     3,     3,     3,     3,     4,     3,
       2,     3,     3,     3,     3,     3,     4,     3,     3,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     4,     5
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
#line 105 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1817 "parser.tab.c"
    break;

  case 16:
#line 112 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1823 "parser.tab.c"
    break;

  case 18:
#line 116 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1829 "parser.tab.c"
    break;

  case 19:
#line 117 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1835 "parser.tab.c"
    break;

  case 20:
#line 118 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1841 "parser.tab.c"
    break;

  case 21:
#line 119 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1847 "parser.tab.c"
    break;

  case 25:
#line 124 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1853 "parser.tab.c"
    break;

  case 26:
#line 128 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1859 "parser.tab.c"
    break;

  case 27:
#line 128 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1865 "parser.tab.c"
    break;

  case 28:
#line 128 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1871 "parser.tab.c"
    break;

  case 31:
#line 132 "parser.y"
                                   {add_attr(current_class,NONE_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);printcode("%s %s;\n",type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1877 "parser.tab.c"
    break;

  case 32:
#line 133 "parser.y"
                                         {add_attr(current_class,CONST_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);printcode("const %s %s;\n",type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1883 "parser.tab.c"
    break;

  case 33:
#line 134 "parser.y"
                                                               {add_attr(current_class,NONE_TYPE,(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s[%s];\n",type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1889 "parser.tab.c"
    break;

  case 34:
#line 135 "parser.y"
                                                                     {add_attr(current_class,CONST_TYPE,(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("const %s %s[%s];\n",type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1895 "parser.tab.c"
    break;

  case 35:
#line 136 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1901 "parser.tab.c"
    break;

  case 36:
#line 137 "parser.y"
                                         {add_attr(current_class,NONE_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);free((yyvsp[-1].s));}
#line 1907 "parser.tab.c"
    break;

  case 37:
#line 138 "parser.y"
                                              {add_attr(current_class,CONST_TYPE,(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);free((yyvsp[-1].s));}
#line 1913 "parser.tab.c"
    break;

  case 38:
#line 139 "parser.y"
                                                {add_attr(current_class,NONE_TYPE,(yyvsp[-4].t),(yyvsp[-3].s),true,yylineno);free((yyvsp[-3].s));}
#line 1919 "parser.tab.c"
    break;

  case 39:
#line 140 "parser.y"
                                                       {add_attr(current_class,CONST_TYPE,(yyvsp[-4].t),(yyvsp[-3].s),true,yylineno);free((yyvsp[-3].s));}
#line 1925 "parser.tab.c"
    break;

  case 40:
#line 141 "parser.y"
                                                        {add_class_type_attr(current_class,NONE_TYPE,(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);free((yyvsp[-2].s));free((yyvsp[-1].s));}
#line 1931 "parser.tab.c"
    break;

  case 42:
#line 144 "parser.y"
                                       {pushscope();}
#line 1937 "parser.tab.c"
    break;

  case 43:
#line 144 "parser.y"
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
#line 1952 "parser.tab.c"
    break;

  case 44:
#line 154 "parser.y"
                                                   {pushscope();}
#line 1958 "parser.tab.c"
    break;

  case 45:
#line 154 "parser.y"
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
#line 1973 "parser.tab.c"
    break;

  case 49:
#line 171 "parser.y"
                                        {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s)); create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno);free((yyvsp[0].s));}
#line 1979 "parser.tab.c"
    break;

  case 50:
#line 172 "parser.y"
                                        {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s)); add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 1985 "parser.tab.c"
    break;

  case 51:
#line 174 "parser.y"
                           {is_static_method = true;}
#line 1991 "parser.tab.c"
    break;

  case 52:
#line 178 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2002 "parser.tab.c"
    break;

  case 53:
#line 186 "parser.y"
                                      {pushscope();}
#line 2008 "parser.tab.c"
    break;

  case 54:
#line 186 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2022 "parser.tab.c"
    break;

  case 55:
#line 196 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2031 "parser.tab.c"
    break;

  case 59:
#line 205 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2037 "parser.tab.c"
    break;

  case 60:
#line 206 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2043 "parser.tab.c"
    break;

  case 62:
#line 209 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2049 "parser.tab.c"
    break;

  case 63:
#line 210 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2055 "parser.tab.c"
    break;

  case 64:
#line 211 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2061 "parser.tab.c"
    break;

  case 65:
#line 212 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2067 "parser.tab.c"
    break;

  case 66:
#line 213 "parser.y"
                        {expr_type= VOID_TYPE;}
#line 2073 "parser.tab.c"
    break;

  case 67:
#line 214 "parser.y"
                    {yyerror("missing ;");expr_type =  VOID_TYPE;}
#line 2079 "parser.tab.c"
    break;

  case 73:
#line 222 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2085 "parser.tab.c"
    break;

  case 76:
#line 225 "parser.y"
            {printcode("break;");}
#line 2091 "parser.tab.c"
    break;

  case 77:
#line 226 "parser.y"
                {printcode("continue;");}
#line 2097 "parser.tab.c"
    break;

  case 78:
#line 229 "parser.y"
                       {printcode("/*");}
#line 2103 "parser.tab.c"
    break;

  case 79:
#line 229 "parser.y"
                                                                 {printcode("*/");}
#line 2109 "parser.tab.c"
    break;

  case 80:
#line 230 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2115 "parser.tab.c"
    break;

  case 82:
#line 233 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2121 "parser.tab.c"
    break;

  case 83:
#line 235 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2133 "parser.tab.c"
    break;

  case 84:
#line 242 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2145 "parser.tab.c"
    break;

  case 85:
#line 249 "parser.y"
                          {has_returned = true;}
#line 2151 "parser.tab.c"
    break;

  case 87:
#line 253 "parser.y"
                                          {create_class_var((yyvsp[-2].m),(yyvsp[-1].s),(yyvsp[0].s),yylineno);}
#line 2157 "parser.tab.c"
    break;

  case 88:
#line 254 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2163 "parser.tab.c"
    break;

  case 89:
#line 254 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2169 "parser.tab.c"
    break;

  case 90:
#line 255 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2175 "parser.tab.c"
    break;

  case 91:
#line 255 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2181 "parser.tab.c"
    break;

  case 92:
#line 256 "parser.y"
                              {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",(yyvsp[-2].s));
            }else{
                add_var(NONE_TYPE,expr_type,(yyvsp[-2].s),yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],(yyvsp[-2].s),(yyvsp[0].s));
            }
            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2193 "parser.tab.c"
    break;

  case 94:
#line 267 "parser.y"
                     {create_var((yyvsp[(-1) - (1)].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2199 "parser.tab.c"
    break;

  case 95:
#line 268 "parser.y"
                              {create_var((yyvsp[(-1) - (3)].m),(yyvsp[-3].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2205 "parser.tab.c"
    break;

  case 96:
#line 271 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2213 "parser.tab.c"
    break;

  case 97:
#line 274 "parser.y"
                          {  //asm("int3");
                                if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2223 "parser.tab.c"
    break;

  case 98:
#line 279 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 2229 "parser.tab.c"
    break;

  case 99:
#line 279 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 2235 "parser.tab.c"
    break;

  case 100:
#line 280 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2243 "parser.tab.c"
    break;

  case 101:
#line 283 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2253 "parser.tab.c"
    break;

  case 102:
#line 288 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 2259 "parser.tab.c"
    break;

  case 103:
#line 288 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 2265 "parser.tab.c"
    break;

  case 104:
#line 291 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2276 "parser.tab.c"
    break;

  case 105:
#line 297 "parser.y"
                      {yyerror("Array size missing");}
#line 2282 "parser.tab.c"
    break;

  case 106:
#line 298 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2288 "parser.tab.c"
    break;

  case 107:
#line 298 "parser.y"
                                                                         {printcode(" }");}
#line 2294 "parser.tab.c"
    break;

  case 108:
#line 299 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2300 "parser.tab.c"
    break;

  case 109:
#line 299 "parser.y"
                                                                                                          {printcode(" }");}
#line 2306 "parser.tab.c"
    break;

  case 110:
#line 303 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2312 "parser.tab.c"
    break;

  case 111:
#line 305 "parser.y"
                                                        {if(arr_type == VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-6].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-6].s), yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2325 "parser.tab.c"
    break;

  case 112:
#line 313 "parser.y"
                                                                    {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-8].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-8].s), yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }expr_type = VOID_TYPE;
                                                            free((yyvsp[-8].s));free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2337 "parser.tab.c"
    break;

  case 113:
#line 321 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}}
#line 2343 "parser.tab.c"
    break;

  case 114:
#line 322 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2355 "parser.tab.c"
    break;

  case 115:
#line 330 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2361 "parser.tab.c"
    break;

  case 116:
#line 330 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2367 "parser.tab.c"
    break;

  case 117:
#line 331 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2373 "parser.tab.c"
    break;

  case 118:
#line 331 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2379 "parser.tab.c"
    break;

  case 119:
#line 334 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2385 "parser.tab.c"
    break;

  case 120:
#line 335 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2392 "parser.tab.c"
    break;

  case 121:
#line 337 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2399 "parser.tab.c"
    break;

  case 122:
#line 339 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2405 "parser.tab.c"
    break;

  case 123:
#line 339 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2413 "parser.tab.c"
    break;

  case 124:
#line 342 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2419 "parser.tab.c"
    break;

  case 125:
#line 342 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2427 "parser.tab.c"
    break;

  case 126:
#line 345 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2433 "parser.tab.c"
    break;

  case 127:
#line 347 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2439 "parser.tab.c"
    break;

  case 128:
#line 351 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2449 "parser.tab.c"
    break;

  case 129:
#line 356 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2458 "parser.tab.c"
    break;

  case 130:
#line 361 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2464 "parser.tab.c"
    break;

  case 131:
#line 361 "parser.y"
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
#line 2502 "parser.tab.c"
    break;

  case 135:
#line 401 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2513 "parser.tab.c"
    break;

  case 136:
#line 409 "parser.y"
                                      {Variable *var = lookup_var((yyvsp[-2].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-2].s));
                                    }else if(var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t.t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t.t],type_arr[expr_type]);
                                    }else if(var->t.t == COMPLEX_TYPE && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }else{
                                        printcode("%s %s %s;",(yyvsp[-2].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    }
                                    // No need to free $2, its const char *
                                    free((yyvsp[-2].s));free((yyvsp[0].s));
                                    expr_type = VOID_TYPE;
                                    }
#line 2536 "parser.tab.c"
    break;

  case 137:
#line 427 "parser.y"
                                                                  {Variable *var = lookup_var((yyvsp[-6].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-6].s));
                                    }else if(!var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t.t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t.t],type_arr[expr_type]);
                                    }else if((var->t.t == COMPLEX_TYPE || var->t.t == FLOAT || var->t.t == DOUBLE_TYPE) && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on %s type",type_arr[var->t.t]);
                                    }else{
                                        printcode("%s[%s] %s %s;",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    }
                                    expr_type = VOID_TYPE;
                                    // No need to free $2, its const char *
                                    free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2558 "parser.tab.c"
    break;

  case 138:
#line 446 "parser.y"
                {(yyval.s) = "=";}
#line 2564 "parser.tab.c"
    break;

  case 139:
#line 447 "parser.y"
              {(yyval.s) = "+=";}
#line 2570 "parser.tab.c"
    break;

  case 140:
#line 448 "parser.y"
              {(yyval.s) = "-=";}
#line 2576 "parser.tab.c"
    break;

  case 141:
#line 449 "parser.y"
              {(yyval.s) = "*=";}
#line 2582 "parser.tab.c"
    break;

  case 142:
#line 450 "parser.y"
              {(yyval.s) = "/=";}
#line 2588 "parser.tab.c"
    break;

  case 143:
#line 451 "parser.y"
              {(yyval.s) = "%=";}
#line 2594 "parser.tab.c"
    break;

  case 144:
#line 454 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2600 "parser.tab.c"
    break;

  case 145:
#line 455 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2606 "parser.tab.c"
    break;

  case 146:
#line 456 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2612 "parser.tab.c"
    break;

  case 148:
#line 459 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2618 "parser.tab.c"
    break;

  case 149:
#line 463 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2624 "parser.tab.c"
    break;

  case 150:
#line 467 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2630 "parser.tab.c"
    break;

  case 151:
#line 467 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2636 "parser.tab.c"
    break;

  case 152:
#line 470 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2642 "parser.tab.c"
    break;

  case 153:
#line 470 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2648 "parser.tab.c"
    break;

  case 154:
#line 471 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2654 "parser.tab.c"
    break;

  case 155:
#line 471 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2660 "parser.tab.c"
    break;

  case 156:
#line 472 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2666 "parser.tab.c"
    break;

  case 157:
#line 472 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2672 "parser.tab.c"
    break;

  case 158:
#line 473 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2678 "parser.tab.c"
    break;

  case 159:
#line 473 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2684 "parser.tab.c"
    break;

  case 160:
#line 476 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2690 "parser.tab.c"
    break;

  case 161:
#line 480 "parser.y"
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
#line 2706 "parser.tab.c"
    break;

  case 162:
#line 494 "parser.y"
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
#line 2722 "parser.tab.c"
    break;

  case 163:
#line 507 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2728 "parser.tab.c"
    break;

  case 164:
#line 508 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2734 "parser.tab.c"
    break;

  case 165:
#line 509 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2740 "parser.tab.c"
    break;

  case 166:
#line 510 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2746 "parser.tab.c"
    break;

  case 167:
#line 511 "parser.y"
                     {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2755 "parser.tab.c"
    break;

  case 168:
#line 515 "parser.y"
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
#line 2770 "parser.tab.c"
    break;

  case 169:
#line 525 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 2776 "parser.tab.c"
    break;

  case 170:
#line 526 "parser.y"
                            {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_composite_val =false;}
#line 2782 "parser.tab.c"
    break;

  case 171:
#line 527 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with complex type");}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2788 "parser.tab.c"
    break;

  case 172:
#line 528 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use > with complex type");}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2794 "parser.tab.c"
    break;

  case 173:
#line 529 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use <= with complex type");}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2800 "parser.tab.c"
    break;

  case 174:
#line 530 "parser.y"
                              {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with complex type");}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2806 "parser.tab.c"
    break;

  case 175:
#line 531 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2812 "parser.tab.c"
    break;

  case 176:
#line 532 "parser.y"
                                          {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2818 "parser.tab.c"
    break;

  case 177:
#line 533 "parser.y"
                    {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2824 "parser.tab.c"
    break;

  case 178:
#line 534 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2830 "parser.tab.c"
    break;

  case 179:
#line 535 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2837 "parser.tab.c"
    break;

  case 181:
#line 539 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 2843 "parser.tab.c"
    break;

  case 182:
#line 541 "parser.y"
                 {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2853 "parser.tab.c"
    break;

  case 183:
#line 546 "parser.y"
             {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 2863 "parser.tab.c"
    break;

  case 184:
#line 551 "parser.y"
               { if( expr_type == STRING_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 2874 "parser.tab.c"
    break;

  case 185:
#line 557 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 2884 "parser.tab.c"
    break;

  case 186:
#line 562 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 2890 "parser.tab.c"
    break;

  case 188:
#line 564 "parser.y"
                 { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
                    }else if(_t->is_class){
                        expr_type = CLASS_TYPE;
                        classname = _t->t.class;
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
#line 2912 "parser.tab.c"
    break;

  case 189:
#line 581 "parser.y"
                     {push_expr_and_args();}
#line 2918 "parser.tab.c"
    break;

  case 190:
#line 581 "parser.y"
                                                      { Variable *v = lookup_var((yyvsp[-4].s));
                                                        if(v == NULL){
                                                            yyerror("Undefined variable %s",(yyval.s));
                                                        }else if(!v->is_arr && v->t.t != STRING_TYPE){
                                                            yyerror("Subscripted object must be of array or string type. got %s type",type_arr[v->t.t]);
                                                        }else if(expr_type != INT_TYPE){
                                                            yyerror("Subscript must be of int type got %s type",type_arr[expr_type]);
                                                        }
                                                        char *t = join((yyvsp[-4].s),"[",(yyvsp[-1].s));(yyval.s) = join(t,"]","");is_composite_val = true;pop_expr_and_args();free(t);
                                                        if(v != NULL){
                                                            if( expr_type == STRING_TYPE){
                                                                yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[v->t.t],type_arr[expr_type]);;
                                                            }else if(v->t.t ==COMPLEX_TYPE){
                                                                expr_type = COMPLEX_TYPE;
                                                            }else if(v->t.t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                                                                expr_type = FLOAT_TYPE;
                                                            }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                                                                expr_type = v->t.t;
                                                            }
                                                        }free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2943 "parser.tab.c"
    break;

  case 191:
#line 601 "parser.y"
                                           { attr* a = find_attr(classname,(yyvsp[0].s));    
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[-3].s),(yyvsp[0].s));
                                        }else{
                                            if(a->is_class){
                                                expr_type = CLASS_TYPE;
                                                classname = a->t.class;
                                            }else{expr_type = a->t.t;}
                                            
                                        }
                                        (yyval.s) = join((yyvsp[-3].s),".",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));
                                    }
#line 2960 "parser.tab.c"
    break;

  case 192:
#line 615 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2972 "parser.tab.c"
    break;


#line 2976 "parser.tab.c"

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
#line 623 "parser.y"


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
