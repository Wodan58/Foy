/*
    module  : times.c
    version : 1.3
    date    : 11/12/24
*/
#ifndef TIMES_C
#define TIMES_C

/**
Q1  OK  2800  times  :  DDA  N [P]  ->  ...
N times executes P.
*/
void times_(pEnv env)
{
    int64_t i, n;
    Node list, node;

    PARM(2, TIMES);
    list = vec_pop(env->stack);
    node = vec_pop(env->stack);
    n = node.u.num;
    for (i = 0; i < n; i++)
	pushcode(env, list.u.lis);
}
#endif
