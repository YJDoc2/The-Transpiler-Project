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
#define YYLAST   1132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  80
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  408

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
     138,   139,   143,   146,   153,   160,   161,   164,   168,   169,
     171,   172,   172,   182,   182,   195,   196,   197,   199,   200,
     202,   206,   214,   214,   224,   229,   230,   231,   233,   234,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   249,   250,   251,   252,   253,   254,   257,   257,   258,
     260,   261,   263,   270,   277,   280,   281,   282,   282,   283,
     283,   284,   284,   285,   292,   296,   297,   298,   299,   301,
     302,   305,   308,   312,   312,   313,   316,   321,   321,   324,
     330,   331,   331,   332,   332,   336,   338,   346,   354,   355,
     363,   363,   364,   364,   367,   368,   370,   372,   372,   375,
     375,   378,   380,   384,   389,   394,   394,   429,   430,   431,
     434,   442,   465,   471,   472,   473,   474,   475,   476,   479,
     480,   481,   481,   484,   488,   492,   492,   495,   495,   496,
     496,   497,   497,   498,   498,   501,   505,   519,   532,   533,
     534,   535,   536,   540,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   563,   566,   571,   576,   582,
     587,   588,   589,   592,   614,   614,   641,   661,   661,   689,
     692
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
  "assigndummy", "assgtype", "ifstmt", "$@19", "ifdummy", "elsedummy",
  "whilestmt", "$@20", "forstmt", "$@21", "$@22", "$@23", "$@24",
  "rangecheckdummy", "simplearraydummy", "iterarraydummy", "expr", "value",
  "varvals", "$@25", "$@26", "classcheckdummy", "cmplxnum", YY_NULLPTR
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

#define YYPACT_NINF (-278)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-167)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -278,     4,   904,  -278,  -278,  -278,  -278,   -38,    21,    19,
      29,  -278,  -278,    53,   890,  -278,  -278,  -278,  -278,    50,
    -278,  1038,   -54,  -278,    51,  -278,    64,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
     104,    93,   103,   275,    49,  -278,   124,  -278,   119,   128,
     148,  -278,  -278,  -278,  -278,   114,    49,    49,    41,  -278,
    -278,  -278,  -278,   126,   978,  -278,  1100,  -278,   127,  -278,
    1100,  -278,  -278,  -278,  -278,  -278,   130,   135,   132,   -22,
     133,   159,   184,   184,  -278,  -278,   157,   154,   215,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,   229,   172,  -278,    -2,   760,   174,   195,    49,   199,
      49,   192,   228,  -278,    49,  -278,    49,    49,  -278,    49,
    1100,  1111,  1111,    71,    71,    71,    71,    15,    15,   254,
     254,   254,    49,   206,   232,   230,    21,   317,  -278,   216,
     235,    21,  1059,  -278,   748,  -278,  -278,  1100,   217,  1100,
     996,  -278,   -21,   817,   264,    33,  1100,   184,   251,  1100,
     218,   223,    21,  -278,   245,  -278,  -278,  1075,   247,   248,
     -17,    56,   831,   174,   233,    49,   224,   845,    49,   192,
    -278,  -278,    49,  -278,  1100,  -278,    49,  -278,    49,  -278,
     317,   236,   136,   250,   255,   -50,    66,   257,  -278,  -278,
     258,  1006,    49,  -278,  -278,  -278,  1100,   240,   242,  1100,
    -278,  -278,  1100,    60,    49,  -278,   239,  -278,   252,   252,
    -278,    49,  -278,    49,   246,   273,  -278,   859,  1100,    72,
     261,  -278,   260,  -278,  1100,   265,  -278,   263,   262,   272,
    1100,  1100,  -278,   269,  -278,    49,    49,  -278,    49,  -278,
     284,  -278,  -278,  -278,  -278,   302,   305,  -278,  -278,   268,
     877,  1100,    61,  1100,  -278,  -278,   330,   314,   315,    14,
    -278,   316,  -278,  -278,    49,    49,   123,  -278,  -278,   335,
      49,    49,    49,   329,   -15,  -278,   320,  -278,  -278,  -278,
    -278,  -278,  -278,  -278,  -278,   127,  -278,  -278,   334,    21,
     317,  -278,    16,  -278,   318,  1100,    86,  -278,  -278,  -278,
     -34,   958,  1100,   972,  -278,  -278,  -278,    11,   317,  -278,
     339,   337,    49,   326,  -278,  1033,   345,  -278,  -278,   138,
     322,   323,   341,   344,   349,  -278,    49,  -278,   355,   317,
      87,  -278,   109,   200,   381,  -278,  -278,  -278,  -278,  -278,
    -278,  -278,  -278,  1100,   360,   358,  -278,  -278,    49,  -278,
     354,   382,   373,   416,  -278,  -278,   363,    97,   366,    49,
    -278,   393,  -278,   459,  -278,  -278,  -278,   237,  -278,   369,
    -278,   502,   545,   362,  -278,   372,  -278,   399,  -278,  -278,
      49,   391,  -278,  -278,  -278,  1100,  -278,   588,   631,  -278,
     674,  -278,  -278,   394,  -278,  -278,   717,  -278
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
       0,    18,    25,    86,    99,    85,     0,     0,   193,   189,
     190,   187,   188,     0,     0,   191,   115,   185,   192,   186,
      93,    55,    78,    81,    29,   120,    92,    95,    88,   101,
      90,     0,   175,   184,   194,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,    12,     0,     0,     0,     0,     0,
       0,     0,     0,   100,     0,   137,     0,     0,   174,     0,
     180,   182,   183,   178,   179,   176,   177,   168,   169,   170,
     171,   172,     0,     0,     0,     0,    12,     0,    56,     0,
       0,    12,     0,    40,     0,   121,   122,   115,    97,   102,
       0,   104,   105,     0,     0,     0,   118,   173,     0,   181,
       0,   196,    12,    57,     0,    30,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
     195,   136,     0,   138,   140,   116,     0,   200,     0,   197,
       0,    58,     0,     0,     0,     0,     0,     0,    50,    28,
       0,     0,     0,   115,   123,    96,   115,     0,   109,   106,
     108,   139,   119,     0,     0,    54,     0,    35,    38,    38,
      33,     0,    31,     0,     0,     0,   132,     0,   126,   124,
       0,   111,     0,   117,   115,     0,    59,     0,     0,     0,
     115,   115,    41,     0,   115,     0,     0,    98,     0,   115,
       0,    60,    39,    37,    36,     0,     0,    45,    43,     0,
       0,   125,     0,   133,   113,   198,     0,     0,     0,    12,
      45,     0,   115,   112,     0,     0,     0,    75,    76,     0,
       0,    83,     0,     0,    12,    53,    66,    67,    73,    71,
      72,    74,    68,    69,    70,   142,    34,    32,     0,    12,
       0,    46,    12,   129,   131,   134,     0,    62,    64,    63,
       0,     0,    82,     0,    24,    84,    65,     0,     0,    47,
       0,     0,     0,     0,   114,     0,     0,   153,   155,     0,
       0,     0,     0,     0,     0,   143,     0,    51,    48,     0,
       0,   127,   193,     0,     0,    60,    60,    61,   144,   145,
     146,   147,   148,   141,     0,     0,    51,   130,     0,   161,
       0,     0,     0,     0,    60,    49,     0,     0,     0,     0,
     167,   149,   156,     0,    60,   128,    60,   165,   163,   151,
      42,     0,     0,     0,   157,     0,   154,     0,    44,   162,
       0,     0,    60,    60,   152,   165,    60,     0,     0,   159,
       0,   164,   150,     0,   158,    60,     0,   160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -278,  -278,    -6,     1,  -278,  -278,  -164,  -278,  -278,  -278,
    -278,   243,  -278,  -278,  -278,   188,   160,  -278,   105,  -278,
    -278,  -278,  -278,   327,  -277,  -278,   462,  -278,  -278,  -278,
     463,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,   287,
    -278,  -278,  -131,  -278,   280,  -278,  -278,  -278,   297,  -278,
    -278,  -258,  -233,  -278,  -278,   289,  -278,  -278,  -278,    85,
    -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,  -278,
      79,  -278,  -278,   -43,  -278,  -207,  -278,  -278,  -278,  -278
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    74,   143,
     105,   238,   170,   257,   270,   269,   301,   200,   354,    17,
      71,   235,   104,   138,   266,   286,   287,    25,    46,   288,
     289,    49,    50,    48,    78,    55,    80,   111,   179,   151,
     248,   275,   102,    23,   155,    76,   106,   173,   145,   358,
     322,   262,    65,   115,   154,   183,   291,   317,   336,   292,
     387,   345,   393,   293,   346,   294,   391,   403,   368,   385,
     384,   359,   378,   263,    67,    68,   114,   214,   134,    69
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    70,   192,   325,     3,     5,     6,    43,   220,    21,
      20,   221,    44,    82,    83,    42,   174,   306,     5,     6,
     315,    88,   330,   331,   332,   333,   334,   197,    98,    99,
     100,   326,   101,   290,     5,     6,     5,     6,   198,  -103,
    -107,     5,     6,   199,   110,   178,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,    87,   295,
      22,    56,   135,   136,   340,   147,    57,   149,   362,   363,
      24,   153,   229,   156,   157,   230,   158,   335,   298,   299,
     321,   299,    96,    97,    98,    99,   100,   373,   101,   159,
      58,    59,    60,   185,    26,    61,    62,   381,   186,   382,
     367,   172,    84,   250,    85,   137,   142,   177,    39,   255,
     256,   184,    64,   259,    45,   397,   398,   201,   264,   400,
     233,   273,   202,    47,   222,   186,   274,   223,   406,   290,
     290,   164,   206,   245,    53,   209,   169,   137,   246,   184,
     290,   304,   167,   212,    54,   156,   324,   357,   290,   290,
     329,   274,   274,    51,    52,   295,   295,   375,   227,   228,
      75,   194,   274,   190,   290,   290,   295,   290,  -166,    77,
      84,   234,    85,   290,   295,   295,    72,    73,   240,    81,
     241,   307,   308,   309,   215,   217,    52,   347,    52,    79,
     295,   295,    86,   295,   103,   107,   108,   109,   112,   295,
     113,  -167,   260,   261,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   116,   101,   117,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   305,   101,   132,   133,   144,   146,   311,   312,   313,
     148,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   150,   101,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   360,   101,   152,
     300,   101,   160,   161,   165,   162,    56,   188,   175,   118,
     119,    57,   343,   166,   189,    21,   191,    56,   195,   196,
     207,   218,    57,   353,   320,   205,   219,   216,   224,   231,
     300,   236,   225,   300,   383,    58,    59,    60,   232,   242,
      61,    62,   337,   237,   243,   187,    58,    59,    60,   249,
     253,    61,    62,   247,   251,   252,   377,    64,   181,   182,
     254,   276,   258,   356,   271,    27,    28,    63,    64,    29,
      30,    31,    32,    33,    34,    35,   265,   395,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     277,   278,   279,   280,   267,   281,   282,   268,   283,   284,
       9,    58,   296,   297,   276,   303,   310,   314,   316,   318,
     338,    11,   339,    12,   323,   341,   344,   -12,   348,   349,
     285,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   277,   278,   279,   280,   350,   281,   282,
     351,   283,   284,     9,    58,   352,   355,   276,   361,   364,
     365,   369,   374,   370,    11,   376,    12,   379,   386,   390,
     -12,   392,   280,   371,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   277,   278,   279,   280,
     396,   281,   282,   405,   283,   284,     9,    58,   302,   319,
     276,   366,   239,   163,    18,    19,   210,    11,   213,    12,
     204,   211,   394,   -12,   399,     0,   372,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   277,
     278,   279,   280,     0,   281,   282,     0,   283,   284,     9,
      58,     0,     0,   276,     0,     0,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,   -12,     0,     0,   380,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   277,   278,   279,   280,     0,   281,   282,     0,
     283,   284,     9,    58,     0,     0,   276,     0,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,   -12,
       0,     0,   388,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   277,   278,   279,   280,     0,
     281,   282,     0,   283,   284,     9,    58,     0,     0,   276,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,   -12,     0,     0,   389,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   277,   278,
     279,   280,     0,   281,   282,     0,   283,   284,     9,    58,
       0,     0,   276,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,     0,   -12,     0,     0,   401,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   277,   278,   279,   280,     0,   281,   282,     0,   283,
     284,     9,    58,     0,     0,   276,     0,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,   -12,     0,
       0,   402,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   277,   278,   279,   280,     0,   281,
     282,     0,   283,   284,     9,    58,     0,     0,   276,     0,
       0,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,   -12,     0,     0,   404,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   277,   278,   279,
     280,     0,   281,   282,     0,   283,   284,     9,    58,     0,
      56,   139,     0,     0,     0,    57,     0,     0,    11,     0,
      12,     0,     0,     0,   -12,     0,     0,   407,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,    58,
      59,    60,     0,     0,    61,    62,     0,     0,   140,   141,
       0,     0,     0,     0,   -27,     0,     0,     0,     0,     0,
     171,    64,     0,     0,     0,   -27,     0,   -12,     0,     0,
     -27,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,   101,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,   101,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,   101,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,   101,     0,     0,   180,
       0,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   203,   101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -2,     4,     0,   208,    27,    28,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,   244,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,     0,     0,     0,     0,     0,   272,
       0,     0,     7,     8,     9,     0,     0,    37,    10,     0,
       0,     0,     0,     0,     0,    11,     0,    12,    13,     0,
       0,   -12,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     0,   101,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     0,   101,
      56,     0,     0,     0,     0,    57,    27,    28,     0,     0,
      29,    30,    31,    32,    33,    34,    35,     0,    56,     0,
       0,     0,     0,    57,     0,     0,     0,   327,    56,    58,
      59,    60,     0,    57,    61,    62,     0,     0,     0,     0,
       0,   328,     0,     0,     0,     0,     0,    58,    59,    60,
       0,    64,    61,    62,     0,    56,     0,    58,    59,    60,
      57,     0,    61,    62,     0,     0,    27,    28,   176,    64,
      29,    30,    31,    32,    33,    34,    35,     0,   226,    64,
       0,     0,     0,     0,   342,    59,    60,    27,    28,    61,
      62,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,     0,     0,    27,    28,    41,    64,    29,    30,    31,
      32,    33,    34,    35,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   168,   101,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,   101,     0,
       0,     0,   193
};

static const yytype_int16 yycheck[] =
{
      43,    44,   166,    37,     0,    20,    21,    61,    58,     8,
      48,    61,    66,    56,    57,    21,   147,   275,    20,    21,
      35,    64,    11,    12,    13,    14,    15,    44,    13,    14,
      15,    65,    17,   266,    20,    21,    20,    21,    55,    61,
      61,    20,    21,    60,    66,    66,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    64,   266,
      41,    12,    64,    65,   322,   108,    17,   110,   345,   346,
      41,   114,   203,   116,   117,   206,   119,    66,    64,    65,
      64,    65,    11,    12,    13,    14,    15,   364,    17,   132,
      41,    42,    43,    60,    41,    46,    47,   374,    65,   376,
     358,   144,    61,   234,    63,   104,   105,   150,    58,   240,
     241,   154,    63,   244,    63,   392,   393,    61,   249,   396,
      60,    60,    66,    59,    58,    65,    65,    61,   405,   362,
     363,   137,   175,    61,    41,   178,   142,   136,    66,   182,
     373,   272,   141,   186,    41,   188,    60,    60,   381,   382,
     314,    65,    65,    49,    50,   362,   363,    60,   201,   202,
      41,   167,    65,   162,   397,   398,   373,   400,    59,    41,
      61,   214,    63,   406,   381,   382,    52,    53,   221,    65,
     223,    58,    59,    60,   190,    49,    50,    49,    50,    41,
     397,   398,    66,   400,    67,    65,    61,    65,    65,   406,
      41,    17,   245,   246,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    59,    17,    64,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   274,    17,     4,    62,    61,    41,   280,   281,   282,
      41,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    61,    17,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    67,    17,    41,
     269,    17,    66,    41,    58,    45,    12,    59,    61,    64,
      65,    17,   325,    48,    61,   284,    41,    12,    41,    41,
      66,    41,    17,   336,   300,    62,    41,    61,    41,    59,
     299,    62,    44,   302,    67,    41,    42,    43,    66,    63,
      46,    47,   318,    61,    41,    64,    41,    42,    43,    59,
      58,    46,    47,    62,    59,    62,   369,    63,    64,    65,
      58,     1,    63,   339,    66,    18,    19,    62,    63,    22,
      23,    24,    25,    26,    27,    28,    62,   390,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    62,    35,    36,    62,    38,    39,
      40,    41,    58,    58,     1,    59,    41,    48,    58,    45,
      41,    51,    45,    53,    66,    59,    41,    57,    66,    66,
      60,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    66,    35,    36,
      66,    38,    39,    40,    41,    66,    61,     1,    37,    59,
      62,    67,    59,    41,    51,    59,    53,    34,    59,    67,
      57,    59,    33,    60,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      59,    35,    36,    59,    38,    39,    40,    41,   270,   299,
       1,   356,   219,   136,     2,     2,   179,    51,   188,    53,
     173,   182,   387,    57,   395,    -1,    60,    18,    19,    20,
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
      39,    40,    41,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,    -1,
      -1,    60,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    57,    -1,    -1,    60,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
      12,     1,    -1,    -1,    -1,    17,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    60,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    55,    -1,    57,    -1,    -1,
      60,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    62,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    62,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,     1,    -1,    62,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
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
      17,    -1,    46,    47,    -1,    -1,    18,    19,    62,    63,
      22,    23,    24,    25,    26,    27,    28,    -1,    62,    63,
      -1,    -1,    -1,    -1,    41,    42,    43,    18,    19,    46,
      47,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    18,    19,    57,    63,    22,    23,    24,
      25,    26,    27,    28,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    57,    17,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    57
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
      43,    46,    47,    62,    63,   120,   141,   142,   143,   147,
     141,    88,    52,    53,    76,    41,   113,    41,   102,    41,
     104,    65,   141,   141,    61,    63,    66,    70,   141,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    17,   110,    67,    90,    78,   114,    65,    61,    65,
      66,   105,    65,    41,   144,   121,    59,    64,    64,    65,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,     4,    62,   146,    64,    65,    71,    91,     1,
      38,    39,    71,    77,    61,   116,    41,   141,    41,   141,
      61,   107,    41,   141,   122,   112,   141,   141,   141,   141,
      66,    41,    45,    91,    70,    58,    48,    71,    57,    70,
      80,    62,   141,   115,   110,    61,    62,   141,    66,   106,
      62,    64,    65,   123,   141,    60,    65,    64,    59,    61,
      71,    41,    74,    57,    70,    41,    41,    44,    55,    60,
      85,    61,    66,    62,   116,    62,   141,    66,    62,   141,
     107,   123,   141,   112,   145,    70,    61,    49,    41,    41,
      58,    61,    58,    61,    41,    44,    62,   141,   141,   110,
     110,    59,    66,    60,   141,    89,    62,    61,    79,    79,
     141,   141,    63,    41,    62,    61,    66,    62,   108,    59,
     110,    59,    62,    58,    58,   110,   110,    81,    63,   110,
     141,   141,   119,   141,   110,    62,    92,    62,    62,    83,
      82,    66,    62,    60,    65,   109,     1,    30,    31,    32,
      33,    35,    36,    38,    39,    60,    93,    94,    97,    98,
     120,   124,   127,   131,   133,   143,    58,    58,    64,    65,
      71,    84,    83,    59,   110,   141,   119,    58,    59,    60,
      41,   141,   141,   141,    48,    35,    58,   125,    45,    84,
      70,    64,   118,    66,    60,    37,    65,    59,    59,    74,
      11,    12,    13,    14,    15,    66,   126,    70,    41,    45,
     119,    59,    41,   141,    41,   129,   132,    49,    66,    66,
      66,    66,    66,   141,    86,    61,    70,    60,   117,   139,
      67,    37,    92,    92,    59,    62,    86,   119,   136,    67,
      41,    60,    60,    92,    59,    60,    59,   141,   140,    34,
      60,    92,    92,    67,   138,   137,    59,   128,    60,    60,
      67,   134,    59,   130,   127,   141,    59,    92,    92,   138,
      92,    60,    60,   135,    60,    59,    92,    60
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
     123,   124,   125,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   127,   129,   130,   132,   131,   134,   133,   135,
     133,   136,   133,   137,   133,   138,   139,   140,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   143,   144,   143,   143,   145,   143,   146,
     147
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
       1,     4,     0,     1,     2,     2,     2,     2,     2,     6,
      11,     0,     9,     0,     0,     0,     6,     0,    12,     0,
      15,     0,     9,     0,    11,     0,     0,     0,     3,     3,
       3,     3,     3,     4,     3,     2,     3,     3,     3,     3,
       3,     4,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     4,     0,     9,     0,
       5
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
#line 1839 "parser.tab.c"
    break;

  case 16:
#line 119 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1845 "parser.tab.c"
    break;

  case 18:
#line 123 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1851 "parser.tab.c"
    break;

  case 19:
#line 124 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1857 "parser.tab.c"
    break;

  case 20:
#line 125 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1863 "parser.tab.c"
    break;

  case 21:
#line 126 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1869 "parser.tab.c"
    break;

  case 25:
#line 131 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1875 "parser.tab.c"
    break;

  case 26:
#line 135 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1881 "parser.tab.c"
    break;

  case 27:
#line 135 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1887 "parser.tab.c"
    break;

  case 28:
#line 135 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1893 "parser.tab.c"
    break;

  case 31:
#line 139 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;\n",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1902 "parser.tab.c"
    break;

  case 32:
#line 143 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];\n",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1910 "parser.tab.c"
    break;

  case 33:
#line 146 "parser.y"
                                                  {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    }else if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);
                                                    printcode("%s %s %s;\n",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 1922 "parser.tab.c"
    break;

  case 34:
#line 153 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }else if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,yylineno);
                                                    printcode("%s %s %s[%s];\n",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 1934 "parser.tab.c"
    break;

  case 35:
#line 160 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1940 "parser.tab.c"
    break;

  case 36:
#line 161 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 1948 "parser.tab.c"
    break;

  case 37:
#line 164 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 1956 "parser.tab.c"
    break;

  case 38:
#line 168 "parser.y"
                        {(yyval.b)= false;}
#line 1962 "parser.tab.c"
    break;

  case 39:
#line 169 "parser.y"
                {(yyval.b) = true;}
#line 1968 "parser.tab.c"
    break;

  case 41:
#line 172 "parser.y"
                                       {pushscope();}
#line 1974 "parser.tab.c"
    break;

  case 42:
#line 172 "parser.y"
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
#line 1989 "parser.tab.c"
    break;

  case 43:
#line 182 "parser.y"
                                                   {pushscope();}
#line 1995 "parser.tab.c"
    break;

  case 44:
#line 182 "parser.y"
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

  case 48:
#line 199 "parser.y"
                                        {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s)); create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno);free((yyvsp[0].s));}
#line 2016 "parser.tab.c"
    break;

  case 49:
#line 200 "parser.y"
                                        {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s)); add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2022 "parser.tab.c"
    break;

  case 50:
#line 202 "parser.y"
                           {is_static_method = true;}
#line 2028 "parser.tab.c"
    break;

  case 51:
#line 206 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2039 "parser.tab.c"
    break;

  case 52:
#line 214 "parser.y"
                                      {pushscope();}
#line 2045 "parser.tab.c"
    break;

  case 53:
#line 214 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2059 "parser.tab.c"
    break;

  case 54:
#line 224 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2068 "parser.tab.c"
    break;

  case 58:
#line 233 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2074 "parser.tab.c"
    break;

  case 59:
#line 234 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2080 "parser.tab.c"
    break;

  case 61:
#line 237 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2086 "parser.tab.c"
    break;

  case 62:
#line 238 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2092 "parser.tab.c"
    break;

  case 63:
#line 239 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2098 "parser.tab.c"
    break;

  case 64:
#line 240 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 2104 "parser.tab.c"
    break;

  case 65:
#line 241 "parser.y"
                        {expr_type= VOID_TYPE;}
#line 2110 "parser.tab.c"
    break;

  case 66:
#line 242 "parser.y"
                    {yyerror("missing ;");expr_type =  VOID_TYPE;}
#line 2116 "parser.tab.c"
    break;

  case 72:
#line 250 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2122 "parser.tab.c"
    break;

  case 75:
#line 253 "parser.y"
            {printcode("break;");}
#line 2128 "parser.tab.c"
    break;

  case 76:
#line 254 "parser.y"
                {printcode("continue;");}
#line 2134 "parser.tab.c"
    break;

  case 77:
#line 257 "parser.y"
                       {printcode("/*");}
#line 2140 "parser.tab.c"
    break;

  case 78:
#line 257 "parser.y"
                                                                 {printcode("*/");}
#line 2146 "parser.tab.c"
    break;

  case 79:
#line 258 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2152 "parser.tab.c"
    break;

  case 81:
#line 261 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2158 "parser.tab.c"
    break;

  case 82:
#line 263 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2170 "parser.tab.c"
    break;

  case 83:
#line 270 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2182 "parser.tab.c"
    break;

  case 84:
#line 277 "parser.y"
                          {has_returned = true;}
#line 2188 "parser.tab.c"
    break;

  case 86:
#line 281 "parser.y"
                                         {create_class_var((yyvsp[-2].m),(yyvsp[-1].s),(yyvsp[0].s),false,yylineno);}
#line 2194 "parser.tab.c"
    break;

  case 87:
#line 282 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));}
#line 2200 "parser.tab.c"
    break;

  case 88:
#line 282 "parser.y"
                                                                            {printcode(" ;");free((yyvsp[-2].s));}
#line 2206 "parser.tab.c"
    break;

  case 89:
#line 283 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2212 "parser.tab.c"
    break;

  case 90:
#line 283 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2218 "parser.tab.c"
    break;

  case 91:
#line 284 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2224 "parser.tab.c"
    break;

  case 92:
#line 284 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2230 "parser.tab.c"
    break;

  case 93:
#line 285 "parser.y"
                              {if(expr_type == VOID_TYPE){
            yyerror("Cannot figure ou type of variable %s, consider typecasting the expression or explicitly stating type",(yyvsp[-2].s));
            }else{
                add_var(NONE_TYPE,expr_type,(yyvsp[-2].s),yylineno);
                printcode("%s %s = %s;",type_arr[expr_type],(yyvsp[-2].s),(yyvsp[0].s));
            }
            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2242 "parser.tab.c"
    break;

  case 95:
#line 296 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2248 "parser.tab.c"
    break;

  case 96:
#line 297 "parser.y"
                                             {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-4].s),true,yylineno);printcode("%s[%s]",(yyvsp[-4].s),(yyvsp[-2].s));free((yyvsp[-4].s));free((yyvsp[-2].s));}
#line 2254 "parser.tab.c"
    break;

  case 97:
#line 298 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2260 "parser.tab.c"
    break;

  case 98:
#line 299 "parser.y"
                                                              {create_class_var((yyvsp[(-2) - (7)].m),(yyvsp[(-1) - (7)].s),(yyvsp[-4].s),true,yylineno);printcode(", %s[%s]",(yyvsp[-4].s),(yyvsp[-2].s));free((yyvsp[-4].s));free((yyvsp[-2].s));}
#line 2266 "parser.tab.c"
    break;

  case 99:
#line 301 "parser.y"
                     {create_var((yyvsp[(-1) - (1)].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2272 "parser.tab.c"
    break;

  case 100:
#line 302 "parser.y"
                              {create_var((yyvsp[(-1) - (3)].m),(yyvsp[-3].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2278 "parser.tab.c"
    break;

  case 101:
#line 305 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2286 "parser.tab.c"
    break;

  case 102:
#line 308 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2295 "parser.tab.c"
    break;

  case 103:
#line 312 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 2301 "parser.tab.c"
    break;

  case 104:
#line 312 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 2307 "parser.tab.c"
    break;

  case 105:
#line 313 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2315 "parser.tab.c"
    break;

  case 106:
#line 316 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2325 "parser.tab.c"
    break;

  case 107:
#line 321 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 2331 "parser.tab.c"
    break;

  case 108:
#line 321 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 2337 "parser.tab.c"
    break;

  case 109:
#line 324 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2348 "parser.tab.c"
    break;

  case 110:
#line 330 "parser.y"
                      {yyerror("Array size missing");}
#line 2354 "parser.tab.c"
    break;

  case 111:
#line 331 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2360 "parser.tab.c"
    break;

  case 112:
#line 331 "parser.y"
                                                                         {printcode(" }");}
#line 2366 "parser.tab.c"
    break;

  case 113:
#line 332 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2372 "parser.tab.c"
    break;

  case 114:
#line 332 "parser.y"
                                                                                                          {printcode(" }");}
#line 2378 "parser.tab.c"
    break;

  case 115:
#line 336 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2384 "parser.tab.c"
    break;

  case 116:
#line 338 "parser.y"
                                                        {if(arr_type == VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-6].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-6].s), yylineno);
                                                                printcode("%s %s[] = { %s };",type_arr[arr_type],(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }
                                                            expr_type = VOID_TYPE;
                                                            free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2397 "parser.tab.c"
    break;

  case 117:
#line 346 "parser.y"
                                                                    {if(arr_type== VOID_TYPE){
                                                            yyerror("Cannot figure ou type of array %s, consider typecasting the expression or explicitly stating type",(yyvsp[-8].s));
                                                            }else{
                                                                add_array(NONE_TYPE,  arr_type, (yyvsp[-8].s), yylineno);
                                                                printcode("%s %s[%s] = { %s };",type_arr[arr_type],(yyvsp[-8].s),(yyvsp[-6].s),(yyvsp[-1].s));
                                                            }expr_type = VOID_TYPE;
                                                            free((yyvsp[-8].s));free((yyvsp[-6].s));free((yyvsp[-1].s));}
#line 2409 "parser.tab.c"
    break;

  case 118:
#line 354 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}}
#line 2415 "parser.tab.c"
    break;

  case 119:
#line 355 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2427 "parser.tab.c"
    break;

  case 120:
#line 363 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2433 "parser.tab.c"
    break;

  case 121:
#line 363 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2439 "parser.tab.c"
    break;

  case 122:
#line 364 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2445 "parser.tab.c"
    break;

  case 123:
#line 364 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2451 "parser.tab.c"
    break;

  case 124:
#line 367 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2457 "parser.tab.c"
    break;

  case 125:
#line 368 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2464 "parser.tab.c"
    break;

  case 126:
#line 370 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2471 "parser.tab.c"
    break;

  case 127:
#line 372 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2477 "parser.tab.c"
    break;

  case 128:
#line 372 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2485 "parser.tab.c"
    break;

  case 129:
#line 375 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2491 "parser.tab.c"
    break;

  case 130:
#line 375 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2499 "parser.tab.c"
    break;

  case 131:
#line 378 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2505 "parser.tab.c"
    break;

  case 132:
#line 380 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2511 "parser.tab.c"
    break;

  case 133:
#line 384 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2521 "parser.tab.c"
    break;

  case 134:
#line 389 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2530 "parser.tab.c"
    break;

  case 135:
#line 394 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2536 "parser.tab.c"
    break;

  case 136:
#line 394 "parser.y"
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
#line 2574 "parser.tab.c"
    break;

  case 140:
#line 434 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2585 "parser.tab.c"
    break;

  case 141:
#line 442 "parser.y"
                                               {
                                    if(temp_type == CLASS_TYPE){
                                        if(expr_type != CLASS_TYPE ){
                                            yyerror("cannot assign %s to class type variable",type_arr[expr_type]);
                                        }else if(strcmp(expr_class,temp_class) != 0){
                                            yyerror("cannot assign class %s value to class %s variable",expr_class,temp_class);
                                        }else if(strcmp((yyvsp[-1].s),"=") != 0){
                                            yyerror("cannot perform compund operations on class type variables");
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
#line 2610 "parser.tab.c"
    break;

  case 142:
#line 465 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 2619 "parser.tab.c"
    break;

  case 143:
#line 471 "parser.y"
                {(yyval.s) = "=";}
#line 2625 "parser.tab.c"
    break;

  case 144:
#line 472 "parser.y"
              {(yyval.s) = "+=";}
#line 2631 "parser.tab.c"
    break;

  case 145:
#line 473 "parser.y"
              {(yyval.s) = "-=";}
#line 2637 "parser.tab.c"
    break;

  case 146:
#line 474 "parser.y"
              {(yyval.s) = "*=";}
#line 2643 "parser.tab.c"
    break;

  case 147:
#line 475 "parser.y"
              {(yyval.s) = "/=";}
#line 2649 "parser.tab.c"
    break;

  case 148:
#line 476 "parser.y"
              {(yyval.s) = "%=";}
#line 2655 "parser.tab.c"
    break;

  case 149:
#line 479 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2661 "parser.tab.c"
    break;

  case 150:
#line 480 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2667 "parser.tab.c"
    break;

  case 151:
#line 481 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2673 "parser.tab.c"
    break;

  case 153:
#line 484 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2679 "parser.tab.c"
    break;

  case 154:
#line 488 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2685 "parser.tab.c"
    break;

  case 155:
#line 492 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2691 "parser.tab.c"
    break;

  case 156:
#line 492 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2697 "parser.tab.c"
    break;

  case 157:
#line 495 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2703 "parser.tab.c"
    break;

  case 158:
#line 495 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2709 "parser.tab.c"
    break;

  case 159:
#line 496 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2715 "parser.tab.c"
    break;

  case 160:
#line 496 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2721 "parser.tab.c"
    break;

  case 161:
#line 497 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2727 "parser.tab.c"
    break;

  case 162:
#line 497 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2733 "parser.tab.c"
    break;

  case 163:
#line 498 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2739 "parser.tab.c"
    break;

  case 164:
#line 498 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2745 "parser.tab.c"
    break;

  case 165:
#line 501 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2751 "parser.tab.c"
    break;

  case 166:
#line 505 "parser.y"
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
#line 2767 "parser.tab.c"
    break;

  case 167:
#line 519 "parser.y"
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
#line 2783 "parser.tab.c"
    break;

  case 168:
#line 532 "parser.y"
                     { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2789 "parser.tab.c"
    break;

  case 169:
#line 533 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2795 "parser.tab.c"
    break;

  case 170:
#line 534 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2801 "parser.tab.c"
    break;

  case 171:
#line 535 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2807 "parser.tab.c"
    break;

  case 172:
#line 536 "parser.y"
                     {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2816 "parser.tab.c"
    break;

  case 173:
#line 540 "parser.y"
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
#line 2832 "parser.tab.c"
    break;

  case 174:
#line 551 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 2838 "parser.tab.c"
    break;

  case 175:
#line 552 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_composite_val =false;}
#line 2844 "parser.tab.c"
    break;

  case 176:
#line 553 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2850 "parser.tab.c"
    break;

  case 177:
#line 554 "parser.y"
                      {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use > with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2856 "parser.tab.c"
    break;

  case 178:
#line 555 "parser.y"
                            {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use <= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2862 "parser.tab.c"
    break;

  case 179:
#line 556 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2868 "parser.tab.c"
    break;

  case 180:
#line 557 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2874 "parser.tab.c"
    break;

  case 181:
#line 558 "parser.y"
                                         {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2880 "parser.tab.c"
    break;

  case 182:
#line 559 "parser.y"
                     {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2886 "parser.tab.c"
    break;

  case 183:
#line 560 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2892 "parser.tab.c"
    break;

  case 184:
#line 561 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2899 "parser.tab.c"
    break;

  case 186:
#line 566 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2909 "parser.tab.c"
    break;

  case 187:
#line 571 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 2919 "parser.tab.c"
    break;

  case 188:
#line 576 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 2930 "parser.tab.c"
    break;

  case 189:
#line 582 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 2940 "parser.tab.c"
    break;

  case 190:
#line 587 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 2946 "parser.tab.c"
    break;

  case 193:
#line 592 "parser.y"
                     { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
                    }else {
                        is_assignable = _t->m != CONST_TYPE;
                    if(_t->is_class){
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
                    }}}
#line 2973 "parser.tab.c"
    break;

  case 194:
#line 614 "parser.y"
                     {push_expr_and_args();}
#line 2979 "parser.tab.c"
    break;

  case 195:
#line 614 "parser.y"
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
#line 3011 "parser.tab.c"
    break;

  case 196:
#line 641 "parser.y"
                                             { attr* a = find_attr(expr_class,(yyvsp[0].s));    
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[-3].s),(yyvsp[0].s));
                                        }else{
                                            is_assignable = a->m != CONST_TYPE;
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
#line 3036 "parser.tab.c"
    break;

  case 197:
#line 661 "parser.y"
                                                 {push_expr_and_args();}
#line 3042 "parser.tab.c"
    break;

  case 198:
#line 661 "parser.y"
                                                                                                  { attr* a = find_attr(expr_class,(yyvsp[-5].s));  
                                                                                                pop_expr_and_args();  
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
#line 3074 "parser.tab.c"
    break;

  case 199:
#line 689 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3080 "parser.tab.c"
    break;

  case 200:
#line 692 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3092 "parser.tab.c"
    break;


#line 3096 "parser.tab.c"

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
#line 700 "parser.y"


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
