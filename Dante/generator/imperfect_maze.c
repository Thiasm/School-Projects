/*
** EPITECH PROJECT, 2019
** generate.c
** File description:
** generate maze
*/

#include "my.h"

void imperfect_maze(data_t *data)
{
    fill_maze(data);
    perfect_algo(data);
    create_imperfect(data);
    ajust_perfect(data);
}

void create_imperfect(data_t *data)
{
    int y = 0;
    int x = 0;
    int nb_break = 0;

    nb_break = (data->y * data->x) / 2;
    for (int i = 0; i < nb_break; i++) {
        y = rand()%data->y;
        x = rand()%data->x;
        data->map[y][x] = '*';
    }
}
