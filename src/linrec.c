/*
    module  : linrec.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef LINREC_C
#define LINREC_C

/**
Q4  OK  2710  linrec  :  DDDDDA  [P] [T] [R1] [R2]  ->  ...
Executes P. If that yields true, executes T.
Else executes R1, recurses, executes R2.
*/
void linrec_(pEnv env)
{
    int size1, size2;
    Node first, second, third, fourth;

    PARM(4, LINREC);
    fourth = vec_pop(env->stack);
    third = vec_pop(env->stack);
    second = vec_pop(env->stack);
    first = vec_pop(env->stack);
    /*
	register the return address
    */
    size2 = vec_size(env->code);
    /*
	execute R2 after returning from the recursion
    */
    pushcode(env, fourth.u.lis);
    /*
	setup the continuation
    */
    code(env, linrec_);
    prime(env, fourth);
    prime(env, third);
    prime(env, second);
    prime(env, first);
    /*
	push the R1 branch of linrec
    */
    pushcode(env, third.u.lis);
    /*
	register the target location for the false branch
    */
    size1 = vec_size(env->code);
    /*
	push the jump address onto the program stack
    */
    push(env, size2);
    /*
	skip the false branch of linrec
    */
    code(env, jump_);
    /*
	push the true branch of linrec
    */
    pushcode(env, second.u.lis);
    /*
	push the jump address onto the program stack
    */
    push(env, size1);
    /*
	jump on false past the true branch of linrec
    */
    code(env, fjump_);
    /*
	save the stack before the condition and restore it afterwards with
	the condition code included.
    */
    save(env, first.u.lis, 0, 0);
    /*
	push the test of linrec
    */
    pushcode(env, first.u.lis);
}
#endif
