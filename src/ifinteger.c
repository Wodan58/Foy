/*
    module  : ifinteger.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFINTEGER_C
#define IFINTEGER_C

/**
Q2  OK  2610  ifinteger  :  DDDP  X [T] [E]  ->  ...
If X is an integer, executes T else executes E.
*/
void ifinteger_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == INTEGER_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
