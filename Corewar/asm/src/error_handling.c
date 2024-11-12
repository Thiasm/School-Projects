/*
** EPITECH PROJECT, 2019
** error_handling.c
** File description:
** Handle errors.
*/

#include "asm.h"
#include "protos.h"

static int which_type(char *line)
{
    if (line[0] == 'r')
        return registr;
    if (line[0] == '%')
        return direct;
    if (line[0] < '9' && line[0] > '0' || line[0] == '-')
        return indirect;
    return -1;
}

static int good_arg(char *line, args_type_t type)
{
    switch (which_type(line)) {
        case registr: if (type == T_REG || type == T_REG |
        T_DIR || type == T_REG | T_IND || T_REG | T_DIR | T_IND)
            return true;
        else
            return false;
        case direct: if (type == T_DIR || type == T_DIR |
        T_REG || type == T_DIR | T_IND || T_DIR | T_REG | T_IND)
            return true;
        else
            return false;
        case indirect: if (type == T_IND || type == T_IND |
        T_DIR || type == T_IND | T_REG || T_IND | T_REG | T_DIR)
            return true;
        else
            return false;
        case -1: return false; break;
    }
    return false;
}

static int argument_are_valid(char **command, int y)
{
    args_type_t *type;
    for (int j = 0; op_tab[j].nbr_cycles != 0; j++)
        if (my_strcmp(op_tab[j].mnemonique, command[y]) == 0)
            type = op_tab[j].type;
    y++;
    for (int arg = 0; command[y] != NULL; y++, arg++) {
        for (int j = 0; op_tab[j].nbr_cycles != 0; j++) {
            if (my_strcmp(op_tab[j].mnemonique, command[y]) == 0)
                return true;
        }
        if (command[y][my_strlen(command[y]) - 1] == ':'
        || command[y][0] == '.' || command[y][0] == '#') {
            arg--;
            continue;
        }
        if (good_arg(command[y], type[arg]) == false)
            return false;
    }
    return (true);
}

static int is_valid(char **command, int y)
{
    int nb_arg;

    for (int j = 0; op_tab[j].nbr_cycles != 0; j++)
        if (my_strcmp(op_tab[j].mnemonique, command[y]) == 0) {
            nb_arg = nbr_arg(command, y + 1);
            if (nb_arg != op_tab[j].nbr_args)
                return (return_err("Invalid arg number.\n"));
            if (argument_are_valid(command, y) == false)
                return (return_err("Wrong argument.\n"));
            break;
        }
    return 0;
}

void error_handling(char **command)
{
    for (int y = 0; command[y] != NULL; y++) {
        if (is_valid(command, y) == 84)
            exit(84);
    }
}