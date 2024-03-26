/*
    module  : size.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef SIZE_C
#define SIZE_C

/**
Q0  OK  2080  size  :  DA  A  ->  I
Integer I is the number of elements of aggregate A.
*/
void size_(pEnv env)
{
    int i;
    Node node;
    int64_t j, set;

    PARM(1, SIZE_);
    node = vec_pop(env->stack);
    switch (node.op) {
    case LIST_:
	node.u.num = vec_size(node.u.lis);
	break;
    case STRING_:
    case BIGNUM_:
	node.u.num = strlen(node.u.str);
	break;
    case SET_:
	set = node.u.set;
	node.u.num = 0;
	for (j = 1, i = 0; i < SETSIZE; i++, j <<= 1)
	    if (set & j)
		node.u.num++;
	break;
    }
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
