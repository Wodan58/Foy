/*
    module  : sametype.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SAMETYPE_C
#define SAMETYPE_C

/**
Q0  OK  3210  sametype  :  DDA  X Y  ->  B
[EXT] Tests whether X and Y have the same type.
*/
void sametype_(pEnv env)
{
    Node first, second;

    PARM(2, ANYTYPE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    if (first.op == ANON_FUNCT_)
	first.u.num = first.u.proc == second.u.proc;
    else
	first.u.num = first.op == second.op;
    first.op = BOOLEAN_;
    vec_push(env->stack, first);
}
#endif
