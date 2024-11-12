/*
** EPITECH PROJECT, 2019
** find_matches
** File description:
** matchstick
*/

#include "my.h"

int find_match(data_t *data)
{
    int nb = how_many_stick(data->map[data->line]);
    char *matches;
    size_t i = 0;

    if (data->print_matches == 0)
        my_putstr("Matches: ");
    data->print_matches = 1;
    if (getline(&matches, &i, stdin) == -1)
        return (84);
    matches_error(my_atoi(matches), data, matches);
    return (0);
}

void matches_error(int tmp, data_t *data, char *matches)
{
    if (tmp < 0 || tmp == -84 || check_if_number(matches) == 84) {
        my_putstr("Error: invalid input (positive number expected)\n");
        data->print_line = 0;
        data->print_matches = 0;
        get_data(data);
    }
    else if (tmp == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        data->print_line = 0;
        data->print_matches = 0;
        get_data(data);
    }
    else
        last_matches_error(tmp, data);
}

void last_matches_error(int tmp, data_t *data)
{
    if (tmp > how_many_stick(data->map[data->line])) {
        my_putstr("Error: not enough matches on this line\n");
        data->print_line = 0;
        data->print_matches = 0;
        get_data(data);
    }
    else if (tmp > data->max_matchs) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(data->max_matchs);
        my_putstr(" matches per turn\n");
        data->print_line = 0;
        data->print_matches = 0;
        get_data(data);
    }
    else {
        data->matchs = tmp;
        data->ask_matches = 0;
    }
}
