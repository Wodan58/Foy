/*
    module  : leaf.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef LEAF_C
#define LEAF_C

/**
Q0  OK  2370  leaf  :  DA  X  ->  B
Tests whether X is not a list.
*/
void leaf_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op != LIST_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
