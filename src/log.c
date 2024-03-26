/*
    module  : log.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef LOG_C
#define LOG_C

/**
Q0  OK  1600  log  :  DA  F  ->  G
G is the natural logarithm of F.
*/
void log_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = log(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
