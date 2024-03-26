/*
    module  : iflist.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFLIST_C
#define IFLIST_C

/**
Q2  OK  2660  iflist  :  DDDP  X [T] [E]  ->  ...
If X is a list, executes T else executes E.
*/
void iflist_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == LIST_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
