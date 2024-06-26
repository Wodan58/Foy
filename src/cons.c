/*
    module  : cons.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CONS_C
#define CONS_C

/**
Q0  OK  2010  cons  :  DDA  X A  ->  B
Aggregate B is A with a new member X (first member for sequences).
*/
void cons_(pEnv env)
{
    Node elem, aggr, node;

    PARM(2, CONS);
    aggr = vec_pop(env->stack);
    elem = vec_pop(env->stack);
    switch (aggr.op) {
    case LIST_:
	vec_copy_cons(node.u.lis, aggr.u.lis, elem);
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	node.u.str = GC_malloc_atomic(strlen(aggr.u.str) + 2);
	node.u.str[0] = elem.u.num;
	strcpy(&node.u.str[1], aggr.u.str);
	break;

    case SET_:
	node.u.set = aggr.u.set | ((int64_t)1 << elem.u.num);
	break;
    }
    node.op = aggr.op;
    vec_push(env->stack, node);
}
#endif
