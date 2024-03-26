/*
    module  : iffile.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef IFFILE_C
#define IFFILE_C

/**
Q2  OK  2680  iffile  :  DDDP  X [T] [E]  ->  ...
[FOREIGN] If X is a file, executes T else executes E.
*/
void iffile_(pEnv env)
{
    Node first, second, node;

    PARM(3, WHILE);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    node = vec_back(env->stack);
    node = node.op == FILE_ ? first : second;
    pushcode(env, node.u.lis);
}
#endif
