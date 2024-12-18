/*
    module  : include.c
    version : 1.3
    date    : 10/11/24
*/
#ifndef INCLUDE_C
#define INCLUDE_C

/**
Q0  OK  3110  include  :  D  "filnam.ext"  ->
Transfers input to file whose name is "filnam.ext".
On end-of-file returns to previous input file.
*/
void include_(pEnv env)
{
    Node node;

    PARM(1, STRTOD);
    node = vec_pop(env->stack);
    if (include(env, node.u.str))
	execerror(env, "valid file name", "include");
}
#endif
