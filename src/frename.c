/*
    module  : frename.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FRENAME_C
#define FRENAME_C

/**
Q0  OK  1930  frename  :  DDA  P1 P2  ->  B
[FOREIGN] The file system object with pathname P1 is renamed to P2.
B is a boolean indicating success or failure.
*/
void frename_(pEnv env)
{
    Node node, path;

    PARM(2, FOPEN);
    path = vec_pop(env->stack);
    node = vec_pop(env->stack);
    node.u.num = !rename(node.u.str, path.u.str);
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
