
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

/* Substitute the variable and function names.  */
#define yyparse         sass_parse
#define yylex           sass_lex
#define yyerror         sass_error
#define yylval          sass_lval
#define yychar          sass_char
#define yydebug         sass_debug
#define yynerrs         sass_nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 28 "sass.y"

#include <stdio.h>
#include "cuobjdumpInstList.h"

int yylex(void);
void yyerror(const char*);
void debug_print( const char *s );

extern cuobjdumpInstList *g_instList;

cuobjdumpInst *instEntry;


/* Line 189 of yacc.c  */
#line 95 "sass_parser.cc"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BAR = 258,
     ADA = 259,
     AND = 260,
     ANDS = 261,
     BRA = 262,
     BRX = 263,
     CAL = 264,
     COS = 265,
     DADD = 266,
     DMIN = 267,
     DMAX = 268,
     DFMA = 269,
     DMUL = 270,
     EX2 = 271,
     F2F = 272,
     F2I = 273,
     FADD = 274,
     FADD32 = 275,
     FADD32I = 276,
     FMAD = 277,
     FMAD32I = 278,
     FMUL = 279,
     FMUL32 = 280,
     FMUL32I = 281,
     FSET = 282,
     DSET = 283,
     G2R = 284,
     GLD = 285,
     GST = 286,
     I2F = 287,
     I2I = 288,
     IADD = 289,
     IADD32 = 290,
     IADD32I = 291,
     IMAD = 292,
     ISAD = 293,
     IMAD24 = 294,
     IMAD32I = 295,
     IMAD32 = 296,
     IADDCARRY = 297,
     IMUL = 298,
     IMUL24 = 299,
     IMUL24H = 300,
     IMULS24 = 301,
     IMUL32 = 302,
     IMUL32S24 = 303,
     IMUL32U24 = 304,
     IMUL32I = 305,
     IMUL32I24 = 306,
     IMUL32IS24 = 307,
     ISET = 308,
     LG2 = 309,
     LLD = 310,
     LST = 311,
     MOV = 312,
     MOV32 = 313,
     MVC = 314,
     MVI = 315,
     NOP = 316,
     NOT = 317,
     NOTS = 318,
     OR = 319,
     ORS = 320,
     R2A = 321,
     R2G = 322,
     R2GU16U8 = 323,
     RCP = 324,
     RCP32 = 325,
     RET = 326,
     RRO = 327,
     RSQ = 328,
     SIN = 329,
     SHL = 330,
     SHR = 331,
     SSY = 332,
     XOR = 333,
     XORS = 334,
     S2R = 335,
     SASS_LD = 336,
     STS = 337,
     LDS = 338,
     SASS_ST = 339,
     IMIN = 340,
     IMAX = 341,
     A2R = 342,
     FMAX = 343,
     FMIN = 344,
     TEX = 345,
     TEX32 = 346,
     C2R = 347,
     EXIT = 348,
     GRED = 349,
     PBK = 350,
     BRK = 351,
     R2C = 352,
     GATOM = 353,
     VOTE = 354,
     EQ = 355,
     EQU = 356,
     GE = 357,
     GEU = 358,
     GT = 359,
     GTU = 360,
     LE = 361,
     LEU = 362,
     LT = 363,
     LTU = 364,
     NE = 365,
     NEU = 366,
     DOTBEXT = 367,
     DOTS = 368,
     DOTSFU = 369,
     DOTTRUNC = 370,
     DOTCEIL = 371,
     DOTFLOOR = 372,
     DOTIR = 373,
     DOTUN = 374,
     DOTNODEP = 375,
     DOTSAT = 376,
     DOTANY = 377,
     DOTALL = 378,
     DOTF16 = 379,
     DOTF32 = 380,
     DOTF64 = 381,
     DOTS8 = 382,
     DOTS16 = 383,
     DOTS32 = 384,
     DOTS64 = 385,
     DOTS128 = 386,
     DOTU8 = 387,
     DOTU16 = 388,
     DOTU32 = 389,
     DOTU24 = 390,
     DOTU64 = 391,
     DOTHI = 392,
     DOTNOINC = 393,
     DOTEQ = 394,
     DOTEQU = 395,
     DOTFALSE = 396,
     DOTGE = 397,
     DOTGEU = 398,
     DOTGT = 399,
     DOTGTU = 400,
     DOTLE = 401,
     DOTLEU = 402,
     DOTLT = 403,
     DOTLTU = 404,
     DOTNE = 405,
     DOTNEU = 406,
     DOTNSF = 407,
     DOTSF = 408,
     DOTCARRY = 409,
     DOTCC = 410,
     DOTX = 411,
     DOTE = 412,
     DOTRED = 413,
     DOTPOPC = 414,
     REGISTER = 415,
     REGISTERLO = 416,
     REGISTERHI = 417,
     OFFSETREGISTER = 418,
     PREDREGISTER = 419,
     PREDREGISTER2 = 420,
     PREDREGISTER3 = 421,
     SREGISTER = 422,
     VERSIONHEADER = 423,
     FUNCTIONHEADER = 424,
     SMEMLOCATION = 425,
     ABSSMEMLOCATION = 426,
     GMEMLOCATION = 427,
     CMEMLOCATION = 428,
     LMEMLOCATION = 429,
     IDENTIFIER = 430,
     HEXLITERAL = 431,
     LEFTBRACKET = 432,
     RIGHTBRACKET = 433,
     PIPE = 434,
     TILDE = 435,
     NEWLINE = 436,
     SEMICOLON = 437,
     LABEL = 438,
     LABELSTART = 439,
     LABELEND = 440,
     PTXHEADER = 441,
     ELFHEADER = 442,
     INFOARCHVERSION = 443,
     INFOCODEVERSION_HEADER = 444,
     INFOCODEVERSION = 445,
     INFOPRODUCER = 446,
     INFOHOST = 447,
     INFOCOMPILESIZE_HEADER = 448,
     INFOCOMPILESIZE = 449,
     INFOIDENTIFIER = 450,
     DOT = 451,
     INSTHEX = 452,
     OSQBRACKET = 453,
     CSQBRACKET = 454
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 42 "sass.y"

  double double_value;
  float  float_value;
  int    int_value;
  char * string_value;
  void * ptr_value;



/* Line 214 of yacc.c  */
#line 340 "sass_parser.cc"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 352 "sass_parser.cc"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   382

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  200
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  226
/* YYNRULES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   454

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    13,    19,    23,    26,    28,
      29,    35,    39,    44,    47,    51,    53,    54,    58,    61,
      62,    64,    68,    72,    74,    76,    80,    84,    86,    88,
      90,    92,    94,    96,    98,   100,   102,   104,   106,   108,
     110,   112,   114,   116,   118,   120,   122,   124,   126,   128,
     130,   132,   134,   136,   138,   140,   142,   144,   146,   148,
     150,   152,   154,   156,   158,   160,   162,   164,   166,   168,
     170,   172,   174,   176,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   196,   198,   200,   202,   204,   206,   208,
     210,   212,   214,   216,   218,   220,   222,   224,   226,   228,
     230,   232,   234,   236,   238,   240,   242,   244,   246,   248,
     250,   252,   254,   256,   258,   260,   262,   264,   266,   268,
     270,   271,   275,   276,   281,   282,   286,   287,   291,   292,
     297,   300,   301,   303,   305,   307,   309,   311,   313,   315,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   359,   361,   362,   366,   367,   369,   373,   376,   380,
     383,   385,   387,   389,   391,   393,   396,   400,   402,   404,
     406,   408,   411,   414,   416,   417,   419,   421,   423,   425,
     427,   429,   431,   433,   435,   437,   439,   441,   443,   445,
     447,   449,   451,   453,   455,   458,   460,   463,   465,   467,
     469,   471,   473,   475,   477,   479,   481,   483,   485,   487,
     489,   491,   493,   495,   497,   499,   501
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     201,     0,    -1,   201,   202,    -1,   202,    -1,   168,   175,
     181,   203,    -1,   181,   168,   175,   181,   203,    -1,   168,
     175,   181,    -1,   203,   204,    -1,   204,    -1,    -1,   169,
     175,   205,   206,   181,    -1,   206,   207,   181,    -1,   206,
     207,   182,   181,    -1,   207,   181,    -1,   207,   182,   181,
      -1,   181,    -1,    -1,   208,   211,   209,    -1,   210,   212,
      -1,    -1,   197,    -1,   184,   183,   185,    -1,   213,   222,
     225,    -1,   214,    -1,   217,    -1,    94,   196,   214,    -1,
      98,   196,   214,    -1,   215,    -1,     4,    -1,     5,    -1,
       6,    -1,     8,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    37,    -1,
      38,    -1,    39,    -1,    40,    -1,    41,    -1,    43,    -1,
      44,    -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,
      50,    -1,    51,    -1,    52,    -1,    49,    -1,    53,    -1,
      54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
      64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,
      69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      75,    -1,    76,    -1,    74,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    93,    -1,     3,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,
      92,    -1,    96,    -1,    97,    -1,    42,    -1,    99,    -1,
      -1,    95,   216,   176,    -1,    -1,     7,   218,   233,   176,
      -1,    -1,     7,   219,   176,    -1,    -1,     9,   220,   176,
      -1,    -1,     9,   221,   138,   176,    -1,   223,   222,    -1,
      -1,   224,    -1,   112,    -1,   113,    -1,   114,    -1,   115,
      -1,   116,    -1,   117,    -1,   156,    -1,   157,    -1,   158,
      -1,   159,    -1,   118,    -1,   119,    -1,   120,    -1,   122,
      -1,   123,    -1,   124,    -1,   125,    -1,   126,    -1,   127,
      -1,   128,    -1,   129,    -1,   130,    -1,   131,    -1,   132,
      -1,   133,    -1,   134,    -1,   135,    -1,   136,    -1,   137,
      -1,    -1,   225,   226,   227,    -1,    -1,   228,    -1,   179,
     228,   179,    -1,   180,   228,    -1,   177,   233,   178,    -1,
     230,   224,    -1,   230,    -1,   231,    -1,   232,    -1,   234,
      -1,   235,    -1,   160,   229,    -1,   198,   160,   199,    -1,
     161,    -1,   162,    -1,   167,    -1,   163,    -1,   164,   165,
      -1,   164,   160,    -1,   155,    -1,    -1,   170,    -1,   171,
      -1,   172,    -1,   173,    -1,   174,    -1,   175,    -1,   176,
      -1,   100,    -1,   101,    -1,   102,    -1,   103,    -1,   104,
      -1,   105,    -1,   106,    -1,   107,    -1,   108,    -1,   109,
      -1,   110,    -1,   111,    -1,   166,   236,    -1,   166,    -1,
     166,   236,    -1,   166,    -1,    16,    -1,    74,    -1,    10,
      -1,   139,    -1,   140,    -1,   141,    -1,   142,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,   147,    -1,   148,
      -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,   153,
      -1,   154,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    97,    98,    99,   101,   102,   105,
     105,   117,   118,   119,   120,   121,   124,   124,   127,   128,
     131,   134,   151,   157,   158,   159,   160,   161,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   164,   164,   164,
     165,   165,   165,   165,   165,   165,   165,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   167,   167,   168,   168,   168,   168,   168,
     168,   168,   168,   169,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   171,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   174,   174,   174,   174,   174,   174,   174,
     177,   177,   199,   199,   217,   217,   235,   235,   254,   254,
     275,   277,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   314,   314,   316,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   332,   333,   334,   335,   336,
     337,   338,   339,   343,   344,   348,   349,   362,   363,   364,
     367,   368,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   385,   388,   391,   399,   407,   408,
     409,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BAR", "ADA", "AND", "ANDS", "BRA",
  "BRX", "CAL", "COS", "DADD", "DMIN", "DMAX", "DFMA", "DMUL", "EX2",
  "F2F", "F2I", "FADD", "FADD32", "FADD32I", "FMAD", "FMAD32I", "FMUL",
  "FMUL32", "FMUL32I", "FSET", "DSET", "G2R", "GLD", "GST", "I2F", "I2I",
  "IADD", "IADD32", "IADD32I", "IMAD", "ISAD", "IMAD24", "IMAD32I",
  "IMAD32", "IADDCARRY", "IMUL", "IMUL24", "IMUL24H", "IMULS24", "IMUL32",
  "IMUL32S24", "IMUL32U24", "IMUL32I", "IMUL32I24", "IMUL32IS24", "ISET",
  "LG2", "LLD", "LST", "MOV", "MOV32", "MVC", "MVI", "NOP", "NOT", "NOTS",
  "OR", "ORS", "R2A", "R2G", "R2GU16U8", "RCP", "RCP32", "RET", "RRO",
  "RSQ", "SIN", "SHL", "SHR", "SSY", "XOR", "XORS", "S2R", "SASS_LD",
  "STS", "LDS", "SASS_ST", "IMIN", "IMAX", "A2R", "FMAX", "FMIN", "TEX",
  "TEX32", "C2R", "EXIT", "GRED", "PBK", "BRK", "R2C", "GATOM", "VOTE",
  "EQ", "EQU", "GE", "GEU", "GT", "GTU", "LE", "LEU", "LT", "LTU", "NE",
  "NEU", "DOTBEXT", "DOTS", "DOTSFU", "DOTTRUNC", "DOTCEIL", "DOTFLOOR",
  "DOTIR", "DOTUN", "DOTNODEP", "DOTSAT", "DOTANY", "DOTALL", "DOTF16",
  "DOTF32", "DOTF64", "DOTS8", "DOTS16", "DOTS32", "DOTS64", "DOTS128",
  "DOTU8", "DOTU16", "DOTU32", "DOTU24", "DOTU64", "DOTHI", "DOTNOINC",
  "DOTEQ", "DOTEQU", "DOTFALSE", "DOTGE", "DOTGEU", "DOTGT", "DOTGTU",
  "DOTLE", "DOTLEU", "DOTLT", "DOTLTU", "DOTNE", "DOTNEU", "DOTNSF",
  "DOTSF", "DOTCARRY", "DOTCC", "DOTX", "DOTE", "DOTRED", "DOTPOPC",
  "REGISTER", "REGISTERLO", "REGISTERHI", "OFFSETREGISTER", "PREDREGISTER",
  "PREDREGISTER2", "PREDREGISTER3", "SREGISTER", "VERSIONHEADER",
  "FUNCTIONHEADER", "SMEMLOCATION", "ABSSMEMLOCATION", "GMEMLOCATION",
  "CMEMLOCATION", "LMEMLOCATION", "IDENTIFIER", "HEXLITERAL",
  "LEFTBRACKET", "RIGHTBRACKET", "PIPE", "TILDE", "NEWLINE", "SEMICOLON",
  "LABEL", "LABELSTART", "LABELEND", "PTXHEADER", "ELFHEADER",
  "INFOARCHVERSION", "INFOCODEVERSION_HEADER", "INFOCODEVERSION",
  "INFOPRODUCER", "INFOHOST", "INFOCOMPILESIZE_HEADER", "INFOCOMPILESIZE",
  "INFOIDENTIFIER", "DOT", "INSTHEX", "OSQBRACKET", "CSQBRACKET",
  "$accept", "program", "sassCode", "functionList", "function", "$@1",
  "statementList", "statement", "$@2", "statementend", "instructionHex",
  "instructionLabel", "assemblyInstruction", "baseInstruction",
  "simpleInstructions", "pbkInstruction", "$@3", "branchInstructions",
  "$@4", "$@5", "$@6", "$@7", "modifierList", "modifier", "opTypes",
  "operandList", "$@8", "operand", "registerlocation", "regMod",
  "memorylocation", "immediateValue", "extraModifier",
  "instructionPredicate", "operandPredicate", "preOperand",
  "predicateModifier", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   200,   201,   201,   202,   202,   202,   203,   203,   205,
     204,   206,   206,   206,   206,   206,   208,   207,   209,   209,
     210,   211,   212,   213,   213,   213,   213,   213,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     216,   215,   218,   217,   219,   217,   220,   217,   221,   217,
     222,   222,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   226,   225,   225,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   228,   228,   228,   228,
     228,   228,   228,   229,   229,   230,   230,   230,   230,   230,
     231,   231,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   233,   233,   234,   234,   235,   235,
     235,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     4,     5,     3,     2,     1,     0,
       5,     3,     4,     2,     3,     1,     0,     3,     2,     0,
       1,     3,     3,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     0,     4,     0,     3,     0,     3,     0,     4,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     0,     1,     3,     2,     3,     2,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     2,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     3,     0,     0,     1,     2,     6,
       0,     0,     4,     8,     0,     9,     7,     5,    16,    15,
      16,     0,     0,    10,     0,    13,     0,     0,    19,    11,
       0,    14,     0,    20,    17,     0,    12,    21,   107,    28,
      29,    30,   122,    31,   126,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   118,    64,    65,
      66,    67,    68,    69,    73,    70,    71,    72,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    97,
      95,    96,    98,    99,   100,   101,   102,   103,   104,   105,
     108,   109,   110,   111,   112,   113,   114,   115,   106,     0,
     120,   116,   117,     0,   119,    18,   131,    23,    27,    24,
       0,     0,     0,     0,     0,     0,     0,   133,   134,   135,
     136,   137,   138,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   139,   140,   141,   142,   164,   131,   132,   205,
       0,   125,   127,     0,    25,   121,    26,   162,   130,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   204,   123,   129,     0,   210,
     208,   209,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   184,   177,   178,   180,     0,   207,
     179,   185,   186,   187,   188,   189,   190,   191,     0,     0,
       0,     0,   163,   165,   170,   171,   172,   173,   174,   183,
     175,   182,   181,   206,     0,     0,   167,     0,   169,   168,
     166,   176
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    12,    13,    18,    20,    21,    22,    34,
      35,    28,   135,   136,   137,   138,   145,   139,   140,   141,
     142,   143,   176,   177,   178,   187,   208,   242,   243,   250,
     244,   245,   246,   180,   247,   248,   205
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
    -126,  -174,  -163,     3,  -184,  -165,  -117,  -184,  -184,  -128,
    -121,  -116,  -128,  -184,  -128,  -184,  -184,  -128,  -120,  -184,
    -119,  -136,  -118,  -184,  -134,  -184,  -114,  -115,  -109,  -184,
    -112,  -184,   -96,  -184,  -184,   186,  -184,  -184,  -184,  -184,
    -184,  -184,  -113,  -184,   -73,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   -80,
    -184,  -184,  -184,   -79,  -184,  -184,  -105,  -184,  -184,  -184,
     -48,  -106,   -57,   -18,   283,   -55,   283,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -105,  -184,   -67,
     -54,  -184,  -184,   -53,  -184,  -184,  -184,  -132,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   -10,  -184,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,   -31,  -184,  -184,  -184,  -122,   -67,
    -184,  -184,  -184,  -184,  -184,  -184,  -184,  -184,   -48,  -127,
    -127,   -35,  -184,  -184,   -22,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,   -52,   -51,  -184,   -72,  -184,  -184,
    -184,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,   126,   116,    27,  -184,  -184,   111,  -184,  -184,
    -184,  -184,  -184,  -184,  -142,  -184,  -184,  -184,  -184,  -184,
    -184,  -184,   -45,  -184,  -111,  -184,  -184,  -184,  -183,  -184,
    -184,  -184,  -184,  -104,  -184,  -184,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -129
static const yytype_int16 yytable[] =
{
     209,     5,   184,     7,   186,     6,   210,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     9,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   224,   225,   226,   227,   228,   251,    16,
     230,    11,     1,   252,    16,    25,    26,    29,    30,   -22,
     -22,   172,   173,   174,   175,     2,   255,   256,    10,    15,
      14,    19,    23,  -124,   211,  -128,    27,    31,    32,    36,
     181,   241,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    33,    37,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   144,   146,   179,   182,
     183,   185,   206,   207,   249,   257,   259,   261,   260,     8,
      17,    24,   188,   258,   254,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,   225,   226,   227,   228,     0,   229,   230,     0,     0,
     231,   232,   233,   234,   235,   236,   237,   238,     0,   239,
     240,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     0,     0,   241,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,    38,    39,    40,    41,
       0,    43,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,     0,     0,   131,
     132,     0,   134
};

static const yytype_int16 yycheck[] =
{
      10,   175,   144,     0,   146,   168,    16,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   181,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   160,   161,   162,   163,   164,   160,    12,
     167,   169,   168,   165,    17,   181,   182,   181,   182,   181,
     182,   156,   157,   158,   159,   181,   239,   240,   175,   175,
     181,   181,   181,   176,    74,   138,   184,   181,   183,   181,
     176,   198,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   197,   185,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   196,   196,   166,   176,
     138,   176,   176,   176,   155,   160,   178,   199,   179,     3,
      14,    20,   177,   244,   238,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,   164,    -1,   166,   167,    -1,    -1,
     170,   171,   172,   173,   174,   175,   176,   177,    -1,   179,
     180,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   181,    -1,    -1,    -1,   198,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    -1,    96,
      97,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   168,   181,   201,   202,   175,   168,     0,   202,   181,
     175,   169,   203,   204,   181,   175,   204,   203,   205,   181,
     206,   207,   208,   181,   207,   181,   182,   184,   211,   181,
     182,   181,   183,   197,   209,   210,   181,   185,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   212,   213,   214,   215,   217,
     218,   219,   220,   221,   196,   216,   196,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   156,   157,   158,   159,   222,   223,   224,   166,
     233,   176,   176,   138,   214,   176,   214,   225,   222,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   236,   176,   176,   226,    10,
      16,    74,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   160,   161,   162,   163,   164,   166,
     167,   170,   171,   172,   173,   174,   175,   176,   177,   179,
     180,   198,   227,   228,   230,   231,   232,   234,   235,   155,
     229,   160,   165,   236,   233,   228,   228,   160,   224,   178,
     179,   199
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
        case 4:

/* Line 1455 of yacc.c  */
#line 97 "sass.y"
    { debug_print((yyvsp[(1) - (4)].string_value)); debug_print((yyvsp[(2) - (4)].string_value)); debug_print(" No parsing errors\n\n");  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 98 "sass.y"
    { debug_print((yyvsp[(2) - (5)].string_value)); debug_print((yyvsp[(3) - (5)].string_value)); debug_print(" No parsing errors\n\n");  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 105 "sass.y"
    {
					debug_print((yyvsp[(1) - (2)].string_value)); 
					debug_print((yyvsp[(2) - (2)].string_value));
					debug_print("\n");
					g_instList->addEntry((yyvsp[(2) - (2)].string_value));
					instEntry = new cuobjdumpInst();
					instEntry->setBase(".entry");
					g_instList->add(instEntry);
					g_instList->getListEnd().addOperand((yyvsp[(2) - (2)].string_value));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 117 "sass.y"
    { debug_print("\n"); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 118 "sass.y"
    { debug_print(";\n"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 119 "sass.y"
    { debug_print("\n"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 120 "sass.y"
    { debug_print(";\n"); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 121 "sass.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 124 "sass.y"
    { instEntry = new cuobjdumpInst(); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 128 "sass.y"
    {instEntry->setBase("NOP"); g_instList->add(instEntry); debug_print("NOP");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 134 "sass.y"
    { char* tempInput = (yyvsp[(2) - (3)].string_value);
							  char* tempLabel = new char[12];
							  tempLabel[0] = 'l';
							  tempLabel[1] = '0';
							  tempLabel[2] = 'x';
							  for(int i=0; i<(8-strlen(tempInput)); i++)
							  {
								tempLabel[3+i] = '0';
							  }
							  for(int i=(11-strlen(tempInput)); i<11; i++)
							  {
								tempLabel[i] = tempInput[i-(11-strlen(tempInput))];
							  }
							  tempLabel[11] = '\0';
							  instEntry->setLabel(tempLabel); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 151 "sass.y"
    { ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 157 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); instEntry->setBase((yyvsp[(1) - (1)].string_value)); g_instList->add(instEntry);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 159 "sass.y"
    { debug_print((yyvsp[(1) - (3)].string_value)); instEntry->setBase((yyvsp[(1) - (3)].string_value)); g_instList->add(instEntry); g_instList->getListEnd().addBaseModifier((yyvsp[(3) - (3)].string_value));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 160 "sass.y"
    { debug_print((yyvsp[(1) - (3)].string_value)); instEntry->setBase((yyvsp[(1) - (3)].string_value)); g_instList->add(instEntry); g_instList->getListEnd().addBaseModifier((yyvsp[(3) - (3)].string_value));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 177 "sass.y"
    {
						debug_print((yyvsp[(1) - (1)].string_value)); instEntry->setBase((yyvsp[(1) - (1)].string_value)); g_instList->add(instEntry);
					;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 179 "sass.y"
    {
						char* tempInput = (yyvsp[(3) - (3)].string_value);
						char* tempLabel = new char[12];
						tempLabel[0] = 'l';
						tempLabel[1] = '0';
						tempLabel[2] = 'x';
						for(int i=0; i<(10-strlen(tempInput)); i++)
						{
							tempLabel[3+i] = '0';
						}
						for(int i=(13-strlen(tempInput)); i<11; i++)
						{
							tempLabel[i] = tempInput[i-(11-strlen(tempInput))];
						}
						tempLabel[11] = '\0';
						g_instList->getListEnd().addOperand(tempLabel);
						g_instList->addCubojdumpLabel(tempLabel);
					;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 199 "sass.y"
    {debug_print((yyvsp[(1) - (1)].string_value)); instEntry->setBase((yyvsp[(1) - (1)].string_value)); g_instList->add(instEntry);;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 200 "sass.y"
    { debug_print((yyvsp[(4) - (4)].string_value));
				  char* tempInput = (yyvsp[(4) - (4)].string_value);
				  char* tempLabel = new char[12];
				  tempLabel[0] = 'l';
				  tempLabel[1] = '0';
				  tempLabel[2] = 'x';
				  for(int i=0; i<(10-strlen(tempInput)); i++)
				  {
					tempLabel[3+i] = '0';
				  }
				  for(int i=(13-strlen(tempInput)); i<11; i++)
				  {
					tempLabel[i] = tempInput[i-(11-strlen(tempInput))];
				  }
				  tempLabel[11] = '\0';
				  g_instList->getListEnd().addOperand(tempLabel);
				  g_instList->addCubojdumpLabel(tempLabel);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 217 "sass.y"
    {debug_print((yyvsp[(1) - (1)].string_value)); instEntry->setBase((yyvsp[(1) - (1)].string_value)); g_instList->add(instEntry);;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 218 "sass.y"
    { debug_print((yyvsp[(3) - (3)].string_value));
				  char* tempInput = (yyvsp[(3) - (3)].string_value);
				  char* tempLabel = new char[12];
				  tempLabel[0] = 'l';
				  tempLabel[1] = '0';
				  tempLabel[2] = 'x';
				  for(int i=0; i<(10-strlen(tempInput)); i++)
				  {
					tempLabel[3+i] = '0';
				  }
				  for(int i=(13-strlen(tempInput)); i<11; i++)
				  {
					tempLabel[i] = tempInput[i-(11-strlen(tempInput))];
				  }
				  tempLabel[11] = '\0';
				  g_instList->getListEnd().addOperand(tempLabel);
				  g_instList->addCubojdumpLabel(tempLabel);;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 235 "sass.y"
    {debug_print((yyvsp[(1) - (1)].string_value)); instEntry->setBase((yyvsp[(1) - (1)].string_value)); g_instList->add(instEntry);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 236 "sass.y"
    { debug_print((yyvsp[(3) - (3)].string_value));
				  char* tempInput = (yyvsp[(3) - (3)].string_value);
				  char* tempLabel = new char[12];
				  tempLabel[0] = 'l';
				  tempLabel[1] = '0';
				  tempLabel[2] = 'x';
				  for(int i=0; i<(10-strlen(tempInput)); i++)
				  {
					tempLabel[3+i] = '0';
				  }
				  for(int i=(13-strlen(tempInput)); i<11; i++)
				  {
					tempLabel[i] = tempInput[i-(11-strlen(tempInput))];
				  }
				  tempLabel[11] = '\0';
				  g_instList->getListEnd().addOperand(tempLabel);
				  g_instList->addCubojdumpLabel(tempLabel);;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 254 "sass.y"
    {debug_print((yyvsp[(1) - (1)].string_value)); instEntry->setBase((yyvsp[(1) - (1)].string_value)); g_instList->add(instEntry);;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 255 "sass.y"
    { debug_print((yyvsp[(4) - (4)].string_value));
				  char* tempInput = (yyvsp[(4) - (4)].string_value);
				  char* tempLabel = new char[12];
				  tempLabel[0] = 'l';
				  tempLabel[1] = '0';
				  tempLabel[2] = 'x';
				  for(int i=0; i<(10-strlen(tempInput)); i++)
				  {
					tempLabel[3+i] = '0';
				  }
				  for(int i=(13-strlen(tempInput)); i<11; i++)
				  {
					tempLabel[i] = tempInput[i-(11-strlen(tempInput))];
				  }
				  tempLabel[11] = '\0';
				  g_instList->getListEnd().addOperand(tempLabel);
				  g_instList->addCubojdumpLabel(tempLabel);;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 280 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addTypeModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 281 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".bext"); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 282 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".s"); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 283 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".sfu"); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 284 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".rz"); ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 285 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".rp"); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 286 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".rm"); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 287 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".x"); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 288 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".e"); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 289 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".red"); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 290 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".popc"); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 291 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".ir"); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 292 "sass.y"
    { /*g_instList->getListEnd().addBaseModifier(".un"); */;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 293 "sass.y"
    { /*g_instList->getListEnd().addBaseModifier(".nodep"); */;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 294 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".any"); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 295 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".all"); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 314 "sass.y"
    { debug_print(" "); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 314 "sass.y"
    {;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 320 "sass.y"
    { g_instList->getListEnd().addBaseModifier(".abs"); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 323 "sass.y"
    { debug_print((yyvsp[(2) - (2)].string_value)); g_instList->getListEnd().addTypeModifier((yyvsp[(2) - (2)].string_value));;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 332 "sass.y"
    { debug_print((yyvsp[(1) - (2)].string_value)); g_instList->addCuobjdumpRegister((yyvsp[(1) - (2)].string_value));;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 333 "sass.y"
    { debug_print((yyvsp[(1) - (3)].string_value)); debug_print((yyvsp[(2) - (3)].string_value)); debug_print((yyvsp[(3) - (3)].string_value)); g_instList->addCuobjdumpRegister((yyvsp[(2) - (3)].string_value));;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 334 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpRegister((yyvsp[(1) - (1)].string_value),true);;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 335 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpRegister((yyvsp[(1) - (1)].string_value),true);;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 336 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpRegister((yyvsp[(1) - (1)].string_value),false);;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 337 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpRegister((yyvsp[(1) - (1)].string_value));;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 338 "sass.y"
    { debug_print((yyvsp[(1) - (2)].string_value)); debug_print(" "); debug_print((yyvsp[(2) - (2)].string_value)); g_instList->addCuobjdumpDoublePredReg((yyvsp[(1) - (2)].string_value), (yyvsp[(2) - (2)].string_value));;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 339 "sass.y"
    { debug_print((yyvsp[(1) - (2)].string_value)); debug_print(" "); debug_print((yyvsp[(2) - (2)].string_value)); g_instList->addCuobjdumpDoublePredReg((yyvsp[(1) - (2)].string_value), (yyvsp[(2) - (2)].string_value));;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 348 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpMemoryOperand((yyvsp[(1) - (1)].string_value),1);;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 349 "sass.y"
    {
				debug_print((yyvsp[(1) - (1)].string_value));
				char* input = (yyvsp[(1) - (1)].string_value);
				char* temp = new char[99];
				temp[0] = input[1];
				unsigned i=1;
				while (i < strlen(input)-2) {
					temp[i] = input[i+2];
					i++;
				}
				g_instList->addCuobjdumpMemoryOperand(temp,1);
				g_instList->getListEnd().addBaseModifier(".abs");
			;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 362 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpMemoryOperand((yyvsp[(1) - (1)].string_value),2);;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 363 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpMemoryOperand((yyvsp[(1) - (1)].string_value),0);;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 364 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->addCuobjdumpMemoryOperand((yyvsp[(1) - (1)].string_value),3);;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 367 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addOperand((yyvsp[(1) - (1)].string_value));;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 368 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addOperand((yyvsp[(1) - (1)].string_value));;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 371 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 372 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 373 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 374 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 375 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 376 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 377 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 378 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 379 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 380 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 381 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 382 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier((yyvsp[(1) - (1)].string_value));;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 385 "sass.y"
    {debug_print((yyvsp[(1) - (2)].string_value)); debug_print((yyvsp[(2) - (2)].string_value));
								g_instList->getListEnd().setPredicate((yyvsp[(1) - (2)].string_value));
								g_instList->getListEnd().addPredicateModifier((yyvsp[(2) - (2)].string_value));;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 388 "sass.y"
    {debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().setPredicate((yyvsp[(1) - (1)].string_value));;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 391 "sass.y"
    {
							debug_print((yyvsp[(1) - (2)].string_value)); 
							debug_print((yyvsp[(2) - (2)].string_value));
							//g_instList->getListEnd().addOperand($1);
							g_instList->getListEnd().setPredicate((yyvsp[(1) - (2)].string_value));
							g_instList->getListEnd().addPredicateModifier((yyvsp[(2) - (2)].string_value));
							/*May be the modifier needs to be added too*/
						;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 399 "sass.y"
    {
							debug_print("HELLO: "); 
							debug_print((yyvsp[(1) - (1)].string_value)); 
							g_instList->getListEnd().addOperand((yyvsp[(1) - (1)].string_value));
						;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 407 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier("ex2");;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 408 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier("sin");;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 409 "sass.y"
    { debug_print((yyvsp[(1) - (1)].string_value)); g_instList->getListEnd().addBaseModifier("cos");;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 412 "sass.y"
    { ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 413 "sass.y"
    { ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 414 "sass.y"
    { ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 415 "sass.y"
    { ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 416 "sass.y"
    { ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 417 "sass.y"
    { ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 418 "sass.y"
    { ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 419 "sass.y"
    { ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 420 "sass.y"
    { ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 421 "sass.y"
    { ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 422 "sass.y"
    { ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 423 "sass.y"
    { ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 424 "sass.y"
    { ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 425 "sass.y"
    { ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 426 "sass.y"
    { ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 427 "sass.y"
    { ;}
    break;



/* Line 1455 of yacc.c  */
#line 2697 "sass_parser.cc"
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
#line 430 "sass.y"


/*support c++ functions go here*/

void debug_print( const char *s )
{
	// uncomment to debug
	// printf("%s",s);
}

