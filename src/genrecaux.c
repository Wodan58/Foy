/*
    module  : genrecaux.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef GENRECAUX_C
#define GENRECAUX_C

/**
Q1  OK  3290  #genrec  :  DDDDDA  [[B] [T] [R1] R2]  ->  ...
Executes B, if that yields true, executes T.
Else executes R1 and then [[[B] [T] [R1] R2] genrec] R2.
*/
void genrecaux_(pEnv env)
{
    int i, size1, size2;
    Node first, second, third, aggr, node, temp;

    PARM(1, DIP);
    aggr = vec_pop(env->stack);		/* item on top of the stack */
    first = vec_at(aggr.u.lis, 0);	/* [B] */
    second = vec_at(aggr.u.lis, 1);	/* [T] */
    third = vec_at(aggr.u.lis, 2);	/* [R1] */
    /*
	record the jump location after the false branch
    */
    size2 = vec_size(env->code);
    /*
	push R2, excluding [B], [T], [R1]
    */
    for (i = vec_size(aggr.u.lis) - 1; i > 2; i--) {
	temp = vec_at(aggr.u.lis, i);
	vec_push(env->code, temp);
    }

    code(env, cons_);		/* build [[[B] [T] [R1] R2] genrecaux_] */
    code(env, cons_);		/* build [genrecaux_] */

    vec_init(node.u.lis);	/* [] */
    node.op = LIST_;
    prime(env, node);

    node.u.proc = genrecaux_;
    node.op = ANON_PRIME_;
    prime(env, node);
    /*
	push the item that was on top of the stack
    */
    prime(env, aggr);
    /*
	push R1
    */
    pushcode(env, third.u.lis);
    /*
	record the jump location before the false branch
    */
    size1 = vec_size(env->code);
    /*
	push the jump address onto the program stack
    */
    push(env, size2);
    /*
	jump after the false branch of genrec
    */
    code(env, jump_);
    /*
	push the true branch of genrec
    */
    pushcode(env, second.u.lis);
    /*
	push the jump address onto the program stack
    */
    push(env, size1);
    /*
	jump on false before the false branch
    */
    code(env, fjump_);
    /*
	save the stack before the condition and restore it afterwards with the
	condition code included.
    */
    save(env, first.u.lis, 0, 0);
    /*
	push the test of genrec
    */
    pushcode(env, first.u.lis);
}
#endif
