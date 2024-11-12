/*
** EPITECH PROJECT, 2019
** room_error_bis
** File description:
** lemin
*/

#include "../include/my.h"

int error_room(data_t *data)
{
    if (number_room_error(data) == 84)
        return (84);
    if (place_room_error(data) == 84)
        return (84);
    if (!data->rooms[0])
        return (84);
    return (0);
}
