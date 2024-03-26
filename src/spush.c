/*
    module  : spush.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SPUSH_C
#define SPUSH_C

/**
Q0  OK  3360  #spush  :  A  ->
Pop the location of an element on the code stack.
Read that element and push it on the data stack.
*/
void spush_(pEnv env)
{
    Node jump, node;

    jump = vec_pop(env->code);
    node = vec_at(env->code, jump.u.num);
    vec_push(env->stack, node);
}
#endif
