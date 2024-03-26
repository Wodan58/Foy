/*
    module  : srand.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SRAND_C
#define SRAND_C

/**
Q0  IGNORE_POP  1780  srand  :  D  I  ->
[IMPURE] Sets the random integer seed to integer I.
*/
void srand_(pEnv env)
{
    Node node;

    PARM(1, UNMKTIME);
    node = vec_pop(env->stack);
    srand(node.u.num);
}
#endif
