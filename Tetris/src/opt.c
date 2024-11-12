/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** opt.c
*/

#include "tetris.h"
#include "proto.h"

int change_key_right(int *i, char **av, char ***info)
{
    if (my_strcmp(av[(*i)], "-r") == 0) {
        if (((*info)[1] = modify_key((*info)[1], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    if (my_strcmp(av[(*i)], "-t") == 0) {
        if (((*info)[2] = modify_key((*info)[2], av[(*i) + 1])) == NULL)
            exit(84);
        (*i) += 2;
        return 1;
    }
    return 0;
}

int see_next(int *i, char **av, char ***info)
{
    if ((my_strcmp(av[(*i)], "-w") == 0) ||
        (my_strcmp(av[(*i)], "--without-next") == 0)) {
        if (((*info)[6] = modify_key((*info)[6], "No")) == NULL)
            exit(84);
        (*i)++;
        return 1;
    }
    return 0;
}

int long_key_sides(char ***info, char **av, int *i)
{
    if (my_strncmp("--key-left=", av[(*i)], 11) == 0) {
        if (((*info)[0] = long_modify_key((*info)[0], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return 1;
    }
    if (my_strncmp("--key-right=", av[(*i)], 12) == 0) {
        if (((*info)[1] = long_modify_key((*info)[1], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return 1;
    }
    return 0;
}

int modify_num(char ***info, char **av, int *i)
{
    if (my_strncmp("--level=", av[(*i)], 8) == 0) {
        if (((*info)[7] = long_modify_key((*info)[7], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return 1;
    }
    if (my_strncmp("--map-size=", av[(*i)], 11) == 0) {
        if (((*info)[8] = modify_wnd((*info)[8], av[(*i)])) == NULL)
            exit(84);
        (*i)++;
        return 1;
    }
    return 0;
}