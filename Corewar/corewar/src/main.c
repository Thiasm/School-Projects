/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** main.c
*/

#include "corewar.h"
#include "protos.h"
#include "my.h"

int helper(char **av)
{
    if (av[1][0] == '-' && av[1][2] == '\0') {
        if (av[1][1] == 'h') {
            my_putstr_fd("USAGE\n\t", 2);
            my_putstr_fd(av[0], 2);
            my_putstr_fd(USAGE_STR, 2);
            my_putstr_fd(HELP_STR, 2);
        } else if (av[1][1] == 'u') {
            my_putstr_fd("USAGE\n\t", 2);
            my_putstr_fd(av[0], 2);
            my_putstr_fd(USAGE_STR, 2);
        }
        return 1;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    (void)env;
    if (ac < 2) {
        my_putstr_fd("Usage: ", 2);
        return exit_prog(84, USAGE_STR);
    } else if (ac == 2) {
        if (helper(av))
            return 0;
    }
    return corewar(av, ac);
}