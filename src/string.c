/*
    module  : string.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STRING_C
#define STRING_C

/**
Q0  OK  2350  string  :  DA  X  ->  B
Tests whether X is a string.
*/
void string_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op == STRING_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
