#include "shell.h"
/*
*This is the shell.c file which contains:
*display prompt
*print command
*execute command
*/

int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_command();
        if (strcmp(command, "exit") == 0)
        {
            free(command);
            exit(EXIT_SUCCESS);
        }
        else if (strcmp(command, "env") == 0)
        {
<<<<<<< HEAD:shell.c
            print_environment();
=======
            extern char **environ;  /* Declaring extern environ */
            char **env = environ;
            while (*env)
            {
                printf("%s\n", *env);
                env++;
            }
>>>>>>> refs/remotes/origin/main:main.c
        }
        else
        {
            execute_command(command);
        }
        free(command);
    }

    return 0;
}

