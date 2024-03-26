/*
    module  : cpush.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CPUSH_C
#define CPUSH_C

/**
Q0  OK  3350  #cpush  :  D  ->
Pop the location of an element from the code stack.
Pop an element from the data stack and store it at the given location.
*/
void cpush_(pEnv env)
{
    Node node, jump;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    jump = vec_pop(env->code);
    vec_at(env->code, jump.u.num) = node;	/* write node */
}
#endif
