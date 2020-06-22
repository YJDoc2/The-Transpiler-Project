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
    bool is_callable = true;
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
#define YYLAST   1420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  87
/* YYNRULES -- Number of rules.  */
#define YYNRULES  220
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  455

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
     347,   347,   348,   348,   349,   350,   357,   357,   361,   362,
     378,   395,   396,   397,   398,   401,   402,   405,   408,   412,
     412,   413,   416,   421,   421,   424,   430,   431,   431,   432,
     432,   436,   438,   449,   460,   461,   472,   472,   473,   473,
     476,   477,   479,   481,   481,   484,   484,   487,   489,   493,
     499,   504,   504,   547,   547,   587,   588,   589,   592,   600,
     625,   631,   632,   633,   634,   635,   636,   639,   640,   641,
     641,   644,   648,   652,   652,   655,   655,   656,   656,   657,
     657,   658,   658,   661,   665,   687,   708,   711,   714,   717,
     720,   722,   734,   735,   736,   738,   740,   742,   744,   746,
     748,   750,   752,   754,   757,   762,   767,   773,   778,   779,
     782,   791,   792,   815,   815,   843,   864,   864,   889,   889,
     935
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
  "$@7", "$@8", "classvarlist", "$@9", "$@10", "$@11", "classvals",
  "decllist", "classdecllist", "varlist", "$@12", "$@13", "arraydecl",
  "$@14", "$@15", "arraysizedummy", "letarraydecl", "letarrvals",
  "chararrdecllist", "$@16", "$@17", "strdecl", "$@18", "$@19",
  "arrayvallist", "fncall", "$@20", "$@21", "arglist", "arg", "assignstmt",
  "assigndummy", "assgtype", "ifstmt", "$@22", "ifdummy", "elsedummy",
  "whilestmt", "$@23", "forstmt", "$@24", "$@25", "$@26", "$@27",
  "rangecheckdummy", "simplearraydummy", "iterarraydummy", "expr", "value",
  "cmplxnum", "varvals", "$@28", "$@29", "$@30", "classcheckdummy", YY_NULLPTR
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

#define YYPACT_NINF (-314)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-185)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -314,    46,  1069,  -314,  -314,  -314,  -314,     0,   134,    28,
      34,  -314,  -314,   105,   182,  -314,  -314,  -314,  -314,    31,
    -314,   246,    32,  -314,    59,  -314,   142,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
     126,  -314,  -314,  1209,  1289,  -314,   183,  -314,   172,   191,
     193,  -314,  -314,   198,   203,  1289,  1289,   -54,  -314,  -314,
    -314,  -314,   190,   196,  1221,  -314,  1387,  -314,  -314,    60,
    1387,  -314,  -314,  -314,  -314,  -314,   209,    41,   212,    49,
     214,   219,   233,   238,   235,   286,   286,  -314,  -314,   248,
     247,   241,   245,  1289,  1289,  1289,  1289,  1289,  1289,  1289,
    1289,  1289,  1289,  1289,  1289,   305,   249,   272,  -314,    -3,
     923,   252,   274,   911,   254,   276,  1289,   254,   277,   257,
    -314,   280,   260,   284,  1289,  -314,   288,  1289,  1289,  -314,
    1289,  1387,  1349,  1349,   177,   177,   177,   177,   216,   216,
     313,   313,   313,  1289,   267,   271,   295,   292,   134,   339,
    -314,   279,   296,   134,  1056,  -314,  -314,  1241,  -314,  -314,
    -314,  1387,  1253,  -314,    58,  1387,  -314,    62,  -314,   219,
    -314,   278,   981,   285,   283,    70,  1387,   286,   281,  1387,
     293,  -314,   297,   134,  -314,   302,   304,  -314,  -314,  1141,
     307,   314,    22,    75,   995,   252,  -314,   287,  1009,  1289,
     254,  1289,   254,  -314,   322,  -314,  -314,  1289,  -314,  1387,
    -314,  -314,  1289,  -314,  1289,  -314,  -314,  1153,   326,   331,
     197,   354,   357,   118,   137,   358,  -314,  -314,   356,  1280,
    1289,  -314,  -314,    35,   341,   336,  1387,  -314,  1387,  -314,
    -314,  -314,  -314,  1387,    79,  1144,  1289,  -314,  -314,   342,
     343,  -314,   219,   219,  -314,  1289,  -314,  1289,   346,   366,
    -314,  1023,  1387,    82,   344,  -314,   388,  -314,   372,  1171,
    -314,  -314,  1387,   377,   378,  -314,  -314,   380,   382,  1387,
    1387,  -314,   379,  -314,  1289,  1289,  1289,   375,  1289,  -314,
    -314,   381,  -314,  -314,  -314,  -314,   384,   386,  -314,  -314,
     383,  1042,  1387,  1387,  1289,    86,  1387,  -314,  -314,   351,
     395,   392,   396,    -1,  -314,   385,  -314,  1387,  -314,  1289,
    1289,   106,  -314,  -314,   413,  1289,  1289,  1289,   425,    77,
    -314,   417,  -314,  -314,  -314,  -314,  -314,  -314,  -314,   170,
    -314,  -314,  -314,   436,     2,  -314,   415,  1387,    96,  -314,
    -314,  -314,     6,  1124,  1387,  1138,  -314,  -314,  -314,    13,
    1351,   438,  1289,   426,  -314,  1308,   444,  -314,  -314,   217,
     420,   421,   422,   424,   427,  -314,  1289,  -314,  -314,  1362,
     102,  -314,   133,    27,   456,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  1387,   435,   457,  -314,  -314,  -314,  1289,
    -314,   430,   458,   439,   483,  -314,  -314,   460,   465,   113,
     466,  1289,  -314,   493,  -314,   527,   571,  -314,  -314,  -314,
    -314,   211,  -314,   469,  -314,  -314,   615,   659,   703,   462,
    -314,   471,  -314,   499,  -314,  -314,  -314,  1289,   473,  -314,
    -314,  -314,  1387,  -314,   747,   791,  -314,   835,  -314,  -314,
     475,  -314,  -314,   879,  -314
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
       0,    18,    25,     0,     0,     0,     0,   212,   207,   208,
     205,   206,     0,     0,     0,   211,   131,   203,   204,   209,
      96,    54,    79,    82,    29,   136,    95,    98,    91,   117,
      93,    39,    89,   111,    87,   193,   202,   213,   151,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   220,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,   155,     0,     0,     0,   192,
       0,   198,   200,   201,   196,   197,   194,   195,   186,   187,
     188,   189,   190,     0,     0,     0,     0,     0,    12,     0,
      55,     0,     0,    12,     0,    41,    38,     0,   137,   138,
     100,    99,     0,   103,   104,   118,   120,   121,    40,    39,
     112,   113,     0,     0,     0,     0,   134,   191,     0,   199,
       0,   218,   215,    12,    56,     0,     0,    30,    24,     0,
       0,     0,     0,     0,     0,     0,   108,   126,     0,     0,
       0,     0,     0,   116,     0,   214,   152,     0,   156,   158,
     153,   132,     0,   210,     0,   155,   216,     0,    59,    57,
       0,     0,     0,     0,     0,     0,    46,    28,     0,     0,
       0,   131,   139,     0,     0,   125,   105,   107,   122,   124,
     114,   157,   155,   135,     0,     0,     0,    53,    52,     0,
       0,    35,    39,    39,    33,     0,    31,     0,     0,     0,
     148,     0,   142,   140,     0,   101,     0,   127,     0,     0,
     133,   219,   131,     0,     0,    60,    58,     0,     0,   131,
     131,    51,     0,   131,     0,     0,     0,     0,     0,   131,
     154,     0,    61,    61,    37,    36,     0,     0,    54,    51,
       0,     0,   141,   109,     0,     0,   149,   129,   217,     0,
       0,     0,     0,    12,    54,     0,   131,   110,   128,     0,
       0,     0,    76,    77,     0,     0,    84,     0,     0,    12,
      50,    67,    68,    74,    72,    75,    69,    70,    71,    73,
      49,    34,    32,     0,    12,   145,   147,   150,     0,    63,
      65,    64,     0,     0,    83,     0,    24,    85,    66,     0,
       0,     0,     0,     0,   130,     0,     0,   171,   173,     0,
       0,     0,     0,     0,     0,   161,     0,    48,    47,     0,
       0,   143,   212,     0,     0,    61,    61,    62,   162,   163,
     164,   165,   166,   159,     0,     0,    48,    47,   146,     0,
     179,     0,     0,     0,     0,    61,    61,     0,     0,     0,
       0,     0,   185,   167,   174,     0,     0,    61,    61,   144,
      61,   183,   181,   169,    44,    42,     0,     0,     0,     0,
     175,     0,   172,     0,    45,    43,   180,     0,     0,    61,
      61,   170,   183,    61,     0,     0,   177,     0,   182,   168,
       0,   176,    61,     0,   178
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,   -19,    -5,  -314,  -314,  -184,  -314,  -314,  -314,
    -314,  -160,  -314,  -314,   140,   143,  -314,  -270,  -314,  -314,
    -196,   390,  -279,  -314,     3,  -314,  -314,  -314,   540,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -111,  -314,  -314,  -201,  -314,   329,
    -314,  -314,  -314,   369,  -314,  -314,  -313,  -314,  -314,  -314,
    -168,   362,  -314,  -314,  -314,   128,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,   129,  -314,  -314,   -43,
    -314,  -314,  -294,  -314,  -314,  -314,  -314
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    38,    14,     2,    15,    40,    16,    74,   155,
     110,   120,   192,   228,   395,   394,    17,    71,   274,   273,
     109,   150,   309,   331,   332,    25,    46,   333,   334,    54,
      53,    49,    50,    48,    78,   196,   114,   200,   233,    84,
      82,    80,   117,   202,   163,   288,   320,   106,    23,   175,
      76,   111,   195,   158,   399,   362,   305,    65,   125,   242,
     173,   208,   335,   359,   376,   336,   433,   385,   440,   337,
     386,   338,   438,   450,   410,   431,   430,   400,   422,   209,
      67,    68,    69,   124,   246,   215,   146
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    70,    42,    21,   220,    18,   166,   348,    87,   203,
      88,   298,    85,    86,   310,   339,   339,     5,     6,     5,
       6,    92,     5,     6,   370,   371,   372,   373,   374,   314,
     263,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   365,   105,    91,     3,   245,    20,   380,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   147,   148,   343,   148,   225,   361,   148,    22,
     161,   291,   366,   165,   269,    24,   264,   226,   296,   297,
     375,   172,   300,   227,   176,   177,   409,   178,   307,   237,
      39,   239,   277,   278,    43,   401,   265,     5,     6,    44,
     179,   266,   313,  -102,   149,   154,   403,   404,   113,   339,
     339,  -119,   357,   156,   194,   346,   116,   107,   344,   198,
    -106,   339,   339,    45,  -123,   199,   415,   416,   108,   201,
     186,   211,   339,   339,   339,   191,   212,   229,   426,   427,
     270,   428,   230,   149,   284,   212,    26,   318,   189,   285,
     339,   339,   319,   339,     5,     6,   236,   364,   238,   339,
     444,   445,   319,   398,   447,   349,   350,   351,   319,   243,
     222,   176,   369,   453,   419,    51,    52,   254,   217,   319,
     255,  -160,  -160,  -160,  -160,  -160,   261,   262,   100,   101,
     102,   103,   104,  -184,   105,    87,   256,    88,   248,   257,
      27,    28,    47,   272,    29,    30,    31,    32,    33,    34,
      35,    36,   279,    75,   280,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   107,   105,   102,
     103,   104,    77,   105,    79,    72,    73,  -160,   108,    81,
      37,   301,   302,   303,    83,   306,   251,    52,    89,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   317,   105,    90,    27,    28,   387,    52,    29,    30,
      31,    32,    33,    34,    35,   112,   347,   306,   115,   429,
     118,   119,   353,   354,   355,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    55,   105,   121,
     122,   123,    56,  -185,    41,   126,   128,   127,   149,   143,
     129,   130,   144,   145,   157,   159,   162,   164,   167,   306,
     168,   169,   383,   170,    21,   171,    57,    58,    59,   174,
     105,    60,    61,   393,   180,   181,   182,   183,   187,   149,
     204,   378,    62,   218,   188,   219,   213,   210,   223,    64,
     206,   207,   321,   214,   234,   224,   306,    27,    28,   216,
     397,    29,    30,    31,    32,    33,    34,    35,   421,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   322,   323,   324,   325,   240,   326,   327,   249,   328,
     329,     9,    57,   250,   442,   252,   321,   185,   253,   258,
     259,   267,    11,   268,    12,   275,   276,   282,    62,   -12,
     281,   286,   330,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   322,   323,   324,   325,   287,
     326,   327,   289,   328,   329,     9,    57,   292,   293,   294,
     321,   295,   304,   299,   308,   345,    11,   311,    12,   312,
     315,   341,    62,   -12,   352,   342,   340,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   322,
     323,   324,   325,   356,   326,   327,   358,   328,   329,     9,
      57,   360,   363,   379,   321,   384,   381,   388,   389,   390,
      11,   391,    12,   402,   392,   405,    62,   -12,   411,   412,
     413,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   322,   323,   324,   325,   406,   326,   327,
     417,   328,   329,     9,    57,   418,   420,   423,   321,   432,
     437,   439,   325,   443,    11,   452,    12,   408,   184,   407,
      62,   -12,    19,   244,   414,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   322,   323,   324,
     325,   441,   326,   327,   232,   328,   329,     9,    57,   241,
       0,   446,   321,     0,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,    62,   -12,     0,     0,   424,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   322,   323,   324,   325,     0,   326,   327,     0,   328,
     329,     9,    57,     0,     0,     0,   321,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,    62,   -12,
       0,     0,   425,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   322,   323,   324,   325,     0,
     326,   327,     0,   328,   329,     9,    57,     0,     0,     0,
     321,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,    62,   -12,     0,     0,   434,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   322,
     323,   324,   325,     0,   326,   327,     0,   328,   329,     9,
      57,     0,     0,     0,   321,     0,     0,     0,     0,     0,
      11,     0,    12,     0,     0,     0,    62,   -12,     0,     0,
     435,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,   -12,   322,   323,   324,   325,     0,   326,   327,
       0,   328,   329,     9,    57,     0,     0,     0,   321,     0,
       0,     0,     0,     0,    11,     0,    12,     0,     0,     0,
      62,   -12,     0,     0,   436,   -12,   -12,     5,     6,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   322,   323,   324,
     325,     0,   326,   327,     0,   328,   329,     9,    57,     0,
       0,     0,   321,     0,     0,     0,     0,     0,    11,     0,
      12,     0,     0,     0,    62,   -12,     0,     0,   448,   -12,
     -12,     5,     6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,
     -12,   322,   323,   324,   325,     0,   326,   327,     0,   328,
     329,     9,    57,     0,     0,     0,   321,     0,     0,     0,
       0,     0,    11,     0,    12,     0,     0,     0,    62,   -12,
       0,     0,   449,   -12,   -12,     5,     6,   -12,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   322,   323,   324,   325,     0,
     326,   327,     0,   328,   329,     9,    57,     0,     0,     0,
     321,     0,     0,     0,     0,     0,    11,     0,    12,     0,
       0,     0,    62,   -12,     0,     0,   451,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   322,
     323,   324,   325,     0,   326,   327,     0,   328,   329,     9,
      57,     0,     0,    55,   151,     0,     0,     0,    56,     0,
      11,     0,    12,     0,     0,     0,    62,   -12,     0,     0,
     454,   -12,   -12,     5,     6,   -12,   -12,   -12,   -12,   -12,
     -12,   -12,    57,    58,    59,     0,     0,    60,    61,     0,
       0,   152,   153,     0,     0,     0,     0,   -27,    62,     0,
       0,   160,     0,     0,    11,    64,    12,     0,   -27,     0,
       0,   -12,     0,     0,   -27,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,     0,   105,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,   105,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,   105,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
     105,     0,     0,     0,   205,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   231,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -2,
       4,     0,   235,     0,    27,    28,     0,     0,    29,    30,
      31,    32,    33,    34,    35,     0,   283,   -12,   -12,     5,
       6,   -12,   -12,   -12,   -12,   -12,   -12,   -12,   -12,     0,
       0,     0,     0,     0,     0,   316,     0,     7,     8,     9,
       0,     0,     0,    10,   190,     0,     0,     0,     0,     0,
      11,     0,    12,    13,     0,     0,     0,   -12,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,   105,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,   105,    55,     0,     0,    27,
      28,    56,     0,    29,    30,    31,    32,    33,    34,    35,
       0,    27,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,     0,    55,   367,    57,    58,    59,    56,     0,
      60,    61,     0,     0,     0,     0,     0,     0,   368,   221,
       0,    62,     0,     0,     0,     0,     0,     0,    64,   271,
     207,   247,    57,    58,    59,     0,     0,    60,    61,     0,
       0,    55,     0,     0,     0,     0,    56,     0,    62,     0,
       0,     0,     0,    55,     0,    64,   290,   207,    56,    27,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      57,    58,    59,    55,     0,    60,    61,     0,    56,     0,
       0,     0,    57,    58,    59,    55,    62,    60,    61,     0,
      56,     0,    63,    64,     0,     0,     0,     0,    62,     0,
       0,     0,    57,    58,    59,    64,     0,    60,    61,     0,
       0,     0,    55,     0,    57,    58,    59,    56,    62,    60,
      61,    55,     0,     0,   193,    64,    56,     0,     0,     0,
      62,     0,     0,     0,     0,     0,   197,    64,     0,     0,
      55,    57,    58,    59,     0,    56,    60,    61,     0,     0,
      57,    58,    59,     0,     0,    60,    61,    62,     0,     0,
       0,     0,     0,   260,    64,     0,    62,     0,     0,   382,
      58,    59,     0,    64,    60,    61,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    62,   105,     0,     0,    27,
      28,     0,    64,    29,    30,    31,    32,    33,    34,    35,
      27,    28,     0,     0,    29,    30,    31,    32,    33,    34,
      35,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,   105,     0,     0,     0,     0,   377,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     396
};

static const yytype_int16 yycheck[] =
{
      43,    44,    21,     8,   188,     2,   117,   320,    62,   169,
      64,   281,    55,    56,   293,   309,   310,    20,    21,    20,
      21,    64,    20,    21,    11,    12,    13,    14,    15,   299,
     231,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    37,    17,    64,     0,   215,    48,   362,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    65,    66,    65,    66,    44,    65,    66,    41,
     113,   272,    66,   116,   242,    41,    41,    55,   279,   280,
      67,   124,   283,    61,   127,   128,   399,   130,   289,   200,
      59,   202,   252,   253,    62,    68,    61,    20,    21,    67,
     143,    66,   298,    62,   109,   110,   385,   386,    67,   403,
     404,    62,    35,   110,   157,   316,    67,    57,   314,   162,
      62,   415,   416,    64,    62,    67,   405,   406,    68,    67,
     149,    61,   426,   427,   428,   154,    66,    62,   417,   418,
      61,   420,    67,   148,    62,    66,    41,    61,   153,    67,
     444,   445,    66,   447,    20,    21,   199,    61,   201,   453,
     439,   440,    66,    61,   443,    59,    60,    61,    66,   212,
     189,   214,   356,   452,    61,    49,    50,    59,   183,    66,
      62,    11,    12,    13,    14,    15,   229,   230,    11,    12,
      13,    14,    15,    60,    17,    62,    59,    64,   217,    62,
      18,    19,    60,   246,    22,    23,    24,    25,    26,    27,
      28,    29,   255,    41,   257,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    57,    17,    13,
      14,    15,    41,    17,    41,    52,    53,    67,    68,    41,
      58,   284,   285,   286,    41,   288,    49,    50,    58,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   304,    17,    67,    18,    19,    49,    50,    22,    23,
      24,    25,    26,    27,    28,    66,   319,   320,    66,    68,
      66,    62,   325,   326,   327,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    12,    17,    66,
      62,    66,    17,    17,    58,    57,    65,    60,   313,     4,
      65,    66,    63,    41,    62,    41,    62,    41,    41,   362,
      63,    41,   365,    63,   329,    41,    41,    42,    43,    41,
      17,    46,    47,   376,    67,    64,    41,    45,    59,   344,
      62,   360,    57,    41,    48,    41,    65,    64,    41,    64,
      65,    66,     1,    60,    67,    41,   399,    18,    19,    62,
     379,    22,    23,    24,    25,    26,    27,    28,   411,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    63,    35,    36,    62,    38,
      39,    40,    41,    62,   437,    41,     1,    58,    41,    41,
      44,    60,    51,    67,    53,    63,    63,    41,    57,    58,
      64,    67,    61,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    41,
      35,    36,    60,    38,    39,    40,    41,    60,    60,    59,
       1,    59,    67,    64,    63,    60,    51,    63,    53,    63,
      67,    59,    57,    58,    41,    59,    61,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    48,    35,    36,    59,    38,    39,    40,
      41,    45,    67,    45,     1,    41,    60,    67,    67,    67,
      51,    67,    53,    37,    67,    60,    57,    58,    68,    41,
      61,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    60,    35,    36,
      60,    38,    39,    40,    41,    60,    60,    34,     1,    60,
      68,    60,    33,    60,    51,    60,    53,   397,   148,   396,
      57,    58,     2,   214,    61,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,   433,    35,    36,   195,    38,    39,    40,    41,   207,
      -1,   442,     1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    -1,    61,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,
      61,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    53,    -1,    -1,    -1,
      57,    58,    -1,    -1,    61,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    -1,    38,    39,    40,    41,    -1,
      -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    -1,    57,    58,    -1,    -1,    61,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    -1,    38,
      39,    40,    41,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    -1,    57,    58,
      -1,    -1,    61,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    -1,    38,    39,    40,    41,    -1,    -1,    -1,
       1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    -1,    57,    58,    -1,    -1,    61,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    -1,    38,    39,    40,
      41,    -1,    -1,    12,     1,    -1,    -1,    -1,    17,    -1,
      51,    -1,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,
      61,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    44,    57,    -1,
      -1,    60,    -1,    -1,    51,    64,    53,    -1,    55,    -1,
      -1,    58,    -1,    -1,    61,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    63,    -1,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    63,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,    63,    -1,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    63,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    38,    39,    40,
      -1,    -1,    -1,    44,    58,    -1,    -1,    -1,    -1,    -1,
      51,    -1,    53,    54,    -1,    -1,    -1,    58,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    17,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    12,    -1,    -1,    18,
      19,    17,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    12,    60,    41,    42,    43,    17,    -1,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    60,    58,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    64,    65,
      66,    58,    41,    42,    43,    -1,    -1,    46,    47,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    17,    -1,    57,    -1,
      -1,    -1,    -1,    12,    -1,    64,    65,    66,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      41,    42,    43,    12,    -1,    46,    47,    -1,    17,    -1,
      -1,    -1,    41,    42,    43,    12,    57,    46,    47,    -1,
      17,    -1,    63,    64,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    41,    42,    43,    64,    -1,    46,    47,    -1,
      -1,    -1,    12,    -1,    41,    42,    43,    17,    57,    46,
      47,    12,    -1,    -1,    63,    64,    17,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      12,    41,    42,    43,    -1,    17,    46,    47,    -1,    -1,
      41,    42,    43,    -1,    -1,    46,    47,    57,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    57,    -1,    -1,    41,
      42,    43,    -1,    64,    46,    47,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    57,    17,    -1,    -1,    18,
      19,    -1,    64,    22,    23,    24,    25,    26,    27,    28,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    70,    73,     0,     1,    20,    21,    38,    39,    40,
      44,    51,    53,    54,    72,    74,    76,    85,    93,    97,
      48,    72,    41,   117,    41,    94,    41,    18,    19,    22,
      23,    24,    25,    26,    27,    28,    29,    58,    71,    59,
      75,    58,    71,    62,    67,    64,    95,    60,   102,   100,
     101,    49,    50,    99,    98,    12,    17,    41,    42,    43,
      46,    47,    57,    63,    64,   126,   148,   149,   150,   151,
     148,    86,    52,    53,    77,    41,   119,    41,   103,    41,
     110,    41,   109,    41,   108,   148,   148,    62,    64,    58,
      67,    71,   148,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    17,   116,    57,    68,    89,
      79,   120,    66,    67,   105,    66,    67,   111,    66,    62,
      80,    66,    62,    66,   152,   127,    57,    60,    65,    65,
      66,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,     4,    63,    41,   155,    65,    66,    72,
      90,     1,    38,    39,    72,    78,    93,    62,   122,    41,
      60,   148,    62,   113,    41,   148,   113,    41,    63,    41,
      63,    41,   148,   129,    41,   118,   148,   148,   148,   148,
      67,    64,    41,    45,    90,    58,    71,    59,    48,    72,
      58,    71,    81,    63,   148,   121,   104,    63,   148,    67,
     106,    67,   112,    80,    62,    63,    65,    66,   130,   148,
      64,    61,    66,    65,    60,   154,    62,    72,    41,    41,
      75,    58,    71,    41,    41,    44,    55,    61,    82,    62,
      67,    63,   122,   107,    67,    63,   148,   113,   148,   113,
      63,   130,   128,   148,   118,   129,   153,    58,    71,    62,
      62,    49,    41,    41,    59,    62,    59,    62,    41,    44,
      63,   148,   148,   116,    41,    61,    66,    60,    67,   129,
      61,    65,   148,    88,    87,    63,    63,    80,    80,   148,
     148,    64,    41,    63,    62,    67,    67,    41,   114,    60,
      65,   116,    60,    60,    59,    59,   116,   116,    86,    64,
     116,   148,   148,   148,    67,   125,   148,   116,    63,    91,
      91,    63,    63,    89,    86,    67,    63,   148,    61,    66,
     115,     1,    30,    31,    32,    33,    35,    36,    38,    39,
      61,    92,    93,    96,    97,   131,   134,   138,   140,   151,
      61,    59,    59,    65,    89,    60,   116,   148,   125,    59,
      60,    61,    41,   148,   148,   148,    48,    35,    59,   132,
      45,    65,   124,    67,    61,    37,    66,    60,    60,    75,
      11,    12,    13,    14,    15,    67,   133,    58,    71,    45,
     125,    60,    41,   148,    41,   136,   139,    49,    67,    67,
      67,    67,    67,   148,    84,    83,    58,    71,    61,   123,
     146,    68,    37,    91,    91,    60,    60,    84,    83,   125,
     143,    68,    41,    61,    61,    91,    91,    60,    60,    61,
      60,   148,   147,    34,    61,    61,    91,    91,    91,    68,
     145,   144,    60,   135,    61,    61,    61,    68,   141,    60,
     137,   134,   148,    60,    91,    91,   145,    91,    61,    61,
     142,    61,    60,    91,    61
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
     104,   103,   105,   103,   103,   103,   106,   103,   107,   107,
     107,   108,   108,   108,   108,   109,   109,   110,   110,   111,
     110,   110,   110,   112,   110,   113,   113,   114,   113,   115,
     113,   116,   117,   117,   118,   118,   120,   119,   121,   119,
     122,   122,   122,   123,   122,   124,   122,   122,   122,   125,
     125,   127,   126,   128,   126,   129,   129,   129,   130,   131,
     132,   133,   133,   133,   133,   133,   133,   134,   134,   135,
     134,   136,   137,   139,   138,   141,   140,   142,   140,   143,
     140,   144,   140,   145,   146,   147,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   149,   149,   149,   149,   149,   149,
     150,   151,   151,   152,   151,   151,   153,   151,   154,   151,
     155
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
       0,     6,     0,     3,     3,     5,     0,     5,     0,     4,
       5,     1,     3,     3,     5,     2,     4,     1,     3,     0,
       3,     3,     5,     0,     5,     3,     2,     0,     7,     0,
       9,     0,     7,     9,     1,     3,     0,     3,     0,     5,
       4,     6,     4,     0,    13,     0,    11,     8,     4,     1,
       3,     0,     5,     0,     8,     0,     2,     3,     1,     4,
       0,     1,     2,     2,     2,     2,     2,     6,    11,     0,
       9,     0,     0,     0,     6,     0,    12,     0,    15,     0,
       9,     0,    11,     0,     0,     0,     3,     3,     3,     3,
       3,     4,     3,     2,     3,     3,     3,     3,     3,     4,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     0,     5,     4,     0,     9,     0,     7,
       0
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
#line 1927 "parser.tab.c"
    break;

  case 16:
#line 124 "parser.y"
                        {yyerror("unknown token %s\n",yytext);}
#line 1933 "parser.tab.c"
    break;

  case 18:
#line 128 "parser.y"
                                {printcode("%s",(yyvsp[0].s));}
#line 1939 "parser.tab.c"
    break;

  case 19:
#line 129 "parser.y"
                         {expr_type =VOID_TYPE;}
#line 1945 "parser.tab.c"
    break;

  case 20:
#line 130 "parser.y"
                     {yyerror("missing ;");expr_type =VOID_TYPE;}
#line 1951 "parser.tab.c"
    break;

  case 21:
#line 131 "parser.y"
                    {expr_type =VOID_TYPE;}
#line 1957 "parser.tab.c"
    break;

  case 23:
#line 133 "parser.y"
               {expr_type =VOID_TYPE;}
#line 1963 "parser.tab.c"
    break;

  case 25:
#line 136 "parser.y"
                        {printcode("%s",(yyvsp[0].s)); free((yyvsp[0].s));}
#line 1969 "parser.tab.c"
    break;

  case 26:
#line 140 "parser.y"
                                {current_class = add_class((yyvsp[-1].s),yylineno);start_class_definition((yyvsp[-1].s));}
#line 1975 "parser.tab.c"
    break;

  case 27:
#line 140 "parser.y"
                                                                                                              {end_attr_list((yyvsp[-3].s));}
#line 1981 "parser.tab.c"
    break;

  case 28:
#line 140 "parser.y"
                                                                                                                                                    {end_class_definition();printcode("#include \"class_%s.h\"",(yyvsp[-6].s));free((yyvsp[-6].s));current_class = NULL;}
#line 1987 "parser.tab.c"
    break;

  case 31:
#line 144 "parser.y"
                                            {if((yyvsp[-3].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-3].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-3].m),(yyvsp[-2].t),(yyvsp[-1].s),false,yylineno);
                                                printcode("%s %s %s;",mod_arr[(yyvsp[-3].m)],type_arr[(yyvsp[-2].t)],(yyvsp[-1].s));free((yyvsp[-1].s));}
#line 1996 "parser.tab.c"
    break;

  case 32:
#line 148 "parser.y"
                                                                        {if((yyvsp[-7].m) == STATIC_TYPE){
                                                                    yyerror("Cannot use static on class attributes");(yyvsp[-7].m) = NONE_TYPE;
                                                                    }add_attr(current_class,(yyvsp[-7].m),(yyvsp[-6].t),(yyvsp[-5].s),true,yylineno);printcode("%s %s %s[%s];",mod_arr[(yyvsp[-7].m)],type_arr[(yyvsp[-6].t)],(yyvsp[-5].s),(yyvsp[-3].s));free((yyvsp[-5].s));free((yyvsp[-3].s));}
#line 2004 "parser.tab.c"
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
#line 2017 "parser.tab.c"
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
#line 2030 "parser.tab.c"
    break;

  case 35:
#line 167 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2036 "parser.tab.c"
    break;

  case 36:
#line 168 "parser.y"
                                                            {if((yyvsp[-4].m) == STATIC_TYPE){
                                                yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                }add_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-2].s));}
#line 2044 "parser.tab.c"
    break;

  case 37:
#line 171 "parser.y"
                                                                 {if((yyvsp[-4].m) == STATIC_TYPE){
                                                            yyerror("Cannot use static on class attributes");(yyvsp[-4].m) = NONE_TYPE;
                                                            }add_class_type_attr(current_class,(yyvsp[-4].m),(yyvsp[-3].s),(yyvsp[-2].s),(yyvsp[-1].b),yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2052 "parser.tab.c"
    break;

  case 39:
#line 176 "parser.y"
                        {(yyval.b)= false;}
#line 2058 "parser.tab.c"
    break;

  case 40:
#line 177 "parser.y"
                {(yyval.b) = true;}
#line 2064 "parser.tab.c"
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
#line 2078 "parser.tab.c"
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
#line 2092 "parser.tab.c"
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
#line 2104 "parser.tab.c"
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
#line 2116 "parser.tab.c"
    break;

  case 46:
#line 215 "parser.y"
                           {is_static_method = true;}
#line 2122 "parser.tab.c"
    break;

  case 47:
#line 219 "parser.y"
                          {add_method(current_class, (yyvsp[(-6) - (0)].s), (yyvsp[0].t), is_static_method,temp_list, yylineno);
                            print_method(current_class,(yyvsp[(-6) - (0)].s));
                            temp_list = NULL;
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2133 "parser.tab.c"
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
#line 2145 "parser.tab.c"
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
#line 2159 "parser.tab.c"
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
#line 2173 "parser.tab.c"
    break;

  case 51:
#line 253 "parser.y"
                                {pushscope();}
#line 2179 "parser.tab.c"
    break;

  case 52:
#line 254 "parser.y"
                            {print_fn_delc((yyvsp[(-7) - (0)].s));
                            fn_type = (yyvsp[0].t);
                            is_in_fn = true;
                            has_returned = false;}
#line 2188 "parser.tab.c"
    break;

  case 53:
#line 259 "parser.y"
                                {print_fn_delc((yyvsp[(-7) - (0)].s));
                                fn_type = CLASS_TYPE;
                                fn_ret_class =(yyvsp[0].s);
                                is_in_fn = true;
                                has_returned = false;}
#line 2198 "parser.tab.c"
    break;

  case 57:
#line 269 "parser.y"
                                    {add_param((yyvsp[-2].m),(yyvsp[-1].t),false,(yyvsp[0].s));add_var((yyvsp[-2].m),(yyvsp[-1].t),(yyvsp[0].s),yylineno); free((yyvsp[0].s));}
#line 2204 "parser.tab.c"
    break;

  case 58:
#line 270 "parser.y"
                                       {add_param((yyvsp[-4].m),(yyvsp[-3].t),true,(yyvsp[-2].s));add_array((yyvsp[-4].m),(yyvsp[-3].t),(yyvsp[-2].s),yylineno); free((yyvsp[-2].s));}
#line 2210 "parser.tab.c"
    break;

  case 59:
#line 271 "parser.y"
                                        {add_class_param((yyvsp[-2].m), (yyvsp[-1].s), false,(yyvsp[0].s));create_class_var((yyvsp[-2].m), (yyvsp[-1].s), (yyvsp[0].s), false,yylineno);free((yyvsp[-1].s));free((yyvsp[0].s));}
#line 2216 "parser.tab.c"
    break;

  case 60:
#line 272 "parser.y"
                                            {add_class_param((yyvsp[-4].m), (yyvsp[-3].s), true,(yyvsp[-2].s));create_class_var((yyvsp[-4].m), (yyvsp[-3].s), (yyvsp[-2].s), true,yylineno);free((yyvsp[-3].s));free((yyvsp[-2].s));}
#line 2222 "parser.tab.c"
    break;

  case 62:
#line 275 "parser.y"
                                     {printcode("%s",(yyvsp[0].s));}
#line 2228 "parser.tab.c"
    break;

  case 63:
#line 276 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2234 "parser.tab.c"
    break;

  case 64:
#line 277 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2240 "parser.tab.c"
    break;

  case 65:
#line 278 "parser.y"
                         {yyerror("error on token %s",yytext);expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2246 "parser.tab.c"
    break;

  case 66:
#line 279 "parser.y"
                        {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2252 "parser.tab.c"
    break;

  case 67:
#line 280 "parser.y"
                    {yyerror("missing ;");expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2258 "parser.tab.c"
    break;

  case 69:
#line 282 "parser.y"
                      {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2264 "parser.tab.c"
    break;

  case 70:
#line 283 "parser.y"
                         {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2270 "parser.tab.c"
    break;

  case 71:
#line 284 "parser.y"
                       {expr_type=temp_type= VOID_TYPE;expr_class=temp_class= NULL;}
#line 2276 "parser.tab.c"
    break;

  case 73:
#line 288 "parser.y"
              {printcode("%s",(yyvsp[0].s));if(strcmp((yyvsp[0].s),"")!=0)printcode(";");free((yyvsp[0].s));}
#line 2282 "parser.tab.c"
    break;

  case 76:
#line 291 "parser.y"
            {printcode("break;");}
#line 2288 "parser.tab.c"
    break;

  case 77:
#line 292 "parser.y"
                {printcode("continue;");}
#line 2294 "parser.tab.c"
    break;

  case 78:
#line 295 "parser.y"
                       {printcode("/*");}
#line 2300 "parser.tab.c"
    break;

  case 79:
#line 295 "parser.y"
                                                                 {printcode("*/");}
#line 2306 "parser.tab.c"
    break;

  case 80:
#line 296 "parser.y"
                    {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2312 "parser.tab.c"
    break;

  case 82:
#line 299 "parser.y"
                              {printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2318 "parser.tab.c"
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
#line 2332 "parser.tab.c"
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
#line 2344 "parser.tab.c"
    break;

  case 85:
#line 317 "parser.y"
                          {has_returned = true;}
#line 2350 "parser.tab.c"
    break;

  case 86:
#line 320 "parser.y"
                                    {temp_type = (yyvsp[0].t);}
#line 2356 "parser.tab.c"
    break;

  case 87:
#line 320 "parser.y"
                                                               {temp_type = VOID_TYPE;}
#line 2362 "parser.tab.c"
    break;

  case 88:
#line 321 "parser.y"
                              {temp_type = CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2368 "parser.tab.c"
    break;

  case 89:
#line 321 "parser.y"
                                                                                    {temp_type = VOID_TYPE;temp_class=NULL;free((yyvsp[-2].s));}
#line 2374 "parser.tab.c"
    break;

  case 90:
#line 322 "parser.y"
                         {printcode("%s %s ",mod_arr[(yyvsp[-1].m)],(yyvsp[0].s));arr_type=temp_type=CLASS_TYPE;temp_class=(yyvsp[0].s);}
#line 2380 "parser.tab.c"
    break;

  case 91:
#line 322 "parser.y"
                                                                                                                        {printcode(" ;");free((yyvsp[-2].s));arr_type=temp_type=VOID_TYPE;temp_class= NULL;}
#line 2386 "parser.tab.c"
    break;

  case 92:
#line 323 "parser.y"
                    { printcode("%s %s ",mod_arr[(yyvsp[-1].m)],type_arr[(yyvsp[0].t)]); arr_type = (yyvsp[0].t);}
#line 2392 "parser.tab.c"
    break;

  case 93:
#line 323 "parser.y"
                                                                                            {printcode(" ;");arr_type=VOID_TYPE;}
#line 2398 "parser.tab.c"
    break;

  case 94:
#line 324 "parser.y"
                       {printcode("%s char ",mod_arr[(yyvsp[-1].m)]); char_buf_mod = (yyvsp[-1].m);}
#line 2404 "parser.tab.c"
    break;

  case 95:
#line 324 "parser.y"
                                                                                               {printcode(" ;");char_buf_mod = NONE_TYPE;}
#line 2410 "parser.tab.c"
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
#line 2426 "parser.tab.c"
    break;

  case 98:
#line 339 "parser.y"
                                {create_class_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].s),(yyvsp[0].s),false,yylineno);printcode("%s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2432 "parser.tab.c"
    break;

  case 99:
#line 340 "parser.y"
                          {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" %s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),false,yylineno);
                            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2444 "parser.tab.c"
    break;

  case 100:
#line 347 "parser.y"
                          {printcode("%s = { ",(yyvsp[-2].s));}
#line 2450 "parser.tab.c"
    break;

  case 101:
#line 347 "parser.y"
                                                                    {printcode(" }");create_class_var((yyvsp[(-2) - (6)].m),(yyvsp[(-1) - (6)].s),(yyvsp[-5].s),false,yylineno);free((yyvsp[-5].s));}
#line 2456 "parser.tab.c"
    break;

  case 102:
#line 348 "parser.y"
                 {/*nothing dummymust be kept to maintain arraydecl*/}
#line 2462 "parser.tab.c"
    break;

  case 103:
#line 348 "parser.y"
                                                                                 {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2468 "parser.tab.c"
    break;

  case 104:
#line 349 "parser.y"
                                      {create_class_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].s),(yyvsp[0].s),false,yylineno);printcode(", %s",(yyvsp[0].s));free((yyvsp[0].s));}
#line 2474 "parser.tab.c"
    break;

  case 105:
#line 350 "parser.y"
                                           {if(expr_type != CLASS_TYPE){yyerror("cannot assign %s to class type variable",type_arr[expr_type]);}
                            if(expr_class == NULL || strcmp(expr_class,temp_class) !=0){
                                yyerror("cannot assign class %s to variable of class %s",expr_class,temp_class);   
                            }else{
                                printcode(" ,%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                            }create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),false,yylineno);
                            free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2486 "parser.tab.c"
    break;

  case 106:
#line 357 "parser.y"
                                  {printcode(", ");}
#line 2492 "parser.tab.c"
    break;

  case 107:
#line 357 "parser.y"
                                                               {create_class_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].s),(yyvsp[-2].s),true,yylineno);free((yyvsp[-2].s));}
#line 2498 "parser.tab.c"
    break;

  case 109:
#line 362 "parser.y"
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
#line 2519 "parser.tab.c"
    break;

  case 110:
#line 378 "parser.y"
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
#line 2540 "parser.tab.c"
    break;

  case 111:
#line 395 "parser.y"
                     {add_var((yyvsp[(-1) - (1)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2546 "parser.tab.c"
    break;

  case 112:
#line 396 "parser.y"
                         {add_array((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2552 "parser.tab.c"
    break;

  case 113:
#line 397 "parser.y"
                              {add_var((yyvsp[(-1) - (3)].m),temp_type,(yyvsp[0].s),yylineno); free((yyvsp[0].s)); }
#line 2558 "parser.tab.c"
    break;

  case 114:
#line 398 "parser.y"
                                      {add_array((yyvsp[(-1) - (5)].m),temp_type,(yyvsp[-2].s),yylineno);free((yyvsp[-2].s));}
#line 2564 "parser.tab.c"
    break;

  case 115:
#line 401 "parser.y"
                                     {create_class_var((yyvsp[(-2) - (2)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2570 "parser.tab.c"
    break;

  case 116:
#line 402 "parser.y"
                                            {create_class_var((yyvsp[(-2) - (4)].m),temp_class,(yyvsp[-1].s),(yyvsp[0].b),yylineno);free((yyvsp[-1].s));}
#line 2576 "parser.tab.c"
    break;

  case 117:
#line 405 "parser.y"
                     {add_var((yyvsp[(-2) - (1)].m),(yyvsp[(-1) - (1)].t),(yyvsp[0].s),yylineno); 
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s)); }
#line 2584 "parser.tab.c"
    break;

  case 118:
#line 408 "parser.y"
                          { if(verify_types((yyvsp[(-1) - (3)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (3)].t)]);
                                add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[-2].s),yylineno);
                                printcode("%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2593 "parser.tab.c"
    break;

  case 119:
#line 412 "parser.y"
                {/*nothing dummy*/}
#line 2599 "parser.tab.c"
    break;

  case 120:
#line 412 "parser.y"
                                              {add_array((yyvsp[(-2) - (3)].m),  (yyvsp[(-1) - (3)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2605 "parser.tab.c"
    break;

  case 121:
#line 413 "parser.y"
                             {add_var((yyvsp[(-2) - (3)].m),(yyvsp[(-1) - (3)].t),(yyvsp[0].s),yylineno); 
                                printcode(",%s ",(yyvsp[0].s));
                                free((yyvsp[0].s));}
#line 2613 "parser.tab.c"
    break;

  case 122:
#line 416 "parser.y"
                                      {
                                        if(verify_types((yyvsp[(-1) - (5)].t),expr_type))yyerror("Invalid assignment : %s cannot be assigned to var type %s",type_arr[expr_type], type_arr[(yyvsp[(-1) - (5)].t)]);
                                        add_var((yyvsp[(-2) - (5)].m),(yyvsp[(-1) - (5)].t),(yyvsp[-2].s),yylineno);
                                        printcode(",%s = %s",(yyvsp[-2].s),(yyvsp[0].s));
                                        free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2623 "parser.tab.c"
    break;

  case 123:
#line 421 "parser.y"
                             {printcode(", ");}
#line 2629 "parser.tab.c"
    break;

  case 124:
#line 421 "parser.y"
                                                          {add_array((yyvsp[(-2) - (5)].m),  (yyvsp[(-1) - (5)].t), (yyvsp[-2].s), yylineno);free((yyvsp[-2].s));}
#line 2635 "parser.tab.c"
    break;

  case 125:
#line 424 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);
                                            }else{
                                                printcode("%s[%s]",(yyvsp[(-1) - (3)].s),(yyvsp[-1].s));
                                            }
                                            free((yyvsp[-1].s));
                                            }
#line 2646 "parser.tab.c"
    break;

  case 126:
#line 430 "parser.y"
                      {yyerror("Array size missing");}
#line 2652 "parser.tab.c"
    break;

  case 127:
#line 431 "parser.y"
                       {printcode("%s[] = { ",(yyvsp[(-1) - (4)].s));}
#line 2658 "parser.tab.c"
    break;

  case 128:
#line 431 "parser.y"
                                                                         {printcode(" }");}
#line 2664 "parser.tab.c"
    break;

  case 129:
#line 432 "parser.y"
                                          {printcode("%s[%s] = { ",(yyvsp[(-1) - (6)].s),(yyvsp[-4].s));free((yyvsp[-4].s));}
#line 2670 "parser.tab.c"
    break;

  case 130:
#line 432 "parser.y"
                                                                                                          {printcode(" }");}
#line 2676 "parser.tab.c"
    break;

  case 131:
#line 436 "parser.y"
                             {if(expr_type != INT_TYPE){yyerror("Array size must be an int type got %s.",type_arr[expr_type]);}expr_type = VOID_TYPE;}
#line 2682 "parser.tab.c"
    break;

  case 132:
#line 438 "parser.y"
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
#line 2698 "parser.tab.c"
    break;

  case 133:
#line 449 "parser.y"
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
#line 2713 "parser.tab.c"
    break;

  case 134:
#line 460 "parser.y"
                            {arr_type = expr_type;if(arr_type == STRING_TYPE){expr_type = VOID_TYPE;}if(expr_type == CLASS_TYPE){expr_type = VOID_TYPE;temp_class=expr_class;}}
#line 2719 "parser.tab.c"
    break;

  case 135:
#line 461 "parser.y"
                            {if(verify_types(expr_type,arr_type)){
                                yyerror("Invalid assignment : %s type cannot be stored in same array as %s",type_arr[expr_type],type_arr[arr_type]);
                            }else if(expr_type == CLASS_TYPE && strcmp(expr_class,temp_class)!=0){
                                yyerror("Cannot combine classes of %s and %s in same array",expr_class,temp_class);
                            }else{
                                arr_type = expr_type;
                            }
                            if(arr_type == STRING_TYPE || expr_type == CLASS_TYPE)expr_type = VOID_TYPE;
                            (yyval.s)=join((yyvsp[-2].s),",",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));}
#line 2733 "parser.tab.c"
    break;

  case 136:
#line 472 "parser.y"
                            {printcode("%s",(yyvsp[0].s));}
#line 2739 "parser.tab.c"
    break;

  case 137:
#line 472 "parser.y"
                                                         {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2745 "parser.tab.c"
    break;

  case 138:
#line 473 "parser.y"
                                     {printcode(" ,%s",(yyvsp[0].s));}
#line 2751 "parser.tab.c"
    break;

  case 139:
#line 473 "parser.y"
                                                                     {free((yyvsp[-2].s));expr_type = VOID_TYPE;}
#line 2757 "parser.tab.c"
    break;

  case 140:
#line 476 "parser.y"
                                      {printcode("[%s]",(yyvsp[-2].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);free((yyvsp[-2].s));}
#line 2763 "parser.tab.c"
    break;

  case 141:
#line 477 "parser.y"
                                           {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                                    }else{printcode("[%s] = %s",(yyvsp[-4].s),(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (6)].s),yylineno);}free((yyvsp[-4].s));free((yyvsp[0].s));}
#line 2770 "parser.tab.c"
    break;

  case 142:
#line 479 "parser.y"
                       {if(expr_type != STRING_TYPE){yyerror("cannot assign any type other than string to charbuf, got %s.",type_arr[expr_type]);
                        }else{printcode("[] = %s",(yyvsp[0].s));add_var(char_buf_mod,STRING_TYPE,(yyvsp[(-1) - (4)].s),yylineno);}free((yyvsp[0].s));}
#line 2777 "parser.tab.c"
    break;

  case 143:
#line 481 "parser.y"
                                                                    {printcode("[%s][%s] = {",(yyvsp[-8].s),(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2783 "parser.tab.c"
    break;

  case 144:
#line 481 "parser.y"
                                                                                                                                               {printcode("}");arr_type = VOID_TYPE;
                                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (13)].s), yylineno);
                                                                                                                free((yyvsp[-11].s));free((yyvsp[-7].s));}
#line 2791 "parser.tab.c"
    break;

  case 145:
#line 484 "parser.y"
                                                  {printcode("[][%s] = { ",(yyvsp[-4].s));arr_type = STRING_TYPE;}
#line 2797 "parser.tab.c"
    break;

  case 146:
#line 484 "parser.y"
                                                                                                                         {printcode("}");arr_type = VOID_TYPE;
                                                                                                add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (11)].s), yylineno);
                                                                                                free((yyvsp[-7].s));}
#line 2805 "parser.tab.c"
    break;

  case 147:
#line 487 "parser.y"
                                                            {printcode("[%s][%s]",(yyvsp[-6].s),(yyvsp[-2].s));add_array(char_buf_mod,  STRING_TYPE, (yyvsp[(-1) - (8)].s), yylineno);}
#line 2811 "parser.tab.c"
    break;

  case 148:
#line 489 "parser.y"
                      {yyerror("Both sizes cannot be empty in a charbuf array");}
#line 2817 "parser.tab.c"
    break;

  case 149:
#line 493 "parser.y"
                    { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}

                        expr_type = VOID_TYPE;
                        printcode("%s ",(yyvsp[0].s));
                        free((yyvsp[0].s));
                        }
#line 2828 "parser.tab.c"
    break;

  case 150:
#line 499 "parser.y"
                            { if(verify_types(arr_type,expr_type)){yyerror("Invalid assignment : %s type cannot be stored in array of type %s",type_arr[expr_type],type_arr[arr_type]);}
                        expr_type = VOID_TYPE;
                        printcode(", %s",(yyvsp[0].s));
                        free((yyvsp[0].s));}
#line 2837 "parser.tab.c"
    break;

  case 151:
#line 504 "parser.y"
                        {push_expr_and_args();if(find_action((yyvsp[-1].s))==0)is_in_fncall=true;}
#line 2843 "parser.tab.c"
    break;

  case 152:
#line 504 "parser.y"
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
#line 2891 "parser.tab.c"
    break;

  case 153:
#line 547 "parser.y"
                                         {push_expr_and_args();is_in_fncall=true;}
#line 2897 "parser.tab.c"
    break;

  case 154:
#line 547 "parser.y"
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
#line 2940 "parser.tab.c"
    break;

  case 158:
#line 592 "parser.y"
            { void *v = lookup_var((yyvsp[0].s));
                if(v == NULL){
                    v = add_literal(NONE_TYPE,expr_type,(yyvsp[0].s));
                }
                if(is_composite_val){((Variable *)v)->is_raw = false;}
                ll_add(arglist,v);free((yyvsp[0].s));expr_type = VOID_TYPE;is_composite_val = false;}
#line 2951 "parser.tab.c"
    break;

  case 159:
#line 600 "parser.y"
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
#line 2978 "parser.tab.c"
    break;

  case 160:
#line 625 "parser.y"
                          {temp_type=expr_type;temp_class=expr_class;
                            expr_type=VOID_TYPE;expr_class=NULL;
                            if(!is_assignable){yyerror("cannot assign to given variable");}
                            }
#line 2987 "parser.tab.c"
    break;

  case 161:
#line 631 "parser.y"
                {(yyval.s) = "=";}
#line 2993 "parser.tab.c"
    break;

  case 162:
#line 632 "parser.y"
              {(yyval.s) = "+=";}
#line 2999 "parser.tab.c"
    break;

  case 163:
#line 633 "parser.y"
              {(yyval.s) = "-=";}
#line 3005 "parser.tab.c"
    break;

  case 164:
#line 634 "parser.y"
              {(yyval.s) = "*=";}
#line 3011 "parser.tab.c"
    break;

  case 165:
#line 635 "parser.y"
              {(yyval.s) = "/=";}
#line 3017 "parser.tab.c"
    break;

  case 166:
#line 636 "parser.y"
              {(yyval.s) = "%=";}
#line 3023 "parser.tab.c"
    break;

  case 167:
#line 639 "parser.y"
                                         {popscope();printcode("}\n");}
#line 3029 "parser.tab.c"
    break;

  case 168:
#line 640 "parser.y"
                                                                       {printcode("}\n");popscope();}
#line 3035 "parser.tab.c"
    break;

  case 169:
#line 641 "parser.y"
                                            {popscope();printcode("}else ");}
#line 3041 "parser.tab.c"
    break;

  case 171:
#line 644 "parser.y"
                        {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}pushscope();printcode("if(%s){",(yyvsp[(-1) - (0)].s));free((yyvsp[(-1) - (0)].s));}
#line 3047 "parser.tab.c"
    break;

  case 172:
#line 648 "parser.y"
                            {popscope();pushscope();printcode("}else{");}
#line 3053 "parser.tab.c"
    break;

  case 173:
#line 652 "parser.y"
                           {if(expr_type !=BOOL_TYPE){yyerror("Condition must be of bool type");}++is_in_loop;printcode("while (%s) {",(yyvsp[-1].s));pushscope();free((yyvsp[-1].s));}
#line 3059 "parser.tab.c"
    break;

  case 174:
#line 652 "parser.y"
                                                                                                                                                                               {printcode(" }");popscope();expr_type=VOID_TYPE;--is_in_loop;}
#line 3065 "parser.tab.c"
    break;

  case 175:
#line 655 "parser.y"
                                                              {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-6].s),yylineno);print_simple_range_loop((yyvsp[-6].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-6].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3071 "parser.tab.c"
    break;

  case 176:
#line 655 "parser.y"
                                                                                                                                                                                                                          {printcode("}");popscope();--is_in_loop;}
#line 3077 "parser.tab.c"
    break;

  case 177:
#line 656 "parser.y"
                                                                       {++is_in_loop;pushscope();add_var(NONE_TYPE,expr_type,(yyvsp[-9].s),yylineno);print_step_range_loop((yyvsp[-9].s),(yyvsp[-7].s),(yyvsp[-4].s),(yyvsp[-1].s),expr_type);free((yyvsp[-9].s));free((yyvsp[-7].s));free((yyvsp[-4].s));free((yyvsp[-1].s));}
#line 3083 "parser.tab.c"
    break;

  case 178:
#line 656 "parser.y"
                                                                                                                                                                                                                                                {printcode("}");popscope();--is_in_loop;}
#line 3089 "parser.tab.c"
    break;

  case 179:
#line 657 "parser.y"
                                                    {++is_in_loop;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3095 "parser.tab.c"
    break;

  case 180:
#line 657 "parser.y"
                                                                                                       {printcode("}");popscope();--is_in_loop;}
#line 3101 "parser.tab.c"
    break;

  case 181:
#line 658 "parser.y"
                                                                 {++is_in_loop;free((yyvsp[-5].s));free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3107 "parser.tab.c"
    break;

  case 182:
#line 658 "parser.y"
                                                                                                                             {printcode("}");popscope();--is_in_loop;}
#line 3113 "parser.tab.c"
    break;

  case 183:
#line 661 "parser.y"
                              {if(expr_type != INT_TYPE && expr_type != FLOAT_TYPE){yyerror("The range bounds and step must be of type int or float , got %s",type_arr[expr_type]);}}
#line 3119 "parser.tab.c"
    break;

  case 184:
#line 665 "parser.y"
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
#line 3143 "parser.tab.c"
    break;

  case 185:
#line 687 "parser.y"
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
#line 3167 "parser.tab.c"
    break;

  case 186:
#line 708 "parser.y"
                      { (yyval.s)=join((yyvsp[-2].s),"+",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            is_composite_val =false;}
#line 3175 "parser.tab.c"
    break;

  case 187:
#line 711 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"-",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3183 "parser.tab.c"
    break;

  case 188:
#line 714 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"*",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); 
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3191 "parser.tab.c"
    break;

  case 189:
#line 717 "parser.y"
                      {(yyval.s)=join((yyvsp[-2].s),"/",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s));
                                            if(expr_type == CLASS_TYPE){yyerror("cannot use + operation on classes");}
                                            }
#line 3199 "parser.tab.c"
    break;

  case 190:
#line 720 "parser.y"
                      {if(expr_type == COMPLEX_TYPE || expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use mod on %s type",type_arr[expr_type]);} 
                                            (yyval.s)=join((yyvsp[-2].s),"%",(yyvsp[0].s)); free((yyvsp[-2].s));free((yyvsp[0].s)); is_composite_val =false;}
#line 3206 "parser.tab.c"
    break;

  case 191:
#line 722 "parser.y"
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
#line 3223 "parser.tab.c"
    break;

  case 192:
#line 734 "parser.y"
                     {(yyval.s)=join("( ",(yyvsp[-1].s)," )"); free((yyvsp[-1].s)); is_composite_val =false;}
#line 3229 "parser.tab.c"
    break;

  case 193:
#line 735 "parser.y"
                             {(yyval.s)=join("-","",(yyvsp[0].s));if(expr_type == CLASS_TYPE){yyerror("Cannot use negetive on class type");}}
#line 3235 "parser.tab.c"
    break;

  case 194:
#line 736 "parser.y"
                       {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use < with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),"<",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3242 "parser.tab.c"
    break;

  case 195:
#line 738 "parser.y"
                       {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use > with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),">",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3249 "parser.tab.c"
    break;

  case 196:
#line 740 "parser.y"
                            {if(expr_type == COMPLEX_TYPE || expr_type == CLASS_TYPE){yyerror("Cannot use <= with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),"<=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3256 "parser.tab.c"
    break;

  case 197:
#line 742 "parser.y"
                             {if(expr_type == COMPLEX_TYPE|| expr_type == CLASS_TYPE){yyerror("Cannot use >= with %s type",type_arr[expr_type]);} 
                                            (yyval.s)= join((yyvsp[-2].s),">=",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3263 "parser.tab.c"
    break;

  case 198:
#line 744 "parser.y"
                                        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                            (yyval.s)= join((yyvsp[-2].s),"==",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3270 "parser.tab.c"
    break;

  case 199:
#line 746 "parser.y"
                                        {if(expr_type == CLASS_TYPE){yyerror("cannot compare classes directly");}
                                        (yyval.s)= join((yyvsp[-3].s),"!=",(yyvsp[0].s));free((yyvsp[-3].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3277 "parser.tab.c"
    break;

  case 200:
#line 748 "parser.y"
                     {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                            (yyval.s)= join((yyvsp[-2].s)," && ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3284 "parser.tab.c"
    break;

  case 201:
#line 750 "parser.y"
                      {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");} 
                        (yyval.s)= join((yyvsp[-2].s)," || ",(yyvsp[0].s));free((yyvsp[-2].s));free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3291 "parser.tab.c"
    break;

  case 202:
#line 752 "parser.y"
                 {if(expr_type == CLASS_TYPE){yyerror("cannot use logical operators on classes directly");}
                    char * t =join("(",(yyvsp[0].s),")");(yyval.s) = join("!",t,"");free(t);free((yyvsp[0].s));expr_type = BOOL_TYPE;}
#line 3298 "parser.tab.c"
    break;

  case 204:
#line 757 "parser.y"
                 {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);
                }else{
                    expr_type = COMPLEX_TYPE;
                }}
#line 3308 "parser.tab.c"
    break;

  case 205:
#line 762 "parser.y"
             {if( expr_type == STRING_TYPE || expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[INT_TYPE],type_arr[expr_type]);;
                }else if(!(expr_type == FLOAT_TYPE || expr_type == DOUBLE_TYPE || expr_type == COMPLEX_TYPE)){
                    expr_type = INT_TYPE;
                }}
#line 3318 "parser.tab.c"
    break;

  case 206:
#line 767 "parser.y"
               { if( expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[FLOAT_TYPE],type_arr[expr_type]);;
                }else if(expr_type != COMPLEX_TYPE){
                    expr_type = FLOAT_TYPE;
                }}
#line 3329 "parser.tab.c"
    break;

  case 207:
#line 773 "parser.y"
                {if(expr_type == VOID_TYPE){
                    expr_type = BOOL_TYPE;
                }else if(expr_type == STRING_TYPE|| expr_type == CLASS_TYPE){
                    yyerror("Invalid operand types : %s and %s cannot be combined.",type_arr[expr_type],type_arr[BOOL_TYPE]);
                }}
#line 3339 "parser.tab.c"
    break;

  case 208:
#line 778 "parser.y"
                {if(expr_type != VOID_TYPE){yyerror("Cannot combine string type with any type.");}expr_type = STRING_TYPE;}
#line 3345 "parser.tab.c"
    break;

  case 210:
#line 782 "parser.y"
                                 {void* _t = calloc(1, strlen((yyvsp[-3].s)) + strlen((yyvsp[-1].s)) + 1+2+2);/*1 for the + symbol,
                                                                                        2 for the perenthesis around the img part
                                                                                        2 for the parenthesis around the whole*/
                                        strcat(_t,"(");strcat(_t, (yyvsp[-3].s));strcat(_t,"+");
                                        strcat(_t,"(");strcat(_t, (yyvsp[-1].s));strcat(_t,")");
                                        strcat(_t, "*I");strcat(_t,")");
                                            (yyval.s) = (char*)_t;free((yyvsp[-3].s));free((yyvsp[-1].s));}
#line 3357 "parser.tab.c"
    break;

  case 212:
#line 792 "parser.y"
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
#line 3385 "parser.tab.c"
    break;

  case 213:
#line 815 "parser.y"
                     {push_expr_and_args();}
#line 3391 "parser.tab.c"
    break;

  case 214:
#line 815 "parser.y"
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
#line 3424 "parser.tab.c"
    break;

  case 215:
#line 843 "parser.y"
                                             { attr* a = NULL;
                                        if(expr_type == CLASS_TYPE)a = find_attr(expr_class,(yyvsp[0].s));
                                        if(a== NULL){
                                            yyerror("No attribute %s declared on class %s",(yyvsp[0].s),expr_class);
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
#line 3450 "parser.tab.c"
    break;

  case 216:
#line 864 "parser.y"
                                                 {push_expr_and_args();}
#line 3456 "parser.tab.c"
    break;

  case 217:
#line 864 "parser.y"
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
                                                                                                    expr_type = a->t.t;}}
                                                                                            char * t = join((yyvsp[-8].s),".",(yyvsp[-5].s));
                                                                                            char *tt = join(t,"[",(yyvsp[-2].s));
                                                                                            (yyval.s) = join(tt,"]","");
                                                                                            free(t);free(tt);
                                                                                            free((yyvsp[-8].s));free((yyvsp[-5].s));free((yyvsp[-2].s));}
#line 3486 "parser.tab.c"
    break;

  case 218:
#line 889 "parser.y"
                                  {push_expr_and_args();is_in_fncall=true;}
#line 3492 "parser.tab.c"
    break;

  case 219:
#line 889 "parser.y"
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
#line 3541 "parser.tab.c"
    break;

  case 220:
#line 935 "parser.y"
                              {if(expr_type != CLASS_TYPE){yyerror("attribute or methods can only be accessed on class type objects found %s",type_arr[expr_type]);}}
#line 3547 "parser.tab.c"
    break;


#line 3551 "parser.tab.c"

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
#line 937 "parser.y"


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
