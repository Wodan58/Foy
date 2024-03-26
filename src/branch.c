/*
    module  : branch.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef BRANCH_C
#define BRANCH_C

/**
Q2  OK  2590  branch  :  DDDP  B [T] [F]  ->  ...
If B is true, then executes T else executes F.
*/
void branch_(pEnv env)
{
    Node first, second, third;

    PARM(3, WHILE);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    first = first.u.num ? second : third;
    pushcode(env, first.u.lis);
}
#endif
