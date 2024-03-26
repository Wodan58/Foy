/*
    module  : opcase.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef OPCASE_C
#define OPCASE_C

/**
Q0  OK  2090  opcase  :  DA  X [..[X Xs]..]  ->  X [Xs]
Indexing on type of X, returns the list [Xs].
*/
void opcase_(pEnv env)
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
	if (node.op == temp.op) {
	    if (node.op == ANON_FUNCT_)
		if (node.u.proc != temp.u.proc)
		    continue;
	    vec_copy_rest(node.u.lis, elem.u.lis, 1);
	    node.op = LIST_;
	    break;
	}
    }
    vec_push(env->stack, node);
}
#endif
