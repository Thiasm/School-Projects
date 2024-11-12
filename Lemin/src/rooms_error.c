/*
** EPITECH PROJECT, 2019
** room_error
** File description:
** lemin
*/

#include "../include/my.h"

int start_end_error(data_t *data, char **tab)
{
    for (int i = 0; data->rooms[i] != NULL; i += 3) {
        if (my_strcmp(tab[0], data->rooms[i]) == 1)
            return (84);
    }
    for (int i = 0; data->rooms[i] != NULL; i += 3) {
        if (my_strcmp(tab[1], data->rooms[i + 1]) == 1)
            if (my_strcmp(tab[2], data->rooms[i + 2]) == 1)
                return (84);
    }
    return (0);
}

int place_room_error_bis(data_t *data, int j, int where)
{
    if (j != where)
        if (my_strcmp(data->rooms[j + 1], data->rooms[where + 1]) == 1)
            if (my_strcmp(data->rooms[j + 2], data->rooms[where + 2]) == 1)
                return (84);
    return (0);
}

int place_room_error(data_t *data)
{
    int where = 0;

    for (int i = 0; data->rooms[i]; i += 3) {
        for (int j = 0; data->rooms[j]; j += 3)
            if (place_room_error_bis(data, j , where) == 84)
                return (84);
        where += 3;
    }
    return (0);
}

int number_room_error_bis(data_t *data, int j, int where)
{
    if (j != where)
        if (my_strcmp(data->rooms[j], data->rooms[where]) == 1)
            return (84);
}

int number_room_error(data_t *data)
{
    int where = 0;

    for (int i = 0; data->rooms[i]; i += 3) {
        for (int j = 0; data->rooms[j]; j += 3)
            if (number_room_error_bis(data, j, where) == 84)
                return (84);
        where += 3;
    }
    return (0);
}
