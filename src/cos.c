/*
    module  : cos.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef COS_C
#define COS_C

/**
Q0  OK  1540  cos  :  DA  F  ->  G
G is the cosine of F.
*/
void cos_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = cos(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
