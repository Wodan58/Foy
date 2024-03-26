/*
    module  : unary2.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef UNARY2_C
#define UNARY2_C

/**
Q1  OK  2500  unary2  :  DDDAA  X1 X2 [P]  ->  R1 R2
Executes P twice, with X1 and X2 on top of the stack.
Returns the two values R1 and R2.
*/
void unary2_(pEnv env)
{	/*	Y Z [P]  unary2  ==>  Y' Z'	*/
    int size;
    Node list, node;

    PARM(3, DIP);
    list = vec_pop(env->stack);
    node = vec_pop(env->stack);		/* Z */
    code(env, swap_);
    size = vec_size(env->code);	/* location of first Z, then Y' */
    prime(env, node);		/* first Z, then Y' */
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
    push(env, size);
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
}
#endif
