/*
** EPITECH PROJECT, 2018
** move_player
** File description:
** sokoban
*/

#include "my.h"

void move_player(var_t *var, pos_t *pos)
{
    switch (var->key) {
    case 65 :
        if (pos->y > 0)
            move_top(var, pos);
        break;
    case 66 :
        if (pos->y < var->lines - 2)
            move_down(var, pos);
        break;
    case 68 :
        if (pos->x > 0)
            move_left(var, pos);
        break;
    case 67 :
        if (pos->x < var->longer - 1)
            move_right(var, pos);
        break;
    }
}

void move_top(var_t *var, pos_t *pos)
{
    int i = 0;

    if (var->map[pos->y - 1][pos->x] == 'X') {
        if (var->map[pos->y - 2][pos->x] != '#'
            && pos->y - 2 != 0) {
            var->map[pos->y - 1][pos->x] = ' ';
            var->map[pos->y - 2][pos->x] = 'X';
            pos->y--;
        }
    }
    else if (var->map[pos->y - 1][pos->x] != '#')
        pos->y--;
}

void move_down(var_t *var, pos_t *pos)
{
    int i = 0;

    if (var->map[pos->y + 1][pos->x] == 'X') {
        if (var->map[pos->y + 2][pos->x] != '#' &&
            var->map[pos->y + 2][pos->x] != 'X') {
            var->map[pos->y + 1][pos->x] = ' ';
            var->map[pos->y + 2][pos->x] = 'X';
            pos->y++;
        }
    }
    else if (var->map[pos->y + 1][pos->x] != '#')
        pos->y++;
}

void move_left(var_t *var, pos_t *pos)
{
    int i = 0;

    if (var->map[pos->y][pos->x - 1] == 'X') {
        if (var->map[pos->y][pos->x - 2] != '#'
            && var->map[pos->y][pos->x - 2] != 'X'
            && pos->x > 1) {
            var->map[pos->y][pos->x - 1] = ' ';
            var->map[pos->y][pos->x - 2] = 'X';
            pos->x--;
        }
    }
    else if (var->map[pos->y][pos->x - 1] != '#')
        pos->x--;
}

void move_right(var_t *var, pos_t *pos)
{
    int i = 0;

    if (var->map[pos->y][pos->x + 1] == 'X') {
        if (var->map[pos->y][pos->x + 2] != '#' &&
            var->map[pos->y][pos->x + 2] != 'X') {
            var->map[pos->y][pos->x + 1] = ' ';
            var->map[pos->y][pos->x + 2] = 'X';
            pos->x++;
        }
    }
    else if (var->map[pos->y][pos->x + 1] != '#')
        pos->x++;
}
