/*
** EPITECH PROJECT, 2019
** main
** File description:
** tetris
*/

#include "tetris.h"
#include "proto.h"

int main(int ac, char **av, char **env)
{
    data_t data;
    char **info = malloc(sizeof(char *) * 10);

    if (ac == 2 && my_strcmp(av[1], "--help") == 0) {
        print_help(av);
        return 0;
    }
    if (!env[0])
        return 84;
    parse_tetriminos(&data);
    info = debug_mode(ac, av, info);
    for (int i = 0; i != ac; i++) {
        if (my_strcmp(av[i], "-D") == 0 || my_strcmp(av[i], "--debug") == 0) {
            disp_debug(info);
            print_tetriminos(&data);
            break;
        }
    }
    free_info(info);
    free_all(&data);
    return 0;
}