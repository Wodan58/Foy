/*
    module  : div.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef DIV_C
#define DIV_C

/**
Q0  OK  1430  div  :  DDAA  I J  ->  K L
Integers K and L are the quotient and remainder of dividing I by J.
*/
void div_(pEnv env)
{
    lldiv_t result;
    Node first, second;

    PARM(2, DIV);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    result = lldiv(first.u.num, second.u.num);
    first.u.num = result.quot;
    vec_push(env->stack, first);
    first.u.num = result.rem;
    vec_push(env->stack, first);
}
#endif
