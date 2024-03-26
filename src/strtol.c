/*
    module  : strtol.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STRTOL_C
#define STRTOL_C

/**
Q0  OK  1740  strtol  :  DDA  S I  ->  J
String S is converted to the integer J using base I.
If I = 0, assumes base 10,
but leading "0" means base 8 and leading "0x" means base 16.
*/
void strtol_(pEnv env)
{
    Node first, second;

    PARM(2, STRTOL);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    first.u.num = strtol(first.u.str, 0, second.u.num);
    first.op = INTEGER_;
    vec_push(env->stack, first);
}
#endif
