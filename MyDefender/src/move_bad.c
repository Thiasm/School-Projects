/*
** EPITECH PROJECT, 2019
** move_bad
** File description:
** defender
*/

#include "../include/my.h"

void move_ajax(data_t *data, game_t *game)
{
    game->bad.time_move_bad = sfClock_getElapsedTime(game->bad.clock_move_bad);
    game->bad.second_move_bad =
    game->bad.time_move_bad.microseconds / 1000000.0;
    for (int i = 0; data->bad_pos[i] != NULL; i++) {
        if ((check_death(data, game, i) == 0) &&
        (game->bad.second_move_bad >= 0.0003)) {
            check_way(data, game, i);
            sfSprite_setPosition(game->bad.s_slime,
            (sfVector2f){data->bad_pos[i][0], data->bad_pos[i][1]});
            sfSprite_setTextureRect(game->bad.s_slime, game->bad.rect_slime);
            sfRenderWindow_drawSprite(data->window, game->bad.s_slime, NULL);
            sfClock_restart(game->bad.clock_move_bad);
            end_wave(data, game);
        }
    }
}

void check_way(data_t *data, game_t *game, int i)
{
    if (data->bad_pos[i][0] > 1100)
        data->bad_pos[i][0] -= data->bad_pos[i][3];
    else if (data->bad_pos[i][1] > 350)
                data->bad_pos[i][1] -= data->bad_pos[i][3];
    else {
        if (data->bad_pos[i][0] > 200)
            data->bad_pos[i][0] -= data->bad_pos[i][3];
        else {
            data->bad_pos[i][4] = 0;
            game->life -= 1;
        }
    }
}

int end_wave(data_t *data, game_t *game)
{
    for (int i = 0; data->bad_pos[i] != NULL; i++)
        if (data->bad_pos[i][4] == 1)
            return (0);
    game->bad.wave_tmp += 3;
    game->bad.speed += 0.5;
    game->wave = game->bad.wave_tmp;
    sfText_setString(game->setting.wave_text, my_itoc(game->wave));
    return (1);
}

int check_death(data_t *data, game_t *game, int i)
{
    if (data->bad_pos[i][2] <= 0) {
        if (data->bad_pos[i][4] == 1) {
            game->money += 50;
            data->bad_pos[i][4] = 0;
            sfMusic_play(game->setting.die);
            return (1);
        }
    }
    if (data->bad_pos[i][4] == 0)
        return (1);
    return (0);
}
