/*
    module  : round.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ROUND_C
#define ROUND_C

/**
Q0  OK  3200  round  :  DA  F  ->  G
[EXT] G is F rounded to the nearest integer.
*/
double round2(double num)
{
    if (num < 0)
	return -floor(-num + 0.5);
    return floor(num + 0.5);
}

void round_(pEnv env)
{
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    node.u.dbl = round2(node.op == FLOAT_ ? node.u.dbl : node.u.num);
    node.op = FLOAT_;
    vec_push(env->stack, node);
}
#endif
