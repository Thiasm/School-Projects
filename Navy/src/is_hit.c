/*
** EPITECH PROJECT, 2019
** is hit
** File description:
** functions to check if a boat got hit
*/

#include "navy.h"

info_t info;

int check_pos(game_var_t *game_var)
{
    int line = info.play[1] - 47;
    int col;

    col = 2 + (info.play[0] - 65) * 2;
    if (game_var->map[line][col] != '.' && game_var->map[line][col] != 'x'
        && game_var->map[line][col] != 'o') {
        game_var->map[line][col] = 'x';
        my_putstr(info.play);
        my_putstr(": hit\n\n");
        game_var->life -= 1;
        return (1);
    } else {
        game_var->map[line][col] = 'o';
        my_putstr(info.play);
        my_putstr(": missed\n\n");
        return (2);
    }
}

void is_hit(game_var_t *game_var)
{
    if (check_pos(game_var) == 1) {
        usleep(5000);
        kill(info.other_pid, SIGUSR2);
        pause();
    } else {
        usleep(5000);
        kill(info.other_pid, SIGUSR1);
        pause();
    }
}

void add_missed(game_var_t *game_var)
{
    int line = info.play[1] - 47;
    int col = 2 + (info.play[0] - 65) * 2;

    game_var->enemy_map[line][col] = 'o';
}

void add_hit(game_var_t *game_var)
{
    int line = info.play[1] - 47;
    int col = 2 + (info.play[0] - 65) * 2;

    game_var->enemy_map[line][col] = 'x';
}
