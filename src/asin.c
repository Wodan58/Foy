/*
    module  : asin.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ASIN_C
#define ASIN_C

/**
Q0  OK  1500  asin  :  DA  F  ->  G
G is the arc sine of F.
*/
void asin_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = asin(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
