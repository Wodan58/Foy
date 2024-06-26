/*
    module  : pred.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef PRED_C
#define PRED_C

/**
Q0  OK  1790  pred  :  DA  M  ->  N
Numeric N is the predecessor of numeric M.
*/
void pred_(pEnv env)
{
    Node node;

    PARM(1, PREDSUCC);
    node = vec_pop(env->stack);
    node.u.num--;
    vec_push(env->stack, node);
}
#endif
