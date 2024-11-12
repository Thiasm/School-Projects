/*
** EPITECH PROJECT, 2019
** is_path.c
** File description:
** is path
*/

#include "../include/my.h"

int is_path(data_t *data, game_t *game)
{
    int x = data->mouse_x;
    int y = data->mouse_y;

    if (y > 300 && y < 500 && x > 0 && x < 1200)
        return (1);
    if (y > 300 && y < 800 && x > 1200 && x < 1400)
        return (1);
    if (y > 600 && y < 800 && x > 1400 && x < 1920)
        return (1);
    return (0);
}
