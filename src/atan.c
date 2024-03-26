/*
    module  : atan.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ATAN_C
#define ATAN_C

/**
Q0  OK  1510  atan  :  DA  F  ->  G
G is the arc tangent of F.
*/
void atan_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = atan(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
