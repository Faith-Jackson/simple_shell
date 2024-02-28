#include "shell.h"

/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while (1)
    {
        printf("#my_simple_shell$ ");
        bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        if (bytes_read == 0)
        {
            printf("\n");
            break;
        }
        buffer[bytes_read - 1] = '\0'; /* Remove newline character */
        handle_command(buffer);
    }

    return 0;
}

