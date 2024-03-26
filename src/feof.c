/*
    module  : feof.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FEOF_C
#define FEOF_C

/**
Q0  OK  1840  feof  :  A  S  ->  S B
[FOREIGN] B is the end-of-file status of stream S.
*/
void feof_(pEnv env)
{
    Node node;

    PARM(1, FGET);
    node = vec_back(env->stack);
    node.u.num = feof(node.u.fil);
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
