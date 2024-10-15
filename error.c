/*
 *  module  : error.c
 *  version : 1.1
 *  date    : 10/11/24
 */
#include "globals.h"

/*
 * print a runtime error to stderr and abort the execution of current program.
 */
void execerror(pEnv env, char *message, char *op)
{
    int leng = 0;
    char *ptr, *str;

    if ((ptr = strrchr(op, '/')) != 0)
	ptr++;
    else
	ptr = op;
    if ((str = strrchr(ptr, '.')) != 0 && str[1] == 'c')
	leng = str - ptr;
    else
	leng = strlen(ptr);
    fflush(stdout);
    fprintf(stderr, "run time error: %s needed for %.*s\n", message, leng, ptr);
    abortexecution_(ABORT_RETRY);
}	/* LCOV_EXCL_LINE */
