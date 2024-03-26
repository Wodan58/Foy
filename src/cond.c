/*
    module  : cond.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef COND_C
#define COND_C

/**
Q1  OK  2690  cond  :  DDA  [..[[Bi] Ti]..[D]]  ->  ...
Tries each Bi. If that yields true, then executes Ti and exits.
If no Bi yields true, executes default D.
*/
void cond_(pEnv env)
{
    int i, size1, size2;
    Node aggr, elem, node;

    PARM(1, CASE);
    aggr = vec_pop(env->stack);
    /*
	jump address past last cond line
    */
    size2 = vec_size(env->code);
    /*
	the last cond line comes without test and no jump is needed
    */
    elem = vec_back(aggr.u.lis);
    pushcode(env, elem.u.lis);
    for (i = vec_size(aggr.u.lis) - 2; i >= 0; i--) {
	/*
	    jump address to the next cond line
	*/
	size1 = vec_size(env->code);
	/*
	    read a cond line
	*/
	elem = vec_at(aggr.u.lis, i);
	/*
	    push the jump address onto the program stack
	*/
	push(env, size2);
	/*
	    jump after executing the rest of the cond line
	*/
	code(env, jump_);
	/*
	    push the rest of the cond line
	*/
	pushcode(env, elem.u.lis);
	node = vec_pop(env->code);
	/*
	    push the jump address onto the program stack
	*/
	push(env, size1);
	/*
	    jump on false to the next cond line; remove condition code
	*/
	code(env, pfalse_);
	/*
	    save the stack before the condition and restore it afterwards with
	    the condition code included.
	*/
	save(env, node.u.lis, 0, 0);
	/*
	    push the test of the cond line
	*/
	pushcode(env, node.u.lis);
    }
}
#endif
