/*
    module  : true.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TRUE_C
#define TRUE_C

/**
Q0  IMMEDIATE  1010  true  :  A  ->  true
Pushes the value true.
*/
void true_(pEnv env)
{
    Node node;

    node.u.num = 1;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
