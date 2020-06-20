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
    char * fn_ret_class;
    type temp_type;
    char * temp_class;
    bool is_assignable = false;
    bool is_callable = false;
    bool is_static_method;


#line 119 "parser.tab.c"

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
    DCOLON = 306,
    CLASSNAME = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

    char *s;
    type t;
    modifier m;
    bool b;

#line 231 "parser.tab.c"

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
#define YYLAST   1446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  445

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


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
      64,    65,    13,    11,    66,    12,    68,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
       9,    67,    10,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      51,    52,    53,    54,    55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   117,   118,   119,   123,   124,   125,   128,   129,
     130,   131,   132,   133,   135,   136,   140,   140,   140,   142,
     143,   144,   148,   151,   159,   167,   168,   171,   174,   176,
     177,   179,   180,   189,   198,   205,   215,   219,   227,   235,
     244,   253,   254,   259,   265,   266,   267,   269,   270,   271,
     272,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   287,   288,   289,   290,   291,   292,   295,   295,
     296,   298,   299,   301,   310,   317,   320,   320,   321,   321,
     322,   322,   323,   323,   324,   324,   325,   336,   339,   340,
     346,   346,   347,   348,   354,   354,   360,   361,   362,   363,
     366,   367,   370,   373,   377,   377,   378,   381,   386,   386,
     389,   395,   396,   396,   397,   397,   401,   403,   414,   425,
     426,   437,   437,   438,   438,   441,   442,   444,   446,   446,
     449,   449,   452,   454,   458,   464,   469,   469,   512,   512,
     552,   553,   554,   557,   565,   590,   596,   597,   598,   599,
     600,   601,   604,   605,   606,   606,   609,   613,   617,   617,
     620,   620,   621,   621,   622,   622,   623,   623,   626,   630,
     652,   673,   676,   679,   682,   685,   687,   699,   700,   701,
     703,   705,   707,   709,   711,   713,   715,   717,   719,   722,
     727,   732,   738,   743,   744,   747,   756,   757,   780,   780,
     808,   830,   830,   856,   856,   902
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
  "COMMENTLINE", "CLASS", "STATICMETHOD", "THIS", "\"::\"", "CLASSNAME",
  "';'", "'{'", "'}'", "'['", "']'", "'('", "')'", "','", "'='", "'.'",
  "$accept", "program", "type", "modifier", "topstmtlist", "topstmt",
  "rawlist", "classdef", "$@1", "$@2", "attrlist", "arraysign",
  "methodlist", "staticdummy", "methoddummy", "clsretmethoddummy",
  "fndeclaration", "pushscopedummy", "fndecldummy", "classfndecldummy",
  "paramlist", "param", "stmtlist", "stmt", "comment", "$@3",
  "commentlist", "returnstmt", "vardeclaration", "$@4", "$@5", "$@6",
  "$@7", "$@8", "classvarlist", "$@9", "$@10", "decllist", "classdecllist",
  "varlist", "$@11", "$@12", "arraydecl", "$@13", "$@14", "arraysizedummy",
  "letarraydecl", "letarrvals", "chararrdecllist", "$@15", "$@16",
  "strdecl", "$@17", "$@18", "arrayvallist", "fncall", "$@19", "$@20",
  "arglist", "arg", "assignstmt", "assigndummy", "assgtype", "ifstmt",
  "$@21", "ifdummy", "elsedummy", "whilestmt", "$@22", "forstmt", "$@23",
  "$@24", "$@25", "$@26", "rangecheckdummy", "simplearraydummy",
  "iterarraydummy", "expr", "value", "cmplxnum", "varvals", "$@27", "$@28",
  "$@29", "classcheckdummy", YY_NULLPTR
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
     299,   300,   301,   302,   303,   304,   305,   306,   307,    59,
     123,   125,    91,    93,    40,    41,    44,    61,    46
};
# endif

#define YYPACT_NINF (-304)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-207)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -304,    76,  1088,  -304,  -304,  -304,  -304,   -37,    62,     4,
      92,  -304,  -304,    97,   315,  -304,  -304,  -304,  -304,    44,
    -304,  1075,    32,  -304,    53,  -304,    75,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
      74,  -304,  -304,  1228,   930,  -304,   124,  -304,   101,   110,
     151,  -304,  -304,   155,   157,   930,   930,   129,  -304,  -304,
    -304,  -304,   141,   136,  1240,  -304,  1428,  -304,  -304,   -49,
    1428,  -304,  -304,  -304,  -304,  -304,   138,    45,   142,    48,
     144,   158,   156,   166,   168,   221,   221,  -304,  -304,   195,
     207,   205,   270,   930,   930,   930,   930,   930,   930,   930,
     930,   930,   930,   930,   930,   265,   223,   248,  -304,    81,
     942,   226,   249,   930,   229,   254,   930,   229,   255,   237,
    -304,   266,   243,   269,   930,  -304,   272,   930,   930,  -304,
     930,  1428,   247,   247,   204,   204,   204,   204,   288,   288,
     294,   294,   294,   930,   252,   256,   277,   276,    62,  1160,
    -304,   263,   278,    62,  1172,  -304,  -304,  1260,  -304,  -304,
    1428,  1272,  -304,    49,  1428,  -304,    63,  -304,   158,  -304,
     262,  1000,   251,   261,    71,  1428,   221,   355,  1428,   267,
    -304,   283,    62,  -304,   287,   290,  -304,  -304,  1351,   306,
     307,    19,    72,  1014,   226,   282,  1028,   930,   229,   930,
     229,  -304,   289,  -304,  -304,   930,  -304,  1428,  -304,  -304,
     930,  -304,   930,  -304,  -304,  1362,   291,   292,   109,   309,
     314,   -52,   -42,   316,  -304,  -304,   285,  1299,   930,  -304,
    -304,   296,   308,  1428,  -304,  1428,  -304,  -304,  -304,  -304,
    1428,    84,  1163,   930,  -304,  -304,   311,   313,  -304,   158,
     158,  -304,   930,  -304,   930,   317,   336,  -304,  1042,  1428,
      86,  -304,   318,  1190,  -304,  -304,  1428,   319,   320,  -304,
    -304,   323,   324,  1428,  1428,  -304,   321,  -304,   930,   930,
     930,  -304,  -304,   341,  -304,  -304,  -304,  -304,   344,   349,
    -304,  -304,   346,  1061,  1428,    91,  1428,  -304,  -304,   370,
     414,   327,   328,    99,  -304,   354,  -304,  -304,   930,   930,
     127,  -304,  -304,   375,   930,   930,   930,   369,    27,  -304,
     359,  -304,  -304,  -304,    54,  -304,  -304,  -304,  -304,   -49,
    -304,  -304,  -304,   374,   106,  -304,   357,  1428,    94,  -304,
    -304,  -304,   -23,  1143,  1428,  1157,  -304,  -304,  -304,    11,
    1373,   377,   930,   365,  -304,  1308,   385,  -304,  -304,   131,
     362,   363,   381,   384,   389,  -304,   930,  -304,  -304,  1388,
     107,  -304,   165,    25,   420,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  1428,   398,   400,  -304,  -304,  -304,   930,
    -304,   393,   421,   458,   502,  -304,  -304,   403,   404,   113,
     406,   930,  -304,   434,  -304,   546,   590,  -304,  -304,  -304,
    -304,   236,  -304,   409,  -304,  -304,   634,   678,   722,   402,
    -304,   413,  -304,   441,  -304,  -304,  -304,   930,   432,  -304,
    -304,  -304,  1428,  -304,   766,   810,  -304,   854,  -304,  -304,
     435,  -304,  -304,   898,  -304
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
       0,    88,    86,     0,     0,    51,     0,    26,     0,     0,
       0,    18,    25,     0,     0,     0,     0,   207,   202,   203,
     200,   201,     0,     0,     0,   206,   126,   198,   199,   204,
      96,    54,    79,    82,    29,   131,    95,    98,    91,   112,
      93,    39,    89,   106,    87,   188,   197,   208,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   215,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,     0,   150,     0,     0,     0,   187,
       0,   193,   195,   196,   191,   192,   189,   190,   181,   182,
     183,   184,   185,     0,     0,     0,     0,     0,    12,     0,
      55,     0,     0,    12,     0,    41,    38,     0,   132,   133,
      99,     0,   101,   102,   113,   115,   116,    40,    39,   107,
     108,     0,     0,     0,     0,   129,   186,     0,   194,     0,
     213,   210,    12,    56,     0,     0,    30,    24,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,     0,
       0,   111,     0,   209,   147,     0,   151,   153,   148,   127,
       0,   205,     0,   150,   211,     0,    59,    57,     0,     0,
       0,     0,     0,     0,    46,    28,     0,     0,     0,   126,
     134,     0,   120,   103,   105,   117,   119,   109,   152,   150,
     130,     0,     0,     0,    53,    52,     0,     0,    35,    39,
      39,    33,     0,    31,     0,     0,     0,   143,     0,   137,
     135,   122,     0,     0,   128,   214,   126,     0,     0,    60,
      58,     0,     0,   126,   126,    51,     0,   126,     0,     0,
       0,   126,   149,     0,    61,    61,    37,    36,     0,     0,
      54,    51,     0,     0,   136,     0,   144,   124,   212,     0,
       0,     0,     0,    12,    54,     0,   126,   123,     0,     0,
       0,    76,    77,     0,     0,    84,     0,     0,    12,    50,
      67,    68,    74,    72,    73,    75,    69,    70,    71,   155,
      49,    34,    32,     0,    12,   140,   142,   145,     0,    63,
      65,    64,     0,     0,    83,     0,    24,    85,    66,     0,
       0,     0,     0,     0,   125,     0,     0,   166,   168,     0,
       0,     0,     0,     0,     0,   156,     0,    48,    47,     0,
       0,   138,   207,     0,     0,    61,    61,    62,   157,   158,
     159,   160,   161,   154,     0,     0,    48,    47,   141,     0,
     174,     0,     0,     0,     0,    61,    61,     0,     0,     0,
       0,     0,   180,   162,   169,     0,     0,    61,    61,   139,
      61,   178,   176,   164,    44,    42,     0,     0,     0,     0,
     170,     0,   167,     0,    45,    43,   175,     0,     0,    61,
      61,   165,   178,    61,     0,     0,   172,     0,   177,   163,
       0,   171,    61,     0,   173
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -304,  -304,   -18,    -4,  -304,  -304,  -185,  -304,  -304,  -304,
    -304,  -152,  -304,  -304,   114,   116,  -304,  -247,  -304,  -304,
    -213,   352,  -267,  -304,     3,  -304,  -304,  -304,   503,  -304,
    -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -108,  -304,  -304,  -202,  -304,   295,  -304,  -304,
    -304,   310,  -304,  -304,  -303,  -211,  -304,  -304,  -198,   301,
    -304,  -304,  -304,    85,  -304,  -304,  -304,  -304,  -304,  -304,
    -304,  -304,  -304,  -304,    78,  -304,  -304,   -43,  -304,  -304,
    -204,  -304,  -304,  -304,  -304
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    74,   155,
     110,   120,   191,   226,   385,   384,    17,    71,   268,   267,
     109,   150,   299,   320,   321,    25,    46,   322,   323,    54,
      53,    49,    50,    48,    78,   114,   198,    84,    82,    80,
     117,   200,   162,   280,   309,   106,    23,   174,    76,   111,
     194,   158,   389,   352,   295,    65,   125,   239,   172,   206,
     325,   349,   366,   326,   423,   375,   430,   327,   376,   328,
     428,   440,   400,   421,   420,   390,   412,   207,    67,    68,
      69,   124,   243,   213,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    70,   218,    42,    21,    18,   338,   251,   107,   165,
     252,    20,    85,    86,   355,   242,   201,   253,   300,   108,
     254,    92,   360,   361,   362,   363,   364,   260,   290,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   263,   105,   356,   304,    22,    91,     5,     6,   370,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   347,   223,   283,  -206,  -206,  -206,  -206,  -206,
     160,   288,   289,   164,   224,   292,     3,   303,   365,   297,
     225,   171,     5,     6,   175,   176,   399,   177,   324,   324,
     234,   334,   236,   391,    43,   329,   329,   271,   272,    44,
     178,     5,     6,    39,   336,   149,   154,  -100,   393,   394,
    -114,  -104,   113,   156,   193,   116,   197,    45,   196,     5,
       6,  -206,  -206,    51,    52,  -118,     5,     6,   405,   406,
     199,   185,   209,    24,   227,    47,   190,   210,    26,   228,
     416,   417,    75,   418,   149,   264,   147,   148,   278,   188,
     210,    77,   307,   279,   233,   354,   235,   308,   248,    52,
     308,   359,   434,   435,   333,   148,   437,   240,   388,   175,
     220,   351,   148,   308,   409,   443,    72,    73,   215,   308,
     377,    52,   324,   324,   258,   259,   339,   340,   341,   329,
     329,    87,    79,    88,   324,   324,    81,   245,    83,    89,
     266,   329,   329,    90,   112,   324,   324,   324,   115,   273,
     118,   274,   329,   329,   329,   100,   101,   102,   103,   104,
     119,   105,   121,   324,   324,  -179,   324,    87,   122,    88,
     329,   329,   324,   329,   123,   293,   294,   296,  -207,   329,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   126,   105,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    55,   105,   337,   296,   127,    56,   143,
     128,   343,   344,   345,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   144,   105,   157,   145,
     159,   161,    57,    58,    59,   163,   166,    60,    61,   149,
     167,   102,   103,   104,   419,   105,   169,   168,    62,   296,
     170,   105,   373,   173,    21,    64,   204,   205,   181,   179,
     180,   182,   186,   383,   202,   208,   187,   212,   216,   256,
     149,   217,   368,    27,    28,   129,   130,    29,    30,    31,
      32,    33,    34,    35,    36,   214,   296,   221,   222,   231,
     249,   387,   237,   246,   247,   250,   261,   255,   411,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   310,   105,    37,   269,   262,   270,   276,   281,   284,
     285,   275,   286,   287,   432,   291,   331,   332,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     311,   312,   313,   314,   298,   315,   316,   301,   317,   318,
       9,    57,   302,   305,   335,   310,   342,   346,   348,   350,
     211,    11,   369,    12,   353,   371,   374,    62,   -12,   378,
     379,   319,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   311,   312,   313,   314,   380,   315,
     316,   381,   317,   318,     9,    57,   382,   392,   395,   310,
     396,   401,   402,   407,   408,    11,   410,    12,   413,   422,
     427,    62,   -12,   429,   314,   330,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   311,   312,
     313,   314,   433,   315,   316,   442,   317,   318,     9,    57,
     183,   398,   397,   310,   230,    19,   238,   241,   431,    11,
     436,    12,     0,     0,     0,    62,   -12,     0,     0,   403,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   311,   312,   313,   314,     0,   315,   316,     0,
     317,   318,     9,    57,     0,     0,     0,   310,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,    62,
     -12,     0,     0,   404,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   311,   312,   313,   314,
       0,   315,   316,     0,   317,   318,     9,    57,     0,     0,
       0,   310,     0,     0,     0,     0,     0,    11,     0,    12,
       0,     0,     0,    62,   -12,     0,     0,   414,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     311,   312,   313,   314,     0,   315,   316,     0,   317,   318,
       9,    57,     0,     0,     0,   310,     0,     0,     0,     0,
       0,    11,     0,    12,     0,     0,     0,    62,   -12,     0,
       0,   415,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   311,   312,   313,   314,     0,   315,
     316,     0,   317,   318,     9,    57,     0,     0,     0,   310,
       0,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,    62,   -12,     0,     0,   424,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   311,   312,
     313,   314,     0,   315,   316,     0,   317,   318,     9,    57,
       0,     0,     0,   310,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,     0,    62,   -12,     0,     0,   425,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   311,   312,   313,   314,     0,   315,   316,     0,
     317,   318,     9,    57,     0,     0,     0,   310,     0,     0,
       0,     0,     0,    11,     0,    12,     0,     0,     0,    62,
     -12,     0,     0,   426,   -12,   -12,     5,     6,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   311,   312,   313,   314,
       0,   315,   316,     0,   317,   318,     9,    57,     0,     0,
       0,   310,     0,     0,     0,     0,     0,    11,     0,    12,
       0,     0,     0,    62,   -12,     0,     0,   438,   -12,   -12,
       5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     311,   312,   313,   314,     0,   315,   316,     0,   317,   318,
       9,    57,     0,     0,     0,   310,     0,     0,     0,     0,
       0,    11,     0,    12,     0,     0,     0,    62,   -12,     0,
       0,   439,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   311,   312,   313,   314,     0,   315,
     316,     0,   317,   318,     9,    57,     0,     0,     0,   310,
       0,     0,     0,     0,     0,    11,     0,    12,     0,     0,
       0,    62,   -12,     0,     0,   441,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   311,   312,
     313,   314,     0,   315,   316,     0,   317,   318,     9,    57,
       0,     0,    55,   151,     0,     0,     0,    56,     0,    11,
       0,    12,     0,     0,     0,    62,   -12,     0,     0,   444,
     -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,    57,    58,    59,     0,     0,    60,    61,     0,     0,
     152,   153,     0,     0,     0,     0,   -27,    62,     0,     0,
       0,     0,     0,    11,    64,    12,     0,   -27,     0,     0,
     -12,     0,     0,   -27,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,   105,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,     0,   203,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   229,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    -2,     4,
       0,   232,     0,    27,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,     0,   277,   -12,   -12,     5,     6,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,     0,
       0,     0,     0,     0,   306,     0,     7,     8,     9,     0,
       0,     0,    10,    41,     0,     0,     0,     0,     0,    11,
       0,    12,    13,     0,     0,     0,   -12,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,    55,     0,     0,    27,    28,
      56,     0,    29,    30,    31,    32,    33,    34,    35,     0,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,     0,    55,   357,    57,    58,    59,    56,     0,    60,
      61,     0,     0,     0,     0,     0,     0,   358,   184,     0,
      62,     0,     0,     0,     0,     0,     0,    64,   265,   205,
     189,    57,    58,    59,     0,     0,    60,    61,     0,     0,
      55,     0,     0,     0,     0,    56,     0,    62,     0,     0,
       0,     0,    55,     0,    64,   282,   205,    56,    27,    28,
       0,     0,    29,    30,    31,    32,    33,    34,    35,    57,
      58,    59,    55,     0,    60,    61,     0,    56,     0,     0,
       0,    57,    58,    59,    55,    62,    60,    61,     0,    56,
       0,    63,    64,     0,     0,     0,     0,    62,     0,     0,
       0,    57,    58,    59,    64,     0,    60,    61,     0,     0,
       0,    55,     0,    57,    58,    59,    56,    62,    60,    61,
      55,     0,     0,   192,    64,    56,     0,     0,     0,    62,
       0,     0,     0,     0,     0,   195,    64,     0,     0,     0,
      57,    58,    59,     0,     0,    60,    61,     0,     0,   372,
      58,    59,     0,     0,    60,    61,    62,     0,     0,     0,
       0,     0,   257,    64,     0,    62,     0,     0,     0,    27,
      28,     0,    64,    29,    30,    31,    32,    33,    34,    35,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    27,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,     0,     0,     0,     0,    27,    28,     0,   219,
      29,    30,    31,    32,    33,    34,    35,     0,     0,     0,
     244,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,   386
};

static const yytype_int16 yycheck[] =
{
      43,    44,   187,    21,     8,     2,   309,    59,    57,   117,
      62,    48,    55,    56,    37,   213,   168,    59,   285,    68,
      62,    64,    11,    12,    13,    14,    15,   229,   275,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   239,    17,    66,   291,    41,    64,    20,    21,   352,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    35,    44,   266,    11,    12,    13,    14,    15,
     113,   273,   274,   116,    55,   277,     0,   290,    67,   281,
      61,   124,    20,    21,   127,   128,   389,   130,   299,   300,
     198,   304,   200,    68,    62,   299,   300,   249,   250,    67,
     143,    20,    21,    59,   306,   109,   110,    62,   375,   376,
      62,    62,    67,   110,   157,    67,    67,    64,   161,    20,
      21,    67,    68,    49,    50,    62,    20,    21,   395,   396,
      67,   149,    61,    41,    62,    60,   154,    66,    41,    67,
     407,   408,    41,   410,   148,    61,    65,    66,    62,   153,
      66,    41,    61,    67,   197,    61,   199,    66,    49,    50,
      66,   346,   429,   430,    65,    66,   433,   210,    61,   212,
     188,    65,    66,    66,    61,   442,    52,    53,   182,    66,
      49,    50,   393,   394,   227,   228,    59,    60,    61,   393,
     394,    62,    41,    64,   405,   406,    41,   215,    41,    58,
     243,   405,   406,    67,    66,   416,   417,   418,    66,   252,
      66,   254,   416,   417,   418,    11,    12,    13,    14,    15,
      62,    17,    66,   434,   435,    60,   437,    62,    62,    64,
     434,   435,   443,   437,    66,   278,   279,   280,    17,   443,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    57,    17,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    12,    17,   308,   309,    60,    17,     4,
      65,   314,   315,   316,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    63,    17,    62,    41,
      41,    62,    41,    42,    43,    41,    41,    46,    47,   303,
      63,    13,    14,    15,    68,    17,    63,    41,    57,   352,
      41,    17,   355,    41,   318,    64,    65,    66,    41,    67,
      64,    45,    59,   366,    62,    64,    48,    60,    41,    44,
     334,    41,   350,    18,    19,    65,    66,    22,    23,    24,
      25,    26,    27,    28,    29,    62,   389,    41,    41,    67,
      41,   369,    63,    62,    62,    41,    60,    41,   401,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     1,    17,    58,    63,    67,    63,    41,    60,    60,
      60,    64,    59,    59,   427,    64,    59,    59,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    63,    35,    36,    63,    38,    39,
      40,    41,    63,    67,    60,     1,    41,    48,    59,    45,
      65,    51,    45,    53,    67,    60,    41,    57,    58,    67,
      67,    61,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    67,    35,
      36,    67,    38,    39,    40,    41,    67,    37,    60,     1,
      60,    68,    41,    60,    60,    51,    60,    53,    34,    60,
      68,    57,    58,    60,    33,    61,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    60,    35,    36,    60,    38,    39,    40,    41,
     148,   387,   386,     1,   194,     2,   205,   212,   423,    51,
     432,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      58,    -1,    -1,    61,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    -1,    -1,    57,    58,    -1,    -1,    61,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      -1,    61,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    -1,    61,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    -1,
      38,    39,    40,    41,    -1,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,
      58,    -1,    -1,    61,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,
      -1,    -1,    -1,    57,    58,    -1,    -1,    61,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,
      -1,    61,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,     1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,
      -1,    57,    58,    -1,    -1,    61,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    -1,    38,    39,    40,    41,
      -1,    -1,    12,     1,    -1,    -1,    -1,    17,    -1,    51,
      -1,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    44,    57,    -1,    -1,
      -1,    -1,    -1,    51,    64,    53,    -1,    55,    -1,    -1,
      58,    -1,    -1,    61,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    63,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    63,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,    63,    -1,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    63,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    38,    39,    40,    -1,
      -1,    -1,    44,    58,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    53,    54,    -1,    -1,    -1,    58,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    12,    -1,    -1,    18,    19,
      17,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    12,    60,    41,    42,    43,    17,    -1,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    60,    58,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,    66,
      58,    41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    17,    -1,    57,    -1,    -1,
      -1,    -1,    12,    -1,    64,    65,    66,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    41,
      42,    43,    12,    -1,    46,    47,    -1,    17,    -1,    -1,
      -1,    41,    42,    43,    12,    57,    46,    47,    -1,    17,
      -1,    63,    64,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    41,    42,    43,    64,    -1,    46,    47,    -1,    -1,
      -1,    12,    -1,    41,    42,    43,    17,    57,    46,    47,
      12,    -1,    -1,    63,    64,    17,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    -1,    41,
      42,    43,    -1,    -1,    46,    47,    57,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    57,    -1,    -1,    -1,    18,
      19,    -1,    64,    22,    23,    24,    25,    26,    27,    28,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    18,    19,    -1,    58,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    58,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    73,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    72,    74,    76,    85,    93,    97,
      48,    72,    41,   115,    41,    94,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    58,    71,    59,
      75,    58,    71,    62,    67,    64,    95,    60,   102,   100,
     101,    49,    50,    99,    98,    12,    17,    41,    42,    43,
      46,    47,    57,    63,    64,   124,   146,   147,   148,   149,
     146,    86,    52,    53,    77,    41,   117,    41,   103,    41,
     108,    41,   107,    41,   106,   146,   146,    62,    64,    58,
      67,    71,   146,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    17,   114,    57,    68,    89,
      79,   118,    66,    67,   104,    66,    67,   109,    66,    62,
      80,    66,    62,    66,   150,   125,    57,    60,    65,    65,
      66,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,     4,    63,    41,   153,    65,    66,    72,
      90,     1,    38,    39,    72,    78,    93,    62,   120,    41,
     146,    62,   111,    41,   146,   111,    41,    63,    41,    63,
      41,   146,   127,    41,   116,   146,   146,   146,   146,    67,
      64,    41,    45,    90,    58,    71,    59,    48,    72,    58,
      71,    81,    63,   146,   119,    63,   146,    67,   105,    67,
     110,    80,    62,    63,    65,    66,   128,   146,    64,    61,
      66,    65,    60,   152,    62,    72,    41,    41,    75,    58,
      71,    41,    41,    44,    55,    61,    82,    62,    67,    63,
     120,    67,    63,   146,   111,   146,   111,    63,   128,   126,
     146,   116,   127,   151,    58,    71,    62,    62,    49,    41,
      41,    59,    62,    59,    62,    41,    44,    63,   146,   146,
     114,    60,    67,   127,    61,    65,   146,    88,    87,    63,
      63,    80,    80,   146,   146,    64,    41,    63,    62,    67,
     112,    60,    65,   114,    60,    60,    59,    59,   114,   114,
      86,    64,   114,   146,   146,   123,   146,   114,    63,    91,
      91,    63,    63,    89,    86,    67,    63,    61,    66,   113,
       1,    30,    31,    32,    33,    35,    36,    38,    39,    61,
      92,    93,    96,    97,   124,   129,   132,   136,   138,   149,
      61,    59,    59,    65,    89,    60,   114,   146,   123,    59,
      60,    61,    41,   146,   146,   146,    48,    35,    59,   130,
      45,    65,   122,    67,    61,    37,    66,    60,    60,    75,
      11,    12,    13,    14,    15,    67,   131,    58,    71,    45,
     123,    60,    41,   146,    41,   134,   137,    49,    67,    67,
      67,    67,    67,   146,    84,    83,    58,    71,    61,   121,
     144,    68,    37,    91,    91,    60,    60,    84,    83,   123,
     141,    68,    41,    61,    61,    91,    91,    60,    60,    61,
      60,   146,   145,    34,    61,    61,    91,    91,    91,    68,
     143,   142,    60,   133,    61,    61,    61,    68,   139,    60,
     135,   132,   146,    60,    91,    91,   143,    91,    61,    61,
     140,    61,    60,    91,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    75,    75,    77,    78,    76,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    82,    83,    84,    85,
      85,    86,    87,    88,    89,    89,    89,    90,    90,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    92,    94,    93,
      93,    95,    95,    96,    96,    96,    98,    97,    99,    97,
     100,    97,   101,    97,   102,    97,    97,    97,   103,   103,
     104,   103,   103,   103,   105,   103,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   108,   108,   108,   110,   108,
     111,   111,   112,   111,   113,   111,   114,   115,   115,   116,
     116,   118,   117,   119,   117,   120,   120,   120,   121,   120,
     122,   120,   120,   120,   123,   123,   125,   124,   126,   124,
     127,   127,   127,   128,   129,   130,   131,   131,   131,   131,
     131,   131,   132,   132,   133,   132,   134,   135,   137,   136,
     139,   138,   140,   138,   141,   138,   142,   138,   143,   144,
     145,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   147,
     147,   147,   147,   147,   147,   148,   149,   149,   150,   149,
     149,   151,   149,   152,   149,   153
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     0,     2,     2,     4,     2,
       1,     1,     1,     1,     0,     2,     0,     0,     8,     0,
       3,     5,     9,     5,     9,     5,     7,     7,     2,     0,
       2,     0,    13,    14,    13,    14,     1,     0,     0,    13,
      13,     0,     0,     0,     0,     2,     3,     3,     5,     3,
       5,     0,     5,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     2,     2,     1,     2,     0,     5,     0,     5,
       0,     4,     0,     4,     0,     4,     4,     2,     1,     3,
       0,     3,     3,     5,     0,     5,     1,     3,     3,     5,
       2,     4,     1,     3,     0,     3,     3,     5,     0,     5,
       3,     2,     0,     7,     0,     9,     0,     7,     9,     1,
       3,     0,     3,     0,     5,     4,     6,     4,     0,    13,
       0,    11,     8,     4,     1,     3,     0,     5,     0,     8,
       0,     2,     3,     1,     4,     0,     1,     2,     2,     2,
       2,     2,     6,    11,     0,     9,     0,     0,     0,     6,
       0,    12,     0,    15,     0,     9,     0,    11,     0,     0,
       0,     3,     3,     3,     3,     3,     4,     3,     2,     3,
       3,     3,     3,     3,     4,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     1,     0,     5,
       4,     0,     9,     0,     7,     0
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
#line 117 "parser.y"
                         {(yyval.m) = NONE_TYPE; }
#line 1925 "parser.tab.c"
    break;

  case 16:
#line 124 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1931 "parser.tab.c"
    break;

  case 18:
#line 128 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1937 "parser.tab.c"
    break;

  case 19:
#line 129 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1943 "parser.tab.c"
    break;

  case 20:
#line 130 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1949 "parser.tab.c"
    break;

  case 21:
#line 131 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1955 "parser.tab.c"
    break;

  case 23:
#line 133 "parser.y"
               {expr_type =VOID_TYPE;}
#line 1961 "parser.tab.c"
    break;

  case 25:
#line 136 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1967 "parser.tab.c"
    break;

  case 26:
#line 140 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1973 "parser.tab.c"
    break;

  case 27:
#line 140 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1979 "parser.tab.c"
    break;

  case 28:
#line 140 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1985 "parser.tab.c"
    break;

  case 31:
#line 144 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1994 "parser.tab.c"
    break;

  case 32:
#line 148 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 2002 "parser.tab.c"
    break;

  case 33:
#line 151 "parser.y"
                                                  {if((yyvsp[-3].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                    } 
                                                    if(strcmp((yyvsp[-2].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].s),(yyvsp[-1].s),false,yylineno);
                                                    printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],(yyvsp[-2].s),(yyvsp[-1].s));
                                                    free((yyvsp[-2].s));free((yyvsp[-1].s));}}
#line 2015 "parser.tab.c"
    break;

  case 34:
#line 159 "parser.y"
                                                                            {if((yyvsp[-7].m) == STATIC_TYPE){
                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                    }
                                                    if(strcmp((yyvsp[-6].s),current_class->name)==0){
                                                        yyerror("cannot reference a class in itself");
                                                    }else{add_class_type_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].s),(yyvsp[-5].s),true,yylineno);
                                                    printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],(yyvsp[-6].s),(yyvsp[-5].s),(yyvsp[-3].s));
                                                    free((yyvsp[-6].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}}
#line 2028 "parser.tab.c"
    break;

  case 35:
#line 167 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2034 "parser.tab.c"
    break;

  case 36:
#line 168 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 2042 "parser.tab.c"
    break;

  case 37:
#line 171 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2050 "parser.tab.c"
    break;

  case 39:
#line 176 "parser.y"
                        {(yyval.b)= false;}
#line 2056 "parser.tab.c"
    break;

  case 40:
#line 177 "parser.y"
                {(yyval.b) = true;}
#line 2062 "parser.tab.c"
    break;

  case 42:
#line 180 "parser.y"
                                                                                                          {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2076 "parser.tab.c"
    break;

  case 43:
#line 189 "parser.y"
                                                                                                                     {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-10].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2090 "parser.tab.c"
    break;

  case 44:
#line 198 "parser.y"
                                                                                                                     {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);}
                                                                                                    free((yyvsp[-10].s));free((yyvsp[-4].s));
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2102 "parser.tab.c"
    break;

  case 45:
#line 205 "parser.y"
                                                                                                                                {printcode("}\n");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-10].s),type_arr[fn_type]);}
                                                                                                    free((yyvsp[-10].s));free((yyvsp[-4].s));
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    is_static_method = false;}
#line 2114 "parser.tab.c"
    break;

  case 46:
#line 215 "parser.y"
                           {is_static_method = true;}
#line 2120 "parser.tab.c"
    break;

  case 47:
#line 219 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2131 "parser.tab.c"
    break;

  case 48:
#line 227 "parser.y"
                                {add_class_ret_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].s), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = CLASS_TYPE;
                            fn_ret_class = (yyvsp[0].s);
                            is_in_fn = true;
                            has_returned = false;}
#line 2143 "parser.tab.c"
    break;

  case 49:
#line 235 "parser.y"
                                                                                                                {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require %s return type, corresponding return statement not found",(yyvsp[-11].s),type_arr[fn_type]);
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));
                                                                                                    is_in_fn = false;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2157 "parser.tab.c"
    break;

  case 50:
#line 244 "parser.y"
                                                                                                                        {printcode("}");
                                                                                                    if(fn_type != VOID_TYPE && !has_returned){
                                                                                                        yyerror("function %s require class %s return type, corresponding return statement not found",(yyvsp[-11].s),(yyvsp[-4].s));
                                                                                                    }
                                                                                                    free((yyvsp[-11].s));free((yyvsp[-4].s));
                                                                                                    is_in_fn = false;fn_ret_class = NULL;
                                                                                                    popscope();
                                                                                                    clear_literals();
                                                                                                    }
#line 2171 "parser.tab.c"
    break;

  case 51:
#line 253 "parser.y"
                                {pushscope();}
#line 2177 "parser.tab.c"
    break;

  case 52:
#line 254 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2186 "parser.tab.c"
    break;

  case 53:
#line 259 "parser.y"
                                {print_fn_delc((yyvsp[(-7) - (0)].s));
                                fn_type = CLASS_TYPE;
                                fn_ret_class =(yyvsp[0].s);
                                is_in_fn = true;
                                has_returned = false;}
#line 2196 "parser.tab.c"
    break;

  case 57:
#line 269 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2202 "parser.tab.c"
    break;

  case 58:
#line 270 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2208 "parser.tab.c"
    break;

  case 59:
#line 271 "parser.y"
                                        {add_class_param((yyvsp[-2].m), (yyvsp[-1].s), false,(yyvsp[0].s));create_class_var((yyvsp[-2].m), (yyvsp[-1].s), (yyvsp[0].s), false,yylineno);free((yyvsp[-1].s));free((yyvsp[0].s));}
#line 2214 "parser.tab.c"
    break;

  case 60:
#line 272 "parser.y"
                                            {add_class_param((yyvsp[-4].m), (yyvsp[-3].s), true,(yyvsp[-2].s));create_class_var((yyvsp[-4].m), (yyvsp[-3].s), (yyvsp[-2].s), true,yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2220 "parser.tab.c"
    break;

  case 62:
#line 275 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2226 "parser.tab.c"
    break;

  case 63:
#line 276 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2232 "parser.tab.c"
    break;

  case 64:
#line 277 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2238 "parser.tab.c"
    break;

  case 65:
#line 278 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2244 "parser.tab.c"
    break;

  case 66:
#line 279 "parser.y"
                        {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2250 "parser.tab.c"
    break;

  case 67:
#line 280 "parser.y"
                    {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2256 "parser.tab.c"
    break;

  case 69:
#line 282 "parser.y"
                      {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2262 "parser.tab.c"
    break;

  case 70:
#line 283 "parser.y"
                         {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2268 "parser.tab.c"
    break;

  case 71:
#line 284 "parser.y"
                       {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2274 "parser.tab.c"
    break;

  case 73:
#line 288 "parser.y"
             {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2280 "parser.tab.c"
    break;

  case 76:
#line 291 "parser.y"
            {printcode("break;");}
#line 2286 "parser.tab.c"
    break;

  case 77:
#line 292 "parser.y"
                {printcode("continue;");}
#line 2292 "parser.tab.c"
    break;

  case 78:
#line 295 "parser.y"
                       {printcode("/*");}
#line 2298 "parser.tab.c"
    break;

  case 79:
#line 295 "parser.y"
                                                                 {printcode("*/");}
#line 2304 "parser.tab.c"
    break;

  case 80:
#line 296 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2310 "parser.tab.c"
    break;

  case 82:
#line 299 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2316 "parser.tab.c"
    break;

  case 83:
#line 301 "parser.y"
                         { if(expr_type != fn_type){
                                yyerror("invalid return type : expected %s, found %s",type_arr[fn_type],type_arr[expr_type]);
                            }else if(fn_type == CLASS_TYPE && strcmp(expr_class,fn_ret_class) !=0){
                                yyerror("invalid return type : expected class %s found class %s",fn_ret_class,expr_class);
                            }else{
                                printcode("return %s;",(yyvsp[0].s));
                                has_returned = true;
                            }
                            free((yyvsp[0].s));}
#line 2330 "parser.tab.c"
    break;

  case 84:
#line 310 "parser.y"
                      {if(fn_type != VOID_TYPE){
                            yyerror("return statement without value is not allowed for function type other than void.");
                        }else{
                            printcode("return;");
                            has_returned = true;
                        }
                        }
#line 2342 "parser.tab.c"
    break;

  case 85:
#line 317 "parser.y"
                          {has_returned = true;}
#line 2348 "parser.tab.c"
    break;

  case 86:
#line 320 "parser.y"
                                    {temp_type = (yyvsp[0].t);}
#line 2354 "parser.tab.c"
    break;

  case 87:
#line 320 "parser.y"
                                                               {temp_type = VOID_TYPE;}
#line 2360 "parser.tab.c"
    break;

  case 88:
#line 321 "parser.y"
                              {temp_type = CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2366 "parser.tab.c"
    break;

  case 89:
#line 321 "parser.y"
                                                                                    {temp_type = VOID_TYPE;temp_class=NULL;free((yyvsp[-2].s));}
#line 2372 "parser.tab.c"
    break;

  case 90:
#line 322 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));arr_type=temp_type=CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2378 "parser.tab.c"
    break;

  case 91:
#line 322 "parser.y"
                                                                                                                        {printcode(" ;");free((yyvsp[-2].s));arr_type=temp_type=VOID_TYPE;temp_class= NULL;}
#line 2384 "parser.tab.c"
    break;

  case 92:
#line 323 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2390 "parser.tab.c"
    break;

  case 93:
#line 323 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2396 "parser.tab.c"
    break;

  case 94:
#line 324 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2402 "parser.tab.c"
    break;

  case 95:
#line 324 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2408 "parser.tab.c"
    break;

  case 96:
#line 325 "parser.y"
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
#line 2424 "parser.tab.c"
    break;

  case 98:
#line 339 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2430 "parser.tab.c"
    break;

  case 99:
#line 340 "parser.y"
                          {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2441 "parser.tab.c"
    break;

  case 100:
#line 346 "parser.y"
                 {/*nothing dummymust be kept to maintain arraydecl*/}
#line 2447 "parser.tab.c"
    break;

  case 101:
#line 346 "parser.y"
                                                                                 {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2453 "parser.tab.c"
    break;

  case 102:
#line 347 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2459 "parser.tab.c"
    break;

  case 103:
#line 348 "parser.y"
                                           {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2470 "parser.tab.c"
    break;

  case 104:
#line 354 "parser.y"
                                  {printcode(", ");}
#line 2476 "parser.tab.c"
    break;

  case 105:
#line 354 "parser.y"
                                                               {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2482 "parser.tab.c"
    break;

  case 106:
#line 360 "parser.y"
                     {add_var((yyvsp[(-1) - (1)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2488 "parser.tab.c"
    break;

  case 107:
#line 361 "parser.y"
                         {add_array((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2494 "parser.tab.c"
    break;

  case 108:
#line 362 "parser.y"
                              {add_var((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2500 "parser.tab.c"
    break;

  case 109:
#line 363 "parser.y"
                                      {add_array((yyvsp[(-1) - (5)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2506 "parser.tab.c"
    break;

  case 110:
#line 366 "parser.y"
                                     {create_class_var((yyvsp[(-2) - (2)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2512 "parser.tab.c"
    break;

  case 111:
#line 367 "parser.y"
                                            {create_class_var((yyvsp[(-2) - (4)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2518 "parser.tab.c"
    break;

  case 112:
#line 370 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2526 "parser.tab.c"
    break;

  case 113:
#line 373 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2535 "parser.tab.c"
    break;

  case 114:
#line 377 "parser.y"
                {/*nothing dummy*/}
#line 2541 "parser.tab.c"
    break;

  case 115:
#line 377 "parser.y"
                                              {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2547 "parser.tab.c"
    break;

  case 116:
#line 378 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2555 "parser.tab.c"
    break;

  case 117:
#line 381 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2565 "parser.tab.c"
    break;

  case 118:
#line 386 "parser.y"
                             {printcode(", ");}
#line 2571 "parser.tab.c"
    break;

  case 119:
#line 386 "parser.y"
                                                          {add_array((yyvsp[(-2) - (5)].m),  (yyvsp[(-1) - (5)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2577 "parser.tab.c"
    break;

  case 120:
#line 389 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2588 "parser.tab.c"
    break;

  case 121:
#line 395 "parser.y"
                      {yyerror("Array size missing");}
#line 2594 "parser.tab.c"
    break;

  case 122:
#line 396 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2600 "parser.tab.c"
    break;

  case 123:
#line 396 "parser.y"
                                                                         {printcode(" }");}
#line 2606 "parser.tab.c"
    break;

  case 124:
#line 397 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2612 "parser.tab.c"
    break;

  case 125:
#line 397 "parser.y"
                                                                                                          {printcode(" }");}
#line 2618 "parser.tab.c"
    break;

  case 126:
#line 401 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2624 "parser.tab.c"
    break;

  case 127:
#line 403 "parser.y"
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
#line 2640 "parser.tab.c"
    break;

  case 128:
#line 414 "parser.y"
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
#line 2655 "parser.tab.c"
    break;

  case 129:
#line 425 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
#line 2661 "parser.tab.c"
    break;

  case 130:
#line 426 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2675 "parser.tab.c"
    break;

  case 131:
#line 437 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2681 "parser.tab.c"
    break;

  case 132:
#line 437 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2687 "parser.tab.c"
    break;

  case 133:
#line 438 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2693 "parser.tab.c"
    break;

  case 134:
#line 438 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2699 "parser.tab.c"
    break;

  case 135:
#line 441 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2705 "parser.tab.c"
    break;

  case 136:
#line 442 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2712 "parser.tab.c"
    break;

  case 137:
#line 444 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2719 "parser.tab.c"
    break;

  case 138:
#line 446 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2725 "parser.tab.c"
    break;

  case 139:
#line 446 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2733 "parser.tab.c"
    break;

  case 140:
#line 449 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2739 "parser.tab.c"
    break;

  case 141:
#line 449 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2747 "parser.tab.c"
    break;

  case 142:
#line 452 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2753 "parser.tab.c"
    break;

  case 143:
#line 454 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2759 "parser.tab.c"
    break;

  case 144:
#line 458 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}

                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2770 "parser.tab.c"
    break;

  case 145:
#line 464 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2779 "parser.tab.c"
    break;

  case 146:
#line 469 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2785 "parser.tab.c"
    break;

  case 147:
#line 469 "parser.y"
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
                                                                                                            //!TODO DO we need these clauses now, yeah....we'll see?
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
#line 2833 "parser.tab.c"
    break;

  case 148:
#line 512 "parser.y"
                                         {push_expr_and_args();is_in_fncall=true;}
#line 2839 "parser.tab.c"
    break;

  case 149:
#line 512 "parser.y"
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
                                                                                                        //!TODO DO we need these clauses now, yeah....we'll see?
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
#line 2882 "parser.tab.c"
    break;

  case 153:
#line 557 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2893 "parser.tab.c"
    break;

  case 154:
#line 565 "parser.y"
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
#line 2920 "parser.tab.c"
    break;

  case 155:
#line 590 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 2929 "parser.tab.c"
    break;

  case 156:
#line 596 "parser.y"
                {(yyval.s) = "=";}
#line 2935 "parser.tab.c"
    break;

  case 157:
#line 597 "parser.y"
              {(yyval.s) = "+=";}
#line 2941 "parser.tab.c"
    break;

  case 158:
#line 598 "parser.y"
              {(yyval.s) = "-=";}
#line 2947 "parser.tab.c"
    break;

  case 159:
#line 599 "parser.y"
              {(yyval.s) = "*=";}
#line 2953 "parser.tab.c"
    break;

  case 160:
#line 600 "parser.y"
              {(yyval.s) = "/=";}
#line 2959 "parser.tab.c"
    break;

  case 161:
#line 601 "parser.y"
              {(yyval.s) = "%=";}
#line 2965 "parser.tab.c"
    break;

  case 162:
#line 604 "parser.y"
                                         {popscope();printcode("}\n");}
#line 2971 "parser.tab.c"
    break;

  case 163:
#line 605 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 2977 "parser.tab.c"
    break;

  case 164:
#line 606 "parser.y"
                                            {popscope();printcode("}else ");}
#line 2983 "parser.tab.c"
    break;

  case 166:
#line 609 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 2989 "parser.tab.c"
    break;

  case 167:
#line 613 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 2995 "parser.tab.c"
    break;

  case 168:
#line 617 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 3001 "parser.tab.c"
    break;

  case 169:
#line 617 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 3007 "parser.tab.c"
    break;

  case 170:
#line 620 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3013 "parser.tab.c"
    break;

  case 171:
#line 620 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 3019 "parser.tab.c"
    break;

  case 172:
#line 621 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3025 "parser.tab.c"
    break;

  case 173:
#line 621 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 3031 "parser.tab.c"
    break;

  case 174:
#line 622 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3037 "parser.tab.c"
    break;

  case 175:
#line 622 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 3043 "parser.tab.c"
    break;

  case 176:
#line 623 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3049 "parser.tab.c"
    break;

  case 177:
#line 623 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 3055 "parser.tab.c"
    break;

  case 178:
#line 626 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 3061 "parser.tab.c"
    break;

  case 179:
#line 630 "parser.y"
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
#line 3085 "parser.tab.c"
    break;

  case 180:
#line 652 "parser.y"
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
#line 3109 "parser.tab.c"
    break;

  case 181:
#line 673 "parser.y"
                      { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            is_composite_val =false;}
#line 3117 "parser.tab.c"
    break;

  case 182:
#line 676 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3125 "parser.tab.c"
    break;

  case 183:
#line 679 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3133 "parser.tab.c"
    break;

  case 184:
#line 682 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s));
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3141 "parser.tab.c"
    break;

  case 185:
#line 685 "parser.y"
                      {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use mod on %s type",type_arr[expr_type]);} 
                                            (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 3148 "parser.tab.c"
    break;

  case 186:
#line 687 "parser.y"
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
#line 3165 "parser.tab.c"
    break;

  case 187:
#line 699 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 3171 "parser.tab.c"
    break;

  case 188:
#line 700 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s));if(expr_type == CLASS_TYPE){yyerror("Cannot use negetive on class type");}}
#line 3177 "parser.tab.c"
    break;

  case 189:
#line 701 "parser.y"
                       {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3184 "parser.tab.c"
    break;

  case 190:
#line 703 "parser.y"
                       {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use > with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3191 "parser.tab.c"
    break;

  case 191:
#line 705 "parser.y"
                            {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use <= with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3198 "parser.tab.c"
    break;

  case 192:
#line 707 "parser.y"
                             {if(expr_type == COMPLEX_TYPE|| expr_type == CLASS_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3205 "parser.tab.c"
    break;

  case 193:
#line 709 "parser.y"
                                        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                            (yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3212 "parser.tab.c"
    break;

  case 194:
#line 711 "parser.y"
                                        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                        (yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3219 "parser.tab.c"
    break;

  case 195:
#line 713 "parser.y"
                     {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                            (yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3226 "parser.tab.c"
    break;

  case 196:
#line 715 "parser.y"
                      {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");} 
                        (yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3233 "parser.tab.c"
    break;

  case 197:
#line 717 "parser.y"
                 {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                    char * t =join("(",(yyvsp[0].s),")");(yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3240 "parser.tab.c"
    break;

  case 199:
#line 722 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 3250 "parser.tab.c"
    break;

  case 200:
#line 727 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 3260 "parser.tab.c"
    break;

  case 201:
#line 732 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 3271 "parser.tab.c"
    break;

  case 202:
#line 738 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 3281 "parser.tab.c"
    break;

  case 203:
#line 743 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 3287 "parser.tab.c"
    break;

  case 205:
#line 747 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3299 "parser.tab.c"
    break;

  case 207:
#line 757 "parser.y"
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
#line 3327 "parser.tab.c"
    break;

  case 208:
#line 780 "parser.y"
                     {push_expr_and_args();}
#line 3333 "parser.tab.c"
    break;

  case 209:
#line 780 "parser.y"
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
#line 3366 "parser.tab.c"
    break;

  case 210:
#line 808 "parser.y"
                                             { attr* a = NULL;
                                        if(expr_type == CLASS_TYPE)a = find_attr(expr_class,(yyvsp[0].s));
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[0].s),expr_class);
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
                                        }
                                        (yyval.s) = join((yyvsp[-3].s),".",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));
                                    }
#line 3393 "parser.tab.c"
    break;

  case 211:
#line 830 "parser.y"
                                                 {push_expr_and_args();}
#line 3399 "parser.tab.c"
    break;

  case 212:
#line 830 "parser.y"
                                                                                                  { attr* a = NULL;
                                                                                                pop_expr_and_args();
                                                                                            if(expr_type == CLASS_TYPE)a = find_attr(expr_class,(yyvsp[-5].s));    
                                                                                            if(a== NULL){
                                                                                                yyerror("No attribute %s declared on class %s",(yyvsp[-8].s),(yyvsp[-5].s));
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
                                                                                            char * t = join((yyvsp[-8].s),".",(yyvsp[-5].s));
                                                                                            char *tt = join(t,"[",(yyvsp[-2].s));
                                                                                            (yyval.s) = join(tt,"]","");
                                                                                            free(t);free(tt);
                                                                                            free((yyvsp[-8].s));free((yyvsp[-5].s));free((yyvsp[-2].s));}
#line 3430 "parser.tab.c"
    break;

  case 213:
#line 856 "parser.y"
                                  {push_expr_and_args();is_in_fncall=true;}
#line 3436 "parser.tab.c"
    break;

  case 214:
#line 856 "parser.y"
                                                                                        {if(!is_in_fn){
                                                                                                    yyerror("Function call is not allowed outside a function.");
                                                                                                    (yyval.s) = strdup("");
                                                                                                }else {
                                                                                                    method * m =find_method(expr_class,(yyvsp[-4].s));
                                                                                                    if(m == NULL){
                                                                                                        yyerror("No method named %s found in class %s",(yyvsp[-4].s),expr_class);
                                                                                                        (yyval.s) = strdup("");
                                                                                                    }else if(!is_callable){
                                                                                                        yyerror("methods can only be called on class type variables or members");
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
                                                                                                        //!TODO DO we need these clauses now, yeah....we'll see?
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

                                                                                                    free((yyvsp[-6].s));free((yyvsp[-4].s));
                                                                                                is_in_fncall = false;}
#line 3485 "parser.tab.c"
    break;

  case 215:
#line 902 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3491 "parser.tab.c"
    break;


#line 3495 "parser.tab.c"

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
#line 904 "parser.y"


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
