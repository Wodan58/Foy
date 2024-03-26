/*
    module  : treestep.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TREESTEP_C
#define TREESTEP_C

/**
Q1  OK  2870  treestep  :  DDA  T [P]  ->  ...
Recursively traverses leaves of tree T, executes P for each leaf.
*/
void treestep_(pEnv env)
{
    int i, j;
    vector(Node) *tree;
    Node list, node, temp;

    PARM(2, DIP);
    list = vec_pop(env->stack);
    node = vec_pop(env->stack);
    vec_init(tree);
    j = vec_size(node.u.lis);
    for (i = 0; i < j; i++) {
	temp = vec_at(node.u.lis, i);
	vec_push(tree, temp);
    }
    while (vec_size(tree)) {
	node = vec_pop(tree);
	if (node.op == LIST_) {
	    j = vec_size(node.u.lis);
	    for (i = 0; i < j; i++) {
		temp = vec_at(node.u.lis, i);
		vec_push(tree, temp);
	    }
	} else {
	    pushcode(env, list.u.lis);
	    prime(env, node);
	}
    }
}
#endif
