/*
    module  : some.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SOME_C
#define SOME_C

/**
Q1  OK  2850  some  :  DDA  A [B]  ->  X
Applies test B to members of aggregate A, X = true if some pass.
*/
void some_(pEnv env)
{
    int64_t j;
    int i, size;
    Node aggr, list, node;

    PARM(2, STEP);
    size = vec_size(env->code);
    /*
	if no test passes, the result will be false.
    */
    code(env, false_);
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
	    code(env, strue_);
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
	    code(env, strue_);
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
		code(env, strue_);
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
