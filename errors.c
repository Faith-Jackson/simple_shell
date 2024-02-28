#include "shell.h"

/**
 * custom_puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void custom_puts(char *str)
{
        int i = 0;

        if (!str)
                return;
        while (str[i] != '\0')
        {
                custom_putchar(str[i]);
                i++;
        }
}

/**
 * custom_putchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_putchar(char c)
{
        static int i;
        static char buf[WRITE_BUFFER_SIZE];

        if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
        {
                write(2, buf, i);
                i = 0;
        }
        if (c != BUFFER_FLUSH)
                buf[i++] = c;
        return (1);
}

/**
 * custom_putchar_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int custom_putchar_fd(char c, int fd)
{
        static int i;
        static char buf[WRITE_BUFFER_SIZE];

        if (c == BUFFER_FLUSH || i >= WRITE_BUFFER_SIZE)
        {
                write(fd, buf, i);
                i = 0;
        }
        if (c != BUFFER_FLUSH)
                buf[i++] = c;
        return (1);
}

/**
 * custom_puts_fd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: the number of characters put
 */
int custom_puts_fd(char *str, int fd)
{
        int i = 0;

        if (!str)
                return (0);
        while (*str)
        {
                i += custom_putchar_fd(*str++, fd);
        }
        return (i);
}

