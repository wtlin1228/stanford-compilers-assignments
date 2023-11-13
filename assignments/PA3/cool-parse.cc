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
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse cool_yyparse
#define yylex   cool_yylex
#define yyerror cool_yyerror
#define yylval  cool_yylval
#define yychar  cool_yychar
#define yydebug cool_yydebug
#define yynerrs cool_yynerrs
#define yylloc cool_yylloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CLASS = 258,
     ELSE = 259,
     FI = 260,
     IF = 261,
     IN = 262,
     INHERITS = 263,
     LET = 264,
     LOOP = 265,
     POOL = 266,
     THEN = 267,
     WHILE = 268,
     CASE = 269,
     ESAC = 270,
     OF = 271,
     DARROW = 272,
     NEW = 273,
     ISVOID = 274,
     STR_CONST = 275,
     INT_CONST = 276,
     BOOL_CONST = 277,
     TYPEID = 278,
     OBJECTID = 279,
     ASSIGN = 280,
     NOT = 281,
     LE = 282,
     ERROR = 283
   };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283




/* Copy the first part of user declarations.  */
#line 6 "cool.y"

  #include <iostream>
  #include "cool-tree.h"
  #include "stringtab.h"
  #include "utilities.h"
  
  extern char *curr_filename;
  
  
  /* Locations */
  #define YYLTYPE int              /* the type of locations */
  #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer
  for the location of tokens */
    
    extern int node_lineno;          /* set before constructing a tree node
    to whatever you want the line number
    for the tree node to be */
      
      
      #define YYLLOC_DEFAULT(Current, Rhs, N)         \
      Current = Rhs[1];                             \
      node_lineno = Current;
    
    
    #define SET_NODELOC(Current)  \
    node_lineno = Current;
    
    /* IMPORTANT NOTE ON LINE NUMBERS
    *********************************
    * The above definitions and macros cause every terminal in your grammar to 
    * have the line number supplied by the lexer. The only task you have to
    * implement for line numbers to work correctly, is to use SET_NODELOC()
    * before constructing any constructs from non-terminals in your grammar.
    * Example: Consider you are matching on the following very restrictive 
    * (fictional) construct that matches a plus between two integer constants. 
    * (SUCH A RULE SHOULD NOT BE  PART OF YOUR PARSER):
    
    plus_consts	: INT_CONST '+' INT_CONST 
    
    * where INT_CONST is a terminal for an integer constant. Now, a correct
    * action for this rule that attaches the correct line number to plus_const
    * would look like the following:
    
    plus_consts	: INT_CONST '+' INT_CONST 
    {
      // Set the line number of the current non-terminal:
      // ***********************************************
      // You can access the line numbers of the i'th item with @i, just
      // like you acess the value of the i'th exporession with $i.
      //
      // Here, we choose the line number of the last INT_CONST (@3) as the
      // line number of the resulting expression (@$). You are free to pick
      // any reasonable line as the line number of non-terminals. If you 
      // omit the statement @$=..., bison has default rules for deciding which 
      // line number to use. Check the manual for details if you are interested.
      @$ = @3;
      
      
      // Observe that we call SET_NODELOC(@3); this will set the global variable
      // node_lineno to @3. Since the constructor call "plus" uses the value of 
      // this global, the plus node will now have the correct line number.
      SET_NODELOC(@3);
      
      // construct the result node:
      $$ = plus(int_const($1), int_const($3));
    }
    
    */
    
    
    
    void yyerror(char *s);        /*  defined below; called for each parse error */
    extern int yylex();           /*  the entry point to the lexer  */
    
    /************************************************************************/
    /*                DONT CHANGE ANYTHING IN THIS SECTION                  */
    
    Program ast_root;	      /* the result of the parse  */
    Classes parse_results;        /* for use in semantic analysis */
    int omerrs = 0;               /* number of errors in lexing and parsing */
    

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 89 "cool.y"
{
      Boolean boolean;
      Symbol symbol;
      Program program;
      Class_ class_;
      Classes classes;
      Feature feature;
      Features features;
      Formal formal;
      Formals formals;
      Case case_;
      Cases cases;
      Expression expression;
      Expressions expressions;
      char *error_msg;
    }
/* Line 193 of yacc.c.  */
#line 259 "cool.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 284 "cool.tab.c"

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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,    38,    36,    35,    37,    43,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    31,
      41,    42,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,    40,     2,     2,     2,
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
      25,    26,    27,    28,     2
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    17,    26,    29,    30,
      32,    35,    38,    41,    44,    54,    58,    66,    72,    73,
      75,    79,    83,    87,    89,    92,    97,   105,   111,   115,
     121,   124,   127,   131,   135,   139,   143,   146,   149,   153,
     157,   161,   165,   167,   169,   171,   173,   175,   178,   181,
     184,   186,   189,   196,   199,   203,   210,   217,   220,   221,
     224,   228,   233,   239,   245,   252,   260,   268,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    -1,    47,    48,    -1,
       3,    23,    29,    49,    30,    31,    -1,     3,    23,     8,
      23,    29,    49,    30,    31,    -1,     1,    31,    -1,    -1,
      50,    -1,    49,    50,    -1,    51,    31,    -1,    52,    31,
      -1,     1,    31,    -1,    24,    32,    53,    33,    34,    23,
      29,    55,    30,    -1,    24,    34,    23,    -1,    24,    34,
      23,    25,    29,    55,    30,    -1,    24,    34,    23,    25,
      55,    -1,    -1,    54,    -1,    53,    35,    54,    -1,    24,
      34,    23,    -1,    24,    25,    55,    -1,    63,    -1,     9,
      61,    -1,     6,    55,    12,    55,    -1,     6,    55,    12,
      55,     4,    55,     5,    -1,    13,    55,    10,    55,    11,
      -1,    29,    56,    30,    -1,    14,    55,    16,    58,    15,
      -1,    18,    23,    -1,    19,    55,    -1,    55,    36,    55,
      -1,    55,    37,    55,    -1,    55,    38,    55,    -1,    55,
      39,    55,    -1,    40,    55,    -1,    26,    55,    -1,    55,
      27,    55,    -1,    55,    41,    55,    -1,    55,    42,    55,
      -1,    32,    55,    33,    -1,    21,    -1,    20,    -1,    22,
      -1,    24,    -1,    57,    -1,    56,    57,    -1,     1,    31,
      -1,    55,    31,    -1,    59,    -1,    58,    59,    -1,    24,
      34,    23,    17,    55,    31,    -1,    35,    55,    -1,    60,
      35,    55,    -1,    24,    34,    23,    62,     7,    55,    -1,
      24,    34,    23,    62,    35,    61,    -1,     1,    35,    -1,
      -1,    25,    55,    -1,    24,    32,    33,    -1,    24,    32,
      55,    33,    -1,    24,    32,    55,    60,    33,    -1,    55,
      43,    24,    32,    33,    -1,    55,    43,    24,    32,    55,
      33,    -1,    55,    43,    24,    32,    55,    60,    33,    -1,
      55,    44,    23,    43,    24,    32,    33,    -1,    55,    44,
      23,    43,    24,    32,    55,    33,    -1,    55,    44,    23,
      43,    24,    32,    55,    60,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   159,   159,   167,   172,   180,   185,   190,   194,   197,
     202,   210,   215,   220,   224,   232,   237,   242,   250,   253,
     259,   267,   275,   280,   285,   290,   295,   300,   305,   310,
     315,   320,   325,   330,   335,   340,   345,   350,   354,   359,
     364,   369,   374,   379,   384,   389,   397,   402,   407,   411,
     418,   423,   431,   439,   444,   452,   457,   462,   466,   469,
     477,   482,   487,   492,   497,   502,   507,   512,   517
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "'{'", "'}'",
  "';'", "'('", "')'", "':'", "','", "'+'", "'-'", "'*'", "'/'", "'~'",
  "'<'", "'='", "'.'", "'@'", "$accept", "program", "class_list", "class",
  "features", "feature", "method_declaration", "attribute_declaration",
  "formals", "formal", "expression", "block_expressions",
  "block_expression", "branches", "branch", "arguments_expressions",
  "let_expression", "let_assign", "dispatch_expression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   123,
     125,    59,    40,    41,    58,    44,    43,    45,    42,    47,
     126,    60,    61,    46,    64
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      49,    50,    50,    50,    51,    52,    52,    52,    53,    53,
      53,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    60,    60,    61,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     8,     2,     0,     1,
       2,     2,     2,     2,     9,     3,     7,     5,     0,     1,
       3,     3,     3,     1,     2,     4,     7,     5,     3,     5,
       2,     2,     3,     3,     3,     3,     2,     2,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     6,     2,     3,     6,     6,     2,     0,     2,
       3,     4,     5,     5,     6,     7,     7,     8,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     3,     7,     0,     1,     4,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
      13,    18,     0,     0,    10,    11,    12,     0,     0,     0,
      19,    15,     5,     0,     0,     0,     0,     0,     6,    21,
       0,    20,     0,     0,     0,     0,     0,     0,    43,    42,
      44,    45,     0,     0,     0,     0,    17,    23,     0,     0,
       0,     0,     0,    24,     0,     0,    30,    31,     0,     0,
      37,     0,     0,     0,    46,     0,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,    22,    60,     0,    48,    16,    49,    28,
      47,    41,    38,    32,    33,    34,    35,    39,    40,     0,
       0,     0,    25,    58,     0,     0,     0,    50,    61,     0,
       0,     0,     0,    14,     0,     0,     0,    27,     0,    29,
      51,    53,    62,     0,    63,     0,     0,     0,    59,     0,
       0,     0,    54,    64,     0,     0,    26,    55,    56,     0,
      65,    66,     0,     0,    67,     0,    52,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    16,    17,    18,    29,    30,
      87,    73,    74,   116,   117,   120,    63,   126,    57
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int16 yypact[] =
{
      52,   -18,    -3,    25,    36,  -125,  -125,    -7,  -125,  -125,
      11,     3,    19,    21,    34,     5,  -125,    54,    58,     3,
    -125,    69,    72,    66,  -125,  -125,  -125,    49,    67,    32,
    -125,    75,  -125,    79,    90,    82,    69,   209,  -125,  -125,
      96,  -125,   233,     2,   233,   233,    97,   233,  -125,  -125,
    -125,   -13,   233,    85,   233,   233,   423,  -125,    92,    85,
     273,    89,    98,  -125,   240,   286,  -125,   423,   233,   109,
     423,    95,   304,   134,  -125,   356,   423,   233,   233,   233,
     233,   233,   233,   233,   110,   113,   233,   374,   233,  -125,
     114,   233,   115,   423,  -125,   317,  -125,  -125,  -125,  -125,
    -125,  -125,   423,   423,   423,   423,   423,   423,   423,   112,
     102,   392,    20,   121,   253,   116,    -1,  -125,  -125,   233,
      45,   159,   127,  -125,   233,   233,    -5,  -125,   136,  -125,
    -125,   423,  -125,   233,  -125,   330,   125,    33,   423,   233,
       2,   144,   423,  -125,    48,   184,  -125,   423,  -125,   233,
    -125,  -125,   343,   410,  -125,    57,  -125,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,   158,   148,    -6,  -125,  -125,  -125,   133,
     -37,  -125,   103,  -125,    55,  -124,    30,  -125,  -125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -9
static const yytype_int16 yytable[] =
{
      56,    10,   139,    61,    13,    60,    13,    64,    65,    24,
      67,   144,    68,     6,   129,    70,    72,    75,    76,    69,
       7,    24,    11,   115,   124,     8,    62,    14,   155,    14,
     140,    93,    95,    -8,    12,    23,    -2,     1,   146,     2,
     102,   103,   104,   105,   106,   107,   108,    77,    19,   111,
      13,   112,    20,     1,   114,     2,    78,    79,    80,    81,
      77,    82,    83,    84,    85,    35,    21,    36,    22,    78,
      79,    80,    81,    14,    82,    83,    84,    85,   132,    33,
     133,   150,   131,   133,   135,    25,    71,   137,   138,    26,
     157,    42,   133,    28,    43,    31,   142,    32,    44,    45,
      37,    34,   147,    46,    47,    48,    49,    50,   152,    51,
      38,    52,   153,    39,    59,    42,    40,    54,    43,    58,
      66,    86,    44,    45,    89,    55,    96,    46,    47,    48,
      49,    50,    90,    51,   109,    52,   110,   113,    59,   115,
      42,    54,    94,    43,   121,   122,   125,    44,    45,    55,
     128,   136,    46,    47,    48,    49,    50,   145,    51,   141,
      52,   149,     9,    59,    99,    42,    54,    27,    43,    41,
     148,   130,    44,    45,    55,     0,   100,    46,    47,    48,
      49,    50,     0,    51,     0,    52,     0,     0,    59,     0,
      42,    54,   134,    43,     0,     0,     0,    44,    45,    55,
       0,     0,    46,    47,    48,    49,    50,     0,    51,     0,
      52,     0,     0,    59,     0,    42,    54,   151,    43,     0,
       0,     0,    44,    45,    55,     0,     0,    46,    47,    48,
      49,    50,     0,    51,     0,    52,     0,     0,    53,    42,
       0,    54,    43,     0,     0,     0,    44,    45,     0,    55,
      91,    46,    47,    48,    49,    50,     0,    51,     0,    52,
       0,     0,    59,     0,   127,    54,     0,    77,     0,     0,
       0,     0,     0,    55,     0,     0,    78,    79,    80,    81,
      77,    82,    83,    84,    85,    88,     0,     0,     0,    78,
      79,    80,    81,     0,    82,    83,    84,    85,     0,     0,
      77,     0,    92,     0,     0,     0,     0,     0,     0,    78,
      79,    80,    81,    77,    82,    83,    84,    85,     0,     0,
       0,     0,    78,    79,    80,    81,     0,    82,    83,    84,
      85,    77,     0,     0,    97,    98,     0,     0,     0,     0,
      78,    79,    80,    81,    77,    82,    83,    84,    85,     0,
     118,     0,   119,    78,    79,    80,    81,    77,    82,    83,
      84,    85,     0,   143,     0,   119,    78,    79,    80,    81,
      77,    82,    83,    84,    85,     0,   154,     0,   119,    78,
      79,    80,    81,    77,    82,    83,    84,    85,     0,   101,
       0,     0,    78,    79,    80,    81,     0,    82,    83,    84,
      85,    77,     0,     0,     0,    98,     0,     0,     0,     0,
      78,    79,    80,    81,     0,    82,    83,    84,    85,    77,
       0,     0,   123,     0,     0,     0,     0,     0,    78,    79,
      80,    81,     0,    82,    83,    84,    85,    77,     0,     0,
       0,   156,     0,     0,     0,     0,    78,    79,    80,    81,
      77,    82,    83,    84,    85,     0,     0,     0,     0,    78,
      79,    80,    81,     0,    82,    83,    84,    85
};

static const yytype_int16 yycheck[] =
{
      37,     8,     7,     1,     1,    42,     1,    44,    45,    15,
      47,   135,    25,    31,    15,    52,    53,    54,    55,    32,
      23,    27,    29,    24,     4,     0,    24,    24,   152,    24,
      35,    68,    69,    30,    23,    30,     0,     1,     5,     3,
      77,    78,    79,    80,    81,    82,    83,    27,    29,    86,
       1,    88,    31,     1,    91,     3,    36,    37,    38,    39,
      27,    41,    42,    43,    44,    33,    32,    35,    34,    36,
      37,    38,    39,    24,    41,    42,    43,    44,    33,    30,
      35,    33,   119,    35,   121,    31,     1,   124,   125,    31,
      33,     6,    35,    24,     9,    23,   133,    31,    13,    14,
      25,    34,   139,    18,    19,    20,    21,    22,   145,    24,
      31,    26,   149,    23,    29,     6,    34,    32,     9,    23,
      23,    29,    13,    14,    35,    40,    31,    18,    19,    20,
      21,    22,    34,    24,    24,    26,    23,    23,    29,    24,
       6,    32,    33,     9,    32,    43,    25,    13,    14,    40,
      34,    24,    18,    19,    20,    21,    22,    32,    24,    23,
      26,    17,     4,    29,    30,     6,    32,    19,     9,    36,
     140,   116,    13,    14,    40,    -1,    73,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    -1,    -1,    29,    -1,
       6,    32,    33,     9,    -1,    -1,    -1,    13,    14,    40,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    -1,    -1,    29,    -1,     6,    32,    33,     9,    -1,
      -1,    -1,    13,    14,    40,    -1,    -1,    18,    19,    20,
      21,    22,    -1,    24,    -1,    26,    -1,    -1,    29,     6,
      -1,    32,     9,    -1,    -1,    -1,    13,    14,    -1,    40,
      10,    18,    19,    20,    21,    22,    -1,    24,    -1,    26,
      -1,    -1,    29,    -1,    11,    32,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    36,    37,    38,    39,
      27,    41,    42,    43,    44,    12,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    42,    43,    44,    -1,    -1,
      27,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    27,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    27,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    27,    41,    42,    43,    44,    -1,
      33,    -1,    35,    36,    37,    38,    39,    27,    41,    42,
      43,    44,    -1,    33,    -1,    35,    36,    37,    38,    39,
      27,    41,    42,    43,    44,    -1,    33,    -1,    35,    36,
      37,    38,    39,    27,    41,    42,    43,    44,    -1,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    41,    42,    43,
      44,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    27,
      -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    27,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      27,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    46,    47,    48,    31,    23,     0,    48,
       8,    29,    23,     1,    24,    49,    50,    51,    52,    29,
      31,    32,    34,    30,    50,    31,    31,    49,    24,    53,
      54,    23,    31,    30,    34,    33,    35,    25,    31,    23,
      34,    54,     6,     9,    13,    14,    18,    19,    20,    21,
      22,    24,    26,    29,    32,    40,    55,    63,    23,    29,
      55,     1,    24,    61,    55,    55,    23,    55,    25,    32,
      55,     1,    55,    56,    57,    55,    55,    27,    36,    37,
      38,    39,    41,    42,    43,    44,    29,    55,    12,    35,
      34,    10,    16,    55,    33,    55,    31,    30,    31,    30,
      57,    33,    55,    55,    55,    55,    55,    55,    55,    24,
      23,    55,    55,    23,    55,    24,    58,    59,    33,    35,
      60,    32,    43,    30,     4,    25,    62,    11,    34,    15,
      59,    55,    33,    35,    33,    55,    24,    55,    55,     7,
      35,    23,    55,    33,    60,    32,     5,    55,    61,    17,
      33,    33,    55,    55,    33,    60,    31,    33
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



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

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

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
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 160 "cool.y"
    { 
              (yyloc) = (yylsp[(1) - (1)]); 
              ast_root = program((yyvsp[(1) - (1)].classes)); 
            }
    break;

  case 3:
#line 168 "cool.y"
    { 
                  (yyloc) = (yylsp[(1) - (1)]); 
                  (yyval.classes) = single_Classes((yyvsp[(1) - (1)].class_));
                }
    break;

  case 4:
#line 173 "cool.y"
    { 
                  (yyloc) = (yylsp[(2) - (2)]); 
                  (yyval.classes) = append_Classes((yyvsp[(1) - (2)].classes),single_Classes((yyvsp[(2) - (2)].class_))); 
                }
    break;

  case 5:
#line 181 "cool.y"
    {
            (yyloc) = (yylsp[(6) - (6)]);
            (yyval.class_) = class_((yyvsp[(2) - (6)].symbol),idtable.add_string("Object"),(yyvsp[(4) - (6)].features), stringtable.add_string(curr_filename)); 
          }
    break;

  case 6:
#line 186 "cool.y"
    { 
              (yyloc) = (yylsp[(8) - (8)]);
              (yyval.class_) = class_((yyvsp[(2) - (8)].symbol),(yyvsp[(4) - (8)].symbol),(yyvsp[(6) - (8)].features),stringtable.add_string(curr_filename)); 
            }
    break;

  case 7:
#line 190 "cool.y"
    {  }
    break;

  case 8:
#line 194 "cool.y"
    {
                (yyval.features) = nil_Features();
              }
    break;

  case 9:
#line 198 "cool.y"
    {
                (yyloc) = (yylsp[(1) - (1)]); 
                (yyval.features) = single_Features((yyvsp[(1) - (1)].feature));
              }
    break;

  case 10:
#line 203 "cool.y"
    {
                (yyloc) = (yylsp[(2) - (2)]); 
                (yyval.features) = append_Features((yyvsp[(1) - (2)].features), single_Features((yyvsp[(2) - (2)].feature)));
              }
    break;

  case 11:
#line 211 "cool.y"
    {
                (yyloc) = (yylsp[(2) - (2)]);
                (yyval.feature) = (yyvsp[(1) - (2)].feature);
            }
    break;

  case 12:
#line 216 "cool.y"
    {
              (yyloc) = (yylsp[(2) - (2)]);
              (yyval.feature) = (yyvsp[(1) - (2)].feature);
            }
    break;

  case 13:
#line 220 "cool.y"
    {  }
    break;

  case 14:
#line 225 "cool.y"
    {
                          (yyloc) = (yylsp[(9) - (9)]);
                          (yyval.feature) = method((yyvsp[(1) - (9)].symbol), (yyvsp[(3) - (9)].formals), (yyvsp[(6) - (9)].symbol), (yyvsp[(8) - (9)].expression));
                        }
    break;

  case 15:
#line 233 "cool.y"
    {
                            (yyloc) = (yylsp[(3) - (3)]);
                            (yyval.feature) = attr((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), no_expr());
                          }
    break;

  case 16:
#line 238 "cool.y"
    {
                            (yyloc) = (yylsp[(7) - (7)]);
                            (yyval.feature) = attr((yyvsp[(1) - (7)].symbol), (yyvsp[(3) - (7)].symbol), (yyvsp[(6) - (7)].expression));
                          }
    break;

  case 17:
#line 243 "cool.y"
    {
                            (yyloc) = (yylsp[(5) - (5)]);
                            (yyval.feature) = attr((yyvsp[(1) - (5)].symbol), (yyvsp[(3) - (5)].symbol), (yyvsp[(5) - (5)].expression));
                          }
    break;

  case 18:
#line 250 "cool.y"
    {
              (yyval.formals) = nil_Formals();
            }
    break;

  case 19:
#line 254 "cool.y"
    {
              (yyloc) = (yylsp[(1) - (1)]);
              (yyval.formals) = single_Formals((yyvsp[(1) - (1)].formal));
            }
    break;

  case 20:
#line 260 "cool.y"
    {
              (yyloc) = (yylsp[(2) - (3)]); 
              (yyval.formals) = append_Formals((yyvsp[(1) - (3)].formals),single_Formals((yyvsp[(3) - (3)].formal))); 
            }
    break;

  case 21:
#line 268 "cool.y"
    {
              (yyloc) = (yylsp[(3) - (3)]);
              (yyval.formal) = formal((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol));
            }
    break;

  case 22:
#line 276 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = assign((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 23:
#line 281 "cool.y"
    {
                  (yyloc) = (yylsp[(1) - (1)]);
                  (yyval.expression) = (yyvsp[(1) - (1)].expression);
                }
    break;

  case 24:
#line 286 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (2)]);
                  (yyval.expression) = (yyvsp[(2) - (2)].expression);
                }
    break;

  case 25:
#line 291 "cool.y"
    {
                  (yyloc) = (yylsp[(4) - (4)]);
                  (yyval.expression) = cond((yyvsp[(2) - (4)].expression),(yyvsp[(4) - (4)].expression), no_expr());
                }
    break;

  case 26:
#line 296 "cool.y"
    {
                  (yyloc) = (yylsp[(4) - (7)]);
                  (yyval.expression) = cond((yyvsp[(2) - (7)].expression),(yyvsp[(4) - (7)].expression),(yyvsp[(6) - (7)].expression));
                }
    break;

  case 27:
#line 301 "cool.y"
    {
                  (yyloc) = (yylsp[(5) - (5)]);
                  (yyval.expression) = loop((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].expression));
                }
    break;

  case 28:
#line 306 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (3)]);
                  (yyval.expression) = block((yyvsp[(2) - (3)].expressions));
                }
    break;

  case 29:
#line 311 "cool.y"
    {
                  (yyloc) = (yylsp[(5) - (5)]);
                  (yyval.expression) = typcase((yyvsp[(2) - (5)].expression), (yyvsp[(4) - (5)].cases));
                }
    break;

  case 30:
#line 316 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (2)]);
                  (yyval.expression) = new_((yyvsp[(2) - (2)].symbol));
                }
    break;

  case 31:
#line 321 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (2)]);
                  (yyval.expression) = isvoid((yyvsp[(2) - (2)].expression));
                }
    break;

  case 32:
#line 326 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = plus((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 33:
#line 331 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = sub((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 34:
#line 336 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = mul((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 35:
#line 341 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = divide((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 36:
#line 346 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (2)]);
                  (yyval.expression) = neg((yyvsp[(2) - (2)].expression));
                }
    break;

  case 37:
#line 350 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (2)]);
                  (yyval.expression) = comp((yyvsp[(2) - (2)].expression));
                }
    break;

  case 38:
#line 355 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = leq((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 39:
#line 360 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = lt((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 40:
#line 365 "cool.y"
    {
                  (yyloc) = (yylsp[(3) - (3)]);
                  (yyval.expression) = eq((yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
                }
    break;

  case 41:
#line 370 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (3)]);
                  (yyval.expression) = (yyvsp[(2) - (3)].expression);
                }
    break;

  case 42:
#line 375 "cool.y"
    {
                  (yyloc) = (yylsp[(1) - (1)]);
                  (yyval.expression) = int_const((yyvsp[(1) - (1)].symbol));
                }
    break;

  case 43:
#line 380 "cool.y"
    {
                  (yyloc) = (yylsp[(1) - (1)]);
                  (yyval.expression) = string_const((yyvsp[(1) - (1)].symbol));
                }
    break;

  case 44:
#line 385 "cool.y"
    {
                  (yyloc) = (yylsp[(1) - (1)]);
                  (yyval.expression) = bool_const((yyvsp[(1) - (1)].boolean)); 
                }
    break;

  case 45:
#line 390 "cool.y"
    {
                  (yyloc) = (yylsp[(1) - (1)]);
                  (yyval.expression) = object((yyvsp[(1) - (1)].symbol)); 
                }
    break;

  case 46:
#line 398 "cool.y"
    {
                        (yyloc) = (yylsp[(1) - (1)]);
                        (yyval.expressions) = single_Expressions((yyvsp[(1) - (1)].expression));
                      }
    break;

  case 47:
#line 403 "cool.y"
    {
                        (yyloc) = (yylsp[(2) - (2)]);
                        (yyval.expressions) = append_Expressions((yyvsp[(1) - (2)].expressions),single_Expressions((yyvsp[(2) - (2)].expression)));
                      }
    break;

  case 48:
#line 407 "cool.y"
    { yyerrok; }
    break;

  case 49:
#line 412 "cool.y"
    {
                        (yyval.expression) = (yyvsp[(1) - (2)].expression);
                      }
    break;

  case 50:
#line 419 "cool.y"
    {
                (yyloc) = (yylsp[(1) - (1)]);
                (yyval.cases) = single_Cases((yyvsp[(1) - (1)].case_));
              }
    break;

  case 51:
#line 424 "cool.y"
    {
                (yyloc) = (yylsp[(2) - (2)]);
                (yyval.cases) = append_Cases((yyvsp[(1) - (2)].cases), single_Cases((yyvsp[(2) - (2)].case_)));
              }
    break;

  case 52:
#line 432 "cool.y"
    {
              (yyloc) = (yylsp[(6) - (6)]);
              (yyval.case_) = branch((yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].symbol), (yyvsp[(5) - (6)].expression));
            }
    break;

  case 53:
#line 440 "cool.y"
    {
                            (yyloc) = (yylsp[(1) - (2)]);
                            (yyval.expressions) = single_Expressions((yyvsp[(2) - (2)].expression));
                          }
    break;

  case 54:
#line 445 "cool.y"
    {
                            (yyloc) = (yylsp[(3) - (3)]);
                            (yyval.expressions) = append_Expressions((yyvsp[(1) - (3)].expressions), single_Expressions((yyvsp[(3) - (3)].expression)));
                          }
    break;

  case 55:
#line 453 "cool.y"
    {
                      (yyloc) = (yylsp[(6) - (6)]);
                      (yyval.expression) = let((yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].symbol), (yyvsp[(4) - (6)].expression), (yyvsp[(6) - (6)].expression));
                    }
    break;

  case 56:
#line 458 "cool.y"
    {      
                      (yyloc) = (yylsp[(6) - (6)]);
                      (yyval.expression) = let((yyvsp[(1) - (6)].symbol), (yyvsp[(3) - (6)].symbol), (yyvsp[(4) - (6)].expression), (yyvsp[(6) - (6)].expression));
                    }
    break;

  case 57:
#line 462 "cool.y"
    { yyerrok; }
    break;

  case 58:
#line 466 "cool.y"
    {
                  (yyval.expression) = no_expr();
                }
    break;

  case 59:
#line 470 "cool.y"
    {
                  (yyloc) = (yylsp[(2) - (2)]);
                  (yyval.expression) = (yyvsp[(2) - (2)].expression);
                }
    break;

  case 60:
#line 478 "cool.y"
    {
                          (yyloc) = (yylsp[(3) - (3)]);
                          (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[(1) - (3)].symbol), nil_Expressions());
                        }
    break;

  case 61:
#line 483 "cool.y"
    {
                          (yyloc) = (yylsp[(3) - (4)]);
                          (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[(1) - (4)].symbol), single_Expressions((yyvsp[(3) - (4)].expression)));
                        }
    break;

  case 62:
#line 488 "cool.y"
    {
                          (yyloc) = (yylsp[(3) - (5)]);
                          (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[(1) - (5)].symbol), append_Expressions(single_Expressions((yyvsp[(3) - (5)].expression)), (yyvsp[(4) - (5)].expressions)));
                        }
    break;

  case 63:
#line 493 "cool.y"
    { 
                          (yyloc) = (yylsp[(5) - (5)]);
                          (yyval.expression) = dispatch((yyvsp[(1) - (5)].expression), (yyvsp[(3) - (5)].symbol), nil_Expressions());
                        }
    break;

  case 64:
#line 498 "cool.y"
    {
                          (yyloc) = (yylsp[(6) - (6)]);
                          (yyval.expression) = dispatch((yyvsp[(1) - (6)].expression), (yyvsp[(3) - (6)].symbol), single_Expressions((yyvsp[(5) - (6)].expression)));
                        }
    break;

  case 65:
#line 503 "cool.y"
    {
                          (yyloc) = (yylsp[(7) - (7)]);
                          (yyval.expression) = dispatch((yyvsp[(1) - (7)].expression), (yyvsp[(3) - (7)].symbol), append_Expressions(single_Expressions((yyvsp[(5) - (7)].expression)), (yyvsp[(6) - (7)].expressions)));
                        }
    break;

  case 66:
#line 508 "cool.y"
    {
                          (yyloc) = (yylsp[(7) - (7)]);
                          (yyval.expression) = static_dispatch((yyvsp[(1) - (7)].expression), (yyvsp[(3) - (7)].symbol), (yyvsp[(5) - (7)].symbol), nil_Expressions());
                        }
    break;

  case 67:
#line 513 "cool.y"
    {
                          (yyloc) = (yylsp[(8) - (8)]);
                          (yyval.expression) = static_dispatch((yyvsp[(1) - (8)].expression), (yyvsp[(3) - (8)].symbol), (yyvsp[(5) - (8)].symbol), single_Expressions((yyvsp[(7) - (8)].expression)));
                        }
    break;

  case 68:
#line 518 "cool.y"
    {
                          (yyloc) = (yylsp[(9) - (9)]);
                          (yyval.expression) = static_dispatch((yyvsp[(1) - (9)].expression), (yyvsp[(3) - (9)].symbol), (yyvsp[(5) - (9)].symbol), append_Expressions(single_Expressions((yyvsp[(7) - (9)].expression)), (yyvsp[(8) - (9)].expressions)));
                        }
    break;


/* Line 1267 of yacc.c.  */
#line 2213 "cool.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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


#line 525 "cool.y"

    
    /* This function is called automatically when Bison detects a parse error. */
    void yyerror(char *s)
    {
      extern int curr_lineno;
      
      cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
      << s << " at or near ";
      print_cool_token(yychar);
      cerr << endl;
      omerrs++;
      
      if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
    }
    
    
