/*
    module  : minus.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef MINUS_C
#define MINUS_C

/**
Q0  OK  1390  -\0minus  :  DDA  M I  ->  N
Numeric N is the result of subtracting integer I from numeric M.
Also supports float.
*/
void minus_(pEnv env)
{
    Node first, second;

    PARM(2, PLUSMINUS);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    switch (first.op) {
    case FLOAT_:
	switch (second.op) {
	case FLOAT_:
	    first.u.dbl -= second.u.dbl;
	    break;

	default:
	    first.u.dbl -= second.u.num;
	    break;
	}
	break;

    default:
	switch (second.op) {
	case FLOAT_:
	    second.u.dbl = first.u.num - second.u.dbl;
	    first = second;
	    break;

	default:
	    first.u.num -= second.u.num;
	    break;
	}
	break;
    }
    vec_push(env->stack, first);
}
#endif
