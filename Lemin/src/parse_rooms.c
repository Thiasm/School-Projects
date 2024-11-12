/*
** EPITECH PROJECT, 2019
** parse_room
** File description:
** lemin
*/

#include "../include/my.h"

int sort_rooms(data_t *data)
{
    int size = 0;
    int room_y = 0;

    for (int i = 0; data->file[i] != NULL; i++)
        if (check_if_room(data->file[i]) == 1)
            size += 1;
    data->rooms = malloc(sizeof(char *) * ((3 * size) + 1));
    for (int i = 0; data->file[i] != NULL; i++) {
        if (my_strcmp(data->file[i], "##start") == 1)
            data->start_y = room_y;
        if (my_strcmp(data->file[i], "##end") == 1)
            data->end_y = room_y;
        if (check_if_room(data->file[i]) == 1) {
            data->rooms = room_to_tab(data->file[i], data->rooms, room_y);
            room_y += 3;
        }
    }
    data->rooms[room_y] = NULL;
    if (error_room(data) == 84)
        return (84);
    return (0);
}

char **room_to_tab(char *str, char **tab, int y)
{
    char *tmp = malloc(sizeof(char) * 20);
    int i = 0;

    for (i = 0; str[i] != ' '; i++)
        tmp[i] = str[i];
    tmp[i] = '\0';
    i += 1;
    tab[y] = my_strcpy(tmp);
    y++;
    tab = room_to_tab_2(i, str, tab, y);
    free(tmp);
    return (tab);
}

char **room_to_tab_2(int i, char *str, char **tab, int x)
{
    char *tmp = malloc(sizeof(char) * 20);
    int j = 0;

    for (j = 0; str[i] != ' '; i++) {
        tmp[j] = str[i];
        j += 1;
    }
    tmp[j] = '\0';
    i += 1;
    tab[x] = my_strcpy(tmp);
    x++;
    free(tmp);
    tmp = malloc(sizeof(char) * 20);
    for (j = 0; str[i] != '\0'; i++) {
        tmp[j] = str[i];
        j += 1;
    }
    tmp[j] = '\0';
    tab[x] = my_strcpy(tmp);
    free(tmp);
    return (tab);
}

int check_if_room(char *str)
{
    int i = 0;

    while (str[i] != ' ') {
        if (str[i] == '\0' || str[i] == '-')
            return (0);
        i += 1;
    }
    i += 1;
    while (str[i] != ' ')
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    if (str[i + 1] != '\0')
        i += 1;
    while (str[i] != '\0')
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    return (1);
}
