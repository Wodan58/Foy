/*
    module  : rolldown.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROLLDOWN_C
#define ROLLDOWN_C

/**
Q0  OK  1240  rolldown  :  DDDAAA  X Y Z  ->  Y Z X
Moves Y and Z down, moves X up.
*/
void rolldown_(pEnv env)
{
    Node first, second, third;

    PARM(3, ANYTYPE);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, second);
    vec_push(env->stack, third);
    vec_push(env->stack, first);
}
#endif
