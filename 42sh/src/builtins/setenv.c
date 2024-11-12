/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** setenv.c
*/

#include "minishell.h"

void add_env_var(char *full_var, char *data)
{
    int i;
    int len = my_tablen(g_env);
    char **new_env = NULL;

    if (!(new_env = (char **)malloc(sizeof(char *) * (len + 2))))
        return;
    for (i = 0; i < len; i++)
        new_env[i] = my_strdup(g_env[i]);
    new_env[i] = my_strjoin(full_var, data);
    new_env[i + 1] = NULL;
    my_freetab(g_env);
    init_env(new_env);
    my_freetab(new_env);
}

int is_env_var(char *cmd)
{
    int i;
    int len = my_strlen(cmd);
    char *full_cmd = NULL;

    if (cmd[my_strlen(cmd) - 1] != '=')
        full_cmd = my_strjoin(cmd, "=");
    else
        full_cmd = my_strjoin(cmd, "");
    for (i= 0; g_env[i]; i++) {
        if (!my_strncmp(g_env[i], full_cmd, len)) {
            break;
        }
    }
    free(full_cmd);
    return (i);
}

int count_alpha(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count += my_isalnum(str[i]);
    return count;
}

void set_or_change(char **cmds, char *full_var)
{
    if (count_alpha(full_var) < (int)my_strlen(full_var) - 1) {
        my_putstr_fd("setenv: Variable name must contain "
            "alphanumeric characters.\n", 2);
        return;
    }
    if (is_env_var(full_var) == my_tablen(g_env)) {
        if (cmds[2] == NULL)
            add_env_var(full_var, "");
        else
            add_env_var(full_var, cmds[2]);
    } else {
        if (cmds[2] == NULL)
            set_env_var(full_var, "");
        else
            set_env_var(full_var, cmds[2]);
    }
}

void set_env(char **cmds)
{
    char *full_var = NULL;

    if (my_tablen(cmds) > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return;
    }
    if (cmds[1] == NULL) {
        print_env(cmds);
        return;
    } else if (cmds[1][my_strlen(cmds[1]) - 1] != '=') {
        full_var = my_strjoin(cmds[1], "=");
    } else
        full_var = my_strjoin(cmds[1], "");
    set_or_change(cmds, full_var);
    free(full_var);
    full_var = NULL;
}
