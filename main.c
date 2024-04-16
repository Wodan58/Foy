/*
    module  : main.c
    version : 1.5
    date    : 04/11/24
*/
#include "globals.h"

char *bottom_of_stack;		/* needed in gc.c */

static jmp_buf begin;		/* restart with empty program */

/*
 * abort execution and restart reading from srcfile; the stack is not cleared.
 */
void abortexecution_(int num)
{
    longjmp(begin, num);
}

/*
 * options - print help on startup options and exit: options are those that
 *	     cannot be set from within the language itself.
 */
static void options()
{
    printf("JOY  -  compiled at %s on %s", __TIME__, __DATE__);
#ifdef VERS
    printf(" (%s)", VERS);
#endif
    printf("\nCopyright 2001 by Manfred von Thun\n");
    printf("Usage: joy (options | filenames | parameters)*\n");
    printf("options, filenames, parameters can be given in any order\n");
    printf("options start with '-' and parameters start with a digit\n");
    printf("filenames can be preceded by a pathname: e.g. './'\n");
#ifdef COMP
    printf("Compile flags: %s\n", COMP);
#endif
#ifdef LINK
    printf("Linker flags: %s\n", LINK);
#endif
    printf("Options:\n");
    printf("  -a : set the autoput flag (0-2)\n");
    printf("  -d : print a trace of stack development\n");
    printf("  -e : set the echoflag (0-3)\n");
    printf("  -g : set the __tracegc flag (0-6)\n");
    printf("  -h : print this help text and exit\n");
    printf("  -i : ignore impure imperative functions\n");
    printf("  -l : do not read usrlib.joy at startup\n");
    printf("  -p : print debug list of tokens\n");
    printf("  -s : dump symbol table after execution\n");
    printf("  -t : print a trace of program execution\n");
    printf("  -u : set the undeferror flag (0,1)\n");
    printf("  -w : no warnings: overwriting, arities\n");
    printf("  -x : print statistics at end of program\n");
}

/*
 * opt_unknown - report unknown option and point out -h option.
 */
static void opt_unknown(char *exe, int ch)
{
    printf("Unknown option argument: \"-%c\"\n", ch);
    printf("More info with: \"%s -h\"\n", exe);
}

static int my_main(int argc, char **argv)
{
    static unsigned char psdump = 0, pstats = 0;
    Env env;
    Node node;
    int i, j, ch, flag;
    char *ptr, *tmp, *exe;
    /*
     * determine srcfile and filenam; they are stored in inilinebuffer.
     */
    FILE *srcfile = stdin;
    char *filenam = "stdin";
    unsigned char mustinclude = 1, helping = 0, unknown = 0;

    memset(&env, 0, sizeof(env));
    /*
     * Start the clock.
     */
    env.startclock = clock();
    /*
     * establish pathname, to be used when loading libraries, and basename.
     */
    if ((ptr = strrchr(argv[0], '/')) != 0 ||
	(ptr = strrchr(argv[0], '\\')) != 0) {
	*ptr++ = 0;
	env.pathname = argv[0];
	argv[0] = ptr;
    } else
	env.pathname = ".";
    exe = argv[0];
    /*
     * These flags are initialized here, allowing them to be overruled by the
     * command line. When set on the command line, they can not be overruled
     * in the source code.
     */
    env.autoput = INIAUTOPUT;
    env.echoflag = INIECHOFLAG;
    env.undeferror = INIUNDEFERROR;
    env.tracegc = INITRACEGC;
    env.overwrite = INIWARNING;
    /*
     * First look for options. They start with -.
     */
    for (i = 1; i < argc; i++) {
	if (argv[i][0] == '-') {
	    for (j = 1; argv[i][j]; j++) {
		switch (argv[i][j]) {
		case 'a' : ptr = &argv[i][j + 1];
			   env.autoput = strtoll(ptr, &tmp, 0);
			   j += tmp - ptr;
			   env.autoput_set = 1;		/* disable usrlib.joy */
			   break;
		case 'd' : env.debugging = 1; break;
		case 'e' : ptr = &argv[i][j + 1];
			   env.echoflag = strtoll(ptr, &tmp, 0);
			   j += tmp - ptr;
			   break;
		case 'g' : ptr = &argv[i][j + 1];
			   env.tracegc = strtoll(ptr, &tmp, 0);
			   j += tmp - ptr;
			   break;
		case 'h' : helping = 1; break;
		case 'i' : env.ignore = 1; break;
		case 'l' : mustinclude = 0; break;
		case 'p' : env.printing = 1; break;
		case 's' : psdump = 1; break;
		case 't' : env.debugging = 2; break;
		case 'u' : ptr = &argv[i][j + 1];
			   env.undeferror = strtoll(ptr, &tmp, 0);
			   j += tmp - ptr;
			   env.undeferror_set = 1;	/* disable usrlib.joy */
			   break;
		case 'w' : env.overwrite = 0; break;
		case 'x' : pstats = 1; break;
		default  : unknown = argv[i][j]; break;
		} /* end switch */
	    } /* end for */
	    /*
	     * Overwrite the option(s) with subsequent parameters. Index i is
	     * decreased, because the next parameter is copied to the current
	     * index and i is increased in the for-loop.
	     */
	    for (--argc, j = i--; j < argc; j++)
		argv[j] = argv[j + 1];
	} /* end if */
    } /* end for */
    /*
     * Look for a possible filename parameter. Filenames cannot start with -
     * and cannot start with a digit, unless preceded by a path: e.g. './'.
     */
    for (i = 1; i < argc; i++) {
	ch = argv[i][0];
	if (!isdigit(ch)) {
	    if ((srcfile = fopen(filenam = argv[i], "r")) == 0) {
		fprintf(stderr, "failed to open the file '%s'.\n", filenam);
		return 0;
	    }
	    /*
	     * Overwrite argv[0] with the filename and shift subsequent
	     * parameters.
	     */
	    if ((ptr = strrchr(argv[0] = filenam, '/')) != 0) {
		*ptr++ = 0;
		argv[0] = filenam = ptr;	/* basename */
	    }
	    for (--argc; i < argc; i++)
		argv[i] = argv[i + 1];
	    break;				/* only one filename */
	} /* end if */
    } /* end for */
    inilinebuffer(srcfile, filenam);
    /*
     * determine argc and argv.
     */
    env.g_argc = argc;
    env.g_argv = argv;
    /*
     * initialize vectors.
     */
    vec_init(env.string);
    vec_init(env.pushback);
    vec_init(env.code);
    vec_init(env.stack);
    vec_init(env.symtab);
    vec_init(env.tokens);
    /*
     * initialize symbol table.
     */
    inisymboltable(&env);
    /*
     * handle options, might print symbol table.
     */
    if (helping || unknown) {
	helping ? options() : opt_unknown(exe, unknown);
	goto einde;
    }
    /*
     * initialize standard output.
     */
    setbuf(stdout, 0);			/* necessary when writing to a pipe */
    /*
     * read initial library.
     */
    if (mustinclude)
	include(&env, "usrlib.joy");	/* try include only once */
    /*
     * setup return address of error, abort, or quit.
     */
    if (setjmp(begin) == ABORT_QUIT)	/* return here after error or abort */
	goto einde;
    /*
     * (re)initialize code vector.
     */
    vec_setsize(env.code, 0);		/* clear code, not stack */
    /*
     * start reading from input file(s).
     */
    ch = getch(&env);
    while (1) {
	ch = getsym(&env, ch);
	if (env.sym == LIBRA || env.sym == HIDE || env.sym == MODULE_ ||
	    env.sym == CONST_) {
	    /*
	     * process definition(s).
	     */
	    if ((flag = env.sym == MODULE_) != 0)
		hide_inner_modules(&env, 1);
	    ch = compound_def(&env, ch);
	    if (flag)
		hide_inner_modules(&env, 0);
	} else {
	    /*
	     * read and evaluate code.
	     */
	    ch = readterm(&env, env.stack, ch);
	    /*
	     * print the top of the data area, the entire stack, or nothing.
	     */
	    if (vec_size(env.stack)) {
		if (env.autoput == 2)
		    writeterm(&env, env.stack);
		else if (env.autoput == 1) {
		    node = vec_pop(env.stack);
		    writefactor(&env, node);
		}
		if (env.autoput)
		    putchar('\n');
	    }
	}
    }
einde:
    if (pstats)
	stats(&env);
    if (psdump)
	dump(&env);
    return 0;
}

int main(int argc, char **argv)
{
    int (*volatile m)(int, char **) = my_main;

    bottom_of_stack = (char *)&argc;
    GC_INIT();
    return (*m)(argc, argv);
}

/*
 * print statistics.
 */
void stats(pEnv env)
{
    printf("%.0f milliseconds CPU\n", (clock() - env->startclock) * 1000.0 /
	   CLOCKS_PER_SEC);
    printf("%.0f data nodes available\n", (double)vec_max(env->stack));
    printf("%.0f code nodes available\n", (double)vec_max(env->code));
    printf("%.0f garbage collections\n", (double)GC_get_gc_no());
    printf("%.0f calls to joy interpreter\n", env->calls);
    printf("%.0f operations executed\n", env->opers);
}

/*
 * dump the symbol table.
 */
void dump(pEnv env)
{
    int i;
    Entry ent;

    for (i = vec_size(env->symtab) - 1; i >= 0; i--) {
	ent = vec_at(env->symtab, i);
	if (!ent.is_user)
	    printf("(%d) %s\n", i, ent.name);
	else {
	    printf("(%d) %s == ", i, ent.name);
	    writeterm(env, ent.u.body);
	    putchar('\n');
	}
    }
}
