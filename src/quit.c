/*
    module  : quit.c
    version : 1.2
    date    : 04/29/24
*/
#ifndef QUIT_C
#define QUIT_C

/**
Q0  IGNORE_OK  3130  quit  :  N  ->
[IMPURE] Exit from Joy.
*/
void quit_(pEnv env)
{
    abortexecution_(ABORT_QUIT);
}
#endif
