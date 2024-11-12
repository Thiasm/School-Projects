/*
** EPITECH PROJECT, 2019
** algo.c
** File description:
** algo
*/

#include "my.h"

int init_algo(data_t *data)
{
    node_t *root = malloc(sizeof(node_t));

    data->list.first = root;
    root->parent = NULL;
    root->close = 0;
    root->cost = 0;
    root->x = 0;
    root->y = 0;
    root->next = NULL;
    return (0);
}

int get_cost(data_t *data, int x, int y)
{
    int g_cost = 0;
    int h_cost = 0;
    int f_cost = 0;

    h_cost = x + y;
    g_cost = ((data->height - 1) - x) + ((data->width - 1) - y);
    f_cost = g_cost + h_cost;
    return (f_cost);
}

int a_star_loop(data_t *data)
{
    node_t *lowest = find_lowest_cost(data);

    if (add_to_close(data, lowest) == 1)
        return (1);
    find_friends(lowest, data);
    return (0);
}

int a_star(data_t *data)
{
    init_algo(data);
    while (open_number(data) > 0) {
        if (a_star_loop(data) == 1) {
            return (1);
        }
    }
    printf("no solution found");
    return (0);
}