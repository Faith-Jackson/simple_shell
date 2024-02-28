#include "shell.h"

/**
 * handle_command - Tokenizes the input command line and executes it
 * @buffer: The input command line
 */
void handle_command(char *buffer)
{
    char *args[ARGS_MAX];
    pid_t pid;
    int status;

    char *token = strtok(buffer, " ");
    int i = 0;
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; /* Null-terminate the args array */

    /* Check if the command exists before forking */
    if (access(args[0], X_OK) == -1)
    {
        perror("access");
        return; /* Exit without forking if command does not exist */
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}

