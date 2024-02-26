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
	int status;

	while (1)
	{
		/* Display prompt */
		write(STDOUT_FILENO, "#my_simple_shell$ ", 9);

		/* Read command from user */
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		if (bytes_read == 0)
		{
			/* End of file condition (Ctrl+D) */
			write(STDOUT_FILENO, "\n", 1);
			break;
		}

		/* Execute command */
		buffer[bytes_read - 1] = '\0'; /* Remove newline character */
		status = system(buffer);
		if (status == -1)
		{
			perror("system");
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}
