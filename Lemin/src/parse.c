/*
** EPITECH PROJECT, 2019
** parse
** File description:
** lemin
*/

#include "../include/my.h"

int parse_file(char *filepath, data_t *data)
{
    int i = 0;
    size_t k = 0;
    int size = 20;

    data->file = malloc(sizeof(char *) * size);
    data->file[0] = malloc(sizeof(char) * 50);
    while (getline(&data->file[i], &k, stdin) != -1) {
        i++;
        data->file[i] = malloc(sizeof(char) * 50);
        if (i >= size) {
            size += 5;
            data->file = my_realloc_tab(data->file, size);
        }
    }
    data->file[i] = NULL;
    if (sort_data(data) == 84)
        return (84);
    return (0);
}

int sort_data(data_t *data)
{
    data->check = 0;
    data->file = clear_comment(data->file);
    if (data->check == 0)
        data->check = find_ant_nbr(data);
    if (data->check == 0)
        data->check = sort_rooms(data);
    if (data->check == 0)
        data->check = sort_tunnels(data);
    if (data->check == 0)
        data->check = count_start_end(data->file, 0, 0);
    if (data->check != 0)
        return 84;
    return (0);
}
