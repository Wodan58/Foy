/*
    module  : frexp.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FREXP_C
#define FREXP_C

/**
Q0  OK  1580  frexp  :  DAA  F  ->  G I
G is the mantissa and I is the exponent of F.
Unless F = 0, 0.5 <= abs(G) < 1.0.
*/
void frexp_(pEnv env)
{
    int exp;
    Node node;

    PARM(1, UFLOAT);
    node = vec_pop(env->stack);
    if (node.op != FLOAT_) {
	node.u.dbl = node.u.num;
	node.op = FLOAT_;
    }
    node.u.dbl = frexp(node.u.dbl, &exp);
    vec_push(env->stack, node);
    node.u.num = exp;
    node.op = INTEGER_;
    vec_push(env->stack, node);
}
#endif
