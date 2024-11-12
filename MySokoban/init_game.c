/*
** EPITECH PROJECT, 2018
** init_game
** File description:
** sokoban
*/

#include "my.h"

void display_map(var_t *var)
{
    curs_set(0);
    for (int y = 0; y < var->lines; y++) {
        for (int x = 0; var->map[y][x] != '\0'; x++) {
            mvprintw(y, x, "%c", var->map[y][x]);
        }
    }
}

void find_p(pos_t *pos, var_t *var)
{
    for (int y = 0; y < var->lines; y++) {
        for (int x = 0; var->map[y][x] != '\0' ; x++) {
            check_map(pos, var, y, x);
        }
    }
}

void check_map(pos_t *pos, var_t *var, int y, int x)
{
    if (var->map[y][x] == 'P') {
        pos->x = x;
        pos->y = y;
        var->map[y][x] = ' ';
    }
    if (var->map[y][x] == 'O')
        var->obj++;
    if (var->map[y][x] == 'X')
        var->nb_x++;
}

void reset_game(var_t *var, pos_t *pos)
{
    if (var->key == 32) {
        var->obj = 0;
        var->map[pos->y][pos->x] = ' ';
        var->map = map_to_tab(var);
        find_p(pos, var);
    }
    quit_game(var, pos);
}

void quit_game(var_t *var, pos_t *pos)
{
    if (var->key == 113)
        var->game = 0;
}
