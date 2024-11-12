/*
** EPITECH PROJECT, 2019
** create_map
** File description:
** matchstick
*/

#include "my.h"

void empty_line(data_t *data, int where)
{
    int x = 0;

    for (x = 0; x < data->width; x++)
        data->map[where][x] = '*';
    data->map[where][x] = '\0';
}

void create_map(data_t *data)
{
    int nb_matches = 0;

    empty_line(data, 0);
    for (int y = 1; y < data->height + 1; y++) {
        nb_matches = ((y - 1) * 2) + 1;
        put_matches(data, y, nb_matches);
    }
    empty_line(data, data->height + 1);
}

void put_matches(data_t *data, int y, int nb_matches)
{
    int x = 0;

    for (x = 0; x < data->width; x++) {
        if (x == 0 || x == data->width - 1)
            data->map[y][x] = '*';
        else if (x >= (data->width / 2) - (y - 1) && nb_matches > 0) {
            data->map[y][x] = '|';
            nb_matches--;
        }
        else
            data->map[y][x] = ' ';
    }
    data->map[y][x] = '\0';
}

void print_map(data_t *data)
{
    for (int h = 0; h < data->height + 2; h++) {
        my_putstr(data->map[h]);
        my_putchar('\n');
    }
    my_putchar('\n');
}

int player_turn(data_t *data)
{
    int nb_delete = 0;

    my_putstr("Your turn:\n");
    if (get_data(data) == 84)
        return (84);
    nb_delete = data->matchs;
    for (int x = data->width; x >= 0 & nb_delete > 0; x--) {
        if (data->map[data->line][x] == '|') {
            data->map[data->line][x] = ' ';
            nb_delete--;
        }
    }
    data->nb_stick -= data->matchs;
    print_action(data, "Player");
    if (data->nb_stick <= 0)
        return (2);
    else
        return (0);
}
