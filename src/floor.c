/*
    module  : floor.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FLOOR_C
#define FLOOR_C

/**
Q0  OK  1570  floor  :  DA  F  ->  G
G is the floor of F.
*/
void floor_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = floor(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
