/*
    module  : dupd.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef DUPD_C
#define DUPD_C

/**
Q0  OK  1270  dupd  :  DDAAA  Y Z  ->  Y Y Z
As if defined by:   dupd  ==  [dup] dip
*/
void dupd_(pEnv env)
{
    Node first, second;

    PARM(2, ANYTYPE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    vec_push(env->stack, first);
    vec_push(env->stack, first);
    vec_push(env->stack, second);
}
#endif
