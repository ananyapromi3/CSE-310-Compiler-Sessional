/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "2005079.y"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <cassert>
#include <fstream>
#include "2005079_SymbolTable.h"
#define BUCKET_SIZE 11
using namespace std;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
SymbolTable *symbolTable;
vector<SymbolInfo *> tempParamList;
int temp_line = 0;
ofstream parseout;
ofstream logout;
ofstream errorout;
extern int line_count;
extern int error_count;
void yyerror(char *s) 
{
	errorout << "Line# " << line_count << ": " << s << "\n";
	logout << "Error at line no " << line_count << " : syntax error\n";
	error_count++;
}
void checkFunc(SymbolInfo *typeSpecifier, SymbolInfo *id, SymbolInfo *parameterList) {}
void checkFunc(SymbolInfo *typeSpecifier, SymbolInfo *id) {}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "2005079.y"
{
    SymbolInfo* symbolInfo; 
}
/* Line 193 of yacc.c.  */
#line 216 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 229 "y.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  143

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      25,    31,    38,    39,    47,    48,    55,    56,    65,    70,
      74,    77,    79,    80,    85,    86,    90,    94,    99,   103,
     105,   107,   109,   113,   120,   122,   127,   129,   132,   134,
     136,   138,   146,   152,   160,   166,   174,   180,   184,   186,
     189,   192,   194,   199,   201,   205,   207,   211,   213,   217,
     219,   223,   225,   229,   232,   235,   237,   239,   244,   248,
     250,   252,   255,   258,   260,   261,   265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    45,    46,    -1,    46,    -1,
      56,    -1,    47,    -1,    48,    -1,     1,    -1,    57,    30,
      32,    52,     3,    38,    -1,    57,    30,    32,     3,    38,
      -1,    57,    30,    32,     1,     3,    38,    -1,    -1,    57,
      30,    32,    52,     3,    49,    53,    -1,    -1,    57,    30,
      32,     3,    50,    53,    -1,    -1,    57,    30,    32,    52,
       1,     3,    51,    53,    -1,    52,    37,    57,    30,    -1,
      52,    37,    57,    -1,    57,    30,    -1,    57,    -1,    -1,
      33,    54,    59,    34,    -1,    -1,    33,    55,    34,    -1,
      57,    58,    38,    -1,    57,    58,     1,    38,    -1,    57,
       1,    38,    -1,    26,    -1,    28,    -1,    13,    -1,    58,
      37,    30,    -1,    58,    37,    30,    35,    42,    36,    -1,
      30,    -1,    30,    35,    42,    36,    -1,    60,    -1,    59,
      60,    -1,    56,    -1,    61,    -1,    53,    -1,     7,    32,
      61,    61,    63,     3,    60,    -1,     6,    32,    63,     3,
      60,    -1,     6,    32,    63,     3,    60,     4,    60,    -1,
       8,    32,    63,     3,    60,    -1,     5,    60,     8,    32,
      63,     3,    38,    -1,    17,    32,    30,     3,    38,    -1,
      12,    63,    38,    -1,    38,    -1,    63,    38,    -1,     1,
      38,    -1,    30,    -1,    30,    35,    63,    36,    -1,    64,
      -1,    62,    22,    64,    -1,    65,    -1,    65,    23,    65,
      -1,    66,    -1,    66,    21,    66,    -1,    67,    -1,    66,
      18,    67,    -1,    68,    -1,    67,    19,    68,    -1,    18,
      68,    -1,    25,    68,    -1,    69,    -1,    62,    -1,    30,
      32,    70,     3,    -1,    32,    63,     3,    -1,    42,    -1,
      41,    -1,    62,    20,    -1,    62,    39,    -1,    71,    -1,
      -1,    71,    37,    64,    -1,    64,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    53,    61,    70,    77,    84,    92,    99,
     122,   140,   162,   161,   201,   200,   231,   230,   265,   282,
     298,   309,   322,   321,   347,   346,   372,   401,   430,   441,
     449,   457,   467,   482,   500,   509,   523,   530,   541,   548,
     555,   562,   575,   586,   599,   610,   623,   634,   645,   652,
     660,   670,   692,   727,   736,   766,   776,   801,   811,   836,
     846,   875,   885,   924,   946,   968,   980,   989,  1030,  1040,
    1049,  1058,  1076,  1096,  1108,  1114,  1128
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RPAREN", "ELSE", "LOOP", "IF", "FOR",
  "WHILE", "DO", "BREAK", "CONTINUE", "RETURN", "VOID", "SWITCH", "CASE",
  "DEFAULT", "PRINTLN", "ADDOP", "MULOP", "INCOP", "RELOP", "ASSIGNOP",
  "LOGICOP", "BITOP", "NOT", "INT", "CHAR", "FLOAT", "DOUBLE", "ID",
  "NEWLINE", "LPAREN", "LCURL", "RCURL", "LSQUARE", "RSQUARE", "COMMA",
  "SEMICOLON", "DECOP", "CONST_CHAR", "CONST_FLOAT", "CONST_INT",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "@1", "@2", "@3", "parameter_list",
  "compound_statement", "@4", "@5", "var_declaration", "type_specifier",
  "declaration_list", "statements", "statement", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    47,
      47,    47,    49,    48,    50,    48,    51,    48,    52,    52,
      52,    52,    54,    53,    55,    53,    56,    56,    56,    57,
      57,    57,    58,    58,    58,    58,    59,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       5,     6,     0,     7,     0,     6,     0,     8,     4,     3,
       2,     1,     0,     4,     0,     3,     3,     4,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     1,
       1,     7,     5,     7,     5,     7,     5,     3,     1,     2,
       2,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     2,     2,     1,     1,     4,     3,     1,
       1,     2,     2,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,    31,    29,    30,     0,     0,     4,     6,     7,
       5,     0,     1,     3,     0,    34,     0,    28,     0,     0,
       0,     0,    26,     0,    14,     0,    21,     0,    27,    32,
       0,    10,     0,     0,    12,     0,    20,    35,     0,    11,
      22,    15,    16,     9,     0,    19,     0,     0,     0,     0,
      13,    18,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,    48,    70,    69,    40,    38,     0,
       0,    36,    39,    66,     0,    53,    55,    57,    59,    61,
      65,    25,    17,    50,     0,     0,     0,     0,     0,     0,
      66,    63,    64,    74,     0,     0,    34,    23,    37,    71,
       0,    72,    49,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,    76,     0,    73,     0,    68,    54,    56,
      60,    58,    62,     0,     0,     0,     0,     0,    67,     0,
      52,     0,    42,     0,    44,    46,    75,     0,     0,     0,
      45,    43,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    44,    32,    49,    25,
      67,    47,    48,    68,    69,    16,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   114,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
       6,   -79,   -79,   -79,   -79,    13,    77,   -79,   -79,   -79,
     -79,     8,   -79,   -79,   -21,    26,    17,   -79,   108,   -19,
     -14,    -5,   -79,    28,    25,     7,    39,    38,   -79,    53,
      35,   -79,    56,    90,    57,   113,   -79,   -79,    52,   -79,
      62,   -79,   -79,   -79,    56,    67,    65,   112,    64,    56,
     -79,   -79,   -79,    76,   112,    91,    96,    99,   130,   100,
     130,   130,    30,   130,   -79,   -79,   -79,   -79,   -79,    10,
      74,   -79,   -79,    37,    95,   -79,   120,    46,   116,   -79,
     -79,   -79,   -79,   -79,   138,   130,    11,   130,   109,   119,
      -6,   -79,   -79,   130,   130,   148,   117,   -79,   -79,   -79,
     130,   -79,   -79,   130,   130,   130,   130,   124,   154,    11,
     155,   -79,   156,   -79,   158,   126,   128,   -79,   -79,   -79,
     116,   147,   -79,   130,   112,   130,   112,   129,   -79,   130,
     -79,   163,   164,   166,   -79,   -79,   -79,   132,   112,   112,
     -79,   -79,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   167,   -79,   -79,   -79,   -79,   -79,   -79,
      78,   -79,   -79,    20,    21,   -79,   -79,   -54,   -26,   -58,
     -57,   -78,    71,    70,    72,   -56,   -79,   -79,   -79
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yytype_int16 yytable[] =
{
      84,    88,    90,    90,    91,    92,    95,     1,    33,    14,
      34,    14,    53,    12,    99,   113,    98,    17,    20,     2,
      10,    11,   118,    27,    28,    29,    10,    11,   108,    60,
     110,    30,     3,   101,     4,    90,    61,   116,    15,    26,
      96,    62,    90,    63,    35,    90,    90,    90,    90,    64,
     122,   136,    65,    66,    21,    22,    45,    99,    18,   100,
     109,    19,    93,    31,   104,    94,   131,   105,   133,    36,
     132,    90,   134,    39,    37,    53,   101,    -2,     1,    54,
      55,    56,    57,   125,   141,   142,    58,     2,    38,    40,
       2,    59,    60,    42,    46,    43,   -24,    51,    81,    61,
       3,    52,     4,     3,    62,     4,    63,    40,    97,    23,
      41,    24,    64,    53,    83,    65,    66,    54,    55,    56,
      57,     2,    50,    85,    58,     2,     2,    82,    86,    59,
      60,    87,    89,   102,     3,   106,     4,    61,     3,     3,
       4,     4,    62,   103,    63,    40,   107,   111,    60,   112,
      64,   117,    19,    65,    66,    61,   123,   124,   126,   127,
      62,   128,    63,   129,   130,   104,   137,   135,   138,   139,
     140,    65,    66,    13,   119,   121,   120
};

static const yytype_uint8 yycheck[] =
{
      54,    58,    60,    61,    60,    61,    63,     1,     1,     1,
       3,     1,     1,     0,    20,    93,    70,    38,     1,    13,
       0,     0,   100,    42,    38,    30,     6,     6,    85,    18,
      87,     3,    26,    39,    28,    93,    25,    94,    30,    18,
      30,    30,   100,    32,    37,   103,   104,   105,   106,    38,
     106,   129,    41,    42,    37,    38,    35,    20,    32,    22,
      86,    35,    32,    38,    18,    35,   123,    21,   125,    30,
     124,   129,   126,    38,    36,     1,    39,     0,     1,     5,
       6,     7,     8,   109,   138,   139,    12,    13,    35,    33,
      13,    17,    18,     3,    42,    38,    34,    30,    34,    25,
      26,    36,    28,    26,    30,    28,    32,    33,    34,     1,
      32,     3,    38,     1,    38,    41,    42,     5,     6,     7,
       8,    13,    44,    32,    12,    13,    13,    49,    32,    17,
      18,    32,    32,    38,    26,    19,    28,    25,    26,    26,
      28,    28,    30,    23,    32,    33,     8,    38,    18,    30,
      38,     3,    35,    41,    42,    25,    32,     3,     3,     3,
      30,     3,    32,    37,    36,    18,     3,    38,     4,     3,
      38,    41,    42,     6,   103,   105,   104
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    13,    26,    28,    44,    45,    46,    47,    48,
      56,    57,     0,    46,     1,    30,    58,    38,    32,    35,
       1,    37,    38,     1,     3,    52,    57,    42,    38,    30,
       3,    38,    50,     1,     3,    37,    30,    36,    35,    38,
      33,    53,     3,    38,    49,    57,    42,    54,    55,    51,
      53,    30,    36,     1,     5,     6,     7,     8,    12,    17,
      18,    25,    30,    32,    38,    41,    42,    53,    56,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    34,    53,    38,    60,    32,    32,    32,    63,    32,
      62,    68,    68,    32,    35,    63,    30,    34,    60,    20,
      22,    39,    38,    23,    18,    21,    19,     8,    63,    61,
      63,    38,    30,    64,    70,    71,    63,     3,    64,    65,
      67,    66,    68,    32,     3,    61,     3,     3,     3,    37,
      36,    63,    60,    63,    60,    38,    64,     3,     4,     3,
      38,    60,    60
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 44 "2005079.y"
    {
		logout << "start : program\n";
		(yyval.symbolInfo) = new SymbolInfo("", "start", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("start : program");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->printParseTree(0, parseout);
	}
    break;

  case 3:
#line 54 "2005079.y"
    {
		logout << "program : program unit\n";
		(yyval.symbolInfo) = new SymbolInfo("", "program", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());	
		(yyval.symbolInfo)->setRule("program : program unit");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo)); 
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 4:
#line 62 "2005079.y"
    {
		logout << "program : unit\n";
		(yyval.symbolInfo) = new SymbolInfo("", "program", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("program : unit");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 5:
#line 71 "2005079.y"
    {
		logout << "unit : var_declaration\n";
		(yyval.symbolInfo) = new SymbolInfo("", "unit", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("unit : var_declaration");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 6:
#line 78 "2005079.y"
    {
		logout << "unit : func_declaration\n";
		(yyval.symbolInfo) = new SymbolInfo("", "unit", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("unit : func_declaration");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 7:
#line 85 "2005079.y"
    {
		logout << "unit : func_definition\n";
		(yyval.symbolInfo) = new SymbolInfo("", "unit", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("unit : func_definition");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 8:
#line 93 "2005079.y"
    {
		(yyval.symbolInfo) = new SymbolInfo("", "unit", line_count, line_count);
		(yyval.symbolInfo)->setRule("unit : error");
	}
    break;

  case 9:
#line 100 "2005079.y"
    {
		logout << "func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n";
		(yyval.symbolInfo) = new SymbolInfo("", "func_declaration", (yyvsp[(1) - (6)].symbolInfo)->getLineStart(), (yyvsp[(6) - (6)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (6)].symbolInfo));
		for (auto item: (yyvsp[(4) - (6)].symbolInfo)->getListItem())
		{
			(yyvsp[(2) - (6)].symbolInfo)->addParamFunc(item);
		}
		(yyvsp[(2) - (6)].symbolInfo)->setSymbolType(FUNCTION);
		(yyvsp[(2) - (6)].symbolInfo)->setDataType((yyvsp[(1) - (6)].symbolInfo)->getDataType());
		if(!symbolTable->insert((yyvsp[(2) - (6)].symbolInfo)))
		{
			errorout << "Line# " << line_count << ": Redefinition of parameter \'" << (yyvsp[(2) - (6)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 10:
#line 123 "2005079.y"
    {
		logout << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n";
		(yyval.symbolInfo) = new SymbolInfo("", "func_declaration", (yyvsp[(1) - (5)].symbolInfo)->getLineStart(), (yyvsp[(5) - (5)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (5)].symbolInfo));
		(yyvsp[(2) - (5)].symbolInfo)->setSymbolType(FUNCTION);
		(yyvsp[(2) - (5)].symbolInfo)->setDataType((yyvsp[(1) - (5)].symbolInfo)->getDataType());
		if(!symbolTable->insert((yyvsp[(2) - (5)].symbolInfo)))
		{
			errorout << "Line# " << line_count << ": Redefinition of parameter \'" << (yyvsp[(2) - (5)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 11:
#line 141 "2005079.y"
    {
		logout << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n";
		(yyval.symbolInfo) = new SymbolInfo("", "func_declaration", (yyvsp[(1) - (6)].symbolInfo)->getLineStart(), (yyvsp[(6) - (6)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (6)].symbolInfo));
		(yyvsp[(2) - (6)].symbolInfo)->setSymbolType(FUNCTION);
		(yyvsp[(2) - (6)].symbolInfo)->setDataType((yyvsp[(1) - (6)].symbolInfo)->getDataType());
		if(!symbolTable->insert((yyvsp[(2) - (6)].symbolInfo)))
		{
			errorout << "Line# " << line_count << ": Redefinition of parameter \'" << (yyvsp[(2) - (6)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 12:
#line 162 "2005079.y"
    { 
		for (auto item: (yyvsp[(4) - (5)].symbolInfo)->getListItem())
		{
			(yyvsp[(2) - (5)].symbolInfo)->addParamFunc(item);
		}
		(yyvsp[(2) - (5)].symbolInfo)->setSymbolType(FUNCTION);
		(yyvsp[(2) - (5)].symbolInfo)->setDataType((yyvsp[(1) - (5)].symbolInfo)->getDataType());
		tempParamList.clear();
		temp_line = line_count;
		for (auto item: (yyvsp[(4) - (5)].symbolInfo)->getListItem())
		{
			tempParamList.push_back(item);
		}
		SymbolInfo *temp = symbolTable->lookup((yyvsp[(2) - (5)].symbolInfo)->getName());
		if (temp && temp->getSymbolType() != (yyvsp[(2) - (5)].symbolInfo)->getSymbolType())
		{
			errorout << "Line# " << line_count << ": \'" << (yyvsp[(2) - (5)].symbolInfo)->getName() << "\' redeclared as different kind of symbol\n";
			error_count++;
		}
		else if(temp && (temp->getDataType() != (yyvsp[(2) - (5)].symbolInfo)->getDataType() || temp->getParamFunc().size() != tempParamList.size()))
		{
			errorout << "Line# " << line_count << ": Conflicting types for \'" << (yyvsp[(2) - (5)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 13:
#line 188 "2005079.y"
    {
		logout << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
		(yyval.symbolInfo) = new SymbolInfo("", "func_declaration", (yyvsp[(1) - (7)].symbolInfo)->getLineStart(), (yyvsp[(7) - (7)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(7) - (7)].symbolInfo));
		symbolTable->insert((yyvsp[(2) - (7)].symbolInfo));
	}
    break;

  case 14:
#line 201 "2005079.y"
    {
		(yyvsp[(2) - (4)].symbolInfo)->setSymbolType(FUNCTION);
		(yyvsp[(2) - (4)].symbolInfo)->setDataType((yyvsp[(1) - (4)].symbolInfo)->getDataType());
		tempParamList.clear();
		SymbolInfo *temp = symbolTable->lookup((yyvsp[(2) - (4)].symbolInfo)->getName());
		if (temp && temp->getSymbolType() != (yyvsp[(2) - (4)].symbolInfo)->getSymbolType())
		{
			errorout << "Line# " << line_count << ": \'" << (yyvsp[(2) - (4)].symbolInfo)->getName() << "\' redeclared as different kind of symbol\n";
			error_count++;
		}
		else if(temp && (temp->getDataType() != (yyvsp[(2) - (4)].symbolInfo)->getDataType() || temp->getParamFunc().size()))
		{
			errorout << "Line# " << line_count << ": Conflicting types for \'" << (yyvsp[(2) - (4)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 15:
#line 218 "2005079.y"
    {
		logout << "func_definition : type_specifier ID LPAREN RPAREN compound_statement\n";
		(yyval.symbolInfo) = new SymbolInfo("", "func_declaration", (yyvsp[(1) - (6)].symbolInfo)->getLineStart(), (yyvsp[(6) - (6)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("func_definition : type_specifier ID LPAREN RPAREN compound_statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (6)].symbolInfo));
		symbolTable->insert((yyvsp[(2) - (6)].symbolInfo));
	}
    break;

  case 16:
#line 231 "2005079.y"
    { 
		(yyvsp[(2) - (6)].symbolInfo)->setSymbolType(FUNCTION);
		(yyvsp[(2) - (6)].symbolInfo)->setDataType((yyvsp[(1) - (6)].symbolInfo)->getDataType());
		tempParamList.clear();
		temp_line = line_count;
		for (auto item: (yyvsp[(4) - (6)].symbolInfo)->getListItem())
		{
			tempParamList.push_back(item);
		}
		SymbolInfo *temp = symbolTable->lookup((yyvsp[(2) - (6)].symbolInfo)->getName());
		if (temp && temp->getSymbolType() != (yyvsp[(2) - (6)].symbolInfo)->getSymbolType())
		{
			errorout << "Line# " << line_count << ": \'" << (yyvsp[(2) - (6)].symbolInfo)->getName() << "\' redeclared as different kind of symbol\n";
			error_count++;
		}
		else if(temp && (temp->getDataType() != (yyvsp[(2) - (6)].symbolInfo)->getDataType() || temp->getParamFunc().size()))
		{
			errorout << "Line# " << line_count << ": Conflicting types for \'" << (yyvsp[(2) - (6)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 17:
#line 253 "2005079.y"
    {
		(yyval.symbolInfo) = new SymbolInfo("", "func_declaration", (yyvsp[(1) - (8)].symbolInfo)->getLineStart(), (yyvsp[(8) - (8)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (8)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (8)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (8)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (8)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (8)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(8) - (8)].symbolInfo));
	}
    break;

  case 18:
#line 266 "2005079.y"
    {
		logout << "parameter_list : parameter_list COMMA type_specifier ID\n";
		(yyval.symbolInfo) = new SymbolInfo("", "parameter_list", (yyvsp[(1) - (4)].symbolInfo)->getLineStart(), (yyvsp[(4) - (4)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("parameter_list : parameter_list COMMA type_specifier ID");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (4)].symbolInfo));
		(yyvsp[(4) - (4)].symbolInfo)->setDataType((yyvsp[(3) - (4)].symbolInfo)->getDataType());
		(yyvsp[(4) - (4)].symbolInfo)->setSymbolType(VARIABLE);
		for(auto item: (yyvsp[(1) - (4)].symbolInfo)->getListItem())
		{
			(yyval.symbolInfo)->addItem(item);
		}
		(yyval.symbolInfo)->addItem((yyvsp[(4) - (4)].symbolInfo));
	}
    break;

  case 19:
#line 283 "2005079.y"
    {
		logout << "parameter_list : parameter_list COMMA type_specifier\n";
		(yyval.symbolInfo) = new SymbolInfo("", "parameter_list", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("parameter_list : parameter_list COMMA type_specifier");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		for(auto item: (yyvsp[(1) - (3)].symbolInfo)->getListItem())
		{
			(yyval.symbolInfo)->addItem(item);
		}
		SymbolInfo *temp = new SymbolInfo("NN", "ID", (yyvsp[(3) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		temp->setDataType((yyvsp[(3) - (3)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addItem(temp);
	}
    break;

  case 20:
#line 299 "2005079.y"
    {
		logout << "parameter_list : type_specifier ID\n";
		(yyval.symbolInfo) = new SymbolInfo("", "parameter_list", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("parameter_list : type_specifier ID");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
		(yyvsp[(2) - (2)].symbolInfo)->setDataType((yyvsp[(1) - (2)].symbolInfo)->getDataType());
		(yyvsp[(2) - (2)].symbolInfo)->setSymbolType(VARIABLE);
		(yyval.symbolInfo)->addItem((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 21:
#line 310 "2005079.y"
    {
		logout << "parameter_list : type_specifier\n";
		(yyval.symbolInfo) = new SymbolInfo("", "parameter_list", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("parameter_list : type_specifier");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		SymbolInfo *temp = new SymbolInfo("NN", "ID", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		temp->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->addItem(temp);
	}
    break;

  case 22:
#line 322 "2005079.y"
    {
		symbolTable->enterScope(BUCKET_SIZE);
		for (auto item: tempParamList)
		{
			if(!symbolTable->insert(item))
			{
				errorout << "Line# " << temp_line << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
				break;
			}
		}
	}
    break;

  case 23:
#line 335 "2005079.y"
    {
		logout << "compound_statement : LCURL statements RCURL\n";
		(yyval.symbolInfo) = new SymbolInfo("", "compound_statement", (yyvsp[(1) - (4)].symbolInfo)->getLineStart(), (yyvsp[(4) - (4)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("compound_statement : LCURL statements RCURL");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (4)].symbolInfo));
		symbolTable->printCurrentScope(logout);
		symbolTable->printParentScope(logout);
		symbolTable->exitScope();
	}
    break;

  case 24:
#line 347 "2005079.y"
    {
		symbolTable->enterScope(BUCKET_SIZE);
		for (auto item: tempParamList)
		{
			if(!symbolTable->insert(item))
			{
				errorout << "Line# " << temp_line << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
				break;
			}
		}
	}
    break;

  case 25:
#line 360 "2005079.y"
    {
		logout << "compound_statement : LCURL RCURL\n";
		(yyval.symbolInfo) = new SymbolInfo("", "compound_statement", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("compound_statement : LCURL RCURL");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		symbolTable->printCurrentScope(logout);
		symbolTable->printParentScope(logout);
		symbolTable->exitScope();
	}
    break;

  case 26:
#line 373 "2005079.y"
    {
		logout << "var_declaration : type_specifier declaration_list SEMICOLON\n";
		(yyval.symbolInfo) = new SymbolInfo("", "var_declaration", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("var_declaration : type_specifier declaration_list SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		for(auto item: (yyvsp[(2) - (3)].symbolInfo)->getListItem())
		{
			item->setDataType((yyvsp[(1) - (3)].symbolInfo)->getDataType());
			SymbolInfo *temp = symbolTable->lookup(item->getName());
			if(item->getDataType() == "VOID")
			{
				errorout << "Line# " << item->getLineStart() << ": Variable or field \'" << item->getName() << "\' declared void\n";
				error_count++;
			}
			else if (temp && temp->getDataType() != item->getDataType())
			{
				errorout << "Line# " << item->getLineStart() << ": Conflicting types for\'" << item->getName() << "'\n";
				error_count++;
			}
			else if(!symbolTable->insert(item))
			{
				errorout << "Line# " << item->getLineStart() << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
			}
		}
	}
    break;

  case 27:
#line 402 "2005079.y"
    {
		logout << "var_declaration : type_specifier declaration_list SEMICOLON\n";
		(yyval.symbolInfo) = new SymbolInfo("", "var_declaration", (yyvsp[(1) - (4)].symbolInfo)->getLineStart(), (yyvsp[(3) - (4)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("var_declaration : type_specifier declaration_list SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (4)].symbolInfo));
		for(auto item: (yyvsp[(2) - (4)].symbolInfo)->getListItem())
		{
			item->setDataType((yyvsp[(1) - (4)].symbolInfo)->getDataType());
			SymbolInfo *temp = symbolTable->lookup(item->getName());
			if(item->getDataType() == "VOID")
			{
				errorout << "Line# " << item->getLineStart() << ": Variable or field \'" << item->getName() << "\' declared void\n";
				error_count++;
			}
			else if (temp && temp->getDataType() != item->getDataType())
			{
				errorout << "Line# " << item->getLineStart() << ": Conflicting types for\'" << item->getName() << "'\n";
				error_count++;
			}
			else if(!symbolTable->insert(item))
			{
				errorout << "Line# " << item->getLineStart() << ": Redefinition of parameter \'" << item->getName() << "\'\n";
				error_count++;
			}
		}
	}
    break;

  case 28:
#line 431 "2005079.y"
    {
		logout << "var_declaration : type_specifier declaration_list SEMICOLON\n";
		(yyval.symbolInfo) = new SymbolInfo("", "var_declaration", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("var_declaration : type_specifier declaration_list SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
	}
    break;

  case 29:
#line 442 "2005079.y"
    {
		logout << "type_specifier : INT\n";
		(yyval.symbolInfo) = new SymbolInfo("INT", "type_specifier", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("type_specifier : INT");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("INT");
	}
    break;

  case 30:
#line 450 "2005079.y"
    {
		logout << "type_specifier : FLOAT\n";
		(yyval.symbolInfo) = new SymbolInfo("FLOAT", "type_specifier", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("type_specifier : FLOAT");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("FLOAT");
	}
    break;

  case 31:
#line 458 "2005079.y"
    {
		logout << "type_specifier : VOID\n";
		(yyval.symbolInfo) = new SymbolInfo("VOID", "type_specifier", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("type_specifier : VOID");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("VOID");
	}
    break;

  case 32:
#line 468 "2005079.y"
    {
		logout << "declaration_list : declaration_list COMMA ID\n";
		(yyval.symbolInfo) = new SymbolInfo("", "declaration_list", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("declaration_list : declaration_list COMMA ID");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		for(auto item: (yyvsp[(1) - (3)].symbolInfo)->getListItem())
		{
			(yyval.symbolInfo)->addItem(item);
		}
		(yyval.symbolInfo)->addItem((yyvsp[(3) - (3)].symbolInfo));
		(yyvsp[(3) - (3)].symbolInfo)->setSymbolType(VARIABLE);
	}
    break;

  case 33:
#line 483 "2005079.y"
    {
		logout << "declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE\n";
		(yyval.symbolInfo) = new SymbolInfo("", "declaration_list", (yyvsp[(1) - (6)].symbolInfo)->getLineStart(), (yyvsp[(6) - (6)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("declaration_list : declaration_list COMMA ID LSQUARE CONST_INT RSQUARE");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (6)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (6)].symbolInfo));
		for(auto item: (yyvsp[(1) - (6)].symbolInfo)->getListItem())
		{
			(yyval.symbolInfo)->addItem(item);
		}
		(yyval.symbolInfo)->addItem((yyvsp[(3) - (6)].symbolInfo));
		(yyvsp[(3) - (6)].symbolInfo)->setSymbolType(ARRAY);
	}
    break;

  case 34:
#line 501 "2005079.y"
    {
		logout << "declaration_list : ID\n";
		(yyval.symbolInfo) = new SymbolInfo("", "declaration_list", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("declaration_list : ID");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->addItem((yyvsp[(1) - (1)].symbolInfo));
		(yyvsp[(1) - (1)].symbolInfo)->setSymbolType(VARIABLE);
	}
    break;

  case 35:
#line 510 "2005079.y"
    {
		logout << "declaration_list : ID LSQUARE CONST_INT RSQUARE\n";
		(yyval.symbolInfo) = new SymbolInfo("", "declaration_list", (yyvsp[(1) - (4)].symbolInfo)->getLineStart(), (yyvsp[(4) - (4)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("declaration_list : ID LSQUARE CONST_INT RSQUARE");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (4)].symbolInfo));
		(yyval.symbolInfo)->addItem((yyvsp[(1) - (4)].symbolInfo));
		(yyvsp[(1) - (4)].symbolInfo)->setSymbolType(ARRAY);
	}
    break;

  case 36:
#line 524 "2005079.y"
    {
		logout << "statements : statement\n";
		(yyval.symbolInfo) = new SymbolInfo("", "statements", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statements : statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 37:
#line 531 "2005079.y"
    {
		logout << "statements : statements statement\n";
		(yyval.symbolInfo) = new SymbolInfo("", "statements", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statements : statements statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 38:
#line 542 "2005079.y"
    {
		logout << "statement : var_declaration\n";
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : var_declaration");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));	
	}
    break;

  case 39:
#line 549 "2005079.y"
    {
		logout << "statement : expression_statement\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : expression_statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 40:
#line 556 "2005079.y"
    {
		logout << "statement : compound_statement\n";
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : compound_statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));	
	}
    break;

  case 41:
#line 563 "2005079.y"
    {
		logout << "statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (7)].symbolInfo)->getLineStart(), (yyvsp[(7) - (7)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(7) - (7)].symbolInfo));	
	}
    break;

  case 42:
#line 576 "2005079.y"
    {
		logout << "statement : IF LPAREN expression RPAREN statement\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (5)].symbolInfo)->getLineStart(), (yyvsp[(5) - (5)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : IF LPAREN expression RPAREN statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (5)].symbolInfo));
	}
    break;

  case 43:
#line 587 "2005079.y"
    {
		logout << "statement : IF LPAREN expression RPAREN statement ELSE statement\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (7)].symbolInfo)->getLineStart(), (yyvsp[(7) - (7)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : IF LPAREN expression RPAREN statement ELSE statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(7) - (7)].symbolInfo));
	}
    break;

  case 44:
#line 600 "2005079.y"
    {
		logout << "statement : WHILE LPAREN expression RPAREN statement\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (5)].symbolInfo)->getLineStart(), (yyvsp[(5) - (5)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : WHILE LPAREN expression RPAREN statement");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (5)].symbolInfo));
	}
    break;

  case 45:
#line 611 "2005079.y"
    {
		logout << "statement : LOOP statement WHILE LPAREN expression RPAREN SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (7)].symbolInfo)->getLineStart(), (yyvsp[(7) - (7)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : LOOP statement WHILE LPAREN expression RPAREN SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(6) - (7)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(7) - (7)].symbolInfo));
	}
    break;

  case 46:
#line 624 "2005079.y"
    {
		logout << "statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (5)].symbolInfo)->getLineStart(), (yyvsp[(5) - (5)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (5)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(5) - (5)].symbolInfo));	
	}
    break;

  case 47:
#line 635 "2005079.y"
    {
		logout << "statement : RETURN expression SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : RETURN expression SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
	}
    break;

  case 48:
#line 646 "2005079.y"
    {
		logout << "expression_statement : SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "expression_statement", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression_statement : SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 49:
#line 653 "2005079.y"
    {
		logout << "expression_statement : expression SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "expression_statement", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 50:
#line 661 "2005079.y"
    {
		logout << "expression_statement : expression SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "expression_statement", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 51:
#line 671 "2005079.y"
    {
		logout << "variable : ID\n";
		(yyval.symbolInfo) = new SymbolInfo("", "variable", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("variable : ID");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));	
		SymbolInfo *temp = symbolTable->lookupAll((yyvsp[(1) - (1)].symbolInfo)->getName());
		if(!temp)
		{
			errorout << "Line# " << (yyvsp[(1) - (1)].symbolInfo)->getLineStart() << ": Undeclared variable \'" << (yyvsp[(1) - (1)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setSymbolType(temp->getSymbolType());
			(yyvsp[(1) - (1)].symbolInfo)->setSymbolType(temp->getSymbolType());
			(yyval.symbolInfo)->setDataType(temp->getDataType());
			(yyvsp[(1) - (1)].symbolInfo)->setDataType(temp->getDataType());
			(yyvsp[(1) - (1)].symbolInfo)->setValue(temp->getValue());
			(yyval.symbolInfo)->setValue(temp->getValue());
		}
	}
    break;

  case 52:
#line 693 "2005079.y"
    {
		logout << "variable : ID LSQUARE expression RSQUARE\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "variable", (yyvsp[(1) - (4)].symbolInfo)->getLineStart(), (yyvsp[(4) - (4)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("variable : ID LSQUARE expression RSQUARE");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (4)].symbolInfo));
		SymbolInfo *temp = symbolTable->lookupAll((yyvsp[(1) - (4)].symbolInfo)->getName());
		if((yyvsp[(3) - (4)].symbolInfo)->getDataType() != "INT" && ((yyvsp[(3) - (4)].symbolInfo)->getSymbolType() != ARRAY && (yyvsp[(3) - (4)].symbolInfo)->getSymbolType() != FUNCTION))
		{
			errorout << "Line# " << (yyvsp[(1) - (4)].symbolInfo)->getLineStart() << ": Array subscript is not an integer\n";
			error_count++;
		}
		if(!temp)
		{
			errorout << "Line# " << (yyvsp[(1) - (4)].symbolInfo)->getLineStart() << ": Undeclared variable \'" << (yyvsp[(1) - (4)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
		else if (temp->getSymbolType() != ARRAY)
		{
			errorout << "Line# " << (yyvsp[(1) - (4)].symbolInfo)->getLineStart() << ": \'" << (yyvsp[(1) - (4)].symbolInfo)->getName() << "\' is not an array\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setDataType(temp->getDataType());
			(yyvsp[(1) - (4)].symbolInfo)->setDataType(temp->getDataType());
			(yyval.symbolInfo)->setSymbolType(VARIABLE);
			(yyvsp[(1) - (4)].symbolInfo)->setSymbolType(ARRAY);
		};
	}
    break;

  case 53:
#line 728 "2005079.y"
    {
		logout << "expression : logic_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "expression", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression : logic_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 54:
#line 737 "2005079.y"
    {
		logout << "expression : variable ASSIGNOP logic_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "expression", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression : variable ASSIGNOP logic_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		if((yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == FUNCTION || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "VOID" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setDataType("INT");
		}
		if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "INT" && (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "FLOAT")
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Warning: possible loss of data in assignment of FLOAT to INT\n";
			error_count++;
		}
	}
    break;

  case 55:
#line 767 "2005079.y"
    {
		logout << "logic_expression : rel_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "logic_expression", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("logic_expression : rel_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 56:
#line 777 "2005079.y"
    {
		logout << "logic_expression : rel_expression LOGICOP rel_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "logic_expression", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("logic_expression : rel_expression LOGICOP rel_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		if((yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == FUNCTION || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "VOID" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setDataType("INT");
		}
	}
    break;

  case 57:
#line 802 "2005079.y"
    {
		logout << "rel_expression : simple_expression\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "rel_expression", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("rel_expression : simple_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 58:
#line 812 "2005079.y"
    {
		logout << "rel_expression : simple_expression RELOP simple_expression\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "rel_expression", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(1) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("rel_expression : simple_expression RELOP simple_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		if((yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == FUNCTION || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "VOID" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setDataType("INT");
		}
	}
    break;

  case 59:
#line 837 "2005079.y"
    {
		logout << "simple_expression : term\n";
		(yyval.symbolInfo) = new SymbolInfo("", "simple_expression", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("simple_expression : term");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 60:
#line 847 "2005079.y"
    {
		logout << "simple_expression : simple_expression ADDOP term\n";
		(yyval.symbolInfo) = new SymbolInfo("", "simple_expression", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("simple_expression : simple_expression ADDOP term");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		if((yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == FUNCTION || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "VOID" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "FLOAT" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "FLOAT")
		{
			(yyval.symbolInfo)->setDataType("FLOAT");
		}
		else
		{
			(yyval.symbolInfo)->setDataType("INT");
		}
	}
    break;

  case 61:
#line 876 "2005079.y"
    {
		logout << "term : unary_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "term", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("term : unary_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 62:
#line 886 "2005079.y"
    {
		logout << "term : term MULOP unary_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "term", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("term : term MULOP unary_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		if((yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(3) - (3)].symbolInfo)->getSymbolType() == FUNCTION || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (3)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else if(((yyvsp[(2) - (3)].symbolInfo)->getName() == "%" || (yyvsp[(2) - (3)].symbolInfo)->getName() == "/") && (yyvsp[(3) - (3)].symbolInfo)->getValue() == 0)
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Warning: division by zero\n";
			error_count++;
		}
		else if((yyvsp[(2) - (3)].symbolInfo)->getName() == "%" && ((yyvsp[(3) - (3)].symbolInfo)->getDataType() != "INT" || (yyvsp[(1) - (3)].symbolInfo)->getDataType() != "INT"))
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Operands of modulus must be integers\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "VOID" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (3)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if((yyvsp[(1) - (3)].symbolInfo)->getDataType() == "FLOAT" || (yyvsp[(3) - (3)].symbolInfo)->getDataType() == "FLOAT")
		{
			(yyval.symbolInfo)->setDataType("FLOAT");
		}
		else
		{
			(yyval.symbolInfo)->setDataType("INT");
		}
	}
    break;

  case 63:
#line 925 "2005079.y"
    {
		logout << "unary_expression : ADDOP unary_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "unary_expression", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("unary_expression : ADDOP unary_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
		if((yyvsp[(2) - (2)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (2)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if((yyvsp[(2) - (2)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(2) - (2)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (2)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setDataType((yyvsp[(2) - (2)].symbolInfo)->getDataType());
		}
	}
    break;

  case 64:
#line 947 "2005079.y"
    {
		logout << "unary_expression : NOT unary_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "unary_expression", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("unary_expression : NOT unary_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
		if((yyvsp[(2) - (2)].symbolInfo)->getDataType() == "VOID")
		{
			errorout << "Line# " << (yyvsp[(1) - (2)].symbolInfo)->getLineStart() << ": Void cannot be used in expression\n";
			error_count++;
		}
		else if((yyvsp[(2) - (2)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(2) - (2)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (2)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else
		{
			(yyval.symbolInfo)->setDataType((yyvsp[(2) - (2)].symbolInfo)->getDataType());
		}
	}
    break;

  case 65:
#line 969 "2005079.y"
    {
		logout << "unary_expression : factor\n";
		(yyval.symbolInfo) = new SymbolInfo("", "unary_expression", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("unary_expression : factor");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 66:
#line 981 "2005079.y"
    {
		logout << "factor : variable\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : variable");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 67:
#line 990 "2005079.y"
    {
		logout << "factor : ID LPAREN argument_list RPAREN\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (4)].symbolInfo)->getLineStart(), (yyvsp[(4) - (4)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : ID LPAREN argument_list RPAREN");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (4)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(4) - (4)].symbolInfo));
		SymbolInfo *temp = symbolTable->lookupAll((yyvsp[(1) - (4)].symbolInfo)->getName());
		if (temp && temp->getSymbolType() == FUNCTION)
		{
			(yyval.symbolInfo)->setDataType(temp->getDataType());
			if (temp->getParamFunc().size() > (yyvsp[(3) - (4)].symbolInfo)->getListItem().size())
			{
				errorout << "Line# " << (yyvsp[(1) - (4)].symbolInfo)->getLineStart() << ": Too few arguments to function \'" << temp->getName() << "\'\n";
				error_count++;
			}
			else if (temp->getParamFunc().size() < (yyvsp[(3) - (4)].symbolInfo)->getListItem().size())
			{
				errorout << "Line# " << (yyvsp[(1) - (4)].symbolInfo)->getLineStart() << ": Too many arguments to function \'" << temp->getName() << "\'\n";
				error_count++;
			}
			else 
			{
				for (int i = 0; i < temp->getParamFunc().size(); i++)
				{
					if (temp->getParamFunc()[i]->getDataType() != (yyvsp[(3) - (4)].symbolInfo)->getListItem()[i]->getDataType())
					{
						errorout << "Line# " << (yyvsp[(3) - (4)].symbolInfo)->getListItem()[i]->getLineStart() << ": Type mismatch for argument " << i + 1 << " of \'" << temp->getName() << "\'\n";
						error_count++;
					}
				}
			}
		}
		else 
		{
			errorout << "Line# " << (yyvsp[(1) - (4)].symbolInfo)->getLineStart() << ": Undeclared function \'" << (yyvsp[(1) - (4)].symbolInfo)->getName() << "\'\n";
			error_count++;
		}
	}
    break;

  case 68:
#line 1031 "2005079.y"
    {
		logout << "factor : LPAREN expression RPAREN\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : LPAREN expression RPAREN");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(2) - (3)].symbolInfo)->getDataType());
	}
    break;

  case 69:
#line 1041 "2005079.y"
    {
		logout << "factor : CONST_INT\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : CONST_INT");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("INT");
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
	}
    break;

  case 70:
#line 1050 "2005079.y"
    {
		logout << "factor : CONST_FLOAT\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : CONST_FLOAT");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("FLOAT");
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
	}
    break;

  case 71:
#line 1059 "2005079.y"
    {
		logout << "factor : variable INCOP\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : variable INCOP");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
		if((yyvsp[(1) - (2)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (2)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (2)].symbolInfo)->getLineStart() << ": Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else 
		{
			(yyval.symbolInfo)->setDataType((yyvsp[(1) - (2)].symbolInfo)->getDataType());
			(yyval.symbolInfo)->setValue((yyvsp[(1) - (2)].symbolInfo)->getValue() + 1);
		}
	}
    break;

  case 72:
#line 1077 "2005079.y"
    {
		logout << "factor : variable DECOP\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : variable DECOP");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
		if((yyvsp[(1) - (2)].symbolInfo)->getSymbolType() == ARRAY || (yyvsp[(1) - (2)].symbolInfo)->getSymbolType() == FUNCTION)
		{
			errorout << "Line# " << (yyvsp[(1) - (2)].symbolInfo)->getLineStart() << ": \'" << (yyvsp[(1) - (2)].symbolInfo)->getName() << "\' Cannot perform operation on non-numeric value\n";
			error_count++;
		}
		else 
		{
			(yyval.symbolInfo)->setDataType((yyvsp[(1) - (2)].symbolInfo)->getDataType());
			(yyval.symbolInfo)->setValue((yyvsp[(1) - (2)].symbolInfo)->getValue() - 1);
		}
	}
    break;

  case 73:
#line 1097 "2005079.y"
    {
		logout << "argument_list : arguments\n";
		(yyval.symbolInfo) = new SymbolInfo("", "argument_list", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("argument_list : arguments");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		for (auto item: (yyvsp[(1) - (1)].symbolInfo)->getListItem())
		{
			(yyval.symbolInfo)->addItem(item);
		}
	}
    break;

  case 74:
#line 1108 "2005079.y"
    {
		(yyval.symbolInfo) = new SymbolInfo("", "argument_list", line_count, line_count);
	}
    break;

  case 75:
#line 1115 "2005079.y"
    {
		logout << "arguments : arguments COMMA logic_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "arguments", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("arguments : arguments COMMA logic_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
		for (auto item: (yyvsp[(1) - (3)].symbolInfo)->getListItem())
		{
			(yyval.symbolInfo)->addItem(item);
		}
		(yyval.symbolInfo)->addItem((yyvsp[(3) - (3)].symbolInfo));
	}
    break;

  case 76:
#line 1129 "2005079.y"
    {
		logout << "arguments : logic_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "arguments", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("arguments : logic_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->addItem((yyvsp[(1) - (1)].symbolInfo));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2831 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1137 "2005079.y"

int main(int argc, char *argv[]) {
	if(argc != 2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	FILE *fin = fopen(argv[1], "r");
	if(fin == NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	line_count = 1;
	error_count = 0;
	logout.open("logout.txt");
	errorout.open("error.txt");
	parseout.open("parsetree.txt");
    symbolTable = new SymbolTable(new ScopeTable(BUCKET_SIZE, NULL));
	yyin = fin;
	yyparse();
	fclose(yyin);
	errorout.close();
	logout <<"Total Lines: "<< line_count<<"\n";
	logout <<"Total Errors: "<< error_count<<"\n";
	logout.close();
	parseout.close();
	return 0;
}



