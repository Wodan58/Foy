/*
    module  : cswap.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CSWAP_C
#define CSWAP_C

/**
Q0  OK  3330  #cswap  :  N  ->
Pop the location of an element from the code stack.
Swap that element with the top of the data stack.
*/
void cswap_(pEnv env)
{
    Node node, jump, elem;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    jump = vec_pop(env->code);
    elem = vec_at(env->code, jump.u.num);
    vec_at(env->code, jump.u.num) = node;	/* write node */
    vec_push(env->stack, elem);
}
#endif
