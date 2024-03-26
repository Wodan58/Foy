/*
    module  : swap.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SWAP_C
#define SWAP_C

/**
Q0  OK  1220  swap  :  DDAA  X Y  ->  Y X
Interchanges X and Y on top of the stack.
*/
void swap_(pEnv env)
{
    Node first, second;

    PARM(2, ANYTYPE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, second);
    vec_push(env->stack, first);
}
#endif
