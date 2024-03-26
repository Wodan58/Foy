/*
    module  : rolldownd.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROLLDOWND_C
#define ROLLDOWND_C

/**
Q0  OK  1300  rolldownd  :  DDDDAAAA  X Y Z W  ->  Y Z X W
As if defined by:   rolldownd  ==  [rolldown] dip
*/
void rolldownd_(pEnv env)
{
    Node first, second, third, fourth;

    PARM(4, ANYTYPE);
    fourth = vec_pop(env->stack);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, second);
    vec_push(env->stack, third);
    vec_push(env->stack, first);
    vec_push(env->stack, fourth);
}
#endif
