/*
    module  : sqrt.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SQRT_C
#define SQRT_C

/**
Q0  OK  1660  sqrt  :  DA  F  ->  G
G is the square root of F.
*/
void sqrt_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = sqrt(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
