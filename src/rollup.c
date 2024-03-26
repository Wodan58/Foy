/*
    module  : rollup.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROLLUP_C
#define ROLLUP_C

/**
Q0  OK  1230  rollup  :  DDDAAA  X Y Z  ->  Z X Y
Moves X and Y up, moves Z down.
*/
void rollup_(pEnv env)
{
    Node first, second, third;

    PARM(3, ANYTYPE);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, third);
    vec_push(env->stack, first);
    vec_push(env->stack, second);
}
#endif
