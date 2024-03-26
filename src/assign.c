/*
    module  : assign.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef ASSIGN_C
#define ASSIGN_C

/**
Q0  IGNORE_POP  3190  assign  :  DD  V [N]  ->
[IMPURE] Assigns value V to the variable with name N.
*/
void assign_(pEnv env)
{
    Node node;
    int index;
    Entry ent;

    PARM(2, ASSIGN);			/* quotation on top */
    node = vec_pop(env->stack);		/* singleton list */
    node = vec_at(node.u.lis, 0);	/* first/last element */
    index = node.u.ent;			/* index user defined name */
    ent = vec_at(env->symtab, index);	/* symbol table entry */
    node = vec_pop(env->stack);		/* value */
    ent.is_user = 1;			/* ensure again user defined */
    vec_init(ent.u.body);		/* (re)initialise body */
    vec_push(ent.u.body, node);		/* insert value in body */
    vec_at(env->symtab, index) = ent;	/* update symbol table */
}
#endif
