/*
** EPITECH PROJECT, 2019
** parse_tunnels
** File description:
** lemin
*/

#include "../include/my.h"

int tunnels_error_2(data_t *data, int compt)
{
    int z = 0;

    for (int i = 0; data->tunnels[i] != NULL; i++) {
        if (my_strcmp(data->tunnels[i], data->rooms[data->end_y]) == 0)
            z++;
    }
    if (z == compt)
        return 84;
}

int tunnels_error(data_t *data)
{
    int y = 0;
    int compt = 0;

    if (!data->tunnels[0])
        return (84);
    for (int i = 0; data->tunnels[i] != NULL; i += 2)
        if (my_strcmp(data->tunnels[i], data->tunnels[i + 1]) == 1)
            return (84);
    for (int i = 0; data->tunnels[i] != NULL; i++)
        compt++;
    for (int i = 0; data->tunnels[i] != NULL; i++)
        if (my_strcmp(data->tunnels[i], data->rooms[data->start_y]) == 0)
            y++;
    if (y == compt)
        return 84;
    if (tunnels_error_2(data, compt) == 84)
        return 84;
}

int sort_tunnels(data_t *data)
{
    int size = 0;
    int room_y = 0;

    for (int i = 0; data->file[i] != NULL; i++)
        if (check_if_tunnels(data->file[i]) == 1)
            size += 1;
    data->tunnels = malloc(sizeof(char *) * ((2 * size) + 1));
    for (int i = 0; data->file[i] != NULL; i++) {
        if (check_if_tunnels(data->file[i]) == 1) {
            data->tunnels = tunnels_to_tab(data->file[i],
            data->tunnels, room_y);
            room_y += 2;
        }
    }
    data->tunnels[room_y] = NULL;
    if (tunnels_error(data) == 84)
        return 84;
    return (0);
}

char **tunnels_to_tab(char *str, char **tab, int y)
{
    char *tmp = malloc(sizeof(char) * 20);
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != '-'; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    tab[y] = my_strcpy(tmp);
    y += 1;
    i += 1;
    free(tmp);
    tmp = malloc(sizeof(char) * 20);
    for (j = 0; str[i] != '\0'; i++, j++)
        tmp[j] = str[i];
    tmp[j] = '\0';
    tab[y] = my_strcpy(tmp);
    free(tmp);
    return (tab);
}

int check_if_tunnels(char *str)
{
    int i = 0;

    while (str[i] != '-') {
        if (str[i] == '\0' || str[i] == ' ')
            return (0);
        i += 1;
    }
    i += 1;
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '-')
            return (0);
        i += 1;
    }
    return (1);
}
