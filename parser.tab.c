/* A Bison parser, made by GNU Bison 3.7.6.  */

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
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

//set to 1 if in debug mode	
	#define DEBUG 0

//maximum amount of allowed structs
	#define MAX_STRUCTS 30

//maximum length of a struct/function name
//if you change this, make sure there is enough space in yylval array of characters
	#define MAX_NAME 50

//maximum number of variables defined in a function/struct/main (including arguments)
	#define MAX_NUM_of_VARS 50

//maximum number of arguments in a function
	#define MAX_ARGS 10

//maximum number of allowed scopes (function, main)
	#define MAX_SCOPE 20
    int yylex();
    void yyerror(const char *s);

//my functions

	//checks if i is grater that zero
	void isGTZ(int i);

	//checks if str has been defined as struct
	int isStruct(char str[MAX_NAME]);

	//check if str is a valid type for a variable
	int isVartype(char str[MAX_NAME]);

	//adds the name (str) of a struct to the global array (struct_names)
	void addStruct_name(char* str);

	//used for checking if a var is declaired (if it is return 1 else return 0)
	//if error_msg not used, pass ""
	int is_declaired(char* var, char* error_msg);

	//used for checking if a func is declaired (if it is return 1 else return 0)
	//if error_msg not used, pass ""
	int is_function(char* func, char* error_msg);


	void add_in_cur_scope(char* var);

	//called on function definition. It will save the type (ex. INT) of the parameters.
	//TODO: use this to check if arguments are of correct type
	void add_type_of_arg(char* type);

	//Checks if the call of a function has the right amount of arguments (using arg_cnter)
	//if not, returns an error
	int is_argument_count_correct(char* func_name);

	//GLobal array to save the struct names in 
	char struct_names[MAX_STRUCTS][MAX_NAME];

	//No idea, may be redundant
	char strct[MAX_NAME];

	//Used for finding the correct position to add a new struct name in struct_names array
	//Maybe it is a good idea to update some functions not to use this!
	int pos = 0;

	//may be redundant
	char cur_scope[MAX_NAME];

	//Organize each scope in a struct
	struct scope{
		//name of function not more than 50 char
		char scope[MAX_NAME];
		//max 50 variables (including arguments) allowed in a scope
		char vars[MAX_NUM_of_VARS][MAX_NAME];
		//counter of arguments
		int argc;
		//no more than 10 arguments allowed (each arg type not more than 50 char)
		char argt[MAX_ARGS][MAX_NAME];
	};

	//An array of structs. Maybe have the size be a define
	struct scope arr_of_scopes[MAX_SCOPE];

	//maybe update functions to find the cur_scope and delete this
	int scope_cnt = 0;

	//argument counter to check if function called with the right amount of args
	int arg_cnter = 0;

#line 165 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROG = 3,                       /* PROG  */
  YYSYMBOL_STRUCT = 4,                     /* STRUCT  */
  YYSYMBOL_ESTRUCT = 5,                    /* ESTRUCT  */
  YYSYMBOL_TYPEDEF = 6,                    /* TYPEDEF  */
  YYSYMBOL_FUNC = 7,                       /* FUNC  */
  YYSYMBOL_ENDFUNC = 8,                    /* ENDFUNC  */
  YYSYMBOL_SMAIN = 9,                      /* SMAIN  */
  YYSYMBOL_EMAIN = 10,                     /* EMAIN  */
  YYSYMBOL_VARS = 11,                      /* VARS  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_INT = 13,                       /* INT  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_EWHILE = 15,                    /* EWHILE  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_TO = 17,                        /* TO  */
  YYSYMBOL_STEP = 18,                      /* STEP  */
  YYSYMBOL_EFOR = 19,                      /* EFOR  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_THEN = 21,                      /* THEN  */
  YYSYMBOL_ELSEIF = 22,                    /* ELSEIF  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_ENDIF = 24,                     /* ENDIF  */
  YYSYMBOL_SWITCH = 25,                    /* SWITCH  */
  YYSYMBOL_CASE = 26,                      /* CASE  */
  YYSYMBOL_DEFAULT = 27,                   /* DEFAULT  */
  YYSYMBOL_ESWITCH = 28,                   /* ESWITCH  */
  YYSYMBOL_PRINT = 29,                     /* PRINT  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_EOL = 31,                       /* EOL  */
  YYSYMBOL_RET = 32,                       /* RET  */
  YYSYMBOL_COMMENT = 33,                   /* COMMENT  */
  YYSYMBOL_OP = 34,                        /* OP  */
  YYSYMBOL_CP = 35,                        /* CP  */
  YYSYMBOL_OB = 36,                        /* OB  */
  YYSYMBOL_CB = 37,                        /* CB  */
  YYSYMBOL_ADD = 38,                       /* ADD  */
  YYSYMBOL_SUB = 39,                       /* SUB  */
  YYSYMBOL_MUL = 40,                       /* MUL  */
  YYSYMBOL_DIV = 41,                       /* DIV  */
  YYSYMBOL_POW = 42,                       /* POW  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_SEMIC = 44,                     /* SEMIC  */
  YYSYMBOL_EQS = 45,                       /* EQS  */
  YYSYMBOL_COMP_OPER = 46,                 /* COMP_OPER  */
  YYSYMBOL_LOG_OPER = 47,                  /* LOG_OPER  */
  YYSYMBOL_COLON_EQ = 48,                  /* COLON_EQ  */
  YYSYMBOL_COLON = 49,                     /* COLON  */
  YYSYMBOL_POS_NUM = 50,                   /* POS_NUM  */
  YYSYMBOL_BOOL = 51,                      /* BOOL  */
  YYSYMBOL_ALPHA = 52,                     /* ALPHA  */
  YYSYMBOL_UNDER = 53,                     /* UNDER  */
  YYSYMBOL_ANU = 54,                       /* ANU  */
  YYSYMBOL_SAU = 55,                       /* SAU  */
  YYSYMBOL_STR = 56,                       /* STR  */
  YYSYMBOL_FLOAT = 57,                     /* FLOAT  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_doc = 59,                       /* doc  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_wrapper = 61,                   /* wrapper  */
  YYSYMBOL_end_wrapper = 62,               /* end_wrapper  */
  YYSYMBOL_pname = 63,                     /* pname  */
  YYSYMBOL_fname = 64,                     /* fname  */
  YYSYMBOL_vname = 65,                     /* vname  */
  YYSYMBOL_vartype = 66,                   /* vartype  */
  YYSYMBOL_arr = 67,                       /* arr  */
  YYSYMBOL_num = 68,                       /* num  */
  YYSYMBOL_num_oper = 69,                  /* num_oper  */
  YYSYMBOL_struct_wrapper = 70,            /* struct_wrapper  */
  YYSYMBOL_71_2 = 71,                      /* $@2  */
  YYSYMBOL_struct = 72,                    /* struct  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_struct_vars = 74,               /* struct_vars  */
  YYSYMBOL_append_struct_vars = 75,        /* append_struct_vars  */
  YYSYMBOL_func = 76,                      /* func  */
  YYSYMBOL_77_4 = 77,                      /* $@4  */
  YYSYMBOL_main = 78,                      /* main  */
  YYSYMBOL_79_5 = 79,                      /* $@5  */
  YYSYMBOL_func_param = 80,                /* func_param  */
  YYSYMBOL_81_6 = 81,                      /* $@6  */
  YYSYMBOL_append_func_param = 82,         /* append_func_param  */
  YYSYMBOL_func_arg = 83,                  /* func_arg  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_85_8 = 85,                      /* $@8  */
  YYSYMBOL_86_9 = 86,                      /* $@9  */
  YYSYMBOL_87_10 = 87,                     /* $@10  */
  YYSYMBOL_append_func_arg = 88,           /* append_func_arg  */
  YYSYMBOL_func_body = 89,                 /* func_body  */
  YYSYMBOL_func_var = 90,                  /* func_var  */
  YYSYMBOL_91_11 = 91,                     /* $@11  */
  YYSYMBOL_append_func_vars = 92,          /* append_func_vars  */
  YYSYMBOL_return_type = 93,               /* return_type  */
  YYSYMBOL_commands = 94,                  /* commands  */
  YYSYMBOL_extend_commands = 95,           /* extend_commands  */
  YYSYMBOL_assign = 96,                    /* assign  */
  YYSYMBOL_97_12 = 97,                     /* $@12  */
  YYSYMBOL_rvalue = 98,                    /* rvalue  */
  YYSYMBOL_99_13 = 99,                     /* $@13  */
  YYSYMBOL_100_14 = 100,                   /* $@14  */
  YYSYMBOL_101_15 = 101,                   /* $@15  */
  YYSYMBOL_append_rvalue = 102,            /* append_rvalue  */
  YYSYMBOL_loop = 103,                     /* loop  */
  YYSYMBOL_while = 104,                    /* while  */
  YYSYMBOL_cond = 105,                     /* cond  */
  YYSYMBOL_for = 106,                      /* for  */
  YYSYMBOL_flow_control = 107,             /* flow_control  */
  YYSYMBOL_if = 108,                       /* if  */
  YYSYMBOL_else = 109,                     /* else  */
  YYSYMBOL_switch = 110,                   /* switch  */
  YYSYMBOL_case = 111,                     /* case  */
  YYSYMBOL_print = 112,                    /* print  */
  YYSYMBOL_print_var = 113                 /* print_var  */
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
typedef yytype_int16 yy_state_t;

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

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  262

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
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   154,   159,   164,   165,   168,   169,   172,
     173,   174,   175,   176,   179,   180,   181,   184,   185,   186,
     189,   190,   191,   192,   193,   197,   198,   201,   202,   204,
     205,   206,   207,   208,   213,   214,   216,   215,   224,   223,
     229,   230,   232,   233,   234,   241,   243,   242,   255,   254,
     262,   264,   263,   271,   272,   276,   277,   277,   278,   278,
     279,   279,   280,   280,   282,   283,   285,   286,   289,   288,
     297,   298,   299,   300,   302,   303,   304,   311,   312,   313,
     314,   315,   316,   318,   319,   320,   321,   322,   323,   324,
     327,   326,   333,   332,   337,   338,   340,   345,   339,   350,
     351,   355,   356,   358,   360,   361,   362,   364,   369,   370,
     372,   374,   375,   376,   378,   380,   381,   382,   386,   388,
     389
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "PROG", "STRUCT", "ESTRUCT",
  "TYPEDEF", "FUNC", "ENDFUNC", "SMAIN", "EMAIN", "VARS", "CHAR", "INT",
  "WHILE", "EWHILE", "FOR", "TO", "STEP", "EFOR", "IF", "THEN", "ELSEIF",
  "ELSE", "ENDIF", "SWITCH", "CASE", "DEFAULT", "ESWITCH", "PRINT",
  "BREAK", "EOL", "RET", "COMMENT", "OP", "CP", "OB", "CB", "ADD", "SUB",
  "MUL", "DIV", "POW", "COMMA", "SEMIC", "EQS", "COMP_OPER", "LOG_OPER",
  "COLON_EQ", "COLON", "POS_NUM", "BOOL", "ALPHA", "UNDER", "ANU", "SAU",
  "STR", "FLOAT", "$accept", "doc", "$@1", "wrapper", "end_wrapper",
  "pname", "fname", "vname", "vartype", "arr", "num", "num_oper",
  "struct_wrapper", "$@2", "struct", "$@3", "struct_vars",
  "append_struct_vars", "func", "$@4", "main", "$@5", "func_param", "$@6",
  "append_func_param", "func_arg", "$@7", "$@8", "$@9", "$@10",
  "append_func_arg", "func_body", "func_var", "$@11", "append_func_vars",
  "return_type", "commands", "extend_commands", "assign", "$@12", "rvalue",
  "$@13", "$@14", "$@15", "append_rvalue", "loop", "while", "cond", "for",
  "flow_control", "if", "else", "switch", "case", "print", "print_var", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
};
#endif

#define YYPACT_NINF (-210)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-20)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      71,    45,  -210,  -210,     2,    71,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,    61,    27,   -46,     7,  -210,  -210,
    -210,  -210,  -210,    20,   -46,   125,    61,    61,    37,    30,
    -210,  -210,    43,    27,   -46,  -210,  -210,  -210,  -210,    61,
     144,  -210,  -210,    13,   239,  -210,  -210,  -210,  -210,  -210,
      36,   -46,  -210,    61,    36,    61,    24,   -46,   210,    34,
      59,   338,  -210,    93,  -210,   338,   338,  -210,  -210,   338,
    -210,  -210,   338,   -46,    35,    27,   -46,    78,    36,   210,
      87,   210,    69,  -210,   103,   111,   112,  -210,  -210,   124,
     -10,   129,   210,   102,  -210,   108,    61,  -210,  -210,  -210,
    -210,    35,   -18,    66,  -210,  -210,    61,   -46,  -210,   133,
     -18,   134,  -210,   136,   124,  -210,  -210,  -210,  -210,  -210,
     210,  -210,   210,   210,    61,   137,   128,   210,  -210,  -210,
      66,   143,   -46,   144,  -210,    35,   239,  -210,    61,   156,
     124,   289,  -210,  -210,  -210,  -210,   304,    61,   -46,   146,
     139,  -210,    35,    35,    36,  -210,   142,   155,    35,   304,
     -18,  -210,  -210,  -210,  -210,  -210,   157,   147,   304,   100,
     304,   304,   304,   304,   338,   128,   151,  -210,  -210,    66,
      36,  -210,   234,    97,   175,   180,    35,    35,    35,   158,
    -210,   304,  -210,    61,    61,   183,  -210,  -210,  -210,  -210,
      51,  -210,  -210,  -210,  -210,  -210,  -210,  -210,    61,   -46,
     294,  -210,  -210,   -18,   158,   158,   158,   289,  -210,   124,
    -210,   304,   304,  -210,   170,   160,  -210,  -210,   204,    35,
     168,   169,   171,   294,  -210,  -210,    61,  -210,  -210,  -210,
    -210,  -210,   100,  -210,   210,   304,    61,    97,  -210,   304,
    -210,   182,   190,  -210,  -210,   202,   173,  -210,  -210,   304,
      51,  -210
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     6,     5,     0,     0,    10,     9,    11,    13,
      12,     2,     1,     4,     0,    34,     0,     0,    45,    17,
      18,    19,    38,     0,     0,     0,     0,     0,     0,     0,
      48,     3,     0,    34,     0,    14,    15,    16,    46,     0,
       0,    35,    36,     0,    77,    20,    21,    23,    22,    24,
       0,     0,    39,     0,    50,     0,     0,     0,     0,     0,
       0,    77,    90,     0,    67,    77,    77,   101,   102,    77,
     108,   109,    77,     0,    25,    34,     0,     0,     0,     0,
       0,     0,     0,    27,    17,    18,    19,    96,    92,    99,
     104,     0,     0,     0,    78,     0,     7,    79,    80,    81,
      82,    25,     0,     0,    37,    51,     0,     0,    66,     0,
       0,     0,    28,     0,    99,    29,    30,    31,    32,    33,
       0,    94,     0,     0,     0,     0,   119,     0,     8,    49,
       0,     0,     0,     0,    40,    25,    77,    68,     0,     0,
      99,    55,    93,   100,   105,   106,    83,     0,     0,     0,
       0,    41,    25,    25,    42,    43,    53,     0,    25,    83,
       0,    95,    56,    60,    62,    58,     0,     0,    83,   111,
      83,    83,    83,    83,    77,   119,     0,    91,    26,     0,
      50,    52,     0,     0,     0,     0,    25,    25,    25,    64,
      97,    83,    84,     0,     0,     0,    85,    86,    87,    88,
       0,   120,   118,    44,    54,    76,    74,    75,     0,     0,
      77,    69,   103,     0,    64,    64,    64,    55,    59,    99,
      89,    83,    83,   110,     0,     0,   117,   114,     0,    25,
      23,    22,    24,    77,    70,    72,     0,    57,    61,    63,
      65,    98,   111,   113,     0,    83,     0,     0,    71,    83,
     112,     0,     0,    47,    73,     0,     0,   116,   107,    83,
       0,   115
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,   218,  -210,     0,  -210,  -210,   201,    -6,     6,    53,
      18,  -210,   -11,  -210,   208,  -210,   101,  -122,  -210,  -210,
    -210,  -210,    57,  -210,  -210,    25,  -210,  -210,  -210,  -210,
     -85,   107,  -209,  -210,    -2,  -210,   -49,    56,   -31,  -210,
     -77,  -210,  -210,  -210,  -111,    15,  -210,   -60,  -210,    46,
    -210,     9,  -210,    -8,    83,    79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,    14,   168,   129,    11,    87,    62,   107,   103,
      89,   120,    18,    53,    23,    26,    52,   134,    25,    43,
      31,    39,    77,   135,   181,   166,   186,   189,   187,   188,
     218,    63,   108,   158,   211,   208,    64,   169,   170,    95,
      90,   114,   113,   219,   121,   171,    67,    91,    68,   172,
      70,   195,    71,   227,   173,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,   234,    12,   142,   111,     5,    19,    20,   151,    21,
      22,    24,    94,    65,    15,   125,    97,    98,    22,   109,
      99,    82,    41,   100,   248,    27,    32,    33,    42,   161,
      65,    16,    83,    17,    65,    65,   122,   123,    65,    44,
      50,    65,    34,   143,    61,    74,    51,    54,    45,    46,
     150,    80,    88,    75,    40,    78,    73,   203,    79,    66,
      76,    61,   144,   145,   104,    61,    61,   101,    92,    61,
     105,   102,    61,    88,     1,    88,    66,   224,   225,   226,
      66,    66,    35,    36,    66,    37,    88,    66,    47,    48,
      69,    49,     2,    93,     3,     6,   128,     7,     8,     9,
      10,   137,     2,    96,     3,    65,   136,    69,   241,   132,
     133,    69,    69,   106,    88,    69,    88,    88,    69,   112,
     131,    88,   193,   194,   146,   200,   153,    72,   139,   237,
     238,   239,    29,   154,    30,   110,    61,   -14,   159,    51,
     209,   210,   175,    65,    72,   -15,   -16,   174,    72,    72,
     124,    66,    72,   127,   130,    72,    45,    46,   126,   165,
      73,   235,   115,   116,   117,   118,   119,   251,   138,   140,
     141,   148,   147,   160,    61,     2,   206,     3,   185,    65,
     152,   176,    69,   177,    94,   180,    76,   182,   156,    66,
     212,   191,   190,   221,   222,   202,    47,    48,   213,    49,
     207,   217,    65,   229,   244,   178,   179,   223,   228,   245,
     233,   183,   246,   -17,   -18,   184,   -19,   256,   257,    72,
      69,   258,   259,    13,   192,    66,   196,   197,   198,   199,
      38,   236,    28,    61,   155,   165,   249,   204,    88,   214,
     215,   216,   240,   157,    81,   254,   253,   220,    66,    82,
      55,   250,   261,    56,   201,    57,    69,    72,     0,    58,
      83,     0,    84,    85,    59,    86,     0,     0,    60,     0,
       2,     0,     3,    82,     0,     0,     0,   242,   243,    69,
       0,     0,   247,     0,    83,   205,    19,    20,     0,    21,
       0,    19,    20,    72,    21,     0,     0,     0,     0,     0,
       0,   252,     0,     0,     0,   255,    45,    46,    56,     0,
      57,     0,     0,     0,    58,   260,    72,     0,    56,    59,
      57,     0,     0,    60,    58,     2,     0,     3,    82,    59,
       0,     0,     0,    60,   167,     2,     0,     3,     0,    83,
       0,   162,   163,     0,   164,     0,   230,   231,     0,   232,
       0,     0,    56,     0,    57,     0,    19,    20,    58,    21,
       0,     0,     0,    59,     0,     0,     0,    60,     0,     2,
       0,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,    21
};

static const yytype_int16 yycheck[] =
{
       0,   210,     0,   114,    81,     5,    52,    53,   130,    55,
      16,     4,    61,    44,    14,    92,    65,    66,    24,    79,
      69,    39,    33,    72,   233,     5,    26,    27,    34,   140,
      61,     4,    50,     6,    65,    66,    46,    47,    69,    39,
      40,    72,     5,   120,    44,    51,    40,    34,    12,    13,
     127,    57,    58,    53,    11,    55,    50,   179,    34,    44,
      54,    61,   122,   123,    75,    65,    66,    73,    34,    69,
      76,    36,    72,    79,     3,    81,    61,    26,    27,    28,
      65,    66,    52,    53,    69,    55,    92,    72,    52,    53,
      44,    55,    31,    34,    33,    50,    96,    52,    53,    54,
      55,   107,    31,    10,    33,   136,   106,    61,   219,    43,
      44,    65,    66,    35,   120,    69,   122,   123,    72,    50,
     102,   127,    22,    23,   124,   174,   132,    44,   110,   214,
     215,   216,     7,   133,     9,    48,   136,    34,   138,   133,
      43,    44,   148,   174,    61,    34,    34,   147,    65,    66,
      21,   136,    69,    45,   101,    72,    12,    13,    56,   141,
     154,   210,    38,    39,    40,    41,    42,   244,    35,    35,
      34,    43,    35,    17,   174,    31,   182,    33,   160,   210,
      37,    35,   136,    44,   233,    43,   180,    32,   135,   174,
      15,    44,    35,   193,   194,    44,    52,    53,    18,    55,
     182,    43,   233,   209,    34,   152,   153,    24,   208,    49,
     210,   158,     8,    45,    45,   159,    45,    35,    28,   136,
     174,    19,    49,     5,   168,   210,   170,   171,   172,   173,
      29,   213,    24,   233,   133,   217,   236,   180,   244,   186,
     187,   188,   217,   136,    34,   247,   246,   191,   233,    39,
      11,   242,   260,    14,   175,    16,   210,   174,    -1,    20,
      50,    -1,    52,    53,    25,    55,    -1,    -1,    29,    -1,
      31,    -1,    33,    39,    -1,    -1,    -1,   221,   222,   233,
      -1,    -1,   229,    -1,    50,    51,    52,    53,    -1,    55,
      -1,    52,    53,   210,    55,    -1,    -1,    -1,    -1,    -1,
      -1,   245,    -1,    -1,    -1,   249,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    20,   259,   233,    -1,    14,    25,
      16,    -1,    -1,    29,    20,    31,    -1,    33,    39,    25,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    -1,    50,
      -1,    52,    53,    -1,    55,    -1,    52,    53,    -1,    55,
      -1,    -1,    14,    -1,    16,    -1,    52,    53,    20,    55,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    31,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    31,    33,    59,    61,    50,    52,    53,    54,
      55,    63,     0,    59,    60,    61,     4,     6,    70,    52,
      53,    55,    65,    72,     4,    76,    73,     5,    72,     7,
       9,    78,    61,    61,     5,    52,    53,    55,    64,    79,
      11,    70,    65,    77,    61,    12,    13,    52,    53,    55,
      61,    66,    74,    71,    34,    11,    14,    16,    20,    25,
      29,    61,    65,    89,    94,    96,   103,   104,   106,   107,
     108,   110,   112,    66,    65,    61,    66,    80,    61,    34,
      65,    34,    39,    50,    52,    53,    55,    64,    65,    68,
      98,   105,    34,    34,    94,    97,    10,    94,    94,    94,
      94,    65,    36,    67,    70,    65,    35,    66,    90,   105,
      48,    98,    50,   100,    99,    38,    39,    40,    41,    42,
      69,   102,    46,    47,    21,    98,    56,    45,    61,    62,
      67,    68,    43,    44,    75,    81,    61,    65,    35,    68,
      35,    34,   102,    98,   105,   105,    61,    35,    43,   113,
      98,    75,    37,    65,    61,    74,    67,    89,    91,    61,
      17,   102,    52,    53,    55,    68,    83,    30,    61,    95,
      96,   103,   107,   112,    61,    65,    35,    44,    67,    67,
      43,    82,    32,    67,    95,    68,    84,    86,    87,    85,
      35,    44,    95,    22,    23,   109,    95,    95,    95,    95,
      94,   113,    44,    75,    80,    51,    65,    68,    93,    43,
      44,    92,    15,    18,    67,    67,    67,    43,    88,   101,
      95,    61,    61,    24,    26,    27,    28,   111,    61,    65,
      52,    53,    55,    61,    90,    94,    68,    88,    88,    88,
      83,   102,    95,    95,    34,    49,     8,    67,    90,    61,
     109,    98,    95,    61,    92,    95,    35,    28,    19,    49,
      95,   111
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    60,    59,    59,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    69,    70,    70,    71,    70,    73,    72,
      74,    74,    75,    75,    75,    76,    77,    76,    79,    78,
      80,    81,    80,    82,    82,    83,    84,    83,    85,    83,
      86,    83,    87,    83,    88,    88,    89,    89,    91,    90,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      97,    96,    99,    98,    98,    98,   100,   101,    98,   102,
     102,   103,   103,   104,   105,   105,   105,   106,   107,   107,
     108,   109,   109,   109,   110,   111,   111,   111,   112,   113,
     113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     2,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     1,     2,     1,
       1,     1,     1,     1,     0,     5,     0,     8,     0,     5,
       4,     5,     2,     2,     4,     0,     0,    14,     0,     6,
       0,     0,     5,     0,     2,     0,     0,     4,     0,     3,
       0,     4,     0,     4,     0,     2,     3,     1,     0,     5,
       2,     3,     2,     4,     1,     1,     1,     0,     2,     2,
       2,     2,     2,     0,     2,     2,     2,     2,     2,     3,
       0,     5,     0,     3,     2,     4,     0,     0,     7,     0,
       2,     1,     1,     7,     1,     3,     3,    11,     1,     1,
       7,     0,     4,     3,     7,     7,     4,     1,     6,     0,
       3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
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
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
#line 155 "parser.y"
        {
		strcpy(cur_scope, "global");
	}
#line 1705 "parser.tab.c"
    break;

  case 26: /* arr: OB num CB arr  */
#line 198 "parser.y"
                        { isGTZ((yyvsp[-2].ival)); }
#line 1711 "parser.tab.c"
    break;

  case 28: /* num: SUB POS_NUM  */
#line 202 "parser.y"
                      { (yyval.ival) = -(yyvsp[0].ival); }
#line 1717 "parser.tab.c"
    break;

  case 36: /* $@2: %empty  */
#line 216 "parser.y"
        {										// there is are shift/reduce conflicts, since varable names have
											// the same tokens as the struct name!!!
//Σκεψου δηλαδή: Όταν δει ; και έπειτα προαιρετικά αλλαγη γραμμής, δεν ξέρει αν το επόμενο token είναι vname ή struct name
		addStruct_name((yyvsp[0].str));
	}
#line 1727 "parser.tab.c"
    break;

  case 38: /* $@3: %empty  */
#line 224 "parser.y"
        {
		addStruct_name((yyvsp[0].str)); //mid-rule in order to add the struct name to the array and be able to use it as a valid 
	}
#line 1735 "parser.tab.c"
    break;

  case 40: /* struct_vars: vartype vname arr append_struct_vars  */
#line 229 "parser.y"
                                                  { isVartype((yyvsp[-3].str)); }
#line 1741 "parser.tab.c"
    break;

  case 41: /* struct_vars: wrapper vartype vname arr append_struct_vars  */
#line 230 "parser.y"
                                                       { isVartype((yyvsp[-3].str)); }
#line 1747 "parser.tab.c"
    break;

  case 46: /* $@4: %empty  */
#line 243 "parser.y"
        {
		if(is_function((yyvsp[0].str),"")){
			yyerror("Function already declaired!");
		}
		arr_of_scopes[scope_cnt].argc = 0;
		strcpy(cur_scope, (yyvsp[0].str)); //TODO also save the amount of arguments!!
		strcpy(arr_of_scopes[scope_cnt].scope, (yyvsp[0].str));
		scope_cnt++;
	}
#line 1761 "parser.tab.c"
    break;

  case 48: /* $@5: %empty  */
#line 255 "parser.y"
        {
		strcpy(cur_scope, "main");
		strcpy(arr_of_scopes[scope_cnt].scope, "main");
		scope_cnt++;
	}
#line 1771 "parser.tab.c"
    break;

  case 51: /* $@6: %empty  */
#line 264 "parser.y"
        {
		add_type_of_arg((yyvsp[-1].str)); //this is not being checked on func call
		arr_of_scopes[scope_cnt-1].argc++;
		add_in_cur_scope((yyvsp[0].str));
	}
#line 1781 "parser.tab.c"
    break;

  case 52: /* func_param: vartype vname $@6 arr append_func_param  */
#line 269 "parser.y"
                              { isVartype((yyvsp[-4].str)); }
#line 1787 "parser.tab.c"
    break;

  case 56: /* $@7: %empty  */
#line 277 "parser.y"
                {arg_cnter++; is_declaired((yyvsp[0].str), "Variable not declaired in this scope!");}
#line 1793 "parser.tab.c"
    break;

  case 58: /* $@8: %empty  */
#line 278 "parser.y"
              {arg_cnter++;}
#line 1799 "parser.tab.c"
    break;

  case 60: /* $@9: %empty  */
#line 279 "parser.y"
                {arg_cnter++; is_declaired((yyvsp[0].str), "Variable not declaired in this scope!");}
#line 1805 "parser.tab.c"
    break;

  case 62: /* $@10: %empty  */
#line 280 "parser.y"
              {arg_cnter++; is_declaired((yyvsp[0].str), "Variable not declaired in this scope!");}
#line 1811 "parser.tab.c"
    break;

  case 68: /* $@11: %empty  */
#line 289 "parser.y"
        {
		if(is_declaired((yyvsp[0].str), "")){
			yyerror("There is already a variable with that name!");
		}
		add_in_cur_scope((yyvsp[0].str));
	}
#line 1822 "parser.tab.c"
    break;

  case 69: /* func_var: vartype vname $@11 arr append_func_vars  */
#line 295 "parser.y"
                                 { isVartype((yyvsp[-4].str)); }
#line 1828 "parser.tab.c"
    break;

  case 74: /* return_type: vname  */
#line 302 "parser.y"
                   { is_declaired((yyvsp[0].str), "Variable is not declaired in this scope!"); }
#line 1834 "parser.tab.c"
    break;

  case 90: /* $@12: %empty  */
#line 327 "parser.y"
        {
		is_declaired((yyvsp[0].str), "Variable is not declaired in this scope!");
	}
#line 1842 "parser.tab.c"
    break;

  case 92: /* $@13: %empty  */
#line 333 "parser.y"
        {
		is_declaired((yyvsp[0].str), "Variable is not declaired in this scope!");
	}
#line 1850 "parser.tab.c"
    break;

  case 96: /* $@14: %empty  */
#line 340 "parser.y"
        {
		is_function((yyvsp[0].str),"Function is not declaired!");
		arg_cnter = 0;
	}
#line 1859 "parser.tab.c"
    break;

  case 97: /* $@15: %empty  */
#line 345 "parser.y"
        {
		is_argument_count_correct((yyvsp[-4].str));
	}
#line 1867 "parser.tab.c"
    break;


#line 1871 "parser.tab.c"

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
          goto yyexhaustedlab;
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 395 "parser.y"


//code from http://aquamentus.com/tut_lexyacc.html
// stuff from lex that bison needs to know about:
//count lines, so you may report on error
extern int line;
extern int yylex();
extern int yyparse();
extern FILE *yyin;

int main(int argc, char **argv){
	int i;

	// open a file handle to a particular file:
	if(argc != 2){
		printf("First argument must be the code file\n");
		exit(1);
	}

	FILE *codefile = fopen(argv[1], "r");
	if (!codefile) {
		printf("%s did not open!\n",argv[2]);
		exit(1);
	}

	//set lex to read from it instead of defaulting to STDIN:
	yyin = codefile;

	//parse through the input file until there is no more:
	do {
		yyparse();
	} while (!feof(yyin));
	printf("The program compiled with no errors!\n");
#if DEBUG
	printf("Scope: %s\n", cur_scope);
	for (int i = 0; i < scope_cnt; i++){
		printf("arr_of_scopes[%d] = %s\n", i, arr_of_scopes[i].scope);
		int j = 0;
		while(strcmp(arr_of_scopes[i].vars[j],"")){
			printf("\t %s,", arr_of_scopes[i].vars[j]);
			j++;
		}
		printf("\n\t %d arguments with types: \n", arr_of_scopes[i].argc);
		for(j = 0; j < arr_of_scopes[i].argc; j++){
			printf("\t %s\n", arr_of_scopes[i].argt[j]);
		}
	}

	for (int i = 0; i < MAX_STRUCTS; i++){
		if(!strcmp(struct_names[i],"")){
			break;
		}
		printf("struct_names[%d] = %s\n",i,struct_names[i]);
	}
#endif
}

void yyerror(const char *s){ //In OReilly chapter one there is no const
    fprintf(stderr, "error in line %d: %s\n", line, s);
	exit(1);
}

//TODO: when a negative val (ex -2) is given as the size of an array,
//the error created is because of the -, as a NUM_OPER token
//a fix could be extending the NUM declaration, so it also recognizes negative numbers
//Keep in mind that in flex NUM should be before NUM_OPERATOR, in order for this to work
void isGTZ(int i){
	if(i <= 0){
		yyerror("Array size must be greater than 0\n");
	} 
}

//updates the array of structs, so the user may later define a var of type struct
void addStruct_name(char* str){
	int i;
	strcpy(struct_names[pos],str);
	pos++;
}

//Checks if variable type is valid, either INTEGER or CHAR tokens or a struct that has been previously defined
int isVartype(char* str){
	int i;
	if(!strcmp(str, "INTEGER") || !strcmp(str, "CHAR")){
		return 1;
	}
	for (i = 0; i < MAX_STRUCTS; i++){
		if(!strcmp(str, "")){
			break; //avoid a few extra iterations
		}
		else if(!strcmp(str, struct_names[i])){
			return 1;
		}
	}
	char *msg = strcat(str," not a var type!\n");
	yyerror(msg);
	return 0;
}

//Adds var in the struct (named scope),
//that is in (scope_cnt-1) position of the arr_of_scopes,
//in field (named vars)
void add_in_cur_scope(char* var){
	int i=0;
	while(strcmp(arr_of_scopes[scope_cnt-1].vars[i],"")){ //strcmp: if match returns 0
		i++;
		if(i==MAX_NUM_of_VARS){
			yyerror("Exceeded the number of allowed variables!\n");
		}
	}
	strcpy(arr_of_scopes[scope_cnt-1].vars[i], var);
}

//Adds type in the struct (named scope),
//that is in (scope_cnt-1) position of the arr_of_scopes,
//in field (argt)
//I may use this later in order to check if a function call is correct
//(has the correct arguments)
//Or even if it has been previously defined
void add_type_of_arg(char* type){
	int i = 0;
	while(strcmp(arr_of_scopes[scope_cnt-1].vars[i],"")){ //strcmp: if match returns 0
		i++;
		if(i==MAX_ARGS){
			yyerror("Exceeded the number of allowed arguments!\n");
		}
	}
	strcpy(arr_of_scopes[scope_cnt-1].argt[i], type);
}

//Check if var is in the cur scope (thus it is declaired)
//Second argument = "" will not display an error message
int is_declaired(char* var, char* error_msg){
	int i = 0;
	while (strcmp(arr_of_scopes[scope_cnt-1].vars[i], "")){
		if(!strcmp(arr_of_scopes[scope_cnt-1].vars[i], var)){
			return 1;
		}
		i++;
	}
	if(strcmp(error_msg,"")){
		yyerror(error_msg);
	}
	return 0;
}

//Check if function is declaired
//Second argument = "" will not display an error message
int is_function(char* func, char* error_msg){
	int i = 0;
	while (strcmp(arr_of_scopes[i].scope, "")){
		if(!strcmp(arr_of_scopes[i].scope, func)){
			return 1;
		}
		i++;
	}
	if(strcmp(error_msg,"")){
		yyerror(error_msg);
	}
	return 0;
}

int is_argument_count_correct(char* func_name){
	int i;
	while(strcmp(func_name, arr_of_scopes[i].scope)){
		i++;
	}
	if(arr_of_scopes[i].argc == arg_cnter){
		return 1;
	}
	else if(arg_cnter > arr_of_scopes[i].argc){
		yyerror("Too many arguments!");
	}
	else{
		yyerror("Not enough arguments!");
	}
}
