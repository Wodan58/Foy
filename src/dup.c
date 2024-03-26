/*
    module  : dup.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef DUP_C
#define DUP_C

/**
Q0  OK  1210  dup  :  A  X  ->  X X
Pushes an extra copy of X onto stack.
*/
void dup_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_back(env->stack);
    vec_push(env->stack, node);
}
#endif
