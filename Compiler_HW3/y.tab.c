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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

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

/**********************************************************************/
#define get_data(Val)   ( Val.type == I_CONST ? Val.data.idata : Val.data.fdata )
#define operation(left, op, right)  if((left.type == I_CONST) && (right.type == I_CONST)){  \
                                        ret.type = I_CONST;                                 \
                                        ret.data.idata = get_data(left) op get_data(right); \
                                    }                                                       \
                                    else{                                                   \
                                        ret.type = F_CONST;                                 \
                                        ret.data.fdata = get_data(left) op get_data(right); \
                                    }
#define print_rel($$) printf("%s\n",get_data($$) ? " true" : " false");
#define print_type(type)    if(type == I_CONST) fprintf(file, "\ti");\
			    else if(type == F_CONST) fprintf(file, "\tf");\
			    else fprintf(file, "\ta");
#define def_type_trans(left, right)     if((left.type == I_CONST)&&(right.type == F_CONST))    fprintf(file, "\tf2i\n"); \
					if((left.type == F_CONST)&&(right.type == I_CONST)) fprintf(file, "\ti2f\n");
/**********************************************************************/
//define print_type(type)    type == I_CONST ? fprintf(file, "\ti") : fprintf(file, "\tf")
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
    int	    iidx;
}INT_FLOAT;

typedef struct _Variable{
    char    id[100];
    char    kind[10];
    char    attribute[1000];
    INT_FLOAT  Val;
    int iidx;
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

FILE* file;
INT_FLOAT val_assign(int type, void* value, int index);
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right);
void assign_expr(char* id, INT_FLOAT value);
void assign_id(char* id, int op, INT_FLOAT expr);
int var_idx;
int ERROR = 0;
void print_var(char* id);
void print_load(char* id);
void print_store(char* id);
void print_jump(int op, char* label_name);
void print_label(char* label_name);
void alu_type_trans(INT_FLOAT left, INT_FLOAT right);
void op_assign(INT_FLOAT left, INT_FLOAT right);
int bool_handler(INT_FLOAT left, int op, INT_FLOAT right);
int isWhile = 0;
int label_idx = 0;

struct Table* CUR_TABLE;
int depth;
int reDeclarV=0, unDeclarV=0, reDeclarF=0, unDeclarF=0;
char* saveID;
int isVariable=0, isFunction=0;
int wkind; //0=variable, 1=function, 2=parameter
int countAttri=0, iferror=0, isforward=0;

#line 171 "y.tab.c" /* yacc.c:339  */

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
#line 108 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char* string;
    bool b_val;
    INT_FLOAT if_val;

#line 321 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 338 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   427

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
       0,   165,   165,   166,   170,   171,   172,   173,   174,   175,
     179,   179,   179,   189,   189,   195,   196,   199,   199,   200,
     201,   202,   203,   204,   208,   209,   213,   217,   221,   221,
     223,   223,   228,   229,   230,   231,   232,   236,   240,   241,
     242,   243,   244,   248,   255,   265,   266,   267,   268,   269,
     270,   274,   280,   280,   291,   291,   301,   302,   305,   308,
     311,   314,   317,   320,   323,   328,   328,   328,   338,   342,
     346,   350,   350,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   384,   385,   386,
     387,   388,   392,   393,   394,   398,   402,   403
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
  "assign_stat", "if_stat", "$@7", "$@8", "boolean_expr", "while_stat",
  "$@9", "$@10", "block", "lcb", "rcb", "print_func", "$@11",
  "expression_stat", "operand", "literal", "identifier", "bool_stat", YY_NULLPTR
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

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -76

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -108,   106,  -108,   -27,   370,  -108,  -108,  -108,   379,  -108,
    -108,  -108,   -33,   373,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,   -31,  -108,    13,    28,  -108,  -108,  -108,  -108,
    -108,   309,  -108,  -108,  -108,  -108,   379,   370,  -108,  -108,
       1,   323,     5,   237,  -108,  -108,   379,   379,   379,   379,
     379,   379,   147,    -2,  -108,  -108,   168,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     261,    14,   285,     6,   379,   379,   379,   379,   379,   379,
     379,   379,   370,  -108,   309,   309,   309,   309,   309,   309,
      -6,    15,    23,   309,  -108,   379,  -108,  -108,  -108,     4,
       4,  -108,  -108,  -108,    12,    12,    12,    12,    12,    12,
     217,   365,    39,  -108,    29,  -108,    -1,    66,    78,   182,
     207,   212,   337,   351,    31,   147,    59,    77,    74,    79,
     309,   147,  -108,    75,    86,  -108,  -108,  -108,  -108,  -108,
    -108,    60,    85,  -108,  -108,     1,    87,   147,    89,    -3,
    -108,  -108,    92,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,   168,  -108,    95,   121,    98,  -108,  -108,   379,  -108,
    -108,   102,   104,    81,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    91,     1,     0,    91,    65,    36,     9,    91,    69,
      92,    93,    94,    95,    32,    33,    35,    96,    97,     2,
       8,     4,     0,     5,     0,     0,    40,    41,    42,     3,
       7,     6,    73,    87,    88,    89,    91,    91,    94,    95,
       0,     0,     0,     0,    43,    44,    91,    91,    91,    91,
      91,    91,    91,     0,    38,    39,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
       0,     0,     0,     0,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    90,    45,    46,    47,    48,    49,    50,
      95,     0,     0,    23,    30,    91,    10,    70,    68,    82,
      83,    84,    85,    86,    80,    78,    81,    79,    76,    77,
      74,    75,     0,    56,    54,    51,    80,    78,    81,    79,
      76,    77,    57,    58,     0,    91,     0,    19,     0,     0,
      37,    91,    71,     0,     0,    66,    20,    13,    17,    31,
      28,     0,     0,    52,    55,     0,     0,    91,     0,     0,
      72,     3,     0,    14,    18,    29,    16,    26,    11,    15,
       3,    91,    67,     0,    91,     0,    12,    27,    91,    25,
      53,     0,     0,     0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,   -28,  -108,  -108,  -108,  -108,  -108,  -108,  -107,  -108,
    -108,  -108,   -74,  -108,  -108,  -108,   -46,  -108,  -108,  -108,
    -108,   -16,  -108,  -108,   -32,  -108,  -108,  -108,   -38,  -108,
     -39,  -108,  -108,    -4,   -42,  -108,  -108,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    19,    20,   131,   163,   146,   158,    91,   147,
     159,   160,   169,    21,   148,   128,    22,   129,    23,    24,
      25,    26,   151,   134,    40,    27,    42,   145,    28,    29,
      98,    30,   142,    31,    32,    33,    34,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    56,    73,   125,    43,    71,    92,   156,    94,    36,
     -34,   114,    53,    57,    58,    59,    60,    61,   136,   115,
      59,    60,    61,    54,   141,    95,    57,    58,    59,    60,
      61,   -21,    70,    72,    96,   157,   -63,   -63,    55,     9,
     154,    82,    84,    85,    86,    87,    88,    89,    93,   132,
     124,   113,   126,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   127,   133,   135,   137,
     116,   117,   118,   119,   120,   121,   122,   123,    41,    92,
      57,    58,    59,    60,    61,    92,   138,   139,   143,   140,
       4,   130,    57,    58,    59,    60,    61,   149,   150,   174,
     153,    92,   155,   -61,   -61,   162,     2,   152,   166,     3,
       4,   170,   172,     5,     6,   -64,   -64,   173,   144,     7,
     167,    93,   165,   161,     3,     4,   171,    93,     5,     6,
       0,     0,   164,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     8,    93,     9,     0,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     6,     0,     8,     0,     9,
     167,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     168,     3,     4,     0,     0,     5,     6,     0,     0,     0,
       0,     7,     0,     8,   -22,     0,     0,    10,    11,    12,
      90,    14,    15,    16,    17,    18,    57,    58,    59,    60,
      61,     0,     0,     0,     8,     0,     9,    97,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,   -62,
     -62,    57,    58,    59,    60,    61,    57,    58,    59,    60,
      61,    57,    58,    59,    60,    61,     0,     0,    62,    63,
      64,    65,    66,    67,   -59,   -59,     0,     0,     0,   -60,
     -60,    57,    58,    59,    60,    61,     0,     0,    62,    63,
      64,    65,    66,    67,     0,     0,     0,     0,     0,     0,
      68,    69,     0,     0,    83,    57,    58,    59,    60,    61,
       0,     0,    62,    63,    64,    65,    66,    67,     0,     0,
       0,     0,     0,     0,    68,    69,     0,     0,   112,    57,
      58,    59,    60,    61,     0,     0,    74,    75,    76,    77,
      78,    79,     0,     0,     0,     0,     0,     0,    80,    81,
       0,     0,    83,    57,    58,    59,    60,    61,     0,     0,
      62,    63,    64,    65,    66,    67,     0,    57,    58,    59,
      60,    61,    68,    69,    74,    75,    76,    77,    78,    79,
       0,    57,    58,    59,    60,    61,    80,    81,    62,    63,
      64,    65,    66,    67,     0,    57,    58,    59,    60,    61,
     -74,   -74,    62,    63,    64,    65,    66,    67,     0,    57,
      58,    59,    60,    61,    68,   -75,    62,    63,    64,    65,
      66,    67,    44,    45,     0,     0,     0,     0,    68,     0,
      46,    47,    48,    49,    50,    51,    37,     0,     0,    52,
      10,    11,    38,    39,     0,     8,     0,    17,    18,    10,
      11,    38,    39,     0,     0,     0,    17,    18
};

static const yytype_int16 yycheck[] =
{
       4,    29,    40,     9,     8,    37,    52,    10,    10,    36,
      43,     5,    43,    14,    15,    16,    17,    18,   125,    13,
      16,    17,    18,    10,   131,    27,    14,    15,    16,    17,
      18,    37,    36,    37,    36,    38,    37,    38,    10,    38,
     147,    36,    46,    47,    48,    49,    50,    51,    52,    10,
      82,    37,    37,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    43,    38,    37,    10,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   125,
      14,    15,    16,    17,    18,   131,     9,    13,    13,    10,
       4,    95,    14,    15,    16,    17,    18,    37,    13,   173,
      13,   147,    13,    37,    38,    13,     0,   145,    13,     3,
       4,    13,    10,     7,     8,    37,    38,    13,   134,    13,
      39,   125,   161,   151,     3,     4,   168,   131,     7,     8,
      -1,    -1,   160,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,   147,    38,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     8,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,     3,     4,    -1,    -1,     7,     8,    -1,    -1,    -1,
      -1,    13,    -1,    36,    37,    -1,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    -1,    37,
      38,    14,    15,    16,    17,    18,    14,    15,    16,    17,
      18,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    37,    38,    -1,    -1,    -1,    37,
      38,    14,    15,    16,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    -1,    -1,    37,    14,    15,    16,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    37,    14,
      15,    16,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    -1,    37,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    -1,    14,    15,    16,
      17,    18,    33,    34,    21,    22,    23,    24,    25,    26,
      -1,    14,    15,    16,    17,    18,    33,    34,    21,    22,
      23,    24,    25,    26,    -1,    14,    15,    16,    17,    18,
      33,    34,    21,    22,    23,    24,    25,    26,    -1,    14,
      15,    16,    17,    18,    33,    34,    21,    22,    23,    24,
      25,    26,    19,    20,    -1,    -1,    -1,    -1,    33,    -1,
      27,    28,    29,    30,    31,    32,    36,    -1,    -1,    36,
      40,    41,    42,    43,    -1,    36,    -1,    47,    48,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,     0,     3,     4,     7,     8,    13,    36,    38,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    54,
      55,    65,    68,    70,    71,    72,    73,    77,    80,    81,
      83,    85,    86,    87,    88,    89,    36,    36,    42,    43,
      76,    85,    78,    85,    19,    20,    27,    28,    29,    30,
      31,    32,    36,    43,    10,    10,    53,    14,    15,    16,
      17,    18,    21,    22,    23,    24,    25,    26,    33,    34,
      85,    76,    85,    80,    21,    22,    23,    24,    25,    26,
      33,    34,    36,    37,    85,    85,    85,    85,    85,    85,
      43,    60,    68,    85,    10,    27,    36,    39,    82,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    37,    37,     5,    13,    85,    85,    85,    85,
      85,    85,    85,    85,    76,     9,    37,    43,    67,    69,
      85,    56,    10,    38,    75,    37,    60,    10,     9,    13,
      10,    60,    84,    13,    73,    79,    58,    61,    66,    37,
      13,    74,    80,    13,    60,    13,    10,    38,    59,    62,
      63,    53,    13,    57,    53,    82,    13,    39,    49,    64,
      13,    86,    10,    13,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      56,    57,    55,    58,    55,    59,    59,    61,    60,    60,
      60,    60,    60,    60,    62,    62,    63,    64,    66,    65,
      67,    65,    68,    68,    68,    68,    68,    69,    70,    70,
      70,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    73,    74,    73,    75,    73,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    78,    79,    77,    80,    81,
      82,    84,    83,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    89,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       0,     0,     9,     0,     7,     1,     1,     0,     5,     2,
       3,     1,     0,     1,     7,     3,     1,     1,     0,     7,
       0,     5,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     4,     0,    10,     0,     6,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     0,     8,     3,     1,
       1,     0,     7,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     1
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
#line 170 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 171 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 172 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 174 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 175 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 179 "compiler_hw3.y" /* yacc.c:1646  */
    {new_scope(); if(strcpy((yyvsp[-1].string),"main")==0) fprintf(file, ".method public static %s()\n.limit stack 50\n.limit locals 50\n",(yyvsp[-1].string));}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 179 "compiler_hw3.y" /* yacc.c:1646  */
    {isFunction=1;}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 179 "compiler_hw3.y" /* yacc.c:1646  */
    {
	if(isforward == 0) dump_symbol(CUR_TABLE);
	else if(isforward == 1) {CUR_TABLE==NULL;isforward=0;}
	delete_scope(); 
	INT_FLOAT n;
	isVariable = 0;
	wkind = 1;
	insert_symbol(&CUR_TABLE, (yyvsp[-7].string), (yyvsp[-8].i_val), wkind, n); 
	if(strcpy((yyvsp[-7].string),"main")==0) fprintf(file, "\treturn\n.end method\n");
	if(reDeclarF==1 && isVariable==0) print_redeclaredF();}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {isFunction=1; isVariable = 0; get_id((yyvsp[-4].string));}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 189 "compiler_hw3.y" /* yacc.c:1646  */
    {
	fprintf(file, "invokestatic compeiler_hw3/%s()",(yyvsp[-6].string));
	if(unDeclarF==1 && isVariable==0) print_undeclaredF();
        if(unDeclarV==1) print_undeclaredV();}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 196 "compiler_hw3.y" /* yacc.c:1646  */
    {isforward=1;}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 199 "compiler_hw3.y" /* yacc.c:1646  */
    {INT_FLOAT n; wkind=2; insert_symbol(&CUR_TABLE, (yyvsp[-1].string), (yyvsp[-2].i_val), wkind, n);}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 199 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "compiler_hw3.y" /* yacc.c:1646  */
    {INT_FLOAT n; wkind=2; insert_symbol(&CUR_TABLE, (yyvsp[0].string), (yyvsp[-1].i_val), wkind, n); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 201 "compiler_hw3.y" /* yacc.c:1646  */
    {get_id((yyvsp[-2].string));}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 202 "compiler_hw3.y" /* yacc.c:1646  */
    {get_id((yyvsp[0].string));}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 203 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 208 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 209 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "compiler_hw3.y" /* yacc.c:1646  */
    {isVariable=1; wkind=0; insert_symbol(&CUR_TABLE, (yyvsp[-3].string), (yyvsp[-4].i_val), wkind, (yyvsp[-1].if_val));}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 221 "compiler_hw3.y" /* yacc.c:1646  */
    {
	if(reDeclarV==1) print_redeclaredV();}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "compiler_hw3.y" /* yacc.c:1646  */
    {isVariable=1; INT_FLOAT n; wkind=0; fprintf(file, "\tldc 0\n"); insert_symbol(&CUR_TABLE, (yyvsp[-1].string), (yyvsp[-2].i_val), wkind, n);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 223 "compiler_hw3.y" /* yacc.c:1646  */
    {
	if(reDeclarV==1) print_redeclaredV();}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 228 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = I_CONST; }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 229 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = F_CONST; }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 230 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = STRING; }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = BOOL; }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 232 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = VOID; }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 248 "compiler_hw3.y" /* yacc.c:1646  */
    {
	INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
	fprintf(file, "\tldc 1\n");
	assign_id((yyvsp[-1].string), ADD, one);
    }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 255 "compiler_hw3.y" /* yacc.c:1646  */
    {
	INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
	fprintf(file, "\tldc 1\n");
	assign_id((yyvsp[-1].string), SUB, one);
    }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 265 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_expr((yyvsp[-2].string), (yyvsp[0].if_val)); print_store((yyvsp[-2].string)); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 266 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_id((yyvsp[-2].string), ADD, (yyvsp[0].if_val)); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 267 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_id((yyvsp[-2].string), SUB, (yyvsp[0].if_val)); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 268 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_id((yyvsp[-2].string), MUL, (yyvsp[0].if_val)); }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 269 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_id((yyvsp[-2].string), DIV, (yyvsp[0].if_val)); }
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 270 "compiler_hw3.y" /* yacc.c:1646  */
    { assign_id((yyvsp[-2].string), MOD, (yyvsp[0].if_val)); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 274 "compiler_hw3.y" /* yacc.c:1646  */
    { 
	dump_symbol(CUR_TABLE);
	delete_scope();
	fprintf(file, "\tgoto EXIT_0\n");
	fprintf(file, "LABEL_ELSE%d:\n", label_idx);
	if(unDeclarV==1) print_undeclaredV();}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 280 "compiler_hw3.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	fprintf(file, "\tgoto EXIT_0\n");
	fprintf(file, "LABEL_ELSE%d:\n", label_idx);
	label_idx++;
	if(unDeclarV==1) print_undeclaredV();
        new_scope();}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 287 "compiler_hw3.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 291 "compiler_hw3.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	fprintf(file, "\tgoto EXIT_0\n");
	fprintf(file, "LABEL_ELSE%d:\n", label_idx);
	label_idx++;
	if(unDeclarV==1) print_undeclaredV();}
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 297 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 301 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = (yyvsp[-1].i_val); }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 302 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), AND, (yyvsp[0].if_val));
	if(isWhile != 1) { print_jump(AND,"LABEL_AND"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_AND"); }
    }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 305 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), OR, (yyvsp[0].if_val));
	if(isWhile != 1) { print_jump(OR,"LABEL_OR"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_OR"); }
    }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 308 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), EQ, (yyvsp[0].if_val));
	if(isWhile != 1) { print_jump(EQ,"LABEL_EQ"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_EQ"); }
    }
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 311 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), NE, (yyvsp[0].if_val));
	if(isWhile != 1) { print_jump(NE,"LABEL_NE"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_NE"); }
    }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 314 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), LT, (yyvsp[0].if_val)); 
	if(isWhile != 1) { print_jump(LT,"LABEL_LT"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_LT"); }
    }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 317 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), LTE, (yyvsp[0].if_val)); 
        if(isWhile != 1) { print_jump(LTE,"LABEL_LTE"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_LTE"); }
    }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 320 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), MT, (yyvsp[0].if_val));
	if(isWhile != 1) { print_jump(MT,"LABEL_MT"); fprintf(file, "\tgoto LABEL_ELSE%d\n",label_idx); print_label("LABEL_MT"); }
    }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 323 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.i_val) = bool_handler((yyvsp[-2].if_val), MTE, (yyvsp[0].if_val));
	if(isWhile != 1) { print_jump(MTE,"LABEL_MTE"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_MTE"); }
    }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 328 "compiler_hw3.y" /* yacc.c:1646  */
    {print_label("LABEL_BEGIN"); isWhile = 1;}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 328 "compiler_hw3.y" /* yacc.c:1646  */
    {
	print_jump(LT,"LABEL_TRUE");fprintf(file, "\tgoto LABEL_FALSE\n");print_label("LABEL_TRUE"); }
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 329 "compiler_hw3.y" /* yacc.c:1646  */
    {
	dump_symbol(CUR_TABLE);
	delete_scope();
	print_label("LABEL_FALSE");
	isWhile = 0;
	if(unDeclarV==1) print_undeclaredV(); }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 338 "compiler_hw3.y" /* yacc.c:1646  */
    { }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 342 "compiler_hw3.y" /* yacc.c:1646  */
    { new_scope(); }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 346 "compiler_hw3.y" /* yacc.c:1646  */
    { /*fprintf(file, "\tgoto EXIT_0\n");*/ }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 350 "compiler_hw3.y" /* yacc.c:1646  */
    {
	fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
        switch((yyvsp[-2].if_val).type){
            case I_CONST:
                fprintf(file, "\tinvokevirtual java/io/PrintStream/println(I)V\n");
                break;
            case F_CONST:
                fprintf(file, "\tinvokevirtual java/io/PrintStream/println(F)V\n");
                break;
            case STRING:
                fprintf(file, "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		break;
	}
	memcpy(&savebuf,buf,256);}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 363 "compiler_hw3.y" /* yacc.c:1646  */
    {if(unDeclarV==1) print_undeclaredV();}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 368 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),AND,(yyvsp[0].if_val)); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 369 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),OR,(yyvsp[0].if_val)); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),EQ,(yyvsp[0].if_val)); }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 371 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),NE,(yyvsp[0].if_val)); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 372 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),LT,(yyvsp[0].if_val)); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),LTE,(yyvsp[0].if_val)); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),MT,(yyvsp[0].if_val)); }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 375 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),MTE,(yyvsp[0].if_val)); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 376 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),ADD,(yyvsp[0].if_val)); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 377 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),SUB,(yyvsp[0].if_val)); }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 378 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),MUL,(yyvsp[0].if_val)); }
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 379 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),DIV,(yyvsp[0].if_val)); }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 380 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = alu((yyvsp[-2].if_val),MOD,(yyvsp[0].if_val)); }
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 387 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[-1].if_val); }
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 388 "compiler_hw3.y" /* yacc.c:1646  */
    {}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 392 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = val_assign(I_CONST, &(yyvsp[0].i_val), -1); fprintf(file, "\tldc %d\n", (yyvsp[0].i_val)); }
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 393 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = val_assign(F_CONST, &(yyvsp[0].f_val), -1); fprintf(file, "\tldc %f\n", (yyvsp[0].f_val)); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 394 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = val_assign(STRING, &(yyvsp[0].string), -1); fprintf(file, "\tldc \"%s\"\n", (yyvsp[0].string)); }
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 398 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = get_id((yyvsp[0].string)); print_load((yyvsp[0].string)); }
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 402 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[0].if_val); }
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 403 "compiler_hw3.y" /* yacc.c:1646  */
    { (yyval.if_val) = (yyvsp[0].if_val); }
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2151 "y.tab.c" /* yacc.c:1646  */
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
#line 406 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */

int main(int argc, char** argv)
{
    yylineno = 0;
    char str1[] = "(";
    char str2[] = ")";
    char str3[] = "{";
    char token[100];
    int seti=0, setf=0;

    file = fopen("compiler_hw3.j","w");
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n"
		    ".method public static main([Ljava/lang/String;)V\n"
		    ".limit stack 50\n"
		    ".limit locals 50\n");

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
		ERROR = 1;
	}
	print_syntaxError();
    }

    fprintf(file, "\tgoto EXIT_0\n");
    fprintf(file, "EXIT_0:\n"
		  "\treturn\n"
                  ".end method\n");
    fclose(file);
    if(ERROR == 1) remove("compiler_hw3.j");

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
    ERROR = 1;
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
	(*table)->Var[idx].iidx = (*table)->Var[idx].Val.iidx = var_idx++;
        def_type_trans((*table)->Var[idx].Val, n);
	if(wkind != 1){
		if(type == I_CONST) fprintf(file, "\tistore %d\n", (*table)->Var[idx].iidx);
    		else if(type == F_CONST) fprintf(file, "\tfstore %d\n", (*table)->Var[idx].iidx);
    		else fprintf(file, "\tastore %d\n", (*table)->Var[idx].iidx);
	}
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
    ERROR = 1;
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
    ERROR = 1;
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
    ERROR = 1;
}

void print_undeclaredF(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Undeclared function %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    unDeclarF = 0;
    saveID = '\0';
    ERROR = 1;
}

void new_scope(){
    if(CUR_TABLE == NULL) {
	create_symbol(&CUR_TABLE);
	(CUR_TABLE->depth)++;
    }
    struct Table* next;
    create_symbol(&next);
    CUR_TABLE->next = next;
    next->prev = CUR_TABLE;
    next->depth = CUR_TABLE->depth + 1;
    CUR_TABLE = next;
}

void delete_scope(){
    CUR_TABLE = CUR_TABLE->prev;
    free(CUR_TABLE->next);
}

INT_FLOAT val_assign(int type, void* value, int index){
    INT_FLOAT Val;
    Val.type = type;
    Val.iidx = index;
    switch(type){                                           
        case I_CONST:
            Val.data.idata = *(int*) value;
            break;
        case F_CONST:
            Val.data.fdata = *(double*) value; 
            break;
        case STRING: 
            strcpy(Val.data.sdata, (char*) value);     
            break;
    }
    return Val;
}

INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right){
    INT_FLOAT ret;
    alu_type_trans(left, right);
    switch(op){    
        case ADD:
            fprintf(file, "add\n");
            operation(left, +, right);
            break;
        case SUB:
            fprintf(file, "sub\n");
            operation(left, -, right);
            break;
        case MUL:
            fprintf(file, "mul\n");
            operation(left, *, right);
            break;
        case DIV:
            if((right.iidx == -1)&&(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0)))){
		memcpy(&savebuf, buf, 256);
		printf("\n|-----------------------------------------------|\n");
    		printf("| Error found in line %d:%s\n", yylineno+1, savebuf);
    		printf("| Variables of numbers is divided by 0");
    		printf("\n|-----------------------------------------------|\n\n");
		memset(&savebuf, '\0', 256);
                ERROR = 1;
                ret.type = -1;
            }
            else {
                fprintf(file, "div\n");
                operation(left, /, right);
            }
            break;
        case MOD:
            if((left.type == I_CONST) && (right.type == I_CONST)){
                fprintf(file, "rem\n");
                ret.type = I_CONST;
                ret.data.idata = left.data.idata % right.data.idata;
            }
            else{
		memcpy(&savebuf, buf, 256);
		printf("\n|-----------------------------------------------|\n");
                printf("| Error found in line %d:%s\n", yylineno+1, savebuf);
                printf("| Modulo operator with floating point operands.");
                printf("\n|-----------------------------------------------|\n\n");
		memset(&savebuf, '\0', 256);
                ERROR = 1;
                ret.type = -1;
            }
            break;
    }
    return ret;
}

void assign_expr(char* id, INT_FLOAT Val){
     Variable* v = lookup_symbol(CUR_TABLE, id);
     if(v == NULL){
        print_undeclaredV();
    }
     else{
        def_type_trans(v->Val, Val);
        v->Val = val_assign(v->Val.type, &Val.data, v->Val.iidx);
    }
}

void assign_id(char* id, int op, INT_FLOAT expr){
    INT_FLOAT left = get_id(id);
    op_assign(left, expr);
    INT_FLOAT Val = alu(left, op, expr);
    assign_expr(id, Val);
    print_var(id);
}

void print_var(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v->Val.type == I_CONST) fprintf(file, "\tistore %d\n", v->iidx);
    else if(v->Val.type == F_CONST) fprintf(file, "\tfstore %d\n", v->iidx);
    else fprintf(file, "\tastore %d\n", v->iidx);
}

void print_load(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    print_type(v->Val.type);
    fprintf(file, "load %d\n", v->iidx);
}

void print_store(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    print_type(v->Val.type);
    fprintf(file, "store %d\n", v->iidx);
}

void alu_type_trans(INT_FLOAT left, INT_FLOAT right){
    if((left.type == F_CONST)&&(right.type == I_CONST))
        fprintf(file, "\ti2f\n\tf");
    else if((left.type == I_CONST)&&(right.type == F_CONST))
        fprintf(file, "\tfstore %d\n\ti2f\n\tfload %d\n\tf", var_idx, var_idx);
    else if((left.type == I_CONST)&&(right.type == I_CONST))
        fprintf(file, "\ti");
    else if((left.type == F_CONST)&&(right.type == F_CONST))
        fprintf(file, "\tf");
    else 
	fprintf(file, "\ta");
}

void op_assign(INT_FLOAT left, INT_FLOAT right){
    print_type(right.type); 
    fprintf(file, "store %d\n", var_idx);
    print_type(left.type); 
    fprintf(file, "load %d\n", left.iidx);
    print_type(right.type); 
    fprintf(file, "load %d\n", var_idx);
}

int bool_handler(INT_FLOAT left, int op, INT_FLOAT right){
    //INT_FLOAT ret;
    if((left.type == F_CONST) || (right.type == F_CONST)){
        alu_type_trans(left, right);
        fprintf(file, "cmpl\n");
    }
    else{
        alu_type_trans(left, right);
        fprintf(file, "sub\n");
    }
    return op;
}

void print_label(char* label_name){
    if(label_name == "LABEL_FALSE") fprintf(file, "\tgoto LABEL_BEGIN\n");
    else if(label_name != "LABEL_BEGIN" && label_name != "LABEL_TRUE")
    	fprintf(file, "\tgoto EXIT_0\n");
    fprintf(file, "%s:\n", label_name);
}

void print_jump(int op, char* label_name){
    switch(op){
        case AND:
            break;
        case OR:
            break;
        case EQ:
	    fprintf(file, "\tifeq %s\n", label_name);
            break;
        case NE:
	    fprintf(file, "\tifne %s\n", label_name);
            break;
        case LT:
	    fprintf(file, "\tiflt %s\n", label_name);
            break;
        case LTE:
	    fprintf(file, "\tifle %s\n", label_name);
            break;
        case MT:
	    fprintf(file, "\tifgt %s\n", label_name);
            break;
        case MTE:
	    fprintf(file, "\tifge %s\n", label_name);
            break;
        default:
            fprintf(file, "\tgoto %s\n", label_name);
            break;
    }
}
