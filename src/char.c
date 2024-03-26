/*
    module  : char.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CHAR_C
#define CHAR_C

/**
Q0  OK  2320  char  :  DA  X  ->  B
Tests whether X is a character.
*/
void char_(pEnv env)
{
    Node node;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    node.u.num = node.op == CHAR_;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
