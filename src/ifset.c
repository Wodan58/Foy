/*
    module  : ifset.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFSET_C
#define IFSET_C

/**
Q2  OK  2640  ifset  :  DDDP  X [T] [E]  ->  ...
If X is a set, executes T else executes E.
*/
void ifset_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == SET_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
