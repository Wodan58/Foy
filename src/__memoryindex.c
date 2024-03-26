/*
    module  : __memoryindex.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef __MEMORYINDEX_C
#define __MEMORYINDEX_C

/**
Q0  OK  3060  __memoryindex  :  A  ->  I
Pushes current value of memory.
*/
void __memoryindex_(pEnv env)
{
    Node node;

    node.u.num = GC_get_memory_use();
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
