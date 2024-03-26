/*
    module  : fread.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef FREAD_C
#define FREAD_C

/**
Q0  OK  1900  fread  :  DA  S I  ->  S L
[FOREIGN] I bytes are read from the current position of stream S
and returned as a list of I integers.
*/
void fread_(pEnv env)
{
    int i, count;
    Node node, elem;
    unsigned char *buf;

    PARM(2, FREAD);
    node = vec_pop(env->stack);
    count = node.u.num;
    node = vec_back(env->stack);
    buf = GC_malloc_atomic(count);
    count = fread(buf, 1, count, node.u.fil);
    vec_init(node.u.lis);
    elem.op = INTEGER_;
    for (i = 0; i < count; i++) {
	elem.u.num = buf[i];
	vec_push(node.u.lis, elem);
    }
    node.op = LIST_;
    vec_push(env->stack, node);
}
#endif
