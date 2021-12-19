
/*  A Bison parser, made from finalcompiler.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	ID	257
#define	NUM	258
#define	NUM_C	259
#define	NUM_D	260
#define	INT	261
#define	CHAR	262
#define	DOUBLE	263
#define	BOOL	264
#define	CONST	265
#define	PLUS	266
#define	MINUS	267
#define	TIMES	268
#define	SLASH	269
#define	EQL	270
#define	NEQ	271
#define	LES	272
#define	LEQ	273
#define	GTR	274
#define	GEQ	275
#define	MOD	276
#define	XOR	277
#define	ODD	278
#define	SPLUS	279
#define	SMINUS	280
#define	UMINUS	281
#define	AND	282
#define	OR	283
#define	NOT	284
#define	LPAREN	285
#define	RPAREN	286
#define	LBRACKETS	287
#define	RBRACKETS	288
#define	LBRACE	289
#define	RBRACE	290
#define	COMMA	291
#define	SEMICOLON	292
#define	PERIOD	293
#define	BECOMES	294
#define	COLON	295
#define	MAIN	296
#define	IF	297
#define	ELSE	298
#define	WHILE	299
#define	WRITE	300
#define	READ	301
#define	DO	302
#define	CALL	303
#define	SWITCH	304
#define	CASE	305
#define	DEFAULT	306
#define	BREAK	307
#define	CONTINUE	308
#define	FOR	309
#define	REPEAT	310
#define	UNTIL	311
#define	EXIT	312



#include <stdio.h>   
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "x0code.h"
#include <malloc.h>
void yyerror(char*);
void syntax_error(char* s);
int yylex(void);
FILE *yout;
FILE *yyin;
struct list* array_ids;

typedef union{
char *ident;
int number;
double number_d;
void* ptr;
char *type;
struct databus* db;
} YYSTYPE;
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		202
#define	YYFLAG		-32768
#define	YYNTBASE	59

#define YYTRANSLATE(x) ((unsigned)(x) <= 312 ? yytranslate[x] : 108)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    58
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     2,     3,     4,    15,    18,    19,    26,    33,
    40,    47,    50,    51,    56,    61,    62,    64,    66,    68,
    70,    72,    75,    77,    79,    81,    83,    85,    87,    89,
    91,    93,    95,    97,    99,   101,   104,   107,   110,   111,
   112,   127,   129,   130,   132,   133,   135,   136,   138,   139,
   151,   153,   154,   165,   167,   168,   177,   178,   183,   184,
   185,   186,   196,   200,   204,   209,   210,   215,   219,   222,
   224,   225,   231,   233,   235,   239,   243,   247,   251,   255,
   259,   263,   267,   270,   272,   276,   280,   282,   286,   290,
   294,   298,   301,   305,   308,   311,   314,   317,   320,   322,
   324
};

static const short yyrhs[] = {    -1,
     0,     0,     0,    42,    35,    60,    64,    61,    66,    62,
    71,    63,    36,     0,    64,    65,     0,     0,    11,     7,
     3,    40,     4,    38,     0,    11,     9,     3,    40,     6,
    38,     0,    11,     8,     3,    40,     4,    38,     0,    11,
    10,     3,    40,     4,    38,     0,    66,    67,     0,     0,
    69,     3,    68,    38,     0,    68,    33,     4,    34,     0,
     0,     7,     0,     9,     0,     8,     0,    10,     0,     3,
     0,    71,    72,     0,    72,     0,    89,     0,    93,     0,
    98,     0,    96,     0,    99,     0,   100,     0,    76,     0,
    83,     0,    86,     0,    73,     0,    74,     0,    75,     0,
    58,    38,     0,    53,    38,     0,    54,    38,     0,     0,
     0,    55,    31,    79,    38,   107,    80,    38,   107,    77,
    81,    78,    32,   107,    82,     0,   101,     0,     0,   103,
     0,     0,   101,     0,     0,    72,     0,     0,    48,   107,
    84,    85,    45,   107,    31,   103,    32,    38,   107,     0,
    72,     0,     0,    56,   107,    87,    88,    57,   107,    31,
   103,    32,    38,     0,    72,     0,     0,    43,    31,   101,
    32,   107,    90,    72,    91,     0,     0,    44,   107,    92,
    72,     0,     0,     0,     0,    45,   107,    94,    31,   101,
    32,   107,    95,    72,     0,    46,   101,    38,     0,    46,
    70,    38,     0,    97,    33,   101,    34,     0,     0,    47,
    70,    97,    38,     0,    35,    71,    36,     0,   101,    38,
     0,    38,     0,     0,    70,    97,   102,    40,   101,     0,
   103,     0,   104,     0,   104,    20,   104,     0,   104,    18,
   104,     0,   104,    21,   104,     0,   104,    19,   104,     0,
   104,    16,   104,     0,   104,    17,   104,     0,   104,    28,
   104,     0,   104,    29,   104,     0,    30,   104,     0,   105,
     0,   104,    12,   105,     0,   104,    13,   105,     0,   106,
     0,   105,    14,   106,     0,   105,    15,   106,     0,   105,
    22,   106,     0,   105,    23,   106,     0,    24,   106,     0,
    31,   101,    32,     0,    70,    97,     0,    70,    25,     0,
    70,    26,     0,    25,    70,     0,    26,    70,     0,     4,
     0,     6,     0,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    56,    63,    64,    74,    77,    80,    82,    85,    92,    98,
   104,   112,   116,   119,   141,   148,   154,   156,   157,   158,
   161,   182,   184,   187,   189,   190,   191,   192,   193,   195,
   196,   197,   198,   199,   200,   203,   207,   220,   233,   242,
   245,   268,   270,   273,   275,   278,   280,   283,   287,   295,
   317,   321,   329,   351,   366,   370,   375,   379,   383,   388,
   396,   399,   421,   425,   448,   466,   469,   495,   499,   501,
   504,   515,   523,   526,   528,   531,   534,   537,   540,   543,
   546,   549,   552,   580,   582,   585,   590,   594,   597,   600,
   603,   606,   611,   613,   645,   658,   671,   684,   697,   708,
   721
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","ID","NUM",
"NUM_C","NUM_D","INT","CHAR","DOUBLE","BOOL","CONST","PLUS","MINUS","TIMES",
"SLASH","EQL","NEQ","LES","LEQ","GTR","GEQ","MOD","XOR","ODD","SPLUS","SMINUS",
"UMINUS","AND","OR","NOT","LPAREN","RPAREN","LBRACKETS","RBRACKETS","LBRACE",
"RBRACE","COMMA","SEMICOLON","PERIOD","BECOMES","COLON","MAIN","IF","ELSE","WHILE",
"WRITE","READ","DO","CALL","SWITCH","CASE","DEFAULT","BREAK","CONTINUE","FOR",
"REPEAT","UNTIL","EXIT","program","@1","@2","@3","@4","const_list","const_dec",
"declaration_list","declaration_stat","array_size","type","var","statement_list",
"statement","exit_stat","break_stat","continue_stat","for_stat","@5","@6","for_exp1",
"for_exp2","for_exp3","loop_stat_list","do_while_stat","@7","do_while_stat_list",
"repeat_until_stat","@8","repeat_until_stat_list","if_stat","@9","else_stat",
"@10","while_stat","@11","@12","write_stat","array_loc","read_stat","compound_stat",
"expression_stat","expression","@13","simple_expr","additive_expr","term","factor",
"get_code_addr", NULL
};
#endif

static const short yyr1[] = {     0,
    60,    61,    62,    63,    59,    64,    64,    65,    65,    65,
    65,    66,    66,    67,    68,    68,    69,    69,    69,    69,
    70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
    72,    72,    72,    72,    72,    73,    74,    75,    77,    78,
    76,    79,    79,    80,    80,    81,    81,    82,    84,    83,
    85,    87,    86,    88,    90,    89,    92,    91,    91,    94,
    95,    93,    96,    96,    97,    97,    98,    99,   100,   100,
   102,   101,   101,   103,   103,   103,   103,   103,   103,   103,
   103,   103,   103,   104,   104,   104,   105,   105,   105,   105,
   105,   105,   106,   106,   106,   106,   106,   106,   106,   106,
   107
};

static const short yyr2[] = {     0,
     0,     0,     0,     0,    10,     2,     0,     6,     6,     6,
     6,     2,     0,     4,     4,     0,     1,     1,     1,     1,
     1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     2,     2,     2,     0,     0,
    14,     1,     0,     1,     0,     1,     0,     1,     0,    11,
     1,     0,    10,     1,     0,     8,     0,     4,     0,     0,
     0,     9,     3,     3,     4,     0,     4,     3,     2,     1,
     0,     5,     1,     1,     3,     3,     3,     3,     3,     3,
     3,     3,     2,     1,     3,     3,     1,     3,     3,     3,
     3,     2,     3,     2,     2,     2,     2,     2,     1,     1,
     0
};

static const short yydefact[] = {     0,
     0,     1,     7,     2,     0,    13,     6,     0,     0,     0,
     0,     3,     0,     0,     0,     0,    17,    19,    18,    20,
     0,    12,     0,     0,     0,     0,     0,    21,    99,   100,
     0,     0,     0,     0,     0,     0,    70,     0,   101,     0,
     0,   101,     0,     0,     0,   101,     0,    66,     4,    23,
    33,    34,    35,    30,    31,    32,    24,    25,    27,    26,
    28,    29,     0,    73,    74,    84,    87,    16,     0,     0,
     0,     0,    66,    92,    97,    98,    83,     0,     0,     0,
    60,    66,     0,    66,    49,    37,    38,    43,    52,    36,
    95,    96,    94,     0,    22,    69,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     8,    10,     9,    11,    94,    93,    68,     0,     0,
    64,    63,     0,     0,     0,    42,     0,     0,     0,     5,
    85,    86,    79,    80,    76,    78,    75,    77,    81,    82,
    88,    89,    90,    91,     0,    14,   101,     0,    67,    51,
     0,   101,    54,     0,     0,     0,     0,    55,     0,   101,
    45,   101,    65,    72,    15,     0,   101,     0,     0,    44,
     0,    59,    61,     0,   101,     0,   101,    56,     0,     0,
    39,     0,    57,    62,     0,    47,     0,     0,   101,    40,
    46,    53,    58,    50,     0,   101,     0,    48,    41,     0,
     0,     0
};

static const short yydefgoto[] = {   200,
     3,     6,    21,    94,     4,     7,    12,    22,   111,    23,
    73,    49,    50,    51,    52,    53,    54,   186,   195,   125,
   169,   190,   199,    55,   124,   151,    56,   127,   154,    57,
   166,   178,   188,    58,   120,   179,    59,    93,    60,    61,
    62,    63,   129,    64,    65,    66,    67,    81
};

static const short yypact[] = {   -11,
     0,-32768,-32768,    34,   102,-32768,-32768,    38,    44,    61,
    63,   108,    -3,    28,    42,    45,-32768,-32768,-32768,-32768,
   193,-32768,    74,    93,    98,   113,   116,-32768,-32768,-32768,
    30,   121,   121,    26,    18,   193,-32768,    94,-32768,    18,
   121,-32768,    88,    91,    99,-32768,    95,    37,   193,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,    96,-32768,    71,    -5,-32768,-32768,   101,   103,
   104,   105,    37,-32768,-32768,-32768,    83,   100,   157,    18,
-32768,     1,   106,-32768,-32768,-32768,-32768,    18,-32768,-32768,
-32768,-32768,    53,   110,-32768,-32768,    26,    26,    26,    26,
    26,    26,    26,    26,    26,    26,    30,    30,    30,    30,
   -25,-32768,-32768,-32768,-32768,   114,-32768,-32768,   117,   120,
-32768,-32768,    27,   193,   118,-32768,   193,    18,    97,-32768,
    -5,    -5,    83,    83,    83,    83,    83,    83,    83,    83,
-32768,-32768,-32768,-32768,   127,-32768,-32768,    18,-32768,-32768,
   109,-32768,-32768,   107,   125,    18,   132,-32768,   123,-32768,
    18,-32768,-32768,-32768,-32768,   193,-32768,   137,   131,-32768,
   139,   128,-32768,    18,-32768,    18,-32768,-32768,   193,   141,
-32768,   142,-32768,-32768,   140,    18,   146,   193,-32768,-32768,
-32768,-32768,-32768,-32768,   143,-32768,   193,-32768,-32768,   148,
   177,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   -21,   144,   -26,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -68,-32768,-32768,
-32768,   -34,-32768,  -136,   -30,     7,   -29,   -39
};


#define	YYLAST		251


static const short yytable[] = {    48,
    78,    74,    85,    77,   116,    83,    89,   145,   107,   108,
    75,    76,   146,    48,    48,   123,   109,   110,    82,    84,
    28,    29,    95,    30,   170,    91,    92,    48,    28,    29,
     1,    30,    28,    29,     2,    30,    24,   180,   121,   182,
    13,    31,    32,    33,     5,   119,    14,    34,    35,    31,
    32,    33,    95,   126,    32,    33,    35,    48,    48,   128,
    35,    91,    92,    15,   149,    16,    48,    25,   133,   134,
   135,   136,   137,   138,   139,   140,    68,   141,   142,   143,
   144,    26,    97,    98,    27,   128,    99,   100,   101,   102,
   103,   104,   -71,   155,    97,    98,    69,   150,   105,   106,
   153,    70,    48,   131,   132,    48,    48,   158,     8,     9,
    10,    11,   161,   159,    17,    18,    19,    20,    71,    72,
   168,   164,   171,    28,    80,    86,    48,   173,    87,    88,
   157,   117,    90,    96,    48,   181,   156,   183,   112,   172,
   113,   114,   115,   122,    48,   130,   128,   201,   147,   194,
   148,   191,   184,   160,   167,   152,   197,    48,   163,    28,
    29,   193,    30,   162,    48,   165,    48,   174,   175,   176,
   198,   177,   185,   187,   196,    48,   202,   189,     0,    79,
    31,    32,    33,   192,     0,     0,    34,    35,     0,     0,
     0,    36,   118,     0,    37,    28,    29,     0,    30,    38,
     0,    39,    40,    41,    42,     0,     0,     0,     0,    43,
    44,    45,    46,     0,    47,     0,    31,    32,    33,     0,
     0,     0,    34,    35,     0,     0,     0,    36,     0,     0,
    37,     0,     0,     0,     0,    38,     0,    39,    40,    41,
    42,     0,     0,     0,     0,    43,    44,    45,    46,     0,
    47
};

static const short yycheck[] = {    21,
    35,    31,    42,    34,    73,    40,    46,    33,    14,    15,
    32,    33,    38,    35,    36,    84,    22,    23,    40,    41,
     3,     4,    49,     6,   161,    25,    26,    49,     3,     4,
    42,     6,     3,     4,    35,     6,    40,   174,    38,   176,
     3,    24,    25,    26,    11,    80,     3,    30,    31,    24,
    25,    26,    79,    88,    25,    26,    31,    79,    80,    33,
    31,    25,    26,     3,    38,     3,    88,    40,    99,   100,
   101,   102,   103,   104,   105,   106,     3,   107,   108,   109,
   110,    40,    12,    13,    40,    33,    16,    17,    18,    19,
    20,    21,    40,   128,    12,    13,     4,   124,    28,    29,
   127,     4,   124,    97,    98,   127,   128,   147,     7,     8,
     9,    10,   152,   148,     7,     8,     9,    10,     6,     4,
   160,   156,   162,     3,    31,    38,   148,   167,    38,    31,
     4,    32,    38,    38,   156,   175,    40,   177,    38,   166,
    38,    38,    38,    38,   166,    36,    33,     0,    32,   189,
    31,   186,   179,    45,    32,    38,   196,   179,    34,     3,
     4,   188,     6,    57,   186,    34,   188,    31,    38,    31,
   197,    44,    32,    32,    32,   197,     0,    38,    -1,    36,
    24,    25,    26,    38,    -1,    -1,    30,    31,    -1,    -1,
    -1,    35,    36,    -1,    38,     3,     4,    -1,     6,    43,
    -1,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    53,
    54,    55,    56,    -1,    58,    -1,    24,    25,    26,    -1,
    -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,    -1,
    38,    -1,    -1,    -1,    -1,    43,    -1,    45,    46,    47,
    48,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    -1,
    58
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */

/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif



/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
{
                        dx=3;             /* 三个空间用于存放静态链SL、动态链DL和返回地址RA  */
                        procReg.tx0=tx;   /* 记录本层标识符的初始位置 */
                        table[tx].adr=cx; /* 记录当前层代码的开始位置 */
                        gen(jmp,0,1);     /* 产生跳转指令，跳转位置已知填1 */
                    ;
    break;}
case 2:
{;
    break;}
case 3:
{
                            code[table[procReg.tx0].adr].a=cx; /* 把前面生成的跳转语句的跳转位置改成当前位置 */
                            strcpy(table[procReg.tx0].name,"main");
                            table[procReg.tx0].kind=procedur;
                            table[procReg.tx0].type=none_t;
                            table[procReg.tx0].adr=cx;         /* 记录当前过程代码地址 */
                            table[procReg.tx0].size=dx;        /* 声明部分中每增加一条声明都会给dx增加1，声明部分已经结束，dx就是当前过程数据的size */
                            procReg.cx0=cx;                    /* 记录当前过程代码地址 */
                            gen(ini,0,dx);                     /* 生成指令，此指令执行时在数据栈中为被调用的过程开辟dx个单元的数据区 */
                        ;
    break;}
case 4:
{
                            gen(opr,0,0);                      /* 每个过程出口都要使用的释放数据段指令 */
                        ;
    break;}
case 5:
{;
    break;}
case 6:
{;
    break;}
case 8:
{
                                                type=int_t;         /* 整型标识符 */
                                                strcpy(id,yyvsp[-3].ident);      /* 获得标识符的名字 */
                                                num=yyvsp[-1].number;             /* 记录标识符的值 */
                                                enter(constant);    /* 进入符号表 */
                                            ;
    break;}
case 9:
{
                                                    type=double_tt; /* 浮点型标识符 */
                                                    strcpy(id,yyvsp[-3].ident);  /* 获得标识符的名字 */
                                                    num_d=yyvsp[-1].number_d;       /* 记录标识符的值 */
                                                    enter(constant);/* 进入符号表 */
                                                ;
    break;}
case 10:
{
                                                type=char_t;        /* char型标识符 */
                                                strcpy(id,yyvsp[-3].ident);      /* 获得标识符的名字 */
                                                num=yyvsp[-1].number;             /* 记录标识符的值 */
                                                enter(constant);    /* 进入符号表 */
                                            ;
    break;}
case 11:
{
                                                type=bool_t;        /* 布尔型标识符 */
                                                strcpy(id,yyvsp[-3].ident);      /* 获得标识符的名字 */
                                                num=yyvsp[-1].number;             /* 记录标识符的值 */
                                                enter(constant);    /* 进入符号表 */
                                            ;
    break;}
case 12:
{
                                            procReg.dx0=dx;          /* 记录当前数据分配的相对地址 */
                                        ;
    break;}
case 13:
{;
    break;}
case 14:
{
                                        /* 记录ID的类型 */
                                        if(strcmp(yyvsp[-3].type,"int")==0){
                                            type=int_t;
                                        } else if(strcmp(yyvsp[-3].type,"char")==0){
                                            type=char_t;
                                        }else if(strcmp(yyvsp[-3].type,"bool")==0){
                                            type=bool_t;
                                        }else if(strcmp(yyvsp[-3].type,"double")==0){
                                            type=double_tt;
                                        } else{
                                            type=none_t;
                                        }

                                        /* 进入符号表 */
                                        strcpy(id,yyvsp[-2].ident);
                                        enter(variable);
                                        type=none_t;
                                    ;
    break;}
case 15:
{
                                                array=1;        /* array=1，表明是数组 */
                                                array_dim++;    /* 记录维度 */
                                                /* 记录每个维度大小 */
                                                array_size=list_add(array_size,yyvsp[-1].number);
                                            ;
    break;}
case 16:
{   
            array=0;
            array_dim=0;
            array_size=NULL;
        ;
    break;}
case 17:
{yyval.type=yyvsp[0].type;;
    break;}
case 18:
{yyval.type=yyvsp[0].type;;
    break;}
case 19:
{yyval.type=yyvsp[0].type;;
    break;}
case 20:
{yyval.type=yyvsp[0].type;;
    break;}
case 21:
{
            int i = position (yyvsp[0].ident);    /* 符号表中查找变量 */
            if(i<=0){
                char s[50];
                sprintf(s,"variable %s undefined!", yyvsp[0].ident);
                syntax_error(s);
            }
            yyval.number = i;
            if(table[i].array){
                array_ids = list_add(array_ids,i);
                array_id = i;
            }
        ;
    break;}
case 22:
{;
    break;}
case 23:
{;
    break;}
case 24:
{;
    break;}
case 25:
{;
    break;}
case 26:
{;
    break;}
case 27:
{;
    break;}
case 28:
{;
    break;}
case 29:
{;
    break;}
case 30:
{;
    break;}
case 31:
{;
    break;}
case 32:
{;
    break;}
case 33:
{;
    break;}
case 34:
{;
    break;}
case 35:
{;
    break;}
case 36:
{gen(ext,0,0);;
    break;}
case 37:
{
                        loop_pos++;
                        if(loop_pos>=LOOPMAX){
                            syntax_error("too many breaks or continues.");
                        }
                        loopReg[loop_pos].cx=cx;    /* 记录当前层代码开始地址 */
                        loopReg[loop_pos].type=brk; /* 记录是否跳出循环 */
                        loopReg[loop_pos].level=loop_level;
                        gen(jmp,0,0);  /* 产生跳转指令，跳转位置未知添0 */
                    ;
    break;}
case 38:
{
                                loop_pos++;
                                if(loop_pos>=LOOPMAX){
                                    syntax_error("too many breaks or continues.");
                                }
                                loopReg[loop_pos].cx=cx;
                                loopReg[loop_pos].type=ctn;
                                loopReg[loop_pos].level=loop_level;
                                gen(jmp,0,0);/* 产生跳转指令，跳转位置未知填0 */
                            ;
    break;}
case 39:
{
                                                                                            if(loop_level==0){
                                                                                                loop_pos=-1;
                                                                                            }
                                                                                            loop_level++;
                                                                                            gen(jpc,0,0);
                                                                                            gen(jmp,0,0);
                                                                                    ;
    break;}
case 40:
{
                    gen(jmp,0,yyvsp[-5].number);
                ;
    break;}
case 41:
{
                                            gen(jmp,0,yyvsp[-6].number+2);
                                            code[yyvsp[-6].number].a=cx;
                                            code[yyvsp[-6].number+1].a=yyvsp[-1].number;
                                            int i;
                                            for(i=0;i<=loop_pos;i++)
                                            {
                                                if(loopReg[i].level==loop_level){
                                                    switch(loopReg[i].type){
                                                        case brk:
                                                            code[loopReg[i].cx].a=cx;  /*跳转地址回填*/
                                                            break;
                                                        case ctn:
                                                            code[loopReg[i].cx].a=yyvsp[-6].number+2; /*跳转地址回填*/
                                                            break;
                                                    }
                                                }
                                            }
                                            loop_level--;

                                        ;
    break;}
case 42:
{;
    break;}
case 43:
{;
    break;}
case 44:
{;
    break;}
case 45:
{;
    break;}
case 46:
{;
    break;}
case 47:
{;
    break;}
case 48:
{;
    break;}
case 49:
{
                            if(loop_level==0)
                            {
                                loop_pos=-1;
                            }
                            loop_level++;
                        ;
    break;}
case 50:
{
                                                                                                                    gen(jpc,0,yyvsp[0].number+2);
                                                                                                                    gen(jmp,0,yyvsp[-9].number);

                                                                                                                    int i;
                                                                                                                    for(i=0;i<=loop_pos;i++)
                                                                                                                    {
                                                                                                                        if(loopReg[i].level==loop_level){
                                                                                                                            switch(loopReg[i].type){
                                                                                                                                case brk:
                                                                                                                                    code[loopReg[i].cx].a=cx;
                                                                                                                                    break;
                                                                                                                                case ctn:
                                                                                                                                    code[loopReg[i].cx].a=yyvsp[-5].number;
                                                                                                                                    break;
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                    loop_level--;
                                                                                                                ;
    break;}
case 51:
{;
    break;}
case 52:
{
                                if(loop_level==0)
                                {
                                    loop_pos=-1;
                                }
                                loop_level++;
                            ;
    break;}
case 53:
{
                                                                                                                gen(jpc,0,yyvsp[-8].number);

                                                                                                                int i;
                                                                                                                for(i=0;i<=loop_pos;i++)
                                                                                                                {
                                                                                                                    if(loopReg[i].level==loop_level){
                                                                                                                        switch(loopReg[i].type){
                                                                                                                            case brk:
                                                                                                                                code[loopReg[i].cx].a=cx;
                                                                                                                                break;
                                                                                                                            case ctn:
                                                                                                                                code[loopReg[i].cx].a=yyvsp[-4].number;
                                                                                                                                break;
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                                loop_level--;

                                                                                                            ;
    break;}
case 54:
{;
    break;}
case 55:
{
                                                    gen(jpc, 0, 0);
                                                ;
    break;}
case 56:
{
                    code[yyvsp[-3].number].a = yyvsp[0].number;
                ;
    break;}
case 57:
{
                            gen(jmp,0,0);
                        ;
    break;}
case 58:
{
                    yyval.number=yyvsp[-2].number+1;
                    code[yyvsp[-2].number].a=cx;
                ;
    break;}
case 59:
{
            yyval.number = cx;
        ;
    break;}
case 60:
{
                                if(loop_level==0)
                                {
                                    loop_pos=-1;
                                }
                                loop_level++;
                            ;
    break;}
case 61:
{
                                                gen(jpc, 0 , 0);
                                            ;
    break;}
case 62:
{
                    gen(jmp, 0, yyvsp[-7].number);
                    code[yyvsp[-2].number].a = cx;

                    int i;
                    for(i=0;i<=loop_pos;i++)
                    {
                        if(loopReg[i].level==loop_level){
                            switch(loopReg[i].type){
                                case brk:
                                    code[loopReg[i].cx].a=cx;
                                    break;
                                case ctn:
                                    code[loopReg[i].cx].a=yyvsp[-7].number;
                                    break;
                            }
                        }
                    }
                    loop_level--;
                ;
    break;}
case 63:
{
                                    gen(opr,0,14);
                                ;
    break;}
case 64:
{
                                    if(table[yyvsp[-1].number].kind==constant){
                                        if(table[yyvsp[-1].number].type==double_tt){
                                            _gen(lit,0,0,1,table[yyvsp[-1].number].val_d);
                                        }else{
                                            gen(lit,0,table[yyvsp[-1].number].val);
                                        }
                                    }else if(table[yyvsp[-1].number].kind==variable){
                                        gen(lod,0,table[yyvsp[-1].number].adr);
                                    }
                                    if(table[yyvsp[-1].number].type==char_t)
                                        gen(opr,0,17);
                                    else if(table[yyvsp[-1].number].type==int_t)
                                        gen(opr,0,14);
                                    else if(table[yyvsp[-1].number].type==bool_t)
                                        gen(opr,0,25);
                                    else if(table[yyvsp[-1].number].type==double_tt)
                                        gen(opr,0,14);
                                    else
                                        error(0); 
                                ;
    break;}
case 65:
{
                                                        int id=list_get_last(array_ids);
                                                        int dim_id=yyvsp[-3].number;
                                                        yyval.number=dim_id+1;  
                                                        if(dim_id+1>table[id].array_dim){
                                                            char s[50];
                                                            sprintf(s,"dimension of array %s is %d, gived %d.", table[id].name, table[id].array_dim, dim_id);
                                                            syntax_error(s);
                                                        }
                                                        int p=list_get_product_after_id(table[id].array_size, dim_id);
                                                        gen(lit,0,p);
                                                        gen(opr,0,4);
                                                        if(dim_id>=1){
                                                            gen(opr,0,2);
                                                        }

                                                    ;
    break;}
case 66:
{yyval.number=0;;
    break;}
case 67:
{
                                        if(table[yyvsp[-2].number].kind==constant){
                                            syntax_error("constant cannot be read.");
                                        }else{
                                            if(yyvsp[-1].number>=1){
                                                gen(lit,0,table[yyvsp[-2].number].adr);
                                                gen(opr,0,2);
                                                if(table[yyvsp[-2].number].type==double_tt){
                                                    _gen(opr,0,16,1,0.0);
                                                }else{
                                                    gen(opr,0,16);
                                                }
                                                gen(sto,0,0);
                                            }else{
                                                if(table[yyvsp[-2].number].type==double_tt){
                                                    _gen(opr,0,16,1,0.0);
                                                }else{
                                                    gen(opr,0,16);
                                                }
                                                gen(sto,0,table[yyvsp[-2].number].adr);
                                            }
                                        }
                                    ;
    break;}
case 68:
{;
    break;}
case 69:
{;
    break;}
case 70:
{;
    break;}
case 71:
{
                        if(table[yyvsp[-1].number].kind==constant){
                            syntax_error("constant cannot be writen.");
                        }else{
                            if(yyvsp[0].number>=1){
                                gen(lit,0,table[yyvsp[-1].number].adr);
                                gen(opr,0,2);
                            }
                        }
                    ;
    break;}
case 72:
{
                            if(yyvsp[-3].number>=1){
                                gen(sto,0,0);
                            }else{
                                gen(sto,0,table[yyvsp[-4].number].adr);
                                gen(lod,0,table[yyvsp[-4].number].adr);
                            }
                        ;
    break;}
case 73:
{;
    break;}
case 74:
{;
    break;}
case 75:
{
                                            gen(opr,0,12);
                                        ;
    break;}
case 76:
{
                                            gen(opr,0,10);
                                        ;
    break;}
case 77:
{
                                            gen(opr,0,11);
                                        ;
    break;}
case 78:
{
                                            gen(opr,0,13);
                                        ;
    break;}
case 79:
{
                                            gen(opr,0,8);
                                        ;
    break;}
case 80:
{
                                            gen(opr,0,9);
                                        ;
    break;}
case 81:
{
                                            gen(opr,0,22);
                                        ;
    break;}
case 82:
{
                                            gen(opr,0,23);
                                        ;
    break;}
case 83:
{
                                            gen(opr,0,24);
                                        ;
    break;}
case 84:
{;
    break;}
case 85:
{
                                    gen(opr,0,2);
                                ;
    break;}
case 86:
{
                                    gen(opr,0,3);
                                ;
    break;}
case 87:
{   

                ;
    break;}
case 88:
{
                            gen(opr,0,4);
                        ;
    break;}
case 89:
{
                            gen(opr,0,5);
                        ;
    break;}
case 90:
{
                            gen(opr,0,20);
                        ;
    break;}
case 91:
{
                            gen(opr,0,21);
                        ;
    break;}
case 92:
{
                            gen(opr,0,6);
                        ;
    break;}
case 93:
{;
    break;}
case 94:
{
                        switch(table[yyvsp[-1].number].kind){
                            case constant:
                                if(yyvsp[0].number>=1){
                                    syntax_error("constant have no index.");
                                }
                                if(table[yyvsp[-1].number].type==double_tt){
                                    _gen(lit,0,0,1,table[yyvsp[-1].number].val_d);
                                }else{
                                    gen(lit,0,table[yyvsp[-1].number].val);
                                }
                                break;
                            case variable:
                                if(yyvsp[0].number>=1){
                                    if(!table[yyvsp[-1].number].array){
                                        char s[50];
                                        sprintf(s,"variable %s is not an array.", table[yyvsp[-1].number].name);
                                        syntax_error(s);
                                    }
                                    gen(lit,0,table[yyvsp[-1].number].adr);
                                    gen(opr,0,2);
                                    gen(lod,0,0);
                                    list_del_last(array_ids);
                                }else{
                                    gen(lod,0,table[yyvsp[-1].number].adr);
                                }
                                break;
                            case procedur:
                                syntax_error("procedur is not supported yet.");
                                break;
                            }
                    ;
    break;}
case 95:
{
                    if(table[yyvsp[-1].number].array==0){
                        gen(lod,0,table[yyvsp[-1].number].adr);
                        gen(lod,0,table[yyvsp[-1].number].adr);
                        gen(lit,0,1);
                        gen(opr,0,2);
                        gen(sto,0,table[yyvsp[-1].number].adr);
                    }else{
                        char s[50];
                        sprintf(s,"%s is an array, not a simple variable.", table[yyvsp[-1].number].name);
                        syntax_error(s);
                    }
                ;
    break;}
case 96:
{
                    if(table[yyvsp[-1].number].array==0){
                        gen(lod,0,table[yyvsp[-1].number].adr);
                        gen(lod,0,table[yyvsp[-1].number].adr);
                        gen(lit,0,1);
                        gen(opr,0,3);
                        gen(sto,0,table[yyvsp[-1].number].adr);
                    }else{
                        char s[50];
                        sprintf(s,"%s is an array, not a simple variable.", table[yyvsp[-1].number].name);
                        syntax_error(s);
                    }
                ;
    break;}
case 97:
{
                    if(table[yyvsp[0].number].array==0){
                        gen(lod,0,table[yyvsp[0].number].adr);
                        gen(lit,0,1);
                        gen(opr,0,2);
                        gen(sto,0,table[yyvsp[0].number].adr);
                        gen(lod,0,table[yyvsp[0].number].adr);
                    }else{
                        char s[50];
                        sprintf(s,"%s is an array, not a simple variable.", table[yyvsp[0].number].name);
                        syntax_error(s);
                    }
                ;
    break;}
case 98:
{
                    if(table[yyvsp[0].number].array==0){
                        gen(lod,0,table[yyvsp[0].number].adr);
                        gen(lit,0,1);
                        gen(opr,0,3);
                        gen(sto,0,table[yyvsp[0].number].adr);
                        gen(lod,0,table[yyvsp[0].number].adr);
                    }else{
                        char s[50];
                        sprintf(s,"%s is an array, not a simple variable.", table[yyvsp[0].number].name);
                        syntax_error(s);
                    }
                ;
    break;}
case 99:
{
                int num;
                num=yyvsp[0].number;
                if(num>AMAX){
                    char s[100];
                    sprintf(s,"integer(%d) should not greater than %d, now 0 instead. ", yyvsp[0].number, AMAX);
                    syntax_error(s);
                    num=0;
                    }
                gen(lit,0,num);
            ;
    break;}
case 100:
{
                num_d=yyvsp[0].number_d;
                _gen(lit,0,0,1,yyvsp[0].number_d);
            ;
    break;}
case 101:
{
                yyval.number = cx;
               ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */


  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}



void yyerror(char *s){
    err++;
    printf("%s in line %d\n",s,line);
    fprintf(ferrout,"%s in line %d\n",s,line);
}

int compile(const char* filePath)
{
    int i;
    listswitch=true;
    int print_table=1;
    yyin = fopen(filePath,"r");

    printf("x0 compiler\n");
    if((ferrout=fopen("ferrout.txt","w"))==NULL){
        printf("Cann't open file!\n");
        exit(0);
    }
    if((fcode=fopen("fcode.txt","w"))==NULL){
        printf("Cann't open fcode.txt file!\n");
        exit(0);
    }
    if((fresult=fopen("fresult.txt","w"))==NULL){
        printf("Cann't open fresult.txt file!\n");
        exit(0);
    }
    if((ftable=fopen("ftable.txt","w"))==NULL){
        printf("Cann't open ftable.txt file!\n");
        exit(0);
    }
    yyparse();
    if(err==0)
    {
        listcode();
        interpret();
    }
    else
        printf("%d errors in PL/0 program\n",err);
    if(print_table){
        printTable(0);
    }
    fclose(fcode);
    fclose(ferrout);
    fclose(ftable);
    return 0;
}