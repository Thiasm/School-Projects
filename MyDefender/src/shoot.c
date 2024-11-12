/*
** EPITECH PROJECT, 2019
** shoot.c
** File description:
** shoot
*/

#include "../include/my.h"

void canon_shoot(data_t *data, game_t *game)
{
    game->bad.time_mine = sfClock_getElapsedTime(game->bad.mine_clock);
    game->bad.mine_sec = game->bad.time_mine.microseconds / 1000000.0;
    if (game->bad.mine_sec >= 5.0) {
        for (int i = 0; data->tower_pos[i] != NULL; i++) {
            if (data->tower_pos[i][2] == 4)
                game->money += 200;
        }
        sfClock_restart(game->bad.mine_clock);
    }
    for (int i = 0; data->tower_pos[i] != NULL; i++)
        parcours_bad(data, i, game);
    }

void parcours_bad(data_t *data, int i, game_t *game)
{
    for (int k = 0; data->bad_pos[k] != NULL; k++) {
        if (data->bad_pos[k][0] >  data->tower_pos[i][0] - 300 &&
            data->bad_pos[k][0] <  data->tower_pos[i][0] + 300 &&
            data->bad_pos[k][1] >  data->tower_pos[i][1] - 300 &&
            data->bad_pos[k][1] <  data->tower_pos[i][1] + 300) {
            if (data->tower_pos[i][2] == 1)
                kill_bad_normal(data, game, k, i);
            if (data->tower_pos[i][2] == 2)
                kill_big(data, game, k, i);
            if (data->tower_pos[i][2] == 3)
                slow_enemi(data, game, k, i);
        }
    }
}

void kill_bad_normal(data_t *data, game_t *game, int k, int i)
{
    game->bad.shoot = sfClock_getElapsedTime(game->bad.clock_shoot);
    game->bad.shoot_sec = game->bad.shoot.microseconds / 1000000.0;
    if (game->bad.shoot_sec >= 0.90) {
        if (data->bad_pos[k][2] <= 0 && data->bad_pos[k] != NULL)
            return;
        data->bad_pos[k][2] -= 100;
        check_death(data, game, k);
        end_wave(data, game);
        sfClock_restart(game->bad.clock_shoot);
    }
    if (data->bad_pos[k][3] < game->bad.speed)
        data->bad_pos[k][3] += 1.0;
}

void kill_big(data_t *data, game_t *game, int k, int i)
{
    game->bad.shoot_big = sfClock_getElapsedTime(game->bad.big);
    game->bad.big_sec = game->bad.shoot_big.microseconds / 1000000.0;
    if (game->bad.big_sec >= 2.00) {
        if (data->bad_pos[k][2] <= 0 && data->bad_pos[k] != NULL)
            return;
        data->bad_pos[k][2] -= 101;
        if (data->bad_pos[k + 1])
            data->bad_pos[k + 1][2] -= 101;
        check_death(data, game, k);
        end_wave(data, game);
        sfClock_restart(game->bad.big);
    }
}

void slow_enemi(data_t *data, game_t *game, int k, int i)
{
    game->bad.shoot_slow = sfClock_getElapsedTime(game->bad.slow);
    game->bad.slow_sec = game->bad.shoot_slow.microseconds / 1000000.0;
    if (game->bad.slow_sec >= 1.5) {
        data->bad_pos[k][3] = 1;
        check_death(data, game, k);
        end_wave(data, game);
        sfClock_restart(game->bad.slow);
    }
}
