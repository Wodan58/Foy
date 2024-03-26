/*
    module  : argc.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ARGC_C
#define ARGC_C

/**
Q0  OK  3050  argc  :  A  ->  I
Pushes the number of command line arguments. This is quivalent to 'argv size'.
*/
void argc_(pEnv env)
{
    Node node;

    node.u.num = env->g_argc;
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
