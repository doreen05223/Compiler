/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno;
extern int yylex();
void yyerror();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
char savebuf[256];
char syntaxerror[256];
char syntaxerrorToken[100];
char saveAttri[1000];

/* Strcuct */
typedef union _DATA{
    int     idata;
    double  fdata;
    char    sdata[101];
    bool    bdata;
}DATA;

typedef struct _INT_FLOAT{
    int     type;
    DATA    data;
}INT_FLOAT;

typedef struct _Variable{
    char    id[100];
    char    kind[10];
    char    attribute[1000];
    INT_FLOAT  Val;
}Variable;

struct Table{
    int index;
    int depth;
    Variable Var[1001];
    struct Table* prev;
    struct Table* next;
};

/* Symbol table function - you can add new function if need. */
Variable* lookup_symbol(struct Table*, char* id);
void create_symbol(struct Table** table);
void insert_symbol(struct Table** table, char* id, int type, int kind, INT_FLOAT Var);
void dump_symbol(struct Table* table);
void print_redeclaredV();
void print_undeclaredV();
void print_redeclaredF();
void print_undeclaredF();
void print_syntaxError();
INT_FLOAT get_id(char* id);
void new_scope();
void delete_scope();

struct Table* CUR_TABLE;
int depth;
int reDeclarV=0, unDeclarV=0, reDeclarF=0, unDeclarF=0;
char* saveID;
int isVariable=0, isFunction=0;
int wkind; //0=variable, 1=function, 2=parameter
int countAttri=0, iferror=0, isforward=0;

#line 133 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PRINT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    VOID = 263,
    COMMA = 264,
    SEMICOLON = 265,
    LSB = 266,
    RSB = 267,
    NEWLINE = 268,
    ADD = 269,
    SUB = 270,
    MUL = 271,
    DIV = 272,
    MOD = 273,
    INC = 274,
    DEC = 275,
    MT = 276,
    LT = 277,
    MTE = 278,
    LTE = 279,
    EQ = 280,
    NE = 281,
    ASGN = 282,
    ADDASGN = 283,
    SUBASGN = 284,
    MULASGN = 285,
    DIVASGN = 286,
    MODASGN = 287,
    AND = 288,
    OR = 289,
    NOT = 290,
    LB = 291,
    RB = 292,
    LCB = 293,
    RCB = 294,
    I_CONST = 295,
    F_CONST = 296,
    STRING = 297,
    ID = 298,
    INT = 299,
    FLOAT = 300,
    BOOL = 301,
    TRUE = 302,
    FALSE = 303,
    RET = 304,
    CONT = 305,
    BREAK = 306
  };
#endif
/* Tokens.  */
#define PRINT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define VOID 263
#define COMMA 264
#define SEMICOLON 265
#define LSB 266
#define RSB 267
#define NEWLINE 268
#define ADD 269
#define SUB 270
#define MUL 271
#define DIV 272
#define MOD 273
#define INC 274
#define DEC 275
#define MT 276
#define LT 277
#define MTE 278
#define LTE 279
#define EQ 280
#define NE 281
#define ASGN 282
#define ADDASGN 283
#define SUBASGN 284
#define MULASGN 285
#define DIVASGN 286
#define MODASGN 287
#define AND 288
#define OR 289
#define NOT 290
#define LB 291
#define RB 292
#define LCB 293
#define RCB 294
#define I_CONST 295
#define F_CONST 296
#define STRING 297
#define ID 298
#define INT 299
#define FLOAT 300
#define BOOL 301
#define TRUE 302
#define FALSE 303
#define RET 304
#define CONT 305
#define BREAK 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 70 "compiler_hw2.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char* string;
    bool b_val;
    INT_FLOAT if_val;

#line 283 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 300 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   308

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   126,   130,   131,   132,   133,   134,   135,
     139,   139,   139,   148,   148,   153,   154,   157,   157,   158,
     159,   160,   161,   162,   166,   170,   174,   178,   178,   180,
     180,   185,   186,   187,   188,   189,   193,   197,   198,   199,
     200,   201,   204,   205,   209,   210,   211,   212,   213,   214,
     218,   222,   222,   230,   230,   237,   244,   248,   252,   256,
     256,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   277,   278,   279,   280,   284,
     285,   286,   290,   294,   295
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PRINT", "IF", "ELSE", "FOR", "WHILE",
  "VOID", "COMMA", "SEMICOLON", "LSB", "RSB", "NEWLINE", "ADD", "SUB",
  "MUL", "DIV", "MOD", "INC", "DEC", "MT", "LT", "MTE", "LTE", "EQ", "NE",
  "ASGN", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "MODASGN", "AND",
  "OR", "NOT", "LB", "RB", "LCB", "RCB", "I_CONST", "F_CONST", "STRING",
  "ID", "INT", "FLOAT", "BOOL", "TRUE", "FALSE", "RET", "CONT", "BREAK",
  "$accept", "program", "stat", "function", "$@1", "$@2", "$@3",
  "ifforward", "paramater", "$@4", "fblock", "flcb", "frcb", "declaration",
  "$@5", "$@6", "type", "initializer", "compound_stat", "incdec_stat",
  "assign_stat", "if_stat", "$@7", "$@8", "while_stat", "block", "lcb",
  "rcb", "print_func", "$@9", "expression_stat", "operand", "literal",
  "identifier", "bool_stat", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -34

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,    83,   -99,   -29,   -25,   -25,   -99,   -99,   -25,   -99,
     -99,   -99,   -34,    46,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,   -19,   -99,     4,    20,   -99,   -99,   -99,   -99,
     -99,   255,   -99,   -99,   -99,   -99,   -25,   -99,   -99,   182,
     182,   207,   -99,   -99,   -25,   -25,   -25,   -25,   -25,   -25,
     125,    -2,   -99,   -99,   147,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   231,     8,
      34,   -99,   255,   255,   255,   255,   255,   255,    -6,    12,
       5,   255,   -99,   -25,   -99,   -99,   -99,    11,    11,   -99,
     -99,   -99,    21,    21,    21,    21,    21,    21,   282,   269,
      40,    29,   -99,   -99,   125,    58,    60,    59,    61,   255,
     125,   -99,    67,    77,   -99,   -99,   -99,   -99,   -99,    48,
      75,   -99,   -99,    76,   125,    79,    -5,   -99,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -99,   147,    80,   100,
      81,   -99,   -25,   -99,    85,    84,    63,   -99,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     1,     0,     0,     0,    35,     9,     0,    57,
      79,    80,    81,    82,    31,    32,    34,    83,    84,     2,
       8,     4,     0,     5,     0,     0,    39,    40,    41,     3,
       7,     6,    61,    75,    76,    77,     0,    81,    82,     0,
       0,     0,    42,    43,     0,     0,     0,     0,     0,     0,
      22,     0,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,    44,    45,    46,    47,    48,    49,    82,     0,
       0,    23,    29,     0,    10,    58,    56,    70,    71,    72,
      73,    74,    68,    66,    69,    67,    64,    65,    62,    63,
       0,    53,    50,    55,    22,     0,    19,     0,     0,    36,
      22,    59,     0,     0,    20,    13,    17,    30,    27,     0,
       0,    51,    54,     0,    22,     0,     0,    60,     3,    14,
      18,    28,    16,    25,    11,    15,     3,     0,     0,     0,
       0,    12,     0,    52,     0,     0,     0,    26,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -27,   -99,   -99,   -99,   -99,   -99,   -99,   -98,   -99,
     -99,   -99,   -99,   -99,   -99,   -99,   -40,   -99,   -99,   -99,
     -99,   -15,   -99,   -99,   -99,   -20,   -99,   -38,   -99,   -99,
      -4,   -37,   -99,   -99,   -99
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    19,    20,   110,   138,   123,   134,    79,   124,
     135,   136,   148,    21,   125,   107,    22,   108,    23,    24,
      25,    26,   128,   113,    27,    28,    29,    86,    30,   120,
      31,    32,    33,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    40,    54,   104,    41,   132,   114,    36,    82,   -33,
      80,     8,   119,   101,    52,    10,    11,    37,    38,    69,
      70,   102,    17,    18,    51,    83,   130,    57,    58,    59,
      53,   -21,    68,   133,    84,    55,    56,    57,    58,    59,
      72,    73,    74,    75,    76,    77,    81,   103,   106,   105,
     111,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    80,    42,    43,   112,   115,   116,
      80,   118,   117,    44,    45,    46,    47,    48,    49,   109,
     121,     4,    50,     2,    80,   126,     3,     4,   127,   129,
       5,     6,   131,   141,   143,   145,     7,   146,   122,   140,
      81,   137,   147,     3,     4,   144,    81,     5,     6,   139,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     8,
      81,     9,     0,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,     6,     0,     0,     8,     0,     9,     0,
      10,    11,    12,    13,    14,    15,    16,    17,    18,   142,
       3,     4,     0,     0,     5,     6,     0,     0,     0,     0,
       7,     8,     0,     0,     0,    10,    11,    12,    78,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     9,    85,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    55,    56,    57,    58,
      59,     0,     0,    60,    61,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,    66,    67,     0,     0,     0,
       9,    55,    56,    57,    58,    59,     0,     0,    60,    61,
      62,    63,    64,    65,     0,     0,     0,     0,     0,     0,
      66,    67,     0,     0,    71,    55,    56,    57,    58,    59,
       0,     0,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,     0,    66,    67,     0,     0,   100,    55,
      56,    57,    58,    59,     0,     0,    60,    61,    62,    63,
      64,    65,     0,    55,    56,    57,    58,    59,    66,    67,
      60,    61,    62,    63,    64,    65,    55,    56,    57,    58,
      59,     0,    66,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
       4,     5,    29,     9,     8,    10,   104,    36,    10,    43,
      50,    36,   110,     5,    10,    40,    41,    42,    43,    39,
      40,    13,    47,    48,    43,    27,   124,    16,    17,    18,
      10,    37,    36,    38,    36,    14,    15,    16,    17,    18,
      44,    45,    46,    47,    48,    49,    50,    13,    43,    37,
      10,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   104,    19,    20,    38,    10,     9,
     110,    10,    13,    27,    28,    29,    30,    31,    32,    83,
      13,     4,    36,     0,   124,    37,     3,     4,    13,    13,
       7,     8,    13,    13,    13,    10,    13,    13,   113,   137,
     104,   128,    39,     3,     4,   142,   110,     7,     8,   136,
      -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,    -1,    36,
     124,    38,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,     8,    -1,    -1,    36,    -1,    38,    -1,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
       3,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,    -1,
      13,    36,    -1,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    37,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,    14,    15,    16,    17,    18,    33,    34,
      21,    22,    23,    24,    25,    26,    14,    15,    16,    17,
      18,    -1,    33,    21,    22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     3,     4,     7,     8,    13,    36,    38,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    54,
      55,    65,    68,    70,    71,    72,    73,    76,    77,    78,
      80,    82,    83,    84,    85,    86,    36,    42,    43,    82,
      82,    82,    19,    20,    27,    28,    29,    30,    31,    32,
      36,    43,    10,    10,    53,    14,    15,    16,    17,    18,
      21,    22,    23,    24,    25,    26,    33,    34,    82,    77,
      77,    37,    82,    82,    82,    82,    82,    82,    43,    60,
      68,    82,    10,    27,    36,    39,    79,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      37,     5,    13,    13,     9,    37,    43,    67,    69,    82,
      56,    10,    38,    75,    60,    10,     9,    13,    10,    60,
      81,    13,    73,    58,    61,    66,    37,    13,    74,    13,
      60,    13,    10,    38,    59,    62,    63,    53,    57,    53,
      79,    13,    49,    13,    83,    10,    13,    39,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      56,    57,    55,    58,    55,    59,    59,    61,    60,    60,
      60,    60,    60,    60,    62,    63,    64,    66,    65,    67,
      65,    68,    68,    68,    68,    68,    69,    70,    70,    70,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    74,    73,    75,    73,    76,    77,    78,    79,    81,
      80,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       0,     0,     9,     0,     7,     1,     1,     0,     5,     2,
       3,     1,     0,     1,     7,     1,     1,     0,     7,     0,
       5,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     2,     2,     3,     3,     3,     3,     3,     3,
       4,     0,    10,     0,     6,     4,     3,     1,     1,     0,
       7,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 4:
#line 130 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 131 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 132 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 135 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {new_scope();}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {isFunction=1;}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {
	if(isforward == 0) dump_symbol(CUR_TABLE);
	else if(isforward == 1) {CUR_TABLE==NULL;isforward=0;}
	delete_scope(); 
	INT_FLOAT n;
	isVariable = 0;
	wkind = 1;
	insert_symbol(&CUR_TABLE, (yyvsp[-7].string), (yyvsp[-8].i_val), wkind, n); 
	if(reDeclarF==1 && isVariable==0) print_redeclaredF();}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "compiler_hw2.y" /* yacc.c:1646  */
    {isFunction=1; isVariable = 0; get_id((yyvsp[-4].string));}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 148 "compiler_hw2.y" /* yacc.c:1646  */
    {
	if(unDeclarF==1 && isVariable==0) print_undeclaredF();
        if(unDeclarV==1) print_undeclaredV();}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 154 "compiler_hw2.y" /* yacc.c:1646  */
    {isforward=1;}
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "compiler_hw2.y" /* yacc.c:1646  */
    {INT_FLOAT n; wkind=2; insert_symbol(&CUR_TABLE, (yyvsp[-1].string), (yyvsp[-2].i_val), wkind, n);}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 158 "compiler_hw2.y" /* yacc.c:1646  */
    {INT_FLOAT n; wkind=2; insert_symbol(&CUR_TABLE, (yyvsp[0].string), (yyvsp[-1].i_val), wkind, n); }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 159 "compiler_hw2.y" /* yacc.c:1646  */
    {get_id((yyvsp[-2].string));}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "compiler_hw2.y" /* yacc.c:1646  */
    {get_id((yyvsp[0].string));}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 161 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 166 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 178 "compiler_hw2.y" /* yacc.c:1646  */
    {isVariable=1; wkind=0; insert_symbol(&CUR_TABLE, (yyvsp[-3].string), (yyvsp[-4].i_val), wkind, (yyvsp[-1].if_val));}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 178 "compiler_hw2.y" /* yacc.c:1646  */
    {
	if(reDeclarV==1) print_redeclaredV();}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 180 "compiler_hw2.y" /* yacc.c:1646  */
    {isVariable=1; INT_FLOAT n; wkind=0; insert_symbol(&CUR_TABLE, (yyvsp[-1].string), (yyvsp[-2].i_val), wkind, n);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 180 "compiler_hw2.y" /* yacc.c:1646  */
    {
	if(reDeclarV==1) print_redeclaredV();}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 185 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.i_val) = I_CONST; }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 186 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.i_val) = F_CONST; }
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 187 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.i_val) = STRING; }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 188 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.i_val) = BOOL; }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 189 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.i_val) = VOID; }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 204 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 205 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 209 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 210 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 211 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 212 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 213 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 214 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 218 "compiler_hw2.y" /* yacc.c:1646  */
    { 
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 222 "compiler_hw2.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();
        new_scope();}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 226 "compiler_hw2.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 230 "compiler_hw2.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 233 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 237 "compiler_hw2.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 244 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    {new_scope();}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 256 "compiler_hw2.y" /* yacc.c:1646  */
    {memcpy(&savebuf,buf,256);}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 256 "compiler_hw2.y" /* yacc.c:1646  */
    {if(unDeclarV==1) print_undeclaredV();}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 261 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 262 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 263 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 264 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 265 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 267 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 268 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 269 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 270 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 271 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 272 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 273 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 280 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[-1].if_val); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 284 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 285 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 286 "compiler_hw2.y" /* yacc.c:1646  */
    {}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 290 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.if_val) = get_id((yyvsp[0].string)); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 294 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[0].if_val); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 295 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[0].if_val); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1939 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 298 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */

int main(int argc, char** argv)
{
    yylineno = 0;
    char str1[] = "(";
    char str2[] = ")";
    char str3[] = "{";
    char token[100];
    int seti=0, setf=0;

    yyparse();
    if(iferror == 0){
    	dump_symbol(CUR_TABLE);
    	printf("\nTotal lines: %d \n",yylineno);
    }
    // if syntactic error
    else if(iferror == 1){
	printf("%d:%s\n",yylineno+1, syntaxerror);	// print error line
	if(strpbrk(syntaxerror,str1) && strpbrk(syntaxerror,str2) && strpbrk(syntaxerror,str3)){
		for(int i=0 ; i<strlen(syntaxerror) ; i++){
			if(syntaxerror[i]==' ' && syntaxerror[i+1]!='(') seti=i;
			if((syntaxerror[i]==' ' && syntaxerror[i+1]=='(')||(syntaxerror[i]=='(')){
				setf=i;
				i=strlen(syntaxerror);
			}
		}
                printf("\n|-----------------------------------------------|\n");
    		printf("| Error found in line %d:%s\n", yylineno+1, syntaxerror);
    		printf("| Undeclared function ");
		for(int i=seti+1 ; i<setf ; i++){ printf("%c", syntaxerror[i]); }
    		printf("\n|-----------------------------------------------|\n\n");
	}
	print_syntaxError();
    }
    return 0;
}

void yyerror(char *s)
{
    memcpy(&syntaxerror, buf, 256);
    memcpy(&syntaxerrorToken, s, 100);
    iferror = 1;
}

void print_syntaxError(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno+1, syntaxerror);
    printf("| %s", syntaxerrorToken);
    printf("\n|-----------------------------------------------|\n\n");
}

void create_symbol(struct Table** table) {
    *table = (struct Table*)malloc(sizeof(struct Table));
    memset(*table, 0, sizeof(struct Table));
}

int noAttri=0, functionDec=0, ii=0, idx=0;
void insert_symbol(struct Table** table, char* id, int type, int kind, INT_FLOAT n){
    if(*table == NULL)  create_symbol(table);
    // Detect if redeclare
    for(int i=1 ; i<=CUR_TABLE->index ; ++i){
        if(strcmp(id, CUR_TABLE->Var[i].id)==0 && type!=(CUR_TABLE->Var[i].Val.type)){
		if(isFunction == 1){ reDeclarF = 1; reDeclarV = 0;}
		if(isVariable == 1){ reDeclarV = 1; reDeclarF = 0;}
		memcpy(&savebuf,buf,256);
		saveID = id;
        	return;
	}
	else if(strcmp(id, CUR_TABLE->Var[i].id)==0 && type==(CUR_TABLE->Var[i].Val.type) && isFunction==1)
		functionDec = 1;
		ii = i;
    }

    if(functionDec==0){
    	// insert symbol
    	idx = ++((*table)->index);
    	strcpy((*table)->Var[idx].id, id);
    	(*table)->Var[idx].Val = n;
    	(*table)->Var[idx].Val.type = type;
    }
    // set attribute table
    if(kind == 0) memcpy( (*table)->Var[idx].kind, "variable", 10 );
    else if(kind == 1){ 
	memcpy( (*table)->Var[idx].kind, "function", 10 );
	if(countAttri != 0){
		char getAttri[1000];
		strncpy(getAttri,saveAttri,countAttri-2);
		getAttri[countAttri-2] = '\0';
		if(functionDec==0)
			memcpy( (*table)->Var[idx].attribute, getAttri, 1000 );		// get attribute
		else if(functionDec==1) {
			memcpy( (*table)->Var[ii].attribute, getAttri, 1000 );
			functionDec=0;
		}
		memset(&saveAttri, '\0', 1000);
		memset(&getAttri, '\0', 1000);
        	countAttri = 0;
	}
    }
    else if(kind ==2){
	memcpy( (*table)->Var[idx].kind, "parameter", 10 );
	if(type == I_CONST){ 
		strcat(saveAttri,"int, ");
		countAttri = countAttri+5;
	}
	else if(type == F_CONST){ 
                strcat(saveAttri,"float, ");
                countAttri = countAttri+7;
        }
	else if(type == STRING){
                strcat(saveAttri,"string, ");
                countAttri = countAttri+8;
        }
	else if(type == BOOL){
                strcat(saveAttri,"bool, ");
                countAttri = countAttri+6;
        }
	else countAttri = 0;
    }
}

void print_redeclaredV(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Redeclared variable %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    reDeclarV = 0;
    saveID = '\0';
}

void print_redeclaredF(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Redeclared function %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    reDeclarF = 0;
    saveID = '\0';
    isFunction = 0;
}

Variable* lookup_symbol(struct Table* table, char* id) {
    if(table == NULL)   return NULL;
    for(int i=1 ; i<=table->index ; ++i){
        if(!strcmp(id, table->Var[i].id)){
            depth = table->depth;
            return &(table->Var[i]);
        }
    }
    if(table->prev != NULL)
        return lookup_symbol(table->prev, id);
    return NULL;
}

void dump_symbol(struct Table* table) {
    if(table->index > 0){
    	printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n","Index", "Name", "Kind", "Type", "Scope", "Attribute");
    	for(int i=1; i<=table->index ; ++i){
        	switch(table->Var[i].Val.type){
            	case I_CONST: if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "int", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "int", table->depth, table->Var[i].attribute);
			      break; 
            	case F_CONST: if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "float", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "float", table->depth, table->Var[i].attribute);
			      break;
            	case STRING:  if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "string", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "string", table->depth, table->Var[i].attribute);
			      break;
	    	case BOOL:    if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "bool", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "bool", table->depth, table->Var[i].attribute);
			      break;
		case VOID:    if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "void", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "void", table->depth, table->Var[i].attribute);
			      break;
        	}
    	}
	printf("\n");
    }
}

INT_FLOAT get_id(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL){
	if(isFunction == 1){ unDeclarF = 1; unDeclarV = 0;}
        if(isVariable == 1){ unDeclarV = 1; unDeclarF = 0;}
	memcpy(&savebuf, buf, 256);
        saveID = id;
        INT_FLOAT n = {0};
        return n;
    }
    else
        return v->Val;
}

void print_undeclaredV(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Undeclared variable %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    unDeclarV = 0;
    saveID = '\0';
}

void print_undeclaredF(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Undeclared function %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    unDeclarF = 0;
    saveID = '\0';
}

void new_scope(){
    if(CUR_TABLE == NULL) {
	create_symbol(&CUR_TABLE);
	(CUR_TABLE->depth)++;
    }
    else{
    	struct Table* next;
    	create_symbol(&next);
    	CUR_TABLE->next = next;
    	next->prev = CUR_TABLE;
    	next->depth = CUR_TABLE->depth + 1;
    	CUR_TABLE = next;
    }
}

void delete_scope(){
    CUR_TABLE = CUR_TABLE->prev;
    free(CUR_TABLE->next);
}
