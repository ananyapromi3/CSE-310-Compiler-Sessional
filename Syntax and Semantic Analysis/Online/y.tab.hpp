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
     LOOP = 260,
     IF = 261,
     FOR = 262,
     WHILE = 263,
     DO = 264,
     BREAK = 265,
     CONTINUE = 266,
     RETURN = 267,
     VOID = 268,
     SWITCH = 269,
     CASE = 270,
     DEFAULT = 271,
     PRINTLN = 272,
     ADDOP = 273,
     MULOP = 274,
     INCOP = 275,
     RELOP = 276,
     ASSIGNOP = 277,
     LOGICOP = 278,
     BITOP = 279,
     NOT = 280,
     INT = 281,
     CHAR = 282,
     FLOAT = 283,
     DOUBLE = 284,
     ID = 285,
     NEWLINE = 286,
     LPAREN = 287,
     LCURL = 288,
     RCURL = 289,
     LSQUARE = 290,
     RSQUARE = 291,
     COMMA = 292,
     SEMICOLON = 293,
     DECOP = 294,
     CONST_CHAR = 295,
     CONST_FLOAT = 296,
     CONST_INT = 297
   };
#endif
/* Tokens.  */
#define RPAREN 258
#define ELSE 259
#define LOOP 260
#define IF 261
#define FOR 262
#define WHILE 263
#define DO 264
#define BREAK 265
#define CONTINUE 266
#define RETURN 267
#define VOID 268
#define SWITCH 269
#define CASE 270
#define DEFAULT 271
#define PRINTLN 272
#define ADDOP 273
#define MULOP 274
#define INCOP 275
#define RELOP 276
#define ASSIGNOP 277
#define LOGICOP 278
#define BITOP 279
#define NOT 280
#define INT 281
#define CHAR 282
#define FLOAT 283
#define DOUBLE 284
#define ID 285
#define NEWLINE 286
#define LPAREN 287
#define LCURL 288
#define RCURL 289
#define LSQUARE 290
#define RSQUARE 291
#define COMMA 292
#define SEMICOLON 293
#define DECOP 294
#define CONST_CHAR 295
#define CONST_FLOAT 296
#define CONST_INT 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "2005079.y"
{
    SymbolInfo* symbolInfo; 
}
/* Line 1529 of yacc.c.  */
#line 137 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

