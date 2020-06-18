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
#define YYLAST   1134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  83
/* YYNRULES -- Number of rules.  */
#define YYNRULES  206
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  419

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
     138,   139,   143,   146,   154,   162,   163,   166,   170,   171,
     173,   174,   174,   184,   184,   197,   198,   199,   201,   202,
     204,   208,   216,   216,   226,   231,   232,   233,   235,   236,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   251,   252,   253,   254,   255,   256,   259,   259,   260,
     262,   263,   265,   272,   279,   282,   282,   283,   283,   284,
     284,   285,   285,   286,   286,   287,   298,   302,   303,   304,
     305,   307,   308,   309,   310,   313,   314,   317,   320,   324,
     324,   325,   328,   333,   333,   336,   342,   343,   343,   344,
     344,   348,   350,   361,   372,   373,   384,   384,   385,   385,
     390,   391,   393,   395,   395,   398,   398,   401,   403,   407,
     412,   417,   417,   452,   453,   454,   457,   465,   488,   494,
     495,   496,   497,   498,   499,   502,   503,   504,   504,   507,
     511,   515,   515,   518,   518,   519,   519,   520,   520,   521,
     521,   524,   528,   542,   555,   556,   557,   558,   559,   563,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   586,   589,   594,   599,   605,   610,   611,   612,   615,
     624,   646,   646,   673,   693,   693,   721
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
  "$@7", "$@8", "$@9", "$@10", "$@11", "classvarlist", "decllist",
  "classdecllist", "varlist", "$@12", "$@13", "arraydecl", "$@14", "$@15",
  "arraysizedummy", "letarraydecl", "letarrvals", "chararrdecllist",
  "$@16", "$@17", "strdecl", "$@18", "$@19", "arrayvallist", "fncall",
  "$@20", "arglist", "arg", "assignstmt", "assigndummy", "assgtype",
  "ifstmt", "$@21", "ifdummy", "elsedummy", "whilestmt", "$@22", "forstmt",
  "$@23", "$@24", "$@25", "$@26", "rangecheckdummy", "simplearraydummy",
  "iterarraydummy", "expr", "value", "cmplxnum", "varvals", "$@27", "$@28",
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
     299,   300,   301,   302,   303,   304,   305,   306,    59,   123,
     125,    91,    93,    40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF (-273)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -273,    43,   895,  -273,  -273,  -273,  -273,    12,   -12,     6,
      25,  -273,  -273,    57,   881,  -273,  -273,  -273,  -273,    53,
    -273,  1029,    15,  -273,    65,  -273,    61,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
      42,  -273,  -273,    84,    76,  -273,    21,  -273,   100,   109,
     115,  -273,  -273,   124,   128,    76,    76,    22,  -273,  -273,
    -273,  -273,   110,   969,  -273,  1105,  -273,  -273,   133,  1105,
    -273,  -273,  -273,  -273,  -273,   144,   167,   181,    38,   182,
     202,   200,   222,   219,   270,   270,  -273,  -273,   235,   232,
     247,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,   294,   237,  -273,    95,   751,   239,   260,
      76,   261,    76,   242,   264,   245,  -273,   267,   253,   275,
      76,  -273,    76,    76,  -273,    76,  1105,  1081,  1081,   257,
     257,   257,   257,   175,   175,   301,   301,   301,    76,   254,
     278,   276,   -12,  1106,  -273,   265,   277,   -12,  1040,  -273,
     132,  -273,  -273,  1105,   263,  1105,   739,  -273,    71,  -273,
     202,  -273,   266,   808,    -1,    75,  1105,   270,   226,  1105,
     269,   268,   -12,  -273,   289,  -273,  -273,  1051,   291,   292,
      34,   121,   822,   239,   272,    76,   297,   836,    76,   242,
    -273,   273,  -273,  -273,    76,  -273,  1105,  -273,    76,  -273,
      76,  -273,  1106,   303,   104,   295,   314,   -51,    14,   325,
    -273,  -273,   323,   987,    76,  -273,  -273,  -273,  1105,   279,
     302,  1105,  -273,  -273,  -273,  1105,   138,    76,  -273,   307,
    -273,   202,   202,  -273,    76,  -273,    76,   308,   329,  -273,
     850,  1105,   145,   311,  -273,   316,  -273,  1105,   317,  -273,
     319,   322,  1105,  1105,  -273,   335,  -273,    76,    76,  -273,
      76,  -273,   339,  -273,  -273,  -273,   344,   345,  -273,  -273,
     313,   868,  1105,   213,  1105,  -273,  -273,   321,   351,   352,
     143,  -273,   353,  -273,  -273,    76,    76,   -41,  -273,  -273,
     370,    76,    76,    76,   365,   113,  -273,   356,  -273,  -273,
    -273,  -273,  -273,  -273,  -273,  -273,   133,  -273,  -273,   371,
     -12,  1106,  -273,   224,  -273,   354,  1105,   215,  -273,  -273,
    -273,   -32,   949,  1105,   963,  -273,  -273,  -273,    24,  1106,
    -273,   377,   374,    76,   363,  -273,   997,   382,  -273,  -273,
     163,   375,   378,   383,   384,   386,  -273,    76,  -273,   392,
    1106,   217,  -273,    49,    17,   417,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,  -273,  1105,   396,   394,  -273,  -273,    76,
    -273,   390,   418,   364,   407,  -273,  -273,   402,   221,   403,
      76,  -273,   429,  -273,   450,  -273,  -273,  -273,   212,  -273,
     406,  -273,   493,   536,   399,  -273,   425,  -273,   454,  -273,
    -273,    76,   433,  -273,  -273,  -273,  1105,  -273,   579,   622,
    -273,   665,  -273,  -273,   434,  -273,  -273,   708,  -273
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     1,    16,    13,    14,     0,    12,     0,
       0,    77,    79,     0,     0,    17,    23,    21,    22,    20,
      24,     0,     0,    96,     0,    80,     0,     8,     9,     7,
       6,     4,     5,    10,     3,    11,    93,    89,    91,    19,
       0,    87,    85,     0,     0,    52,     0,    26,     0,     0,
       0,    18,    25,     0,     0,     0,     0,   200,   195,   196,
     193,   194,     0,     0,   197,   121,   191,   192,   198,    95,
      55,    78,    81,    29,   126,    94,    97,    90,   107,    92,
      38,    88,   101,    86,   181,   190,   201,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,     0,     0,
       0,   143,     0,     0,   180,     0,   186,   188,   189,   184,
     185,   182,   183,   174,   175,   176,   177,   178,     0,     0,
       0,     0,    12,     0,    56,     0,     0,    12,     0,    40,
       0,   127,   128,   121,    99,   108,     0,   110,   111,    39,
      38,   102,   103,     0,     0,     0,   124,   179,     0,   187,
       0,   203,    12,    57,     0,    30,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     106,     0,   202,   142,     0,   144,   146,   122,     0,   199,
       0,   204,     0,    58,     0,     0,     0,     0,     0,     0,
      50,    28,     0,     0,     0,   121,   129,    98,   121,     0,
     115,   112,   114,   104,   145,   125,     0,     0,    54,     0,
      35,    38,    38,    33,     0,    31,     0,     0,     0,   138,
       0,   132,   130,     0,   117,     0,   123,   121,     0,    59,
       0,     0,   121,   121,    41,     0,   121,     0,     0,   100,
       0,   121,     0,    60,    37,    36,     0,     0,    45,    43,
       0,     0,   131,     0,   139,   119,   205,     0,     0,     0,
      12,    45,     0,   121,   118,     0,     0,     0,    75,    76,
       0,     0,    83,     0,     0,    12,    53,    66,    67,    73,
      71,    72,    74,    68,    69,    70,   148,    34,    32,     0,
      12,     0,    46,    12,   135,   137,   140,     0,    62,    64,
      63,     0,     0,    82,     0,    24,    84,    65,     0,     0,
      47,     0,     0,     0,     0,   120,     0,     0,   159,   161,
       0,     0,     0,     0,     0,     0,   149,     0,    51,    48,
       0,     0,   133,   200,     0,     0,    60,    60,    61,   150,
     151,   152,   153,   154,   147,     0,     0,    51,   136,     0,
     167,     0,     0,     0,     0,    60,    49,     0,     0,     0,
       0,   173,   155,   162,     0,    60,   134,    60,   171,   169,
     157,    42,     0,     0,     0,   163,     0,   160,     0,    44,
     168,     0,     0,    60,    60,   158,   171,    60,     0,     0,
     165,     0,   170,   156,     0,   164,    60,     0,   166
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -273,  -273,   -19,    -4,  -273,  -273,  -173,  -273,  -273,  -273,
    -273,  -145,  -273,  -273,  -273,   214,   186,  -273,   130,  -273,
    -273,  -273,  -273,   357,   -90,  -273,   496,  -273,  -273,  -273,
     498,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,   315,  -273,  -273,  -147,  -273,   305,  -273,  -273,
    -273,   326,  -273,  -273,  -272,  -212,  -273,  -273,   312,  -273,
    -273,  -273,   129,  -273,  -273,  -273,  -273,  -273,  -273,  -273,
    -273,  -273,  -273,    96,  -273,  -273,   -43,  -273,  -273,  -207,
    -273,  -273,  -273
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    73,   149,
     107,   116,   180,   268,   281,   280,   312,   212,   365,    17,
      70,   248,   106,   144,   277,   297,   298,    25,    46,   299,
     300,    54,    53,    49,    50,    48,    77,    83,    81,    79,
     113,   189,   157,   260,   286,   104,    23,   165,    75,   108,
     183,   151,   369,   333,   273,    64,   121,   164,   195,   302,
     328,   347,   303,   398,   356,   404,   304,   357,   305,   402,
     414,   379,   396,   395,   370,   389,   274,    66,    67,    68,
     120,   227,   140
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    69,    42,   204,    21,   336,   184,   233,     5,     6,
     234,    55,    84,    85,   317,   190,    56,   318,   319,   320,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   337,   103,   341,   342,   343,   344,   345,
      57,    58,    59,     3,    89,    60,    61,    22,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
      20,   351,    63,   193,   194,   301,    24,   153,   242,   155,
     306,   243,   235,    71,    72,   236,    43,   163,   209,   166,
     167,    44,   168,    86,   371,    87,   250,   251,    55,   210,
     346,    51,    52,    56,   211,   169,    55,   378,    26,  -109,
     262,    56,   143,   148,   112,   266,   267,   182,  -172,   270,
      86,    39,    87,   187,   275,     5,     6,    57,    58,    59,
      47,   196,    60,    61,   174,    57,    58,    59,    45,   179,
      60,    61,  -113,     5,     6,   197,   315,   188,   143,    63,
     198,    74,   218,   177,    55,   221,    62,    63,   326,    56,
      76,   196,   340,   230,    52,   225,    78,   166,   206,   141,
     142,   301,   301,     5,     6,    80,   306,   306,   202,    82,
     240,   241,   301,    57,    58,    59,    88,   306,    60,    61,
     301,   301,   213,   228,   247,   306,   306,   214,   100,   101,
     102,   252,   103,   253,   181,    63,   301,   301,   246,   301,
     105,   306,   306,   198,   306,   301,   257,   309,   310,   109,
     306,   258,   358,    52,   271,   272,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   110,   103,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   316,   103,     5,     6,   111,   114,   322,   323,
     324,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   115,   103,   117,   373,   374,    98,    99,
     100,   101,   102,   284,   103,   335,   311,   368,   285,   394,
     285,   386,   285,   118,   119,   384,   285,  -173,   332,   310,
     199,    21,   331,   354,   122,   392,   123,   393,   138,   139,
     150,   152,   154,   156,   364,   158,   311,   159,   160,   311,
     348,   124,   125,   408,   409,   161,   162,   411,   103,   171,
     170,   172,   287,   175,   185,   176,   417,   191,   200,   201,
     203,   367,   207,   208,   217,   223,   231,   388,   244,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   288,   289,   290,   291,   232,   292,   293,   406,   294,
     295,     9,    57,   219,   229,   287,   237,   238,   245,   249,
     255,   254,    11,   259,    12,   261,   263,   264,   -12,   282,
     265,   296,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   288,   289,   290,   291,   269,   292,
     293,   276,   294,   295,     9,    57,   278,   279,   287,   307,
     308,   321,   314,   325,   327,    11,   329,    12,   349,   350,
     334,   -12,   352,   355,   382,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   288,   289,   290,
     291,   359,   292,   293,   360,   294,   295,     9,    57,   361,
     362,   287,   363,   366,   372,   375,   376,   380,    11,   381,
      12,   385,   387,   390,   -12,   397,   401,   383,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     288,   289,   290,   291,   403,   292,   293,   291,   294,   295,
       9,    57,   407,   416,   287,   313,   330,   377,    18,   173,
      19,    11,   410,    12,   222,   226,   224,   -12,     0,   216,
     391,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   288,   289,   290,   291,   405,   292,   293,
       0,   294,   295,     9,    57,     0,     0,   287,     0,     0,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
     -12,     0,     0,   399,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   288,   289,   290,   291,
       0,   292,   293,     0,   294,   295,     9,    57,     0,     0,
     287,     0,     0,     0,     0,     0,     0,    11,     0,    12,
       0,     0,     0,   -12,     0,     0,   400,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   288,
     289,   290,   291,     0,   292,   293,     0,   294,   295,     9,
      57,     0,     0,   287,     0,     0,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,   -12,     0,     0,   412,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   288,   289,   290,   291,     0,   292,   293,     0,
     294,   295,     9,    57,     0,     0,   287,     0,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,   -12,
       0,     0,   413,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   288,   289,   290,   291,     0,
     292,   293,     0,   294,   295,     9,    57,     0,     0,   287,
       0,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,   -12,     0,     0,   415,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   288,   289,
     290,   291,     0,   292,   293,     0,   294,   295,     9,    57,
       0,    55,   145,     0,     0,     0,    56,     0,     0,    11,
       0,    12,     0,     0,     0,   -12,     0,     0,   418,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
      57,    58,    59,     0,     0,    60,    61,     0,     0,   146,
     147,     0,     0,     0,     0,   -27,     0,     0,     0,     0,
       0,   186,    63,     0,     0,     0,   -27,     0,   -12,     0,
       0,   -27,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,   103,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,     0,   103,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     0,   103,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,   103,     0,     0,
     192,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   215,   103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -2,     4,     0,   220,    27,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,     0,   256,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,     0,     0,     0,     0,     0,
     283,     0,     0,     7,     8,     9,     0,     0,    37,    10,
       0,     0,     0,     0,     0,     0,    11,     0,    12,    13,
       0,     0,   -12,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,     0,   103,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,     0,
     103,    55,     0,     0,     0,     0,    56,    27,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,     0,    55,
       0,     0,     0,     0,    56,     0,     0,     0,   338,    55,
      57,    58,    59,     0,    56,    60,    61,     0,     0,     0,
       0,     0,   339,     0,     0,     0,     0,     0,    57,    58,
      59,     0,    63,    60,    61,     0,     0,     0,   353,    58,
      59,     0,     0,    60,    61,     0,     0,    27,    28,   239,
      63,    29,    30,    31,    32,    33,    34,    35,    27,    28,
      63,     0,    29,    30,    31,    32,    33,    34,    35,    27,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,     0,     0,    41,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   178,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   205,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,   103,     0,    27,    28,     0,     0,    29,    30,
      31,    32,    33,    34,    35
};

static const yytype_int16 yycheck[] =
{
      43,    44,    21,   176,     8,    37,   153,    58,    20,    21,
      61,    12,    55,    56,   286,   160,    17,    58,    59,    60,
      63,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    65,    17,    11,    12,    13,    14,    15,
      41,    42,    43,     0,    63,    46,    47,    41,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      48,   333,    63,    64,    65,   277,    41,   110,   215,   112,
     277,   218,    58,    52,    53,    61,    61,   120,    44,   122,
     123,    66,   125,    61,    67,    63,   231,   232,    12,    55,
      66,    49,    50,    17,    60,   138,    12,   369,    41,    61,
     247,    17,   106,   107,    66,   252,   253,   150,    59,   256,
      61,    58,    63,   156,   261,    20,    21,    41,    42,    43,
      59,   164,    46,    47,   143,    41,    42,    43,    63,   148,
      46,    47,    61,    20,    21,    60,   283,    66,   142,    63,
      65,    41,   185,   147,    12,   188,    62,    63,    35,    17,
      41,   194,   325,    49,    50,   198,    41,   200,   177,    64,
      65,   373,   374,    20,    21,    41,   373,   374,   172,    41,
     213,   214,   384,    41,    42,    43,    66,   384,    46,    47,
     392,   393,    61,   202,   227,   392,   393,    66,    13,    14,
      15,   234,    17,   236,    62,    63,   408,   409,    60,   411,
      67,   408,   409,    65,   411,   417,    61,    64,    65,    65,
     417,    66,    49,    50,   257,   258,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    61,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,   285,    17,    20,    21,    65,    65,   291,   292,
     293,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    61,    17,    65,   356,   357,    11,    12,
      13,    14,    15,    60,    17,    60,   280,    60,    65,    67,
      65,    60,    65,    61,    65,   375,    65,    17,    64,    65,
      64,   295,   311,   336,    59,   385,    64,   387,     4,    62,
      61,    41,    41,    61,   347,    41,   310,    62,    41,   313,
     329,    64,    65,   403,   404,    62,    41,   407,    17,    41,
      66,    45,     1,    58,    61,    48,   416,    61,    59,    61,
      41,   350,    41,    41,    62,    62,    41,   380,    59,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    41,    35,    36,   401,    38,
      39,    40,    41,    66,    61,     1,    41,    44,    66,    62,
      41,    63,    51,    62,    53,    59,    59,    58,    57,    66,
      58,    60,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    63,    35,
      36,    62,    38,    39,    40,    41,    62,    62,     1,    58,
      58,    41,    59,    48,    58,    51,    45,    53,    41,    45,
      66,    57,    59,    41,    60,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    66,    35,    36,    66,    38,    39,    40,    41,    66,
      66,     1,    66,    61,    37,    59,    62,    67,    51,    41,
      53,    59,    59,    34,    57,    59,    67,    60,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    59,    35,    36,    33,    38,    39,
      40,    41,    59,    59,     1,   281,   310,   367,     2,   142,
       2,    51,   406,    53,   189,   200,   194,    57,    -1,   183,
      60,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,   398,    35,    36,
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
      -1,    12,     1,    -1,    -1,    -1,    17,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    60,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    55,    -1,    57,    -1,
      -1,    60,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    17,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      62,    -1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    62,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    62,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    62,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    38,    39,    40,    -1,    -1,    57,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    54,
      -1,    -1,    57,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    12,    -1,    -1,    -1,    -1,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    12,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    59,    12,
      41,    42,    43,    -1,    17,    46,    47,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,    41,    42,
      43,    -1,    63,    46,    47,    -1,    -1,    -1,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    -1,    18,    19,    62,
      63,    22,    23,    24,    25,    26,    27,    28,    18,    19,
      63,    -1,    22,    23,    24,    25,    26,    27,    28,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    57,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    72,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    71,    73,    75,    87,    94,    98,
      48,    71,    41,   114,    41,    95,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    57,    70,    58,
      74,    57,    70,    61,    66,    63,    96,    59,   103,   101,
     102,    49,    50,   100,    99,    12,    17,    41,    42,    43,
      46,    47,    62,    63,   123,   144,   145,   146,   147,   144,
      88,    52,    53,    76,    41,   116,    41,   104,    41,   107,
      41,   106,    41,   105,   144,   144,    61,    63,    66,    70,
     144,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    17,   113,    67,    90,    78,   117,    65,
      61,    65,    66,   108,    65,    61,    79,    65,    61,    65,
     148,   124,    59,    64,    64,    65,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,     4,    62,
     150,    64,    65,    71,    91,     1,    38,    39,    71,    77,
      61,   119,    41,   144,    41,   144,    61,   110,    41,    62,
      41,    62,    41,   144,   125,   115,   144,   144,   144,   144,
      66,    41,    45,    91,    70,    58,    48,    71,    57,    70,
      80,    62,   144,   118,   113,    61,    62,   144,    66,   109,
      79,    61,    62,    64,    65,   126,   144,    60,    65,    64,
      59,    61,    71,    41,    74,    57,    70,    41,    41,    44,
      55,    60,    85,    61,    66,    62,   119,    62,   144,    66,
      62,   144,   110,    62,   126,   144,   115,   149,    70,    61,
      49,    41,    41,    58,    61,    58,    61,    41,    44,    62,
     144,   144,   113,   113,    59,    66,    60,   144,    89,    62,
      79,    79,   144,   144,    63,    41,    62,    61,    66,    62,
     111,    59,   113,    59,    58,    58,   113,   113,    81,    63,
     113,   144,   144,   122,   144,   113,    62,    92,    62,    62,
      83,    82,    66,    62,    60,    65,   112,     1,    30,    31,
      32,    33,    35,    36,    38,    39,    60,    93,    94,    97,
      98,   123,   127,   130,   134,   136,   147,    58,    58,    64,
      65,    71,    84,    83,    59,   113,   144,   122,    58,    59,
      60,    41,   144,   144,   144,    48,    35,    58,   128,    45,
      84,    70,    64,   121,    66,    60,    37,    65,    59,    59,
      74,    11,    12,    13,    14,    15,    66,   129,    70,    41,
      45,   122,    59,    41,   144,    41,   132,   135,    49,    66,
      66,    66,    66,    66,   144,    86,    61,    70,    60,   120,
     142,    67,    37,    92,    92,    59,    62,    86,   122,   139,
      67,    41,    60,    60,    92,    59,    60,    59,   144,   143,
      34,    60,    92,    92,    67,   141,   140,    59,   131,    60,
      60,    67,   137,    59,   133,   130,   144,    59,    92,    92,
     141,    92,    60,    60,   138,    60,    59,    92,    60
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
      96,    96,    97,    97,    97,    99,    98,   100,    98,   101,
      98,   102,    98,   103,    98,    98,    98,   104,   104,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   108,
     107,   107,   107,   109,   107,   110,   110,   111,   110,   112,
     110,   113,   114,   114,   115,   115,   117,   116,   118,   116,
     119,   119,   119,   120,   119,   121,   119,   119,   119,   122,
     122,   124,   123,   125,   125,   125,   126,   127,   128,   129,
     129,   129,   129,   129,   129,   130,   130,   131,   130,   132,
     133,   135,   134,   137,   136,   138,   136,   139,   136,   140,
     136,   141,   142,   143,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   145,   145,   145,   145,   146,
     147,   148,   147,   147,   149,   147,   150
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
       0,     2,     2,     1,     2,     0,     5,     0,     5,     0,
       4,     0,     4,     0,     4,     4,     2,     1,     5,     3,
       7,     1,     3,     3,     5,     2,     4,     1,     3,     0,
       3,     3,     5,     0,     5,     3,     2,     0,     7,     0,
       9,     0,     7,     9,     1,     3,     0,     3,     0,     5,
       4,     6,     4,     0,    13,     0,    11,     8,     4,     1,
       3,     0,     5,     0,     2,     3,     1,     4,     0,     1,
       2,     2,     2,     2,     2,     6,    11,     0,     9,     0,
       0,     0,     6,     0,    12,     0,    15,     0,     9,     0,
      11,     0,     0,     0,     3,     3,     3,     3,     3,     4,
       3,     2,     3,     3,     3,     3,     3,     4,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     0,     5,     4,     0,     9,     0
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
#line 1845 "parser.tab.c"
    break;

  case 16:
#line 119 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1851 "parser.tab.c"
    break;

  case 18:
#line 123 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1857 "parser.tab.c"
    break;

  case 19:
#line 124 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1863 "parser.tab.c"
    break;

  case 20:
#line 125 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1869 "parser.tab.c"
    break;

  case 21:
#line 126 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1875 "parser.tab.c"
    break;

  case 23:
#line 128 "parser.y"
               {expr_type =VOID_TYPE;}
#line 1881 "parser.tab.c"
    break;

  case 25:
#line 131 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1887 "parser.tab.c"
    break;

  case 26:
#line 135 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1893 "parser.tab.c"
    break;

  case 27:
#line 135 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1899 "parser.tab.c"
    break;

  case 28:
#line 135 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1905 "parser.tab.c"
    break;

  case 31:
#line 139 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;\n",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1914 "parser.tab.c"
    break;

  case 32:
#line 143 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];\n",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 1922 "parser.tab.c"
    break;

  case 33:
#line 146 "parser.y"
                                                  {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    } 
                                                    if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);
                                                    printcode("%s %s %s;\n",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 1935 "parser.tab.c"
    break;

  case 34:
#line 154 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }
                                                    if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,yylineno);
                                                    printcode("%s %s %s[%s];\n",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 1948 "parser.tab.c"
    break;

  case 35:
#line 162 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 1954 "parser.tab.c"
    break;

  case 36:
#line 163 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 1962 "parser.tab.c"
    break;

  case 37:
#line 166 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 1970 "parser.tab.c"
    break;

  case 38:
#line 170 "parser.y"
                        {(yyval.b)= false;}
#line 1976 "parser.tab.c"
    break;

  case 39:
#line 171 "parser.y"
                {(yyval.b) = true;}
#line 1982 "parser.tab.c"
    break;

  case 41:
#line 174 "parser.y"
                                       {pushscope();}
#line 1988 "parser.tab.c"
    break;

  case 42:
#line 174 "parser.y"
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
#line 2003 "parser.tab.c"
    break;

  case 43:
#line 184 "parser.y"
                                                   {pushscope();}
#line 2009 "parser.tab.c"
    break;

  case 44:
#line 184 "parser.y"
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
#line 2024 "parser.tab.c"
    break;

  case 48:
#line 201 "parser.y"
                                        {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s)); add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno);free((yyvsp[0].s));/*duplicated as paramlist does not create var*/}
#line 2030 "parser.tab.c"
    break;

  case 49:
#line 202 "parser.y"
                                        {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s)); add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2036 "parser.tab.c"
    break;

  case 50:
#line 204 "parser.y"
                           {is_static_method = true;}
#line 2042 "parser.tab.c"
    break;

  case 51:
#line 208 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2053 "parser.tab.c"
    break;

  case 52:
#line 216 "parser.y"
                                      {pushscope();}
#line 2059 "parser.tab.c"
    break;

  case 53:
#line 216 "parser.y"
                                                                                                                 {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2073 "parser.tab.c"
    break;

  case 54:
#line 226 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2082 "parser.tab.c"
    break;

  case 58:
#line 235 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2088 "parser.tab.c"
    break;

  case 59:
#line 236 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2094 "parser.tab.c"
    break;

  case 61:
#line 239 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2100 "parser.tab.c"
    break;

  case 62:
#line 240 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2106 "parser.tab.c"
    break;

  case 63:
#line 241 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2112 "parser.tab.c"
    break;

  case 64:
#line 242 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2118 "parser.tab.c"
    break;

  case 65:
#line 243 "parser.y"
                        {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2124 "parser.tab.c"
    break;

  case 66:
#line 244 "parser.y"
                    {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2130 "parser.tab.c"
    break;

  case 68:
#line 246 "parser.y"
                      {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2136 "parser.tab.c"
    break;

  case 69:
#line 247 "parser.y"
                         {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2142 "parser.tab.c"
    break;

  case 70:
#line 248 "parser.y"
                       {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2148 "parser.tab.c"
    break;

  case 72:
#line 252 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2154 "parser.tab.c"
    break;

  case 75:
#line 255 "parser.y"
            {printcode("break;");}
#line 2160 "parser.tab.c"
    break;

  case 76:
#line 256 "parser.y"
                {printcode("continue;");}
#line 2166 "parser.tab.c"
    break;

  case 77:
#line 259 "parser.y"
                       {printcode("/*");}
#line 2172 "parser.tab.c"
    break;

  case 78:
#line 259 "parser.y"
                                                                 {printcode("*/");}
#line 2178 "parser.tab.c"
    break;

  case 79:
#line 260 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2184 "parser.tab.c"
    break;

  case 81:
#line 263 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2190 "parser.tab.c"
    break;

  case 82:
#line 265 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2202 "parser.tab.c"
    break;

  case 83:
#line 272 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2214 "parser.tab.c"
    break;

  case 84:
#line 279 "parser.y"
                          {has_returned = true;}
#line 2220 "parser.tab.c"
    break;

  case 85:
#line 282 "parser.y"
                                    {temp_type = (yyvsp[0].t);}
#line 2226 "parser.tab.c"
    break;

  case 86:
#line 282 "parser.y"
                                                               {temp_type = VOID_TYPE;}
#line 2232 "parser.tab.c"
    break;

  case 87:
#line 283 "parser.y"
                              {temp_type = CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2238 "parser.tab.c"
    break;

  case 88:
#line 283 "parser.y"
                                                                                    {temp_type = VOID_TYPE;temp_class=NULL;free((yyvsp[-2].s));}
#line 2244 "parser.tab.c"
    break;

  case 89:
#line 284 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));}
#line 2250 "parser.tab.c"
    break;

  case 90:
#line 284 "parser.y"
                                                                            {printcode(" ;");free((yyvsp[-2].s));}
#line 2256 "parser.tab.c"
    break;

  case 91:
#line 285 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2262 "parser.tab.c"
    break;

  case 92:
#line 285 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2268 "parser.tab.c"
    break;

  case 93:
#line 286 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2274 "parser.tab.c"
    break;

  case 94:
#line 286 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2280 "parser.tab.c"
    break;

  case 95:
#line 287 "parser.y"
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
#line 2296 "parser.tab.c"
    break;

  case 97:
#line 302 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2302 "parser.tab.c"
    break;

  case 98:
#line 303 "parser.y"
                                             {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-4].s),true,yylineno);printcode("%s[%s]",(yyvsp[-4].s),(yyvsp[-2].s));free((yyvsp[-4].s));free((yyvsp[-2].s));}
#line 2308 "parser.tab.c"
    break;

  case 99:
#line 304 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2314 "parser.tab.c"
    break;

  case 100:
#line 305 "parser.y"
                                                              {create_class_var((yyvsp[(-2) - (7)].m),(yyvsp[(-1) - (7)].s),(yyvsp[-4].s),true,yylineno);printcode(", %s[%s]",(yyvsp[-4].s),(yyvsp[-2].s));free((yyvsp[-4].s));free((yyvsp[-2].s));}
#line 2320 "parser.tab.c"
    break;

  case 101:
#line 307 "parser.y"
                     {add_var((yyvsp[(-1) - (1)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2326 "parser.tab.c"
    break;

  case 102:
#line 308 "parser.y"
                         {add_array((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2332 "parser.tab.c"
    break;

  case 103:
#line 309 "parser.y"
                              {add_var((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2338 "parser.tab.c"
    break;

  case 104:
#line 310 "parser.y"
                                      {add_array((yyvsp[(-1) - (5)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2344 "parser.tab.c"
    break;

  case 105:
#line 313 "parser.y"
                                     {create_class_var((yyvsp[(-2) - (2)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2350 "parser.tab.c"
    break;

  case 106:
#line 314 "parser.y"
                                            {create_class_var((yyvsp[(-2) - (4)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2356 "parser.tab.c"
    break;

  case 107:
#line 317 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2364 "parser.tab.c"
    break;

  case 108:
#line 320 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2373 "parser.tab.c"
    break;

  case 109:
#line 324 "parser.y"
                {add_array((yyvsp[(-2) - (1)].m),  (yyvsp[(-1) - (1)].t), (yyvsp[0].s), yylineno);}
#line 2379 "parser.tab.c"
    break;

  case 110:
#line 324 "parser.y"
                                                                      {free((yyvsp[-2].s));}
#line 2385 "parser.tab.c"
    break;

  case 111:
#line 325 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2393 "parser.tab.c"
    break;

  case 112:
#line 328 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2403 "parser.tab.c"
    break;

  case 113:
#line 333 "parser.y"
                             {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[0].s), yylineno);}
#line 2409 "parser.tab.c"
    break;

  case 114:
#line 333 "parser.y"
                                                                                   {free((yyvsp[-2].s));}
#line 2415 "parser.tab.c"
    break;

  case 115:
#line 336 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2426 "parser.tab.c"
    break;

  case 116:
#line 342 "parser.y"
                      {yyerror("Array size missing");}
#line 2432 "parser.tab.c"
    break;

  case 117:
#line 343 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2438 "parser.tab.c"
    break;

  case 118:
#line 343 "parser.y"
                                                                         {printcode(" }");}
#line 2444 "parser.tab.c"
    break;

  case 119:
#line 344 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2450 "parser.tab.c"
    break;

  case 120:
#line 344 "parser.y"
                                                                                                          {printcode(" }");}
#line 2456 "parser.tab.c"
    break;

  case 121:
#line 348 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2462 "parser.tab.c"
    break;

  case 122:
#line 350 "parser.y"
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
#line 2478 "parser.tab.c"
    break;

  case 123:
#line 361 "parser.y"
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
#line 2493 "parser.tab.c"
    break;

  case 124:
#line 372 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
#line 2499 "parser.tab.c"
    break;

  case 125:
#line 373 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2513 "parser.tab.c"
    break;

  case 126:
#line 384 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2519 "parser.tab.c"
    break;

  case 127:
#line 384 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2525 "parser.tab.c"
    break;

  case 128:
#line 385 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2531 "parser.tab.c"
    break;

  case 129:
#line 385 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2537 "parser.tab.c"
    break;

  case 130:
#line 390 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2543 "parser.tab.c"
    break;

  case 131:
#line 391 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2550 "parser.tab.c"
    break;

  case 132:
#line 393 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2557 "parser.tab.c"
    break;

  case 133:
#line 395 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2563 "parser.tab.c"
    break;

  case 134:
#line 395 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2571 "parser.tab.c"
    break;

  case 135:
#line 398 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2577 "parser.tab.c"
    break;

  case 136:
#line 398 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2585 "parser.tab.c"
    break;

  case 137:
#line 401 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2591 "parser.tab.c"
    break;

  case 138:
#line 403 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2597 "parser.tab.c"
    break;

  case 139:
#line 407 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2607 "parser.tab.c"
    break;

  case 140:
#line 412 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2616 "parser.tab.c"
    break;

  case 141:
#line 417 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2622 "parser.tab.c"
    break;

  case 142:
#line 417 "parser.y"
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
#line 2660 "parser.tab.c"
    break;

  case 146:
#line 457 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2671 "parser.tab.c"
    break;

  case 147:
#line 465 "parser.y"
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
#line 2696 "parser.tab.c"
    break;

  case 148:
#line 488 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 2705 "parser.tab.c"
    break;

  case 149:
#line 494 "parser.y"
                {(yyval.s) = "=";}
#line 2711 "parser.tab.c"
    break;

  case 150:
#line 495 "parser.y"
              {(yyval.s) = "+=";}
#line 2717 "parser.tab.c"
    break;

  case 151:
#line 496 "parser.y"
              {(yyval.s) = "-=";}
#line 2723 "parser.tab.c"
    break;

  case 152:
#line 497 "parser.y"
              {(yyval.s) = "*=";}
#line 2729 "parser.tab.c"
    break;

  case 153:
#line 498 "parser.y"
              {(yyval.s) = "/=";}
#line 2735 "parser.tab.c"
    break;

  case 154:
#line 499 "parser.y"
              {(yyval.s) = "%=";}
#line 2741 "parser.tab.c"
    break;

  case 155:
#line 502 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2747 "parser.tab.c"
    break;

  case 156:
#line 503 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2753 "parser.tab.c"
    break;

  case 157:
#line 504 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2759 "parser.tab.c"
    break;

  case 159:
#line 507 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2765 "parser.tab.c"
    break;

  case 160:
#line 511 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2771 "parser.tab.c"
    break;

  case 161:
#line 515 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 2777 "parser.tab.c"
    break;

  case 162:
#line 515 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 2783 "parser.tab.c"
    break;

  case 163:
#line 518 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2789 "parser.tab.c"
    break;

  case 164:
#line 518 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 2795 "parser.tab.c"
    break;

  case 165:
#line 519 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 2801 "parser.tab.c"
    break;

  case 166:
#line 519 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 2807 "parser.tab.c"
    break;

  case 167:
#line 520 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2813 "parser.tab.c"
    break;

  case 168:
#line 520 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 2819 "parser.tab.c"
    break;

  case 169:
#line 521 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 2825 "parser.tab.c"
    break;

  case 170:
#line 521 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 2831 "parser.tab.c"
    break;

  case 171:
#line 524 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 2837 "parser.tab.c"
    break;

  case 172:
#line 528 "parser.y"
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
#line 2853 "parser.tab.c"
    break;

  case 173:
#line 542 "parser.y"
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
#line 2869 "parser.tab.c"
    break;

  case 174:
#line 555 "parser.y"
                     { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2875 "parser.tab.c"
    break;

  case 175:
#line 556 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2881 "parser.tab.c"
    break;

  case 176:
#line 557 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2887 "parser.tab.c"
    break;

  case 177:
#line 558 "parser.y"
                     {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2893 "parser.tab.c"
    break;

  case 178:
#line 559 "parser.y"
                     {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){
                        yyerror("Cannot use mod on %s type",type_arr[expr_type]);
                        }
                        (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 2902 "parser.tab.c"
    break;

  case 179:
#line 563 "parser.y"
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
#line 2918 "parser.tab.c"
    break;

  case 180:
#line 574 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 2924 "parser.tab.c"
    break;

  case 181:
#line 575 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s)); free((yyvsp[0].s)); is_composite_val =false;}
#line 2930 "parser.tab.c"
    break;

  case 182:
#line 576 "parser.y"
                      {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2936 "parser.tab.c"
    break;

  case 183:
#line 577 "parser.y"
                      {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use > with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2942 "parser.tab.c"
    break;

  case 184:
#line 578 "parser.y"
                            {if(expr_type == COMPLEX_TYPE ){yyerror("Cannot use <= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2948 "parser.tab.c"
    break;

  case 185:
#line 579 "parser.y"
                             {if(expr_type == COMPLEX_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);}(yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2954 "parser.tab.c"
    break;

  case 186:
#line 580 "parser.y"
                                        {(yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2960 "parser.tab.c"
    break;

  case 187:
#line 581 "parser.y"
                                         {(yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2966 "parser.tab.c"
    break;

  case 188:
#line 582 "parser.y"
                     {(yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2972 "parser.tab.c"
    break;

  case 189:
#line 583 "parser.y"
                      {(yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2978 "parser.tab.c"
    break;

  case 190:
#line 584 "parser.y"
                 {char * t =join("(",(yyvsp[0].s),")");
                            (yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 2985 "parser.tab.c"
    break;

  case 192:
#line 589 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 2995 "parser.tab.c"
    break;

  case 193:
#line 594 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 3005 "parser.tab.c"
    break;

  case 194:
#line 599 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 3016 "parser.tab.c"
    break;

  case 195:
#line 605 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 3026 "parser.tab.c"
    break;

  case 196:
#line 610 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 3032 "parser.tab.c"
    break;

  case 199:
#line 615 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3044 "parser.tab.c"
    break;

  case 200:
#line 624 "parser.y"
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
#line 3071 "parser.tab.c"
    break;

  case 201:
#line 646 "parser.y"
                     {push_expr_and_args();}
#line 3077 "parser.tab.c"
    break;

  case 202:
#line 646 "parser.y"
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
#line 3109 "parser.tab.c"
    break;

  case 203:
#line 673 "parser.y"
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
#line 3134 "parser.tab.c"
    break;

  case 204:
#line 693 "parser.y"
                                                 {push_expr_and_args();}
#line 3140 "parser.tab.c"
    break;

  case 205:
#line 693 "parser.y"
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
#line 3172 "parser.tab.c"
    break;

  case 206:
#line 721 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3178 "parser.tab.c"
    break;


#line 3182 "parser.tab.c"

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
#line 723 "parser.y"


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
