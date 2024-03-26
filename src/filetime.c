/*
    module  : filetime.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FILETIME_C
#define FILETIME_C

#include <sys/stat.h>

/**
Q0  OK  3150  filetime  :  DA  F  ->  T
[FOREIGN] T is the modification time of file F.
*/
void filetime_(pEnv env)
{
    Node node;
    struct stat buf;

    PARM(1, STRTOD);
    node = vec_pop(env->stack);
    if (stat(node.u.str, &buf) == -1)
	node.u.num = 0;
    else
	node.u.num = buf.st_mtime;
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
