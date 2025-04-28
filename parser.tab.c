
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
bool is_loop = false;
bool is_switch = false;


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
     UMINUS = 282
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
#line 177 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "parser.tab.c"

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
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNRULES -- Number of states.  */
#define YYNSTATES  183

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
      47,    48,    51,    55,    61,    68,    69,    75,    79,    81,
      83,    85,    87,    89,    91,    93,    95,    99,   103,   107,
     111,   115,   119,   122,   125,   129,   133,   137,   141,   143,
     144,   146,   147,   149,   150,   157,   159,   160,   165,   166,
     173,   174,   175,   185,   186,   187,   188,   189,   203,   204,
     205,   206,   207,   220,   221,   228,   232,   233,   234,   243,
     244,   245,   252,   253,   261,   262,   270,   273,   274,   276,
     278,   282,   285,   290,   295,   296,   298,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    43,    45,    -1,    43,    80,    -1,
      -1,    44,    45,    -1,    47,    -1,    52,    35,    -1,    48,
      -1,    50,    35,    -1,    55,    -1,    59,    -1,    61,    -1,
      64,    -1,    73,    -1,    17,    53,    35,    -1,    21,    35,
      -1,    22,    35,    -1,     1,    35,    -1,    -1,    46,    47,
      -1,     9,     8,    35,    -1,     9,     8,    27,    51,    35,
      -1,    23,     9,     8,    27,    51,    35,    -1,    -1,    36,
      49,    46,    44,    37,    -1,     8,    27,    51,    -1,    52,
      -1,    50,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,    52,    28,    52,    -1,    52,
      29,    52,    -1,    52,    30,    52,    -1,    52,    31,    52,
      -1,    52,    32,    52,    -1,    52,    26,    52,    -1,    29,
      52,    -1,    33,    52,    -1,    52,    24,    52,    -1,    52,
      25,    52,    -1,    38,    52,    39,    -1,    52,    11,    52,
      -1,    86,    -1,    -1,    52,    -1,    -1,    50,    -1,    -1,
      12,    38,    52,    39,    56,    57,    -1,    45,    -1,    -1,
      45,    13,    58,    45,    -1,    -1,    14,    38,    52,    39,
      60,    45,    -1,    -1,    -1,    15,    62,    45,    63,    14,
      38,    52,    39,    35,    -1,    -1,    -1,    -1,    -1,    16,
      38,    65,    54,    35,    66,    53,    67,    35,    54,    68,
      39,    45,    -1,    -1,    -1,    -1,    -1,    16,    38,    69,
      47,    70,    53,    71,    35,    54,    72,    39,    45,    -1,
      -1,    18,    38,    52,    39,    74,    75,    -1,    36,    78,
      37,    -1,    -1,    -1,    36,    78,    20,    76,    40,    44,
      77,    37,    -1,    -1,    -1,    78,    19,     3,    79,    40,
      44,    -1,    -1,     9,     8,    38,    81,    83,    39,    48,
      -1,    -1,    10,     8,    38,    82,    83,    39,    48,    -1,
       1,    37,    -1,    -1,    84,    -1,    85,    -1,    84,    41,
      85,    -1,     9,     8,    -1,     9,     8,    27,    51,    -1,
       8,    38,    87,    39,    -1,    -1,    88,    -1,    52,    -1,
      88,    41,    52,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    68,    68,    69,    70,    74,    75,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,   101,   102,   103,
     107,   108,   112,   119,   131,   146,   146,   150,   174,   175,
     179,   180,   181,   182,   183,   184,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   226,
     227,   231,   232,   237,   237,   241,   242,   242,   245,   245,
     249,   249,   249,   253,   253,   257,   260,   253,   269,   269,
     273,   276,   269,   288,   288,   292,   293,   293,   293,   297,
     298,   298,   303,   303,   329,   329,   351,   355,   356,   360,
     361,   365,   374,   391,   409,   410,   415,   416
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
     275,   276,   277,   278,   279,   280,   281,    61,    43,    45,
      42,    47,    37,    33,   282,    59,   123,   125,    40,    41,
      58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      46,    46,    47,    47,    47,    49,    48,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    54,    54,    56,    55,    57,    58,    57,    60,    59,
      62,    63,    61,    65,    66,    67,    68,    64,    69,    70,
      71,    72,    64,    74,    73,    75,    76,    77,    75,    78,
      79,    78,    81,    80,    82,    80,    80,    83,    83,    84,
      84,    85,    85,    86,    87,    87,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       0,     2,     3,     5,     6,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     1,     0,
       1,     0,     1,     0,     6,     1,     0,     4,     0,     6,
       0,     0,     9,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    12,     0,     6,     3,     0,     0,     8,     0,
       0,     6,     0,     7,     0,     7,     2,     0,     1,     1,
       3,     2,     4,     4,     0,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    30,    31,    32,    33,    34,    35,
       0,     0,     0,     0,    60,     0,    49,     0,     0,     0,
       0,     0,     0,    25,     0,     3,     7,     9,     0,     0,
      11,    12,    13,    14,    15,     4,    48,    19,    86,     0,
      94,     0,     0,     0,     0,     0,    63,    35,    50,     0,
       0,    17,    18,     0,    42,    43,    20,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    29,
      27,    28,    96,     0,    95,     0,    22,    82,    84,     0,
       0,     0,     0,    61,    51,     0,    16,     0,     0,     5,
      46,    47,    44,    45,    41,    36,    37,    38,    39,    40,
      93,     0,     0,    87,    87,    53,    58,     0,     0,     0,
      52,     0,    69,    73,     0,     0,    21,    97,    23,     0,
       0,    88,    89,     0,     0,     0,     0,    64,    49,     0,
       0,    26,     6,    91,     0,     0,     0,    55,    54,    59,
       0,    49,    70,    79,    74,    24,     0,    83,    90,    85,
      56,     0,    65,     0,     0,    92,     0,     0,     0,    51,
       0,    76,    75,    57,    62,    51,    71,    80,     0,    66,
       0,     0,     5,     0,     0,     5,     0,     0,    72,     0,
       0,    67,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   115,   132,    89,    26,    27,    56,    28,    70,
      29,    49,   111,    30,   124,   138,   156,    31,   125,    32,
      45,   108,    33,    84,   141,   158,   173,    85,   128,   153,
     170,    34,   129,   144,   168,   180,   154,   171,    35,   103,
     104,   120,   121,   122,    36,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -149
static const yytype_int16 yypact[] =
{
    -149,    74,  -149,   -22,  -149,  -149,  -149,  -149,  -149,   -15,
       6,    34,     5,    18,  -149,    20,   292,    21,    25,    35,
      60,   292,   292,  -149,   292,  -149,  -149,  -149,    38,   105,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   298,
     292,   -11,    33,   292,   292,   256,    -4,    47,   369,    41,
     292,  -149,  -149,    86,    72,    72,  -149,   309,  -149,   292,
     292,   292,   292,   292,   292,   292,   292,   292,  -149,  -149,
    -149,   369,   369,    62,    58,   298,  -149,  -149,  -149,   321,
     333,    67,    96,  -149,    97,    -3,  -149,   345,    79,    -3,
    -149,    36,   282,   379,    72,     2,     2,    72,    72,    72,
    -149,   292,    73,   100,   100,  -149,  -149,     4,    99,    84,
    -149,    80,  -149,  -149,   298,   180,  -149,   369,  -149,   109,
      81,    77,  -149,    82,   256,   256,    90,  -149,   292,    83,
      87,  -149,  -149,   112,   106,   100,   106,   128,  -149,  -149,
     292,   292,  -149,  -149,  -149,  -149,   298,  -149,  -149,  -149,
    -149,   357,  -149,   117,   -16,  -149,   256,   118,   131,    97,
     164,  -149,  -149,  -149,  -149,    97,  -149,  -149,   129,  -149,
     133,   130,  -149,   135,   256,  -149,   218,   256,  -149,   142,
     140,  -149,  -149
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,  -149,  -137,    -1,  -149,   -48,   -79,  -149,   -21,   -74,
     -14,  -119,  -148,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,    64,  -149,    55,  -149,  -149,  -149
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      25,   102,    48,   160,   161,   -68,    82,    54,    55,   142,
      57,   166,    39,    37,    41,    38,    75,   169,    69,   -68,
      20,   162,   152,    40,    76,    71,    72,    77,    62,    79,
      80,    75,    65,    66,    67,   176,    87,   112,   179,    76,
     130,   116,    42,    43,    83,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    69,   147,    44,   149,    46,    50,
      51,    71,    62,   110,    63,    64,    65,    66,    67,    53,
      52,    78,   155,    58,     2,     3,    86,     4,     5,     6,
       7,     8,     9,    10,    11,    40,    12,   117,    13,    14,
      15,    16,    17,    69,    88,    18,    19,    20,    62,   101,
      71,   100,    37,    21,   107,   109,   114,    22,   118,   119,
      23,    39,    24,   126,    48,   127,    59,   133,   135,   143,
     134,   136,   145,   137,   139,    69,   151,    48,   140,    60,
      61,    62,    71,    63,    64,    65,    66,    67,   110,   146,
      68,   150,    23,    81,   110,     4,     5,     6,     7,     8,
       9,    82,   159,   164,    12,   163,    13,    14,    15,    16,
      17,   -81,   -81,    18,    19,    20,   165,   167,   123,   172,
     175,    21,   174,   178,   177,    22,   181,   182,    23,   -81,
      24,    81,     0,     4,     5,     6,     7,     8,     9,    82,
     148,     0,    12,     0,    13,    14,    15,    16,    17,     0,
       0,    18,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,     0,     0,    23,   131,    24,    81,
       0,     4,     5,     6,     7,     8,     9,    82,     0,     0,
      12,     0,    13,    14,    15,    16,    17,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,     0,    23,   -77,    24,    81,     0,     4,
       5,     6,     7,     8,     9,    82,     0,     0,    12,     0,
      13,    14,    15,    16,    17,     0,     0,    18,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
       0,     0,    23,    59,    24,     4,     5,     6,     7,     8,
      47,     4,     5,     6,     7,     8,     9,     0,    62,     0,
      63,    64,    65,    66,    67,     0,     0,     0,     0,     0,
      59,    21,     0,     0,     0,    22,     0,    21,     0,     0,
      24,    22,    59,    60,    61,    62,    24,    63,    64,    65,
      66,    67,     0,     0,    59,    60,    61,    62,    90,    63,
      64,    65,    66,    67,     0,     0,    59,    60,    61,    62,
     105,    63,    64,    65,    66,    67,     0,     0,    59,    60,
      61,    62,   106,    63,    64,    65,    66,    67,     0,     0,
      59,    60,    61,    62,   113,    63,    64,    65,    66,    67,
      59,     0,     0,    60,    61,    62,   157,    63,    64,    65,
      66,    67,     0,    60,     0,    62,     0,    63,    64,    65,
      66,    67
};

static const yytype_int16 yycheck[] =
{
       1,    75,    16,    19,    20,     9,     9,    21,    22,   128,
      24,   159,    27,    35,     8,    37,    27,   165,    39,    23,
      23,    37,   141,    38,    35,    39,    40,    38,    26,    43,
      44,    27,    30,    31,    32,   172,    50,    85,   175,    35,
     114,    89,     8,    38,    45,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    75,   134,    38,   136,    38,    38,
      35,    75,    26,    84,    28,    29,    30,    31,    32,     9,
      35,    38,   146,    35,     0,     1,    35,     3,     4,     5,
       6,     7,     8,     9,    10,    38,    12,   101,    14,    15,
      16,    17,    18,   114,     8,    21,    22,    23,    26,    41,
     114,    39,    35,    29,     8,     8,    27,    33,    35,     9,
      36,    27,    38,    14,   128,    35,    11,     8,    41,    36,
      39,    39,    35,   124,   125,   146,   140,   141,    38,    24,
      25,    26,   146,    28,    29,    30,    31,    32,   159,    27,
      35,    13,    36,     1,   165,     3,     4,     5,     6,     7,
       8,     9,    35,    35,    12,   156,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    35,     3,   104,    40,
      40,    29,    39,   174,    39,    33,   177,    37,    36,    37,
      38,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
     135,    -1,    12,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    -1,    -1,    36,    37,    38,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    15,    16,    17,    18,    -1,    -1,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    -1,    -1,    36,    37,    38,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      -1,    -1,    36,    11,    38,     3,     4,     5,     6,     7,
       8,     3,     4,     5,     6,     7,     8,    -1,    26,    -1,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      11,    29,    -1,    -1,    -1,    33,    -1,    29,    -1,    -1,
      38,    33,    11,    24,    25,    26,    38,    28,    29,    30,
      31,    32,    -1,    -1,    11,    24,    25,    26,    39,    28,
      29,    30,    31,    32,    -1,    -1,    11,    24,    25,    26,
      39,    28,    29,    30,    31,    32,    -1,    -1,    11,    24,
      25,    26,    39,    28,    29,    30,    31,    32,    -1,    -1,
      11,    24,    25,    26,    39,    28,    29,    30,    31,    32,
      11,    -1,    -1,    24,    25,    26,    39,    28,    29,    30,
      31,    32,    -1,    24,    -1,    26,    -1,    28,    29,    30,
      31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    12,    14,    15,    16,    17,    18,    21,    22,
      23,    29,    33,    36,    38,    45,    47,    48,    50,    52,
      55,    59,    61,    64,    73,    80,    86,    35,    37,    27,
      38,     8,     8,    38,    38,    62,    38,     8,    52,    53,
      38,    35,    35,     9,    52,    52,    49,    52,    35,    11,
      24,    25,    26,    28,    29,    30,    31,    32,    35,    50,
      51,    52,    52,    87,    88,    27,    35,    38,    38,    52,
      52,     1,     9,    45,    65,    69,    35,    52,     8,    46,
      39,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      39,    41,    51,    81,    82,    39,    39,     8,    63,     8,
      50,    54,    47,    39,    27,    44,    47,    52,    35,     9,
      83,    84,    85,    83,    56,    60,    14,    35,    70,    74,
      51,    37,    45,     8,    39,    41,    39,    45,    57,    45,
      38,    66,    53,    36,    75,    35,    27,    48,    85,    48,
      13,    52,    53,    71,    78,    51,    58,    39,    67,    35,
      19,    20,    37,    45,    35,    35,    54,     3,    76,    54,
      72,    79,    40,    68,    39,    40,    44,    39,    45,    44,
      77,    45,    37
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
#line 226 "parser.y"
    { (yyval.val).name = NULL; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    { (yyval.val).name = NULL; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { printf("[Line %d] If statement\n", line_num); enter_scope(); quad_if_start((yyvsp[(3) - (4)].val).name); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { exit_scope(); quad_if_end(); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { enter_scope(); quad_if_else(); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { exit_scope(); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { is_loop = true; printf("[Line %d] While loop\n", line_num); enter_scope(); quad_while_start((yyvsp[(3) - (4)].val).name) ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { is_loop = false; exit_scope(); quad_while_end(); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { is_loop = true; printf("[Line %d] Do-While loop\n", line_num); enter_scope(); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { is_loop = false; exit_scope(); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    { enter_scope(); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    { 
          printf("[Line %d] For loop\n", line_num);
          is_loop = true;
          quad_for_start(); 
      ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    { 
          quad_for_condition((yyvsp[(7) - (7)].val).name);
      ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 260 "parser.y"
    {
        quad_for_skip();
      ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    { 
          exit_scope();
          is_loop = false;
          quad_for_end();
      ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    { enter_scope(); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    { 
          printf("[Line %d] For loop\n", line_num);
          is_loop = true;
          quad_for_start(); 
      ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { 
          quad_for_condition((yyvsp[(6) - (6)].val).name);
      ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {
          quad_for_skip();
      ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    { 
          exit_scope();
          is_loop = false;
          quad_for_end();
      ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {  is_switch = true; printf("[Line %d] Switch statement\n", line_num); enter_scope();  quad_switch_start((yyvsp[(3) - (4)].val).name); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    { exit_scope();  quad_switch_end(); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    { is_switch = false; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { quad_switch_default(); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { quad_switch_case_end(); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { is_switch = false; ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { quad_switch_case((yyvsp[(3) - (3)].val).name); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    { quad_switch_case_end(); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
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

  case 83:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
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

  case 84:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
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

  case 85:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
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

  case 86:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    { yyerrok; exit_scope(); printf("skipping function body on line %d\n", line_num); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 355 "parser.y"
    {;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    {;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    { 
        if (seen_default_param)
            yyerror("Non-default parameter '%s' after a default one", (yyvsp[(2) - (2)].str));
        
        add_symbol((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].type_val), true);
        param_types.push_back((yyvsp[(1) - (2)].type_val));
        default_params.push_back(false);
        quad_function_param((yyvsp[(2) - (2)].str), typeToString((yyvsp[(1) - (2)].type_val)), NULL);
      ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 375 "parser.y"
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

  case 93:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
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

  case 94:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    { (yyval.list_val) = make_empty_list(); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    { (yyval.list_val) = make_list((yyvsp[(1) - (1)].val)); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    { (yyval.list_val) = append_to_list((yyvsp[(1) - (3)].list_val), (yyvsp[(3) - (3)].val)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2294 "parser.tab.c"
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
#line 418 "parser.y"


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

