/*
    module  : min.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef MIN_C
#define MIN_C

/**
Q0  OK  1820  min  :  DDA  N1 N2  ->  N
N is the minimum of numeric values N1 and N2.  Also supports float.
*/
void min_(pEnv env)
{
    Node first, second;

    PARM(2, MAXMIN);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    switch (first.op) {
    case FLOAT_:
	switch (second.op) {
	case FLOAT_:
	    if (second.u.dbl < first.u.dbl)
		first.u.dbl = second.u.dbl;
	    break;

	default:
	    if (second.u.num < first.u.dbl)
		first.u.dbl = second.u.num;
	    break;
	}
	break;

    default:
	switch (second.op) {
	case FLOAT_:
	    if (first.u.num < second.u.dbl)
		second.u.dbl = first.u.num;
	    first = second;
	    break;

	default:
	    if (second.u.num < first.u.num)
		first.u.num = second.u.num;
	    break;
	}
	break;
    }
    vec_push(env->stack, first);
}
#endif
