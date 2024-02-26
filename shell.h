#ifndef SHELL_H
#define SHELL_H

/*
*Functions declation are listed here
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define ARGS_MAX 64

void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void print_environment(void);

#endif /* SHELL_H */

