/*
    module  : name.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef NAME_C
#define NAME_C

/**
Q0  OK  2170  name  :  DA  sym  ->  "sym"
For operators and combinators, the string "sym" is the name of item sym,
for literals sym the result string is its type.
*/
void name_(pEnv env)
{
    Node node;
    int index;

    PARM(1, ANYTYPE);
    node = vec_pop(env->stack);
    if (node.op == USR_)
	index = node.u.ent;
    else if (node.op == ANON_FUNCT_)
	index = operindex(env, node.u.proc);
    else
	index = node.op;
    node.u.str = vec_at(env->symtab, index).name;
    node.op = STRING_;
    vec_push(env->stack, node);
}
#endif
