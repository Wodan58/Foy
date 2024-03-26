/*
    module  : ceil.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CEIL_C
#define CEIL_C

/**
Q0  OK  1530  ceil  :  DA  F  ->  G
G is the float ceiling of F.
*/
void ceil_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = ceil(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
