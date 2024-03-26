/*
    module  : unstack.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef UNSTACK_C
#define UNSTACK_C

/**
Q0  OK  2000  unstack  :  DP  [X Y ..]  ->  ..Y X
The list [X Y ..] becomes the new stack.
*/
void unstack_(pEnv env)
{
    Node node;

    PARM(1, HELP);
    node = vec_pop(env->stack);
    vec_setsize(env->stack, 0);
    vec_copy_reverse(env->stack, node.u.lis);
}
#endif
