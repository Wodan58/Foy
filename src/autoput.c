/*
    module  : autoput.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef AUTOPUT_C
#define AUTOPUT_C

/**
Q0  OK  1090  autoput  :  A  ->  I
Pushes current value of flag for automatic output, I = 0..2.
*/
void autoput_(pEnv env)
{
    Node node;

    node.u.num = env->autoput;
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
