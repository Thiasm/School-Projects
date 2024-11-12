/*
** EPITECH PROJECT, 2018
** create tab
** File description:
** sokoban
*/

#include "my.h"

char **map_to_tab(var_t *var)
{
    int buffer_i = 0;
    int xmax = 0;

    var->map = malloc(sizeof(char *) * (var->lines));
    for (int y = 0; y < var->lines; y++) {
        var->map[y] = malloc(sizeof(char) * (var->longer + 1));
        for (int x = 0; var->buffer[buffer_i] != '\n'; x++) {
            if (var->buffer[buffer_i] == '\0')
                return (var->map);
            var->map[y][x] = var->buffer[buffer_i];
            buffer_i++;
            xmax = x;
        }
        var->map[y][xmax + 1] = '\0';
        buffer_i++;
    }
}

void find_line(var_t *var)
{
    var->lines = 1;
    for (int i = 0; i < var->size; i++)
        if (var->buffer[i] == '\n')
            var->lines++;
}

int my_strline(char *str)
{
    int rng = 0;

    while (str[rng] != '\n') {
        rng++;
    }
    return (rng);
}

void error(var_t *var, pos_t *pos, int argc)
{
    for (int y = 0; y < var->lines; y++) {
        for (int x = 0; var->map[y][x] != '\0'; x++) {
            if (var->map[y][x] != ' ' && var->map[y][x] != 'P' && var->map[y]
                [x]!= 'X' && var->map[y][x] != '#' && var->map[y][x] != 'O')
                exit(84);
        }
    }
    if (var->nb_x != var->obj || var->nb_x == 0)
        exit(84);
}
