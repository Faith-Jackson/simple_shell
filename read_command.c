#include "shell.h"

<<<<<<< HEAD
=======
/**
 * read_command - Read a command from standard input
 *
 * Return: Pointer a to the read command
 */
>>>>>>> refs/remotes/origin/main
char *read_command(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    write(STDOUT_FILENO, "#cisfun$ ", 9);

<<<<<<< HEAD
    characters = getline(&buffer, &bufsize, stdin);
    if (characters == -1)
    {
        if (feof(stdin))
        {
            write(STDOUT_FILENO, "\n", 1);
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    buffer[characters - 1] = '\0'; /* newline character is removed */
    return buffer;
=======
	buffer[characters - 1] = '\0'; /* Removing newline character */
	return (buffer);
>>>>>>> refs/remotes/origin/main
}

