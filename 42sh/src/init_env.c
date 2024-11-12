/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** init_env.c
*/

#include "minishell.h"

void check_basics(void)
{
    char *cmd = NULL;
    char *my_tab[] = {"setenv", "OLDPWD=", NULL};

    if ((cmd = get_env_var("OLDPWD=")) == NULL)
        set_env(my_tab);
    free(cmd);
}

int init_env(char **env)
{
    int i = 0;
    if (!env || env[0] == NULL) {
        my_putstr_fd("mysh: Empty env\n", 2);
        return 84;
    }
    if ((g_env = (char**)malloc(sizeof(char *) *
        (my_tablen(env) + 1))) == NULL) {
        return 84;
    }
    for (i = 0; env[i] != NULL; i++) {
        if (!(g_env[i] = my_strdup(env[i])))
            return 84;
    }
    g_env[i] = NULL;
    check_basics();
    return 0;
}
