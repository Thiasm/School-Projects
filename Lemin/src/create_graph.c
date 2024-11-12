/*
** EPITECH PROJECT, 2019
** create_graph.c
** File description:
** Create the anthill with chained lists
*/

#include "../include/my.h"

int *find_connection(char *name, char **tunnels, int size)
{
    int *rank = malloc(sizeof(int *) * size);
    int i = 0;

    for (int y = 0; tunnels[y] != NULL; y++) {
        if (my_strcmp(name, tunnels[y]) == 1) {
            if (y % 2 == 0)
                rank[i] = y + 1;
            else
                rank[i] = y - 1;
            i++;
        }
    }
    rank[i] = -1;
    return (rank);
}

struct room_s *find_associated_room(int rank, data_t *data)
{
    room_t *buff = data->list->first;

    while (buff != NULL) {
        if (my_strcmp(buff->name, data->tunnels[rank]) == 1) {
            return (buff);
        }
        buff = buff->single_next;
    }
    return (NULL);
}

void create_graph(data_t *data)
{
    room_t *buff = data->list->first;
    int *rank;
    int i;
    int y;

    while (buff != NULL) {
        rank = find_connection(buff->name, data->tunnels, data->list->size);
        buff->next = malloc(sizeof(room_t) *
        (how_many_next(buff->name, data->tunnels) + 1));
        for (i = 0, y = 0; rank[i] != -1; i++) {
            buff->next[y] = find_associated_room(rank[i], data);
            if (buff->next[y] != NULL)
                y++;
        }
        buff->next[y] = NULL;
        free(rank);
        buff = buff->single_next;
    }
}
