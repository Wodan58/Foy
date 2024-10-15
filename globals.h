/*
    module  : globals.h
    version : 1.21
    date    : 10/11/24
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
#include <setjmp.h>
#include <math.h>
#include <time.h>

#ifdef _MSC_VER
#define WIN32_LEAN_AND_MEAN
#include <windows.h>		/* pollute name space as much as possible */
#include <io.h>			/* also import deprecated POSIX names */
#pragma warning(disable: 4244 4267 4996)
#define kh_packed		/* forget about __attribute__ ((packed)) */
#else
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#endif

#define USE_KHASHL

#ifdef _MSC_VER
#include "../joy1/gc-8.2.8/include/gc.h"
#else
#include <gc.h>			/* system installed BDW */
#endif
#include "kvec.h"
#include "khashl.h"

/* configure			*/
#define SHELLESCAPE	'$'
#define INPSTACKMAX	10
#define INPLINEMAX	255
#define BUFFERMAX	80
#define HELPLINEMAX	72
#define MAXNUM		40
#define FILENAMEMAX	14
#define DISPLAYMAX	10	/* nesting in HIDE & MODULE */
#define INIECHOFLAG	0
#define INIAUTOPUT	1
#define INITRACEGC	1
#define INIUNDEFERROR	0
#define INIWARNING	0

/* installation dependent	*/
#define SETSIZE (int)(CHAR_BIT * sizeof(uint64_t))	/* from limits.h */
#define MAXINT_ INT64_MAX				/* from stdint.h */

typedef enum {
    ANYTYPE,
    DIP,
    WHILE,
    IFTE,
    LINREC,
    HELP,
    INFRA,
    UFLOAT,
    MUL,
    BFLOAT,
    FGET,
    FPUT,
    STRFTIME,
    FPUTCHARS,
    STRTOD,
    FOPEN,
    UNMKTIME,
    FREAD,
    LDEXP,
    STRTOL,
    FSEEK,
    TIMES,
    MAXMIN,
    PREDSUCC,
    PLUSMINUS,
    SIZE_,
    STEP,
    TAKE,
    CONCAT,
    ANDORXOR,
    NOT,
    PRIMREC,
    SMALL,
    BODY,
    INTERN,
    FORMAT,
    FORMATF,
    CONS,
    IN_,
    HAS,
    CASE,
    FIRST,
    OF,
    AT,
    DIV,
    REM,
    DIVIDE,
    FWRITE,
    ASSIGN,
#ifdef USE_MULTI_THREADS_JOY
    RECEIVE,
    SEND
#endif
} Params;

enum {
    ILLEGAL_,
    COPIED_,
    USR_,
    ANON_FUNCT_,
    BOOLEAN_,
    CHAR_,
    INTEGER_,
    SET_,
    STRING_,
    LIST_,
    FLOAT_,
    FILE_,
    BIGNUM_,
    USR_PRIME_,
    ANON_PRIME_,
    USR_STRING_,
    USR_LIST_,

    LIBRA,
    EQDEF,
    HIDE,
    IN__,
    MODULE_,
    PRIVATE,
    PUBLIC,
    CONST_
};

typedef enum {
    OK,
    IGNORE_OK,
    IGNORE_PUSH,
    IGNORE_POP,
    IMMEDIATE,
    POSTPONE
} Flags;

typedef enum {
    ABORT_NONE,
    ABORT_RETRY,
    ABORT_QUIT
} Abort;

typedef struct Env *pEnv;		/* global variables */
typedef void (*proc_t)(pEnv);		/* procedure */
typedef unsigned char Operator;		/* opcode / datatype */
typedef vector(struct Node) NodeList;	/* vector type */

typedef union {
    int64_t num;	/* USR, BOOLEAN, CHAR, INTEGER */
    proc_t proc;	/* ANON_FUNCT */
    uint64_t set;	/* SET */
    char *str;		/* STRING */
    NodeList *lis;	/* LIST */
    double dbl;		/* FLOAT */
    FILE *fil;		/* FILE */
    int ent;		/* SYMBOL */
} Types;

typedef struct Node {
    Types u;
    Operator op;
} Node;

typedef struct Token {
    Operator op;
    int x, y, pos;
    Types u;
} Token;

typedef struct Entry {
    char *name, is_user, flags, is_ok;
    union {
	NodeList *body;
	proc_t proc;
    } u;
} Entry;

KHASHL_MAP_INIT(KH_LOCAL, symtab_t, symtab, const char *, int, kh_hash_str,
		kh_eq_str)
KHASHL_MAP_INIT(KH_LOCAL, funtab_t, funtab, uint64_t, int, kh_hash_uint64,
		kh_eq_generic)

typedef struct Env {
    jmp_buf finclude;		/* return point in finclude */
    double calls;		/* statistics */
    double opers;
    double dbl;			/* numerics */
    int64_t num;
    char *str;			/* string */
    clock_t startclock;
    char **g_argv;		/* command line */
    char *homedir;		/* HOME or HOMEPATH */
    char *mod_name;		/* name of module */
    vector(char *) *pathnames;	/* pathnames to be searched when including */
    vector(char) *string;	/* value */
    vector(char) *pushback;	/* push back buffer */
    vector(Token) *tokens;	/* read ahead table */
    NodeList *code, *stack;	/* code and data area */
    vector(Entry) *symtab;	/* symbol table */
    symtab_t *hash;		/* hash tables that index the symbol table */
    funtab_t *prim;
    int hide_stack[DISPLAYMAX];
    struct {
	char *name;
	int hide;
    } module_stack[DISPLAYMAX];
    int g_argc;			/* command line */
    Operator sym;		/* symbol */
    unsigned char inlining;	/* flags */
    unsigned char postpone;
    unsigned char getting;
    unsigned char autoput;
    unsigned char autoput_set;
    unsigned char echoflag;
    unsigned char tracegc;
    unsigned char undeferror;
    unsigned char undeferror_set;
    unsigned char debugging;
    unsigned char ignore;
    unsigned char overwrite;
    unsigned char printing;
    unsigned char finclude_busy;
} Env;

/* arty.c */
int arity(pEnv env, NodeList *quot, int num);
/* main.c */
void abortexecution_(int num);
void dump(pEnv env);
void stats(pEnv env);
/* modl.c */
void savemod(int *hide, int *modl, int *hcnt);
void undomod(int hide, int modl, int hcnt);
void initmod(pEnv env, char *name);
void initpriv(pEnv env);
void stoppriv(void);
void exitpriv(void);
void exitmod(void);
char *classify(pEnv env, char *name);
int qualify(pEnv env, char *name);
/* otab.c */
int operindex(pEnv env, proc_t proc);
char *cmpname(pEnv env, proc_t proc);
char *operarity(pEnv env, proc_t proc);
void inisymboltable(pEnv env);	/* initialise */
/* parm.c */
void parm(pEnv env, int num, Params type, char *file);
/* prog.c */
void pushcode(pEnv env, NodeList *term);
void code(pEnv env, proc_t proc);
void push(pEnv env, int64_t num);
void prime(pEnv env, Node node);
/* read.c */
int readfactor(pEnv env, NodeList *term, int ch);
int readterm(pEnv env, NodeList *term, int ch);
/* save.c */
void save(pEnv env, NodeList *list, int num, int remove);
/* scan.c */
void inilinebuffer(pEnv env);
int getch(pEnv env);
void ungetch(int ch);
void error(char *str);
int include(pEnv env, char *name);
int getsym(pEnv env, int ch);
/* symb.c */
int lookup(pEnv env, char *name);
int enteratom(pEnv env, char *name);
int compound_def(pEnv env, int ch);
/* undf.c */
void hide_inner_modules(pEnv env, int flag);
/* writ.c */
void writefactor(pEnv env, Node node);
void writeterm(pEnv env, NodeList *term);
void writecode(pEnv env, NodeList *term);
/* error.c */
void execerror(pEnv env, char *str, char *op);
