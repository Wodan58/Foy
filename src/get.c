/*
    module  : get.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef GET_C
#define GET_C

/**
Q0  POSTPONE  3070  get  :  A  ->  F
[IMPURE] Reads a factor from input and pushes it onto stack.
*/
void get_(pEnv env)
{
    int ch;

    env->getting = 1;
    ch = getch(env);
    ch = getsym(env, ch);
    if (env->sym == USR_)
	env->sym = STRING_;
    ch = readfactor(env, env->stack, ch);
    ungetch(ch);
    env->getting = 0;
}
#endif
