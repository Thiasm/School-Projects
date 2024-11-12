/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** env.c
*/

#include "minishell.h"

void print_an_env(char **cmds)
{
    char *var = NULL;
    char *to_print = NULL;

    if (my_tablen(cmds) == 1)
        print_env(cmds);
    else if (my_tablen(cmds) == 2) {
        if (cmds[1][my_strlen(cmds[1]) - 1] != '=')
            var = my_strjoin(cmds[1], "=");
        else
            var = my_strjoin(cmds[1], "");
        if ((to_print = get_env_var(var)) == NULL) {
            free(var);
            return;
        }
        my_printf("%s\n", to_print);
        free(var);
        free(to_print);
    } else
        my_putstr_fd("printenv: Too many arguments.\n", 2);
}

void print_env(char **cmds)
{
    (void)cmds;

    if (!g_env) {
        my_putstr("mysh: env: environment is empty\n");
        return;
    }
    for (int i = 0; g_env[i] != NULL; i++) {
        my_putstr(g_env[i]);
        my_putchar('\n');
    }
}