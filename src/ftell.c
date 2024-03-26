/*
    module  : ftell.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FTELL_C
#define FTELL_C

/**
Q0  OK 1990  ftell  :  A  S  ->  S I
[FOREIGN] I is the current position of stream S.
*/
void ftell_(pEnv env)
{
    Node node;

    PARM(1, FGET);
    node = vec_back(env->stack);
    node.u.num = ftell(node.u.fil);
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
