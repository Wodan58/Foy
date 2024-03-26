/*
    module  : __dump.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef __DUMP_C
#define __DUMP_C

/**
Q0  OK  1070  __dump  :  A  ->  [..]
debugging only: pushes the dump as a list.
*/
void __dump_(pEnv env)
{
    Node node;

    node.u.num = 0;
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
