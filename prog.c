/*
    module  : prog.c
    version : 1.1
    date    : 03/21/24
*/
#include "globals.h"

/*
 * pushcode pushes a term onto the code list.
 */
void pushcode(pEnv env, NodeList *term)
{
    vec_copy_reverse(env->code, term);
}

/*
 * code pushes an anonymous function onto the code stack.
 */
void code(pEnv env, proc_t proc)
{
    Node node;

    node.u.proc = proc;
    node.op = ANON_FUNCT_;
    vec_push(env->code, node);
}

/*
 * push an integer on the code stack.
 */
void push(pEnv env, int64_t num)
{
    Node node;

    node.u.num = num;
    node.op = INTEGER_;
    vec_push(env->code, node);
}

/*
 * prime pushes a node on the code stack that came from the data stack.
 */
void prime(pEnv env, Node node)
{
    if (node.op == USR_)
	node.op = USR_PRIME_;
    if (node.op == ANON_FUNCT_)
	node.op = ANON_PRIME_;
    vec_push(env->code, node);
}
