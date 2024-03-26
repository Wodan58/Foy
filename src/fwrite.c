/*
    module  : fwrite.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FWRITE_C
#define FWRITE_C

/**
Q0  OK  1910  fwrite  :  D  S L  ->  S
[FOREIGN] A list of integers are written as bytes to the current position of
stream S.
*/
void fwrite_(pEnv env)
{
    int i, j;
    unsigned char *buf;
    Node node, elem, temp;

    PARM(2, FWRITE);
    elem = vec_pop(env->stack);
    node = vec_back(env->stack);
    j = vec_size(elem.u.lis);
    buf = GC_malloc_atomic(j);
    for (i = 0; i < j; i++) {
	temp = vec_at(elem.u.lis, i);
	buf[i] = temp.u.num;
    }
    fwrite(buf, 1, j, node.u.fil);
}
#endif
