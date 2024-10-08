/*
 *  module  : undefs.c
 *  version : 1.10
 *  date    : 09/16/24
 */
#include "globals.h"

void hide_inner_modules(pEnv env, int flag)
{
    Entry ent;
    Token node;
    char *name;
    khint_t key;
    size_t leng;
    int i, last = 0;

    /*
     * There are two calls to this function. In the first call, the name of
     * the module is read and stored in mod_name. In the second call, mod_name
     * is used when searching the symbol table.
     */
    if (flag) {
	node = vec_back(env->tokens);
	if (node.op == USR_) {
	    leng = strlen(node.u.str) + 2;
	    env->mod_name = GC_malloc_atomic(leng);
	    snprintf(env->mod_name, leng, "%s.", node.u.str);
	} else
	    env->mod_name = ".";	/* empty module name */
	return;
    }
    /*
     * At this point in the program, the symbol table is already filled with
     * the member functions and can be inspected right now.
     */
    name = env->mod_name;	/* name of module */
    leng = strlen(name);	/* length of name, including separator */
    /*
     * Look in the symbol table for the last mention of this name. The first
     * may not be present, because private symbols are not stored with the
     * name of the module.
     */
    for (i = vec_size(env->symtab) - 1; i > 0; i--) {
	ent = vec_at(env->symtab, i);
	if (!ent.is_user || ent.is_ok)		/* builtins or verified ok */
	    break;
	if (strchr(ent.name, '.') == 0)		/* ent.name is not a module */
	    break;
	if (!last && !strncmp(name, ent.name, leng)) {
	    last = i;				/* found a public definition */
	    vec_at(env->symtab, i).is_ok = 1;	/* register as end of module */
	}					/* continue search for start */
    }
    /*
     * If there are other modules within this range, they should be
     * invalidated. This is accomplished by removing the module from the hash
     * table. The module is still present in the symbol table, but cannot be
     * found. Exactly what is needed.
     */
    for (; i < last; i++) {
	ent = vec_at(env->symtab, i);
	if (ent.is_ok || !strchr(ent.name, '.'))/* previous modules are ok */
	    continue;
	if (isdigit((int)ent.name[0]))		/* hidden names are ok */
	    continue;
	if (strncmp(name, ent.name, leng)) {	/* an inner module was found */
#ifdef USE_KHASHL
	    if ((key = symtab_get(env->hash, ent.name)) != kh_end(env->hash))
		symtab_del(env->hash, key);
#else
	    if ((key = kh_get(Symtab, env->hash, ent.name))
			    != kh_end(env->hash))
		kh_del(Symtab, env->hash, key);
#endif
	}
    }
}
