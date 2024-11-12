/*
** EPITECH PROJECT, 2019
** pathfinding_tools.c
** File description:
** Next pathfinding file.
*/
#include "../include/my.h"

char **finalize_path(char **path, room_t *room, int y, int i)
{
    path[y] = my_strcpy(room->name);
    path[y + 1] = my_strcpy(room->next[i]->name);
    path[y + 2] = NULL;
    return (path);
}

char **return_path(data_t *data, int check, int previous_id, int where)
{
    char **path = malloc(sizeof(char *) * 999);
    int y = 0;
    room_t *room = data->list->first;

    while (room != NULL) {
        for (int i = 0; room->next[i] != NULL; i++) {
            if (room->next[i]->id == 0)
                return (finalize_path(path, room, y , i));
            if (room->next[i]->id <= check
                && room->next[i]->id != previous_id) {
                check = room->id;
                where = i;
            }
        }
        check = 9999;
        path[y] = my_strcpy(room->name);
        previous_id = room->id;
        room = room->next[where];
        y++;
    }
    path[y] = NULL;
    return (path);
}

void create_way(data_t *data)
{
    for (int i = 0; data->path[i]; i++)
        add_way(data, i);
}

room_t *add_way(data_t *data, int i)
{
    room_t *room;

    room = malloc(sizeof(room_t));
    room->single_next = NULL;
    room->name = my_strcpy(data->path[i]);
    room->ant = 0;
    room->id = 0;
    if (i == 0) {
        data->list->way = room;
        room->previous = NULL;
    }
    else {
        room->previous = data->list->last;
        room->previous->single_next = room;
    }
    data->list->last = room;
    return (room);
}
