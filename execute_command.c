#include "shell.h"
#include <string.h>

/**
 * exe comm - It Execute commands in the shell we have created
 * @command: The command prompts that is to be executed
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	/* Fork a child process */
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{

		/* Check all built in commands */
		if (strcmp(command, "cd") == 0)
		execute_command.c{
			/* Handles cd command */
			if (chdir(getenv("HOME")) == -1)
			{
				perror("chdir");
			}
			exit(EXIT_SUCCESS); /* Exit child process after executing built-in command */
		}
		else if (strcmp(command, "mkdir") == 0)
		{
			/* Handle mkdir command */
			char *args[] = {"/bin/mkdir", "-p", "Faith", NULL}; /* Create directory Faith */
			execvp(args[0], args);
			perror("execvp"); /* perror is only called if execvp fails */
			exit(EXIT_FAILURE); /* Exit child process with failure status */
		}
		else
		{
			/* For other commands, execute using execvp */
			char *args[] = {command, NULL}; /* Construct args array */
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}
}

