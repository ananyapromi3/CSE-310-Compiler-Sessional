/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RPAREN = 258,
     ELSE = 259,
     IF = 260,
     FOR = 261,
     WHILE = 262,
     DO = 263,
     BREAK = 264,
     CONTINUE = 265,
     RETURN = 266,
     VOID = 267,
     SWITCH = 268,
     CASE = 269,
     DEFAULT = 270,
     PRINTLN = 271,
     ADDOP = 272,
     MULOP = 273,
     INCOP = 274,
     RELOP = 275,
     ASSIGNOP = 276,
     LOGICOP = 277,
     BITOP = 278,
     NOT = 279,
     INT = 280,
     CHAR = 281,
     FLOAT = 282,
     DOUBLE = 283,
     ID = 284,
     NEWLINE = 285,
     LPAREN = 286,
     LCURL = 287,
     RCURL = 288,
     LSQUARE = 289,
     RSQUARE = 290,
     COMMA = 291,
     SEMICOLON = 292,
     DECOP = 293,
     CONST_CHAR = 294,
     CONST_FLOAT = 295,
     CONST_INT = 296
   };
#endif
/* Tokens.  */
#define RPAREN 258
#define ELSE 259
#define IF 260
#define FOR 261
#define WHILE 262
#define DO 263
#define BREAK 264
#define CONTINUE 265
#define RETURN 266
#define VOID 267
#define SWITCH 268
#define CASE 269
#define DEFAULT 270
#define PRINTLN 271
#define ADDOP 272
#define MULOP 273
#define INCOP 274
#define RELOP 275
#define ASSIGNOP 276
#define LOGICOP 277
#define BITOP 278
#define NOT 279
#define INT 280
#define CHAR 281
#define FLOAT 282
#define DOUBLE 283
#define ID 284
#define NEWLINE 285
#define LPAREN 286
#define LCURL 287
#define RCURL 288
#define LSQUARE 289
#define RSQUARE 290
#define COMMA 291
#define SEMICOLON 292
#define DECOP 293
#define CONST_CHAR 294
#define CONST_FLOAT 295
#define CONST_INT 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "2005079.y"
{
    SymbolInfo* symbolInfo; 
}
/* Line 1529 of yacc.c.  */
#line 135 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

