/*
    module  : gc.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef GC_C
#define GC_C

/**
Q0  IGNORE_OK  3010  gc  :  N  ->
[IMPURE] Initiates garbage collection.
*/
void gc_(pEnv env)
{
    vec_shrink(env->stack);
    vec_shrink(env->code);
    GC_gcollect();
}
#endif
