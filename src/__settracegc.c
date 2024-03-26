/*
    module  : __settracegc.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef __SETTRACEGC_C
#define __SETTRACEGC_C

/**
Q0  OK  2970  __settracegc  :  D  I  ->
[IMPURE] Sets value of flag for tracing garbage collection to I (= 0..6).
*/
void __settracegc_(pEnv env)
{
    Node node;

    PARM(1, PREDSUCC);
    node = vec_pop(env->stack);
    env->tracegc = node.u.num;
}
#endif
