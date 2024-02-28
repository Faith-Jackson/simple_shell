#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containing the history file
 */
char *get_history_file(info_t *info)
{
        char *buf, *dir;

        dir = custom_getenv(info, "HOME=");
        if (!dir)
                return (NULL);
        buf = malloc(sizeof(char) * (custom_strlen(dir) + custom_strlen(HISTORY_FILE) + 2));
        if (!buf)
                return (NULL);
        buf[0] = 0;
        custom_strcpy(buf, dir);
        custom_strcat(buf, "/");
        custom_strcat(buf, HISTORY_FILE);
        return (buf);
}

/**
 * write_history_to_file - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history_to_file(info_t *info)
{
        ssize_t fd;
        char *filename = get_history_file(info);
        list_t *node = NULL;

        if (!filename)
                return (-1);

        fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
        free(filename);
        if (fd == -1)
                return (-1);
        for (node = info->history; node; node = node->next)
        {
                custom_puts_fd(node->str, fd);
                custom_putchar_fd('\n', fd);
        }
        custom_putchar_fd(BUFFER_FLUSH, fd);
        close(fd);
        return (1);
}

/**
 * read_history_from_file - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history_from_file(info_t *info)
{
        int i, last = 0, linecount = 0;
        ssize_t fd, rdlen, fsize = 0;
        struct stat st;
        char *buf = NULL, *filename = get_history_file(info);

        if (!filename)
                return (0);

        fd = open(filename, O_RDONLY);
        free(filename);
        if (fd == -1)
                return (0);
        if (!fstat(fd, &st))
                fsize = st.st_size;
        if (fsize < 2)
                return (0);
        buf = malloc(sizeof(char) * (fsize + 1));
        if (!buf)
                return (0);
        rdlen = read(fd, buf, fsize);
        buf[fsize] = 0;
        if (rdlen <= 0)
                return (free(buf), 0);
        close(fd);
        for (i = 0; i < fsize; i++)
                if (buf[i] == '\n')
                {
                        buf[i] = 0;
                        build_history_list(info, buf + last, linecount++);
                        last = i + 1;
                }
        if (last != i)
                build_history_list(info, buf + last, linecount++);
        free(buf);
        info->histcount = linecount;
        while (info->histcount-- >= MAX_HISTORY_SIZE)
                delete_node_at_index(&(info->history), 0);
        renumber_history_list(info);
        return (info->histcount);
}

/**
 * build_history_list - adds an entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history line count, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
        list_t *node = NULL;

        if (info->history)
                node = info->history;
        add_node_end(&node, buf, linecount);

        if (!info->history)
                info->history = node;
        return (0);
}

/**
 * renumber_history_list - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history_list(info_t *info)
{
        list_t *node = info->history;
        int i = 0;

        while (node)
        {
                node->num = i++;
                node = node->next;
        }
        return (info->histcount = i);
}

