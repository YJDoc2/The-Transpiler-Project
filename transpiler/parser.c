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


#line 97 "parser.tab.c"

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
    MOD = 258,
    UMINUS = 259,
    BOOL = 260,
    COMPLEX = 261,
    CONST = 262,
    STATIC = 263,
    DOUBLE = 264,
    FLOAT = 265,
    LONG = 266,
    SHORT = 267,
    VOID = 268,
    INT = 269,
    STRING = 270,
    CHARBUF = 271,
    BREAK = 272,
    CONTINUE = 273,
    ELSE = 274,
    FOR = 275,
    IF = 276,
    RETURN = 277,
    WHILE = 278,
    I = 279,
    IN = 280,
    NOT = 281,
    RAW = 282,
    USE = 283,
    DECL = 284,
    IDENTIFIER = 285,
    BOOLVAL = 286,
    STRINGVAL = 287,
    FNDECL = 288,
    RETTYPE = 289,
    INTNUM = 290,
    FLOATNUM = 291,
    RAWSTART = 292,
    RAWEND = 293,
    RAWLINE = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

    char *s;
    type t;
    modifier m;

#line 195 "parser.tab.c"

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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   294


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
      45,    46,     5,     3,    49,     4,     2,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
       2,    52,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    50,     2,    51,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    81,    82,    83,    87,    88,    89,    92,    93,
      94,    95,    97,    98,   101,   111,   117,   118,   119,   121,
     122,   124,   125,   126,   127,   130,   131,   132,   133,   136,
     137,   137,   138,   138,   141,   142,   145,   148,   153,   153,
     154,   157,   162,   162,   165,   171,   172,   172,   173,   173,
     177,   179,   179,   180,   180,   183,   184,   186,   188,   188,
     191,   191,   194,   196,   200,   205,   210,   210,   246,   247,
     248,   251,   259,   266,   274,   275,   276,   277,   278,   279,
     289,   290,   291,   293,   298,   303,   308,   322,   327,   328,
     329,   329,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'+'", "'-'", "'*'", "'/'", "MOD",
  "UMINUS", "BOOL", "COMPLEX", "CONST", "STATIC", "DOUBLE", "FLOAT",
  "LONG", "SHORT", "VOID", "INT", "STRING", "CHARBUF", "BREAK", "CONTINUE",
  "ELSE", "FOR", "IF", "RETURN", "WHILE", "I", "IN", "NOT", "RAW", "USE",
  "DECL", "IDENTIFIER", "BOOLVAL", "STRINGVAL", "FNDECL", "\"->\"",
  "INTNUM", "FLOATNUM", "\"<{\"", "\"}>\"", "RAWLINE", "';'", "'('", "')'",
  "'{'", "'}'", "','", "'['", "']'", "'='", "$accept", "program", "type",
  "modifier", "topstmtlist", "topstmt", "rawlist", "fndeclaration",
  "fndecldummy", "paramlist", "param", "stmtlist", "stmt",
  "vardeclaration", "$@1", "$@2", "decllist", "varlist", "$@3", "$@4",
  "arraydecl", "$@5", "$@6", "arraydecldummy", "chararrdecllist", "$@7",
  "$@8", "strdecl", "$@9", "$@10", "arrayvallist", "fncall", "$@11",
  "arglist", "arg", "returnstmt", "expr", "value", "$@12", "cmplxnum", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,    43,    45,    42,    47,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,    59,    40,    41,   123,   125,    44,
      91,    93,    61
};
# endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -65,     2,   205,   -65,   -65,   -65,   -65,   -32,    56,    10,
     230,   -65,   -65,   -24,   -65,   242,    26,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   -65,    84,
      13,   -65,    45,    67,   -65,   -65,   -65,    59,    -7,   -65,
      65,   -44,    73,    99,   104,    56,   242,   -65,    87,   121,
     155,   100,   145,   -65,    56,   -65,   146,    89,   -65,   -65,
     155,    -2,   -65,   -65,   -65,   -65,   168,   -65,   223,   -65,
     -65,    96,   -65,    22,   242,   138,    47,     8,    87,   -65,
     -65,   -65,   150,   112,   155,   155,   155,   155,   155,    94,
      19,   155,   100,   -65,   147,   109,   155,   -65,   -65,   -65,
     155,   155,   -65,   155,    12,    12,   -65,   -65,   -65,   152,
     149,   223,   -65,   162,   -65,   -65,    24,   223,    60,   117,
      51,   -65,   164,   -65,   165,   -65,   -65,   155,   155,   -65,
     155,   -65,   223,   -65,   -65,   155,   -65,    72,   159,    58,
     223,   -65,    90,   223,   -65,   153,   155,   190,   187,   -65,
     189,   -65,   -65,   -65,   188,   -65,   -65,   155,   155,   -65,
     223,   -65,   -65,   -65,   182,   223,   116,   131,   155,   194,
     -65,   -65,   127,   -65,   -65,   155,   144,   -65
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    17,    21,    20,    22,     0,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    42,    40,    19,     0,
       0,    26,     0,     0,    18,    23,    44,    39,    12,    61,
      43,    46,    41,     0,     0,    12,     0,    27,     0,     0,
       0,     0,     0,    45,    12,    28,     0,     0,    62,    63,
       0,    96,    97,    98,    94,    95,     0,    99,    47,    92,
      93,     0,    49,    50,     0,    29,     0,     0,     0,    91,
      76,   100,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,    25,     0,     0,     0,    60,    64,    78,
       0,     0,    90,     0,    84,    85,    86,    87,    88,     0,
      54,    51,    53,     0,    30,    73,     0,    67,    65,     0,
       0,    89,     0,    56,     0,    31,    60,     0,     0,    77,
       0,    79,    81,   101,   102,     0,    60,     0,     0,     0,
      66,    80,     0,    74,    58,     0,    83,     0,     0,    24,
      34,    36,    37,    38,     0,    60,    57,     0,     0,    32,
      82,    22,    33,    70,    72,    75,     0,     0,     0,     0,
      59,    35,     0,    68,    71,     0,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -65,   -65,   -14,    -5,   -65,   -65,    76,   -65,   -65,   -65,
     208,   -65,   -65,   125,   -65,   -65,   -65,   -65,   -65,   -65,
     171,   -65,   -65,   -60,   -65,   -65,   -65,   176,   -65,   -65,
     -64,   128,   -65,   -65,   134,   -65,   -50,   -65,   -65,   -65
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    27,    10,     2,    11,    29,    12,   113,    38,
      47,   137,   150,    13,    33,    32,    37,    42,    51,    92,
      72,   135,   158,   118,    40,    48,    78,    58,   175,   168,
     142,    67,    99,   119,   131,   153,   143,    69,   100,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      68,    30,     3,    15,     5,     6,   -48,    77,    50,    14,
      79,    84,    85,    86,    87,    88,    83,    86,    87,    88,
      28,    90,    84,    85,    86,    87,    88,    84,    85,    86,
      87,    88,    56,    46,   104,   105,   106,   107,   108,    44,
      46,   111,    45,    80,    16,   116,   117,    36,    81,    74,
     120,   121,    82,   122,    84,    85,    86,    87,    88,    97,
      93,    84,    85,    86,    87,    88,   138,     5,     6,   132,
     110,    31,   -52,   145,    91,   126,   144,   139,   140,    39,
     132,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,    60,   166,   164,   160,    95,   146,    96,
      60,    41,   133,   147,   172,     8,   148,   165,    43,   155,
     127,   176,   128,    60,    49,    84,    85,    86,    87,    88,
     149,    60,    52,    61,    62,    63,    34,    35,    64,    65,
      61,    62,    63,    53,    66,    64,    65,    57,   156,   157,
      76,    66,    54,    61,    62,    63,   109,    89,    64,    65,
      71,    61,    62,    63,    66,    59,    64,    65,   102,    60,
     115,   103,    66,   129,   170,   157,   130,    84,    85,    86,
      87,    88,    60,   171,    35,   174,   157,    17,    18,    73,
      75,    19,    20,    21,    22,    23,    24,    25,    94,    61,
      62,    63,   177,   157,    64,    65,   101,   159,   114,   123,
      66,   124,    61,    62,    63,    -2,     4,    64,    65,   125,
     134,   154,   136,    66,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,    84,    85,    86,    87,
      88,   161,    80,   162,   169,   163,     7,   167,     8,    17,
      18,   173,     9,    19,    20,    21,    22,    23,    24,    25,
      26,    17,    18,    55,    98,    19,    20,    21,    22,    23,
      24,    25,   151,   112,   141,   152
};

static const yytype_uint8 yycheck[] =
{
      50,    15,     0,     8,    11,    12,    50,    57,    52,    41,
      60,     3,     4,     5,     6,     7,    66,     5,     6,     7,
      44,    71,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    46,    38,    84,    85,    86,    87,    88,    46,
      45,    91,    49,    45,    34,    95,    96,    34,    50,    54,
     100,   101,    66,   103,     3,     4,     5,     6,     7,    51,
      74,     3,     4,     5,     6,     7,   126,    11,    12,   119,
      51,    45,    50,     1,    52,    51,   136,   127,   128,    34,
     130,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     4,   158,   155,   146,    50,    26,    52,
       4,    34,    51,    31,   168,    33,    34,   157,    49,    51,
      50,   175,    52,     4,    49,     3,     4,     5,     6,     7,
      48,     4,    49,    34,    35,    36,    42,    43,    39,    40,
      34,    35,    36,    34,    45,    39,    40,    50,    48,    49,
      51,    45,    38,    34,    35,    36,    52,    51,    39,    40,
      50,    34,    35,    36,    45,    34,    39,    40,    46,     4,
      51,    49,    45,    46,    48,    49,    49,     3,     4,     5,
       6,     7,     4,    42,    43,    48,    49,     9,    10,    34,
      34,    13,    14,    15,    16,    17,    18,    19,    50,    34,
      35,    36,    48,    49,    39,    40,    46,    44,    51,    47,
      45,    52,    34,    35,    36,     0,     1,    39,    40,    47,
      46,    52,    47,    45,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     3,     4,     5,     6,
       7,    41,    45,    44,    52,    47,    31,   161,    33,     9,
      10,    47,    37,    13,    14,    15,    16,    17,    18,    19,
      20,     9,    10,    45,    78,    13,    14,    15,    16,    17,
      18,    19,   137,    92,   130,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    54,    57,     0,     1,    11,    12,    31,    33,    37,
      56,    58,    60,    66,    41,    56,    34,     9,    10,    13,
      14,    15,    16,    17,    18,    19,    20,    55,    44,    59,
      55,    45,    68,    67,    42,    43,    34,    69,    62,    34,
      77,    34,    70,    49,    46,    49,    56,    63,    78,    49,
      52,    71,    49,    34,    38,    63,    55,    50,    80,    34,
       4,    34,    35,    36,    39,    40,    45,    84,    89,    90,
      92,    50,    73,    34,    56,    34,    51,    89,    79,    89,
      45,    50,    55,    89,     3,     4,     5,     6,     7,    51,
      89,    52,    72,    55,    50,    50,    52,    51,    80,    85,
      91,    46,    46,    49,    89,    89,    89,    89,    89,    52,
      51,    89,    73,    61,    51,    51,    89,    89,    76,    86,
      89,    89,    89,    47,    52,    47,    51,    50,    52,    46,
      49,    87,    89,    51,    46,    74,    47,    64,    76,    89,
      89,    87,    83,    89,    76,     1,    26,    31,    34,    48,
      65,    66,    84,    88,    52,    51,    48,    49,    75,    44,
      89,    41,    44,    47,    76,    89,    83,    59,    82,    52,
      48,    42,    83,    47,    48,    81,    83,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    56,    57,    57,    57,    58,    58,
      58,    58,    59,    59,    60,    61,    62,    62,    62,    63,
      63,    64,    64,    64,    64,    65,    65,    65,    65,    66,
      67,    66,    68,    66,    69,    69,    70,    70,    71,    70,
      70,    70,    72,    70,    73,    73,    74,    73,    75,    73,
      76,    78,    77,    79,    77,    80,    80,    80,    81,    80,
      82,    80,    80,    80,    83,    83,    85,    84,    86,    86,
      86,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    90,
      91,    90,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     0,     2,    12,     0,     0,     2,     3,     3,
       5,     0,     3,     3,     2,     4,     1,     1,     1,     4,
       0,     4,     0,     4,     1,     3,     1,     3,     0,     3,
       3,     5,     0,     5,     3,     2,     0,     7,     0,     9,
       0,     0,     3,     0,     5,     4,     6,     4,     0,    13,
       0,    11,     8,     4,     1,     3,     0,     5,     0,     2,
       3,     1,     2,     1,     3,     3,     3,     3,     3,     4,
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
#line 81 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1516 "parser.tab.c"
    break;

  case 16:
#line 88 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1522 "parser.tab.c"
    break;

  case 18:
#line 92 "parser.y"
                                {printcode("%s\n",(yyvsp[0].s));}
#line 1528 "parser.tab.c"
    break;

  case 19:
#line 93 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1534 "parser.tab.c"
    break;

  case 20:
#line 94 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1540 "parser.tab.c"
    break;

  case 21:
#line 95 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1546 "parser.tab.c"
    break;

  case 23:
#line 98 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1552 "parser.tab.c"
    break;

  case 24:
#line 101 "parser.y"
                                                                                                  {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 1566 "parser.tab.c"
    break;

  case 25:
#line 111 "parser.y"
                            {print_fn_delc((yyvsp[(-6) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;
                            pushscope();}
#line 1576 "parser.tab.c"
    break;

  case 29:
#line 121 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));create_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 1582 "parser.tab.c"
    break;

  case 30:
#line 122 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 1588 "parser.tab.c"
    break;

  case 32:
#line 125 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type = VOID_TYPE;}
#line 1594 "parser.tab.c"
    break;

  case 33:
#line 126 "parser.y"
                        {expr_type= VOID_TYPE;}
#line 1600 "parser.tab.c"
    break;

  case 34:
#line 127 "parser.y"
                    {yyerror("missing ;");expr_type =  VOID_TYPE;}
#line 1606 "parser.tab.c"
    break;

  case 35:
#line 130 "parser.y"
                             {printcode("%s\n",(yyvsp[0].s));}
#line 1612 "parser.tab.c"
    break;

  case 37:
#line 132 "parser.y"
             {printcode((yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";\n");free((yyvsp[0].s));}
#line 1618 "parser.tab.c"
    break;

  case 40:
#line 137 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 1624 "parser.tab.c"
    break;

  case 41:
#line 137 "parser.y"
                                                                                            {printcode(" ;\n");arr_type=VOID_TYPE;}
#line 1630 "parser.tab.c"
    break;

  case 42:
#line 138 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 1636 "parser.tab.c"
    break;

  case 43:
#line 138 "parser.y"
                                                                                               {printcode(" ;\n");char_buf_mod = NONE_TYPE;}
#line 1642 "parser.tab.c"
    break;

  case 44:
#line 141 "parser.y"
                     {create_var((yyvsp[(-1) - (1)].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 1648 "parser.tab.c"
    break;

  case 45:
#line 142 "parser.y"
                              {create_var((yyvsp[(-1) - (3)].m),(yyvsp[-3].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 1654 "parser.tab.c"
    break;

  case 46:
#line 145 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 1662 "parser.tab.c"
    break;

  case 47:
#line 148 "parser.y"
                          {
                                if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 1672 "parser.tab.c"
    break;

  case 48:
#line 153 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 1678 "parser.tab.c"
    break;

  case 49:
#line 153 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 1684 "parser.tab.c"
    break;

  case 50:
#line 154 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 1692 "parser.tab.c"
    break;

  case 51:
#line 157 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 1702 "parser.tab.c"
    break;

  case 52:
#line 162 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 1708 "parser.tab.c"
    break;

  case 53:
#line 162 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 1714 "parser.tab.c"
    break;

  case 54:
#line 165 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 1725 "parser.tab.c"
    break;

  case 55:
#line 171 "parser.y"
                      {yyerror("Array size missing");}
#line 1731 "parser.tab.c"
    break;

  case 56:
#line 172 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 1737 "parser.tab.c"
    break;

  case 57:
#line 172 "parser.y"
                                                                         {printcode(" }");}
#line 1743 "parser.tab.c"
    break;

  case 58:
#line 173 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 1749 "parser.tab.c"
    break;

  case 59:
#line 173 "parser.y"
                                                                                                          {printcode(" }");}
#line 1755 "parser.tab.c"
    break;

  case 60:
#line 177 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 1761 "parser.tab.c"
    break;

  case 61:
#line 179 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 1767 "parser.tab.c"
    break;

  case 62:
#line 179 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 1773 "parser.tab.c"
    break;

  case 63:
#line 180 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 1779 "parser.tab.c"
    break;

  case 64:
#line 180 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 1785 "parser.tab.c"
    break;

  case 65:
#line 183 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 1791 "parser.tab.c"
    break;

  case 66:
#line 184 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 1798 "parser.tab.c"
    break;

  case 67:
#line 186 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 1805 "parser.tab.c"
    break;

  case 68:
#line 188 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 1811 "parser.tab.c"
    break;

  case 69:
#line 188 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 1819 "parser.tab.c"
    break;

  case 70:
#line 191 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 1825 "parser.tab.c"
    break;

  case 71:
#line 191 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 1833 "parser.tab.c"
    break;

  case 72:
#line 194 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 1839 "parser.tab.c"
    break;

  case 73:
#line 196 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 1845 "parser.tab.c"
    break;

  case 74:
#line 200 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 1855 "parser.tab.c"
    break;

  case 75:
#line 205 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 1864 "parser.tab.c"
    break;

  case 76:
#line 210 "parser.y"
                        {push_expr_and_args();if(!find_action((yyvsp[-1].s)))is_in_fncall=true;}
#line 1870 "parser.tab.c"
    break;

  case 77:
#line 210 "parser.y"
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
#line 1909 "parser.tab.c"
    break;

  case 81:
#line 251 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_val_arr){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_val_arr = false;}
#line 1920 "parser.tab.c"
    break;

  case 82:
#line 259 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;\n",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 1932 "parser.tab.c"
    break;

  case 83:
#line 266 "parser.y"
                        {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;\n");
                            has_returned = true;
                        }}
#line 1943 "parser.tab.c"
    break;

  case 84:
#line 274 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 1949 "parser.tab.c"
    break;

  case 85:
#line 275 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 1955 "parser.tab.c"
    break;

  case 86:
#line 276 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 1961 "parser.tab.c"
    break;

  case 87:
#line 277 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 1967 "parser.tab.c"
    break;

  case 88:
#line 278 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_val_arr =false;}
#line 1973 "parser.tab.c"
    break;

  case 89:
#line 279 "parser.y"
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
#line 1988 "parser.tab.c"
    break;

  case 90:
#line 289 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_val_arr =false;}
#line 1994 "parser.tab.c"
    break;

  case 91:
#line 290 "parser.y"
                            {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_val_arr =false;}
#line 2000 "parser.tab.c"
    break;

  case 93:
#line 293 "parser.y"
                 {if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2010 "parser.tab.c"
    break;

  case 94:
#line 298 "parser.y"
             {if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 2020 "parser.tab.c"
    break;

  case 95:
#line 303 "parser.y"
               { if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 2030 "parser.tab.c"
    break;

  case 96:
#line 308 "parser.y"
                 { Variable *_t = lookup_var((yyvsp[0].s));
                    if(_t == NULL){
                        yyerror("Undefined variable %s",(yyvsp[0].s));
                    }else if(_t->is_arr && !is_in_fncall){
                        yyerror("cannot use arrray without subscript.");
                    }else if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[_t->t],type_arr[expr_type]);;
                    }else if(_t->t ==COMPLEX_TYPE){
                        expr_type = COMPLEX_TYPE;
                    }else if(_t->t == FLOAT_TYPE && expr_type != COMPLEX_TYPE){
                        expr_type = FLOAT_TYPE;
                    }else if(expr_type != COMPLEX_TYPE && expr_type != FLOAT_TYPE){
                        expr_type = _t->t;
                    }}
#line 2049 "parser.tab.c"
    break;

  case 97:
#line 322 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type != BOOL_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 2059 "parser.tab.c"
    break;

  case 98:
#line 327 "parser.y"
                {if(expr_type != VOID_TYPE){asm("int3");yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 2065 "parser.tab.c"
    break;

  case 100:
#line 329 "parser.y"
                     {push_expr_and_args();}
#line 2071 "parser.tab.c"
    break;

  case 101:
#line 329 "parser.y"
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
                                                            if(expr_type == BOOL_TYPE || expr_type == STRING_TYPE){
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
#line 2103 "parser.tab.c"
    break;

  case 102:
#line 358 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;}
#line 2115 "parser.tab.c"
    break;


#line 2119 "parser.tab.c"

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
#line 366 "parser.y"


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
