/*
    module  : typeof.c
    version : 1.2
    date    : 06/22/24
*/
#ifndef TYPEOF_C
#define TYPEOF_C

/**
Q0  OK  3220  typeof  :  DA  X  ->  I
[EXT] Replace X by its type.
*/
void typeof_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op;
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
