/*
    module  : drop.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef DROP_C
#define DROP_C

/**
Q0  OK  2130  drop  :  DDA  A N  ->  B
Aggregate B is the result of deleting the first N elements of A.
*/
void drop_(pEnv env)
{
    int i;
    int64_t j;
    Node aggr, elem, node;

    PARM(2, TAKE);
    elem = vec_pop(env->stack);
    aggr = vec_pop(env->stack);
    node = aggr;
    switch (aggr.op) {
    case LIST_:
	if (elem.u.num >= vec_size(aggr.u.lis))
	    node.u.lis = 0;
	else
	    vec_copy_rest(node.u.lis, aggr.u.lis, elem.u.num);
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	if ((i = strlen(aggr.u.str)) <= elem.u.num)
	    node.u.str = "";
	else {
	    node.u.str = GC_malloc_atomic(i - elem.u.num + 1);
	    strcpy(node.u.str, aggr.u.str + elem.u.num);
	}
	break;

    case SET_:
	node.u.set = 0;
	for (j = 1, i = 0; i < SETSIZE; i++, j <<= 1)
	    if (aggr.u.set & j) {
		if (elem.u.num < 1)
		    node.u.set |= j;
		else
		    elem.u.num--;
	    }
	break;
    }
    vec_push(env->stack, node);
}
#endif
