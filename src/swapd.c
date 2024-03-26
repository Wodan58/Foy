/*
    module  : swapd.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SWAPD_C
#define SWAPD_C

/**
Q0  OK  1280  swapd  :  DDDAAA  X Y Z  ->  Y X Z
As if defined by:   swapd  ==  [swap] dip
*/
void swapd_(pEnv env)
{
    Node first, second, third;

    PARM(3, ANYTYPE);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, second);
    vec_push(env->stack, first);
    vec_push(env->stack, third);
}
#endif
