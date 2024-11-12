/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** main.c
*/

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    if (init_env(env) != 0)
        return 84;
    minishell();
    my_freetab(g_env);
    return 0;
}
