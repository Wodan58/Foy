/*
    module  : format.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FORMAT_C
#define FORMAT_C

/**
Q0  OK  1760  format  :  DDDDA  N C I J  ->  S
S is the formatted version of N in mode C
('d or 'i = decimal, 'o = octal, 'x or
'X = hex with lower or upper case letters)
with maximum width I and minimum width J.
*/
void format_(pEnv env)
{
    int leng;
    char format[7], *result;
    Node first, second, third, fourth;

    PARM(4, FORMAT);
    fourth = vec_pop(env->stack);	/* min width */
    third = vec_pop(env->stack);	/* max width */
    second = vec_pop(env->stack);	/* mode */
    first = vec_pop(env->stack);	/* number */
    strcpy(format, "%*.*ld");
    format[5] = second.u.num;
    leng = snprintf(0, 0, format, third.u.num, fourth.u.num, first.u.num) + 1;
    result = GC_malloc_atomic(leng + 1);
    snprintf(result, leng, format, third.u.num, fourth.u.num, first.u.num);
    first.u.str = result;
    first.op = STRING_;
    vec_push(env->stack, first);
}
#endif
