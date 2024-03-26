/*
    module  : step.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STEP_C
#define STEP_C

/**
Q1  OK  2770  step  :  DDQ  A [P]  ->  ...
Sequentially putting members of aggregate A onto stack,
executes P for each member of A.
*/
void step_(pEnv env)
{
    int i;
    Node aggr, list, node;

    PARM(2, STEP);
    list = vec_pop(env->stack);
    aggr = vec_pop(env->stack);
    switch (aggr.op) {
    case LIST_:
	for (i = vec_size(aggr.u.lis) - 1; i >= 0; i--) {
	    pushcode(env, list.u.lis);
	    node = vec_at(aggr.u.lis, i);
	    prime(env, node);
	}
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	node.op = CHAR_;
	for (i = strlen(aggr.u.str) - 1; i >= 0; i--) {
	    pushcode(env, list.u.lis);
	    node.u.num = aggr.u.str[i];
	    prime(env, node);
	}
	break;

    case SET_:
	node.op = INTEGER_;
	for (i = SETSIZE - 1; i >= 0; i--)
	    if (aggr.u.set & ((int64_t)1 << i)) {
		pushcode(env, list.u.lis);
		node.u.num = i;
		prime(env, node);
	    }
	break;
    }
}
#endif
