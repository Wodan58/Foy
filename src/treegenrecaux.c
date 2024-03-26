/*
    module  : treegenrecaux.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TREEGENRECAUX_C
#define TREEGENRECAUX_C

/**
Q1  OK  3300  #treegenrec  :  DDDDDA  T [[O1] [O2] C]  ->  ...
T is a tree. If T is a leaf, executes O1.
Else executes O2 and then [[[O1] [O2] C] treegenrec] C.
*/
void treegenrecaux_(pEnv env)
{
    Node list, node;

    PARM(1, DIP);
    list = vec_pop(env->stack);		/* item on top of the stack */
    node = vec_back(env->stack);	/* 2nd item on the stack */
    if (node.op == LIST_) {		/* list = [[O1] [O2] C] */
	pushcode(env, list.u.lis);	/* C */
	(void)vec_pop(env->code);
	(void)vec_pop(env->code);

	code(env, cons_);		/* [[[O1] [O2] C] treegenrecaux] */
	code(env, cons_);		/* [treegenrecaux] */

	vec_init(node.u.lis);		/* [] */
	prime(env, node);

	node.u.proc = treegenrecaux_;
	node.op = ANON_PRIME_;
	prime(env, node);

	vec_push(env->code, list);	/* list = [[O1] [O2] C] */
	list = vec_at(list.u.lis, 1);	/* list = [O2] */
	pushcode(env, list.u.lis);
    } else {				/* list = [[O1] [O2] C] */
	list = vec_at(list.u.lis, 0);	/* list = [O1] */
	pushcode(env, list.u.lis);
    }
}
#endif
