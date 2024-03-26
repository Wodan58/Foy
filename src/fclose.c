/*
    module  : fclose.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FCLOSE_C
#define FCLOSE_C

/**
Q0  OK  1830  fclose  :  D  S  ->
[FOREIGN] Stream S is closed and removed from the stack.
*/
void fclose_(pEnv env)
{
    Node node;

    PARM(1, FGET);
    node = vec_pop(env->stack);
    fclose(node.u.fil);
}
#endif
