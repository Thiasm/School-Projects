/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** ia.c
*/

#include "my.h"

int ia_turn(data_t *data)
{
    int nb_delete;

    my_putstr("AI's turn...\n");
    create_ia(data);
    nb_delete = data->matchs;
    for (int x = data->width; x >= 0 & nb_delete > 0; x--) {
        if (data->map[data->line][x] == '|') {
            data->map[data->line][x] = ' ';
            nb_delete--;
        }
    }
    data->nb_stick = data->nb_stick - data->matchs;
    print_action(data, "AI");
    if (data->nb_stick <= 0)
        return (1);
    else
        return (0);
}

void create_ia(data_t *data)
{
    int n = data->max_matchs;
    int N = data->nb_stick;
    int m = N % n;

    data->matchs = m - 1;
    if (data->matchs <= 0 || data->matchs > data->max_matchs)
        data->matchs = 1;
    ia_line(data);
}

void ia_line(data_t *data)
{
    data->line = data->height;
    while (how_many_stick(data->map[data->line]) < data->matchs ||
    data->line == 0) {
        data->line--;
        if (data->line == 0) {
            data->matchs--;
            ia_line(data);
        }
    }
}
