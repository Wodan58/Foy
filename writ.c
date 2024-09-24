/*
 *  module  : writ.c
 *  version : 1.4
 *  date    : 09/17/24
 */
#include "globals.h"

/*
 * writefactor prints a factor in readable format to stdout.
 */
void writefactor(pEnv env, Node node)
{
    int i;
    uint64_t set, j;
    char *ptr, buf[BUFFERMAX], tmp[MAXNUM];

    switch (node.op) {
    case USR_PRIME_:
	putchar('#');
	goto usr_prime;

    case USR_:
usr_prime:
	printf("%s", vec_at(env->symtab, node.u.ent).name);
	break;

    case ANON_PRIME_:
	putchar('#');
	goto anon_prime;

    case ANON_FUNCT_:
anon_prime:
	printf("%s", vec_at(env->symtab, operindex(env, node.u.proc)).name);
	break;

    case BOOLEAN_:
	printf("%s", node.u.num ? "true" : "false");
	break;

    case CHAR_:
	if (node.u.num >= 8 && node.u.num <= 13)
	    printf("'\\%c", "btnvfr"[node.u.num - 8]);
	else if (iscntrl(node.u.num) || node.u.num == 32)
	    printf("'\\%03d", (int)node.u.num);
	else
	    printf("'%c", (int)node.u.num);
	break;

    case INTEGER_:
	printf("%" PRId64, node.u.num);
	break;

    case SET_:
	putchar('{');
	for (i = 0, j = 1, set = node.u.set; i < SETSIZE; i++, j <<= 1)
	    if (set & j) {
		printf("%d", i);
		set &= ~j;
		if (set)
		    putchar(' ');
	    }
	putchar('}');
	break;

    case STRING_:
	putchar('"');
	for (ptr = node.u.str; *ptr; ptr++)
	    if (*ptr == '"')
		printf("\\\"");
	    else if (*ptr >= 8 && *ptr <= 13)
		printf("\\%c", "btnvfr"[*ptr - 8]);
	    else if (iscntrl((int)*ptr))
		printf("\\%03d", *ptr);
	    else
		putchar(*ptr);
	putchar('"');
	break;

    case LIST_:
	putchar('[');
	writeterm(env, node.u.lis);
	putchar(']');
	break;

    case FLOAT_:
	snprintf(buf, BUFFERMAX, "%g", node.u.dbl);	/* exponent is e */
	if ((ptr = strchr(buf, '.')) == 0) {	/* locate decimal point */
	    if ((ptr = strchr(buf, 'e')) == 0) {/* locate start of exponent */
		i = buf[strlen(buf) - 1];
		if (isdigit(i))			/* check digit present */
		    strcat(buf, ".0");		/* add decimal point and 0 */
	    } else {
		strcpy(tmp, ptr);		/* save exponent */
		strcat(buf, ".0");		/* add decimal point and 0 */
		strcat(buf, tmp);		/* restore exponent */
	    }
	}
	printf("%s", buf);
	break;

    case FILE_:
	if (!node.u.fil)
	    printf("NULL");
	else if (node.u.fil == stdin)
	    printf("stdin");
	else if (node.u.fil == stdout)
	    printf("stdout");
	else if (node.u.fil == stderr)
	    printf("stderr");
	else
	    printf("%p", (void *)node.u.fil);
	break;
    }
}

/*
 * writeterm prints the contents of a list in readable format to stdout.
 */
void writeterm(pEnv env, NodeList *term)
{
    int i, j;
    Node node;

    j = vec_size(term);
    for (i = 0; i < j; i++) {
	node = vec_at(term, i);
	writefactor(env, node);
	if (i < j - 1)
	    putchar(' ');
    }
}

/*
 * writecode prints the contents of a list in readable format to stdout.
 */
void writecode(pEnv env, NodeList *term)
{
    int i;
    Node node;

    for (i = vec_size(term) - 1; i >= 0; i--) {
	node = vec_at(term, i);
	writefactor(env, node);
	if (i)
	    putchar(' ');
    }
}
