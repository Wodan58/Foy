/*
    module  : case.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CASE_C
#define CASE_C

#include "compare.h"

/**
Q1  OK  2100  case  :  DP  X [..[X Y]..]  ->  Y i
Indexing on the value of X, execute the matching Y.
*/
void case_(pEnv env)
{
    int i, j;
    Node aggr, node, elem, temp;

    PARM(2, CASE);
    aggr = vec_pop(env->stack);
    node = vec_back(env->stack);
    j = vec_size(aggr.u.lis);
    for (i = 0; i < j; i++) {
	elem = vec_at(aggr.u.lis, i);
	if (i == j - 1) {
	    node = elem;
	    break;
	}
	temp = vec_at(elem.u.lis, 0);
	if (!Compare(env, node, temp)) {
	    vec_copy_rest(node.u.lis, elem.u.lis, 1);
	    (void)vec_pop(env->stack);
	    break;
	}
    }
    pushcode(env, node.u.lis);
}
#endif
