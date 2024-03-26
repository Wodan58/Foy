/*
    module  : jfalse.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef JFALSE_C
#define JFALSE_C

/**
Q0  OK  3390  #jfalse  :  N  ->
Pop the jump location from the program stack. If the top of the data stack
is false, jump to that location.
*/
void jfalse_(pEnv env)
{
    Node test, jump;

    PARM(1, ANYTYPE);
    test = vec_pop(env->stack);
    jump = vec_pop(env->code);
    if (test.u.num != 1) {
	vec_setsize(env->code, jump.u.num);
	code(env, false_);
    }
}
#endif
