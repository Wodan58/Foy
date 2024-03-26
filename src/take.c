/*
    module  : take.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TAKE_C
#define TAKE_C

/**
Q0  OK  2140  take  :  DDA  A N  ->  B
Aggregate B is the result of retaining just the first N elements of A.
*/
void take_(pEnv env)
{
    int i;
    int64_t j;
    Node elem, aggr, node;

    PARM(2, TAKE);
    elem = vec_pop(env->stack);
    aggr = vec_pop(env->stack);
    node = aggr;
    switch (aggr.op) {
    case LIST_:
	if (elem.u.num < vec_size(aggr.u.lis))
	    vec_copy_count(node.u.lis, aggr.u.lis, elem.u.num);
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	if (elem.u.num < (int)strlen(aggr.u.str)) {
	    node.u.str = GC_malloc_atomic(elem.u.num + 1);
	    strncpy(node.u.str, aggr.u.str, elem.u.num);
	    node.u.str[elem.u.num] = 0;
	    node.op = STRING_;
	}
	break;

    case SET_:
	node.u.set = 0;
	for (j = 1, i = 0; i < SETSIZE && elem.u.num; i++, j <<= 1)
	    if (aggr.u.set & j) {
		node.u.set |= j;
		elem.u.num--;
	    }
	node.op = SET_;
	break;
    }
    vec_push(env->stack, node);
}
#endif
