/*
    module  : pick.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef PICK_C
#define PICK_C

/**
Q0  OK  3180  pick  :  DA  X Y Z 2  ->  X Y Z X
[EXT] Pushes an extra copy of nth (e.g. 2) item X on top of the stack.
*/
void pick_(pEnv env)
{
    int size;
    Node node;

    PARM(1, UNMKTIME);
    node = vec_pop(env->stack);
    size = vec_size(env->stack);
    if (node.u.num < size)
	node = vec_at(env->stack, size - node.u.num - 1);
    else
	node = vec_at(env->stack, 0);
    vec_push(env->stack, node);
}
#endif
