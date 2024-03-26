/*
    module  : ifstring.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFSTRING_C
#define IFSTRING_C

/**
Q2  OK  2650  ifstring  :  DDDP  X [T] [E]  ->  ...
If X is a string, executes T else executes E.
*/
void ifstring_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == STRING_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
