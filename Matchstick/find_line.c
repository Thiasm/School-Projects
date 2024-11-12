/*
** EPITECH PROJECT, 2019
** find_line
** File description:
** matchstick
*/

#include "my.h"

int find_line(data_t *data)
{
    char *line = NULL;
    size_t i = 0;

    if (data->print_line == 0)
        my_putstr("Line: ");
    data->print_line = 1;
    if (getline(&line, &i, stdin) == -1)
        return (84);
    error_line(data, my_atoi(line), line);
    if (data->ask_matches == 1 && data->line > 0)
        if (find_match(data) == 84)
            return (84);
    return (0);
}

void error_line(data_t *data, int tmp, char *line)
{
    if (check_if_number(line) == 84 || tmp < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        data->print_line = 0;
        get_data(data);
    }
    else if (tmp > data->height || tmp == 0) {
        my_putstr("Error: this line is out of range\n");
        data->print_line = 0;
        get_data(data);
    }
    else
        data->line = tmp;
}
