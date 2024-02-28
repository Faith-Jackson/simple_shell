#include "shell.h"

/**
 * get_environment - returns the string array copy of the environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environment(info_t *info)
{
        if (!info->environment || info->env_changed)
        {
                info->environment = list_to_strings(info->env);
                info->env_changed = 0;
        }

        return (info->environment);
}

/**
 * unset_environment_variable - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on deletion, 0 otherwise
 * @var: the environment variable property
 */
int unset_environment_variable(info_t *info, char *var)
{
        list_t *node = info->env;
        size_t i = 0;
        char *p;

        if (!node || !var)
                return (0);

        while (node)
        {
                p = starts_with(node->str, var);
                if (p && *p == '=')
                {
                        info->env_changed = delete_node_at_index(&(info->env), i);
                        i = 0;
                        node = info->env;
                        continue;
                }
                node = node->next;
                i++;
        }
        return (info->env_changed);
}

/**
 * set_environment_variable - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the environment variable property
 * @value: the environment variable value
 *  Return: Always 0
 */
int set_environment_variable(info_t *info, char *var, char *value)
{
        char *buf = NULL;
        list_t *node;
        char *p;

        if (!var || !value)
                return (0);

        buf = malloc(custom_strlen(var) + custom_strlen(value) + 2);
        if (!buf)
                return (1);
        custom_strcpy(buf, var);
        custom_strcat(buf, "=");
        custom_strcat(buf, value);
        node = info->env;
        while (node)
        {
                p = starts_with(node->str, var);
                if (p && *p == '=')
                {
                        free(node->str);
                        node->str = buf;
                        info->env_changed = 1;
                        return (0);
                }
                node = node->next;
        }
        add_node_end(&(info->env), buf, 0);
        free(buf);
        info->env_changed = 1;
        return (0);
}
