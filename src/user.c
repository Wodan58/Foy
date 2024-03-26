/*
    module  : user.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef USER_C
#define USER_C

/**
Q0  OK  2380  user  :  DA  X  ->  B
Tests whether X is a user-defined symbol.
*/
void user_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op == USR_ ||
		 node.op == USR_STRING_ || node.op == USR_LIST_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
