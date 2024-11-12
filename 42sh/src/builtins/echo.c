/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** echo.c
*/

#include "minishell.h"

void echo_loop(char **av, int *i)
{
    for (int j = 0; av[*i][j] != '\0'; j++) {
        if (av[*i][j] == '\\')
            continue;
        my_putchar(av[*i][j]);
    }
}

void echo(char **av)
{
    int no_ret = 0;

    if (av[1] && !my_strncmp(av[1], "-n\0", 3))
        no_ret = 1;
    for (int i = no_ret + 1; av[i] != NULL; i++) {
        echo_loop(av, &i);
        if (av[i + 1] && av[i + 1] != NULL)
            my_putchar(' ');
    }
    if (no_ret == 0)
        my_putchar('\n');
}