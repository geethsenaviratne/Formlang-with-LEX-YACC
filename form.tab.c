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
#line 1 "form.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int yylineno;  

void yyerror(const char *s);
int yylex();

#define MAX_FIELDS 100
char* used_fields[MAX_FIELDS];
int field_count = 0;

bool is_duplicate_field(const char* name) {
    for (int i = 0; i < field_count; i++) {
        if (strcmp(used_fields[i], name) == 0) return true;
    }
    return false;
}

void add_field(const char* name) {
    if (field_count < MAX_FIELDS) {
        used_fields[field_count++] = strdup(name);
    }
}

bool is_valid_field_type(const char* type) {
    const char* valid[] = {
        "text", "number", "password", "email", "date", "file",
        "checkbox", "radio", "dropdown", "textarea"
    };

    for (int i = 0; i < 10; i++) {
        if (strcmp(valid[i], type) == 0) return true;
    }
    return false;
}

char* concat(const char* s1, const char* s2) {
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

#line 118 "form.tab.c"

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

#include "form.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_ROWS = 6,                       /* ROWS  */
  YYSYMBOL_COLS = 7,                       /* COLS  */
  YYSYMBOL_DEFAULT = 8,                    /* DEFAULT  */
  YYSYMBOL_FORM = 9,                       /* FORM  */
  YYSYMBOL_SECTION = 10,                   /* SECTION  */
  YYSYMBOL_FIELD = 11,                     /* FIELD  */
  YYSYMBOL_REQUIRED = 12,                  /* REQUIRED  */
  YYSYMBOL_META = 13,                      /* META  */
  YYSYMBOL_EQUAL = 14,                     /* EQUAL  */
  YYSYMBOL_VALIDATE = 15,                  /* VALIDATE  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ERROR = 17,                     /* ERROR  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_OPTIONS = 19,                   /* OPTIONS  */
  YYSYMBOL_TRUE = 20,                      /* TRUE  */
  YYSYMBOL_FALSE = 21,                     /* FALSE  */
  YYSYMBOL_LBRACKET = 22,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 23,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_COLON = 25,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 26,                 /* SEMICOLON  */
  YYSYMBOL_LBRACE = 27,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 28,                    /* RBRACE  */
  YYSYMBOL_MIN = 29,                       /* MIN  */
  YYSYMBOL_MAX = 30,                       /* MAX  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_program = 32,                   /* program  */
  YYSYMBOL_33_1 = 33,                      /* $@1  */
  YYSYMBOL_meta_list = 34,                 /* meta_list  */
  YYSYMBOL_meta_stmt = 35,                 /* meta_stmt  */
  YYSYMBOL_section = 36,                   /* section  */
  YYSYMBOL_field_list = 37,                /* field_list  */
  YYSYMBOL_field = 38,                     /* field  */
  YYSYMBOL_rowval = 39,                    /* rowval  */
  YYSYMBOL_colval = 40,                    /* colval  */
  YYSYMBOL_defval = 41,                    /* defval  */
  YYSYMBOL_form_body = 42,                 /* form_body  */
  YYSYMBOL_validate_block = 43,            /* validate_block  */
  YYSYMBOL_option_list = 44                /* option_list  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  26
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    69,    78,    79,    83,    90,    96,    97,
     101,   117,   141,   165,   180,   199,   215,   233,   234,   235,
     238,   239,   241,   245,   272,   277,   278
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "STRING",
  "NUMBER", "ROWS", "COLS", "DEFAULT", "FORM", "SECTION", "FIELD",
  "REQUIRED", "META", "EQUAL", "VALIDATE", "IF", "ERROR", "LT", "OPTIONS",
  "TRUE", "FALSE", "LBRACKET", "RBRACKET", "COMMA", "COLON", "SEMICOLON",
  "LBRACE", "RBRACE", "MIN", "MAX", "$accept", "program", "$@1",
  "meta_list", "meta_stmt", "section", "field_list", "field", "rowval",
  "colval", "defval", "form_body", "validate_block", "option_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-21)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -21,    12,    -4,   -21,    11,    14,   -21,   -12,     5,    15,
      17,    19,   -21,    -8,    -2,    -1,     0,    13,   -21,   -21,
     -21,    18,    16,     2,    28,   -10,   -21,    30,   -21,     9,
     -21,   -21,    20,    32,    31,    -6,    10,    25,    21,    22,
      26,    37,   -21,    29,    27,    40,   -21,    23,    24,   -21,
     -20,    44,    46,   -21,    45,   -21,    37,    39,    49,    33,
      34,    41,   -13,    35,   -21,    42,    36,    52,    47,   -21,
      50,    38,   -21,    54,    43,    53,   -21,    56,   -21,    48,
      63,   -21,   -21,    51,   -21
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     4,     0,     0,     0,
       0,     0,    22,     2,     0,     0,     0,    24,    20,    21,
       6,     0,     0,     0,     0,     0,     9,     0,     3,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,     0,     0,     0,    10,     0,     0,    25,
       0,     0,     0,    17,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,     0,     0,     0,    11,
       0,     0,    18,     0,     0,     0,    23,     0,    12,     0,
       0,    16,    19,     0,    15
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,   -21,   -21,    55,   -21,    57,   -21,   -21,
     -21,   -21,    58,    59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,    17,     2,     6,    12,    25,    26,    54,    73,
      83,    13,    19,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    24,    11,    57,    58,     4,    38,    16,    39,     5,
      68,    58,     3,    40,     7,     9,    41,     8,    30,    10,
      42,    14,    15,    43,    20,    11,    21,    22,    16,    24,
      28,    29,    27,    32,    33,    35,    36,    44,    34,    45,
      48,    49,    47,    51,    52,    53,    56,    46,    59,    55,
      60,    63,    61,    64,    75,    67,    70,    72,     0,    74,
      66,    69,    77,    65,    71,    79,    76,    82,    18,    78,
      80,     0,     0,     0,    81,    23,     0,    84,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62
};

static const yytype_int8 yycheck[] =
{
       6,    11,    10,    23,    24,     9,    12,    15,    14,    13,
      23,    24,     0,    19,     3,    27,    22,     3,    28,    14,
      26,     4,     3,    29,    26,    10,    27,    27,    15,    11,
      28,     3,    16,     3,    25,     3,     5,    27,    18,    14,
      14,     4,    20,    14,    17,     5,    22,    26,     4,    26,
       4,    12,     7,     4,     4,    14,    14,     5,    -1,    12,
      26,    26,     8,    30,    28,    12,    28,     4,    13,    26,
      14,    -1,    -1,    -1,    26,    17,    -1,    26,    -1,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,     0,     9,    13,    35,     3,     3,    27,
      14,    10,    36,    42,     4,     3,    15,    33,    36,    43,
      26,    27,    27,    43,    11,    37,    38,    16,    28,     3,
      28,    38,     3,    25,    18,     3,     5,     6,    12,    14,
      19,    22,    26,    29,    27,    14,    26,    20,    14,     4,
      44,    14,    17,     5,    39,    26,    22,    23,    24,     4,
       4,     7,    44,    12,     4,    30,    26,    14,    23,    26,
      14,    28,     5,    40,    12,     4,    28,     8,    26,    12,
      14,    26,     4,    41,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    33,    32,    34,    34,    35,    36,    37,    37,
      38,    38,    38,    38,    38,    38,    38,    39,    40,    41,
      42,    42,    42,    43,    43,    44,    44
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     2,     0,     5,     5,     2,     1,
       6,     9,    11,     7,     5,    14,    12,     1,     1,     1,
       2,     2,     1,    12,     0,     1,     3
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
  case 2: /* $@1: %empty  */
#line 69 "form.y"
                                              {
        printf("<!-- Form: %s -->\n", (yyvsp[-2].str));
        printf("<form name=\"%s\">\n%s<div><button type=\"submit\">Submit</button></div>\n</form>\n", (yyvsp[-2].str), (yyvsp[0].str));
    }
#line 1200 "form.tab.c"
    break;

  case 3: /* program: meta_list FORM IDENTIFIER LBRACE form_body $@1 validate_block RBRACE  */
#line 73 "form.y"
                           {
     }
#line 1207 "form.tab.c"
    break;

  case 4: /* meta_list: meta_list meta_stmt  */
#line 78 "form.y"
                        { (yyval.str) = (yyvsp[-1].str); }
#line 1213 "form.tab.c"
    break;

  case 5: /* meta_list: %empty  */
#line 79 "form.y"
                  { (yyval.str) = strdup(""); }
#line 1219 "form.tab.c"
    break;

  case 6: /* meta_stmt: META IDENTIFIER EQUAL STRING SEMICOLON  */
#line 83 "form.y"
                                           {
        printf("<!-- Meta: %s = %s -->\n", (yyvsp[-3].str), (yyvsp[-1].str));
    }
#line 1227 "form.tab.c"
    break;

  case 7: /* section: SECTION IDENTIFIER LBRACE field_list RBRACE  */
#line 90 "form.y"
                                                {
        (yyval.str) = (yyvsp[-1].str);
    }
#line 1235 "form.tab.c"
    break;

  case 8: /* field_list: field_list field  */
#line 96 "form.y"
                     { (yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1241 "form.tab.c"
    break;

  case 9: /* field_list: field  */
#line 97 "form.y"
            { (yyval.str) = (yyvsp[0].str); }
#line 1247 "form.tab.c"
    break;

  case 10: /* field: FIELD IDENTIFIER COLON IDENTIFIER REQUIRED SEMICOLON  */
#line 101 "form.y"
                                                         {
        if (!is_valid_field_type((yyvsp[-2].str))) {
            fprintf(stderr, "Error: Unknown field type '%s' for field '%s' at line %d\n", (yyvsp[-2].str), (yyvsp[-4].str), yylineno);
            YYABORT;            //Force parsing to stop with failure
        }
        if (is_duplicate_field((yyvsp[-4].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-4].str), yylineno);
            YYABORT;
        }
        add_field((yyvsp[-4].str));
        char buffer[256];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <input type=\"%s\" name=\"%s\" required></label></div>\n", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str));

        (yyval.str) = strdup(buffer);   //Stores the generated HTML string as the result of this rule
    }
#line 1267 "form.tab.c"
    break;

  case 11: /* field: FIELD IDENTIFIER COLON IDENTIFIER LBRACKET option_list RBRACKET REQUIRED SEMICOLON  */
#line 117 "form.y"
                                                                                         {
        if (strcmp((yyvsp[-5].str), "radio") != 0) {
            fprintf(stderr, "Error: Only 'radio' field can have direct options at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field((yyvsp[-7].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-7].str), yylineno);
            YYABORT;
        }
        add_field((yyvsp[-7].str));
        char buffer[1024] = "";
        char* options = strdup((yyvsp[-3].str));
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s:</label><br>\n", (yyvsp[-7].str));
        char* token = strtok(options, ",");
        while (token) {
            char line[256];
            sprintf(line, "<input type=\"radio\" name=\"%s\" value=%s> %s<br>\n", (yyvsp[-7].str), token, token);
            strcat(buffer, line);
            token = strtok(NULL, ",");
        }
        strcat(buffer, "</div>\n");
        (yyval.str) = strdup(buffer);       
    }
#line 1295 "form.tab.c"
    break;

  case 12: /* field: FIELD IDENTIFIER COLON IDENTIFIER OPTIONS EQUAL LBRACKET option_list RBRACKET REQUIRED SEMICOLON  */
#line 141 "form.y"
                                                                                                       {
        if (strcmp((yyvsp[-7].str), "dropdown") != 0) {
            fprintf(stderr, "Error: Only 'dropdown' field can use 'options=' at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field((yyvsp[-9].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-9].str), yylineno);
            YYABORT;   
        }
        add_field((yyvsp[-9].str));
        char buffer[1024] = "";
        char* options = strdup((yyvsp[-3].str));
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <select name=\"%s\" required>\n", (yyvsp[-9].str), (yyvsp[-9].str));
        char* token = strtok(options, ",");
        while (token) {
            char line[256];
            sprintf(line, "<option value=%s>%s</option>\n", token, token);
            strcat(buffer, line);
            token = strtok(NULL, ",");
        }
        strcat(buffer, "</select></label></div>\n");
        (yyval.str) = strdup(buffer);
    }
#line 1323 "form.tab.c"
    break;

  case 13: /* field: FIELD IDENTIFIER COLON IDENTIFIER EQUAL TRUE SEMICOLON  */
#line 165 "form.y"
                                                             {
        if (strcmp((yyvsp[-3].str), "checkbox") != 0) {
            fprintf(stderr, "Error: Only 'checkbox' field can be assigned = true at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field((yyvsp[-5].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-5].str), yylineno);
            YYABORT;
        }
        add_field((yyvsp[-5].str));
        char buffer[256];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label><input type=\"checkbox\" name=\"%s\" checked> %s</label></div>\n", (yyvsp[-5].str), (yyvsp[-5].str));
        (yyval.str) = strdup(buffer);
    }
#line 1342 "form.tab.c"
    break;

  case 14: /* field: FIELD IDENTIFIER COLON IDENTIFIER SEMICOLON  */
#line 180 "form.y"
                                                  {
        if (!is_valid_field_type((yyvsp[-1].str))) {
            fprintf(stderr, "Error: Unknown field type '%s' for field '%s' at line %d\n", (yyvsp[-1].str), (yyvsp[-3].str), yylineno);
            YYABORT;
        }
        if (is_duplicate_field((yyvsp[-3].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-3].str), yylineno);
            YYABORT;
        }
        add_field((yyvsp[-3].str));
        char buffer[256];
        if (strcmp((yyvsp[-1].str), "checkbox") == 0) {
            sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label><input type=\"checkbox\" name=\"%s\"> %s</label></div>\n", (yyvsp[-3].str), (yyvsp[-3].str));
        } else {
            sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <input type=\"%s\" name=\"%s\"></label></div>\n", (yyvsp[-3].str), (yyvsp[-1].str), (yyvsp[-3].str));
        }
        (yyval.str) = strdup(buffer);
    }
#line 1365 "form.tab.c"
    break;

  case 15: /* field: FIELD IDENTIFIER COLON IDENTIFIER ROWS EQUAL rowval COLS EQUAL colval DEFAULT EQUAL defval SEMICOLON  */
#line 199 "form.y"
                                                                                                           {
        if (strcmp((yyvsp[-10].str), "textarea") != 0) {
            fprintf(stderr, "Error: Only 'textarea' can have rows, cols, and default at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field((yyvsp[-12].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-12].str), yylineno);
            YYABORT;
        }
        add_field((yyvsp[-12].str));
        char buffer[512];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <br><textarea name=\"%s\" rows=\"%s\" cols=\"%s\">%s</textarea></label></div>\n",
                (yyvsp[-12].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-3].str), (yyvsp[-1].str));
        (yyval.str) = strdup(buffer);
    }
#line 1385 "form.tab.c"
    break;

  case 16: /* field: FIELD IDENTIFIER COLON IDENTIFIER MIN EQUAL STRING MAX EQUAL STRING REQUIRED SEMICOLON  */
#line 215 "form.y"
                                                                                             {
        if (!(strcmp((yyvsp[-8].str), "number") == 0 || strcmp((yyvsp[-8].str), "date") == 0)) {
            fprintf(stderr, "Error: Only 'number' or 'date' fields can use min/max at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field((yyvsp[-10].str))) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", (yyvsp[-10].str), yylineno);
            YYABORT;
        }
        add_field((yyvsp[-10].str));
        char buffer[512];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <input type=\"%s\" name=\"%s\" min=%s max=%s required></label></div>\n",
                (yyvsp[-10].str), (yyvsp[-8].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-2].str));
        (yyval.str) = strdup(buffer);
    }
#line 1405 "form.tab.c"
    break;

  case 17: /* rowval: NUMBER  */
#line 233 "form.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1411 "form.tab.c"
    break;

  case 18: /* colval: NUMBER  */
#line 234 "form.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1417 "form.tab.c"
    break;

  case 19: /* defval: STRING  */
#line 235 "form.y"
               { (yyval.str) = (yyvsp[0].str); }
#line 1423 "form.tab.c"
    break;

  case 20: /* form_body: form_body section  */
#line 238 "form.y"
                      { (yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str)); }
#line 1429 "form.tab.c"
    break;

  case 21: /* form_body: form_body validate_block  */
#line 239 "form.y"
                               { (yyval.str) = concat((yyvsp[-1].str), (yyvsp[0].str)); 
     }
#line 1436 "form.tab.c"
    break;

  case 22: /* form_body: section  */
#line 241 "form.y"
              { (yyval.str) = (yyvsp[0].str); }
#line 1442 "form.tab.c"
    break;

  case 23: /* validate_block: VALIDATE LBRACE IF IDENTIFIER LT NUMBER LBRACE ERROR STRING SEMICOLON RBRACE RBRACE  */
#line 245 "form.y"
                                                                                        {
        char buffer[2048];
        char *raw_msg = strdup((yyvsp[-3].str));
        char *msg = raw_msg;

        // Remove surrounding quotes
        int len = strlen(msg);
        if (len >= 2 && msg[0] == '"' && msg[len - 1] == '"') {
            msg[len - 1] = '\0';  // Remove trailing quote
            msg++;                // Skip leading quote
        }

//JavaScript for Validation
        snprintf(buffer, sizeof(buffer),
            "<script>\n"
            "document.querySelector('form').addEventListener('submit', function(e) {\n"
            "    var val = document.forms[0]['%s'].value;\n"
            "    if (Number(val) < %s) {\n"
            "        e.preventDefault();\n"
            "        alert('%s');\n"
            "    }\n"
            "});\n"
            "</script>\n",
            (yyvsp[-8].str), (yyvsp[-6].str), msg
        );
        (yyval.str) = strdup(buffer);
    }
#line 1474 "form.tab.c"
    break;

  case 24: /* validate_block: %empty  */
#line 272 "form.y"
                  { (yyval.str) = strdup(""); }
#line 1480 "form.tab.c"
    break;

  case 25: /* option_list: STRING  */
#line 277 "form.y"
           { (yyval.str) = (yyvsp[0].str); }
#line 1486 "form.tab.c"
    break;

  case 26: /* option_list: option_list COMMA STRING  */
#line 278 "form.y"
                               {
        char* temp = concat((yyvsp[-2].str), ",");
        (yyval.str) = concat(temp, (yyvsp[0].str));
        free(temp);
    }
#line 1496 "form.tab.c"
    break;


#line 1500 "form.tab.c"

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

#line 285 "form.y"


//Error Handler
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

int main() {
    return yyparse();
}
