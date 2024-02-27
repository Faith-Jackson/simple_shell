#include "shell.h"
/*
*input command paths are determined here
*/

void print_environment(void)
{
    extern char **environ;
    char **env = environ;
    while (*env)
    {
        printf("%s\n", *env);
        env++;
    }
}

