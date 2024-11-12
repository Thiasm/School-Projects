/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** main.c
*/

#include "asm.h"
#include "protos.h"
#include "my.h"

int helper(char **av)
{
    if (av[1][0] == '-' && av[1][2] == '\0') {
        if (av[1][1] == 'h') {
            my_putstr_fd("USAGE\n\t", 2);
            my_putstr_fd(av[0], 2);
            my_putstr_fd(" file_name[.s]\n", 2);
            my_putstr_fd("DESCRIPTION\n\tfile_name\t", 2);
            my_putstr_fd("file in assembly language to be converted into ", 2);
            my_putstr_fd("file_name.cor, an \n\t\t\texecutable in the ", 2);
            my_putstr_fd("Virtual Machine\n", 2);
        } else if (av[1][1] == 'u') {
            my_putstr_fd("USAGE\n\t", 2);
            my_putstr_fd(av[0], 2);
            my_putstr_fd(" file_name[.s]\n", 2);
        }
        return 1;
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    (void)env;
    if (ac < 2) {
        return exit_prog(84, "Usage: ./asm file_name[.s]");
    } else if (ac == 2) {
        if (helper(av))
            return 0;
    }
    for (int i = 1; av[i] != NULL; i++)
        handle_file(av[i]);
    return 0;
}