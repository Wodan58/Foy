/*
    module  : primrec.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef PRIMREC_C
#define PRIMREC_C

/**
Q2  OK  2820  primrec  :  DDDA  X [I] [C]  ->  R
Executes I to obtain an initial value R0.
For integer X uses increasing positive integers to X, combines by C for new R.
For aggregate X uses successive members and combines by C for new R.
*/
void primrec_(pEnv env)
{
    int64_t j;
    int i, k = 0;
    Node first, second, third, node;

    PARM(3, PRIMREC);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    switch (first.op) {
    case LIST_:
	k = vec_size(first.u.lis);
	for (i = 0; i < k; i++) {
	    node = vec_at(first.u.lis, i);
	    vec_push(env->stack, node);
	}
	break;
 
    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	node.op = CHAR_;
	k = strlen(first.u.str);
	for (i = 0; i < k; i++) {
	    node.u.num = first.u.str[i];
	    vec_push(env->stack, node);
	}
	break;

    case SET_:
	node.op = INTEGER_;
	for (k = 0, j = 1, i = 0; i < SETSIZE; i++, j <<= 1)
	    if (first.u.set & j) {
		node.u.num = i;
		vec_push(env->stack, node);
		k++;
	    }
	break;
 
    case INTEGER_:
	node.op = INTEGER_;
        for (k = i = first.u.num; i > 0; i--) {
	    node.u.num = i;
	    vec_push(env->stack, node);
	}
	break;
    }
    for (i = 0; i < k; i++)
	pushcode(env, third.u.lis);
    pushcode(env, second.u.lis);
}
#endif
