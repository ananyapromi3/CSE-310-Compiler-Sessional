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
#line 214 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 227 "y.tab.cpp"

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
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNRULES -- Number of states.  */
#define YYNSTATES  136

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

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
      35,    36,    37,    38,    39,    40,    41
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
     136,   138,   146,   152,   160,   166,   172,   176,   178,   181,
     184,   186,   191,   193,   197,   199,   203,   205,   209,   211,
     215,   217,   221,   224,   227,   229,   231,   236,   240,   242,
     244,   247,   250,   252,   253,   257
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    44,    45,    -1,    45,    -1,
      55,    -1,    46,    -1,    47,    -1,     1,    -1,    56,    29,
      31,    51,     3,    37,    -1,    56,    29,    31,     3,    37,
      -1,    56,    29,    31,     1,     3,    37,    -1,    -1,    56,
      29,    31,    51,     3,    48,    52,    -1,    -1,    56,    29,
      31,     3,    49,    52,    -1,    -1,    56,    29,    31,    51,
       1,     3,    50,    52,    -1,    51,    36,    56,    29,    -1,
      51,    36,    56,    -1,    56,    29,    -1,    56,    -1,    -1,
      32,    53,    58,    33,    -1,    -1,    32,    54,    33,    -1,
      56,    57,    37,    -1,    56,    57,     1,    37,    -1,    56,
       1,    37,    -1,    25,    -1,    27,    -1,    12,    -1,    57,
      36,    29,    -1,    57,    36,    29,    34,    41,    35,    -1,
      29,    -1,    29,    34,    41,    35,    -1,    59,    -1,    58,
      59,    -1,    55,    -1,    60,    -1,    52,    -1,     6,    31,
      60,    60,    62,     3,    59,    -1,     5,    31,    62,     3,
      59,    -1,     5,    31,    62,     3,    59,     4,    59,    -1,
       7,    31,    62,     3,    59,    -1,    16,    31,    29,     3,
      37,    -1,    11,    62,    37,    -1,    37,    -1,    62,    37,
      -1,     1,    37,    -1,    29,    -1,    29,    34,    62,    35,
      -1,    63,    -1,    61,    21,    63,    -1,    64,    -1,    64,
      22,    64,    -1,    65,    -1,    65,    20,    65,    -1,    66,
      -1,    65,    17,    66,    -1,    67,    -1,    66,    18,    67,
      -1,    17,    67,    -1,    24,    67,    -1,    68,    -1,    61,
      -1,    29,    31,    69,     3,    -1,    31,    62,     3,    -1,
      41,    -1,    40,    -1,    61,    19,    -1,    61,    38,    -1,
      70,    -1,    -1,    70,    36,    63,    -1,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    53,    61,    70,    77,    84,    92,    99,
     122,   140,   162,   161,   201,   200,   231,   230,   265,   282,
     298,   309,   322,   321,   347,   346,   372,   401,   430,   441,
     449,   457,   467,   482,   500,   509,   523,   530,   541,   548,
     555,   562,   575,   586,   599,   610,   621,   632,   639,   647,
     657,   679,   714,   723,   753,   763,   788,   798,   823,   833,
     862,   872,   911,   933,   955,   967,   976,  1017,  1027,  1036,
    1045,  1063,  1083,  1095,  1101,  1115
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "RPAREN", "ELSE", "IF", "FOR", "WHILE",
  "DO", "BREAK", "CONTINUE", "RETURN", "VOID", "SWITCH", "CASE", "DEFAULT",
  "PRINTLN", "ADDOP", "MULOP", "INCOP", "RELOP", "ASSIGNOP", "LOGICOP",
  "BITOP", "NOT", "INT", "CHAR", "FLOAT", "DOUBLE", "ID", "NEWLINE",
  "LPAREN", "LCURL", "RCURL", "LSQUARE", "RSQUARE", "COMMA", "SEMICOLON",
  "DECOP", "CONST_CHAR", "CONST_FLOAT", "CONST_INT", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "@1", "@2",
  "@3", "parameter_list", "compound_statement", "@4", "@5",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", 0
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
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    46,
      46,    46,    48,    47,    49,    47,    50,    47,    51,    51,
      51,    51,    53,    52,    54,    52,    55,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       5,     6,     0,     7,     0,     6,     0,     8,     4,     3,
       2,     1,     0,     4,     0,     3,     3,     4,     3,     1,
       1,     1,     3,     6,     1,     4,     1,     2,     1,     1,
       1,     7,     5,     7,     5,     5,     3,     1,     2,     2,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     2,     2,     1,     1,     4,     3,     1,     1,
       2,     2,     1,     0,     3,     1
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
       0,    50,     0,    47,    69,    68,    40,    38,     0,     0,
      36,    39,    65,     0,    52,    54,    56,    58,    60,    64,
      25,    17,    49,     0,     0,     0,     0,     0,    65,    62,
      63,    73,     0,     0,    34,    23,    37,    70,     0,    71,
      48,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      75,     0,    72,     0,    67,    53,    55,    59,    57,    61,
       0,     0,     0,     0,    66,     0,    51,    42,     0,    44,
      45,    74,     0,     0,    43,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    44,    32,    49,    25,
      66,    47,    48,    67,    68,    16,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,   111,   112
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
     106,   -74,   -74,   -74,   -74,    20,    94,   -74,   -74,   -74,
     -74,    11,   -74,   -74,   -13,   -15,    10,   -74,   112,   -11,
      -3,     6,   -74,    23,    25,     1,    28,    35,   -74,    37,
      41,   -74,    50,    80,    61,    36,   -74,   -74,    58,   -74,
      72,   -74,   -74,   -74,    50,    79,    76,    85,    90,    50,
     -74,   -74,   -74,    91,    98,    99,   105,   118,   107,   118,
     118,    53,   118,   -74,   -74,   -74,   -74,   -74,    12,    48,
     -74,   -74,    55,   104,   -74,   123,    83,   128,   -74,   -74,
     -74,   -74,   -74,   118,   103,   118,   111,   121,   -10,   -74,
     -74,   118,   118,   148,   119,   -74,   -74,   -74,   118,   -74,
     -74,   118,   118,   118,   118,   149,   103,   151,   -74,   152,
     -74,   153,   124,   122,   -74,   -74,   -74,   128,   144,   -74,
      85,   118,    85,   125,   -74,   118,   -74,   159,   161,   -74,
     -74,   -74,    85,    85,   -74,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   160,   -74,   -74,   -74,   -74,   -74,   -74,
     -22,   -74,   -74,    17,    15,   -74,   -74,   -64,   -70,   -59,
     -54,   -73,    64,    65,    67,   -53,   -74,   -74,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -25
static const yytype_int16 yytable[] =
{
      88,    88,    33,    86,    34,    96,    89,    90,    93,    97,
      41,    20,    14,    14,   106,    11,    18,    10,   110,    19,
      12,    11,    50,    10,    17,   115,    30,    81,    99,   105,
      27,   107,    88,    26,    28,    29,   121,    35,   113,    88,
      15,    94,    88,    88,    88,    88,    21,    22,     2,    53,
      45,   119,   131,    54,    55,    56,   127,    36,   129,    57,
       2,     3,    31,     4,    58,    59,    88,   128,   134,   135,
      37,    38,    60,     3,    97,     4,    98,    61,    39,    62,
      40,    95,    40,    42,    91,    63,    53,    92,    64,    65,
      54,    55,    56,    99,    -2,     1,    57,     2,    43,    46,
     102,    58,    59,   103,    53,   -24,     2,     1,    51,    60,
       3,    52,     4,    23,    61,    24,    62,    40,     2,     3,
      59,     4,    63,    80,     2,    64,    65,    60,    82,    83,
      84,     3,    61,     4,    62,    59,    85,     3,    87,     4,
      63,   100,    60,    64,    65,   101,   104,    61,   108,    62,
     109,   114,   120,    19,   122,   123,   124,   126,    64,    65,
     125,   102,   130,   132,   133,   116,    13,     0,   118,   117
};

static const yytype_int16 yycheck[] =
{
      59,    60,     1,    57,     3,    69,    59,    60,    62,    19,
      32,     1,     1,     1,    84,     0,    31,     0,    91,    34,
       0,     6,    44,     6,    37,    98,     3,    49,    38,    83,
      41,    85,    91,    18,    37,    29,   106,    36,    92,    98,
      29,    29,   101,   102,   103,   104,    36,    37,    12,     1,
      35,   104,   125,     5,     6,     7,   120,    29,   122,    11,
      12,    25,    37,    27,    16,    17,   125,   121,   132,   133,
      35,    34,    24,    25,    19,    27,    21,    29,    37,    31,
      32,    33,    32,     3,    31,    37,     1,    34,    40,    41,
       5,     6,     7,    38,     0,     1,    11,    12,    37,    41,
      17,    16,    17,    20,     1,    33,    12,     1,    29,    24,
      25,    35,    27,     1,    29,     3,    31,    32,    12,    25,
      17,    27,    37,    33,    12,    40,    41,    24,    37,    31,
      31,    25,    29,    27,    31,    17,    31,    25,    31,    27,
      37,    37,    24,    40,    41,    22,    18,    29,    37,    31,
      29,     3,     3,    34,     3,     3,     3,    35,    40,    41,
      36,    17,    37,     4,     3,   101,     6,    -1,   103,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    12,    25,    27,    43,    44,    45,    46,    47,
      55,    56,     0,    45,     1,    29,    57,    37,    31,    34,
       1,    36,    37,     1,     3,    51,    56,    41,    37,    29,
       3,    37,    49,     1,     3,    36,    29,    35,    34,    37,
      32,    52,     3,    37,    48,    56,    41,    53,    54,    50,
      52,    29,    35,     1,     5,     6,     7,    11,    16,    17,
      24,    29,    31,    37,    40,    41,    52,    55,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      33,    52,    37,    31,    31,    31,    62,    31,    61,    67,
      67,    31,    34,    62,    29,    33,    59,    19,    21,    38,
      37,    22,    17,    20,    18,    62,    60,    62,    37,    29,
      63,    69,    70,    62,     3,    63,    64,    66,    65,    67,
       3,    60,     3,     3,     3,    36,    35,    59,    62,    59,
      37,    63,     4,     3,    59,    59
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

  case 46:
#line 622 "2005079.y"
    {
		logout << "statement : RETURN expression SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "statement", (yyvsp[(1) - (3)].symbolInfo)->getLineStart(), (yyvsp[(3) - (3)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("statement : RETURN expression SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (3)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(3) - (3)].symbolInfo));
	}
    break;

  case 47:
#line 633 "2005079.y"
    {
		logout << "expression_statement : SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "expression_statement", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression_statement : SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
	}
    break;

  case 48:
#line 640 "2005079.y"
    {
		logout << "expression_statement : expression SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "expression_statement", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 49:
#line 648 "2005079.y"
    {
		logout << "expression_statement : expression SEMICOLON\n";	
		(yyval.symbolInfo) = new SymbolInfo("", "expression_statement", (yyvsp[(1) - (2)].symbolInfo)->getLineStart(), (yyvsp[(2) - (2)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression_statement : expression SEMICOLON");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (2)].symbolInfo));
		(yyval.symbolInfo)->addChild((yyvsp[(2) - (2)].symbolInfo));
	}
    break;

  case 50:
#line 658 "2005079.y"
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

  case 51:
#line 680 "2005079.y"
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

  case 52:
#line 715 "2005079.y"
    {
		logout << "expression : logic_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "expression", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("expression : logic_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 53:
#line 724 "2005079.y"
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

  case 54:
#line 754 "2005079.y"
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

  case 55:
#line 764 "2005079.y"
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

  case 56:
#line 789 "2005079.y"
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

  case 57:
#line 799 "2005079.y"
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

  case 58:
#line 824 "2005079.y"
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

  case 59:
#line 834 "2005079.y"
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

  case 60:
#line 863 "2005079.y"
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

  case 61:
#line 873 "2005079.y"
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

  case 62:
#line 912 "2005079.y"
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

  case 63:
#line 934 "2005079.y"
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

  case 64:
#line 956 "2005079.y"
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

  case 65:
#line 968 "2005079.y"
    {
		logout << "factor : variable\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : variable");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType((yyvsp[(1) - (1)].symbolInfo)->getDataType());
		(yyval.symbolInfo)->setSymbolType((yyvsp[(1) - (1)].symbolInfo)->getSymbolType());
	}
    break;

  case 66:
#line 977 "2005079.y"
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

  case 67:
#line 1018 "2005079.y"
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

  case 68:
#line 1028 "2005079.y"
    {
		logout << "factor : CONST_INT\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : CONST_INT");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("INT");
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
	}
    break;

  case 69:
#line 1037 "2005079.y"
    {
		logout << "factor : CONST_FLOAT\n";
		(yyval.symbolInfo) = new SymbolInfo("", "factor", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("factor : CONST_FLOAT");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->setDataType("FLOAT");
		(yyval.symbolInfo)->setValue((yyvsp[(1) - (1)].symbolInfo)->getValue());
	}
    break;

  case 70:
#line 1046 "2005079.y"
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

  case 71:
#line 1064 "2005079.y"
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

  case 72:
#line 1084 "2005079.y"
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

  case 73:
#line 1095 "2005079.y"
    {
		(yyval.symbolInfo) = new SymbolInfo("", "argument_list", line_count, line_count);
	}
    break;

  case 74:
#line 1102 "2005079.y"
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

  case 75:
#line 1116 "2005079.y"
    {
		logout << "arguments : logic_expression\n";
		(yyval.symbolInfo) = new SymbolInfo("", "arguments", (yyvsp[(1) - (1)].symbolInfo)->getLineStart(), (yyvsp[(1) - (1)].symbolInfo)->getLineEnd());
		(yyval.symbolInfo)->setRule("arguments : logic_expression");
		(yyval.symbolInfo)->addChild((yyvsp[(1) - (1)].symbolInfo));
		(yyval.symbolInfo)->addItem((yyvsp[(1) - (1)].symbolInfo));
	}
    break;


/* Line 1267 of yacc.c.  */
#line 2806 "y.tab.cpp"
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


#line 1124 "2005079.y"

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



