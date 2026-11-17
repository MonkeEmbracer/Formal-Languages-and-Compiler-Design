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
#line 1 "poemia.y"

#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char* message);

extern int yylineno;
extern char* yytext;

void scanner_init(const char* source, const char* token_list);
int scanner_finish(void);

static int* productions = NULL;
static int production_count = 0;
static int production_capacity = 0;

static void use(int number) {
    if (production_count == production_capacity) {
        production_capacity = production_capacity == 0 ? 64 : production_capacity * 2;
        productions = realloc(productions, production_capacity * sizeof(int));
    }
    productions[production_count++] = number;
}

#line 97 "poemia.tab.c"

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

#include "poemia.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TITLE = 3,                      /* TITLE  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_BY = 5,                         /* BY  */
  YYSYMBOL_AUTHOR = 6,                     /* AUTHOR  */
  YYSYMBOL_DECL_KW = 7,                    /* DECL_KW  */
  YYSYMBOL_COMMA_SP = 8,                   /* COMMA_SP  */
  YYSYMBOL_TYPE_INT = 9,                   /* TYPE_INT  */
  YYSYMBOL_TYPE_QUEUE = 10,                /* TYPE_QUEUE  */
  YYSYMBOL_ASSIGN_KW = 11,                 /* ASSIGN_KW  */
  YYSYMBOL_ASSIGN_MID = 12,                /* ASSIGN_MID  */
  YYSYMBOL_IDENTIFIER = 13,                /* IDENTIFIER  */
  YYSYMBOL_INT_CONST = 14,                 /* INT_CONST  */
  YYSYMBOL_STRING_CONST = 15,              /* STRING_CONST  */
  YYSYMBOL_OP_PLUS = 16,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 17,                  /* OP_MINUS  */
  YYSYMBOL_OP_TIMES = 18,                  /* OP_TIMES  */
  YYSYMBOL_OP_DIV = 19,                    /* OP_DIV  */
  YYSYMBOL_LPAREN = 20,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 21,                    /* RPAREN  */
  YYSYMBOL_CMP_GT = 22,                    /* CMP_GT  */
  YYSYMBOL_CMP_GE = 23,                    /* CMP_GE  */
  YYSYMBOL_CMP_LT = 24,                    /* CMP_LT  */
  YYSYMBOL_CMP_LE = 25,                    /* CMP_LE  */
  YYSYMBOL_CMP_EQ = 26,                    /* CMP_EQ  */
  YYSYMBOL_CMP_NE = 27,                    /* CMP_NE  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_BOOL_TRUE = 30,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 31,                /* BOOL_FALSE  */
  YYSYMBOL_IF_START = 32,                  /* IF_START  */
  YYSYMBOL_IF_OPEN = 33,                   /* IF_OPEN  */
  YYSYMBOL_IF_CONT = 34,                   /* IF_CONT  */
  YYSYMBOL_COMMA_NL = 35,                  /* COMMA_NL  */
  YYSYMBOL_IF_THEN = 36,                   /* IF_THEN  */
  YYSYMBOL_ELSE_KW = 37,                   /* ELSE_KW  */
  YYSYMBOL_DOT = 38,                       /* DOT  */
  YYSYMBOL_QUOTE_END = 39,                 /* QUOTE_END  */
  YYSYMBOL_REPEAT_START = 40,              /* REPEAT_START  */
  YYSYMBOL_REPEAT_COLON = 41,              /* REPEAT_COLON  */
  YYSYMBOL_REPEAT_END = 42,                /* REPEAT_END  */
  YYSYMBOL_WORM_PUSH_START = 43,           /* WORM_PUSH_START  */
  YYSYMBOL_WORM_PUSH_VERB = 44,            /* WORM_PUSH_VERB  */
  YYSYMBOL_WORM_PUSH_PREFIX = 45,          /* WORM_PUSH_PREFIX  */
  YYSYMBOL_WORM_PUSH_BY = 46,              /* WORM_PUSH_BY  */
  YYSYMBOL_WORM_POP_VERB = 47,             /* WORM_POP_VERB  */
  YYSYMBOL_WORM_POP_OBJ = 48,              /* WORM_POP_OBJ  */
  YYSYMBOL_WORM_TOP = 49,                  /* WORM_TOP  */
  YYSYMBOL_WORM_CLEAR_START = 50,          /* WORM_CLEAR_START  */
  YYSYMBOL_WORM_CLEAR_END = 51,            /* WORM_CLEAR_END  */
  YYSYMBOL_WORM_EMPTY = 52,                /* WORM_EMPTY  */
  YYSYMBOL_READ_START = 53,                /* READ_START  */
  YYSYMBOL_READ_END = 54,                  /* READ_END  */
  YYSYMBOL_PRINT_KW = 55,                  /* PRINT_KW  */
  YYSYMBOL_PRINT_MESSAGE = 56,             /* PRINT_MESSAGE  */
  YYSYMBOL_PRINT_OF = 57,                  /* PRINT_OF  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_stmt_list = 60,                 /* stmt_list  */
  YYSYMBOL_statement = 61,                 /* statement  */
  YYSYMBOL_decl_stmt = 62,                 /* decl_stmt  */
  YYSYMBOL_type = 63,                      /* type  */
  YYSYMBOL_assign_stmt = 64,               /* assign_stmt  */
  YYSYMBOL_expr = 65,                      /* expr  */
  YYSYMBOL_term = 66,                      /* term  */
  YYSYMBOL_factor = 67,                    /* factor  */
  YYSYMBOL_add_op = 68,                    /* add_op  */
  YYSYMBOL_mul_op = 69,                    /* mul_op  */
  YYSYMBOL_if_stmt = 70,                   /* if_stmt  */
  YYSYMBOL_else_part = 71,                 /* else_part  */
  YYSYMBOL_bool_expr = 72,                 /* bool_expr  */
  YYSYMBOL_bool_term = 73,                 /* bool_term  */
  YYSYMBOL_bool_factor = 74,               /* bool_factor  */
  YYSYMBOL_comparison = 75,                /* comparison  */
  YYSYMBOL_cmp_op = 76,                    /* cmp_op  */
  YYSYMBOL_repeat_stmt = 77,               /* repeat_stmt  */
  YYSYMBOL_push_stmt = 78,                 /* push_stmt  */
  YYSYMBOL_pop_stmt = 79,                  /* pop_stmt  */
  YYSYMBOL_clear_stmt = 80,                /* clear_stmt  */
  YYSYMBOL_read_stmt = 81,                 /* read_stmt  */
  YYSYMBOL_read_end = 82,                  /* read_end  */
  YYSYMBOL_print_stmt = 83,                /* print_stmt  */
  YYSYMBOL_printable = 84                  /* printable  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   312


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    52,    53,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    70,    74,    75,    79,    83,
      84,    88,    89,    93,    94,    95,    96,   100,   101,   105,
     106,   110,   115,   116,   120,   121,   125,   126,   130,   131,
     132,   133,   134,   138,   142,   143,   144,   145,   146,   147,
     151,   155,   156,   160,   164,   168,   172,   173,   177,   178,
     182,   183
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TITLE", "NEWLINE",
  "BY", "AUTHOR", "DECL_KW", "COMMA_SP", "TYPE_INT", "TYPE_QUEUE",
  "ASSIGN_KW", "ASSIGN_MID", "IDENTIFIER", "INT_CONST", "STRING_CONST",
  "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIV", "LPAREN", "RPAREN",
  "CMP_GT", "CMP_GE", "CMP_LT", "CMP_LE", "CMP_EQ", "CMP_NE", "OR", "AND",
  "BOOL_TRUE", "BOOL_FALSE", "IF_START", "IF_OPEN", "IF_CONT", "COMMA_NL",
  "IF_THEN", "ELSE_KW", "DOT", "QUOTE_END", "REPEAT_START", "REPEAT_COLON",
  "REPEAT_END", "WORM_PUSH_START", "WORM_PUSH_VERB", "WORM_PUSH_PREFIX",
  "WORM_PUSH_BY", "WORM_POP_VERB", "WORM_POP_OBJ", "WORM_TOP",
  "WORM_CLEAR_START", "WORM_CLEAR_END", "WORM_EMPTY", "READ_START",
  "READ_END", "PRINT_KW", "PRINT_MESSAGE", "PRINT_OF", "$accept",
  "program", "stmt_list", "statement", "decl_stmt", "type", "assign_stmt",
  "expr", "term", "factor", "add_op", "mul_op", "if_stmt", "else_part",
  "bool_expr", "bool_term", "bool_factor", "comparison", "cmp_op",
  "repeat_stmt", "push_stmt", "pop_stmt", "clear_stmt", "read_stmt",
  "read_end", "print_stmt", "printable", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-46)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,    10,    27,    11,   -46,    25,    34,    14,    36,    38,
      35,     6,    45,    -5,    60,    61,     4,    71,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,    68,    65,
      46,    14,   -18,   -46,   -46,    -5,    66,     2,    16,   -46,
      30,    48,    73,    52,    14,    53,    -5,    52,    85,    -5,
      42,     7,   -46,   -46,   -46,    87,    -5,   -46,   -46,    -5,
     -46,   -46,   -46,   -46,    51,    52,   -46,   -46,    82,    83,
      81,   -46,   -46,   -46,   -46,   -46,   -46,   -46,    54,    82,
     -22,     0,    54,   -46,   -46,   -46,    16,   -46,   -46,    70,
     -11,   -46,   -46,   -46,   -46,   -46,   -46,    -5,    52,    52,
      76,    52,   -46,    54,    81,   -46,   109,    83,    14,    -1,
     110,    78,    77,   113,   -46,    14,     1,   -46
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     4,     5,
       6,     7,     8,    11,    12,    13,    10,     9,     0,     0,
       0,    14,     0,    23,    24,     0,     0,     0,    20,    22,
       0,    57,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,    26,    27,    28,     0,     0,    29,    30,     0,
      54,    56,    55,    58,    23,     0,    40,    41,    60,    61,
      35,    37,    38,    59,     3,    16,    17,    15,    18,     0,
       0,    14,    51,    53,    25,    52,    19,    21,    42,     0,
       0,    44,    45,    46,    47,    48,    49,     0,     0,     0,
       0,     0,    39,    43,    34,    36,     0,    50,    14,     0,
      33,     0,     0,     0,    31,    14,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -46,   -46,   -30,   -40,   -46,   -46,   -46,   -13,    62,    63,
     -46,   -46,   -46,   -46,   -45,    21,    22,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    17,    18,    19,    77,    20,    79,    38,    39,
      56,    59,    21,   112,    69,    70,    71,    72,    97,    22,
      23,    24,    25,    26,    62,    27,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    48,    80,    44,    74,    44,    98,     8,    33,    34,
     102,     9,     1,   100,     3,    35,     5,    98,    53,    54,
      90,     8,    51,    53,    54,     9,    49,     4,    84,    50,
      68,     6,    10,    78,    57,    58,    82,   110,     7,   117,
      11,    74,   101,    12,    36,    13,    10,    31,    55,    28,
      14,    29,    89,    15,    11,    16,   107,    12,    32,    13,
      42,    43,    75,    76,    14,    64,    34,    15,    30,    16,
      53,    54,    65,    40,    41,    44,    45,    46,   109,    52,
      47,    60,    66,    67,   103,   116,    53,    54,    63,    81,
      83,    84,    91,    92,    93,    94,    95,    96,    53,    54,
      85,    36,    61,    88,    91,    92,    93,    94,    95,    96,
      99,    98,   106,   108,   111,   113,   114,   115,    86,   104,
       0,   105,    87
};

static const yytype_int8 yycheck[] =
{
      13,    31,    47,     4,    44,     4,    28,     7,    13,    14,
      21,    11,     3,    35,     4,    20,     5,    28,    16,    17,
      65,     7,    35,    16,    17,    11,    44,     0,    21,    47,
      43,     6,    32,    46,    18,    19,    49,    38,     4,    38,
      40,    81,    42,    43,    49,    45,    32,    41,    46,    13,
      50,    13,    65,    53,    40,    55,   101,    43,    13,    45,
      56,    57,     9,    10,    50,    13,    14,    53,    33,    55,
      16,    17,    20,    13,    13,     4,     8,    12,   108,    13,
      34,    51,    30,    31,    97,   115,    16,    17,    15,     4,
      48,    21,    22,    23,    24,    25,    26,    27,    16,    17,
      13,    49,    54,    52,    22,    23,    24,    25,    26,    27,
      29,    28,    36,     4,     4,    37,    39,     4,    56,    98,
      -1,    99,    59
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    59,     4,     0,     5,     6,     4,     7,    11,
      32,    40,    43,    45,    50,    53,    55,    60,    61,    62,
      64,    70,    77,    78,    79,    80,    81,    83,    13,    13,
      33,    41,    13,    13,    14,    20,    49,    65,    66,    67,
      13,    13,    56,    57,     4,     8,    12,    34,    60,    44,
      47,    65,    13,    16,    17,    46,    68,    18,    19,    69,
      51,    54,    82,    15,    13,    20,    30,    31,    65,    72,
      73,    74,    75,    84,    61,     9,    10,    63,    65,    65,
      72,     4,    65,    48,    21,    13,    66,    67,    52,    65,
      72,    22,    23,    24,    25,    26,    27,    76,    28,    29,
      35,    42,    21,    65,    73,    74,    36,    72,     4,    60,
      38,     4,    71,    37,    39,     4,    60,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    63,    63,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      74,    74,    74,    75,    76,    76,    76,    76,    76,    76,
      77,    78,    78,    79,    80,    81,    82,    82,    83,    83,
      84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     6,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     1,     1,     4,     3,
       1,     3,     1,     1,     1,     3,     2,     1,     1,     1,
       1,    11,     5,     0,     3,     1,     3,     1,     1,     3,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       6,     4,     4,     4,     3,     3,     1,     0,     3,     3,
       1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* program: TITLE NEWLINE BY AUTHOR NEWLINE stmt_list  */
#line 48 "poemia.y"
                                                { use(1); }
#line 1523 "poemia.tab.c"
    break;

  case 3: /* stmt_list: stmt_list NEWLINE statement  */
#line 52 "poemia.y"
                                  { use(2); }
#line 1529 "poemia.tab.c"
    break;

  case 4: /* stmt_list: statement  */
#line 53 "poemia.y"
                { use(3); }
#line 1535 "poemia.tab.c"
    break;

  case 5: /* statement: decl_stmt  */
#line 57 "poemia.y"
                { use(4); }
#line 1541 "poemia.tab.c"
    break;

  case 6: /* statement: assign_stmt  */
#line 58 "poemia.y"
                  { use(5); }
#line 1547 "poemia.tab.c"
    break;

  case 7: /* statement: if_stmt  */
#line 59 "poemia.y"
              { use(6); }
#line 1553 "poemia.tab.c"
    break;

  case 8: /* statement: repeat_stmt  */
#line 60 "poemia.y"
                  { use(7); }
#line 1559 "poemia.tab.c"
    break;

  case 9: /* statement: print_stmt  */
#line 61 "poemia.y"
                 { use(8); }
#line 1565 "poemia.tab.c"
    break;

  case 10: /* statement: read_stmt  */
#line 62 "poemia.y"
                { use(9); }
#line 1571 "poemia.tab.c"
    break;

  case 11: /* statement: push_stmt  */
#line 63 "poemia.y"
                { use(10); }
#line 1577 "poemia.tab.c"
    break;

  case 12: /* statement: pop_stmt  */
#line 64 "poemia.y"
               { use(11); }
#line 1583 "poemia.tab.c"
    break;

  case 13: /* statement: clear_stmt  */
#line 65 "poemia.y"
                 { use(12); }
#line 1589 "poemia.tab.c"
    break;

  case 14: /* statement: %empty  */
#line 66 "poemia.y"
             { use(13); }
#line 1595 "poemia.tab.c"
    break;

  case 15: /* decl_stmt: DECL_KW IDENTIFIER COMMA_SP type  */
#line 70 "poemia.y"
                                       { use(14); }
#line 1601 "poemia.tab.c"
    break;

  case 16: /* type: TYPE_INT  */
#line 74 "poemia.y"
               { use(15); }
#line 1607 "poemia.tab.c"
    break;

  case 17: /* type: TYPE_QUEUE  */
#line 75 "poemia.y"
                 { use(16); }
#line 1613 "poemia.tab.c"
    break;

  case 18: /* assign_stmt: ASSIGN_KW IDENTIFIER ASSIGN_MID expr  */
#line 79 "poemia.y"
                                           { use(17); }
#line 1619 "poemia.tab.c"
    break;

  case 19: /* expr: expr add_op term  */
#line 83 "poemia.y"
                       { use(18); }
#line 1625 "poemia.tab.c"
    break;

  case 20: /* expr: term  */
#line 84 "poemia.y"
           { use(19); }
#line 1631 "poemia.tab.c"
    break;

  case 21: /* term: term mul_op factor  */
#line 88 "poemia.y"
                         { use(20); }
#line 1637 "poemia.tab.c"
    break;

  case 22: /* term: factor  */
#line 89 "poemia.y"
             { use(21); }
#line 1643 "poemia.tab.c"
    break;

  case 23: /* factor: IDENTIFIER  */
#line 93 "poemia.y"
                 { use(22); }
#line 1649 "poemia.tab.c"
    break;

  case 24: /* factor: INT_CONST  */
#line 94 "poemia.y"
                { use(23); }
#line 1655 "poemia.tab.c"
    break;

  case 25: /* factor: LPAREN expr RPAREN  */
#line 95 "poemia.y"
                         { use(24); }
#line 1661 "poemia.tab.c"
    break;

  case 26: /* factor: WORM_TOP IDENTIFIER  */
#line 96 "poemia.y"
                          { use(25); }
#line 1667 "poemia.tab.c"
    break;

  case 27: /* add_op: OP_PLUS  */
#line 100 "poemia.y"
              { use(26); }
#line 1673 "poemia.tab.c"
    break;

  case 28: /* add_op: OP_MINUS  */
#line 101 "poemia.y"
               { use(27); }
#line 1679 "poemia.tab.c"
    break;

  case 29: /* mul_op: OP_TIMES  */
#line 105 "poemia.y"
               { use(28); }
#line 1685 "poemia.tab.c"
    break;

  case 30: /* mul_op: OP_DIV  */
#line 106 "poemia.y"
             { use(29); }
#line 1691 "poemia.tab.c"
    break;

  case 31: /* if_stmt: IF_START IF_OPEN IF_CONT bool_expr COMMA_NL IF_THEN NEWLINE stmt_list DOT else_part QUOTE_END  */
#line 111 "poemia.y"
                                                        { use(30); }
#line 1697 "poemia.tab.c"
    break;

  case 32: /* else_part: NEWLINE ELSE_KW NEWLINE stmt_list DOT  */
#line 115 "poemia.y"
                                            { use(31); }
#line 1703 "poemia.tab.c"
    break;

  case 33: /* else_part: %empty  */
#line 116 "poemia.y"
             { use(32); }
#line 1709 "poemia.tab.c"
    break;

  case 34: /* bool_expr: bool_expr OR bool_term  */
#line 120 "poemia.y"
                             { use(33); }
#line 1715 "poemia.tab.c"
    break;

  case 35: /* bool_expr: bool_term  */
#line 121 "poemia.y"
                { use(34); }
#line 1721 "poemia.tab.c"
    break;

  case 36: /* bool_term: bool_term AND bool_factor  */
#line 125 "poemia.y"
                                { use(35); }
#line 1727 "poemia.tab.c"
    break;

  case 37: /* bool_term: bool_factor  */
#line 126 "poemia.y"
                  { use(36); }
#line 1733 "poemia.tab.c"
    break;

  case 38: /* bool_factor: comparison  */
#line 130 "poemia.y"
                 { use(37); }
#line 1739 "poemia.tab.c"
    break;

  case 39: /* bool_factor: LPAREN bool_expr RPAREN  */
#line 131 "poemia.y"
                              { use(38); }
#line 1745 "poemia.tab.c"
    break;

  case 40: /* bool_factor: BOOL_TRUE  */
#line 132 "poemia.y"
                { use(39); }
#line 1751 "poemia.tab.c"
    break;

  case 41: /* bool_factor: BOOL_FALSE  */
#line 133 "poemia.y"
                 { use(40); }
#line 1757 "poemia.tab.c"
    break;

  case 42: /* bool_factor: IDENTIFIER WORM_EMPTY  */
#line 134 "poemia.y"
                            { use(41); }
#line 1763 "poemia.tab.c"
    break;

  case 43: /* comparison: expr cmp_op expr  */
#line 138 "poemia.y"
                       { use(42); }
#line 1769 "poemia.tab.c"
    break;

  case 44: /* cmp_op: CMP_GT  */
#line 142 "poemia.y"
             { use(43); }
#line 1775 "poemia.tab.c"
    break;

  case 45: /* cmp_op: CMP_GE  */
#line 143 "poemia.y"
             { use(44); }
#line 1781 "poemia.tab.c"
    break;

  case 46: /* cmp_op: CMP_LT  */
#line 144 "poemia.y"
             { use(45); }
#line 1787 "poemia.tab.c"
    break;

  case 47: /* cmp_op: CMP_LE  */
#line 145 "poemia.y"
             { use(46); }
#line 1793 "poemia.tab.c"
    break;

  case 48: /* cmp_op: CMP_EQ  */
#line 146 "poemia.y"
             { use(47); }
#line 1799 "poemia.tab.c"
    break;

  case 49: /* cmp_op: CMP_NE  */
#line 147 "poemia.y"
             { use(48); }
#line 1805 "poemia.tab.c"
    break;

  case 50: /* repeat_stmt: REPEAT_START REPEAT_COLON stmt_list NEWLINE REPEAT_END bool_expr  */
#line 151 "poemia.y"
                                                                       { use(49); }
#line 1811 "poemia.tab.c"
    break;

  case 51: /* push_stmt: WORM_PUSH_START IDENTIFIER WORM_PUSH_VERB expr  */
#line 155 "poemia.y"
                                                     { use(50); }
#line 1817 "poemia.tab.c"
    break;

  case 52: /* push_stmt: WORM_PUSH_PREFIX expr WORM_PUSH_BY IDENTIFIER  */
#line 156 "poemia.y"
                                                    { use(51); }
#line 1823 "poemia.tab.c"
    break;

  case 53: /* pop_stmt: WORM_PUSH_START IDENTIFIER WORM_POP_VERB WORM_POP_OBJ  */
#line 160 "poemia.y"
                                                            { use(52); }
#line 1829 "poemia.tab.c"
    break;

  case 54: /* clear_stmt: WORM_CLEAR_START IDENTIFIER WORM_CLEAR_END  */
#line 164 "poemia.y"
                                                 { use(53); }
#line 1835 "poemia.tab.c"
    break;

  case 55: /* read_stmt: READ_START IDENTIFIER read_end  */
#line 168 "poemia.y"
                                     { use(54); }
#line 1841 "poemia.tab.c"
    break;

  case 56: /* read_end: READ_END  */
#line 172 "poemia.y"
               { use(55); }
#line 1847 "poemia.tab.c"
    break;

  case 57: /* read_end: %empty  */
#line 173 "poemia.y"
             { use(56); }
#line 1853 "poemia.tab.c"
    break;

  case 58: /* print_stmt: PRINT_KW PRINT_MESSAGE STRING_CONST  */
#line 177 "poemia.y"
                                          { use(57); }
#line 1859 "poemia.tab.c"
    break;

  case 59: /* print_stmt: PRINT_KW PRINT_OF printable  */
#line 178 "poemia.y"
                                  { use(58); }
#line 1865 "poemia.tab.c"
    break;

  case 60: /* printable: expr  */
#line 182 "poemia.y"
           { use(59); }
#line 1871 "poemia.tab.c"
    break;

  case 61: /* printable: bool_expr  */
#line 183 "poemia.y"
                { use(60); }
#line 1877 "poemia.tab.c"
    break;


#line 1881 "poemia.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 186 "poemia.y"


void yyerror(const char* message) {
    printf("SYNTAX ERROR line %d near '%s': %s\n", yylineno, yytext, message);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <source file> [token list]\n", argv[0]);
        return 1;
    }

    scanner_init(argv[1], argc > 2 ? argv[2] : "tokens.txt");
    int parse_result = yyparse();
    int lexical_errors = scanner_finish();

    if (parse_result == 0 && lexical_errors == 0) {
        printf("Program is syntactically correct\n");

        printf("Reductions (bottom-up order):\n");
        for (int i = 0; i < production_count; i++) {
            printf("%d ", productions[i]);
        }
        printf("\n");

        printf("Rightmost derivation:\n");
        for (int i = production_count - 1; i >= 0; i--) {
            printf("%d ", productions[i]);
        }
        printf("\n");
    }
    else {
        if (lexical_errors > 0) {
            printf("%d lexical error(s)\n", lexical_errors);
        }
        if (parse_result != 0) {
            printf("Parsing failed\n");
        }
    }

    free(productions);
    return parse_result != 0 || lexical_errors != 0;
}
