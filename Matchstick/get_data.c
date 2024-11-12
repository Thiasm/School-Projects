/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** get_data.c
*/

#include "my.h"

int get_data(data_t *data)
{
    int value = 0;

    value = find_line(data);
    if (data->line == 0)
        value = find_line(data);
    if (data->matchs == 0)
        value = find_line(data);
    return (value);
}