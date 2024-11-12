/*
** EPITECH PROJECT, 2019
** check_nbr_arg.c
** File description:
** check the nbr of arg
*/

#include "asm.h"

static int return_nb_arg(int start, int y)
{
    if (y - start > 0)
        return y - start;
    else
        return 1;
}

int nbr_arg(char **command, int y)
{
    int start = y;

    for (; command[y] != NULL; y++) {
        for (int j = 0; op_tab[j].nbr_cycles != 0; j++) {
            if (my_strcmp(op_tab[j].mnemonique, command[y]) == 0)
                return return_nb_arg(start, y);
        }
        if (command[y][my_strlen(command[y]) - 1] == ':'
            || command[y][0] == '.' || command[y][0] == '#')
            start++;
    }
    return return_nb_arg(start, y);
}