/*
    module  : rotated.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROTATED_C
#define ROTATED_C

/**
Q0  OK  1310  rotated  :  DDDDAAAA  X Y Z W  ->  Z Y X W
As if defined by:   rotated  ==  [rotate] dip
*/
void rotated_(pEnv env)
{
    Node first, second, third, fourth;

    PARM(4, ANYTYPE);
    fourth = vec_pop(env->stack);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, third);
    vec_push(env->stack, second);
    vec_push(env->stack, first);
    vec_push(env->stack, fourth);
}
#endif
