
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
#include <vector>
#include <stdarg.h>

#include "quadruples.h"
#include "quadruples.cpp"
extern FILE *quadFile = nullptr;

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
bool is_loop = false;
bool is_switch = false;


/* Line 189 of yacc.c  */
#line 106 "parser.tab.c"

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
     UMINUS = 282
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 33 "parser.y"

    Value val;
    ListValue list_val;
    char *str;
    char *relop;
    int type_val;




/* Line 214 of yacc.c  */
#line 180 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 192 "parser.tab.c"

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
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   282

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    32,     2,     2,
      38,    39,    30,    28,    41,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    35,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    14,    16,    19,
      21,    24,    26,    28,    30,    32,    34,    38,    41,    44,
      45,    48,    52,    58,    65,    66,    72,    76,    78,    80,
      82,    84,    86,    88,    90,    92,    96,   100,   104,   108,
     112,   116,   119,   122,   126,   130,   134,   138,   140,   141,
     143,   144,   146,   147,   154,   156,   160,   161,   168,   169,
     170,   180,   181,   182,   194,   195,   196,   207,   208,   215,
     219,   226,   227,   233,   234,   242,   243,   251,   252,   254,
     256,   260,   263,   268,   273,   274,   276,   278
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    43,    45,    -1,    43,    72,    -1,
      -1,    44,    45,    -1,    47,    -1,    52,    35,    -1,    48,
      -1,    50,    35,    -1,    55,    -1,    58,    -1,    60,    -1,
      63,    -1,    68,    -1,    17,    52,    35,    -1,    21,    35,
      -1,    22,    35,    -1,    -1,    46,    47,    -1,     9,     8,
      35,    -1,     9,     8,    27,    51,    35,    -1,    23,     9,
       8,    27,    51,    35,    -1,    -1,    36,    49,    46,    44,
      37,    -1,     8,    27,    51,    -1,    52,    -1,    50,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,
       8,    -1,    52,    28,    52,    -1,    52,    29,    52,    -1,
      52,    30,    52,    -1,    52,    31,    52,    -1,    52,    32,
      52,    -1,    52,    26,    52,    -1,    29,    52,    -1,    33,
      52,    -1,    52,    24,    52,    -1,    52,    25,    52,    -1,
      38,    52,    39,    -1,    52,    11,    52,    -1,    78,    -1,
      -1,    52,    -1,    -1,    50,    -1,    -1,    12,    38,    52,
      39,    56,    57,    -1,    45,    -1,    45,    13,    45,    -1,
      -1,    14,    38,    52,    39,    59,    45,    -1,    -1,    -1,
      15,    61,    45,    62,    14,    38,    52,    39,    35,    -1,
      -1,    -1,    16,    38,    64,    54,    35,    53,    35,    54,
      39,    65,    45,    -1,    -1,    -1,    16,    38,    66,    47,
      53,    35,    54,    39,    67,    45,    -1,    -1,    18,    38,
      52,    39,    69,    70,    -1,    36,    71,    37,    -1,    36,
      71,    20,    40,    44,    37,    -1,    -1,    71,    19,     3,
      40,    44,    -1,    -1,     9,     8,    38,    73,    75,    39,
      48,    -1,    -1,    10,     8,    38,    74,    75,    39,    48,
      -1,    -1,    76,    -1,    77,    -1,    76,    41,    77,    -1,
       9,     8,    -1,     9,     8,    27,    51,    -1,     8,    38,
      79,    39,    -1,    -1,    80,    -1,    52,    -1,    80,    41,
      52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    73,    77,    78,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   103,   104,   108,
     109,   113,   121,   143,   160,   160,   164,   186,   187,   191,
     192,   193,   194,   195,   196,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   236,   237,
     241,   242,   247,   247,   251,   252,   255,   255,   259,   259,
     259,   263,   264,   263,   272,   273,   272,   284,   284,   288,
     289,   293,   294,   299,   299,   324,   324,   348,   349,   353,
     354,   358,   366,   382,   391,   392,   397,   398
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
  "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "';'", "'{'",
  "'}'", "'('", "')'", "':'", "','", "$accept", "program", "statements",
  "statement", "declarations", "declaration", "block", "$@1", "assignment",
  "expression_or_assignment", "expression", "opt_expression",
  "opt_assignment", "if_statement", "$@2", "if_body", "while_statement",
  "$@3", "do_while_statement", "$@4", "$@5", "for_statement", "$@6", "$@7",
  "$@8", "$@9", "switch_statement", "$@10", "switch_body", "case_list",
  "function", "$@11", "$@12", "parameters", "parameter_list", "parameter",
  "function_call", "argument_list_opt", "non_empty_argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    61,    43,    45,
      42,    47,    37,    33,   282,    59,   123,   125,    40,    41,
      58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    47,    49,    48,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    53,    53,
      54,    54,    56,    55,    57,    57,    59,    58,    61,    62,
      60,    64,    65,    63,    66,    67,    63,    69,    68,    70,
      70,    71,    71,    73,    72,    74,    72,    75,    75,    76,
      76,    77,    77,    78,    79,    79,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     3,     2,     2,     0,
       2,     3,     5,     6,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     1,     0,     1,
       0,     1,     0,     6,     1,     3,     0,     6,     0,     0,
       9,     0,     0,    11,     0,     0,    10,     0,     6,     3,
       6,     0,     5,     0,     7,     0,     7,     0,     1,     1,
       3,     2,     4,     4,     0,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    29,    30,    31,    32,    33,    34,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     3,     7,     9,     0,     0,    11,
      12,    13,    14,    15,     4,    47,     0,    84,     0,     0,
       0,     0,     0,    61,    34,     0,     0,    17,    18,     0,
      41,    42,    19,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    28,    26,    27,    86,     0,
      85,     0,    21,    73,    75,     0,     0,     0,    59,    50,
       0,    16,     0,     0,     5,    45,    46,    43,    44,    40,
      35,    36,    37,    38,    39,    83,     0,     0,    77,    77,
      52,    56,     0,     0,     0,    51,     0,    48,    67,     0,
       0,    20,    87,    22,     0,     0,    78,    79,     0,     0,
       0,     0,    48,    49,     0,     0,     0,    25,     6,    81,
       0,     0,     0,    54,    53,    57,     0,     0,    50,    71,
      68,    23,     0,    74,    80,    76,     0,     0,    50,     0,
       0,    82,    55,     0,     0,    65,     0,     0,    69,    60,
      62,     0,     0,     5,     0,    66,     5,     0,    63,    72,
      70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   110,   128,    84,    25,    26,    52,    27,    66,
      28,   124,   106,    29,   119,   134,    30,   120,    31,    42,
     103,    32,    79,   164,    80,   161,    33,   125,   140,   150,
      34,    98,    99,   115,   116,   117,    35,    69,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
    -153,    59,  -153,  -153,  -153,  -153,  -153,  -153,   -12,     8,
      17,    -9,     2,  -153,    13,   240,    19,    20,    35,    70,
     240,   240,  -153,   240,  -153,  -153,  -153,    49,   305,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,   246,   240,    51,    52,
     240,   240,   204,    -4,    55,   317,   240,  -153,  -153,    79,
      75,    75,  -153,    74,  -153,   240,   240,   240,   240,   240,
     240,   240,   240,   240,  -153,  -153,  -153,     6,     6,    68,
      67,   246,  -153,  -153,  -153,   257,   269,   103,  -153,   104,
      -3,  -153,   281,    90,    -3,  -153,   334,   230,   327,    75,
      84,    84,    75,    75,    75,  -153,   240,    86,   113,   113,
    -153,  -153,    25,   111,    99,  -153,    92,   240,  -153,   246,
     132,  -153,     6,  -153,   120,    93,   101,  -153,    94,   204,
     204,    96,   240,     6,   108,    95,   116,  -153,  -153,   125,
     121,   113,   121,   143,  -153,  -153,   240,   123,   104,  -153,
    -153,  -153,   246,  -153,  -153,  -153,   204,   293,   104,   127,
     -16,  -153,  -153,   124,   128,  -153,   159,   138,  -153,  -153,
    -153,   204,   139,  -153,   204,  -153,  -153,   168,  -153,   204,
    -153
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -152,    -1,  -153,   -71,   -76,  -153,   -18,   -70,
     -13,    42,  -126,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,    82,  -153,    56,  -153,  -153,  -153
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      24,    97,    45,   156,   157,   -64,    77,    50,    51,   107,
      53,   167,   149,   111,   169,    36,    38,    55,    65,   -64,
      19,   158,   154,    67,    68,    39,    37,    75,    76,    40,
      56,    57,    58,    82,    59,    60,    61,    62,    63,   126,
      41,    78,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    43,    71,    65,   143,    47,   145,    46,    67,     2,
      72,   105,     3,     4,     5,     6,     7,     8,     9,    10,
      48,    11,   151,    12,    13,    14,    15,    16,    71,    49,
      17,    18,    19,   112,    54,    55,    72,    83,    20,    73,
      74,    65,    21,    37,   123,    22,    67,    23,    56,    57,
      58,    58,    59,    60,    61,    62,    63,    95,    96,   123,
      58,   102,   104,    85,    61,    62,    63,   109,   133,   135,
     105,   113,   114,   147,    65,   121,    36,   122,   129,    67,
     105,   139,   130,   132,   136,     3,     4,     5,     6,     7,
       8,    77,   131,   138,    11,   152,    12,    13,    14,    15,
      16,   141,   142,    17,    18,    19,   146,    22,   148,   159,
     165,    20,   162,   168,   137,    21,   155,   160,    22,   127,
      23,     3,     4,     5,     6,     7,     8,    77,   163,   166,
      11,   118,    12,    13,    14,    15,    16,   144,     0,    17,
      18,    19,     0,     0,     0,     0,     0,    20,     0,     0,
       0,    21,     0,     0,    22,   170,    23,     3,     4,     5,
       6,     7,     8,    77,     0,     0,    11,     0,    12,    13,
      14,    15,    16,     0,     0,    17,    18,    19,     0,     0,
       0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
      22,    55,    23,     3,     4,     5,     6,     7,    44,     3,
       4,     5,     6,     7,     8,     0,    58,     0,    59,    60,
      61,    62,    63,     0,     0,     0,     0,     0,    55,    20,
       0,     0,     0,    21,     0,    20,     0,     0,    23,    21,
      55,    56,    57,    58,    23,    59,    60,    61,    62,    63,
       0,     0,    55,    56,    57,    58,   100,    59,    60,    61,
      62,    63,     0,     0,    55,    56,    57,    58,   101,    59,
      60,    61,    62,    63,     0,     0,    55,    56,    57,    58,
     108,    59,    60,    61,    62,    63,     0,     0,    55,    56,
      57,    58,   153,    59,    60,    61,    62,    63,    55,     0,
      64,    56,    57,    58,     0,    59,    60,    61,    62,    63,
       0,    56,    81,    58,     0,    59,    60,    61,    62,    63,
      58,     0,    59,    60,    61,    62,    63
};

static const yytype_int16 yycheck[] =
{
       1,    71,    15,    19,    20,     9,     9,    20,    21,    80,
      23,   163,   138,    84,   166,    27,     8,    11,    36,    23,
      23,    37,   148,    36,    37,     8,    38,    40,    41,    38,
      24,    25,    26,    46,    28,    29,    30,    31,    32,   109,
      38,    42,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    38,    27,    71,   130,    35,   132,    38,    71,     0,
      35,    79,     3,     4,     5,     6,     7,     8,     9,    10,
      35,    12,   142,    14,    15,    16,    17,    18,    27,     9,
      21,    22,    23,    96,    35,    11,    35,     8,    29,    38,
      38,   109,    33,    38,   107,    36,   109,    38,    24,    25,
      26,    26,    28,    29,    30,    31,    32,    39,    41,   122,
      26,     8,     8,    39,    30,    31,    32,    27,   119,   120,
     138,    35,     9,   136,   142,    14,    27,    35,     8,   142,
     148,    36,    39,    39,    38,     3,     4,     5,     6,     7,
       8,     9,    41,    35,    12,   146,    14,    15,    16,    17,
      18,    35,    27,    21,    22,    23,    13,    36,    35,    35,
     161,    29,     3,   164,   122,    33,    39,    39,    36,    37,
      38,     3,     4,     5,     6,     7,     8,     9,    40,    40,
      12,    99,    14,    15,    16,    17,    18,   131,    -1,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    -1,    -1,    36,    37,    38,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,    -1,
      36,    11,    38,     3,     4,     5,     6,     7,     8,     3,
       4,     5,     6,     7,     8,    -1,    26,    -1,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    -1,    11,    29,
      -1,    -1,    -1,    33,    -1,    29,    -1,    -1,    38,    33,
      11,    24,    25,    26,    38,    28,    29,    30,    31,    32,
      -1,    -1,    11,    24,    25,    26,    39,    28,    29,    30,
      31,    32,    -1,    -1,    11,    24,    25,    26,    39,    28,
      29,    30,    31,    32,    -1,    -1,    11,    24,    25,    26,
      39,    28,    29,    30,    31,    32,    -1,    -1,    11,    24,
      25,    26,    39,    28,    29,    30,    31,    32,    11,    -1,
      35,    24,    25,    26,    -1,    28,    29,    30,    31,    32,
      -1,    24,    35,    26,    -1,    28,    29,    30,    31,    32,
      26,    -1,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    12,    14,    15,    16,    17,    18,    21,    22,    23,
      29,    33,    36,    38,    45,    47,    48,    50,    52,    55,
      58,    60,    63,    68,    72,    78,    27,    38,     8,     8,
      38,    38,    61,    38,     8,    52,    38,    35,    35,     9,
      52,    52,    49,    52,    35,    11,    24,    25,    26,    28,
      29,    30,    31,    32,    35,    50,    51,    52,    52,    79,
      80,    27,    35,    38,    38,    52,    52,     9,    45,    64,
      66,    35,    52,     8,    46,    39,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    39,    41,    51,    73,    74,
      39,    39,     8,    62,     8,    50,    54,    47,    39,    27,
      44,    47,    52,    35,     9,    75,    76,    77,    75,    56,
      59,    14,    35,    52,    53,    69,    51,    37,    45,     8,
      39,    41,    39,    45,    57,    45,    38,    53,    35,    36,
      70,    35,    27,    48,    77,    48,    13,    52,    35,    54,
      71,    51,    45,    39,    54,    39,    19,    20,    37,    35,
      39,    67,     3,    40,    65,    45,    40,    44,    45,    44,
      37
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
#line 71 "parser.y"
    { ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (2)].val); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    { 
          if(current_return_type == -1) {
              yyerror("Return statement not in function");
          } else {
              seen_return = true;
              if(current_return_type == TYPE_VOID) {
                  yyerror("Void function cannot return a value");
              } else if(!type_mismatch(current_return_type, (yyvsp[(2) - (3)].val).type)) {
                  printf("[Line %d] Return statement\n", line_num);
              }   
          }
      ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { if(!is_loop && !is_switch) yyerror("Break statement not in loop or switch"); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { if(!is_loop) yyerror("Continue statement not in loop"); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {
          int idx = add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].type_val));
          if (idx != -1) {
            printf("[Line %d] Declaration: %s\n", line_num, (yyvsp[(2) - (3)].str));
            quad_handle_identifier((yyvsp[(2) - (3)].str), "STORE");

          }
      ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {
          /* check type compatibility between declared type and initializer */
          if(!type_mismatch((yyvsp[(1) - (5)].type_val), (yyvsp[(4) - (5)].val).type)) {
            int idx = add_symbol((yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].type_val), true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = (yyvsp[(4) - (5)].val);
                symbol_table.table[idx].init_value.is_const = false;
                printf("[Line %d] Declaration with init: %s = ...\n", line_num, (yyvsp[(2) - (5)].str));

                quad_handle_identifier((yyvsp[(2) - (5)].str), "STORE");

                if ((yyvsp[(1) - (5)].type_val) == TYPE_INT) {
                    quad_push_integer((yyvsp[(4) - (5)].val).data.ival);       //
                }else if ((yyvsp[(1) - (5)].type_val) == TYPE_FLOAT) {
                    quad_push_float((yyvsp[(4) - (5)].val).data.fval);
                }else if ((yyvsp[(1) - (5)].type_val) == TYPE_STRING || (yyvsp[(1) - (5)].type_val) == TYPE_CHAR) {
                    quad_push_string((yyvsp[(4) - (5)].val).data.sval);
                }
                quad_handle_identifier((yyvsp[(2) - (5)].str), "STORE");
            }
          }
      ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {
        /* check type compatibility between declared type and initializer */
        if(!type_mismatch((yyvsp[(2) - (6)].type_val), (yyvsp[(5) - (6)].val).type)) {
            int idx = add_symbol((yyvsp[(3) - (6)].str), (yyvsp[(2) - (6)].type_val), true);
            if(idx != -1) {
                symbol_table.table[idx].init_value = (yyvsp[(5) - (6)].val);
                symbol_table.table[idx].init_value.is_const = true;
                printf("[Line %d] Constant declaration: %s = ...\n", line_num, (yyvsp[(3) - (6)].str));

                quad_handle_identifier((yyvsp[(3) - (6)].str), "STORE");
            } 

        }
      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { enter_block_scope(); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    { exit_scope(); (yyval.val) = (yyvsp[(4) - (5)].val); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
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
              type_mismatch(symbol_table.table[idx].type, (yyvsp[(3) - (3)].val).type);
          }

      ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {
          int idx = find_symbol((yyvsp[(1) - (1)].str));
          if(idx == -1) {
              yyerror("Undeclared variable used in expression");
              (yyval.val) = make_runtime_value(TYPE_INT);
          } 
          else if(is_function(idx)) {
              yyerror("Function '%s' used as variable", (yyvsp[(1) - (1)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else if(symbol_table.table[idx].is_initialized == false) {
              yyerror("Variable '%s' used before initialization", (yyvsp[(1) - (1)].str));
              (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
          }
          else{
              symbol_table.table[idx].is_used = true;
              if(symbol_table.table[idx].init_value.is_const && symbol_table.table[idx].init_value.is_evaluated) {
                  (yyval.val) = symbol_table.table[idx].init_value;
              } 
              else {
                  (yyval.val) = make_runtime_value(symbol_table.table[idx].type);
              }
          }
      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyval.val) = add_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 221 "parser.y"
    { (yyval.val) = sub_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    { (yyval.val) = mul_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    { (yyval.val) = div_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { (yyval.val) = mod_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 225 "parser.y"
    { (yyval.val) = pow_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 226 "parser.y"
    { (yyval.val) = neg_value((yyvsp[(2) - (2)].val)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 227 "parser.y"
    { (yyval.val) = not_value((yyvsp[(2) - (2)].val)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    { (yyval.val) = and_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    { (yyval.val) = or_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    { (yyval.val) = compare_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyvsp[(2) - (3)].relop)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    {;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { printf("[Line %d] If statement\n", line_num); enter_scope(); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { exit_scope(); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    { is_loop = true; printf("[Line %d] While loop\n", line_num); enter_scope(); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    { is_loop = false; exit_scope(); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    { is_loop = true; printf("[Line %d] Do-While loop\n", line_num); enter_scope(); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    { is_loop = false; exit_scope(); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 259 "parser.y"
    {;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { enter_scope(); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    {
          printf("[Line %d] For loop\n", line_num);
          is_loop = true;
      ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    {
          exit_scope();
          is_loop = false;
      ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    { enter_scope(); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {
          printf("[Line %d] For loop\n", line_num);
          is_loop = true;
      ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    {
          exit_scope();
          is_loop = false;
      ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {  is_switch = true; printf("[Line %d] Switch statement\n", line_num); enter_scope(); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { exit_scope(); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    { is_switch = false; ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 289 "parser.y"
    { is_switch = false; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    {;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { 
        int idx = add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].type_val), true);
        if (idx == -1) {
        } else {
            printf("[Line %d] Function definition: %s\n", line_num, (yyvsp[(2) - (3)].str)); 
            current_function_name = strdup((yyvsp[(2) - (3)].str));
            current_return_type = (yyvsp[(1) - (3)].type_val);
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
            seen_return = false;
        }
        enter_scope(); // Noitce that the function name itself is in a scope higher than the parameters and body 
      ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    {
          if (current_function_name != NULL) {
              if (current_return_type != TYPE_VOID && !seen_return) {
                  yyerror("Non-void function '%s' does not return a value", current_function_name);
              }
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { 
        int idx = add_symbol((yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].type_val), true);
        if (idx == -1) {
        } else {
            printf("[Line %d] Function definition: %s\n", line_num, (yyvsp[(2) - (3)].str)); 
            current_function_name = strdup((yyvsp[(2) - (3)].str));
            current_return_type = (yyvsp[(1) - (3)].type_val);
            current_function_idx = idx;
            param_types.clear();
            default_params.clear();
            seen_default_param = false;
        }
        enter_scope(); // Noitce that the function name itself is in a scope higher than the parameters and body 
      ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {
          if (current_function_name != NULL) {
              add_function(current_function_idx, current_function_name, current_return_type, param_types, default_params);
              free(current_function_name);
              current_return_type = -1;
          } 
          exit_scope(); 
      ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 348 "parser.y"
    {;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 353 "parser.y"
    {;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    { 
        if (seen_default_param)
            yyerror("Non-default parameter '%s' after a default one", (yyvsp[(2) - (2)].str));
        
        add_symbol((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].type_val), true);
        param_types.push_back((yyvsp[(1) - (2)].type_val));
        default_params.push_back(false);
      ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
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
      ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    {
          printf("[Line %d] Function call: %s\n", line_num, (yyvsp[(1) - (4)].str)); 
          check_function_call((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].list_val));
          (yyval.val) = make_runtime_value(get_function_return_type((yyvsp[(1) - (4)].str))); 
      ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
    { (yyval.list_val) = make_empty_list(); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 397 "parser.y"
    { (yyval.list_val) = make_list((yyvsp[(1) - (1)].val)); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 398 "parser.y"
    { (yyval.list_val) = append_to_list((yyvsp[(1) - (3)].list_val), (yyvsp[(3) - (3)].val)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2173 "parser.tab.c"
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
#line 400 "parser.y"


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
    const char *input_fname = "input.mel";

    if (argc > 1) {
        input_fname = argv[1];
        size_t len = strlen(input_fname);
        if (len < 5 || strcmp(input_fname + len - 4, ".mel") != 0) {
            fprintf(stderr, "Error: input file must have a \".mel\" extension (got \"%s\")\n", input_fname);
            return 1;
        }
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
    quadFile = quad_init_file("./output/quad.txt");
    quad_set_output("./output/quad.txt", quadFile);
    yyparse();
    fclose(stdin);
    fclose(stderr);
    print_symbol_table("output/symbol_table.txt");
    print_unused_symbols("output/errors.txt");
    
    return 0;
}

