/*
    module  : getch.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef GETCH_C
#define GETCH_C

/**
Q0  POSTPONE  3160  getch  :  A  ->  N
[IMPURE] Reads a character from input and puts it onto stack.
*/
void getch_(pEnv env)
{
    Node node;

    node.u.num = getch(env);
    node.op = CHAR_;
    vec_push(env->stack, node);
}
#endif
