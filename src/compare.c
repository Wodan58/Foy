/*
    module  : compare.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef COMPARE_C
#define COMPARE_C

#include "compare.h"

/**
Q0  OK  2050  compare  :  DDA  A B  ->  I
I (=-1,0,+1) is the comparison of aggregates A and B.
The values correspond to the predicates <=, =, >=.
*/
void compare_(pEnv env)
{
    Node first, second;

    PARM(2, ANYTYPE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    first.u.num = Compare(env, first, second);
    first.op = INTEGER_;
    vec_push(env->stack, first);
}
#endif
