
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "error.h"
#include "value.h"
#include "quadruples.h"
#include <vector>
#include <stdarg.h>

extern int yylex(void);
void yyerror(const char *s, ...);
extern int line_num;

// Function handling
char* current_function_name;
int current_function_idx;
int current_return_type = -1;
bool seen_return = false;
std::vector<int> param_types;
std::vector<bool> default_params;
bool seen_default_param = false;

// loop and switch handling
int is_loop = 0;
int is_switch = 0;


/* Line 189 of yacc.c  */
#line 103 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT_LITERAL = 259,
     CHAR_LITERAL = 260,
     BOOL_LITERAL = 261,
     STRING_LITERAL = 262,
     VARIABLE = 263,
     TYPE = 264,
     VOID = 265,
     RELOP = 266,
     IF = 267,
     ELSE = 268,
     WHILE = 269,
     DO = 270,
     FOR = 271,
     RETURN = 272,
     SWITCH = 273,
     CASE = 274,
     DEFAULT = 275,
     BREAK = 276,
     CONTINUE = 277,
     CONST = 278,
     LAND = 279,
     LOR = 280,
     POW = 281,
     INC = 282,
     DEC = 283,
     UMINUS = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "parser.y"

    Value val;
    ListValue list_val;
    char *str;
    char *relop;
    int type_val;




/* Line 214 of yacc.c  */
#line 179 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   429

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  101
/* YYNRULES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,    34,     2,     2,
      40,    41,    32,    30,    43,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    37,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    14,    16,    19,
      21,    24,    26,    28,    30,    32,    34,    38,    41,    44,
      47,    48,    51,    55,    61,    68,    69,    75,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    99,   103,   107,
     111,   115,   119,   122,   125,   129,   133,   137,   141,   143,
     146,   149,   152,   155,   156,   158,   159,   161,   162,   169,
     171,   172,   177,   178,   185,   186,   187,   197,   198,   199,
     200,   201,   215,   216,   217,   218,   219,   232,   233,   240,
     244,   245,   246,   255,   256,   257,   264,   265,   273,   274,
     282,   285,   286,   288,   290,   294,   297,   302,   307,   308,
     310,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    45,    47,    -1,    45,    82,    -1,
      -1,    46,    47,    -1,    49,    -1,    54,    37,    -1,    50,
      -1,    52,    37,    -1,    57,    -1,    61,    -1,    63,    -1,
      66,    -1,    75,    -1,    17,    55,    37,    -1,    21,    37,
      -1,    22,    37,    -1,     1,    37,    -1,    -1,    48,    49,
      -1,     9,     8,    37,    -1,     9,     8,    29,    53,    37,
      -1,    23,     9,     8,    29,    53,    37,    -1,    -1,    38,
      51,    48,    46,    39,    -1,     8,    29,    53,    -1,    54,
      -1,    52,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,    54,    30,    54,    -1,    54,
      31,    54,    -1,    54,    32,    54,    -1,    54,    33,    54,
      -1,    54,    34,    54,    -1,    54,    26,    54,    -1,    31,
      54,    -1,    35,    54,    -1,    54,    24,    54,    -1,    54,
      25,    54,    -1,    40,    54,    41,    -1,    54,    11,    54,
      -1,    88,    -1,    27,     8,    -1,    28,     8,    -1,     8,
      27,    -1,     8,    28,    -1,    -1,    54,    -1,    -1,    52,
      -1,    -1,    12,    40,    54,    41,    58,    59,    -1,    47,
      -1,    -1,    47,    13,    60,    47,    -1,    -1,    14,    40,
      54,    41,    62,    47,    -1,    -1,    -1,    15,    64,    47,
      65,    14,    40,    54,    41,    37,    -1,    -1,    -1,    -1,
      -1,    16,    40,    67,    56,    37,    68,    55,    69,    37,
      56,    70,    41,    47,    -1,    -1,    -1,    -1,    -1,    16,
      40,    71,    49,    72,    55,    73,    37,    56,    74,    41,
      47,    -1,    -1,    18,    40,    54,    41,    76,    77,    -1,
      38,    80,    39,    -1,    -1,    -1,    38,    80,    20,    78,
      42,    46,    79,    39,    -1,    -1,    -1,    80,    19,     3,
      81,    42,    46,    -1,    -1,     9,     8,    40,    83,    85,
      41,    50,    -1,    -1,    10,     8,    40,    84,    85,    41,
      50,    -1,     1,    39,    -1,    -1,    86,    -1,    87,    -1,
      86,    43,    87,    -1,     9,     8,    -1,     9,     8,    29,
      53,    -1,     8,    40,    89,    41,    -1,    -1,    90,    -1,
      54,    -1,    90,    43,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    69,    70,    74,    75,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   101,   102,   103,
     107,   108,   112,   119,   131,   146,   146,   150,   174,   175,
     179,   180,   181,   182,   183,   184,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     242,   261,   280,   302,   303,   307,   308,   313,   313,   317,
     318,   318,   321,   321,   325,   325,   325,   329,   329,   333,
     336,   329,   345,   345,   349,   352,   345,   364,   364,   368,
     369,   369,   369,   373,   374,   374,   379,   379,   405,   405,
     427,   431,   432,   436,   437,   441,   450,   467,   485,   486,
     491,   492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT_LITERAL",
  "CHAR_LITERAL", "BOOL_LITERAL", "STRING_LITERAL", "VARIABLE", "TYPE",
  "VOID", "RELOP", "IF", "ELSE", "WHILE", "DO", "FOR", "RETURN", "SWITCH",
  "CASE", "DEFAULT", "BREAK", "CONTINUE", "CONST", "LAND", "LOR", "POW",
  "INC", "DEC", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS",
  "';'", "'{'", "'}'", "'('", "')'", "':'", "','", "$accept", "program",
  "statements", "statement", "declarations", "declaration", "block", "$@1",
  "assignment", "expression_or_assignment", "expression", "opt_expression",
  "opt_assignment", "if_statement", "$@2", "if_body", "$@3",
  "while_statement", "$@4", "do_while_statement", "$@5", "$@6",
  "for_statement", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "switch_statement", "$@15", "switch_body", "$@16", "$@17",
  "case_list", "$@18", "function", "$@19", "$@20", "parameters",
  "parameter_list", "parameter", "function_call", "argument_list_opt",
  "non_empty_argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
      43,    45,    42,    47,    37,    33,   284,    59,   123,   125,
      40,    41,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    49,    51,    50,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    58,    57,    59,
      60,    59,    62,    61,    64,    65,    63,    67,    68,    69,
      70,    66,    71,    72,    73,    74,    66,    76,    75,    77,
      78,    79,    77,    80,    81,    80,    83,    82,    84,    82,
      82,    85,    85,    86,    86,    87,    87,    88,    89,    89,
      90,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       0,     2,     3,     5,     6,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     1,     2,
       2,     2,     2,     0,     1,     0,     1,     0,     6,     1,
       0,     4,     0,     6,     0,     0,     9,     0,     0,     0,
       0,    13,     0,     0,     0,     0,    12,     0,     6,     3,
       0,     0,     8,     0,     0,     6,     0,     7,     0,     7,
       2,     0,     1,     1,     3,     2,     4,     4,     0,     1,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,    64,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     3,     7,     9,
       0,     0,    11,    12,    13,    14,    15,     4,    48,    19,
      90,    51,    52,     0,    98,     0,     0,     0,     0,     0,
      67,    35,    54,     0,     0,    17,    18,     0,    49,    50,
      42,    43,    20,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    29,    27,    28,   100,     0,
      99,     0,    22,    86,    88,     0,     0,     0,     0,    65,
      55,     0,    16,     0,     0,     5,    46,    47,    44,    45,
      41,    36,    37,    38,    39,    40,    97,     0,     0,    91,
      91,    57,    62,     0,     0,     0,    56,     0,    73,    77,
       0,     0,    21,   101,    23,     0,     0,    92,    93,     0,
       0,     0,     0,    68,    53,     0,     0,    26,     6,    95,
       0,     0,     0,    59,    58,    63,     0,    53,    74,    83,
      78,    24,     0,    87,    94,    89,    60,     0,    69,     0,
       0,    96,     0,     0,     0,    55,     0,    80,    79,    61,
      66,    55,    75,    84,     0,    70,     0,     0,     5,     0,
       0,     5,     0,     0,    76,     0,     0,    71,    82
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   121,   138,    95,    28,    29,    62,    30,    76,
      31,    53,   117,    32,   130,   144,   162,    33,   131,    34,
      49,   114,    35,    90,   147,   164,   179,    91,   134,   159,
     176,    36,   135,   150,   174,   186,   160,   177,    37,   109,
     110,   126,   127,   128,    38,    79,    80
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -172
static const yytype_int16 yypact[] =
{
    -172,   150,  -172,     8,  -172,  -172,  -172,  -172,  -172,    -2,
      22,    34,    21,    23,  -172,    24,     9,    29,    46,    47,
      76,    85,    88,     9,     9,  -172,     9,  -172,  -172,  -172,
      63,   110,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,    71,     9,     6,    64,     9,     9,   308,
      -4,    -6,   362,    66,     9,  -172,  -172,   102,  -172,  -172,
      86,    86,  -172,    56,  -172,     9,     9,     9,     9,     9,
       9,     9,     9,     9,  -172,  -172,  -172,   362,   362,    77,
      79,    71,  -172,  -172,  -172,    83,   326,   101,   115,  -172,
     117,    -3,  -172,   338,   116,    -3,  -172,   395,   386,   374,
      86,    94,    94,    86,    86,    86,  -172,     9,   111,   130,
     130,  -172,  -172,    31,   135,   134,  -172,   132,  -172,  -172,
      71,   228,  -172,   362,  -172,   162,   133,   137,  -172,   142,
     308,   308,   136,  -172,     9,   146,   138,  -172,  -172,   157,
     149,   130,   149,   185,  -172,  -172,     9,     9,  -172,  -172,
    -172,  -172,    71,  -172,  -172,  -172,  -172,   350,  -172,   164,
     -16,  -172,   308,   175,   176,   117,   196,  -172,  -172,  -172,
    -172,   117,  -172,  -172,   172,  -172,   177,   178,  -172,   180,
     308,  -172,   268,   308,  -172,   188,   183,  -172,  -172
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -171,    -1,  -172,     0,   -70,  -172,   -19,   -79,
     -15,  -116,  -106,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,   107,  -172,    84,  -172,  -172,  -172
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -86
static const yytype_int16 yytable[] =
{
      27,    52,   108,   166,   167,   -72,    88,   182,    60,    61,
     185,    63,     4,     5,     6,     7,     8,    51,   148,   -72,
      20,    41,    42,   168,    75,    41,    42,    43,    77,    78,
      45,   158,    85,    86,    44,    81,    21,    22,    44,    93,
      23,   136,    46,    82,    24,    39,    83,    40,    89,    26,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   172,
      81,    47,    75,    48,    50,   175,    77,    65,    82,    54,
     153,   116,   155,   161,     4,     5,     6,     7,     8,     9,
      66,    67,    68,    55,    56,    57,    69,    70,    71,    72,
      73,   118,   123,    58,    65,   122,    59,    96,    21,    22,
      64,    75,    23,    92,    84,    77,    24,    66,    67,    68,
      94,    26,    68,    69,    70,    71,    72,    73,   106,    52,
      68,    65,   107,   113,   111,   115,    71,    72,    73,   143,
     145,   157,    52,    75,    66,    67,    68,    77,    39,   125,
      69,    70,    71,    72,    73,   120,   116,    74,   124,   132,
       2,     3,   116,     4,     5,     6,     7,     8,     9,    10,
      11,   169,    12,    43,    13,    14,    15,    16,    17,   133,
     139,    18,    19,    20,   140,   151,   146,    21,    22,   184,
     141,    23,   187,   142,   149,    24,   152,    25,    25,    87,
      26,     4,     5,     6,     7,     8,     9,    88,   156,   173,
      12,   165,    13,    14,    15,    16,    17,   -85,   -85,    18,
      19,    20,   170,   171,   178,    21,    22,   129,   180,    23,
     181,   183,   188,    24,     0,   154,    25,   -85,    26,    87,
       0,     4,     5,     6,     7,     8,     9,    88,     0,     0,
      12,     0,    13,    14,    15,    16,    17,     0,     0,    18,
      19,    20,     0,     0,     0,    21,    22,     0,     0,    23,
       0,     0,     0,    24,     0,     0,    25,   137,    26,    87,
       0,     4,     5,     6,     7,     8,     9,    88,     0,     0,
      12,     0,    13,    14,    15,    16,    17,     0,     0,    18,
      19,    20,     0,     0,     0,    21,    22,     0,     0,    23,
       0,     0,     0,    24,     0,     0,    25,   -81,    26,    87,
       0,     4,     5,     6,     7,     8,     9,    88,     0,     0,
      12,     0,    13,    14,    15,    16,    17,     0,     0,    18,
      19,    20,     0,     0,     0,    21,    22,    65,     0,    23,
       0,     0,     0,    24,     0,     0,    25,     0,    26,    65,
      66,    67,    68,     0,     0,     0,    69,    70,    71,    72,
      73,    65,    66,    67,    68,     0,     0,   112,    69,    70,
      71,    72,    73,    65,    66,    67,    68,     0,     0,   119,
      69,    70,    71,    72,    73,    65,    66,    67,    68,     0,
       0,   163,    69,    70,    71,    72,    73,    65,    66,     0,
      68,     0,     0,     0,    69,    70,    71,    72,    73,     0,
       0,     0,    68,     0,     0,     0,    69,    70,    71,    72,
      73,    68,     0,     0,     0,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
       1,    16,    81,    19,    20,     9,     9,   178,    23,    24,
     181,    26,     3,     4,     5,     6,     7,     8,   134,    23,
      23,    27,    28,    39,    43,    27,    28,    29,    43,    44,
       8,   147,    47,    48,    40,    29,    27,    28,    40,    54,
      31,   120,     8,    37,    35,    37,    40,    39,    49,    40,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   165,
      29,    40,    81,    40,    40,   171,    81,    11,    37,    40,
     140,    90,   142,   152,     3,     4,     5,     6,     7,     8,
      24,    25,    26,    37,    37,     9,    30,    31,    32,    33,
      34,    91,   107,     8,    11,    95,     8,    41,    27,    28,
      37,   120,    31,    37,    40,   120,    35,    24,    25,    26,
       8,    40,    26,    30,    31,    32,    33,    34,    41,   134,
      26,    11,    43,     8,    41,     8,    32,    33,    34,   130,
     131,   146,   147,   152,    24,    25,    26,   152,    37,     9,
      30,    31,    32,    33,    34,    29,   165,    37,    37,    14,
       0,     1,   171,     3,     4,     5,     6,     7,     8,     9,
      10,   162,    12,    29,    14,    15,    16,    17,    18,    37,
       8,    21,    22,    23,    41,    37,    40,    27,    28,   180,
      43,    31,   183,    41,    38,    35,    29,    38,    38,     1,
      40,     3,     4,     5,     6,     7,     8,     9,    13,     3,
      12,    37,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    37,    37,    42,    27,    28,   110,    41,    31,
      42,    41,    39,    35,    -1,   141,    38,    39,    40,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    40,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    39,    40,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    27,    28,    11,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    40,    11,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    11,    24,    25,    26,    -1,    -1,    41,    30,    31,
      32,    33,    34,    11,    24,    25,    26,    -1,    -1,    41,
      30,    31,    32,    33,    34,    11,    24,    25,    26,    -1,
      -1,    41,    30,    31,    32,    33,    34,    11,    24,    -1,
      26,    -1,    -1,    -1,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    12,    14,    15,    16,    17,    18,    21,    22,
      23,    27,    28,    31,    35,    38,    40,    47,    49,    50,
      52,    54,    57,    61,    63,    66,    75,    82,    88,    37,
      39,    27,    28,    29,    40,     8,     8,    40,    40,    64,
      40,     8,    54,    55,    40,    37,    37,     9,     8,     8,
      54,    54,    51,    54,    37,    11,    24,    25,    26,    30,
      31,    32,    33,    34,    37,    52,    53,    54,    54,    89,
      90,    29,    37,    40,    40,    54,    54,     1,     9,    47,
      67,    71,    37,    54,     8,    48,    41,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    41,    43,    53,    83,
      84,    41,    41,     8,    65,     8,    52,    56,    49,    41,
      29,    46,    49,    54,    37,     9,    85,    86,    87,    85,
      58,    62,    14,    37,    72,    76,    53,    39,    47,     8,
      41,    43,    41,    47,    59,    47,    40,    68,    55,    38,
      77,    37,    29,    50,    87,    50,    13,    54,    55,    73,
      80,    53,    60,    41,    69,    37,    19,    20,    39,    47,
      37,    37,    56,     3,    78,    56,    74,    81,    42,    70,
      41,    42,    46,    41,    47,    46,    79,    47,    39
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    { 
          if(current_return_type == -1) {
              yyerror("Return statement not in function");
          } else {
              seen_return = true;
              if(current_return_type == TYPE_VOID && (yyvsp[(2) - (3)].val).name != NULL) {
                  yyerror("Void function cannot return a value");
              } else if(current_return_type == TYPE_VOID || !type_mismatch(current_return_type, (yyvsp[(2) - (3)].val).type)) {
                  printf("[Line %d] Return statement\n", line_num);
                  emit_quad("RETURN", (yyvsp[(2) - (3)].val).name, NULL, NULL);
              }
          }
      ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { if(!is_loop && !is_switch) yyerror("Break statement not in loop or switch"); quad_break(); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { if(!is_loop) yyerror("Continue statement not in loop"); quad_continue(); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { yyerrok; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {
          int idx = add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].type_val));
          if (idx != -1) {
            printf("[Line %d] Declaration: %s\n", line_num, (yyvsp[(2) - (3)].str));
            emit_quad("DECLARE", typeToString((yyvsp[(1) - (3)].type_val)), NULL, (yyvsp[(2) - (3)].str));
          }
      ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {
          /* check type compatibility between declared type and initializer */
          if(!type_mismatch((yyvsp[(1) - (5)].type_val), (yyvsp[(4) - (5)].val).type)) {
            int idx = add_symbol((yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].type_val), true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = (yyvsp[(4) - (5)].val);
                symbol_table.table[idx].init_value.is_const = false;
                printf("[Line %d] Declaration with init: %s = ...\n", line_num, (yyvsp[(2) - (5)].str));
                emit_quad("DECLARE", typeToString((yyvsp[(1) - (5)].type_val)), (yyvsp[(4) - (5)].val).name, (yyvsp[(2) - (5)].str));
            }
          }
      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {
        /* check type compatibility between declared type and initializer */
        if(!type_mismatch((yyvsp[(2) - (6)].type_val), (yyvsp[(5) - (6)].val).type)) {
            int idx = add_symbol((yyvsp[(3) - (6)].str), (yyvsp[(2) - (6)].type_val), true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = (yyvsp[(5) - (6)].val);
                symbol_table.table[idx].init_value.is_const = true;
                printf("[Line %d] Constant declaration: %s = ...\n", line_num, (yyvsp[(3) - (6)].str));
                emit_quad("DECLARE_CONST", typeToString((yyvsp[(2) - (6)].type_val)), (yyvsp[(5) - (6)].val).name, (yyvsp[(3) - (6)].str));
            } 
        }
      ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { enter_block_scope(); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    { exit_scope(); (yyval.val) = (yyvsp[(4) - (5)].val); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {
          printf("[Line %d] Assignment: %s = ...\n", line_num, (yyvsp[(1) - (3)].str));
          int idx = find_symbol((yyvsp[(1) - (3)].str));
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in assignment", (yyvsp[(1) - (3)].str));
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable", (yyvsp[(1) - (3)].str));
          }
          else {
              if(symbol_table.table[idx].init_value.is_const) {
                  yyerror("Cannot assign to constant '%s'", (yyvsp[(1) - (3)].str));
              }
              // check type compatibility during assignment
              if(!type_mismatch(symbol_table.table[idx].type, (yyvsp[(3) - (3)].val).type)){
                emit_quad("ASSIGN", (yyvsp[(3) - (3)].val).name, NULL, (yyvsp[(1) - (3)].str));
              }
          }

      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {
          int idx = find_symbol((yyvsp[(1) - (1)].str));
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in expression", (yyvsp[(1) - (1)].str));
              (yyval.val) = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable", (yyvsp[(1) - (1)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].is_initialized == false) {
              yyerror("Variable '%s' used before initialization", (yyvsp[(1) - (1)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
              (yyval.val).name = symbol_table.table[idx].name;
          }
          else{
              symbol_table.table[idx].is_used = true;
              if(symbol_table.table[idx].init_value.is_const && symbol_table.table[idx].init_value.is_evaluated) {
                  (yyval.val) = symbol_table.table[idx].init_value;
              } 
              else {
                  (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
              }
              (yyval.val).name = symbol_table.table[idx].name;
          }
      ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { (yyval.val) = add_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("+", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    { (yyval.val) = sub_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("-", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    { (yyval.val) = mul_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("*", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    { (yyval.val) = div_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("/", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    { (yyval.val) = mod_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("%", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { (yyval.val) = pow_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("^", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { (yyval.val) = neg_value((yyvsp[(2) - (2)].val)); (yyval.val).name = emit_quad("MINUS", (yyvsp[(2) - (2)].val).name, NULL, NULL); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { (yyval.val) = not_value((yyvsp[(2) - (2)].val)); (yyval.val).name = emit_quad("NOT", (yyvsp[(2) - (2)].val).name, NULL, NULL); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { (yyval.val) = and_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("AND", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval.val) = or_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("OR", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyval.val) = compare_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyvsp[(2) - (3)].relop)); (yyval.val).name = emit_quad((yyvsp[(2) - (3)].relop), (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {
        int idx = find_symbol((yyvsp[(2) - (2)].str));
        if(idx == -1) {
            yyerror("Undeclared variable '%s' used in prefix increment", (yyvsp[(2) - (2)].str));
            (yyval.val) = make_runtime_value(TYPE_INT);
        } 
        else if(is_function(idx)) {
            yyerror("Function '%s' used as variable in increment", (yyvsp[(2) - (2)].str));
            (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
        }
        else if(symbol_table.table[idx].init_value.is_const) {
            yyerror("Cannot increment constant '%s'", (yyvsp[(2) - (2)].str));
            (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
        }
        else {
            (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
            (yyval.val).name = quad_prefix("INC", (yyvsp[(2) - (2)].str));
        }
      ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {
          int idx = find_symbol((yyvsp[(2) - (2)].str));
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in prefix decrement", (yyvsp[(2) - (2)].str));
              (yyval.val) = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable in decrement", (yyvsp[(2) - (2)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].init_value.is_const) {
              yyerror("Cannot decrement constant '%s'", (yyvsp[(2) - (2)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else {
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
              (yyval.val).name = quad_prefix("DEC", (yyvsp[(2) - (2)].str));
          }
      ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {
          int idx = find_symbol((yyvsp[(1) - (2)].str));
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in postfix increment", (yyvsp[(1) - (2)].str));
              (yyval.val) = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable in increment", (yyvsp[(1) - (2)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].init_value.is_const) {
              yyerror("Cannot increment constant '%s'", (yyvsp[(1) - (2)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else {
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
              (yyval.val).name = quad_postfix("INC", (yyvsp[(1) - (2)].str));
          }
      ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {
          int idx = find_symbol((yyvsp[(1) - (2)].str));
          if(idx == -1) {
              yyerror("Undeclared variable '%s' used in postfix decrement", (yyvsp[(1) - (2)].str));
              (yyval.val) = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable in decrement", (yyvsp[(1) - (2)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].init_value.is_const) {
              yyerror("Cannot decrement constant '%s'", (yyvsp[(1) - (2)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else {
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
              (yyval.val).name = quad_postfix("DEC", (yyvsp[(1) - (2)].str));
          }
      ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    { (yyval.val).name = NULL; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    { (yyval.val).name = NULL; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    { printf("[Line %d] If statement\n", line_num); enter_scope(); quad_if_start((yyvsp[(3) - (4)].val).name); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    { exit_scope(); quad_if_end(); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    { enter_scope(); quad_if_else(); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    { exit_scope(); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { is_loop++; printf("[Line %d] While loop\n", line_num); enter_scope(); quad_while_start((yyvsp[(3) - (4)].val).name) ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { is_loop--; exit_scope(); quad_while_end(); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { is_loop++; printf("[Line %d] Do-While loop\n", line_num); enter_scope(); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { is_loop--; exit_scope(); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { enter_scope(); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { 
          printf("[Line %d] For loop\n", line_num);
          is_loop++;
          quad_for_start(); 
      ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 333 "parser.y"
    { 
          quad_for_condition((yyvsp[(7) - (7)].val).name);
      ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 336 "parser.y"
    {
        quad_for_skip();
      ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    { 
          exit_scope();
          is_loop--;
          quad_for_end();
      ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    { enter_scope(); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    { 
          printf("[Line %d] For loop\n", line_num);
          is_loop++;
          quad_for_start(); 
      ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    { 
          quad_for_condition((yyvsp[(6) - (6)].val).name);
      ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {
          quad_for_skip();
      ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    { 
          exit_scope();
          is_loop--;
          quad_for_end();
      ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {  is_switch++; printf("[Line %d] Switch statement\n", line_num); enter_scope();  quad_switch_start((yyvsp[(3) - (4)].val).name); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    { exit_scope();  quad_switch_end(); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    { is_switch--; ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    { quad_switch_default(); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    { quad_switch_case_end(); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    { is_switch--; ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    {;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    { quad_switch_case((yyvsp[(3) - (3)].val).name); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    { quad_switch_case_end(); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 379 "parser.y"
    { 
        int idx = add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].type_val), true);
        if (idx != -1) {
            printf("[Line %d] Function definition: %s\n", line_num, (yyvsp[(2) - (3)].str)); 
            current_function_name = strdup((yyvsp[(2) - (3)].str));
            current_return_type = (yyvsp[(1) - (3)].type_val);
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
            seen_return = false;
            quad_function_declare((yyvsp[(2) - (3)].str), typeToString((yyvsp[(1) - (3)].type_val)));
        }
        enter_scope(); // Noitce that the function name itself is in a scope higher than the parameters and body 
      ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 393 "parser.y"
    {
          if (current_function_name != NULL) {
              if (current_return_type != TYPE_VOID && !seen_return) {
                  yyerror("Non-void function '%s' does not return a value", current_function_name);
              }
              quad_function_end(current_function_name);
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 405 "parser.y"
    { 
        int idx = add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].type_val), true);
        if (idx != -1) {
            printf("[Line %d] Function definition: %s\n", line_num, (yyvsp[(2) - (3)].str)); 
            current_function_name = strdup((yyvsp[(2) - (3)].str));
            current_return_type = (yyvsp[(1) - (3)].type_val);
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
            quad_function_declare((yyvsp[(2) - (3)].str), typeToString((yyvsp[(1) - (3)].type_val)));
        }
        enter_scope(); // Notice that the function name itself is in a scope higher than the parameters and body 
      ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    {
          if (current_function_name != NULL) {
              quad_function_end(current_function_name);
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 427 "parser.y"
    { yyerrok; exit_scope(); printf("skipping function body on line %d\n", line_num); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 431 "parser.y"
    {;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 436 "parser.y"
    {;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    { 
        if (seen_default_param)
            yyerror("Non-default parameter '%s' after a default one", (yyvsp[(2) - (2)].str));
        
        add_symbol((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].type_val), true);
        param_types.push_back((yyvsp[(1) - (2)].type_val));
        default_params.push_back(false);
        quad_function_param((yyvsp[(2) - (2)].str), typeToString((yyvsp[(1) - (2)].type_val)), NULL);
      ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 451 "parser.y"
    {
        if(!type_mismatch((yyvsp[(1) - (4)].type_val), (yyvsp[(4) - (4)].val).type)) {
            int idx = add_symbol((yyvsp[(2) - (4)].str), (yyvsp[(1) - (4)].type_val), true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = (yyvsp[(4) - (4)].val);
                symbol_table.table[idx].init_value.is_const = false;
            }
        }
        param_types.push_back((yyvsp[(1) - (4)].type_val));
        default_params.push_back(true);
        seen_default_param = true;
        quad_function_param((yyvsp[(2) - (4)].str), typeToString((yyvsp[(1) - (4)].type_val)), (yyvsp[(4) - (4)].val).name);
      ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 467 "parser.y"
    {
          printf("[Line %d] Function call: %s\n", line_num, (yyvsp[(1) - (4)].str)); 
          if(check_function_call((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].list_val))){
            // Convert list of arguments to vector of names
            std::vector<Value> arg_names;
            for (int i = 0; i < (yyvsp[(3) - (4)].list_val).size; i++) {
                arg_names.push_back((yyvsp[(3) - (4)].list_val).values[i]);
            }
            
            // Add quadruples for function call
            quad_function_call((yyvsp[(1) - (4)].str), arg_names);
          }
          (yyval.val) = make_runtime_value(get_function_return_type((yyvsp[(1) - (4)].str))); 
      ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 485 "parser.y"
    { (yyval.list_val) = make_empty_list(); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    { (yyval.list_val) = make_list((yyvsp[(1) - (1)].val)); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 492 "parser.y"
    { (yyval.list_val) = append_to_list((yyvsp[(1) - (3)].list_val), (yyvsp[(3) - (3)].val)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2403 "parser.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 494 "parser.y"


void yyerror(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    // Calculate required buffer size
    int len = snprintf(NULL, 0, "[Line %d] Error: ", line_num) + 
              vsnprintf(NULL, 0, format, args) + 1;
    
    // Allocate buffer
    char *msg = (char *)malloc(len);
    if (!msg) {
        va_end(args);
        return;
    }
    
    // Format the message
    sprintf(msg, "[Line %d] Error: ", line_num);
    vsprintf(msg + strlen(msg), format, args);
    
    fprintf(stderr, "%s\n", msg);
    free(msg);
    va_end(args);
}

int main(int argc, char **argv) {
    const char *input_fname = "test.mel";

    if (argc > 1) {
        input_fname = argv[1];
        size_t len = strlen(input_fname);
        if (len < 5 || strcmp(input_fname + len - 4, ".mel") != 0) {
            fprintf(stderr, "Error: input file must have a \".mel\" extension (got \"%s\")\n", input_fname);
            return 1;
        }
    }
    
    // Create output directory if it doesn't exist
    if (system("mkdir output") == -1) {
        fprintf(stderr, "Error: cannot create output directory\n");
        return 1;
    }

    if (freopen(input_fname, "r", stdin) == NULL) {
        fprintf(stderr, "Error: cannot open %s for reading\n", input_fname);
        exit(1);
    }
    if (freopen("output/errors.txt", "w", stderr) == NULL) {
        fprintf(stderr, "Error: cannot open output/errors.txt for writing\n");
        exit(1);
    }
    fprintf(stderr, "---------------------ERRORS---------------------\n");
    quad_init_file();
    yyparse();
    quad_close_table();
    fclose(stdin);
    fclose(stderr);
    print_symbol_table("output/symbol_table.txt");
    print_unused_symbols("output/errors.txt");
    
    return 0;
}

