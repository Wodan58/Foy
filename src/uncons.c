/*
    module  : uncons.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef UNCONS_C
#define UNCONS_C

/**
Q0  OK  2110  uncons  :  DAA  A  ->  F R
F and R are the first and the rest of non-empty aggregate A.
*/
void uncons_(pEnv env)
{
    int i = 0;
    Node aggr, elem, temp;

    PARM(1, FIRST);
    aggr = vec_pop(env->stack);
    switch (aggr.op) {
    case LIST_:
	elem = vec_at(aggr.u.lis, 0);
	vec_copy_rest(temp.u.lis, aggr.u.lis, 1);
	aggr.u.lis = temp.u.lis;
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	elem.u.num = *aggr.u.str++;
	elem.op = CHAR_;
	aggr.u.str = GC_strdup(aggr.u.str);
	break;

    case SET_:
	while (!(aggr.u.set & ((int64_t)1 << i)))
	    i++;
	elem.u.num = i;
	elem.op = INTEGER_;
	aggr.u.set &= ~((int64_t)1 << i);
	break;
    }
    vec_push(env->stack, elem);		/* push element */
    vec_push(env->stack, aggr);		/* push remainder */
}
#endif
