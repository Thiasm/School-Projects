/*
** EPITECH PROJECT, 2019
** print_way.c
** File description:
** lemin
*/

#include "../include/my.h"

int print_path(data_t *data)
{
    room_t *room;
    int arrived = 0;
    int space = 0;
    int obj = data->ant_number;

    my_printf("#moves\n");
    if (data->check != 0 || data->path == NULL)
        return (84);
    while (arrived != obj) {
        space = 0;
        room = data->list->last;
        while (room) {
            check_arrived(data, &space, &arrived, room);
            ant_forward(data, &space, room);
            room = room->previous;
        }
        my_printf("\n");
    }
    return (0);
}

void ant_forward(data_t *data, int *space, room_t *room)
{
    if (room->ant > 0) {
        room->ant -= 1;
        room->single_next->ant += 1;
        room->single_next->id = room->id;
        if (*space == 1)
            my_printf(" ");
        my_printf("P%d-%s", room->id, room->single_next->name);
        *space = 1;
    }
}

void check_arrived(data_t *data, int *space, int *arrived, room_t *room)
{
    if (room->single_next == data->list->last && room->ant > 0) {
        if (*space == 1)
            my_printf(" ");
        my_printf("P%d-%s", room->id, room->single_next->name);
        *space = 1;
        room->ant -= 1;
        *arrived += 1;
    }
    if (room == data->list->way && data->ant_number > 0) {
        room->ant += 1;
        room->id = room->single_next->id + 1;
        data->ant_number -= 1;
    }
}