/*
    module  : iflogical.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFLOGICAL_C
#define IFLOGICAL_C

/**
Q2  OK  2630  iflogical  :  DDDP  X [T] [E]  ->  ...
If X is a logical or truth value, executes T else executes E.
*/
void iflogical_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == BOOLEAN_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
