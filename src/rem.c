/*
    module  : rem.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef REM_C
#define REM_C

/**
Q0  OK  1420  rem  :  DDA  I J  ->  K
Integer K is the remainder of dividing I by J.  Also supports float.
*/
void rem_(pEnv env)
{
    Node first, second;

    PARM(2, REM);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    switch (first.op) {
    case FLOAT_:
	switch (second.op) {
	case FLOAT_:
	    first.u.dbl = fmod(first.u.dbl, second.u.dbl);
	    break;

	default:
	    first.u.dbl = fmod(first.u.dbl, second.u.num);
	    break;
	}
	break;

    default:
	switch (second.op) {
	case FLOAT_:
	    second.u.dbl = fmod(first.u.num, second.u.dbl);
	    first = second;
	    break;

	default:
	    first.u.num %= second.u.num;
	    break;
	}
	break;
    }
    vec_push(env->stack, first);
}
#endif
