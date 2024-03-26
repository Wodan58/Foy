/*
    module  : or.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef OR_C
#define OR_C

/**
Q0  OK  1340  or  :  DDA  X Y  ->  Z
Z is the union of sets X and Y, logical disjunction for truth values.
*/
void or_(pEnv env)
{
    Node first, second;

    PARM(2, ANDORXOR);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    switch (first.op) {
    case SET_:
	first.u.set = first.u.set | second.u.set;
	break;
    case BOOLEAN_:
    case CHAR_:
    case INTEGER_:
	first.u.num = first.u.num || second.u.num;
	first.op = BOOLEAN_;
	break;
    }
    vec_push(env->stack, first);
}
#endif
