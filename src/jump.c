/*
    module  : jump.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef JUMP_C
#define JUMP_C

/**
Q0  OK  3320  #jump  :  N  ->
Pop the jump location from the program stack. Jump to that location.
*/
void jump_(pEnv env)
{
    Node jump;

    jump = vec_pop(env->code);
    vec_setsize(env->code, jump.u.num);
}
#endif
