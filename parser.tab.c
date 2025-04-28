
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
Value handle_unary_op(const char* op_name, const char* op_code, char* var_name, bool is_prefix);
void handle_assignment(const char* var, Value expr, const char* op, int line_num);
extern int line_num;

// For multiple declarations
int current_decl_type;

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
#line 108 "parser.tab.c"

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
     BIT_AND = 284,
     BIT_OR = 285,
     BIT_XOR = 286,
     LSHIFT = 287,
     RSHIFT = 288,
     BIT_NOT = 289,
     ADD_ASSIGN = 290,
     SUB_ASSIGN = 291,
     MUL_ASSIGN = 292,
     DIV_ASSIGN = 293,
     MOD_ASSIGN = 294,
     BIT_AND_ASSIGN = 295,
     BIT_OR_ASSIGN = 296,
     BIT_XOR_ASSIGN = 297,
     LSHIFT_ASSIGN = 298,
     RSHIFT_ASSIGN = 299,
     UMINUS = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 35 "parser.y"

    Value val;
    ListValue list_val;
    char *str;
    char *relop;
    int type_val;



/* Line 214 of yacc.c  */
#line 199 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 211 "parser.tab.c"

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
#define YYLAST   730

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  221

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,     2,     2,
      56,    57,    48,    46,    59,    47,     2,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    53,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    11,    14,    16,    19,
      21,    24,    26,    28,    30,    32,    34,    38,    41,    44,
      47,    48,    51,    55,    61,    68,    69,    75,    79,    83,
      87,    91,    95,    99,   103,   107,   111,   115,   119,   121,
     123,   125,   127,   129,   131,   133,   135,   139,   143,   147,
     151,   155,   159,   162,   165,   169,   173,   177,   181,   185,
     189,   193,   197,   201,   204,   206,   209,   212,   215,   218,
     219,   221,   222,   224,   225,   232,   234,   235,   240,   241,
     248,   249,   250,   260,   261,   262,   263,   264,   278,   279,
     280,   281,   282,   295,   296,   303,   307,   308,   309,   318,
     319,   320,   327,   328,   336,   337,   345,   348,   349,   351,
     353,   357,   360,   365,   370,   371,   373,   375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      61,     0,    -1,    -1,    61,    63,    -1,    61,    98,    -1,
      -1,    62,    63,    -1,    65,    -1,    70,    53,    -1,    66,
      -1,    68,    53,    -1,    73,    -1,    77,    -1,    79,    -1,
      82,    -1,    91,    -1,    17,    71,    53,    -1,    21,    53,
      -1,    22,    53,    -1,     1,    53,    -1,    -1,    64,    65,
      -1,     9,     8,    53,    -1,     9,     8,    45,    69,    53,
      -1,    23,     9,     8,    45,    69,    53,    -1,    -1,    54,
      67,    64,    62,    55,    -1,     8,    45,    69,    -1,     8,
      35,    69,    -1,     8,    36,    69,    -1,     8,    37,    69,
      -1,     8,    38,    69,    -1,     8,    39,    69,    -1,     8,
      41,    69,    -1,     8,    40,    69,    -1,     8,    42,    69,
      -1,     8,    43,    69,    -1,     8,    44,    69,    -1,    70,
      -1,    68,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,     7,    -1,     8,    -1,    70,    46,    70,    -1,    70,
      47,    70,    -1,    70,    48,    70,    -1,    70,    49,    70,
      -1,    70,    50,    70,    -1,    70,    26,    70,    -1,    47,
      70,    -1,    51,    70,    -1,    70,    24,    70,    -1,    70,
      25,    70,    -1,    56,    70,    57,    -1,    70,    11,    70,
      -1,    70,    32,    70,    -1,    70,    33,    70,    -1,    70,
      29,    70,    -1,    70,    30,    70,    -1,    70,    31,    70,
      -1,    34,    70,    -1,   104,    -1,    27,     8,    -1,    28,
       8,    -1,     8,    27,    -1,     8,    28,    -1,    -1,    70,
      -1,    -1,    68,    -1,    -1,    12,    56,    70,    57,    74,
      75,    -1,    63,    -1,    -1,    63,    13,    76,    63,    -1,
      -1,    14,    56,    70,    57,    78,    63,    -1,    -1,    -1,
      15,    80,    63,    81,    14,    56,    70,    57,    53,    -1,
      -1,    -1,    -1,    -1,    16,    56,    83,    72,    53,    84,
      71,    85,    53,    69,    86,    57,    63,    -1,    -1,    -1,
      -1,    -1,    16,    56,    87,    65,    88,    71,    89,    53,
      69,    90,    57,    63,    -1,    -1,    18,    56,    70,    57,
      92,    93,    -1,    54,    96,    55,    -1,    -1,    -1,    54,
      96,    20,    94,    58,    62,    95,    55,    -1,    -1,    -1,
      96,    19,     3,    97,    58,    62,    -1,    -1,     9,     8,
      56,    99,   101,    57,    66,    -1,    -1,    10,     8,    56,
     100,   101,    57,    66,    -1,     1,    55,    -1,    -1,   102,
      -1,   103,    -1,   102,    59,   103,    -1,     9,     8,    -1,
       9,     8,    45,    69,    -1,     8,    56,   105,    57,    -1,
      -1,   106,    -1,    70,    -1,   106,    59,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    76,    76,    77,    78,    82,    83,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,   109,   110,   111,
     115,   116,   120,   127,   139,   154,   154,   158,   161,   164,
     167,   170,   173,   176,   179,   182,   185,   188,   196,   197,
     201,   202,   203,   204,   205,   206,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   257,
     258,   262,   263,   268,   268,   272,   273,   273,   276,   276,
     280,   280,   280,   284,   284,   288,   291,   284,   300,   300,
     304,   307,   300,   319,   319,   323,   324,   324,   324,   328,
     329,   329,   334,   334,   360,   360,   382,   386,   387,   391,
     392,   396,   405,   422,   440,   441,   446,   447
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
  "INC", "DEC", "BIT_AND", "BIT_OR", "BIT_XOR", "LSHIFT", "RSHIFT",
  "BIT_NOT", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "BIT_AND_ASSIGN", "BIT_OR_ASSIGN", "BIT_XOR_ASSIGN",
  "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "'='", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "UMINUS", "';'", "'{'", "'}'", "'('", "')'", "':'", "','",
  "$accept", "program", "statements", "statement", "declarations",
  "declaration", "block", "$@1", "assignment", "expression_or_assignment",
  "expression", "opt_expression", "opt_assignment", "if_statement", "$@2",
  "if_body", "$@3", "while_statement", "$@4", "do_while_statement", "$@5",
  "$@6", "for_statement", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "$@13", "$@14", "switch_statement", "$@15", "switch_body", "$@16",
  "$@17", "case_list", "$@18", "function", "$@19", "$@20", "parameters",
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    61,    43,    45,    42,    47,
      37,    33,   300,    59,   123,   125,    40,    41,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    65,    67,    66,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    74,    73,    75,    76,    75,    78,    77,
      80,    81,    79,    83,    84,    85,    86,    82,    87,    88,
      89,    90,    82,    92,    91,    93,    94,    95,    93,    96,
      97,    96,    99,    98,   100,    98,    98,   101,   101,   102,
     102,   103,   103,   104,   105,   105,   106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     0,     2,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       0,     2,     3,     5,     6,     0,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     2,     2,     2,     2,     0,
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
       2,     0,     1,     0,    40,    41,    42,    43,    44,    45,
       0,     0,     0,     0,    80,     0,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     3,     7,
       9,     0,     0,    11,    12,    13,    14,    15,     4,    64,
      19,   106,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   114,     0,     0,     0,     0,
       0,    83,    45,    70,     0,     0,    17,    18,     0,    65,
      66,    63,    52,    53,    20,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,    39,    28,    38,    29,    30,    31,    32,    34,
      33,    35,    36,    37,    27,   116,     0,   115,     0,    22,
     102,   104,     0,     0,     0,     0,    81,    71,     0,    16,
       0,     0,     5,    56,    57,    54,    55,    51,    60,    61,
      62,    58,    59,    46,    47,    48,    49,    50,   113,     0,
       0,   107,   107,    73,    78,     0,     0,     0,    72,     0,
      89,    93,     0,     0,    21,   117,    23,     0,     0,   108,
     109,     0,     0,     0,     0,    84,    69,     0,     0,    26,
       6,   111,     0,     0,     0,    75,    74,    79,     0,    69,
      90,    99,    94,    24,     0,   103,   110,   105,    76,     0,
      85,     0,     0,   112,     0,     0,     0,     0,     0,    96,
      95,    77,    82,     0,    91,   100,     0,    86,     0,     0,
       5,     0,     0,     5,     0,     0,    92,     0,     0,    87,
      98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   153,   170,   122,    29,    30,    74,    92,    93,
      94,    64,   149,    33,   162,   176,   194,    34,   163,    35,
      60,   146,    36,   117,   179,   196,   211,   118,   166,   191,
     208,    37,   167,   182,   206,   218,   192,   209,    38,   141,
     142,   158,   159,   160,    39,   106,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -166
static const yytype_int16 yypact[] =
{
    -166,    92,  -166,     0,  -166,  -166,  -166,  -166,  -166,   674,
       3,    17,   -39,    -4,  -166,     4,   422,     6,     8,    10,
      42,    48,    62,   422,   422,   422,  -166,   422,  -166,  -166,
    -166,    19,   548,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,   454,   454,   454,   454,   454,   454,
     454,   454,   454,   454,   454,   422,   -40,    15,   422,   422,
     390,    -5,   -19,   578,    20,   422,  -166,  -166,    66,  -166,
    -166,    49,    49,    49,  -166,   158,  -166,   422,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,  -166,  -166,  -166,   578,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,   578,    34,    35,   454,  -166,
    -166,  -166,   465,   495,    50,    97,  -166,   103,    -2,  -166,
     507,    67,    -2,  -166,   271,   618,   588,    49,   148,   628,
     658,    -7,    -7,    18,    18,    49,    49,    49,  -166,   422,
      63,   108,   108,  -166,  -166,   -33,   104,   223,  -166,    68,
    -166,  -166,   454,   278,  -166,   578,  -166,   115,    70,    65,
    -166,    71,   390,   390,    69,  -166,   422,    75,    77,  -166,
    -166,    86,    78,   108,    78,   120,  -166,  -166,   422,   422,
    -166,  -166,  -166,  -166,   454,  -166,  -166,  -166,  -166,   536,
    -166,    82,   -17,  -166,   390,    83,    84,   454,   137,  -166,
    -166,  -166,  -166,   454,  -166,  -166,    87,  -166,    85,    89,
    -166,    93,   390,  -166,   334,   390,  -166,   222,    94,  -166,
    -166
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -163,     9,  -166,   -73,  -126,  -166,     5,   -18,
      -1,  -165,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,     2,  -166,   -32,  -166,  -166,  -166
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -102
static const yytype_int16 yytable[] =
{
      32,   180,   198,   199,   -88,   108,    31,   115,    42,    43,
      28,    56,   108,   109,   190,    63,   110,    58,   -88,    80,
     109,    20,    71,    72,    73,    57,    75,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,    55,   200,    86,
      87,    88,    89,    90,    80,   150,   185,   214,   187,   154,
     217,    68,    59,    40,   105,    41,    69,   112,   113,    32,
      61,    66,    65,    67,   120,    31,    88,    89,    90,   116,
      70,   111,    76,   119,   121,    80,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     140,   138,     2,     3,   139,     4,     5,     6,     7,     8,
       9,    10,    11,    40,    12,   145,    13,    14,    15,    16,
      17,   147,   152,    18,    19,    20,   156,   157,   164,    21,
      22,   165,   148,   171,   173,   178,    23,   172,   174,   181,
     183,   184,    26,   188,   168,   197,   202,   203,   155,    24,
     205,   186,   212,    25,   161,   210,    26,   213,    27,   220,
     215,     0,    32,     0,     0,     0,     0,     0,    31,    77,
       0,    32,    32,     0,     0,    63,   193,    31,    31,    77,
       0,   175,   177,     0,    80,     0,     0,   189,    63,   204,
      84,    85,    78,    79,    80,   207,     0,    81,    82,    83,
      84,    85,     0,    32,    86,    87,    88,    89,    90,    31,
       0,     0,     0,   201,    86,    87,    88,    89,    90,     0,
       0,    32,     0,    32,    32,   123,    32,    31,     0,    31,
      31,   216,    31,   114,   219,     4,     5,     6,     7,     8,
       9,   115,     0,     0,    12,     0,    13,    14,    15,    16,
      17,  -101,  -101,    18,    19,    20,     0,     0,     0,    21,
      22,     0,     0,     0,     0,     0,    23,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    24,
       0,     0,     0,    25,     0,     0,    26,  -101,    27,   114,
       0,     4,     5,     6,     7,     8,     9,   115,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    80,     0,    18,
      19,    20,     0,    84,    85,    21,    22,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,    86,    87,    88,
      89,    90,     0,     0,     0,    24,     0,     0,     0,    25,
       0,     0,    26,   169,    27,   114,     0,     4,     5,     6,
       7,     8,     9,   115,     0,     0,    12,     0,    13,    14,
      15,    16,    17,     0,     0,    18,    19,    20,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,     0,     0,    26,   -97,
      27,   114,     0,     4,     5,     6,     7,     8,     9,   115,
       0,     0,    12,     0,    13,    14,    15,    16,    17,     0,
       0,    18,    19,    20,     0,     0,     0,    21,    22,     0,
       0,     0,     0,     0,    23,     4,     5,     6,     7,     8,
      62,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,     0,     0,    26,     0,    27,     0,     0,    21,
      22,     0,     0,     0,     0,     0,    23,     4,     5,     6,
       7,     8,     9,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,     0,     0,    77,     0,    27,     0,
       0,    21,    22,     0,     0,     0,     0,     0,    23,    78,
      79,    80,     0,     0,    81,    82,    83,    84,    85,     0,
       0,    24,     0,     0,     0,    25,    77,     0,     0,     0,
      27,    86,    87,    88,    89,    90,     0,     0,    77,    78,
      79,    80,   143,     0,    81,    82,    83,    84,    85,     0,
       0,    78,    79,    80,     0,     0,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    77,     0,     0,
       0,     0,   144,    86,    87,    88,    89,    90,     0,    77,
      78,    79,    80,     0,   151,    81,    82,    83,    84,    85,
       0,     0,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,    77,
       0,     0,     0,   195,    86,    87,    88,    89,    90,    77,
       0,    91,    78,    79,    80,     0,     0,    81,    82,    83,
      84,    85,    78,     0,    80,     0,     0,    81,    82,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    77,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    77,
       0,     0,     0,     0,    80,     0,     0,    81,    82,    83,
      84,    85,     0,     0,    80,     0,     0,    81,     0,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    90,    77,
       0,     0,     0,     0,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,    80,     0,     0,    81,     0,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    43,     0,    86,    87,    88,    89,    90,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55
};

static const yytype_int16 yycheck[] =
{
       1,   166,    19,    20,     9,    45,     1,     9,    27,    28,
       1,     8,    45,    53,   179,    16,    56,    56,    23,    26,
      53,    23,    23,    24,    25,     8,    27,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    56,    55,    46,
      47,    48,    49,    50,    26,   118,   172,   210,   174,   122,
     213,     9,    56,    53,    55,    55,     8,    58,    59,    60,
      56,    53,    56,    53,    65,    60,    48,    49,    50,    60,
       8,    56,    53,    53,     8,    26,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
     108,    57,     0,     1,    59,     3,     4,     5,     6,     7,
       8,     9,    10,    53,    12,     8,    14,    15,    16,    17,
      18,     8,    45,    21,    22,    23,    53,     9,    14,    27,
      28,    53,   117,     8,    59,    56,    34,    57,    57,    54,
      53,    45,    54,    13,   152,    53,    53,    53,   139,    47,
       3,   173,    57,    51,   142,    58,    54,    58,    56,    55,
      57,    -1,   153,    -1,    -1,    -1,    -1,    -1,   153,    11,
      -1,   162,   163,    -1,    -1,   166,   184,   162,   163,    11,
      -1,   162,   163,    -1,    26,    -1,    -1,   178,   179,   197,
      32,    33,    24,    25,    26,   203,    -1,    29,    30,    31,
      32,    33,    -1,   194,    46,    47,    48,    49,    50,   194,
      -1,    -1,    -1,   194,    46,    47,    48,    49,    50,    -1,
      -1,   212,    -1,   214,   215,    57,   217,   212,    -1,   214,
     215,   212,   217,     1,   215,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    34,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    47,
      -1,    -1,    -1,    51,    -1,    -1,    54,    55,    56,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    -1,
      12,    -1,    14,    15,    16,    17,    18,    26,    -1,    21,
      22,    23,    -1,    32,    33,    27,    28,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,
      -1,    -1,    54,    55,    56,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    51,    -1,    -1,    54,    55,
      56,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    -1,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    34,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    -1,    -1,    54,    -1,    56,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    34,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    51,    -1,    -1,    11,    -1,    56,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    24,
      25,    26,    -1,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    47,    -1,    -1,    -1,    51,    11,    -1,    -1,    -1,
      56,    46,    47,    48,    49,    50,    -1,    -1,    11,    24,
      25,    26,    57,    -1,    29,    30,    31,    32,    33,    -1,
      -1,    24,    25,    26,    -1,    -1,    29,    30,    31,    32,
      33,    46,    47,    48,    49,    50,    -1,    11,    -1,    -1,
      -1,    -1,    57,    46,    47,    48,    49,    50,    -1,    11,
      24,    25,    26,    -1,    57,    29,    30,    31,    32,    33,
      -1,    -1,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    46,    47,    48,    49,    50,    -1,    -1,    11,
      -1,    -1,    -1,    57,    46,    47,    48,    49,    50,    11,
      -1,    53,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    24,    -1,    26,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    46,    47,    48,    49,    50,    11,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    11,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    30,    31,
      32,    33,    -1,    -1,    26,    -1,    -1,    29,    -1,    31,
      32,    33,    -1,    -1,    46,    47,    48,    49,    50,    11,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    -1,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    -1,    46,    47,    48,    49,    50,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    12,    14,    15,    16,    17,    18,    21,    22,
      23,    27,    28,    34,    47,    51,    54,    56,    63,    65,
      66,    68,    70,    73,    77,    79,    82,    91,    98,   104,
      53,    55,    27,    28,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    56,     8,     8,    56,    56,
      80,    56,     8,    70,    71,    56,    53,    53,     9,     8,
       8,    70,    70,    70,    67,    70,    53,    11,    24,    25,
      26,    29,    30,    31,    32,    33,    46,    47,    48,    49,
      50,    53,    68,    69,    70,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,   105,   106,    45,    53,
      56,    56,    70,    70,     1,     9,    63,    83,    87,    53,
      70,     8,    64,    57,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    57,    59,
      69,    99,   100,    57,    57,     8,    81,     8,    68,    72,
      65,    57,    45,    62,    65,    70,    53,     9,   101,   102,
     103,   101,    74,    78,    14,    53,    88,    92,    69,    55,
      63,     8,    57,    59,    57,    63,    75,    63,    56,    84,
      71,    54,    93,    53,    45,    66,   103,    66,    13,    70,
      71,    89,    96,    69,    76,    57,    85,    53,    19,    20,
      55,    63,    53,    53,    69,     3,    94,    69,    90,    97,
      58,    86,    57,    58,    62,    57,    63,    62,    95,    63,
      55
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
#line 76 "parser.y"
    { ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
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
#line 109 "parser.y"
    { if(!is_loop && !is_switch) yyerror("Break statement not in loop or switch"); quad_break(); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    { if(!is_loop) yyerror("Continue statement not in loop"); quad_continue(); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    { yyerrok; ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
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
#line 127 "parser.y"
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
#line 139 "parser.y"
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
#line 154 "parser.y"
    { enter_block_scope(); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { exit_scope(); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), NULL, line_num);
      ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "+", line_num);
      ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "-", line_num);
      ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "*", line_num);
      ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "/", line_num);
      ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "%", line_num);
      ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "BIT_OR", line_num);
      ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "BIT_AND", line_num);
      ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "BIT_XOR", line_num);
      ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "LSHIFT", line_num);
      ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {
          handle_assignment((yyvsp[(1) - (3)].str), (yyvsp[(3) - (3)].val), "RSHIFT", line_num);
      ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
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

  case 46:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    { (yyval.val) = add_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("+", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    { (yyval.val) = sub_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("-", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    { (yyval.val) = mul_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("*", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    { (yyval.val) = div_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("/", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    { (yyval.val) = mod_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("%", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { (yyval.val) = pow_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("^", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.val) = neg_value((yyvsp[(2) - (2)].val)); (yyval.val).name = emit_quad("MINUS", (yyvsp[(2) - (2)].val).name, NULL, NULL); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    { (yyval.val) = not_value((yyvsp[(2) - (2)].val)); (yyval.val).name = emit_quad("NOT", (yyvsp[(2) - (2)].val).name, NULL, NULL); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 240 "parser.y"
    { (yyval.val) = and_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("AND", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    { (yyval.val) = or_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("OR", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.val) = compare_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val), (yyvsp[(2) - (3)].relop)); (yyval.val).name = emit_quad((yyvsp[(2) - (3)].relop), (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.val) = lshift_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("LSHIFT", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { (yyval.val) = rshift_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("RSHIFT", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    { (yyval.val) = bit_and_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("BIT_AND", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { (yyval.val) = bit_or_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("BIT_OR", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    { (yyval.val) = bit_xor_values((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val)); (yyval.val).name = emit_quad("BIT_XOR", (yyvsp[(1) - (3)].val).name, (yyvsp[(3) - (3)].val).name, NULL); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { (yyval.val) = bit_not_value((yyvsp[(2) - (2)].val)); (yyval.val).name = emit_quad("BIT_NOT", (yyvsp[(2) - (2)].val).name, NULL, NULL); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    {;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    { (yyval.val) = handle_unary_op("increment", "INC", (yyvsp[(2) - (2)].str), true); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    { (yyval.val) = handle_unary_op("decrement", "DEC", (yyvsp[(2) - (2)].str), true); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 253 "parser.y"
    { (yyval.val) = handle_unary_op("increment", "INC", (yyvsp[(1) - (2)].str), false); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 254 "parser.y"
    { (yyval.val) = handle_unary_op("decrement", "DEC", (yyvsp[(1) - (2)].str), false); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 257 "parser.y"
    { (yyval.val).name = NULL; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    { (yyval.val).name = NULL; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { printf("[Line %d] If statement\n", line_num); enter_scope(); quad_if_start((yyvsp[(3) - (4)].val).name); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { exit_scope(); quad_if_end(); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { enter_scope(); quad_if_else(); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { exit_scope(); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    { is_loop++; printf("[Line %d] While loop\n", line_num); enter_scope(); quad_while_start((yyvsp[(3) - (4)].val).name) ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    { is_loop--; exit_scope(); quad_while_end(); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    { is_loop++; printf("[Line %d] Do-While loop\n", line_num); enter_scope(); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    { is_loop--; exit_scope(); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { enter_scope(); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { 
          printf("[Line %d] For loop\n", line_num);
          is_loop++;
          quad_for_start(); 
      ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    { 
          quad_for_condition((yyvsp[(7) - (7)].val).name);
      ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {
        quad_for_skip();
      ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    { 
          exit_scope();
          is_loop--;
          quad_for_end();
      ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    { enter_scope(); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 300 "parser.y"
    { 
          printf("[Line %d] For loop\n", line_num);
          is_loop++;
          quad_for_start(); 
      ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 304 "parser.y"
    { 
          quad_for_condition((yyvsp[(6) - (6)].val).name);
      ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {
          quad_for_skip();
      ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 311 "parser.y"
    { 
          exit_scope();
          is_loop--;
          quad_for_end();
      ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    {  is_switch++; printf("[Line %d] Switch statement\n", line_num); enter_scope();  quad_switch_start((yyvsp[(3) - (4)].val).name); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    { exit_scope();  quad_switch_end(); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { is_switch--; ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { quad_switch_default(); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { quad_switch_case_end(); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { is_switch--; ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { quad_switch_case((yyvsp[(3) - (3)].val).name); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    { quad_switch_case_end(); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 334 "parser.y"
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

  case 103:

/* Line 1455 of yacc.c  */
#line 348 "parser.y"
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

  case 104:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
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

  case 105:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
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

  case 106:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    { yyerrok; exit_scope(); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    {;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
    {;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    { 
        if (seen_default_param)
            yyerror("Non-default parameter '%s' after a default one", (yyvsp[(2) - (2)].str));
        
        add_symbol((yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].type_val), true);
        param_types.push_back((yyvsp[(1) - (2)].type_val));
        default_params.push_back(false);
        quad_function_param((yyvsp[(2) - (2)].str), typeToString((yyvsp[(1) - (2)].type_val)), NULL);
      ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 406 "parser.y"
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

  case 113:

/* Line 1455 of yacc.c  */
#line 422 "parser.y"
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

  case 114:

/* Line 1455 of yacc.c  */
#line 440 "parser.y"
    { (yyval.list_val) = make_empty_list(); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 446 "parser.y"
    { (yyval.list_val) = make_list((yyvsp[(1) - (1)].val)); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 447 "parser.y"
    { (yyval.list_val) = append_to_list((yyvsp[(1) - (3)].list_val), (yyvsp[(3) - (3)].val)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2556 "parser.tab.c"
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
#line 449 "parser.y"


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

Value handle_unary_op(const char* op_name, const char* op_code, char* var_name, bool is_prefix) {
    Value result;
    int idx = find_symbol(var_name);
    
    if (idx == -1) {
        yyerror("Undeclared variable '%s' used in %s %s", var_name, 
                is_prefix ? "prefix" : "postfix", op_name);
        result = make_runtime_value(TYPE_INT);
    } 
    else if (is_function(idx)) {
        yyerror("Function '%s' used as variable in %s", var_name, op_name);
        result = make_runtime_value(symbol_table.table[idx].type);
    }
    else if (symbol_table.table[idx].type != TYPE_INT && symbol_table.table[idx].type != TYPE_FLOAT) {
        yyerror("Invalid type for %s '%s'", op_name, var_name);
        result = make_runtime_value(symbol_table.table[idx].type);
    }
    else if (symbol_table.table[idx].is_initialized == false) {
        yyerror("Variable '%s' used before initialization in %s", var_name, op_name);
        result = make_runtime_value(symbol_table.table[idx].type);
        result.name = symbol_table.table[idx].name;
    }
    else if (symbol_table.table[idx].init_value.is_const) {
        yyerror("Cannot %s constant '%s'", op_name, var_name);
        result = make_runtime_value(symbol_table.table[idx].type);
    }
    else {
        symbol_table.table[idx].is_used = true;
        result = make_runtime_value(symbol_table.table[idx].type);
        result.name = is_prefix 
            ? quad_prefix(op_code, var_name)
            : quad_postfix(op_code, var_name);
    }
    
    return result;
}

void handle_assignment(const char* var, Value expr, const char* op, int line_num)
{
    printf("[Line %d] Assignment: %s %s ...\n", line_num, var, op ? op : "=");
    
    int idx = find_symbol(var);
    if(idx == -1) {
        yyerror("Undeclared variable '%s' used in assignment", var);
    }
    else if(is_function(idx)) {
        yyerror("Function '%s' used as variable", var);
    }
    else {
        if(symbol_table.table[idx].init_value.is_const) {
            yyerror("Cannot assign to constant '%s'", var);
        }
        else if(!type_mismatch(symbol_table.table[idx].type, expr.type)) {
            if(op == NULL) {
                // Simple assignment '='
                emit_quad("ASSIGN", expr.name, NULL, var);
            }
            else {
                // Compound assignment
                char* tmp = emit_quad(op, var, expr.name, NULL);
                emit_quad("ASSIGN", tmp, NULL, var);
            }
        }
    }
}


int main(int argc, char **argv) {
    const char *input_fname = "input.mel";

    if (argc > 1) {
        input_fname = argv[1];
        // size_t len = strlen(input_fname);
        // if (len < 5 || strcmp(input_fname + len - 4, ".mel") != 0) {
        //     fprintf(stderr, "Error: input file must have a \".mel\" extension (got \"%s\")\n", input_fname);
        //     return 1;
        // }
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

