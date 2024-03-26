/*
    module  : fflush.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FFLUSH_C
#define FFLUSH_C

/**
Q0  OK  1860  fflush  :  N  S  ->  S
[FOREIGN] Flush stream S, forcing all buffered output to be written.
*/
void fflush_(pEnv env)
{
    Node node;

    PARM(1, FGET);
    node = vec_back(env->stack);
    fflush(node.u.fil);
}
#endif
