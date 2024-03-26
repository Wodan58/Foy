/*
    module  : stack.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef STACK_C
#define STACK_C

/**
Q0  OK  1040  stack  :  A  .. X Y Z  ->  .. X Y Z [Z Y X ..]
Pushes the stack as a list.
*/
void stack_(pEnv env)
{
    Node node;

    vec_init(node.u.lis);
    vec_grow(node.u.lis, vec_size(env->stack));
    vec_copy_reverse(node.u.lis, env->stack);
    node.op = LIST_;
    vec_push(env->stack, node);
}
#endif
