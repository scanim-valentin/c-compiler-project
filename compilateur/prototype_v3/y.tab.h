/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tDeclareInt = 258,             /* tDeclareInt  */
    tDeclareConstInt = 259,        /* tDeclareConstInt  */
    tOpeningBracket = 260,         /* tOpeningBracket  */
    tClosingBracket = 261,         /* tClosingBracket  */
    tWhile = 262,                  /* tWhile  */
    tElse = 263,                   /* tElse  */
    tIf = 264,                     /* tIf  */
    tMain = 265,                   /* tMain  */
    tPlus = 266,                   /* tPlus  */
    tMinus = 267,                  /* tMinus  */
    tMult = 268,                   /* tMult  */
    tDiv = 269,                    /* tDiv  */
    tSup = 270,                    /* tSup  */
    tInf = 271,                    /* tInf  */
    tEqual = 272,                  /* tEqual  */
    tAssign = 273,                 /* tAssign  */
    tOpeningParenthesis = 274,     /* tOpeningParenthesis  */
    tClosingParenthesis = 275,     /* tClosingParenthesis  */
    tNewline = 276,                /* tNewline  */
    tPointVirgule = 277,           /* tPointVirgule  */
    tVirgule = 278,                /* tVirgule  */
    tPrintf = 279,                 /* tPrintf  */
    tValueInt = 280,               /* tValueInt  */
    tVarName = 281,                /* tVarName  */
    tValueExp = 282                /* tValueExp  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tDeclareInt 258
#define tDeclareConstInt 259
#define tOpeningBracket 260
#define tClosingBracket 261
#define tWhile 262
#define tElse 263
#define tIf 264
#define tMain 265
#define tPlus 266
#define tMinus 267
#define tMult 268
#define tDiv 269
#define tSup 270
#define tInf 271
#define tEqual 272
#define tAssign 273
#define tOpeningParenthesis 274
#define tClosingParenthesis 275
#define tNewline 276
#define tPointVirgule 277
#define tVirgule 278
#define tPrintf 279
#define tValueInt 280
#define tVarName 281
#define tValueExp 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "compilateur.y"
 int nb; char * var; double nb_exp; 

#line 124 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
