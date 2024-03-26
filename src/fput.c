/*
    module  : fput.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FPUT_C
#define FPUT_C

/**
Q0  OK  1940  fput  :  D  S X  ->  S
[FOREIGN] Writes X to stream S, pops X off stack.
*/
void fput_(pEnv env)
{
    int stdout_dup;
    Node node, elem;

    PARM(2, FPUT);
    elem = vec_pop(env->stack);
    node = vec_back(env->stack);
    fflush(stdout);
    if ((stdout_dup = dup(1)) != -1)
        dup2(fileno(node.u.fil), 1);
    writefactor(env, elem);
    putchar(' ');
    fflush(stdout);
    if (stdout_dup != -1) {
        dup2(stdout_dup, 1);
        close(stdout_dup);
    }
}
#endif
