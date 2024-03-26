/*
    module  : popd.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef POPD_C
#define POPD_C

/**
Q0  OK  1260  popd  :  DDA  Y Z  ->  Z
As if defined by:   popd  ==  [pop] dip
*/
void popd_(pEnv env)
{
    Node node;

    PARM(2, ANYTYPE);
    node = vec_pop(env->stack);
    (void)vec_pop(env->stack);
    vec_push(env->stack, node);
}
#endif
