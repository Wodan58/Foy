/*
    module  : fseek.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FSEEK_C
#define FSEEK_C

/**
Q0  OK  1980  fseek  :  DDA  S P W  ->  S B
[FOREIGN] Stream S is repositioned to position P relative to whence-point W,
where W = 0, 1, 2 for beginning, current position, end respectively.
*/
void fseek_(pEnv env)
{
    Node node, locat, orien;

    PARM(3, FSEEK);
    orien = vec_pop(env->stack);
    locat = vec_pop(env->stack);
    node = vec_back(env->stack);
    node.u.num = fseek(node.u.fil, locat.u.num, orien.u.num) != 0;
    node.op = BOOLEAN_;
    vec_push(env->stack, node);
}
#endif
