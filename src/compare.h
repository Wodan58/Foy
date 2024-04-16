/*
    module  : compare.h
    version : 1.3
    date    : 04/11/24
*/
#ifndef COMPARE_H
#define COMPARE_H

int is_null(pEnv env, Node node)
{
    switch (node.op) {
    case USR_:
    case USR_PRIME_:
	return !node.u.ent;
    case ANON_FUNCT_:
    case ANON_PRIME_:
	return !node.u.proc;
    case BOOLEAN_:
    case CHAR_:
    case INTEGER_:
	return !node.u.num;
    case SET_:
	return !node.u.set;
    case STRING_:
    case USR_STRING_:
	return !*node.u.str;
    case LIST_:
    case USR_LIST_:
	return !vec_size(node.u.lis);
    case FLOAT_:
	return !node.u.dbl;
    case FILE_:
	return !node.u.fil;
    }
    return 0;
}

/*
    BOOLEAN, CHAR, INTEGER, SET, FLOAT, BIGNUM are lumped together allowing
    numerical compare; USR, ANON_FUNCT, STRING, BIGNUM are lumped together
    allowing string compare; FILE can only be compared with FILE; LISTs can
    be not be compared with anything.
*/
int Compare(pEnv env, Node first, Node second)
{
    FILE *fp1, *fp2;
    char *name1, *name2;
    double dbl1 = 0, dbl2 = 0;
    int64_t num1 = 0, num2 = 0;

    if (is_null(env, first) && is_null(env, second))	/* nothing is unique */
	return 0;
    switch (first.op) {
    case USR_:
    case USR_PRIME_:
	name1 = vec_at(env->symtab, first.u.ent).name;
	switch (second.op) {
	case USR_:
	case USR_PRIME_:
	    name2 = vec_at(env->symtab, second.u.ent).name;
	    goto cmpstr;
	case ANON_FUNCT_:
	case ANON_PRIME_:
	    name2 = cmpname(env, second.u.proc);
	    goto cmpstr;
	case STRING_:
	case BIGNUM_:
	case USR_STRING_:
	    name2 = second.u.str;
	    goto cmpstr;
	default:
	    return 1; /* unequal */
	}
	break;
    case ANON_FUNCT_:
    case ANON_PRIME_:
	name1 = cmpname(env, first.u.proc);
	switch (second.op) {
	case USR_:
	case USR_PRIME_:
	    name2 = vec_at(env->symtab, second.u.ent).name;
	    goto cmpstr;
	case ANON_FUNCT_:
	case ANON_PRIME_:
	    name2 = cmpname(env, second.u.proc);
	    goto cmpstr;
	case STRING_:
	case BIGNUM_:
	case USR_STRING_:
	    name2 = second.u.str;
	    goto cmpstr;
	default:
	    return 1; /* unequal */
	}
	break;
    case BOOLEAN_:
	num1 = first.u.num;
	switch (second.op) {
	case BOOLEAN_:
	case CHAR_:
	case INTEGER_:
	case SET_:
	    num2 = second.u.num;
	    goto cmpnum;
	case FLOAT_:
	    dbl1 = num1;
	    dbl2 = second.u.dbl;
	    goto cmpdbl;
	default:
	    return 1; /* unequal */
	}
	break;
    case CHAR_:
	num1 = first.u.num;
	switch (second.op) {
	case BOOLEAN_:
	case CHAR_:
	case INTEGER_:
	case SET_:
	    num2 = second.u.num;
	    goto cmpnum;
	case FLOAT_:
	    dbl1 = num1;
	    dbl2 = second.u.dbl;
	    goto cmpdbl;
	default:
	    return 1; /* unequal */
	}
	break;
    case INTEGER_:
	num1 = first.u.num;
	switch (second.op) {
	case BOOLEAN_:
	case CHAR_:
	case INTEGER_:
	case SET_:
	    num2 = second.u.num;
	    goto cmpnum;
	case FLOAT_:
	    dbl1 = num1;
	    dbl2 = second.u.dbl;
	    goto cmpdbl;
	default:
	    return 1; /* unequal */
	}
	break;
    case SET_:
	num1 = first.u.num;
	switch (second.op) {
	case BOOLEAN_:
	case CHAR_:
	case INTEGER_:
	case SET_:
	case FLOAT_:
	    num2 = second.u.num;
	    goto cmpnum;
	    break;
	default:
	    return 1; /* unequal */
	}
	break;
    case STRING_:
    case USR_STRING_:
	name1 = first.u.str;
	switch (second.op) {
	case USR_:
	case USR_PRIME_:
	    name2 = vec_at(env->symtab, second.u.ent).name;
	    goto cmpstr;
	case ANON_FUNCT_:
	case ANON_PRIME_:
	    name2 = cmpname(env, second.u.proc);
	    goto cmpstr;
	case STRING_:
	case BIGNUM_:
	case USR_STRING_:
	    name2 = second.u.str;
	    goto cmpstr;
	default:
	    return 1; /* unequal */
	}
	break;
    case FLOAT_:
	dbl1 = first.u.dbl;
	switch (second.op) {
	case BOOLEAN_:
	case CHAR_:
	case INTEGER_:
	    dbl2 = second.u.num;
	    goto cmpdbl;
	case SET_:
	    num1 = first.u.num;
	    num2 = second.u.num;
	    goto cmpnum;
	case FLOAT_:
	    dbl2 = second.u.dbl;
	    goto cmpdbl;
	default:
	    return 1; /* unequal */
	}
	break;
    case FILE_:
	fp1 = first.u.fil;
	switch (second.op) {
	case FILE_:
	    fp2 = second.u.fil;
	    return fp1 < fp2 ? -1 : fp1 > fp2;
	default:
	    return 1; /* unequal */
	}
	break;
    default:
	return 1; /* unequal */
    }
cmpnum:
    return num1 < num2 ? -1 : num1 > num2;
cmpdbl:
    return dbl1 < dbl2 ? -1 : dbl1 > dbl2;
cmpstr:
    num1 = strcmp(name1, name2);
    return num1 < 0 ? -1 : num1 > 0;
}
#endif
