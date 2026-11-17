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

#ifndef YY_YY_POEMIA_TAB_H_INCLUDED
# define YY_YY_POEMIA_TAB_H_INCLUDED
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
    TITLE = 258,                   /* TITLE  */
    NEWLINE = 259,                 /* NEWLINE  */
    BY = 260,                      /* BY  */
    AUTHOR = 261,                  /* AUTHOR  */
    DECL_KW = 262,                 /* DECL_KW  */
    COMMA_SP = 263,                /* COMMA_SP  */
    TYPE_INT = 264,                /* TYPE_INT  */
    TYPE_QUEUE = 265,              /* TYPE_QUEUE  */
    ASSIGN_KW = 266,               /* ASSIGN_KW  */
    ASSIGN_MID = 267,              /* ASSIGN_MID  */
    IDENTIFIER = 268,              /* IDENTIFIER  */
    INT_CONST = 269,               /* INT_CONST  */
    STRING_CONST = 270,            /* STRING_CONST  */
    OP_PLUS = 271,                 /* OP_PLUS  */
    OP_MINUS = 272,                /* OP_MINUS  */
    OP_TIMES = 273,                /* OP_TIMES  */
    OP_DIV = 274,                  /* OP_DIV  */
    LPAREN = 275,                  /* LPAREN  */
    RPAREN = 276,                  /* RPAREN  */
    CMP_GT = 277,                  /* CMP_GT  */
    CMP_GE = 278,                  /* CMP_GE  */
    CMP_LT = 279,                  /* CMP_LT  */
    CMP_LE = 280,                  /* CMP_LE  */
    CMP_EQ = 281,                  /* CMP_EQ  */
    CMP_NE = 282,                  /* CMP_NE  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    BOOL_TRUE = 285,               /* BOOL_TRUE  */
    BOOL_FALSE = 286,              /* BOOL_FALSE  */
    IF_START = 287,                /* IF_START  */
    IF_OPEN = 288,                 /* IF_OPEN  */
    IF_CONT = 289,                 /* IF_CONT  */
    COMMA_NL = 290,                /* COMMA_NL  */
    IF_THEN = 291,                 /* IF_THEN  */
    ELSE_KW = 292,                 /* ELSE_KW  */
    DOT = 293,                     /* DOT  */
    QUOTE_END = 294,               /* QUOTE_END  */
    REPEAT_START = 295,            /* REPEAT_START  */
    REPEAT_COLON = 296,            /* REPEAT_COLON  */
    REPEAT_END = 297,              /* REPEAT_END  */
    WORM_PUSH_START = 298,         /* WORM_PUSH_START  */
    WORM_PUSH_VERB = 299,          /* WORM_PUSH_VERB  */
    WORM_PUSH_PREFIX = 300,        /* WORM_PUSH_PREFIX  */
    WORM_PUSH_BY = 301,            /* WORM_PUSH_BY  */
    WORM_POP_VERB = 302,           /* WORM_POP_VERB  */
    WORM_POP_OBJ = 303,            /* WORM_POP_OBJ  */
    WORM_TOP = 304,                /* WORM_TOP  */
    WORM_CLEAR_START = 305,        /* WORM_CLEAR_START  */
    WORM_CLEAR_END = 306,          /* WORM_CLEAR_END  */
    WORM_EMPTY = 307,              /* WORM_EMPTY  */
    READ_START = 308,              /* READ_START  */
    READ_END = 309,                /* READ_END  */
    PRINT_KW = 310,                /* PRINT_KW  */
    PRINT_MESSAGE = 311,           /* PRINT_MESSAGE  */
    PRINT_OF = 312                 /* PRINT_OF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_POEMIA_TAB_H_INCLUDED  */
