/*
** EPITECH PROJECT, 2019
** error_handling
** File description:
** navty
*/

#include "navy.h"

int error(int argc, char **argv)
{
    if ((argc > 3) || (argc == 1))
        return (0);
    if (argc == 3 && argv[1][0] == '-')
        return (0);
    if ((argc == 2) && (str_compare(argv[1], "-h") == 0)) {
        my_putstr("USAGE\n      ");
        my_putstr("./navy [first_player_pid] navy_positions\n");
        my_putstr("DESCRIPTION\n      ");
        my_putstr("first_player_pid: only for the 2nd player. ");
        my_putstr("pid of the first player.\n");
        my_putstr("      navy_positions: file representing ");
        my_putstr("the positions of the ships\n");
        return (0);
    }
    return (1);
}
