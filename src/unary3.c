/*
    module  : unary3.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef UNARY3_C
#define UNARY3_C

/**
Q1  OK  2510  unary3  :  DDDDAAA  X1 X2 X3 [P]  ->  R1 R2 R3
Executes P three times, with Xi, returns Ri (i = 1..3).
*/
void unary3_(pEnv env)
{	/*	X Y Z [P]  unary3  ==>  X' Y' Z'	*/
    int size1, size2;
    Node param1, param2, list;

    PARM(4, DIP);
    list = vec_pop(env->stack);
    param2 = vec_pop(env->stack);
    param1 = vec_pop(env->stack);

    code(env, rolldown_);

    size2 = vec_size(env->code);	/* location of first Z, then Y' */
    prime(env, param2);			/* first Z, then Y' */

    size1 = vec_size(env->code);	/* location of first Y, then X' */
    prime(env, param1);			/* first Y, then X' */

    /*
	save the stack before the condition and restore it afterwards with
	the condition code included.
    */
    save(env, list.u.lis, 1, 1);
    /*
	Calculate Z' on top of the stack
    */
    pushcode(env, list.u.lis);
    /*
	Push the address of Z
    */
    push(env, size2);
    /*
	Swap Z and Y'
    */
    code(env, cswap_);
    /*
	save the stack before the condition and restore it afterwards with
	the condition code included.
    */
    save(env, list.u.lis, 1, 1);
    /*
	Calculate Y' on top of the stack
    */
    pushcode(env, list.u.lis);
    /*
	Push the address of Y
    */
    push(env, size1);
    /*
	Swap Y and X'
    */
    code(env, cswap_);
    /*
	save the stack before the condition and restore it afterwards with
	the condition code included.
    */
    save(env, list.u.lis, 1, 1);
    /*
	Calculate X' on top of the stack
    */
    pushcode(env, list.u.lis);
}
#endif
