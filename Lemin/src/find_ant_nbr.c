/*
** EPITECH PROJECT, 2019
** find_ant_nbr.c
** File description:
** Find the number of ant in the file
*/

#include "../include/my.h"
#include <string.h>

int find_ant_nbr(data_t *data)
{
    char *line = data->file[0];

    if (line == NULL)
        return (84);
    for (int x = 0; line[x] != '\0'; x++) {
        if (line[x] > '9' || line[x] < '0')
            return (84);
    }
    data->ant_number = my_atoi(line);
    if (data->ant_number <= 0)
        return (84);
    return (0);
}
