/*
** EPITECH PROJECT, 2019
** create_list
** File description:
** CPE_lemin_2018
*/

#include "../include/my.h"

room_t *add_room(data_t *data, list_t *list, int i)
{
    room_t *room;

    room = malloc(sizeof(room_t));
    list->size += 1;
    room->single_next = NULL;
    room->name = data->rooms[i];
    room->id = -2;
    room->ant = 0;
    room->next = NULL;
    room->previous = list->last;
    list->last->single_next = room;
    list->last = room;
    return (room);
}

room_t *create_start(data_t *data, list_t *list)
{
    room_t *room;

    room = malloc(sizeof(room_t));
    room->single_next = NULL;
    list->size = 1;
    room->name = data->rooms[data->start_y];
    room->id = -1;
    room->ant = 0;
    room->next = NULL;
    room->previous = NULL;
    list->first = room;
    list->last = room;
    return (room);
}

room_t *create_end(data_t *data, list_t *list)
{
    room_t *room;

    room = malloc(sizeof(room_t));
    list->size += 1;
    room->single_next = NULL;
    room->name = data->rooms[data->end_y];
    room->id = 0;
    room->ant = 0;
    room->next = NULL;
    room->previous = list->last;
    room->previous->single_next = room;
    list->last = room;
    return (room);
}

list_t *create_first(data_t *data)
{
    list_t *list;

    list = malloc(sizeof(list_t));
    list->first = NULL;
    list->last = NULL;
    list->way = NULL;
    list->size = 0;
    return (list);
}

void link_rooms(data_t *data)
{
    data->list = create_first(data);
    create_start(data, data->list);
    for (int i = 0; data->rooms[i] != NULL; i += 3) {
        if (i == data->start_y || i == data->end_y)
            if (data->rooms[i + 3])
                i += 3;
            else {
                create_end(data, data->list);
                return;
            }
        if (i != data->start_y && i != data->end_y)
            add_room(data, data->list, i);
    }
    create_end(data, data->list);
}
