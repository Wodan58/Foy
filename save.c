/*
    module  : save.c
    version : 1.2
    date    : 10/15/24
*/
#include "globals.h"
#include "builtin.h"

/*
 * Save the stack just before executing a program. Restore it afterwards
 * without num items and including the new top of the stack.
 */
void save(pEnv env, NodeList *list, int num, int remove)
{
    Node node;
    int status;

    if (!list)
	goto done;
    /*
     * If the status is UNKNOWN, it needs to be calculated. Once calculated,
     * it is either OK or NOT_OK. In both cases, the status is KNOWN and need
     * not be calculated again. In case it is NOT_OK, the entire stack needs
     * to be saved and restored.
     */
    if ((status = vec_getarity(list)) == ARITY_UNKNOWN) {
	status = arity(env, list, num) == 1 ? ARITY_OK : ARITY_NOT_OK;
	if (env->overwrite) {
	    printf("%s: (", status == ARITY_OK ? "info" : "warning");
	    writeterm(env, list);
	    printf(") has %scorrect arity\n", status == ARITY_OK ?  "" : "in");
	}
    }
    vec_setarity(list, status);
    if (status == ARITY_NOT_OK) {
done:
	/*
	    replace the new stack with the old stack
	*/
	code(env, unstack_);		/* the stack is restored with result */
	/*
	    include the test result in the old stack
	*/
	code(env, cons_);
	/*
	    remove remove items from the old stack
	*/
	while (remove--)
	    code(env, rest_);
	/*
	    restore the old stack after the test
	*/
	vec_init(node.u.lis);
	vec_copy_reverse(node.u.lis, env->stack);	/* save the stack */
	node.op = LIST_;
	prime(env, node);
    }
}
