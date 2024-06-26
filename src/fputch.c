/*
    module  : fputch.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FPUTCH_C
#define FPUTCH_C

/**
Q0  OK  1950  fputch  :  A  S C  ->  S
[FOREIGN] The character C is written to the current position of stream S.
*/
void fputch_(pEnv env)
{
    Node node, elem;

    PARM(2, FREAD);
    elem = vec_pop(env->stack);
    node = vec_back(env->stack);
    putc(elem.u.num, node.u.fil);
}
#endif
