/*
    module  : iffloat.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFFLOAT_C
#define IFFLOAT_C

/**
Q2  OK  2670  iffloat  :  DDDP  X [T] [E]  ->  ...
If X is a float, executes T else executes E.
*/
void iffloat_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == FLOAT_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
