/*
    module  : dip.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef DIP_C
#define DIP_C

/**
Q1  OK  2430  dip  :  DDPA  X [P]  ->  ...  X
Saves X, executes P, pushes X back.
*/
void dip_(pEnv env)
{
    Node list, node;

    PARM(2, DIP);
    list = vec_pop(env->stack);
    node = vec_pop(env->stack);
    prime(env, node);
    pushcode(env, list.u.lis);
}
#endif
