/*
** EPITECH PROJECT, 2019
** pathfinding.c
** File description:
** Find shortest path.
*/

#include "../include/my.h"

char **launch_pathfinding(data_t *data)
{
    int status = 0;

    while (pathfinding(data, status) != 1)
        status++;
    return (return_path(data, 99999999, 99999999, 0));
}

struct room_s **give_id(room_t *room, int status)
{
    if (room->id == status) {
        for (int i = 0; room->next[i] != NULL; i++) {
            if (room->next[i]->id == -2) {
                room->next[i]->id = status + 1;
            }
        }
    }
    return (room->next);
}

int pathfinding(data_t *data, int status)
{
    room_t *room = data->list->last;

    while (room->id != -1) {
        if (status == 10)
            return (1);
        room->next = give_id(room, status);
        for (int i = 0; room->next[i] != NULL; i++)
            if (room->next[i]->id == -1)
                return (1);
        room = room->previous;
    }
    return (0);
}
