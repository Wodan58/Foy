/*
    module  : chr.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef CHR_C
#define CHR_C

/**
Q0  OK  1470  chr  :  DA  I  ->  C
C is the character whose Ascii value is integer I (or logical or character).
*/
void chr_(pEnv env)
{
    Node node;

    PARM(1, PREDSUCC);
    node = vec_pop(env->stack);
    node.op = CHAR_;
    vec_push(env->stack, node);
}
#endif
