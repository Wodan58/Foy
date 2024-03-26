/*
    module  : log10.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef LOG10_C
#define LOG10_C

/**
Q0  OK  1610  log10  :  DA  F  ->  G
G is the common logarithm of F.
*/
void log10_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = log10(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
