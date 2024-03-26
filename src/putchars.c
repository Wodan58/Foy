/*
    module  : putchars.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef PUTCHARS_C
#define PUTCHARS_C

/**
Q0  IGNORE_POP  3100  putchars  :  D  "abc.."  ->
[IMPURE] Writes abc.. (without quotes)
*/
void putchars_(pEnv env)
{
    Node node;

    PARM(1, STRTOD);
    node = vec_pop(env->stack);
    printf("%s", node.u.str);
}
#endif
