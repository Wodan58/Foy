/*
    module  : exp.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef EXP_C
#define EXP_C

/**
Q0  OK  1560  exp  :  DA  F  ->  G
G is e (2.718281828...) raised to the Fth power.
*/
void exp_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = exp(node.op == FLOAT_ ? node.u.dbl : (double)node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
