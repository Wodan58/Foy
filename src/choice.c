/*
    module  : choice.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CHOICE_C
#define CHOICE_C

/**
Q0  OK  1330  choice  :  DDDA  B T F  ->  X
If B is true, then X = T else X = F.
*/
void choice_(pEnv env)
{
    Node first, second, third;

    PARM(3, ANYTYPE);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    first = first.u.num ? second : third;
    vec_push(env->stack, first);
}
#endif
