/*
    module  : put.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef PUT_C
#define PUT_C

/**
Q0  IGNORE_POP  3080  put  :  D  X  ->
[IMPURE] Writes X to output, pops X off stack.
*/
void put_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    writefactor(env, node);
#if 0
    putchar(' ');
#endif
}
#endif
