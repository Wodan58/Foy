/*
    module  : fjump.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FJUMP_C
#define FJUMP_C

/**
Q0  OK  3420  #fjump  :  D  ->
Pop the jump location from the program stack. Pop the top of the data stack.
If the top of the stack was false, jump to the location in the program stack.
*/
void fjump_(pEnv env)
{
    Node test, jump;

    PARM(1, ANYTYPE);
    test = vec_pop(env->stack);
    jump = vec_pop(env->code);
    if (!test.u.num)
	vec_setsize(env->code, jump.u.num);
}
#endif
