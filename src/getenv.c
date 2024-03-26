/*
    module  : getenv.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef GETENV_C
#define GETENV_C

/**
Q0  OK  3030  getenv  :  DA  "variable"  ->  "value"
Retrieves the value of the environment variable "variable".
*/
void getenv_(pEnv env)
{
    Node node;

    PARM(1, STRTOD);
    node = vec_pop(env->stack);
    if ((node.u.str = getenv(node.u.str)) == 0)
	node.u.str = "";
    vec_push(env->stack, node);
}
#endif
