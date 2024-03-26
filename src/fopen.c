/*
    module  : fopen.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FOPEN_C
#define FOPEN_C

/**
Q0  OK  1890  fopen  :  DDA  P M  ->  S
[FOREIGN] The file system object with pathname P is opened with mode M
(r, w, a, etc.) and stream object S is pushed; if the open fails, file:NULL
is pushed.
*/
void fopen_(pEnv env)
{
    Node path, mode;

    PARM(2, FOPEN);
    mode = vec_pop(env->stack);
    path = vec_pop(env->stack);
    path.u.fil = fopen(path.u.str, mode.u.str);
    path.op = FILE_;
    vec_push(env->stack, path);
}
#endif
