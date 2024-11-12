/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** debug_mode.c
*/

#include "tetris.h"
#include "proto.h"

char **init_debug(char **info)
{
    info[0] = my_str_dup("^EOD");
    info[1] = my_str_dup("^EOC");
    info[2] = my_str_dup("^EOA");
    info[3] = my_str_dup("^EOB");
    info[4] = my_str_dup("q");
    info[5] = my_str_dup("(space)");
    info[6] = my_str_dup("Yes");
    info[7] = my_str_dup("1");
    info[8] = my_str_dup("20*10");
    info[9] = NULL;
    return info;
}

char **debug_mode(int ac, char **av, char **info)
{
    info = init_debug(info);
    info = modify_info(info, ac, av);
    return info;
}
