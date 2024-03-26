/*
    module  : geql.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef GEQL_C
#define GEQL_C

#include "compare.h"

/**
Q0  OK  2220  >=\0geql  :  DDA  X Y  ->  B
Either both X and Y are numeric or both are strings or symbols.
Tests whether X greater than or equal to Y.  Also supports float.
*/
void geql_(pEnv env)
{
    Node first, second;

    PARM(2, ANYTYPE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    if (first.op == SET_ || second.op == SET_)
	first.u.num = !(second.u.set & ~first.u.set);
    else
	first.u.num = Compare(env, first, second) >= 0;
    first.op = BOOLEAN_;
    vec_push(env->stack, first);
}
#endif
