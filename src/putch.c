/*
    module  : putch.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef PUTCH_C
#define PUTCH_C

/**
Q0  OK  3090  putch  :  D  N  ->
[IMPURE] N : numeric, writes character whose ASCII is N.
*/
void putch_(pEnv env)
{
    Node node;

    PARM(1, PREDSUCC);
    node = vec_pop(env->stack);
    putchar(node.u.num);
}
#endif
