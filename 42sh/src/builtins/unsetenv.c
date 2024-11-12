/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** unsetenv.c
*/

#include "minishell.h"

void rem_env_var(int var_pos)
{
    int i;
    int j;
    int len = my_tablen(g_env);
    char **new_env = NULL;

    if (!(new_env = (char **)malloc(sizeof(char *) * (len + 1))))
        return;
    for (i = 0, j = 0; i < len && g_env[j] != NULL; i++, j++) {
        if (j == var_pos && g_env[j + 1])
            j += 1;
        else if (j == var_pos && !g_env[j + 1]) {
            break;
        }
        new_env[i] = my_strdup(g_env[j]);
    }
    new_env[i] = NULL;
    my_freetab(g_env);
    init_env(new_env);
    my_freetab(new_env);
}

void unset_env(char **cmds)
{
    char *full_var = NULL;
    int var_pos = 0;

    if (cmds[1] == NULL) {
        my_putstr_fd("unsetenv: Too few arguments\n", 2);
        return;
    }
    for (int i = 1; cmds[i] != NULL; i++) {
        if (cmds[i][my_strlen(cmds[i]) - 1] != '=') {
            full_var = my_strjoin(cmds[i], "=");
        } else
            full_var = my_strjoin(cmds[i], "");
        if ((var_pos = is_env_var(full_var)) || (var_pos == 0))
            rem_env_var(var_pos);
        free(full_var);
        full_var = NULL;
    }
}
