/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 108 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char* string;
    bool b_val;
    INT_FLOAT if_val;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
