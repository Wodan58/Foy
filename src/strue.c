/*
    module  : strue.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STRUE_C
#define STRUE_C

/**
Q0  OK  3400  #strue  :  N  ->
Pop the jump location from the program stack. If the top of the data stack
is true, jump to that location.
*/
void strue_(pEnv env)
{
    Node test, jump;

    PARM(1, ANYTYPE);
    test = vec_pop(env->stack);
    jump = vec_pop(env->code);
    if (test.u.num) {
	vec_setsize(env->code, jump.u.num);
	code(env, true_);
    }
}
#endif
