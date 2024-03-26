/*
    module  : float.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FLOAT_C
#define FLOAT_C

/**
Q0  OK  2390  float  :  DA  R  ->  B
Tests whether R is a float.
*/
void float_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op == FLOAT_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
