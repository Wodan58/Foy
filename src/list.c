/*
    module  : list.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef LIST_C
#define LIST_C

/**
Q0  OK  2360  list  :  DA  X  ->  B
Tests whether X is a list.
*/
void list_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op == LIST_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
