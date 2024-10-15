/*
    module  : read.c
    version : 1.3
    date    : 10/11/24
*/
#include "globals.h"

/*
 * trace the evaluation.
 */
static void trace(pEnv env)
{
    writeterm(env, env->stack);
    if (env->debugging == 2) {
	printf(" : ");
	writecode(env, env->code);
    }
    putchar('\n');
}

/*
 * exeterm evaluates nodes from the code array.
 */
static void exeterm(pEnv env)
{
    Node node;
    Entry ent;

    while (vec_size(env->code)) {
	if (env->debugging)
	    trace(env);
	node = vec_pop(env->code);
	switch (node.op) {
	case USR_:
	    ent = vec_at(env->symtab, node.u.ent);
	    if (!ent.u.body && env->undeferror)
		execerror(env, "definition", ent.name);
	    pushcode(env, ent.u.body);
	    break;

	case ANON_FUNCT_:
	    (*node.u.proc)(env);
	    env->opers++;
	    break;

	case USR_PRIME_:
	    node.op = USR_;
	    goto next;

	case ANON_PRIME_:
	    node.op = ANON_FUNCT_;
	    goto next;

	default:
next:
	    vec_push(env->stack, node);
	    break;
	}
    }
    env->calls++;
}

/*
 * list2set converts a list to a set.
 */
static uint64_t list2set(NodeList *list)
{
    int i;
    Node node;
    uint64_t set = 0;

    for (i = vec_size(list) - 1; i >= 0; i--) {
	node = vec_at(list, i);
	if (node.op == CHAR_ || node.op == INTEGER_)
	    if (node.u.num < 0 || node.u.num >= SETSIZE)
		error("small numeric expected in set");
	    else
		set |= (uint64_t)1 << node.u.num;
	else
	    error("numeric expected in set");
    }
    return set;
}

/*
 * readfactor reads a Joy factor and appends it to term.
 */
int readfactor(pEnv env, NodeList *term, int ch)
{
    Entry ent;
    Node node;
    NodeList *temp;
    int index, flags = 0;

    switch (env->sym) {
    case USR_:
	index = lookup(env, env->str);
	if (!index && strchr(env->str, '.')) {
	    error("no such field in module");
	    return ch;
	}
	ent = vec_at(env->symtab, index);
	/*
	 * Check that the function is immediate or that operation is on the
	 * main stack.
	 */
	if (ent.flags == POSTPONE && env->stack == term)
	    env->postpone = 1;
	else if (!env->postpone && (ent.flags == IMMEDIATE ||
		  env->stack == term))
	    flags = 1;

	if (ent.is_user) {
	    if (flags) {
		if (!ent.u.body && env->undeferror)
		    execerror(env, "definition", ent.name);
		pushcode(env, ent.u.body);
	    } else {
		node.u.ent = index;
		node.op = USR_;
		vec_push(term, node);
	    }
	} else {
	    if (flags) {
		temp = 0;
		if (env->stack != term) {
		    temp = env->stack;
		    env->stack = term;
		}
		(*ent.u.proc)(env);
		env->opers++;
		if (temp)
		    env->stack = temp;
	    } else {
		node.u.proc = ent.u.proc;
		node.op = ANON_FUNCT_;
		vec_push(term, node);
	    }
	}
	break;

    case CHAR_:
    case INTEGER_:
	node.u.num = env->num;
	node.op = env->sym;
	vec_push(term, node);
	break;

    case STRING_:
	node.u.str = env->str;
	node.op = STRING_;
	vec_push(term, node);
	break;

    case FLOAT_:
	node.u.dbl = env->dbl;
	node.op = FLOAT_;
	vec_push(term, node);
	break;

    case '{':
	ch = getsym(env, ch);
	vec_init(node.u.lis);
	if (env->sym != '}')
	    ch = readterm(env, node.u.lis, ch);
	if (env->sym != '}')
	    error("'}' expected");
	node.u.set = list2set(node.u.lis);
	node.op = SET_;
	vec_push(term, node);
	break;

    case '[':
	ch = getsym(env, ch);
	vec_init(node.u.lis);
	if (env->sym != ']')
	    ch = readterm(env, node.u.lis, ch);
	if (env->sym != ']')
	    error("']' expected");
	node.op = LIST_;
	vec_push(term, node);
	break;

    case '(':
	error("'(' not implemented");
	break;
#if 0
    default:
	error("a factor cannot begin with this symbol");
	break;
#endif
    }
    return ch;
}

/*
 * readterm reads a Joy term. The factors are stored in term.
 */
int readterm(pEnv env, NodeList *term, int ch)
{
    int sym;

    while (1) {
	ch = readfactor(env, term, ch);
	sym = env->sym;
	if (!strchr(".;", env->sym))
	    ch = getsym(env, ch);	/* install next symbol */
	/*
	 * evaluate postponed code sequences.
	 */
	if (env->postpone) {
	    if (sym != '.')		/* postpone till final stop */
		continue;
	    env->postpone = 0;		/* stop postponing */
	    pushcode(env, env->stack);	/* transfer stack to code */
	    vec_setsize(env->stack, 0);	/* clear stack */
	    exeterm(env);		/* evaluate against stack */
	    break;
	}
	/*
	 * evaluate any pending code sequences.
	 */
	if (vec_size(env->code) && !env->getting)
	    exeterm(env);
	if (strchr(".;]}", env->sym) ||
	   (env->sym >= LIBRA && env->sym <= CONST_))
	    break;
    }
    return ch;
}
