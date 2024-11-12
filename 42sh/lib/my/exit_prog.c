/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** exit_prog.c
*/

#include "my.h"

int exit_prog(int ret, char *str)
{
    my_putstr_fd(str, 2);
    my_putstr_fd("\n", 2);
    return ret;
}
