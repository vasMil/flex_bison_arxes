/* A Bison parser, made by GNU Bison 3.7.6.  */

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    PROG = 258,                    /* PROG  */
    STRUCT = 259,                  /* STRUCT  */
    ESTRUCT = 260,                 /* ESTRUCT  */
    TYPEDEF = 261,                 /* TYPEDEF  */
    FUNC = 262,                    /* FUNC  */
    ENDFUNC = 263,                 /* ENDFUNC  */
    SMAIN = 264,                   /* SMAIN  */
    EMAIN = 265,                   /* EMAIN  */
    VARS = 266,                    /* VARS  */
    CHAR = 267,                    /* CHAR  */
    INT = 268,                     /* INT  */
    WHILE = 269,                   /* WHILE  */
    EWHILE = 270,                  /* EWHILE  */
    FOR = 271,                     /* FOR  */
    TO = 272,                      /* TO  */
    STEP = 273,                    /* STEP  */
    EFOR = 274,                    /* EFOR  */
    IF = 275,                      /* IF  */
    THEN = 276,                    /* THEN  */
    ELSEIF = 277,                  /* ELSEIF  */
    ELSE = 278,                    /* ELSE  */
    ENDIF = 279,                   /* ENDIF  */
    SWITCH = 280,                  /* SWITCH  */
    CASE = 281,                    /* CASE  */
    DEFAULT = 282,                 /* DEFAULT  */
    ESWITCH = 283,                 /* ESWITCH  */
    PRINT = 284,                   /* PRINT  */
    BREAK = 285,                   /* BREAK  */
    EOL = 286,                     /* EOL  */
    RET = 287,                     /* RET  */
    COMMENT = 288,                 /* COMMENT  */
    OP = 289,                      /* OP  */
    CP = 290,                      /* CP  */
    OB = 291,                      /* OB  */
    CB = 292,                      /* CB  */
    ADD = 293,                     /* ADD  */
    SUB = 294,                     /* SUB  */
    MUL = 295,                     /* MUL  */
    DIV = 296,                     /* DIV  */
    POW = 297,                     /* POW  */
    COMMA = 298,                   /* COMMA  */
    SEMIC = 299,                   /* SEMIC  */
    EQS = 300,                     /* EQS  */
    COMP_OPER = 301,               /* COMP_OPER  */
    LOG_OPER = 302,                /* LOG_OPER  */
    COLON_EQ = 303,                /* COLON_EQ  */
    COLON = 304,                   /* COLON  */
    POS_NUM = 305,                 /* POS_NUM  */
    BOOL = 306,                    /* BOOL  */
    ALPHA = 307,                   /* ALPHA  */
    UNDER = 308,                   /* UNDER  */
    ANU = 309,                     /* ANU  */
    SAU = 310,                     /* SAU  */
    STR = 311,                     /* STR  */
    FLOAT = 312                    /* FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 100 "parser.y"
 
	char str[50];
	int ival;

#line 126 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
