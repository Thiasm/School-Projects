/*
** EPITECH PROJECT, 2019
** generate.c
** File description:
** generate maze
*/

#include "my.h"

void check_arround(int y, int x, data_t *data)
{
    int random = 0;
    int up = 0;
    int left = 0;

    if (y - 1 >= 0 && data->map[y - 1][x] == 'X')
        up = 1;
    if (x - 1 >= 0 && data->map[y][x - 1] == 'X')
        left = 1;
    if (y - 1 >= 0 && up == 1 && left == 0)
        data->map[y - 1][x] = '*';
    if (x - 1 >= 0 && up == 0 && left == 1)
        data->map[y][x - 1] = '*';
    if (up == 1 && left == 1) {
        random = rand()%2;
        if (x - 1 >= 0 && random == 0)
            data->map[y][x - 1] = '*';
        else if (y - 1 >= 0 && random == 1)
            data->map[y - 1][x] = '*';
    }
}

void perfect_algo(data_t *data)
{
    int y = 0;
    int x = 0;

    for (y = 0; y < data->y; y += 2) {
        for (x = 0; x < data->x; x += 2) {
            if (y == 0)
                data->map[y][x] = '*';
            check_arround(y , x, data);
        }
    }
}

void ajust_perfect(data_t *data)
{
    if (data->map[data->y - 1][data->x - 2] == 'X'
    && data->map[data->y - 2][data->x - 1] == 'X')
        data->map[data->y - 1][data->x - 2] = '*';
    data->map[data->y - 1][data->x - 1] = '*';
}

void perfect_maze(data_t *data)
{
    fill_maze(data);
    perfect_algo(data);
    ajust_perfect(data);
}

void fill_maze(data_t *data)
{
    int x = 0;
    int y = 0;

    for (y = 0; y < data->y; y++) {
        for (x = 0; x < data->x; x++) {
            if (x % 2 == 0 && y % 2 == 0)
                data->map[y][x] = '*';
            else
                data->map[y][x] = 'X';
        }
        data->map[y][x] = '\0';
    }
}
