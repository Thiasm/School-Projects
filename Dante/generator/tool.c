/*
** EPITECH PROJECT, 2019
** tool.c
** File description:
** tool.c
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

char **malloc_tab(int x, int y)
{
    char **map;
    int i;

    if ((map = malloc(sizeof(char *) * (y + 1))) == NULL)
        exit(84);
    for (i = 0; i < y; i++) {
        map[i] = malloc(sizeof(char) * (x + 1));
    }
    map[i] = NULL;
    return (map);
}

int my_strcmp(char *string, char *str)
{
    for (int i = 0; string[i] == str[i]; i++)
        if (string[i] == '\0' && str[i] == '\0')
            return (1);
    return (0);
}

void print_free_map(data_t *data)
{
    int j = 0;

    for (int y = 0; data->map[y] != NULL; y++) {
        for (int x = 0; data->map[y][x] != '\0'; x++)
            putchar(data->map[y][x]);
        if (y != data->y - 1)
            putchar('\n');
    }
    for (int i = 0; data->map[i] != NULL; i++)
        free(data->map[i]);
    free(data->map);
}
