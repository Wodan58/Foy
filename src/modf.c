/*
    module  : modf.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef MODF_C
#define MODF_C

/**
Q0  OK  1620  modf  :  DAA  F  ->  G H
G is the fractional part and H is the integer part
(but expressed as a float) of F.
*/
void modf_(pEnv env)
{
    Node node;
    double exp;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = modf(node.op == FLOAT_ ? node.u.dbl : node.u.num, &exp);
    node.op = FLOAT_;
    vec_push(env->stack, node);
    node.u.dbl = exp;
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
