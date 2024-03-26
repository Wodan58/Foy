/*
    module  : sinh.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SINH_C
#define SINH_C

/**
Q0  OK  1650  sinh  :  DA  F  ->  G
G is the hyperbolic sine of F.
*/
void sinh_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = sinh(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
