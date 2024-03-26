/*
    module  : rollupd.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROLLUPD_C
#define ROLLUPD_C

/**
Q0  OK  1290  rollupd  :  DDDDAAAA  X Y Z W  ->  Z X Y W
As if defined by:   rollupd  ==  [rollup] dip
*/
void rollupd_(pEnv env)
{
    Node first, second, third, fourth;

    PARM(4, ANYTYPE);
    fourth = vec_pop(env->stack);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, third);
    vec_push(env->stack, first);
    vec_push(env->stack, second);
    vec_push(env->stack, fourth);
}
#endif
