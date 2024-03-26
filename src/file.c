/*
    module  : file.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FILE_C
#define FILE_C

/**
Q0  OK  2400  file  :  DA  F  ->  B
[FOREIGN] Tests whether F is a file.
*/
void file_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op == FILE_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
