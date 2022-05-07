/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "compilateur.y"

#include <stdlib.h>
#include <stdio.h>
#include "include/ts.h"
#include "include/parser.h"
extern int yylineno;
void yyerror(char *s);

#line 80 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tDeclareInt = 258,             /* tDeclareInt  */
    tDeclareConstInt = 259,        /* tDeclareConstInt  */
    tOpeningBracket = 260,         /* tOpeningBracket  */
    tClosingBracket = 261,         /* tClosingBracket  */
    tWhile = 262,                  /* tWhile  */
    tElse = 263,                   /* tElse  */
    tIf = 264,                     /* tIf  */
    tMain = 265,                   /* tMain  */
    tPlus = 266,                   /* tPlus  */
    tMinus = 267,                  /* tMinus  */
    tStar = 268,                   /* tStar  */
    tDiv = 269,                    /* tDiv  */
    tSup = 270,                    /* tSup  */
    tInf = 271,                    /* tInf  */
    tEqual = 272,                  /* tEqual  */
    tAssign = 273,                 /* tAssign  */
    tEsp = 274,                    /* tEsp  */
    tOpeningParenthesis = 275,     /* tOpeningParenthesis  */
    tClosingParenthesis = 276,     /* tClosingParenthesis  */
    tNewline = 277,                /* tNewline  */
    tPointVirgule = 278,           /* tPointVirgule  */
    tVirgule = 279,                /* tVirgule  */
    tPrintf = 280,                 /* tPrintf  */
    tValueInt = 281,               /* tValueInt  */
    tVarName = 282,                /* tVarName  */
    tValueExp = 283                /* tValueExp  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define tDeclareInt 258
#define tDeclareConstInt 259
#define tOpeningBracket 260
#define tClosingBracket 261
#define tWhile 262
#define tElse 263
#define tIf 264
#define tMain 265
#define tPlus 266
#define tMinus 267
#define tStar 268
#define tDiv 269
#define tSup 270
#define tInf 271
#define tEqual 272
#define tAssign 273
#define tEsp 274
#define tOpeningParenthesis 275
#define tClosingParenthesis 276
#define tNewline 277
#define tPointVirgule 278
#define tVirgule 279
#define tPrintf 280
#define tValueInt 281
#define tVarName 282
#define tValueExp 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "compilateur.y"
 int nb; char * var; double nb_exp; 

#line 192 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tDeclareInt = 3,                /* tDeclareInt  */
  YYSYMBOL_tDeclareConstInt = 4,           /* tDeclareConstInt  */
  YYSYMBOL_tOpeningBracket = 5,            /* tOpeningBracket  */
  YYSYMBOL_tClosingBracket = 6,            /* tClosingBracket  */
  YYSYMBOL_tWhile = 7,                     /* tWhile  */
  YYSYMBOL_tElse = 8,                      /* tElse  */
  YYSYMBOL_tIf = 9,                        /* tIf  */
  YYSYMBOL_tMain = 10,                     /* tMain  */
  YYSYMBOL_tPlus = 11,                     /* tPlus  */
  YYSYMBOL_tMinus = 12,                    /* tMinus  */
  YYSYMBOL_tStar = 13,                     /* tStar  */
  YYSYMBOL_tDiv = 14,                      /* tDiv  */
  YYSYMBOL_tSup = 15,                      /* tSup  */
  YYSYMBOL_tInf = 16,                      /* tInf  */
  YYSYMBOL_tEqual = 17,                    /* tEqual  */
  YYSYMBOL_tAssign = 18,                   /* tAssign  */
  YYSYMBOL_tEsp = 19,                      /* tEsp  */
  YYSYMBOL_tOpeningParenthesis = 20,       /* tOpeningParenthesis  */
  YYSYMBOL_tClosingParenthesis = 21,       /* tClosingParenthesis  */
  YYSYMBOL_tNewline = 22,                  /* tNewline  */
  YYSYMBOL_tPointVirgule = 23,             /* tPointVirgule  */
  YYSYMBOL_tVirgule = 24,                  /* tVirgule  */
  YYSYMBOL_tPrintf = 25,                   /* tPrintf  */
  YYSYMBOL_tValueInt = 26,                 /* tValueInt  */
  YYSYMBOL_tVarName = 27,                  /* tVarName  */
  YYSYMBOL_tValueExp = 28,                 /* tValueExp  */
  YYSYMBOL_YYACCEPT = 29,                  /* $accept  */
  YYSYMBOL_PROGRAMME = 30,                 /* PROGRAMME  */
  YYSYMBOL_Bloc = 31,                      /* Bloc  */
  YYSYMBOL_32_1 = 32,                      /* $@1  */
  YYSYMBOL_Corps = 33,                     /* Corps  */
  YYSYMBOL_34_2 = 34,                      /* $@2  */
  YYSYMBOL_Ligne = 35,                     /* Ligne  */
  YYSYMBOL_BlocBased = 36,                 /* BlocBased  */
  YYSYMBOL_ContenuLigne = 37,              /* ContenuLigne  */
  YYSYMBOL_InstructionIfElse = 38,         /* InstructionIfElse  */
  YYSYMBOL_39_3 = 39,                      /* $@3  */
  YYSYMBOL_40_4 = 40,                      /* $@4  */
  YYSYMBOL_InstructionElse = 41,           /* InstructionElse  */
  YYSYMBOL_42_5 = 42,                      /* $@5  */
  YYSYMBOL_InstructionWhile = 43,          /* InstructionWhile  */
  YYSYMBOL_44_6 = 44,                      /* $@6  */
  YYSYMBOL_45_7 = 45,                      /* $@7  */
  YYSYMBOL_Printf = 46,                    /* Printf  */
  YYSYMBOL_Declaration = 47,               /* Declaration  */
  YYSYMBOL_48_8 = 48,                      /* $@8  */
  YYSYMBOL_DeclarationType = 49,           /* DeclarationType  */
  YYSYMBOL_VarName = 50,                   /* VarName  */
  YYSYMBOL_Assignation = 51,               /* Assignation  */
  YYSYMBOL_Prio0Arith = 52,                /* Prio0Arith  */
  YYSYMBOL_Prio1Arith = 53,                /* Prio1Arith  */
  YYSYMBOL_Prio2Arith = 54,                /* Prio2Arith  */
  YYSYMBOL_Prio3Arith = 55,                /* Prio3Arith  */
  YYSYMBOL_56_9 = 56,                      /* $@9  */
  YYSYMBOL_57_10 = 57,                     /* $@10  */
  YYSYMBOL_Val = 58                        /* Val  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   84

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    18,    18,    21,    21,    23,    23,    23,    23,    25,
      27,    27,    27,    29,    29,    29,    31,    31,    31,    33,
      33,    33,    35,    35,    35,    37,    40,    41,    41,    44,
      45,    58,    59,    62,    66,    67,    68,    69,    72,    73,
      74,    77,    78,    79,    82,    82,    83,    83,    84,    85,
      88,    89,    90
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tDeclareInt",
  "tDeclareConstInt", "tOpeningBracket", "tClosingBracket", "tWhile",
  "tElse", "tIf", "tMain", "tPlus", "tMinus", "tStar", "tDiv", "tSup",
  "tInf", "tEqual", "tAssign", "tEsp", "tOpeningParenthesis",
  "tClosingParenthesis", "tNewline", "tPointVirgule", "tVirgule",
  "tPrintf", "tValueInt", "tVarName", "tValueExp", "$accept", "PROGRAMME",
  "Bloc", "$@1", "Corps", "$@2", "Ligne", "BlocBased", "ContenuLigne",
  "InstructionIfElse", "$@3", "$@4", "InstructionElse", "$@5",
  "InstructionWhile", "$@6", "$@7", "Printf", "Declaration", "$@8",
  "DeclarationType", "VarName", "Assignation", "Prio0Arith", "Prio1Arith",
  "Prio2Arith", "Prio3Arith", "$@9", "$@10", "Val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,     6,    19,   -38,   -38,   -38,     1,   -38,   -38,   -38,
       3,    17,     9,   -38,    37,     1,   -38,    21,   -38,   -38,
     -38,   -38,    18,   -38,    26,    -6,    -6,    -6,   -38,   -38,
       1,   -38,    23,    30,    -6,   -38,   -38,    -6,   -38,   -38,
     -38,    28,    14,    24,    25,   -38,    29,   -38,   -38,    18,
      33,    31,    -6,    -6,    32,   -38,    -6,    -6,    -6,    -6,
      -6,    -6,    -6,   -38,   -38,    -6,   -38,   -38,   -38,   -38,
       6,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,     6,
     -38,   -38,    46,   -38,   -38,     6,   -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     2,     1,     8,    30,    29,    22,
       0,     0,     0,    10,     0,     8,     6,     0,    11,    12,
      15,    13,     0,    14,     0,     0,     0,     0,     4,     5,
       8,     9,    32,    26,     0,    44,    46,     0,    51,    50,
      52,     0,    37,    40,    43,    48,     0,    33,     7,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,     0,     0,    25,    31,     0,    23,    45,    47,    49,
       0,    34,    35,    36,    38,    39,    42,    41,    28,     0,
      17,    24,    21,    19,    18,     0,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,    -1,   -38,   -12,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,     8,   -38,   -25,   -24,   -18,   -37,   -38,   -38,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    13,     6,    14,    30,    15,    16,    17,    18,
      70,    82,    84,    85,    19,    24,    79,    20,    21,    50,
      22,    33,    23,    41,    42,    43,    44,    52,    53,    45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       4,    46,    47,    29,     7,     8,     3,    35,     9,    51,
      10,     3,    54,    36,    37,    67,    68,     1,    48,     5,
      38,    39,    40,    25,    76,    77,    11,    27,    12,    56,
      57,    58,    71,    72,    73,    59,    60,    26,    61,    62,
      78,    74,    75,    28,    31,    32,    34,    49,   -27,    55,
      63,    65,    66,    69,    83,     0,     0,    64,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,     0,     0,     0,    86
};

static const yytype_int8 yycheck[] =
{
       1,    26,    27,    15,     3,     4,     5,    13,     7,    34,
       9,     5,    37,    19,    20,    52,    53,    10,    30,     0,
      26,    27,    28,    20,    61,    62,    25,    18,    27,    15,
      16,    17,    56,    57,    58,    11,    12,    20,    13,    14,
      65,    59,    60,     6,    23,    27,    20,    24,    18,    21,
      21,    18,    21,    21,     8,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    -1,    -1,    -1,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    30,     5,    31,     0,    32,     3,     4,     7,
       9,    25,    27,    31,    33,    35,    36,    37,    38,    43,
      46,    47,    49,    51,    44,    20,    20,    18,     6,    33,
      34,    23,    27,    50,    20,    13,    19,    20,    26,    27,
      28,    52,    53,    54,    55,    58,    52,    52,    33,    24,
      48,    52,    56,    57,    52,    21,    15,    16,    17,    11,
      12,    13,    14,    21,    50,    18,    21,    55,    55,    21,
      39,    53,    53,    53,    54,    54,    55,    55,    52,    45,
      31,    31,    40,     8,    41,    42,    31
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    29,    30,    32,    31,    33,    34,    33,    33,    35,
      36,    36,    36,    37,    37,    37,    39,    40,    38,    42,
      41,    41,    44,    45,    43,    46,    47,    48,    47,    49,
      49,    50,    50,    51,    52,    52,    52,    52,    53,    53,
      53,    54,    54,    54,    56,    55,    57,    55,    55,    55,
      58,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     4,     2,     0,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     0,     8,     0,
       3,     0,     0,     0,     7,     4,     2,     0,     5,     1,
       1,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     0,     3,     0,     3,     1,     3,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* PROGRAMME: tMain Bloc  */
#line 18 "compilateur.y"
                           { Parse_End(); }
#line 1286 "y.tab.c"
    break;

  case 3: /* $@1: %empty  */
#line 21 "compilateur.y"
                           { initBloc_TdS() ;}
#line 1292 "y.tab.c"
    break;

  case 4: /* Bloc: tOpeningBracket $@1 Corps tClosingBracket  */
#line 21 "compilateur.y"
                                                                     { expungeBloc_TdS() ;}
#line 1298 "y.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 23 "compilateur.y"
                                    {printf("Post Bloc Corps\n");}
#line 1304 "y.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 31 "compilateur.y"
                                                                               { Parse_If() ; }
#line 1310 "y.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 31 "compilateur.y"
                                                                                                     { Parse_Else() ; }
#line 1316 "y.tab.c"
    break;

  case 18: /* InstructionIfElse: tIf tOpeningParenthesis Prio0Arith tClosingParenthesis $@3 Bloc $@4 InstructionElse  */
#line 31 "compilateur.y"
                                                                                                                                        { Parse_EndElse() ; }
#line 1322 "y.tab.c"
    break;

  case 19: /* $@5: %empty  */
#line 33 "compilateur.y"
                            {printf("tElse\n");}
#line 1328 "y.tab.c"
    break;

  case 20: /* InstructionElse: tElse $@5 Bloc  */
#line 33 "compilateur.y"
                                                       {printf("Post Bloc Instruction Else\n");}
#line 1334 "y.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 35 "compilateur.y"
                              { Parse_InitWhile() ; }
#line 1340 "y.tab.c"
    break;

  case 23: /* $@7: %empty  */
#line 35 "compilateur.y"
                                                                                                         { Parse_While() ; }
#line 1346 "y.tab.c"
    break;

  case 24: /* InstructionWhile: tWhile $@6 tOpeningParenthesis Prio0Arith tClosingParenthesis $@7 Bloc  */
#line 35 "compilateur.y"
                                                                                                                                  { Parse_EndWhile() ; }
#line 1352 "y.tab.c"
    break;

  case 25: /* Printf: tPrintf tOpeningParenthesis Prio0Arith tClosingParenthesis  */
#line 37 "compilateur.y"
                                                                        { Parse_printf() ; }
#line 1358 "y.tab.c"
    break;

  case 26: /* Declaration: DeclarationType VarName  */
#line 40 "compilateur.y"
                                          { push_TdS((yyvsp[0].var), (yyvsp[-1].var)) ; }
#line 1364 "y.tab.c"
    break;

  case 27: /* $@8: %empty  */
#line 41 "compilateur.y"
                                          { push_TdS((yyvsp[0].var), (yyvsp[-1].var)) ; }
#line 1370 "y.tab.c"
    break;

  case 28: /* Declaration: DeclarationType VarName $@8 tAssign Prio0Arith  */
#line 41 "compilateur.y"
                                                                                    { Parse_Copy((yyvsp[-3].var)) ; }
#line 1376 "y.tab.c"
    break;

  case 29: /* DeclarationType: tDeclareConstInt  */
#line 44 "compilateur.y"
                                       { (yyval.var) = "const_int" ; }
#line 1382 "y.tab.c"
    break;

  case 30: /* DeclarationType: tDeclareInt  */
#line 45 "compilateur.y"
                                  { (yyval.var) = "int" ; }
#line 1388 "y.tab.c"
    break;

  case 31: /* VarName: tVarName tVirgule VarName  */
#line 58 "compilateur.y"
                                        { (yyval.var) = (yyvsp[-2].var) ;}
#line 1394 "y.tab.c"
    break;

  case 32: /* VarName: tVarName  */
#line 59 "compilateur.y"
                       { (yyval.var) = (yyvsp[0].var) ; }
#line 1400 "y.tab.c"
    break;

  case 33: /* Assignation: tVarName tAssign Prio0Arith  */
#line 62 "compilateur.y"
                                              { Parse_Copy((yyvsp[-2].var)) ; }
#line 1406 "y.tab.c"
    break;

  case 34: /* Prio0Arith: Prio1Arith tSup Prio1Arith  */
#line 66 "compilateur.y"
                                            { Parse_Arith(SUP) ; }
#line 1412 "y.tab.c"
    break;

  case 35: /* Prio0Arith: Prio1Arith tInf Prio1Arith  */
#line 67 "compilateur.y"
                                              { Parse_Arith(INF) ; }
#line 1418 "y.tab.c"
    break;

  case 36: /* Prio0Arith: Prio1Arith tEqual Prio1Arith  */
#line 68 "compilateur.y"
                                                { Parse_Arith(EQU) ; }
#line 1424 "y.tab.c"
    break;

  case 38: /* Prio1Arith: Prio2Arith tPlus Prio2Arith  */
#line 72 "compilateur.y"
                                             { Parse_Arith(ADD) ; }
#line 1430 "y.tab.c"
    break;

  case 39: /* Prio1Arith: Prio2Arith tMinus Prio2Arith  */
#line 73 "compilateur.y"
                                                { Parse_Arith(SOU) ; }
#line 1436 "y.tab.c"
    break;

  case 41: /* Prio2Arith: Prio3Arith tDiv Prio3Arith  */
#line 77 "compilateur.y"
                                            { Parse_Arith(DIV) ; }
#line 1442 "y.tab.c"
    break;

  case 42: /* Prio2Arith: Prio3Arith tStar Prio3Arith  */
#line 78 "compilateur.y"
                                         { Parse_Arith(MUL) ; }
#line 1448 "y.tab.c"
    break;

  case 44: /* $@9: %empty  */
#line 82 "compilateur.y"
                       { Parse_Unref() ; }
#line 1454 "y.tab.c"
    break;

  case 46: /* $@10: %empty  */
#line 83 "compilateur.y"
                   { Parse_Ref() ; }
#line 1460 "y.tab.c"
    break;

  case 48: /* Prio3Arith: Val  */
#line 84 "compilateur.y"
                 { Parse_ApplyRef() ; }
#line 1466 "y.tab.c"
    break;

  case 49: /* Prio3Arith: tOpeningParenthesis Prio0Arith tClosingParenthesis  */
#line 85 "compilateur.y"
                                                                { Parse_ApplyRef() ; }
#line 1472 "y.tab.c"
    break;

  case 50: /* Val: tVarName  */
#line 88 "compilateur.y"
                   { Parse_Copy_To_TdS_Top((yyvsp[0].var)) ; }
#line 1478 "y.tab.c"
    break;

  case 51: /* Val: tValueInt  */
#line 89 "compilateur.y"
                    { Parse_AllocateTemp((yyvsp[0].nb), "int") ; }
#line 1484 "y.tab.c"
    break;

  case 52: /* Val: tValueExp  */
#line 90 "compilateur.y"
                    { Parse_AllocateTemp((yyvsp[0].nb_exp), "int") ; }
#line 1490 "y.tab.c"
    break;


#line 1494 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 93 "compilateur.y"


void yyerror(char *s) {
    fprintf(stderr,  "line %d: %s\n",  yylineno, s);
    exit(-1);
}

int main(){
    // On crée le fichier 
    Parse_Init("ASM_file") ;
    yyparse();
    printf("Final TdS: \n") ;  print_TdS() ;
    return 0 ;
}
