/*
** EPITECH PROJECT, 2019
** algo.c
** File description:
** algo
*/

#include "my.h"

int add_to_close(data_t *data, node_t *new)
{
    new->close = 1;
    if (new->x == (data->width - 1) && new->y == (data->height - 1)) {
        print_path(data, new);
        return (1);
    }
    return (0);
}

int check_node(node_t *origin, data_t *data, int y, int x)
{
    node_t *node = data->list.first;

    if (data->maze[y][x] != '*')
        return (84);
    while (node) {
        if (node->x == x && node->y == y)
            return (84);
        node = node->next;
    }
    return (0);
}

void add_to_open(data_t *data, node_t *parent, int y, int x)
{
    node_t *new = malloc(sizeof(node_t));

    new->close = 0;
    new->parent = parent;
    new->x = x;
    new->y = y;
    new->next = data->list.first;
    data->list.first = new;
    new->cost = get_cost(data, x, y);
}

void find_friends(node_t *close, data_t *data)
{
    if (close->x > 0)
        if (check_node(close, data, close->y, close->x - 1) == 0)
            add_to_open(data, close, close->y, close->x - 1);
    if (close->x < data->width - 1)
        if (check_node(close, data, close->y, close->x + 1) == 0)
            add_to_open(data, close, close->y, close->x + 1);
    if (close->y > 0)
        if (check_node(close, data, close->y - 1, close->x) == 0)
            add_to_open(data, close, close->y - 1, close->x);
    if (close->y < data->height - 1)
        if (check_node(close, data, close->y + 1, close->x) == 0)
            add_to_open(data, close, close->y + 1, close->x);
}
