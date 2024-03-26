/*
    module  : quit.c
    version : 1.1
    date    : 03/21/24
*/
#ifndef QUIT_C
#define QUIT_C

/**
Q0  IGNORE_OK  3130  quit  :  N  ->
[IMPURE] Exit from Joy.
*/
void quit_(pEnv env)
{
    exit(EXIT_SUCCESS);
}
#endif
