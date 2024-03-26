/*
    module  : all.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ALL_C
#define ALL_C

/**
Q1  OK  2860  all  :  DDA  A [B]  ->  X
Applies test B to members of aggregate A, X = true if all pass.
*/
void all_(pEnv env)
{
    int64_t j;
    int i, size;
    Node aggr, list, node;

    PARM(2, STEP);
    size = vec_size(env->code);
    /*
	if all tests pass, the result will be true.
    */
    code(env, true_);
    list = vec_pop(env->stack);
    aggr = vec_pop(env->stack);
    switch (aggr.op) {
    case LIST_:
	for (i = 0, j = vec_size(aggr.u.lis); i < j; i++) {
	    /*
		push the location of the result type
	    */
	    push(env, size);
	    /*
		add an instruction that builds the result type
	    */
	    code(env, jfalse_);
	    /*
		save and restore the stack, if needed
	    */
	    save(env, list.u.lis, 1, 0);
	    /*
		push the program to be executed for each element
	    */
	    pushcode(env, list.u.lis);
	    /*
		push the element to be mapped
	    */
	    node = vec_at(aggr.u.lis, i);
	    prime(env, node);
	}
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	node.op = CHAR_;
	for (i = strlen(aggr.u.str) - 1; i >= 0; i--) {
	    /*
		push the location of the result type
	    */
	    push(env, size);
	    /*
		add an instruction that builds the result type
	    */
	    code(env, jfalse_);
	    /*
		save and restore the stack, if needed
	    */
	    save(env, list.u.lis, 1, 0);
	    /*
		push the program to be executed for each element
	    */
	    pushcode(env, list.u.lis);
	    /*
		push the element to be mapped
	    */
	    node.u.num = aggr.u.str[i];
	    prime(env, node);
	}
	break;

    case SET_:
	node.op = INTEGER_;
	for (j = 1, i = 0; i < SETSIZE; i++, j <<= 1)
	    if (aggr.u.set & j) {
		/*
		    push the location of the result type
		*/
		push(env, size);
		/*
		    add an instruction that builds the result type
		*/
		code(env, jfalse_);
		/*
		    save and restore the stack, if needed
		*/
		save(env, list.u.lis, 1, 0);
		/*
		    push the program to be executed for each element
		*/
		pushcode(env, list.u.lis);
		/*
		    push the element to be mapped
		*/
		node.u.num = i;
		prime(env, node);
	    }
	break;
    }
}
#endif
