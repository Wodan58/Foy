/*
    module  : time.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TIME_C
#define TIME_C

/**
Q0  IGNORE_PUSH  1140  time  :  A  ->  I
[IMPURE] Pushes the current time (in seconds since the Epoch).
*/
void time_(pEnv env)
{
    Node node;

    node.u.num = time(0);
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
