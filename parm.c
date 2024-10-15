/*
    module  : parm.c
    version : 1.8
    date    : 10/11/24
*/
#include "globals.h"

/*
 * check the number of parameters and if not sufficient call execerror.
 */
static void checknum(pEnv env, int num, int leng, char *file)
{
    char *ptr = 0;

    if (num > leng)
	switch (num) {
	case 1: ptr = "one parameter";
		break;
	case 2: ptr = "two parameters";
		break;
	case 3: ptr = "three parameters";
		break;
	case 4: ptr = "four parameters";
		break;
	case 5: ptr = "five parameters";
		break;
	}
    if (ptr)
	execerror(env, ptr, file);
}

/*
 * check parameters, all of them
 */
void parm(pEnv env, int num, Params type, char *file)
{
    int i, j;
    unsigned leng;
    Node first, second, third, fourth;

    leng = vec_size(env->stack);
    checknum(env, num, leng, file);
/*
 * check number and type of parameters:
 */
    switch (type) {
    case ANYTYPE:
	break;
/*
 * one quote is needed:
 */
    case DIP:
	first = vec_back(env->stack);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	break;
/*
 * two quotes are needed:
 */
    case WHILE:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	if (second.op != LIST_)
	    execerror(env, "quotation as second parameter", file);
	break;
/*
 * three quotes are needed:
 */
    case IFTE:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	third = vec_at(env->stack, leng - 3);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	if (second.op != LIST_)
	    execerror(env, "quotation as second parameter", file);
	if (third.op != LIST_)
	    execerror(env, "quotation as third parameter", file);
	break;
/*
 * four quotes are needed:
 */
    case LINREC:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	third = vec_at(env->stack, leng - 3);
	fourth = vec_at(env->stack, leng - 4);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	if (second.op != LIST_)
	    execerror(env, "quotation as second parameter", file);
	if (third.op != LIST_)
	    execerror(env, "quotation as third parameter", file);
	if (fourth.op != LIST_)
	    execerror(env, "quotation as fourth parameter", file);
	break;
/*
 * list is needed:
 */
    case HELP:
	first = vec_back(env->stack);
	if (first.op != LIST_)
	    execerror(env, "list", file);
	break;
/*
 * list is needed as second parameter:
 */
    case INFRA:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	if (second.op != LIST_)
	    execerror(env, "list as second parameter", file);
	break;
/*
 * float or integer is needed:
 */
    case UFLOAT:
	first = vec_back(env->stack);
	if (first.op != FLOAT_ && first.op != INTEGER_)
	    execerror(env, "float or integer", file);
	break;
/*
 * two floats or integers are needed:
 */
    case MUL:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != BIGNUM_ && first.op != FLOAT_ && first.op != INTEGER_)
	    execerror(env, "float or (big)integer", file);
	if (second.op != BIGNUM_ && second.op != FLOAT_ &&
	    second.op != INTEGER_)
	    execerror(env, "two floats or (big)integers", file);
	break;
/*
 * two floats or integers are needed:
 */
    case BFLOAT:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != FLOAT_ && first.op != INTEGER_)
	    execerror(env, "float or integer", file);
	if (second.op != FLOAT_ && second.op != INTEGER_)
	    execerror(env, "two floats or integers", file);
	break;
/*
 * file is needed:
 */
    case FGET:
	first = vec_back(env->stack);
	if (first.op != FILE_ || !first.u.fil)
	    execerror(env, "file", file);
	break;
/*
 * file is needed as second parameter:
 */
    case FPUT:
	second = vec_at(env->stack, leng - 2);
	if (second.op != FILE_ || !second.u.fil)
	    execerror(env, "file", file);
	break;
/*
 * string is needed:
 */
    case STRFTIME:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != STRING_)
	    execerror(env, "string", file);
	if (second.op != LIST_)
	    execerror(env, "list as second parameter", file);
	break;
    case FPUTCHARS:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != STRING_ && first.op != BIGNUM_)
	    execerror(env, "string", file);
	if (second.op != FILE_ || !second.u.fil)
	    execerror(env, "file", file);
	break;
    case STRTOD:
	first = vec_back(env->stack);
	if (first.op != STRING_ && first.op != BIGNUM_)
	    execerror(env, "string", file);
	break;
/*
 * string is needed as second parameter:
 */
    case FOPEN:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != STRING_)
	    execerror(env, "string", file);
	if (second.op != STRING_)
	    execerror(env, "string as second parameter", file);
	break;
/*
 * integer is needed:
 */
    case UNMKTIME:
	first = vec_back(env->stack);
	if (first.op != INTEGER_)
	    execerror(env, "integer", file);
	break;

    case FREAD:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != INTEGER_ && first.op != CHAR_ && first.op != BOOLEAN_)
	    execerror(env, "numeric", file);
	if (second.op != FILE_ || !second.u.fil)
	    execerror(env, "file", file);
	break;

    case LDEXP:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != INTEGER_)
	    execerror(env, "integer", file);
	if (second.op != FLOAT_ && second.op != INTEGER_)
	    execerror(env, "float or integer as second parameter", file);
	break;

    case STRTOL:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != INTEGER_)
	    execerror(env, "integer", file);
	if (second.op != STRING_ && second.op != BIGNUM_)
	    execerror(env, "string as second parameter", file);
	break;
/*
 * two integers are needed:
 */
    case FSEEK:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	third = vec_at(env->stack, leng - 3);
	if (first.op != INTEGER_ || second.op != INTEGER_)
	    execerror(env, "two integers", file);
	if (third.op != FILE_ || !third.u.fil)
	    execerror(env, "file", file);
	break;
/*
 * integer is needed as second parameter:
 */
    case TIMES:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	if (second.op != INTEGER_)
	    execerror(env, "integer as second parameter", file);
#if 0
	if (second.u.num < 0)
	    execerror(env, "non-negative integer", file);
#endif
	break;
/*
 * numeric type is needed:
 */
    case MAXMIN:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if ((first.op == FLOAT_ || first.op == INTEGER_) &&
	    (second.op == FLOAT_ || second.op == INTEGER_))
	    ;
	else if (first.op != INTEGER_ && first.op != CHAR_ &&
		 first.op != BOOLEAN_ && second.op != INTEGER_ &&
		 second.op != CHAR_ && second.op != BOOLEAN_)
	    execerror(env, "numeric", file);
	else if (first.op != second.op)
	    execerror(env, "two parameters of the same type", file);
	break;
/*
 * numeric type is needed:
 */
    case PREDSUCC:
	first = vec_back(env->stack);
	if (first.op != INTEGER_ && first.op != CHAR_ && first.op != BOOLEAN_ &&
	    first.op != BIGNUM_)
	    execerror(env, "numeric", file);
	break;
/*
 * numeric type is needed as second parameter:
 */
    case PLUSMINUS:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if ((first.op == BIGNUM_ || first.op == FLOAT_ || first.op == INTEGER_)
	    && (second.op == BIGNUM_ || second.op == FLOAT_ ||
	    second.op == INTEGER_))
	    ;
	else if (first.op != INTEGER_)
	    execerror(env, "integer", file);
	else if (second.op != INTEGER_ && second.op != CHAR_)
	    execerror(env, "numeric as second parameter", file);
	break;
/*
 * aggregate parameter is needed:
 */
    case SIZE_:
	first = vec_back(env->stack);
	if (first.op != LIST_ && first.op != STRING_ && first.op != SET_ &&
	    first.op != BIGNUM_)
	    execerror(env, "aggregate parameter", file);
	break;
/*
 * aggregate parameter is needed as second parameter:
 */
    case STEP:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != LIST_)
	    execerror(env, "quotation as top parameter", file);
	if (second.op != LIST_ && second.op != STRING_ && second.op != SET_ &&
	    second.op != BIGNUM_)
	    execerror(env, "aggregate parameter", file);
	break;

    case TAKE:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != INTEGER_ || first.u.num < 0)
	    execerror(env, "non-negative integer", file);
	if (second.op != LIST_ && second.op != STRING_ && second.op != SET_ &&
	    second.op != BIGNUM_)
	    execerror(env, "aggregate parameter", file);
	break;
/*
 * two parameters of the same type are needed:
 */
    case CONCAT:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != LIST_ && first.op != STRING_ && first.op != SET_ &&
	    second.op != BIGNUM_)
	    execerror(env, "aggregate parameter", file);
	if (first.op != second.op)
	    execerror(env, "two parameters of the same type", file);
	break;
/*
 * specific number of types:
 */
    case ANDORXOR:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != second.op)
	    execerror(env, "two parameters of the same type", file);
	if (first.op != SET_ && first.op != INTEGER_ && first.op != CHAR_ &&
	    first.op != BOOLEAN_)
	    execerror(env, "different type", file);
	break;

    case NOT:
	first = vec_back(env->stack);
	if (first.op != SET_ && first.op != INTEGER_ && first.op != CHAR_ &&
	    first.op != BOOLEAN_)
	    execerror(env, "different type", file);
	break;
/*
 * specific number of types:
 */
    case PRIMREC:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	third = vec_at(env->stack, leng - 3);
	if (first.op != LIST_ || second.op != LIST_)
	    execerror(env, "two quotations", file);
	if (third.op != LIST_ && third.op != STRING_ && third.op != SET_ &&
	    third.op != INTEGER_)
	    execerror(env, "different type", file);
	break;
/*
 * specific number of types:
 */
    case SMALL:
	first = vec_back(env->stack);
	if (first.op != LIST_ && first.op != STRING_ && first.op != SET_ &&
	    first.op != INTEGER_ && first.op != BOOLEAN_ && first.op != BIGNUM_)
	    execerror(env, "different type", file);
	break;
/*
 * user defined symbol:
 */
    case BODY:
	first = vec_back(env->stack);
	if (first.op != USR_)
	    execerror(env, "user defined symbol", file);
	break;
/*
 * valid symbol name:
 */
    case INTERN:
	first = vec_back(env->stack);
	if (first.op != STRING_)
	    execerror(env, "string", file);
	/*
	 * a negative number is not a valid name
	 */
	if (first.u.str[0] == '-' && isdigit((int)first.u.str[1]))
	    execerror(env, "valid name", file);
	/*
	 * a name that starts with any of these characters is not valid
	 */
	if (strchr("\"#'().0123456789;[]{}", first.u.str[0]))
	    execerror(env, "valid name", file);
	/*
	 * a name consists of alphanumeric characters, or one of the dashes
	 */
	for (i = strlen(first.u.str) - 1; i > 0; i--)
	     if (!isalnum((int)first.u.str[i]) &&
		 !strchr("-=_", first.u.str[i]))
		 execerror(env, "valid name", file);
	break;
/*
 * character:
 */
    case FORMAT:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	third = vec_at(env->stack, leng - 3);
	fourth = vec_at(env->stack, leng - 4);
	if (first.op != INTEGER_ || second.op != INTEGER_)
	    execerror(env, "two integers", file);
	if (third.op != CHAR_)
	    execerror(env, "character", file);
	if (!strchr("dioxX", third.u.num))
	    execerror(env, "one of: d i o x X", file);
	if (fourth.op != INTEGER_ && fourth.op != CHAR_ &&
	    fourth.op != BOOLEAN_)
	    execerror(env, "numeric as fourth parameter", file);
	break;

    case FORMATF:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	third = vec_at(env->stack, leng - 3);
	fourth = vec_at(env->stack, leng - 4);
	if (first.op != INTEGER_ || second.op != INTEGER_)
	    execerror(env, "two integers", file);
	if (third.op != CHAR_)
	    execerror(env, "character", file);
	if (!strchr("eEfgG", third.u.num))
	    execerror(env, "one of: e E f g G", file);
	if (fourth.op != FLOAT_)
	    execerror(env, "float as fourth parameter", file);
	break;
/*
 * set member:
 */
    case CONS:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	switch (first.op) {
	case LIST_:
	    break;
	case STRING_:
	case BIGNUM_:
	    if (second.op != CHAR_)
		execerror(env, "character", file);
	    break;
	case SET_:
	    if ((second.op != INTEGER_ && second.op != CHAR_) ||
		 second.u.num < 0 || second.u.num >= SETSIZE)
		execerror(env, "small numeric", file);
	    break;
	default:
	    execerror(env, "aggregate parameter", file);
	}
	break;
/*
 * set member:
 */
    case IN_:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	switch (first.op) {
	case LIST_:
	    break;
	case STRING_:
	case BIGNUM_:
#if 0
	    if (second.op != CHAR_)
		execerror(env, "character", file);
#endif
	    break;
	case SET_:
	    if ((second.op != INTEGER_ && second.op != CHAR_) ||
		 second.u.num < 0 || second.u.num >= SETSIZE)
		execerror(env, "small numeric", file);
	    break;
	default:
	    execerror(env, "aggregate parameter", file);
	}
	break;
/*
 * set member:
 */
    case HAS:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	switch (second.op) {
	case LIST_:
	    break;
	case STRING_:
	case BIGNUM_:
#if 0
	    if (first.op != CHAR_)
		execerror(env, "character", file);
#endif
	    break;
	case SET_:
	    if ((first.op != INTEGER_ && first.op != CHAR_) ||
		 first.u.num < 0 || first.u.num >= SETSIZE)
		execerror(env, "small numeric", file);
	    break;
	default:
	    execerror(env, "aggregate parameter", file);
	}
	break;
/*
 * check empty list:
 */
    case CASE:
	first = vec_back(env->stack);
	if (first.op != LIST_)
	    execerror(env, "list", file);
	if (!vec_size(first.u.lis))
	    execerror(env, "non-empty list", file);
	for (i = vec_size(first.u.lis) - 1; i >= 0; i--) {
	    second = vec_at(first.u.lis, i);
	    if (second.op != LIST_)
		execerror(env, "internal list", file);
	}
	break;
/*
 * check empty aggregate:
 */
    case FIRST:
	first = vec_back(env->stack);
	switch (first.op) {
	case LIST_:
	    if (!vec_size(first.u.lis))
		execerror(env, "non-empty list", file);
	    break;
	case STRING_:
	case BIGNUM_:
	    if (!*first.u.str)
		execerror(env, "non-empty string", file);
	    break;
	case SET_:
	    if (!first.u.set)
		execerror(env, "non-empty set", file);
	    break;
	default:
	    execerror(env, "aggregate parameter", file);
	}
	break;
/*
 * check empty aggregate:
 */
    case OF:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (second.u.num < 0)
	    execerror(env, "non-negative integer", file);
	switch (first.op) {
	case LIST_  : if (!vec_size(first.u.lis))
			  execerror(env, "non-empty list", file);
		      if (second.u.num >= vec_size(first.u.lis))
			  execerror(env, "smaller index", file);
		      break;
	case STRING_:
	case BIGNUM_: if (!*first.u.str)
			  execerror(env, "non-empty string", file);
		      if (second.u.num >= (int)strlen(first.u.str))
			  execerror(env, "smaller index", file);
		      break;
	case SET_   : if (!first.u.set)
			  execerror(env, "non-empty set", file);
		      for (i = 0, j = second.u.num; i < SETSIZE; i++)
			  if (first.u.set & ((int64_t)1 << i)) {
			      if (!j)
				  return;
			      j--;
			  }
		      execerror(env, "smaller index", file);
		      break;
	default     : execerror(env, "aggregate parameter", file); 
	}
	break;

    case AT:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.u.num < 0)
	    execerror(env, "non-negative integer", file);
	switch (second.op) {
	case LIST_  : if (!vec_size(second.u.lis))
			  execerror(env, "non-empty list", file);
		      if (first.u.num >= vec_size(second.u.lis))
			  execerror(env, "smaller index", file);
		      break;
	case STRING_:
	case BIGNUM_: if (!*second.u.str)
			  execerror(env, "non-empty string", file);
		      if (first.u.num >= (int)strlen(second.u.str))
			  execerror(env, "smaller index", file);
		      break;
	case SET_   : if (!second.u.set)
			  execerror(env, "non-empty set", file);
		      for (i = 0, j = first.u.num; i < SETSIZE; i++)
			  if (second.u.set & ((int64_t)1 << i)) {
			      if (!j)
				  return;
			      j--;
			  }
		      execerror(env, "smaller index", file);
		      break;
	default     : execerror(env, "aggregate parameter", file);
	}
	break;
/*
 * check second operand:
 */
    case DIV:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != INTEGER_ || second.op != INTEGER_)
	    execerror(env, "two integers", file);
	if (!first.u.num)
	    execerror(env, "non-zero operand", file);
	break;

    case REM:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != FLOAT_ && first.op != INTEGER_)
	    execerror(env, "float or integer", file);
	if (second.op != FLOAT_ && second.op != INTEGER_)
	    execerror(env, "two floats or integers", file);
	if ((first.op == FLOAT_ && !first.u.dbl) || !first.u.num)
	    execerror(env, "non-zero operand", file);
	break;

    case DIVIDE:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != BIGNUM_ && first.op != FLOAT_ && first.op != INTEGER_)
	    execerror(env, "float or integer", file);
	if (second.op != BIGNUM_ && second.op != FLOAT_ &&
	    second.op != INTEGER_)
	    execerror(env, "two floats or integers", file);
	if ((first.op == BIGNUM_ && first.u.str[1] == '0') ||
	    (first.op == FLOAT_ && !first.u.dbl) || !first.u.num)
	    execerror(env, "non-zero divisor", file);
	break;
/*
 * check numeric list:
 */
    case FWRITE:
	first = vec_back(env->stack);
	second = vec_at(env->stack, leng - 2);
	if (first.op != LIST_)
	    execerror(env, "list", file);
	if (second.op != FILE_ || !second.u.fil)
	    execerror(env, "file", file);
	for (i = vec_size(first.u.lis) - 1; i >= 0; i--) {
	    second = vec_at(first.u.lis, i);
	    if (second.op != INTEGER_)
		execerror(env, "numeric list", file);
	}
	break;
/*
 * check list at top with user defined symbol.
 */
    case ASSIGN:
	first = vec_back(env->stack);
	if (first.op != LIST_)
	    execerror(env, "list", file);
	if (!vec_size(first.u.lis))
	    execerror(env, "non-empty list", file);
	first = vec_back(first.u.lis);
	if (first.op != USR_)
	    execerror(env, "user defined symbol", file);
	break;
#ifdef USE_MULTI_THREADS_JOY
/*
 * channel as top parameter:
 */
    case RECEIVE:
	first = vec_back(env->stack);
	if (first.op != INTEGER_)
	    execerror(env, "channel", file);
	break;
/*
 * channel as second parameter:
 */
    case SEND:
	second = vec_at(env->stack, leng - 2);
	if (second.op != INTEGER_)
	    execerror(env, "channel", file);
	break;
#endif
    }
}
