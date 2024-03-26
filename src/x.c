/*
    module  : x.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef X_C
#define X_C

/**
Q1  OK  2420  x  :  P  [P] x  ->  ...
Executes P without popping [P]. So, [P] x  ==  [P] P.
*/
void x_(pEnv env)
{
    Node node;

    PARM(1, DIP);
    node = vec_back(env->stack);
    pushcode(env, node.u.lis);
}
#endif
