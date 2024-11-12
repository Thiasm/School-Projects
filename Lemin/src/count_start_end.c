/*
** EPITECH PROJECT, 2019
** count_start_end.c
** File description:
** Verify if there is only one start and one end
*/

#include "../include/my.h"

int count_start_end(char **file, int nbr_start, int nbr_end)
{
    int returned;

    for (int y = 0, returned = -1; file[y] != NULL; y++) {
        if (my_strcmp(file[y], "##start") == 1) {
            nbr_start++;
            returned = check_if_room(file[y + 1]);
        }
        else if (my_strcmp(file[y], "##end") == 1) {
            nbr_end++;
            returned = check_if_room(file[y + 1]);
        }
        if (returned == 0)
            return (84);
    }
    if (nbr_start != 1 || nbr_end != 1)
        return (84);
}
