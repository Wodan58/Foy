/*
    module  : ifchar.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFCHAR_C
#define IFCHAR_C

/**
Q2  OK  2620  ifchar  :  DDDP  X [T] [E]  ->  ...
If X is a character, executes T else executes E.
*/
void ifchar_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == CHAR_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
