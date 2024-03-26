/*
    module  : rotate.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROTATE_C
#define ROTATE_C

/**
Q0  OK  1250  rotate  :  DDDAAA  X Y Z  ->  Z Y X
Interchanges X and Z.
*/
void rotate_(pEnv env)
{
    Node first, second, third;

    PARM(3, ANYTYPE);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, third);
    vec_push(env->stack, second);
    vec_push(env->stack, first);
}
#endif
