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
    #include "filenames.h"
    #include "globals.h"
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
    char * fn_ret_class;
    type temp_type;
    char * temp_class;
    bool is_assignable = false;
    bool is_callable = true;
    bool is_static_method = false;
    bool is_private_method =false;


#line 121 "parser.tab.c"

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
    PRIVATE = 306,
    DCOLON = 307,
    CLASSNAME = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "parser.y"

    char *s;
    type t;
    modifier m;
    bool b;

#line 234 "parser.tab.c"

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
#define YYLAST   1538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  229
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  474

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


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
      65,    66,    13,    11,    67,    12,    69,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    60,
       9,    68,    10,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      51,    52,    53,    54,    55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   120,   121,   122,   126,   127,   128,   131,   132,
     133,   134,   135,   136,   138,   139,   143,   143,   143,   145,
     146,   147,   151,   154,   162,   170,   171,   174,   177,   179,
     180,   182,   183,   192,   201,   208,   218,   219,   221,   225,
     226,   228,   236,   244,   253,   262,   264,   269,   275,   276,
     277,   279,   280,   281,   282,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   297,   298,   299,   300,
     301,   302,   305,   305,   306,   308,   309,   311,   320,   327,
     330,   330,   331,   331,   332,   332,   333,   333,   334,   334,
     335,   346,   349,   350,   357,   357,   358,   358,   359,   360,
     367,   367,   371,   372,   388,   405,   406,   407,   408,   411,
     412,   415,   418,   422,   422,   423,   426,   431,   431,   434,
     440,   441,   441,   442,   442,   446,   448,   459,   470,   471,
     482,   482,   483,   483,   486,   487,   489,   491,   491,   494,
     494,   497,   499,   503,   509,   514,   514,   556,   556,   595,
     596,   597,   600,   608,   633,   639,   640,   641,   642,   643,
     644,   647,   648,   649,   649,   652,   656,   660,   660,   663,
     663,   664,   664,   665,   665,   666,   666,   669,   673,   695,
     716,   719,   722,   725,   728,   730,   742,   743,   744,   746,
     748,   750,   752,   754,   756,   758,   760,   762,   765,   770,
     775,   781,   786,   787,   790,   799,   800,   823,   823,   851,
     871,   871,   897,   897,   936,   963,   963,   994,   994,  1042
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
  "COMMENTLINE", "CLASS", "STATICMETHOD", "THIS", "PRIVATE", "\"::\"",
  "CLASSNAME", "';'", "'{'", "'}'", "'['", "']'", "'('", "')'", "','",
  "'='", "'.'", "$accept", "program", "type", "modifier", "topstmtlist",
  "topstmt", "rawlist", "classdef", "$@1", "$@2", "attrlist", "arraysign",
  "methodlist", "pvtmethoddummy", "staticdummy", "pvt", "methoddummy",
  "clsretmethoddummy", "fndeclaration", "pushscopedummy", "fndecldummy",
  "classfndecldummy", "paramlist", "param", "stmtlist", "stmt", "comment",
  "$@3", "commentlist", "returnstmt", "vardeclaration", "$@4", "$@5",
  "$@6", "$@7", "$@8", "classvarlist", "$@9", "$@10", "$@11", "classvals",
  "decllist", "classdecllist", "varlist", "$@12", "$@13", "arraydecl",
  "$@14", "$@15", "arraysizedummy", "letarraydecl", "letarrvals",
  "chararrdecllist", "$@16", "$@17", "strdecl", "$@18", "$@19",
  "arrayvallist", "fncall", "$@20", "$@21", "arglist", "arg", "assignstmt",
  "assigndummy", "assgtype", "ifstmt", "$@22", "ifdummy", "elsedummy",
  "whilestmt", "$@23", "forstmt", "$@24", "$@25", "$@26", "$@27",
  "rangecheckdummy", "simplearraydummy", "iterarraydummy", "expr", "value",
  "cmplxnum", "varvals", "$@28", "$@29", "$@30", "$@31", "$@32",
  "classcheckdummy", YY_NULLPTR
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      59,   123,   125,    91,    93,    40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF (-313)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-189)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -313,     5,  1028,  -313,  -313,  -313,  -313,     2,    90,   -30,
      28,  -313,  -313,    42,   260,  -313,  -313,  -313,  -313,    71,
    -313,  1015,     7,  -313,    86,  -313,    99,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
      -7,  -313,  -313,  1262,  1370,  -313,   101,  -313,   135,   145,
     151,  -313,  -313,   153,   157,  1370,  1370,    35,  -313,  -313,
    -313,  -313,    27,   105,   162,  1242,  -313,  1126,  -313,  -313,
      37,  1126,  -313,  -313,  -313,  -313,  -313,   146,    25,   180,
      54,   190,   208,   214,   233,   230,   284,   284,  -313,  -313,
     295,   297,   281,   283,   279,   228,  1370,  1370,  1370,  1370,
    1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,   342,   285,
     306,  -313,    20,   304,   287,   311,  1234,   293,   317,  1370,
     293,   319,   298,  -313,   323,   301,   327,  1370,  -313,   305,
     308,   331,  1370,  1370,  -313,  1370,  1126,   192,   192,   127,
     127,   127,   127,   289,   289,   357,   357,   357,  1370,   307,
     314,   335,   336,    90,  1101,  -313,   320,   334,   326,  -313,
    -313,    90,  -313,  1289,  -313,  -313,  -313,  1126,  1316,  -313,
      80,  1126,  -313,    84,  -313,   208,  -313,   321,   303,  1105,
    -313,  -313,   337,    88,  1126,   284,   255,  1126,   344,  -313,
     347,    90,  -313,   370,   371,  -313,  -313,    90,    52,  1423,
      93,   967,   287,  -313,   348,   981,  1370,   293,  1370,   293,
    -313,   351,  -313,  -313,  1370,  -313,  1126,  -313,  1370,  -313,
    -313,  1370,  -313,  1370,  -313,  -313,  1441,   354,   355,   161,
    1452,  -313,  -313,  -313,   376,   378,   382,   384,  1343,  1370,
    -313,  -313,   -16,   367,   361,  1126,  -313,  1126,  -313,  -313,
    -313,  1132,  1126,  -313,  1126,   110,  1164,  1370,  -313,  -313,
     383,   386,  -313,   414,   415,   416,   417,   -40,    58,  -313,
     995,  1126,   111,   392,  -313,   420,  -313,   401,  -313,   399,
    1191,  -313,  -313,  1126,   404,   406,  -313,  -313,   208,   208,
     403,   405,  -313,  1370,  -313,  1370,  -313,  1370,  1370,  1370,
     424,  1370,  -313,  -313,  -313,   409,  -313,  -313,   435,   440,
    -313,  -313,  1126,  1126,   433,  1009,  1126,  1126,  1370,   123,
    1126,  -313,  -313,   368,   413,  -313,  -313,  -313,  -313,   410,
     438,   442,  -313,  1126,  -313,  1370,  1370,   273,  -313,  -313,
     464,  1370,  1370,  1370,   459,    59,  -313,   446,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,   115,  -313,    46,    57,   448,
     450,  -313,   444,  1126,   182,  -313,  -313,  -313,   -23,  1084,
    1126,  1098,  -313,  -313,  -313,     4,   468,   470,  -313,  -313,
    1370,   457,  -313,  1397,   478,  -313,  -313,   224,   469,   472,
     477,   479,   480,  -313,  1370,  1465,  1479,   184,  -313,   166,
      22,   509,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    1126,  -313,  -313,  -313,  -313,  -313,  1370,  -313,   481,   510,
     458,   503,   491,   492,   494,   496,   186,   497,  1370,  -313,
     526,  -313,  -313,  -313,  -313,  -313,  -313,  -313,   211,  -313,
     502,   548,   593,   638,   683,   728,   495,  -313,   521,  -313,
     552,  -313,  -313,  -313,  -313,  -313,  1370,   529,  -313,  -313,
    -313,  1126,  -313,   773,   818,  -313,   863,  -313,  -313,   530,
    -313,  -313,   908,  -313
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    82,    84,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,   101,     0,    85,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    98,    94,    96,    19,
       0,    92,    90,     0,     0,    55,     0,    26,     0,     0,
       0,    18,    25,     0,     0,     0,     0,   216,   211,   212,
     209,   210,     0,     0,     0,     0,   215,   135,   207,   208,
     213,   100,    58,    83,    86,    29,   140,    99,   102,    95,
     121,    97,    39,    93,   115,    91,   197,   206,   217,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,   159,     0,
     219,     0,     0,     0,   196,     0,   202,   204,   205,   200,
     201,   198,   199,   190,   191,   192,   193,   194,     0,     0,
       0,     0,     0,    12,     0,    59,     0,     0,    49,    50,
      41,    12,    38,     0,   141,   142,   104,   103,     0,   107,
     108,   122,   124,   125,    40,    39,   116,   117,     0,     0,
     222,   220,     0,     0,   138,   195,     0,   203,     0,   227,
     224,    12,    60,     0,     0,    30,    24,    12,    46,     0,
       0,     0,     0,   112,   130,     0,     0,     0,     0,     0,
     120,     0,   218,   156,     0,   160,   162,   159,     0,   157,
     136,     0,   214,     0,   159,   225,     0,    63,    61,     0,
       0,    48,    47,    28,     0,     0,     0,     0,     0,     0,
     135,   143,     0,     0,   129,   109,   111,   126,   128,   118,
     161,     0,   135,   159,   139,     0,     0,     0,    57,    56,
       0,     0,    35,     0,     0,     0,     0,     0,     0,   152,
       0,   146,   144,     0,   105,     0,   131,     0,   223,     0,
       0,   137,   228,   135,     0,     0,    64,    62,    39,    39,
       0,     0,    33,     0,    31,     0,   135,     0,     0,     0,
       0,     0,   135,   221,   158,     0,    65,    65,     0,     0,
      55,    55,   135,   135,     0,     0,   145,   113,     0,     0,
     153,   133,   226,     0,     0,    37,    36,    58,    58,     0,
       0,     0,   135,   114,   132,     0,     0,     0,    80,    81,
       0,     0,    88,     0,     0,    12,    54,    71,    72,    78,
      76,    79,    73,    74,    75,    77,    53,    12,    12,     0,
       0,   149,   151,   154,     0,    67,    69,    68,     0,     0,
      87,     0,    24,    89,    70,     0,     0,     0,    34,    32,
       0,     0,   134,     0,     0,   175,   177,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   147,   216,
       0,     0,    65,    65,    66,   166,   167,   168,   169,   170,
     163,    52,    51,    52,    51,   150,     0,   183,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   189,
     171,   178,    65,    65,    65,    65,   148,    65,   187,   185,
     173,     0,     0,     0,     0,     0,     0,   179,     0,   176,
       0,    44,    42,    45,    43,   184,     0,     0,    65,    65,
     174,   187,    65,     0,     0,   181,     0,   186,   172,     0,
     180,    65,     0,   182
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -313,  -313,   -18,    -4,  -313,  -313,  -190,  -313,  -313,  -313,
    -313,  -173,  -313,  -313,  -313,   434,   179,   183,  -313,   -34,
    -313,  -313,   -37,   445,  -300,  -313,     6,  -313,  -313,  -313,
     595,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -110,  -313,  -313,  -231,
    -313,   372,  -313,  -313,  -313,   398,  -313,  -313,  -312,  -313,
    -313,  -313,  -179,   388,  -313,  -313,  -313,   155,  -313,  -313,
    -313,  -313,  -313,  -313,  -313,  -313,  -313,  -313,   142,  -313,
    -313,   -43,  -313,  -313,  -275,  -313,  -313,  -313,  -313,  -313,
    -313
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    75,   160,
     113,   123,   198,   234,   235,   161,   423,   422,    17,    72,
     285,   284,   112,   155,   323,   347,   348,    25,    46,   349,
     350,    54,    53,    49,    50,    48,    79,   203,   117,   207,
     242,    85,    83,    81,   120,   209,   169,   301,   336,   109,
      23,   183,    77,   114,   202,   164,   416,   380,   319,    66,
     128,   253,   179,   215,   351,   375,   394,   352,   450,   402,
     459,   353,   403,   354,   457,   469,   427,   448,   447,   417,
     439,   216,    68,    69,    70,   127,   218,   217,   257,   224,
     151
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    71,   210,    42,    21,     3,   229,   324,    18,   272,
     172,    22,    86,    87,   383,   388,   389,   390,   391,   392,
     292,   279,    95,   293,   364,   273,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   251,   108,
       5,     6,    51,    52,   384,   256,   274,    94,   355,   355,
      20,   275,   305,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   314,     5,     6,   397,    24,
      43,   321,   393,   167,   280,    44,   171,     5,     6,     5,
       6,   329,   330,    26,   178,    90,   152,   153,  -106,   184,
     185,   418,   186,   116,   373,   110,    91,   246,    88,   248,
      89,   362,   420,   421,   426,   187,   111,   231,   154,   232,
       5,     6,   376,   153,   233,   308,   309,  -123,   294,   162,
     201,   295,   119,   377,   153,   205,  -164,  -164,  -164,  -164,
    -164,    39,   441,   442,   443,   444,   194,   445,   103,   104,
     105,   106,   107,  -110,   108,   355,   355,  -127,   206,   154,
     220,    45,   208,    73,    74,   221,   238,   199,   463,   464,
      47,   239,   466,   245,    92,   247,   355,   355,   355,   355,
     355,   472,   281,   110,   297,   252,    76,   221,   254,   298,
     184,   237,   387,  -164,   111,   334,    78,   226,   355,   355,
     335,   355,    80,   230,    82,   270,   271,   355,    84,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   259,   108,
     262,    52,   264,   115,   283,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,  -188,   108,    88,
      93,    89,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   382,   108,   415,   118,   436,   335,
     312,   335,   313,   335,   315,   316,   317,   121,   320,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   122,   108,   404,    52,   333,   327,   328,    27,    28,
     446,   124,    29,    30,    31,    32,    33,    34,    35,    36,
     357,   358,   363,   320,   134,   135,   125,   126,   369,   370,
     371,  -189,   105,   106,   107,   156,   108,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    37,
     108,   222,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   365,   366,   367,   129,   320,   130,   131,
     400,    21,   157,   158,   132,   133,   148,   150,   -27,   149,
     163,   410,   165,   154,   154,    11,   168,    12,   170,   -27,
     173,   159,   174,   -49,   175,   176,   -27,   212,   177,   337,
     180,   181,   182,   320,   108,   188,   190,   412,   414,   189,
     195,   191,   196,   159,   211,   438,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,   219,   342,   343,   223,   344,   345,     9,    57,
     225,   227,   228,   461,   337,   249,   243,   260,   261,    11,
     265,    12,   266,   267,    62,   268,    63,   -12,   276,   277,
     346,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   338,   339,   340,   341,   286,   342,   343,
     287,   344,   345,     9,    57,   288,   289,   290,   291,   337,
     299,   300,   302,   303,    11,   306,    12,   307,   310,    62,
     311,    63,   -12,   322,   359,   356,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,   318,   342,   343,   325,   344,   345,     9,    57,
     326,   331,   360,   361,   337,   368,   374,   372,   378,    11,
     379,    12,   381,   395,    62,   396,    63,   -12,   398,   401,
     430,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   338,   339,   340,   341,   405,   342,   343,
     406,   344,   345,     9,    57,   407,   419,   408,   409,   337,
     428,   429,   432,   433,    11,   434,    12,   435,   437,    62,
     440,    63,   -12,   449,   456,   431,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,   458,   342,   343,   341,   344,   345,     9,    57,
     462,   471,   197,   425,   337,   255,   424,    19,   192,    11,
     241,    12,   250,   465,    62,   460,    63,   -12,     0,     0,
     451,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   338,   339,   340,   341,     0,   342,   343,
       0,   344,   345,     9,    57,     0,     0,     0,     0,   337,
       0,     0,     0,     0,    11,     0,    12,     0,     0,    62,
       0,    63,   -12,     0,     0,   452,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,     0,   342,   343,     0,   344,   345,     9,    57,
       0,     0,     0,     0,   337,     0,     0,     0,     0,    11,
       0,    12,     0,     0,    62,     0,    63,   -12,     0,     0,
     453,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   338,   339,   340,   341,     0,   342,   343,
       0,   344,   345,     9,    57,     0,     0,     0,     0,   337,
       0,     0,     0,     0,    11,     0,    12,     0,     0,    62,
       0,    63,   -12,     0,     0,   454,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,     0,   342,   343,     0,   344,   345,     9,    57,
       0,     0,     0,     0,   337,     0,     0,     0,     0,    11,
       0,    12,     0,     0,    62,     0,    63,   -12,     0,     0,
     455,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   338,   339,   340,   341,     0,   342,   343,
       0,   344,   345,     9,    57,     0,     0,     0,     0,   337,
       0,     0,     0,     0,    11,     0,    12,     0,     0,    62,
       0,    63,   -12,     0,     0,   467,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,     0,   342,   343,     0,   344,   345,     9,    57,
       0,     0,     0,     0,   337,     0,     0,     0,     0,    11,
       0,    12,     0,     0,    62,     0,    63,   -12,     0,     0,
     468,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   338,   339,   340,   341,     0,   342,   343,
       0,   344,   345,     9,    57,     0,     0,     0,     0,   337,
       0,     0,     0,     0,    11,     0,    12,     0,     0,    62,
       0,    63,   -12,     0,     0,   470,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   338,   339,
     340,   341,     0,   342,   343,     0,   344,   345,     9,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,    62,     0,    63,   -12,     0,     0,
     473,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,     0,   108,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,     0,   108,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,     0,   108,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,     0,   108,     0,    -2,     4,
       0,   240,     0,    27,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,     0,   244,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,   296,
       0,     0,     0,     0,     0,     0,     7,     8,     9,     0,
       0,     0,    10,   332,    41,     0,     0,     0,     0,    11,
       0,    12,    13,     0,     0,     0,     0,   -12,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
       0,   108,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,     0,   108,     0,    55,     0,    27,
      28,     0,    56,    29,    30,    31,    32,    33,    34,    35,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,     0,   108,    55,   385,    57,    58,    59,    56,
       0,    60,    61,     0,     0,     0,     0,     0,     0,   386,
     193,    62,     0,    63,     0,     0,     0,     0,     0,     0,
      65,   213,   214,    57,    58,    59,    55,     0,    60,    61,
       0,    56,     0,     0,     0,     0,     0,     0,    62,     0,
      63,     0,     0,     0,     0,     0,     0,    65,   278,   214,
       0,     0,     0,    55,     0,    57,    58,    59,    56,     0,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
      62,     0,    63,     0,     0,     0,     0,     0,     0,    65,
     282,   214,    57,    58,    59,     0,     0,    60,    61,     0,
       0,     0,     0,     0,     0,     0,    55,    62,     0,    63,
       0,    56,     0,     0,    55,     0,    65,   304,   214,    56,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,     0,     0,     0,    55,    57,    58,    59,     0,    56,
      60,    61,     0,    57,    58,    59,     0,     0,    60,    61,
      62,     0,    63,     0,     0,   166,     0,     0,    62,    65,
      63,    55,     0,    57,    58,    59,    56,    65,    60,    61,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
      63,     0,     0,     0,     0,     0,    64,    65,    55,     0,
      57,    58,    59,    56,     0,    60,    61,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,    63,     0,     0,
       0,     0,     0,   200,    65,    55,     0,    57,    58,    59,
      56,     0,    60,    61,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,    63,     0,     0,     0,     0,     0,
     204,    65,    55,     0,    57,    58,    59,    56,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,    63,     0,     0,     0,     0,     0,   269,    65,    55,
       0,    57,    58,    59,    56,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,    63,     0,
       0,     0,     0,     0,     0,    65,     0,     0,   399,    58,
      59,    27,    28,    60,    61,    29,    30,    31,    32,    33,
      34,    35,     0,    62,     0,    63,     0,     0,     0,    27,
      28,     0,    65,    29,    30,    31,    32,    33,    34,    35,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,     0,   236,    27,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,     0,     0,     0,    27,    28,     0,
     258,    29,    30,    31,    32,    33,    34,    35,     0,     0,
       0,   263,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   411,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   413
};

static const yytype_int16 yycheck[] =
{
      43,    44,   175,    21,     8,     0,   196,   307,     2,   240,
     120,    41,    55,    56,    37,    11,    12,    13,    14,    15,
      60,   252,    65,    63,   336,    41,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   217,    17,
      20,    21,    49,    50,    67,   224,    62,    65,   323,   324,
      48,    67,   283,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   296,    20,    21,   380,    41,
      63,   302,    68,   116,   253,    68,   119,    20,    21,    20,
      21,   312,   313,    41,   127,    58,    66,    67,    63,   132,
     133,    69,   135,    68,    35,    58,    69,   207,    63,   209,
      65,   332,   402,   403,   416,   148,    69,    55,   112,    57,
      20,    21,    66,    67,    62,   288,   289,    63,    60,   113,
     163,    63,    68,    66,    67,   168,    11,    12,    13,    14,
      15,    60,   432,   433,   434,   435,   154,   437,    11,    12,
      13,    14,    15,    63,    17,   420,   421,    63,    68,   153,
      62,    65,    68,    52,    53,    67,    63,   161,   458,   459,
      61,    68,   462,   206,    59,   208,   441,   442,   443,   444,
     445,   471,    62,    58,    63,   218,    41,    67,   221,    68,
     223,   199,   372,    68,    69,    62,    41,   191,   463,   464,
      67,   466,    41,   197,    41,   238,   239,   472,    41,     7,
       8,     9,    10,    11,    12,    13,    14,    15,   226,    17,
      49,    50,   230,    67,   257,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    61,    17,    63,
      68,    65,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    62,    17,    62,    67,    62,    67,
     293,    67,   295,    67,   297,   298,   299,    67,   301,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    63,    17,    49,    50,   318,   310,   311,    18,    19,
      69,    67,    22,    23,    24,    25,    26,    27,    28,    29,
     327,   328,   335,   336,    66,    67,    63,    67,   341,   342,
     343,    17,    13,    14,    15,     1,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    59,
      17,    66,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    60,    61,    62,    41,   380,    41,    58,
     383,   345,    38,    39,    61,    66,     4,    41,    44,    64,
      63,   394,    41,   357,   358,    51,    63,    53,    41,    55,
      41,    57,    64,    59,    41,    64,    62,    64,    41,     1,
      65,    63,    41,   416,    17,    68,    41,   395,   396,    65,
      60,    45,    48,    57,    63,   428,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    65,    35,    36,    61,    38,    39,    40,    41,
      63,    41,    41,   456,     1,    64,    68,    63,    63,    51,
      44,    53,    44,    41,    56,    41,    58,    59,    61,    68,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    64,    35,    36,
      64,    38,    39,    40,    41,    41,    41,    41,    41,     1,
      68,    41,    61,    64,    51,    61,    53,    61,    65,    56,
      65,    58,    59,    64,    64,    62,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    68,    35,    36,    60,    38,    39,    40,    41,
      60,    68,    64,    61,     1,    41,    60,    48,    60,    51,
      60,    53,    68,    45,    56,    45,    58,    59,    61,    41,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    68,    35,    36,
      68,    38,    39,    40,    41,    68,    37,    68,    68,     1,
      69,    41,    61,    61,    51,    61,    53,    61,    61,    56,
      34,    58,    59,    61,    69,    62,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    61,    35,    36,    33,    38,    39,    40,    41,
      61,    61,   158,   414,     1,   223,   413,     2,   153,    51,
     202,    53,   214,   461,    56,   450,    58,    59,    -1,    -1,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,
      -1,    58,    59,    -1,    -1,    62,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,
      -1,    58,    59,    -1,    -1,    62,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,
      -1,    58,    59,    -1,    -1,    62,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    56,
      -1,    58,    59,    -1,    -1,    62,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    56,    -1,    58,    59,    -1,    -1,
      62,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,     0,     1,
      -1,    64,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    64,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    44,    64,    59,    -1,    -1,    -1,    -1,    51,
      -1,    53,    54,    -1,    -1,    -1,    -1,    59,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    12,    -1,    18,
      19,    -1,    17,    22,    23,    24,    25,    26,    27,    28,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,    12,    61,    41,    42,    43,    17,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      59,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    41,    42,    43,    12,    -1,    46,    47,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    12,    -1,    41,    42,    43,    17,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    56,    -1,    58,
      -1,    17,    -1,    -1,    12,    -1,    65,    66,    67,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    12,    41,    42,    43,    -1,    17,
      46,    47,    -1,    41,    42,    43,    -1,    -1,    46,    47,
      56,    -1,    58,    -1,    -1,    61,    -1,    -1,    56,    65,
      58,    12,    -1,    41,    42,    43,    17,    65,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    64,    65,    12,    -1,
      41,    42,    43,    17,    -1,    46,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    64,    65,    12,    -1,    41,    42,    43,
      17,    -1,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    -1,
      64,    65,    12,    -1,    41,    42,    43,    17,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,    12,
      -1,    41,    42,    43,    17,    -1,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    41,    42,
      43,    18,    19,    46,    47,    22,    23,    24,    25,    26,
      27,    28,    -1,    56,    -1,    58,    -1,    -1,    -1,    18,
      19,    -1,    65,    22,    23,    24,    25,    26,    27,    28,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    59,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    18,    19,    -1,
      59,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    71,    74,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    73,    75,    77,    88,    96,   100,
      48,    73,    41,   120,    41,    97,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    59,    72,    60,
      76,    59,    72,    63,    68,    65,    98,    61,   105,   103,
     104,    49,    50,   102,   101,    12,    17,    41,    42,    43,
      46,    47,    56,    58,    64,    65,   129,   151,   152,   153,
     154,   151,    89,    52,    53,    78,    41,   122,    41,   106,
      41,   113,    41,   112,    41,   111,   151,   151,    63,    65,
      58,    69,    59,    68,    72,   151,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    17,   119,
      58,    69,    92,    80,   123,    67,    68,   108,    67,    68,
     114,    67,    63,    81,    67,    63,    67,   155,   130,    41,
      41,    58,    61,    66,    66,    67,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,     4,    64,
      41,   160,    66,    67,    73,    93,     1,    38,    39,    57,
      79,    85,    96,    63,   125,    41,    61,   151,    63,   116,
      41,   151,   116,    41,    64,    41,    64,    41,   151,   132,
      65,    63,    41,   121,   151,   151,   151,   151,    68,    65,
      41,    45,    93,    59,    72,    60,    48,    85,    82,    73,
      64,   151,   124,   107,    64,   151,    68,   109,    68,   115,
      81,    63,    64,    66,    67,   133,   151,   157,   156,    65,
      62,    67,    66,    61,   159,    63,    73,    41,    41,    76,
      73,    55,    57,    62,    83,    84,    59,    72,    63,    68,
      64,   125,   110,    68,    64,   151,   116,   151,   116,    64,
     133,   132,   151,   131,   151,   121,   132,   158,    59,    72,
      63,    63,    49,    59,    72,    44,    44,    41,    41,    64,
     151,   151,   119,    41,    62,    67,    61,    68,    66,   119,
     132,    62,    66,   151,    91,    90,    64,    64,    41,    41,
      41,    41,    60,    63,    60,    63,    64,    63,    68,    68,
      41,   117,    61,    64,    66,   119,    61,    61,    81,    81,
      65,    65,   151,   151,   119,   151,   151,   151,    68,   128,
     151,   119,    64,    94,    94,    60,    60,    89,    89,   119,
     119,    68,    64,   151,    62,    67,   118,     1,    30,    31,
      32,    33,    35,    36,    38,    39,    62,    95,    96,    99,
     100,   134,   137,   141,   143,   154,    62,    92,    92,    64,
      64,    61,   119,   151,   128,    60,    61,    62,    41,   151,
     151,   151,    48,    35,    60,   135,    66,    66,    60,    60,
     127,    68,    62,    37,    67,    61,    61,    76,    11,    12,
      13,    14,    15,    68,   136,    45,    45,   128,    61,    41,
     151,    41,   139,   142,    49,    68,    68,    68,    68,    68,
     151,    59,    72,    59,    72,    62,   126,   149,    69,    37,
      94,    94,    87,    86,    87,    86,   128,   146,    69,    41,
      62,    62,    61,    61,    61,    61,    62,    61,   151,   150,
      34,    94,    94,    94,    94,    94,    69,   148,   147,    61,
     138,    62,    62,    62,    62,    62,    69,   144,    61,   140,
     137,   151,    61,    94,    94,   148,    94,    62,    62,   145,
      62,    61,    94,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    75,    75,    76,    76,    78,    79,    77,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    83,    83,    84,    85,
      85,    86,    87,    88,    88,    89,    90,    91,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    97,    96,    96,    98,    98,    99,    99,    99,
     101,   100,   102,   100,   103,   100,   104,   100,   105,   100,
     100,   100,   106,   106,   107,   106,   108,   106,   106,   106,
     109,   106,   110,   110,   110,   111,   111,   111,   111,   112,
     112,   113,   113,   114,   113,   113,   113,   115,   113,   116,
     116,   117,   116,   118,   116,   119,   120,   120,   121,   121,
     123,   122,   124,   122,   125,   125,   125,   126,   125,   127,
     125,   125,   125,   128,   128,   130,   129,   131,   129,   132,
     132,   132,   133,   134,   135,   136,   136,   136,   136,   136,
     136,   137,   137,   138,   137,   139,   140,   142,   141,   144,
     143,   145,   143,   146,   143,   147,   143,   148,   149,   150,
     151,   151,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   151,   151,   151,   151,   151,   152,   152,
     152,   152,   152,   152,   153,   154,   154,   155,   154,   154,
     156,   154,   157,   154,   154,   158,   154,   159,   154,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     6,    10,     6,    10,     5,     8,     8,     2,     0,
       2,     0,    14,    14,    14,    14,     0,     1,     1,     0,
       1,     0,     0,    13,    13,     0,     0,     0,     0,     2,
       3,     3,     5,     3,     5,     0,     5,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     0,     4,     1,     0,     2,     2,     1,     2,
       0,     5,     0,     5,     0,     4,     0,     4,     0,     4,
       4,     2,     1,     3,     0,     6,     0,     3,     3,     5,
       0,     5,     0,     4,     5,     1,     3,     3,     5,     2,
       4,     1,     3,     0,     3,     3,     5,     0,     5,     3,
       2,     0,     7,     0,     9,     0,     7,     9,     1,     3,
       0,     3,     0,     5,     4,     6,     4,     0,    13,     0,
      11,     8,     4,     1,     3,     0,     5,     0,     8,     0,
       2,     3,     1,     4,     0,     1,     2,     2,     2,     2,
       2,     6,    11,     0,     9,     0,     0,     0,     6,     0,
      12,     0,    15,     0,     9,     0,    11,     0,     0,     0,
       3,     3,     3,     3,     3,     4,     3,     2,     3,     3,
       3,     3,     3,     4,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     0,     5,     3,
       0,     8,     0,     7,     4,     0,     9,     0,     7,     0
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
#line 120 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1961 "parser.tab.c"
    break;

  case 16:
#line 127 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1967 "parser.tab.c"
    break;

  case 18:
#line 131 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1973 "parser.tab.c"
    break;

  case 19:
#line 132 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1979 "parser.tab.c"
    break;

  case 20:
#line 133 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1985 "parser.tab.c"
    break;

  case 21:
#line 134 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1991 "parser.tab.c"
    break;

  case 23:
#line 136 "parser.y"
               {expr_type =VOID_TYPE;}
#line 1997 "parser.tab.c"
    break;

  case 25:
#line 139 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 2003 "parser.tab.c"
    break;

  case 26:
#line 143 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 2009 "parser.tab.c"
    break;

  case 27:
#line 143 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 2015 "parser.tab.c"
    break;

  case 28:
#line 143 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 2021 "parser.tab.c"
    break;

  case 31:
#line 147 "parser.y"
                                                {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,(yyvsp[-4].b),yylineno);
                                                printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 2030 "parser.tab.c"
    break;

  case 32:
#line 151 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,(yyvsp[-8].b),yylineno);printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 2038 "parser.tab.c"
    break;

  case 33:
#line 154 "parser.y"
                                                      {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    } 
                                                    if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,(yyvsp[-4].b),yylineno);
                                                    printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 2051 "parser.tab.c"
    break;

  case 34:
#line 162 "parser.y"
                                                                                {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }
                                                    if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,(yyvsp[-8].b),yylineno);
                                                    printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 2064 "parser.tab.c"
    break;

  case 35:
#line 170 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2070 "parser.tab.c"
    break;

  case 36:
#line 171 "parser.y"
                                                                {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),(yyvsp[-5].b),yylineno);free((yyvsp[-2].s));}
#line 2078 "parser.tab.c"
    break;

  case 37:
#line 174 "parser.y"
                                                                     {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),(yyvsp[-5].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2086 "parser.tab.c"
    break;

  case 39:
#line 179 "parser.y"
                        {(yyval.b)= false;}
#line 2092 "parser.tab.c"
    break;

  case 40:
#line 180 "parser.y"
                {(yyval.b) = true;}
#line 2098 "parser.tab.c"
    break;

  case 42:
#line 183 "parser.y"
                                                                                                                         {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2112 "parser.tab.c"
    break;

  case 43:
#line 192 "parser.y"
                                                                                                                     {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2126 "parser.tab.c"
    break;

  case 44:
#line 201 "parser.y"
                                                                                                                                    {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);}
                                                                                                    free((yyvsp[-10].s));free((yyvsp[-4].s));
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2138 "parser.tab.c"
    break;

  case 45:
#line 208 "parser.y"
                                                                                                                                {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);}
                                                                                                    free((yyvsp[-10].s));free((yyvsp[-4].s));
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2150 "parser.tab.c"
    break;

  case 46:
#line 218 "parser.y"
                         {is_private_method = false;}
#line 2156 "parser.tab.c"
    break;

  case 47:
#line 219 "parser.y"
                {is_private_method = true;}
#line 2162 "parser.tab.c"
    break;

  case 48:
#line 221 "parser.y"
                           {is_static_method = true;is_private_method = false;}
#line 2168 "parser.tab.c"
    break;

  case 49:
#line 225 "parser.y"
             {(yyval.b) = false;}
#line 2174 "parser.tab.c"
    break;

  case 50:
#line 226 "parser.y"
                    {(yyval.b) = true;}
#line 2180 "parser.tab.c"
    break;

  case 51:
#line 228 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, is_private_method,yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2191 "parser.tab.c"
    break;

  case 52:
#line 236 "parser.y"
                                {add_class_ret_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].s), is_static_method,temp_list,is_private_method, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = CLASS_TYPE;
                            fn_ret_class = (yyvsp[0].s);
                            is_in_fn = true;
                            has_returned = false;}
#line 2203 "parser.tab.c"
    break;

  case 53:
#line 244 "parser.y"
                                                                                                                 {printcode("}"); 
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2217 "parser.tab.c"
    break;

  case 54:
#line 253 "parser.y"
                                                                                                                        {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require class %s return type, corresponding return statement not found",(yyvsp[-11].s),(yyvsp[-4].s));
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));free((yyvsp[-4].s));
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2231 "parser.tab.c"
    break;

  case 55:
#line 262 "parser.y"
                                {pushscope();}
#line 2237 "parser.tab.c"
    break;

  case 56:
#line 264 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2246 "parser.tab.c"
    break;

  case 57:
#line 269 "parser.y"
                                {print_fn_delc((yyvsp[(-7) - (0)].s));
                                fn_type = CLASS_TYPE;
                                fn_ret_class =(yyvsp[0].s);
                                is_in_fn = true;
                                has_returned = false;}
#line 2256 "parser.tab.c"
    break;

  case 61:
#line 279 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2262 "parser.tab.c"
    break;

  case 62:
#line 280 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2268 "parser.tab.c"
    break;

  case 63:
#line 281 "parser.y"
                                        {add_class_param((yyvsp[-2].m), (yyvsp[-1].s), false,(yyvsp[0].s));create_class_var((yyvsp[-2].m), (yyvsp[-1].s), (yyvsp[0].s), false,yylineno);free((yyvsp[-1].s));free((yyvsp[0].s));}
#line 2274 "parser.tab.c"
    break;

  case 64:
#line 282 "parser.y"
                                            {add_class_param((yyvsp[-4].m), (yyvsp[-3].s), true,(yyvsp[-2].s));create_class_var((yyvsp[-4].m), (yyvsp[-3].s), (yyvsp[-2].s), true,yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2280 "parser.tab.c"
    break;

  case 66:
#line 285 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2286 "parser.tab.c"
    break;

  case 67:
#line 286 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2292 "parser.tab.c"
    break;

  case 68:
#line 287 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2298 "parser.tab.c"
    break;

  case 69:
#line 288 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2304 "parser.tab.c"
    break;

  case 70:
#line 289 "parser.y"
                        {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2310 "parser.tab.c"
    break;

  case 71:
#line 290 "parser.y"
                    {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2316 "parser.tab.c"
    break;

  case 73:
#line 292 "parser.y"
                      {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2322 "parser.tab.c"
    break;

  case 74:
#line 293 "parser.y"
                         {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2328 "parser.tab.c"
    break;

  case 75:
#line 294 "parser.y"
                       {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2334 "parser.tab.c"
    break;

  case 77:
#line 298 "parser.y"
              {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2340 "parser.tab.c"
    break;

  case 80:
#line 301 "parser.y"
            {printcode("break;");}
#line 2346 "parser.tab.c"
    break;

  case 81:
#line 302 "parser.y"
                {printcode("continue;");}
#line 2352 "parser.tab.c"
    break;

  case 82:
#line 305 "parser.y"
                       {printcode("/*");}
#line 2358 "parser.tab.c"
    break;

  case 83:
#line 305 "parser.y"
                                                                 {printcode("*/");}
#line 2364 "parser.tab.c"
    break;

  case 84:
#line 306 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2370 "parser.tab.c"
    break;

  case 86:
#line 309 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2376 "parser.tab.c"
    break;

  case 87:
#line 311 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else if(fn_type == CLASS_TYPE && strcmp(expr_class,fn_ret_class) !=0){
                                yyerror("invalid return type : expected class %s found class %s",fn_ret_class,expr_class);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2390 "parser.tab.c"
    break;

  case 88:
#line 320 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2402 "parser.tab.c"
    break;

  case 89:
#line 327 "parser.y"
                          {has_returned = true;}
#line 2408 "parser.tab.c"
    break;

  case 90:
#line 330 "parser.y"
                                    {temp_type = (yyvsp[0].t);}
#line 2414 "parser.tab.c"
    break;

  case 91:
#line 330 "parser.y"
                                                               {temp_type = VOID_TYPE;}
#line 2420 "parser.tab.c"
    break;

  case 92:
#line 331 "parser.y"
                              {temp_type = CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2426 "parser.tab.c"
    break;

  case 93:
#line 331 "parser.y"
                                                                                    {temp_type = VOID_TYPE;temp_class=NULL;free((yyvsp[-2].s));}
#line 2432 "parser.tab.c"
    break;

  case 94:
#line 332 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));arr_type=temp_type=CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2438 "parser.tab.c"
    break;

  case 95:
#line 332 "parser.y"
                                                                                                                        {printcode(" ;");free((yyvsp[-2].s));arr_type=temp_type=VOID_TYPE;temp_class= NULL;}
#line 2444 "parser.tab.c"
    break;

  case 96:
#line 333 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2450 "parser.tab.c"
    break;

  case 97:
#line 333 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2456 "parser.tab.c"
    break;

  case 98:
#line 334 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2462 "parser.tab.c"
    break;

  case 99:
#line 334 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2468 "parser.tab.c"
    break;

  case 100:
#line 335 "parser.y"
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
#line 2484 "parser.tab.c"
    break;

  case 102:
#line 349 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2490 "parser.tab.c"
    break;

  case 103:
#line 350 "parser.y"
                          {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),false,yylineno);
                            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2502 "parser.tab.c"
    break;

  case 104:
#line 357 "parser.y"
                          {printcode("%s = { ",(yyvsp[-2].s));}
#line 2508 "parser.tab.c"
    break;

  case 105:
#line 357 "parser.y"
                                                                    {printcode(" }");create_class_var((yyvsp[(-2) - (6)].m),(yyvsp[(-1) - (6)].s),(yyvsp[-5].s),false,yylineno);free((yyvsp[-5].s));}
#line 2514 "parser.tab.c"
    break;

  case 106:
#line 358 "parser.y"
                 {/*nothing dummymust be kept to maintain arraydecl*/}
#line 2520 "parser.tab.c"
    break;

  case 107:
#line 358 "parser.y"
                                                                                 {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2526 "parser.tab.c"
    break;

  case 108:
#line 359 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2532 "parser.tab.c"
    break;

  case 109:
#line 360 "parser.y"
                                           {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" ,%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),false,yylineno);
                            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2544 "parser.tab.c"
    break;

  case 110:
#line 367 "parser.y"
                                  {printcode(", ");}
#line 2550 "parser.tab.c"
    break;

  case 111:
#line 367 "parser.y"
                                                               {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2556 "parser.tab.c"
    break;

  case 113:
#line 372 "parser.y"
                                    {attr * a = find_attr(temp_class,(yyvsp[-2].s));
                                            if(a==NULL){yyerror("No attribute named %s defined on class %s",(yyvsp[-2].s),temp_class);
                                            }else{
                                                if(a->is_class){
                                                    if(expr_type != CLASS_TYPE){
                                                        yyerror("Cannont assign non-class value to class type attribute");
                                                    }else if(strcmp(expr_class,a->t.class) !=0){
                                                        yyerror("value of class %s cannot be assigned to attribute of type class %s",expr_class,a->t.class);
                                                    }else{
                                                        printcode(".%s = %s,",(yyvsp[-2].s),(yyvsp[0].s));
                                                    }
                                                }else  if(verify_types(a->t.t,expr_type)){
                                                    yyerror("cannot assign type %s to variable of type %s",type_arr[a->t.t],type_arr[expr_type]);
                                                }else{
                                                    printcode(".%s = %s,",(yyvsp[-2].s),(yyvsp[0].s));
                                                }}}
#line 2577 "parser.tab.c"
    break;

  case 114:
#line 388 "parser.y"
                                        {attr * a = find_attr(temp_class,(yyvsp[-2].s));
                                            if(a==NULL){yyerror("No attribute named %s defined on class %s",(yyvsp[-2].s),temp_class);
                                            }else{
                                                if(a->is_class){
                                                    if(expr_type != CLASS_TYPE){
                                                        yyerror("Cannont assign non-class value to class type attribute");
                                                    }else if(strcmp(expr_class,a->t.class) !=0){
                                                        yyerror("value of class %s cannot be assigned to attribute of type class %s",expr_class,a->t.class);
                                                    }else{
                                                        printcode(".%s = %s,",(yyvsp[-2].s),(yyvsp[0].s));
                                                    }
                                                }else  if(verify_types(a->t.t,expr_type)){
                                                    yyerror("cannot assign type %s to variable of type %s",type_arr[a->t.t],type_arr[expr_type]);
                                                }else{
                                                    printcode(".%s = %s,",(yyvsp[-2].s),(yyvsp[0].s));
                                                }}}
#line 2598 "parser.tab.c"
    break;

  case 115:
#line 405 "parser.y"
                     {add_var((yyvsp[(-1) - (1)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2604 "parser.tab.c"
    break;

  case 116:
#line 406 "parser.y"
                         {add_array((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2610 "parser.tab.c"
    break;

  case 117:
#line 407 "parser.y"
                              {add_var((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2616 "parser.tab.c"
    break;

  case 118:
#line 408 "parser.y"
                                      {add_array((yyvsp[(-1) - (5)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2622 "parser.tab.c"
    break;

  case 119:
#line 411 "parser.y"
                                     {create_class_var((yyvsp[(-2) - (2)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2628 "parser.tab.c"
    break;

  case 120:
#line 412 "parser.y"
                                            {create_class_var((yyvsp[(-2) - (4)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2634 "parser.tab.c"
    break;

  case 121:
#line 415 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2642 "parser.tab.c"
    break;

  case 122:
#line 418 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2651 "parser.tab.c"
    break;

  case 123:
#line 422 "parser.y"
                {/*nothing dummy*/}
#line 2657 "parser.tab.c"
    break;

  case 124:
#line 422 "parser.y"
                                              {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2663 "parser.tab.c"
    break;

  case 125:
#line 423 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2671 "parser.tab.c"
    break;

  case 126:
#line 426 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2681 "parser.tab.c"
    break;

  case 127:
#line 431 "parser.y"
                             {printcode(", ");}
#line 2687 "parser.tab.c"
    break;

  case 128:
#line 431 "parser.y"
                                                          {add_array((yyvsp[(-2) - (5)].m),  (yyvsp[(-1) - (5)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2693 "parser.tab.c"
    break;

  case 129:
#line 434 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2704 "parser.tab.c"
    break;

  case 130:
#line 440 "parser.y"
                      {yyerror("Array size missing");}
#line 2710 "parser.tab.c"
    break;

  case 131:
#line 441 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2716 "parser.tab.c"
    break;

  case 132:
#line 441 "parser.y"
                                                                         {printcode(" }");}
#line 2722 "parser.tab.c"
    break;

  case 133:
#line 442 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2728 "parser.tab.c"
    break;

  case 134:
#line 442 "parser.y"
                                                                                                          {printcode(" }");}
#line 2734 "parser.tab.c"
    break;

  case 135:
#line 446 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2740 "parser.tab.c"
    break;

  case 136:
#line 448 "parser.y"
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
#line 2756 "parser.tab.c"
    break;

  case 137:
#line 459 "parser.y"
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
#line 2771 "parser.tab.c"
    break;

  case 138:
#line 470 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
#line 2777 "parser.tab.c"
    break;

  case 139:
#line 471 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2791 "parser.tab.c"
    break;

  case 140:
#line 482 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2797 "parser.tab.c"
    break;

  case 141:
#line 482 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2803 "parser.tab.c"
    break;

  case 142:
#line 483 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2809 "parser.tab.c"
    break;

  case 143:
#line 483 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2815 "parser.tab.c"
    break;

  case 144:
#line 486 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2821 "parser.tab.c"
    break;

  case 145:
#line 487 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2828 "parser.tab.c"
    break;

  case 146:
#line 489 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2835 "parser.tab.c"
    break;

  case 147:
#line 491 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2841 "parser.tab.c"
    break;

  case 148:
#line 491 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2849 "parser.tab.c"
    break;

  case 149:
#line 494 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2855 "parser.tab.c"
    break;

  case 150:
#line 494 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2863 "parser.tab.c"
    break;

  case 151:
#line 497 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2869 "parser.tab.c"
    break;

  case 152:
#line 499 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2875 "parser.tab.c"
    break;

  case 153:
#line 503 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}

                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2886 "parser.tab.c"
    break;

  case 154:
#line 509 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2895 "parser.tab.c"
    break;

  case 155:
#line 514 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2901 "parser.tab.c"
    break;

  case 156:
#line 514 "parser.y"
                                                                                                    {if(!is_in_fn){
                                                                                                    yyerror("Function call is not allowed outside a function.");
                                                                                                    (yyval.s) = strdup("");
                                                                                                }else if(find_action((yyvsp[-4].s))){
                                                                                                    perform_action((yyvsp[-4].s));
                                                                                                    (yyval.s) = strdup("");
                                                                                                }else{
                                                                                                    Function *fn = find_fn((yyvsp[-4].s));
                                                                                                    is_callable = false;
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
                                                                                                            expr_type = CLASS_TYPE;
                                                                                                            expr_class = fn->ret_t.class;
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
#line 2948 "parser.tab.c"
    break;

  case 157:
#line 556 "parser.y"
                                         {push_expr_and_args();is_in_fncall=true;}
#line 2954 "parser.tab.c"
    break;

  case 158:
#line 556 "parser.y"
                                                                                               {if(!is_in_fn){
                                                                                                    yyerror("Function call is not allowed outside a function.");
                                                                                                    (yyval.s) = strdup("");
                                                                                                }else {
                                                                                                    is_callable = false;
                                                                                                    method * m =find_method((yyvsp[-6].s),(yyvsp[-4].s));
                                                                                                    if(m == NULL){
                                                                                                        yyerror("No method named %s found in class %s",(yyvsp[-4].s),(yyvsp[-6].s));
                                                                                                    }else if(!m->is_static){
                                                                                                        yyerror("cannot access non-static methods withoud a class variable");
                                                                                                    }
                                                                                                    verify_method_call((yyvsp[-4].s),m,yylineno);
                                                                                                    (yyval.s) = get_methodcall_str(m,NULL);
                                                                                                    ll_clear(arglist);
                                                                                                    pop_expr_and_args();
                                                                                                    type fn_ret = m->ret_t.t;
                                                                                                    if(expr_type == VOID_TYPE){
                                                                                                        if(m->is_ret_class){
                                                                                                            expr_type = CLASS_TYPE;
                                                                                                            expr_class = m->ret_t.class;
                                                                                                        }else{
                                                                                                            expr_type = fn_ret;
                                                                                                        }
                                                                                                    }else if(m->is_ret_class){
                                                                                                        expr_type = CLASS_TYPE;
                                                                                                        expr_class = m->ret_t.class;
                                                                                                    }else if(expr_type == STRING_TYPE || expr_type != VOID_TYPE && fn_ret == STRING_TYPE ){
                                                                                                        yyerror("Cannot combine string type with any type.");
                                                                                                    }else if((expr_type == BOOL_TYPE && fn_ret != BOOL_TYPE) ||
                                                                                                        (fn_ret ==BOOL_TYPE && expr_type !=BOOL_TYPE)){
                                                                                                            yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                                                                                                    }else if(expr_type == COMPLEX_TYPE || fn_ret == COMPLEX_TYPE){
                                                                                                        expr_type = COMPLEX_TYPE;
                                                                                                    }else if(expr_type == FLOAT_TYPE || fn_ret == FLOAT_TYPE || fn_ret == DOUBLE_TYPE){
                                                                                                        expr_type = FLOAT_TYPE;
                                                                                                    }}free((yyvsp[-6].s));free((yyvsp[-4].s));
                                                                                                is_in_fncall = false;}
#line 2996 "parser.tab.c"
    break;

  case 162:
#line 600 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 3007 "parser.tab.c"
    break;

  case 163:
#line 608 "parser.y"
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
#line 3034 "parser.tab.c"
    break;

  case 164:
#line 633 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 3043 "parser.tab.c"
    break;

  case 165:
#line 639 "parser.y"
                {(yyval.s) = "=";}
#line 3049 "parser.tab.c"
    break;

  case 166:
#line 640 "parser.y"
              {(yyval.s) = "+=";}
#line 3055 "parser.tab.c"
    break;

  case 167:
#line 641 "parser.y"
              {(yyval.s) = "-=";}
#line 3061 "parser.tab.c"
    break;

  case 168:
#line 642 "parser.y"
              {(yyval.s) = "*=";}
#line 3067 "parser.tab.c"
    break;

  case 169:
#line 643 "parser.y"
              {(yyval.s) = "/=";}
#line 3073 "parser.tab.c"
    break;

  case 170:
#line 644 "parser.y"
              {(yyval.s) = "%=";}
#line 3079 "parser.tab.c"
    break;

  case 171:
#line 647 "parser.y"
                                         {popscope();printcode("}\n");}
#line 3085 "parser.tab.c"
    break;

  case 172:
#line 648 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 3091 "parser.tab.c"
    break;

  case 173:
#line 649 "parser.y"
                                            {popscope();printcode("}else ");}
#line 3097 "parser.tab.c"
    break;

  case 175:
#line 652 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 3103 "parser.tab.c"
    break;

  case 176:
#line 656 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 3109 "parser.tab.c"
    break;

  case 177:
#line 660 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 3115 "parser.tab.c"
    break;

  case 178:
#line 660 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 3121 "parser.tab.c"
    break;

  case 179:
#line 663 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3127 "parser.tab.c"
    break;

  case 180:
#line 663 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 3133 "parser.tab.c"
    break;

  case 181:
#line 664 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3139 "parser.tab.c"
    break;

  case 182:
#line 664 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 3145 "parser.tab.c"
    break;

  case 183:
#line 665 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3151 "parser.tab.c"
    break;

  case 184:
#line 665 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 3157 "parser.tab.c"
    break;

  case 185:
#line 666 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3163 "parser.tab.c"
    break;

  case 186:
#line 666 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 3169 "parser.tab.c"
    break;

  case 187:
#line 669 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 3175 "parser.tab.c"
    break;

  case 188:
#line 673 "parser.y"
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
#line 3199 "parser.tab.c"
    break;

  case 189:
#line 695 "parser.y"
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
#line 3223 "parser.tab.c"
    break;

  case 190:
#line 716 "parser.y"
                      { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            is_composite_val =false;}
#line 3231 "parser.tab.c"
    break;

  case 191:
#line 719 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3239 "parser.tab.c"
    break;

  case 192:
#line 722 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3247 "parser.tab.c"
    break;

  case 193:
#line 725 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s));
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3255 "parser.tab.c"
    break;

  case 194:
#line 728 "parser.y"
                      {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use mod on %s type",type_arr[expr_type]);} 
                                            (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 3262 "parser.tab.c"
    break;

  case 195:
#line 730 "parser.y"
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
#line 3279 "parser.tab.c"
    break;

  case 196:
#line 742 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 3285 "parser.tab.c"
    break;

  case 197:
#line 743 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s));if(expr_type == CLASS_TYPE){yyerror("Cannot use negetive on class type");}}
#line 3291 "parser.tab.c"
    break;

  case 198:
#line 744 "parser.y"
                       {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3298 "parser.tab.c"
    break;

  case 199:
#line 746 "parser.y"
                       {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use > with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3305 "parser.tab.c"
    break;

  case 200:
#line 748 "parser.y"
                            {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use <= with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3312 "parser.tab.c"
    break;

  case 201:
#line 750 "parser.y"
                             {if(expr_type == COMPLEX_TYPE|| expr_type == CLASS_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3319 "parser.tab.c"
    break;

  case 202:
#line 752 "parser.y"
                                        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                            (yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3326 "parser.tab.c"
    break;

  case 203:
#line 754 "parser.y"
                                        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                        (yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3333 "parser.tab.c"
    break;

  case 204:
#line 756 "parser.y"
                     {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                            (yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3340 "parser.tab.c"
    break;

  case 205:
#line 758 "parser.y"
                      {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");} 
                        (yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3347 "parser.tab.c"
    break;

  case 206:
#line 760 "parser.y"
                 {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                    char * t =join("(",(yyvsp[0].s),")");(yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3354 "parser.tab.c"
    break;

  case 208:
#line 765 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 3364 "parser.tab.c"
    break;

  case 209:
#line 770 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 3374 "parser.tab.c"
    break;

  case 210:
#line 775 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 3385 "parser.tab.c"
    break;

  case 211:
#line 781 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 3395 "parser.tab.c"
    break;

  case 212:
#line 786 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 3401 "parser.tab.c"
    break;

  case 214:
#line 790 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3413 "parser.tab.c"
    break;

  case 216:
#line 800 "parser.y"
                 { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
                    }else {
                    is_assignable = _t->m != CONST_TYPE;
                    is_callable = true;
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
#line 3441 "parser.tab.c"
    break;

  case 217:
#line 823 "parser.y"
                     {push_expr_and_args();}
#line 3447 "parser.tab.c"
    break;

  case 218:
#line 823 "parser.y"
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
                                                            is_callable = true;
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
#line 3480 "parser.tab.c"
    break;

  case 219:
#line 851 "parser.y"
                            {attr* a = NULL;
                                        a = (attr*)hm_get(current_class->attr,(yyvsp[0].s));
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[0].s),current_class->name);
                                        }else{
                                            is_assignable = a->m != CONST_TYPE;
                                            is_callable = true;
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
                                        }(yyval.s) = join("this","->",(yyvsp[0].s));free((yyvsp[0].s));}
#line 3505 "parser.tab.c"
    break;

  case 220:
#line 871 "parser.y"
                              {push_expr_and_args();}
#line 3511 "parser.tab.c"
    break;

  case 221:
#line 871 "parser.y"
                                                                               { attr* a = NULL;
                                                                            pop_expr_and_args();
                                                                            a = (attr*)hm_get(current_class->attr,(yyvsp[-5].s));
                                                                            if(a== NULL){
                                                                                yyerror("No attribute %s declared on class %s",(yyvsp[-5].s),current_class->name);
                                                                            }else{
                                                                                is_assignable = a->m != CONST_TYPE;
                                                                                is_callable = true;
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
                                                                                    expr_type = a->t.t;}}
                                                                            char * t = join("this","->",(yyvsp[-5].s));
                                                                            char *tt = join(t,"[",(yyvsp[-2].s));
                                                                            (yyval.s) = join(tt,"]","");
                                                                            free(t);free(tt);
                                                                            free((yyvsp[-5].s));free((yyvsp[-2].s));}
#line 3542 "parser.tab.c"
    break;

  case 222:
#line 897 "parser.y"
                              {push_expr_and_args();is_in_fncall=true;}
#line 3548 "parser.tab.c"
    break;

  case 223:
#line 897 "parser.y"
                                                                                    {if(!is_in_fn){yyerror("Function call is not allowed outside a function.");
                                                                                                    (yyval.s) = strdup("");
                                                                                                }else {
                                                                                                    method * m =(method*)hm_get(current_class->methods,(yyvsp[-4].s));
                                                                                                    if(m == NULL){
                                                                                                        yyerror("No method named %s found in class %s",(yyvsp[-4].s),current_class->name);
                                                                                                        (yyval.s) = strdup("");
                                                                                                    }else if(!is_callable){
                                                                                                        yyerror("methods can only be called directly on class type variables or members");
                                                                                                        (yyval.s) = strdup("");
                                                                                                    }else{
                                                                                                        verify_method_call((yyvsp[-4].s),m,yylineno);
                                                                                                        (yyval.s) = get_methodcall_str(m,"*this");
                                                                                                        ll_clear(arglist);
                                                                                                        pop_expr_and_args();
                                                                                                        type fn_ret = m->ret_t.t;
                                                                                                        if(expr_type == VOID_TYPE){
                                                                                                            if(m->is_ret_class){
                                                                                                                expr_type = CLASS_TYPE;
                                                                                                                expr_class = m->ret_t.class;
                                                                                                            }else{
                                                                                                                expr_type = fn_ret;
                                                                                                            }
                                                                                                        }else if(m->is_ret_class){
                                                                                                            expr_type = CLASS_TYPE;
                                                                                                            expr_class = m->ret_t.class;
                                                                                                        }else if(m->ret_t.t == VOID_TYPE){
                                                                                                            expr_type = VOID_TYPE;
                                                                                                        }else if(expr_type == STRING_TYPE || expr_type != VOID_TYPE && fn_ret == STRING_TYPE ){
                                                                                                            yyerror("Cannot combine string type with any type.");
                                                                                                        }else if((expr_type == BOOL_TYPE && fn_ret != BOOL_TYPE) ||
                                                                                                            (fn_ret ==BOOL_TYPE && expr_type !=BOOL_TYPE)){
                                                                                                                yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                                                                                                        }else if(expr_type == COMPLEX_TYPE || fn_ret == COMPLEX_TYPE){
                                                                                                            expr_type = COMPLEX_TYPE;
                                                                                                        }else if(expr_type == FLOAT_TYPE || fn_ret == FLOAT_TYPE || fn_ret == DOUBLE_TYPE){
                                                                                                            expr_type = FLOAT_TYPE;
                                                                                                        }}}
                                                                                                is_callable = false;free((yyvsp[-4].s));is_in_fncall = false;}
#line 3592 "parser.tab.c"
    break;

  case 224:
#line 936 "parser.y"
                                             { attr* a = NULL;
                                        if(expr_type == CLASS_TYPE){a = find_attr(expr_class,(yyvsp[0].s));
                                        }else{
                                            yyerror("Members can only be accessed on Class type variables");
                                        }
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[0].s),expr_class);
                                        }else{
                                            if(a->is_pvt){
                                                yyerror("Cannot access the private attribute %s outside the class",(yyvsp[0].s));
                                            }
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
#line 3624 "parser.tab.c"
    break;

  case 225:
#line 963 "parser.y"
                                                 {push_expr_and_args();}
#line 3630 "parser.tab.c"
    break;

  case 226:
#line 963 "parser.y"
                                                                                                  { attr* a = NULL;
                                                                                                pop_expr_and_args();
                                                                                            if(expr_type == CLASS_TYPE){a = find_attr(expr_class,(yyvsp[-5].s));
                                                                                                }else{
                                                                                                    yyerror("Members can only be accessed on Class type variables");
                                                                                                }
                                                                                            if(a== NULL){
                                                                                                yyerror("No attribute %s declared on class %s",(yyvsp[-8].s),(yyvsp[-5].s));
                                                                                            }else{
                                                                                                if(a->is_pvt){
                                                                                                    yyerror("Cannot access the private attribute %s outside the class",(yyvsp[-5].s));
                                                                                                }
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
                                                                                                    expr_type = a->t.t;}}
                                                                                            char * t = join((yyvsp[-8].s),".",(yyvsp[-5].s));
                                                                                            char *tt = join(t,"[",(yyvsp[-2].s));
                                                                                            (yyval.s) = join(tt,"]","");
                                                                                            free(t);free(tt);
                                                                                            free((yyvsp[-8].s));free((yyvsp[-5].s));free((yyvsp[-2].s));}
#line 3666 "parser.tab.c"
    break;

  case 227:
#line 994 "parser.y"
                                  {push_expr_and_args();is_in_fncall=true;}
#line 3672 "parser.tab.c"
    break;

  case 228:
#line 994 "parser.y"
                                                                                        {if(!is_in_fn){
                                                                                                    yyerror("Function call is not allowed outside a function.");
                                                                                                    (yyval.s) = strdup("");
                                                                                                }else {
                                                                                                    method * m =find_method(expr_class,(yyvsp[-4].s));
                                                                                                    if(m == NULL){
                                                                                                        yyerror("No method named %s found in class %s",(yyvsp[-4].s),expr_class);
                                                                                                        (yyval.s) = strdup("");
                                                                                                    }else if(!is_callable){
                                                                                                        yyerror("methods can only be called directly on class type variables or members");
                                                                                                        (yyval.s) = strdup("");
                                                                                                    }else if(m->is_pvt){
                                                                                                        yyerror("Cannot call private method %s outside the class",(yyvsp[-4].s));
                                                                                                        (yyval.s) = strdup("");
                                                                                                    }else{
                                                                                                    verify_method_call((yyvsp[-4].s),m,yylineno);
                                                                                                    (yyval.s) = get_methodcall_str(m,(yyvsp[-6].s));
                                                                                                    ll_clear(arglist);
                                                                                                    pop_expr_and_args();
                                                                                                    type fn_ret = m->ret_t.t;
                                                                                                    if(expr_type == VOID_TYPE){
                                                                                                        if(m->is_ret_class){
                                                                                                            expr_type = CLASS_TYPE;
                                                                                                            expr_class = m->ret_t.class;
                                                                                                        }else{
                                                                                                            expr_type = fn_ret;
                                                                                                        }
                                                                                                    }else if(m->is_ret_class){
                                                                                                        expr_type = CLASS_TYPE;
                                                                                                        expr_class = m->ret_t.class;
                                                                                                    }else if(m->ret_t.t == VOID_TYPE){
                                                                                                        expr_type = VOID_TYPE;
                                                                                                    }else if(expr_type == STRING_TYPE || expr_type != VOID_TYPE && fn_ret == STRING_TYPE ){
                                                                                                        yyerror("Cannot combine string type with any type.");
                                                                                                    }else if((expr_type == BOOL_TYPE && fn_ret != BOOL_TYPE) ||
                                                                                                        (fn_ret ==BOOL_TYPE && expr_type !=BOOL_TYPE)){
                                                                                                            yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                                                                                                    }else if(expr_type == COMPLEX_TYPE || fn_ret == COMPLEX_TYPE){
                                                                                                        expr_type = COMPLEX_TYPE;
                                                                                                    }else if(expr_type == FLOAT_TYPE || fn_ret == FLOAT_TYPE || fn_ret == DOUBLE_TYPE){
                                                                                                        expr_type = FLOAT_TYPE;
                                                                                                    }}
                                                                                                    }

                                                                                                is_callable = false;free((yyvsp[-6].s));free((yyvsp[-4].s));
                                                                                                is_in_fncall = false;}
#line 3723 "parser.tab.c"
    break;

  case 229:
#line 1042 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3729 "parser.tab.c"
    break;


#line 3733 "parser.tab.c"

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
#line 1044 "parser.y"


void main(int argc , char **argv){

    global_init();

    pre_class_map = make_hashmap(20, __hash_str__, __compair__str__);
    preparse();
    hm_delete(pre_class_map, pre_class_clean);
    switch_list();
    
    printcode("\n#line 1 \"%s\"\n\n",crr_file_name);
    yyparse();
    print_code_header();

    global_cleanup();

    
}
