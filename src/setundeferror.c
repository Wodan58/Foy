/*
    module  : setundeferror.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SETUNDEFERROR_C
#define SETUNDEFERROR_C

/**
Q0  IGNORE_POP  2990  setundeferror  :  D  I  ->
[IMPURE] Sets flag that controls behavior of undefined functions
(0 = no error, 1 = error).
*/
void setundeferror_(pEnv env)
{
    Node node;

    PARM(1, PREDSUCC);
    node = vec_pop(env->stack);
    if (!env->undeferror_set)
	env->undeferror = node.u.num;
}
#endif
