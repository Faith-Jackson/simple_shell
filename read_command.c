#include "shell.h"

/**
 * read_command - This Reads a command from standard input given
 *
 * Return: it returns Pointer a to the read command
 */
char *read_command(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    write(STDOUT_FILENO, "#cisfun$ ", 9);

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

	buffer[characters - 1] = '\0'; /* Removing newline character */

	return (buffer);
}

