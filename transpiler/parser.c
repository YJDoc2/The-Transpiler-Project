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

    void preparse(); // as preparse is a macro from preparser.l must be given here
    extern char *type_arr[],*mod_arr[];
    bool is_in_fn = false;
    bool has_returned = false;
    type fn_type = VOID_TYPE;
    type arg_type;
    type expr_type = VOID_TYPE;
    type arr_type = VOID_TYPE;
    modifier char_buf_mod = NONE_TYPE;
    bool is_val_arr = false;
    bool is_in_fncall = false;


#line 98 "parser.tab.c"

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
    I = 286,
    IN = 287,
    RAW = 288,
    USE = 289,
    DECL = 290,
    IDENTIFIER = 291,
    BOOLVAL = 292,
    STRINGVAL = 293,
    FNDECL = 294,
    RETTYPE = 295,
    INTNUM = 296,
    FLOATNUM = 297,
    RAWSTART = 298,
    RAWEND = 299,
    RAWLINE = 300,
    BEGINCOMMENT = 301,
    ENDCOMMENT = 302,
    COMMENTLINE = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "parser.y"

    char *s;
    type t;
    modifier m;

#line 205 "parser.tab.c"

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
#define YYLAST   868

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  152
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

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
      56,    57,    13,    11,    60,    12,    64,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       9,    63,    10,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
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
      51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    89,    90,    91,    95,    96,    97,   100,   101,
     102,   103,   104,   106,   107,   110,   120,   126,   127,   128,
     130,   131,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   145,   146,   147,   148,   149,   152,   152,   153,
     155,   156,   158,   165,   172,   175,   176,   176,   177,   177,
     180,   181,   184,   187,   192,   192,   193,   196,   201,   201,
     204,   210,   211,   211,   212,   212,   216,   218,   218,   219,
     219,   222,   223,   225,   227,   227,   230,   230,   233,   235,
     239,   244,   249,   249,   285,   286,   287,   290,   298,   316,
     335,   336,   337,   338,   339,   340,   343,   344,   345,   345,
     348,   352,   356,   356,   359,   359,   360,   360,   361,   361,
     362,   362,   365,   369,   383,   396,   397,   398,   399,   400,
     401,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   423,   425,   430,   435,   441,   455,   460,   461,
     462,   462,   491
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
  "ELSE", "RETURN", "WHILE", "I", "IN", "RAW", "USE", "DECL", "IDENTIFIER",
  "BOOLVAL", "STRINGVAL", "FNDECL", "\"->\"", "INTNUM", "FLOATNUM",
  "\"<{\"", "\"}>\"", "RAWLINE", "BEGINCOMMENT", "ENDCOMMENT",
  "COMMENTLINE", "';'", "'('", "')'", "'{'", "'}'", "','", "'['", "']'",
  "'='", "'.'", "$accept", "program", "type", "modifier", "topstmtlist",
  "topstmt", "rawlist", "fndeclaration", "fndecldummy", "paramlist",
  "param", "stmtlist", "stmt", "comment", "$@1", "commentlist",
  "returnstmt", "vardeclaration", "$@2", "$@3", "decllist", "varlist",
  "$@4", "$@5", "arraydecl", "$@6", "$@7", "arraydecldummy",
  "chararrdecllist", "$@8", "$@9", "strdecl", "$@10", "$@11",
  "arrayvallist", "fncall", "$@12", "arglist", "arg", "assignstmt",
  "assgtype", "ifstmt", "$@13", "ifdummy", "elsedummy", "whilestmt",
  "$@14", "forstmt", "$@15", "$@16", "$@17", "$@18", "rangecheckdummy",
  "simplearraydummy", "iterarraydummy", "expr", "value", "$@19",
  "cmplxnum", YY_NULLPTR
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
     299,   300,   301,   302,   303,    59,    40,    41,   123,   125,
      44,    91,    93,    61,    46
};
# endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-124)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -179,     6,   647,  -179,  -179,  -179,  -179,   -37,    47,   -33,
    -179,  -179,   161,  -179,  -179,  -179,   -31,  -179,   815,   -24,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,    77,    10,  -179,    79,    17,    52,  -179,
    -179,  -179,     2,    14,  -179,  -179,  -179,    38,   -40,    55,
      60,    61,    47,   815,  -179,    58,    82,   805,    73,    94,
    -179,    47,  -179,   107,   730,  -179,  -179,   805,   805,   -36,
    -179,  -179,  -179,  -179,   788,  -179,   618,  -179,  -179,   737,
    -179,    12,   815,    91,    21,   530,    58,   141,   141,  -179,
    -179,   121,   604,   805,   805,   805,   805,   805,   805,   805,
     805,   805,   805,   805,   805,   168,   128,   544,   805,    73,
    -179,   131,   747,   805,  -179,  -179,  -179,   805,   805,  -179,
     805,   618,   510,   510,    97,    97,    97,    97,    78,    78,
     177,   177,   177,   805,   137,   147,   618,  -179,   159,  -179,
    -179,   558,   618,    42,   637,   572,   141,   726,   618,  -179,
     160,  -179,  -179,   805,   805,  -179,   805,  -179,   618,  -179,
    -179,   805,  -179,   180,   151,   590,   618,  -179,    71,   618,
    -179,    67,   182,   805,   805,   805,   176,    -2,    16,  -179,
     171,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,   169,
    -179,  -179,   805,   805,  -179,  -179,  -179,    20,   698,   618,
     712,  -179,  -179,   165,   166,   167,   170,   172,   805,  -179,
     805,  -179,  -179,   173,   618,    95,   812,   189,  -179,  -179,
     106,  -179,  -179,  -179,  -179,  -179,   618,   618,   805,   179,
    -179,    25,   133,   200,  -179,  -179,  -179,   190,   115,  -179,
    -179,   192,   211,   222,   264,   -10,  -179,   805,   201,   805,
    -179,   226,  -179,   805,   117,  -179,   156,  -179,   204,   618,
    -179,   306,   202,  -179,   209,  -179,   235,  -179,   805,   212,
    -179,  -179,  -179,   618,  -179,   348,   390,  -179,   432,  -179,
    -179,   213,  -179,  -179,   474,  -179
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
      47,    49,     0,    17,    21,    22,    20,    23,     0,     0,
      50,     8,     9,     7,     6,     4,     5,    10,     3,    11,
      58,    56,    19,     0,     0,    27,     0,     0,     0,    18,
      24,    60,    55,    12,    48,    51,    77,    59,    62,    57,
       0,     0,    12,     0,    28,     0,     0,     0,     0,     0,
      61,    12,    29,     0,     0,    78,    79,     0,     0,   146,
     147,   148,   144,   145,     0,   149,    63,   142,   143,     0,
      65,    66,     0,    30,     0,     0,     0,   132,   141,    92,
     150,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    71,     0,     0,     0,
      26,     0,     0,     0,    76,    80,    94,     0,     0,   131,
       0,   137,   139,   140,   135,   136,   133,   134,   125,   126,
     127,   128,   129,     0,     0,    70,    67,    69,     0,    31,
      89,     0,    83,    81,     0,     0,   130,     0,   138,    72,
       0,    32,    76,     0,     0,    93,     0,    95,    97,   151,
     152,     0,    76,     0,     0,     0,    82,    96,     0,    90,
      74,     0,     0,     0,    53,     0,     0,    12,     0,    25,
      37,    38,    45,    43,    44,    46,    39,    40,    41,     0,
      76,    73,     0,     0,    33,    35,    34,     0,     0,    52,
       0,    23,    54,     0,     0,     0,     0,     0,     0,   100,
       0,    36,    86,    88,    91,     0,     0,     0,   110,   112,
       0,   101,   102,   103,   104,   105,    76,    98,     0,     0,
      75,   146,     0,     0,    32,    32,    42,     0,     0,    84,
     118,     0,     0,     0,     0,     0,    87,     0,     0,     0,
     124,   106,   113,     0,     0,    32,   122,   120,   108,    99,
      85,     0,     0,   114,     0,   111,     0,   119,     0,     0,
      32,    32,   109,   122,    32,     0,     0,   116,     0,   121,
     107,     0,   115,    32,     0,   117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,    -4,     5,  -179,  -179,    68,  -179,  -179,  -179,
     220,  -170,  -179,   271,  -179,  -179,  -179,   273,  -179,  -179,
    -179,  -179,  -179,  -179,   185,  -179,  -179,  -136,  -179,  -179,
    -179,   191,  -179,  -179,  -178,  -155,  -179,  -179,   122,  -179,
      34,    29,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,     7,  -179,  -179,   -57,  -179,  -179,  -179
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    31,    12,     2,    13,    33,    14,   138,    43,
      54,   163,   180,   181,    20,    36,   182,   183,    38,    37,
      42,    49,    58,   109,    80,   161,   193,   143,    47,    55,
      86,    65,   247,   228,   168,    75,   116,   144,   157,   185,
     210,   186,   266,   234,   271,   187,   235,   188,   269,   281,
     248,   264,   263,   240,   257,   169,    77,   117,    78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      76,   203,   204,   205,   206,   207,     3,    85,   184,    19,
      87,    88,    17,    18,    34,   215,   164,    92,     5,     6,
      89,   -64,   107,    57,    32,    90,   170,   203,   204,   205,
     206,   207,    35,   202,     5,     6,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    53,    63,
     238,   136,    41,   209,   213,   141,   142,    53,   216,    46,
     145,   146,    50,   147,   243,   244,    82,     5,     6,   254,
      91,    51,    89,   -68,    52,   108,   148,   208,   110,   209,
     217,    89,   112,  -123,   113,   261,    90,   158,   184,   184,
     237,   102,   103,   104,    48,   105,   165,   166,    56,   158,
     275,   276,    60,   153,   278,   154,   184,    61,   100,   101,
     102,   103,   104,   284,   105,    59,   198,   199,   200,    64,
     184,   184,   194,   184,    66,   195,   196,    39,    40,   184,
     191,   192,    44,    45,    79,   214,    81,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    83,
     105,   226,   111,   227,   230,   192,   236,    40,  -124,   232,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   133,   105,   246,   192,   260,   192,   118,    21,
      22,   171,    18,    23,    24,    25,    26,    27,    28,    29,
      30,   134,   256,   139,   105,   149,   259,   241,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     150,   273,   172,   173,   189,   174,   175,   151,   162,   176,
     262,   177,   178,   171,   197,   201,   211,   212,   221,   222,
     223,   233,    10,   224,    11,   225,   229,   239,   242,   179,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   245,   250,   172,   173,   249,   174,   175,   255,
     258,   176,   265,   177,   178,   171,   268,   270,   173,   220,
     274,   283,    62,    15,    10,    16,    11,   115,   167,   253,
     277,   251,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   137,   272,   172,   173,     0,   174,
     175,     0,     0,   176,     0,   177,   178,   171,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,    11,     0,
       0,     0,     0,   252,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,     0,     0,   172,   173,
       0,   174,   175,     0,     0,   176,     0,   177,   178,   171,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
      11,     0,     0,     0,     0,   267,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,     0,
     172,   173,     0,   174,   175,     0,     0,   176,     0,   177,
     178,   171,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,    11,     0,     0,     0,     0,   279,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
       0,     0,   172,   173,     0,   174,   175,     0,     0,   176,
       0,   177,   178,   171,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    11,     0,     0,     0,     0,   280,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,     0,     0,   172,   173,     0,   174,   175,     0,
       0,   176,     0,   177,   178,   171,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    11,     0,     0,     0,
       0,   282,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,     0,     0,   172,   173,     0,   174,
     175,     0,     0,   176,     0,   177,   178,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    10,   105,    11,     0,
       0,     0,     0,   285,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,   114,     0,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   135,   105,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     152,   105,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   159,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -2,     4,    67,
       0,     0,   190,     0,    68,     0,     0,     0,     0,     0,
       0,   119,     0,     0,   120,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,     0,    69,
      70,    71,     0,     0,    72,    73,     7,     0,     8,     0,
       0,     0,     9,    74,   155,     0,     0,   156,     0,    10,
       0,    11,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    67,   105,     0,     0,     0,    68,     0,    67,
       0,     0,     0,     0,    68,     0,   218,     0,     0,    67,
       0,     0,     0,     0,    68,     0,     0,     0,     0,     0,
     219,     0,    69,    70,    71,     0,     0,    72,    73,    69,
      70,    71,     0,   160,    72,    73,    74,     0,     0,    69,
      70,    71,    84,    74,    72,    73,     0,     0,     0,   106,
      67,     0,     0,    74,     0,    68,    21,    22,     0,   140,
      23,    24,    25,    26,    27,    28,    29,    67,     0,     0,
       0,     0,    68,     0,    67,     0,     0,     0,     0,    68,
      69,    70,    71,    21,    22,    72,    73,    23,    24,    25,
      26,    27,    28,    29,    74,     0,     0,    69,    70,    71,
       0,     0,    72,    73,   231,    70,    71,     0,     0,    72,
      73,    74,     0,     0,     0,     0,     0,     0,    74
};

static const yytype_int16 yycheck[] =
{
      57,    11,    12,    13,    14,    15,     0,    64,   163,    42,
      67,    68,    49,     8,    18,   193,   152,    74,    20,    21,
      56,    61,    79,    63,    55,    61,   162,    11,    12,    13,
      14,    15,    56,    35,    20,    21,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    43,    53,
     228,   108,    42,    63,   190,   112,   113,    52,    38,    42,
     117,   118,    60,   120,   234,   235,    61,    20,    21,   247,
      74,    57,    56,    61,    60,    63,   133,    61,    82,    63,
      60,    56,    61,    58,    63,   255,    61,   144,   243,   244,
     226,    13,    14,    15,    42,    17,   153,   154,    60,   156,
     270,   271,    42,    61,   274,    63,   261,    46,    11,    12,
      13,    14,    15,   283,    17,    60,   173,   174,   175,    61,
     275,   276,    55,   278,    42,    58,    59,    50,    51,   284,
      59,    60,    53,    54,    61,   192,    42,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    42,
      17,   208,    61,   210,    59,    60,    50,    51,    17,   216,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     4,    17,    59,    60,    59,    60,    57,    18,
      19,     1,   177,    22,    23,    24,    25,    26,    27,    28,
      29,    63,   249,    62,    17,    58,   253,    64,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      63,   268,    32,    33,    63,    35,    36,    58,    58,    39,
      64,    41,    42,     1,    42,    49,    55,    58,    63,    63,
      63,    42,    52,    63,    54,    63,    63,    58,    38,    59,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    62,    42,    32,    33,    64,    35,    36,    58,
      34,    39,    58,    41,    42,     1,    64,    58,    33,   201,
      58,    58,    52,     2,    52,     2,    54,    86,   156,   245,
     273,    59,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,   109,   266,    32,    33,    -1,    35,
      36,    -1,    -1,    39,    -1,    41,    42,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    54,    -1,
      -1,    -1,    -1,    59,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    35,    36,    -1,    -1,    39,    -1,    41,    42,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      54,    -1,    -1,    -1,    -1,    59,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    -1,    35,    36,    -1,    -1,    39,    -1,    41,
      42,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    54,    -1,    -1,    -1,    -1,    59,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    35,    36,    -1,    -1,    39,
      -1,    41,    42,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    54,    -1,    -1,    -1,    -1,    59,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    35,    36,    -1,
      -1,    39,    -1,    41,    42,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    54,    -1,    -1,    -1,
      -1,    59,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    -1,    35,
      36,    -1,    -1,    39,    -1,    41,    42,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    52,    17,    54,    -1,
      -1,    -1,    -1,    59,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    62,    -1,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    62,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      62,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    62,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    12,
      -1,    -1,    62,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    60,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    42,
      43,    44,    -1,    -1,    47,    48,    39,    -1,    41,    -1,
      -1,    -1,    45,    56,    57,    -1,    -1,    60,    -1,    52,
      -1,    54,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    12,    17,    -1,    -1,    -1,    17,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    58,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    42,    43,    44,    -1,    -1,    47,    48,    42,
      43,    44,    -1,    57,    47,    48,    56,    -1,    -1,    42,
      43,    44,    62,    56,    47,    48,    -1,    -1,    -1,    62,
      12,    -1,    -1,    56,    -1,    17,    18,    19,    -1,    62,
      22,    23,    24,    25,    26,    27,    28,    12,    -1,    -1,
      -1,    -1,    17,    -1,    12,    -1,    -1,    -1,    -1,    17,
      42,    43,    44,    18,    19,    47,    48,    22,    23,    24,
      25,    26,    27,    28,    56,    -1,    -1,    42,    43,    44,
      -1,    -1,    47,    48,    42,    43,    44,    -1,    -1,    47,
      48,    56,    -1,    -1,    -1,    -1,    -1,    -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,    69,     0,     1,    20,    21,    39,    41,    45,
      52,    54,    68,    70,    72,    78,    82,    49,    68,    42,
      79,    18,    19,    22,    23,    24,    25,    26,    27,    28,
      29,    67,    55,    71,    67,    56,    80,    84,    83,    50,
      51,    42,    85,    74,    53,    54,    42,    93,    42,    86,
      60,    57,    60,    68,    75,    94,    60,    63,    87,    60,
      42,    46,    75,    67,    61,    96,    42,    12,    17,    42,
      43,    44,    47,    48,    56,   100,   120,   121,   123,    61,
      89,    42,    68,    42,    62,   120,    95,   120,   120,    56,
      61,    67,   120,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    17,    62,   120,    63,    88,
      67,    61,    61,    63,    62,    96,   101,   122,    57,    57,
      60,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,     4,    63,    62,   120,    89,    73,    62,
      62,   120,   120,    92,   102,   120,   120,   120,   120,    58,
      63,    58,    62,    61,    63,    57,    60,   103,   120,    62,
      57,    90,    58,    76,    92,   120,   120,   103,    99,   120,
      92,     1,    32,    33,    35,    36,    39,    41,    42,    59,
      77,    78,    81,    82,   100,   104,   106,   110,   112,    63,
      62,    59,    60,    91,    55,    58,    59,    42,   120,   120,
     120,    49,    35,    11,    12,    13,    14,    15,    61,    63,
     105,    55,    58,    92,   120,    99,    38,    60,    58,    58,
      71,    63,    63,    63,    63,    63,   120,   120,    98,    63,
      59,    42,   120,    42,   108,   111,    50,    92,    99,    58,
     118,    64,    38,    76,    76,    62,    59,    97,   115,    64,
      42,    59,    59,   105,    99,    58,   120,   119,    34,   120,
      59,    76,    64,   117,   116,    58,   107,    59,    64,   113,
      58,   109,   106,   120,    58,    76,    76,   117,    76,    59,
      59,   114,    59,    58,    76,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    68,    68,    68,    69,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    72,    73,    74,    74,    74,
      75,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    77,    79,    78,    78,
      80,    80,    81,    81,    81,    82,    83,    82,    84,    82,
      85,    85,    86,    86,    87,    86,    86,    86,    88,    86,
      89,    89,    90,    89,    91,    89,    92,    94,    93,    95,
      93,    96,    96,    96,    97,    96,    98,    96,    96,    96,
      99,    99,   101,   100,   102,   102,   102,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   106,
     108,   109,   111,   110,   113,   112,   114,   112,   115,   112,
     116,   112,   117,   118,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   121,   121,
     122,   121,   123
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     0,     2,    12,     0,     0,     2,     3,
       3,     5,     0,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     4,     1,     1,     1,     1,     0,     4,     1,
       0,     2,     2,     1,     2,     4,     0,     4,     0,     4,
       1,     3,     1,     3,     0,     3,     3,     5,     0,     5,
       3,     2,     0,     7,     0,     9,     0,     0,     3,     0,
       5,     4,     6,     4,     0,    13,     0,    11,     8,     4,
       1,     3,     0,     5,     0,     2,     3,     1,     3,     7,
       1,     2,     2,     2,     2,     2,     6,    11,     0,     9,
       0,     0,     0,     6,     0,    12,     0,    15,     0,     9,
       0,    11,     0,     0,     0,     3,     3,     3,     3,     3,
       4,     3,     2,     3,     3,     3,     3,     3,     4,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     5
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
#line 89 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1706 "parser.tab.c"
    break;

  case 16:
#line 96 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1712 "parser.tab.c"
    break;

  case 18:
#line 100 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1718 "parser.tab.c"
    break;

  case 19:
#line 101 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1724 "parser.tab.c"
    break;

  case 20:
#line 102 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1730 "parser.tab.c"
    break;

  case 21:
#line 103 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1736 "parser.tab.c"
    break;

  case 24:
#line 107 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1742 "parser.tab.c"
    break;

  case 25:
#line 110 "parser.y"
                                                                                                  {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 1756 "parser.tab.c"
    break;

  case 26:
#line 120 "parser.y"
                            {print_fn_delc((yyvsp[(-6) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;
                            pushscope();}
#line 1766 "parser.tab.c"
    break;

  case 30:
#line 130 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 1772 "parser.tab.c"
    break;

  case 31:
#line 131 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 1778 "parser.tab.c"
    break;

  case 33:
#line 134 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1784 "parser.tab.c"
    break;

  case 34:
#line 135 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1790 "parser.tab.c"
    break;

  case 35:
#line 136 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1796 "parser.tab.c"
    break;

  case 36:
#line 137 "parser.y"
                        {expr_type= VOID_TYPE;}
#line 1802 "parser.tab.c"
    break;

  case 37:
#line 138 "parser.y"
                    {yyerror("missing ;");expr_type =  VOID_TYPE;}
#line 1808 "parser.tab.c"
    break;

  case 42:
#line 145 "parser.y"
                             {printcode("%s",(yyvsp[0].s));}
#line 1814 "parser.tab.c"
    break;

  case 44:
#line 147 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 1820 "parser.tab.c"
    break;

  case 47:
#line 152 "parser.y"
                       {printcode("/*");}
#line 1826 "parser.tab.c"
    break;

  case 48:
#line 152 "parser.y"
                                                                 {printcode("*/");}
#line 1832 "parser.tab.c"
    break;

  case 49:
#line 153 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 1838 "parser.tab.c"
    break;

  case 51:
#line 156 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 1844 "parser.tab.c"
    break;

  case 52:
#line 158 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 1856 "parser.tab.c"
    break;

  case 53:
#line 165 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 1868 "parser.tab.c"
    break;

  case 54:
#line 172 "parser.y"
                          {has_returned = true;}
#line 1874 "parser.tab.c"
    break;

  case 56:
#line 176 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 1880 "parser.tab.c"
    break;

  case 57:
#line 176 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 1886 "parser.tab.c"
    break;

  case 58:
#line 177 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 1892 "parser.tab.c"
    break;

  case 59:
#line 177 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 1898 "parser.tab.c"
    break;

  case 60:
#line 180 "parser.y"
                     {create_var((yyvsp[(-1) - (1)].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 1904 "parser.tab.c"
    break;

  case 61:
#line 181 "parser.y"
                              {create_var((yyvsp[(-1) - (3)].m),(yyvsp[-3].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 1910 "parser.tab.c"
    break;

  case 62:
#line 184 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 1918 "parser.tab.c"
    break;

  case 63:
#line 187 "parser.y"
                          {  //asm("int3");
                                if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 1928 "parser.tab.c"
    break;

  case 64:
#line 192 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 1934 "parser.tab.c"
    break;

  case 65:
#line 192 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 1940 "parser.tab.c"
    break;

  case 66:
#line 193 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 1948 "parser.tab.c"
    break;

  case 67:
#line 196 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 1958 "parser.tab.c"
    break;

  case 68:
#line 201 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 1964 "parser.tab.c"
    break;

  case 69:
#line 201 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 1970 "parser.tab.c"
    break;

  case 70:
#line 204 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 1981 "parser.tab.c"
    break;

  case 71:
#line 210 "parser.y"
                      {yyerror("Array size missing");}
#line 1987 "parser.tab.c"
    break;

  case 72:
#line 211 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 1993 "parser.tab.c"
    break;

  case 73:
#line 211 "parser.y"
                                                                         {printcode(" }");}
#line 1999 "parser.tab.c"
    break;

  case 74:
#line 212 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2005 "parser.tab.c"
    break;

  case 75:
#line 212 "parser.y"
                                                                                                          {printcode(" }");}
#line 2011 "parser.tab.c"
    break;

  case 76:
#line 216 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2017 "parser.tab.c"
    break;

  case 77:
#line 218 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2023 "parser.tab.c"
    break;

  case 78:
#line 218 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2029 "parser.tab.c"
    break;

  case 79:
#line 219 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2035 "parser.tab.c"
    break;

  case 80:
#line 219 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2041 "parser.tab.c"
    break;

  case 81:
#line 222 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2047 "parser.tab.c"
    break;

  case 82:
#line 223 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2054 "parser.tab.c"
    break;

  case 83:
#line 225 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2061 "parser.tab.c"
    break;

  case 84:
#line 227 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2067 "parser.tab.c"
    break;

  case 85:
#line 227 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2075 "parser.tab.c"
    break;

  case 86:
#line 230 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2081 "parser.tab.c"
    break;

  case 87:
#line 230 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2089 "parser.tab.c"
    break;

  case 88:
#line 233 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2095 "parser.tab.c"
    break;

  case 89:
#line 235 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2101 "parser.tab.c"
    break;

  case 90:
#line 239 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2111 "parser.tab.c"
    break;

  case 91:
#line 244 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2120 "parser.tab.c"
    break;

  case 92:
#line 249 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2126 "parser.tab.c"
    break;

  case 93:
#line 249 "parser.y"
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
                                            pop_expr_and_args();\
                                            // TODOverify error types...
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
#line 2165 "parser.tab.c"
    break;

  case 97:
#line 290 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_val_arr){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_val_arr = false;}
#line 2176 "parser.tab.c"
    break;

  case 98:
#line 298 "parser.y"
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
#line 2199 "parser.tab.c"
    break;

  case 99:
#line 316 "parser.y"
                                                                  {Variable *var = lookup_var((yyvsp[-6].s));
                                    if(var == NULL){
                                        yyerror("Undeclared variable %s.",(yyvsp[-6].s));
                                    }else if(!var->is_arr){
                                        yyerror("Cannot subscript a non-array type variable");
                                    }else if(var->m == CONST_TYPE){
                                        yyerror("Cannot assign to constant variable.");
                                    }else if(verify_types(var->t,expr_type)){
                                        yyerror("cannot assign type %s to variable of type %s",type_arr[var->t],type_arr[expr_type]);
                                    }else if(var->t == COMPLEX_TYPE && strcmp((yyvsp[-1].s),"%=")==0){
                                        yyerror("Cannot use mod on complex type");
                                    }else{
                                        printcode("%s[%s] %s %s;",(yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),(yyvsp[0].s));
                                    }
                                    expr_type = VOID_TYPE;
                                    // No need to free $2, its const char *
                                    free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2221 "parser.tab.c"
    break;

  case 100:
#line 335 "parser.y"
                {(yyval.s) = "=";}
#line 2227 "parser.tab.c"
    break;

  case 101:
#line 336 "parser.y"
              {(yyval.s) = "+=";}
#line 2233 "parser.tab.c"
    break;

  case 102:
#line 337 "parser.y"
              {(yyval.s) = "-=";}
#line 2239 "parser.tab.c"
    break;

  case 103:
#line 338 "parser.y"
              {(yyval.s) = "*=";}
#line 2245 "parser.tab.c"
    break;

  case 104:
#line 339 "parser.y"
              {(yyval.s) = "/=";}
#line 2251 "parser.tab.c"
    break;

  case 105:
#line 340 "parser.y"
              {(yyval.s) = "%=";}
#line 2257 "parser.tab.c"
    break;

  case 106:
#line 343 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2263 "parser.tab.c"
    break;

  case 107:
#line 344 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2269 "parser.tab.c"
    break;

  case 108:
#line 345 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2275 "parser.tab.c"
    break;

  case 110:
#line 348 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2281 "parser.tab.c"
    break;

  case 111:
#line 352 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2287 "parser.tab.c"
    break;

  case 112:
#line 356 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2293 "parser.tab.c"
    break;

  case 113:
#line 356 "parser.y"
                                                                                                                                                                  {printcode(" }");popscope();expr_type=VOID_TYPE;}
#line 2299 "parser.tab.c"
    break;

  case 114:
#line 359 "parser.y"
                                                              {pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2305 "parser.tab.c"
    break;

  case 115:
#line 359 "parser.y"
                                                                                                                                                                                                             {printcode("}");popscope();}
#line 2311 "parser.tab.c"
    break;

  case 116:
#line 360 "parser.y"
                                                                       {pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));}
#line 2317 "parser.tab.c"
    break;

  case 117:
#line 360 "parser.y"
                                                                                                                                                                                                                         {printcode("}");popscope();}
#line 2323 "parser.tab.c"
    break;

  case 118:
#line 361 "parser.y"
                                                    {free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2329 "parser.tab.c"
    break;

  case 119:
#line 361 "parser.y"
                                                                                          {printcode("}");popscope();}
#line 2335 "parser.tab.c"
    break;

  case 120:
#line 362 "parser.y"
                                                                 {free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2341 "parser.tab.c"
    break;

  case 121:
#line 362 "parser.y"
                                                                                                                {printcode("}");popscope();}
#line 2347 "parser.tab.c"
    break;

  case 122:
#line 365 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2353 "parser.tab.c"
    break;

  case 123:
#line 369 "parser.y"
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
#line 2369 "parser.tab.c"
    break;

  case 124:
#line 383 "parser.y"
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
#line 2385 "parser.tab.c"
    break;

  case 125:
#line 396 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 2391 "parser.tab.c"
    break;

  case 126:
#line 397 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 2397 "parser.tab.c"
    break;

  case 127:
#line 398 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 2403 "parser.tab.c"
    break;

  case 128:
#line 399 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 2409 "parser.tab.c"
    break;

  case 129:
#line 400 "parser.y"
                     {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use mod on complex");}(yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 2415 "parser.tab.c"
    break;

  case 130:
#line 401 "parser.y"
                                         {void * v = calloc(1,3+strlen(type_arr[(yyvsp[-2].t)])); // 2 for '()' one for end-of-string 0
                                sprintf(v,"(%s) ",type_arr[(yyvsp[-2].t)]);
                                char * t = join("(",(yyvsp[0].s),")");
                                (yyval.s) = join(v,"",t);
                                 is_val_arr =false;
                                free(v);
                                free(t);
                                free((yyvsp[0].s));
                                expr_type = (yyvsp[-2].t);
                            }
#line 2430 "parser.tab.c"
    break;

  case 131:
#line 411 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_val_arr =false;}
#line 2436 "parser.tab.c"
    break;

  case 132:
#line 412 "parser.y"
                            {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_val_arr =false;}
#line 2442 "parser.tab.c"
    break;

  case 133:
#line 413 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with complex type");}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2448 "parser.tab.c"
    break;

  case 134:
#line 414 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use > with complex type");}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2454 "parser.tab.c"
    break;

  case 135:
#line 415 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use <= with complex type");}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2460 "parser.tab.c"
    break;

  case 136:
#line 416 "parser.y"
                              {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with complex type");}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2466 "parser.tab.c"
    break;

  case 137:
#line 417 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2472 "parser.tab.c"
    break;

  case 138:
#line 418 "parser.y"
                                          {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2478 "parser.tab.c"
    break;

  case 139:
#line 419 "parser.y"
                    {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2484 "parser.tab.c"
    break;

  case 140:
#line 420 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2490 "parser.tab.c"
    break;

  case 141:
#line 421 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2497 "parser.tab.c"
    break;

  case 143:
#line 425 "parser.y"
                 {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2507 "parser.tab.c"
    break;

  case 144:
#line 430 "parser.y"
             {if( expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 2517 "parser.tab.c"
    break;

  case 145:
#line 435 "parser.y"
               { if( expr_type == STRING_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 2528 "parser.tab.c"
    break;

  case 146:
#line 441 "parser.y"
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
#line 2547 "parser.tab.c"
    break;

  case 147:
#line 455 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 2557 "parser.tab.c"
    break;

  case 148:
#line 460 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 2563 "parser.tab.c"
    break;

  case 150:
#line 462 "parser.y"
                     {push_expr_and_args();}
#line 2569 "parser.tab.c"
    break;

  case 151:
#line 462 "parser.y"
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
                                                        is_val_arr = true;
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
#line 2601 "parser.tab.c"
    break;

  case 152:
#line 491 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2613 "parser.tab.c"
    break;


#line 2617 "parser.tab.c"

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
#line 499 "parser.y"


void main(int argc , char **argv){

    __init_io__("./test.ttp",NULL);
    __init_literals__();
    __init_vars__();
    __init_actions__();
    __init_functions__();
    __init_scopes__();
    __init_expr__();
    preparse();
    yyparse();
    __cleanup_expr__();
    __cleanup_scopes__();
    __cleanup_functions__();
    __cleanup_actions__();
    __cleanup_vars__();
    __cleanup_literals__();
    __cleanup_io__();
}
