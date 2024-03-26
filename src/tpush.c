/*
    module  : tpush.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef TPUSH_C
#define TPUSH_C

/**
Q0  OK  3410  #tpush  :  D  ->
Pop the location of two aggregates and an element from the program stack.
The element is added to one of the two aggregates, depending on the value
on top of the data stack.
*/
void tpush_(pEnv env)
{
    int i;
    Node test, jump, elem, node;

    PARM(1, ANYTYPE);
    test = vec_pop(env->stack);
    jump = vec_pop(env->code);
    elem = vec_pop(env->code);
    if (test.u.num)
	node = vec_at(env->code, jump.u.num + 1);
    else
	node = vec_at(env->code, jump.u.num);	/* one step further away */
    switch (node.op) {
    case LIST_:
	vec_push(node.u.lis, elem);
	break;

    case STRING_:
    case BIGNUM_:
    case USR_STRING_:
	i = strlen(node.u.str);
	node.u.str[i++] = elem.u.num;
	node.u.str[i] = 0;
	break;

    case SET_:
	node.u.set |= ((int64_t)1 << elem.u.num);
	break;
    }
    if (test.u.num)
	vec_at(env->code, jump.u.num + 1) = node;	/* write node */
    else
	vec_at(env->code, jump.u.num) = node;		/* write node */
}
#endif
