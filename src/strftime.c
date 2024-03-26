/*
    module  : strftime.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STRFTIME_C
#define STRFTIME_C

#include "decode.h"

/**
Q0  OK  1730  strftime  :  DDA  T S1  ->  S2
Formats a list T in the format of localtime or gmtime
using string S1 and pushes the result S2.
*/
void strftime_(pEnv env)
{
    struct tm t;
    Node first, second;

    PARM(2, STRFTIME);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    decode(first, &t);
    first.u.str = GC_malloc_atomic(INPLINEMAX);
    strftime(first.u.str, INPLINEMAX, second.u.str, &t);
    first.op = STRING_;
    vec_push(env->stack, first);
}
#endif
