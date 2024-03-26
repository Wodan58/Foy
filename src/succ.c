/*
    module  : succ.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SUCC_C
#define SUCC_C

/**
Q0  OK  1800  succ  :  DA  M  ->  N
Numeric N is the successor of numeric M.
*/
void succ_(pEnv env)
{
    Node node;

    PARM(1, PREDSUCC);
    node = vec_pop(env->stack);
    node.u.num++;
    vec_push(env->stack, node);
}
#endif
