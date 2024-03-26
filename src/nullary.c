/*
    module  : nullary.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef NULLARY_C
#define NULLARY_C

/**
Q0  OK  2480  nullary  :  DA  [P]  ->  R
Executes P, which leaves R on top of the stack.
No matter how many parameters this consumes, none are removed from the stack.
*/
void nullary_(pEnv env)
{
    Node list;

    PARM(1, DIP);
    /*
	read the program from the stack
    */
    list = vec_pop(env->stack);
    /*
	the old stack is saved and restored with the new top.
    */
    save(env, 0, 0, 0);
    /*
	execute program
    */
    pushcode(env, list.u.lis);
}
#endif
