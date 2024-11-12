/*
** EPITECH PROJECT, 2019
** tool
** File description:
** solver
*/

#include "my.h"

char *my_strcpy(char *str)
{
    char *new;
    int i;

    new = malloc((strlen(str) + 1));
    for (i = 0; str[i]; i++)
        new[i] = str[i];
    new[i] = '\0';
    return (new);
}

void print_free_map(data_t *data)
{
    node_t *node = data->list.first;

    data->maze[data->height - 1][data->width] = 'o';
    for (int y = 0; y < data->height - 1; y++)
        printf("%s\n", data->maze[y]);
    printf("%s", data->maze[data->height - 1]);
    for (int i = 0; data->maze[i] != NULL; i++)
        free(data->maze[i]);
    free(data->maze);
    while (node->next) {
        data->list.first = node->next;
        free(node);
        node = data->list.first;
    }
}

node_t *find_lowest_cost(data_t *data)
{
    node_t *node = data->list.first;
    int lower = 9999;

    while (node) {
        if (node->close < lower && node->close == 0)
            lower = node->cost;
        node = node->next;
    }
    node = data->list.first;
    while (node) {
        if (node->cost == lower && node->close == 0)
            return (node);
        node = node->next;
    }
}

int open_number(data_t *data)
{
    int close = 0;
    int number = 0;
    node_t *node = data->list.first;

    while (node) {
        if (node->close == 0)
            number += 1;
        if (node->close == 1)
            close += 1;
        node = node->next;
    }
    return (number);
}

void print_path(data_t *data, node_t *node)
{
    while (node) {
        if (node->close == 1)
            data->maze[node->y][node->x] = 'o';
        node = node->parent;
    }
}
