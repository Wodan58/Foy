/*
    module  : times.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TIMES_C
#define TIMES_C

/**
Q1  OK  2800  times  :  DDA  N [P]  ->  ...
N times executes P.
*/
void times_(pEnv env)
{
    Node list, node;

    PARM(2, TIMES);
    list = vec_pop(env->stack);
    node = vec_pop(env->stack);
    while (node.u.num--)
	pushcode(env, list.u.lis);
}
#endif
