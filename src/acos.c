/*
    module  : acos.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ACOS_C
#define ACOS_C

/**
Q0  OK  1490  acos  :  DA  F  ->  G
G is the arc cosine of F.
*/
void acos_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = acos(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
