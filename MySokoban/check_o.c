/*
** EPITECH PROJECT, 2018
** check_succes
** File description:
** sokoban
*/

#include "my.h"

void game_on(var_t *var, pos_t *pos, WINDOW *sokoban)
{
    clear();
    if (LINES < var->lines || COLS < var->longer)
        check_window_size(sokoban, var, pos);
    else
        game_boucle(var, pos);
    refresh();
}

int win_game(pos_t *pos, var_t *var)
{
    int i = 0;

    for (int y = 0; y < var->lines; y++) {
        for (int x = 0; var->map[y][x] != '\0' ; x++) {
            if (var->map[y][x] == 'O')
                return (0);
        }
    }
    var->game = 0;
}

void find_o_pos(pos_t *pos, var_t *var)
{
    pos->tab_pos_o = malloc(sizeof(int *) * var->obj);
    for (int y = 0; y < var->lines; y++) {
        for (int x = 0; var->map[y][x] != '\0'; x++) {
            if (var->map[y][x] == 'O') {
                pos->tab_pos_o[pos->y_o] = malloc(sizeof(int) * 2);
                pos->tab_pos_o[pos->y_o][0] = y;
                pos->tab_pos_o[pos->y_o][1] = x;
                pos->y_o++;
            }
        }
    }
}

void back_mark(pos_t *pos, var_t *var)
{
    int i = 0;

    while (i < pos->y_o) {
        if (var->map[pos->tab_pos_o[i][0]][pos->tab_pos_o[i][1]] == ' ')
            var->map[pos->tab_pos_o[i][0]][pos->tab_pos_o[i][1]] = 'O';
        i++;
    }
}
