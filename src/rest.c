/*
    module  : rest.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef REST_C
#define REST_C

/**
Q0  OK  2040  rest  :  DA  A  ->  R
R is the non-empty aggregate A with its first member removed.
*/
void rest_(pEnv env)
{
    int i = 0;
    Node node, temp;

    PARM(1, FIRST);
    node = vec_pop(env->stack);
    switch (node.op) {
    case LIST_:
	vec_copy_rest(temp.u.lis, node.u.lis, 1);
	node.u.lis = temp.u.lis;
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	node.u.str = GC_strdup(++node.u.str);  
	break;

    case SET_:
	while (!(node.u.set & ((int64_t)1 << i)))
	    i++;
	node.u.set &= ~((int64_t)1 << i);
	break;
    }
    vec_push(env->stack, node);
}
#endif
