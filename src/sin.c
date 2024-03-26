/*
    module  : sin.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SIN_C
#define SIN_C

/**
Q0  OK  1640  sin  :  DA  F  ->  G
G is the sine of F.
*/
void sin_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = sin(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
