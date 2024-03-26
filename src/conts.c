/*
    module  : conts.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CONTS_C
#define CONTS_C

/**
Q0  OK  1080  conts  :  A  ->  [[P] [Q] ..]
Pushes current continuations. Buggy, do not use.
*/
void conts_(pEnv env)
{
    Node node;

    vec_init(node.u.lis);
    vec_copy_reverse(node.u.lis, env->code);
    node.op = LIST_;
    vec_push(env->stack, node);
}
#endif
