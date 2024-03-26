/*
    module  : fremove.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FREMOVE_C
#define FREMOVE_C

/**
Q0  OK  1920  fremove  :  DA  P  ->  B
[FOREIGN] The file system object with pathname P is removed from the file
system. B is a boolean indicating success or failure.
*/
void fremove_(pEnv env)
{
    Node node;

    PARM(1, STRTOD);
    node = vec_pop(env->stack);
    node.u.num = !remove(node.u.str);
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
