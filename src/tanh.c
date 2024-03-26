/*
    module  : tanh.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TANH_C
#define TANH_C

/**
Q0  OK  1680  tanh  :  DA  F  ->  G
G is the hyperbolic tangent of F.
*/
void tanh_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = tanh(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
