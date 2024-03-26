/*
    module  : divide.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef DIVIDE_C
#define DIVIDE_C

/**
Q0  OK  1410  /\0divide  :  DDA  I J  ->  K
Integer K is the (rounded) ratio of integers I and J.  Also supports float.
*/
void divide_(pEnv env)
{
    Node first, second;

    PARM(2, DIVIDE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    switch (first.op) {
    case FLOAT_:
	switch (second.op) {
	case FLOAT_:
	    first.u.dbl /= second.u.dbl;
	    break;

	default:
	    first.u.dbl /= second.u.num;
	    break;
	}
	break;

    default:
	switch (second.op) {
	case FLOAT_:
	    second.u.dbl = first.u.num / second.u.dbl;
	    first = second;
	    break;

	default:
	    first.u.num /= second.u.num;
	    break;
	}
	break;
    }
    vec_push(env->stack, first);
}
#endif
