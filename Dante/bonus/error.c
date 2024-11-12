/*
** EPITECH PROJECT, 2019
** error
** File description:
** solver
*/

#include "my.h"

int get_data(data_t *data)
{
    int x = strlen(data->maze[0]);

    for (int i = 0; data->maze[i] != NULL; i++) {
        data->height += 1;
        if (strlen(data->maze[i]) != x) {
            write(2, "Invalid map\n", 12);
            exit(84);
        }
    }
    data->width = x - 1;
}

void error_handling(char *str, int y, data_t *data)
{
    if (str[0] != 'X' && str[0] != '*') {
        data->maze[y] = NULL;
        free(str);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
        if (str[i] != 'X' && str[i] != '*' && str[i] != '\0') {
            write(2, "Invalid map\n", 12);
            exit(84);
        }
    }
}