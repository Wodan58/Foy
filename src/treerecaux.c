/*
    module  : treerecaux.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TREERECAUX_C
#define TREERECAUX_C

/**
Q1  OK  3310  #treerec  :  DDDDA  T [[O] C]  ->  ...
T is a tree. If T is a leaf, executes O. Else executes [[[O] C] treerec] C.
*/
void treerecaux_(pEnv env)
{
    Node list, node;

    PARM(2, DIP);
    list = vec_pop(env->stack);		/* item on top of the stack */
    node = vec_back(env->stack);	/* 2nd item on the stack */
    if (node.op == LIST_) {		/* list = [[O] C] */

	pushcode(env, list.u.lis);	/* C */
	(void)vec_pop(env->code);

	code(env, cons_);		/* [[O] C] treerecaux] */
	code(env, cons_);		/* [treerecaux] */

	vec_init(node.u.lis);		/* [] */
	prime(env, node);

	node.u.proc = treerecaux_;
	node.op = ANON_PRIME_;
	prime(env, node);

	prime(env, list);		/* list = [[O] C] */
    } else {
	list = vec_at(list.u.lis, 0);	/* list = [O] */
	pushcode(env, list.u.lis);
    }
}
#endif
