/*
    module  : fgetch.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FGETCH_C
#define FGETCH_C

/**
Q0  OK  1870  fgetch  :  A  S  ->  S C
[FOREIGN] C is the next available character from stream S.
*/
void fgetch_(pEnv env)
{
    Node node;

    PARM(1, FGET);
    node = vec_back(env->stack);
    node.u.num = getc(node.u.fil);
    node.op = CHAR_;
    vec_push(env->stack, node);
}
#endif
