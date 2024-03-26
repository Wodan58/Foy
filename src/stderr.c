/*
    module  : stderr.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STDERR_C
#define STDERR_C

/**
Q0  IMMEDIATE  1190  stderr  :  A  ->  S
[FOREIGN] Pushes the standard error stream.
*/
void stderr_(pEnv env)
{
    Node node;

    node.u.fil = stderr;
    node.op = FILE_;
    vec_push(env->stack, node);
}
#endif
