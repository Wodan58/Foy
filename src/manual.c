/*
    module  : manual.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef MANUAL_C
#define MANUAL_C

#include "manual.h"

/**
Q0  IGNORE_OK  2930  manual  :  N  ->
[IMPURE] Writes this manual of all Joy primitives to output file.
*/
void manual_(pEnv env)
{
    make_manual(0);
}
#endif
