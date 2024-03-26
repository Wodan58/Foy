/*
    module  : rand.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef RAND_C
#define RAND_C

/**
Q0  OK  1150  rand  :  A  ->  I
[IMPURE] I is a random integer.
*/
void rand_(pEnv env)
{
    Node node;

    node.u.num = rand();
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
