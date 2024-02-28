#include "shell.h"

/*
*this are were commands response are printed
 * display_prompt -It Displays the shell prompt
 */

void display_prompt(void)
{
    write(STDOUT_FILENO, "#my_simple_shell$ ", 9);
}

