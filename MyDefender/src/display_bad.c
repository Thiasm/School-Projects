/*
** EPITECH PROJECT, 2019
** display_bad
** File description:
** defender
*/

#include "../include/my.h"

void display_bad(data_t *data, game_t *game)
{
    if (game->wave > 0)
        data->bad_pos = spawn_bad(data, game);
    move_ajax(data, game);
    anime_bad(data, game);
    sfText_setString(game->setting.life_text, my_itoc(game->life));
    sfText_setString(game->setting.money_text, my_itoc(game->money));
}

void anime_bad(data_t *data, game_t *game)
{
    game->bad.time_bad = sfClock_getElapsedTime(game->bad.clock_bad);
    game->bad.second_bad = game->bad.time_bad.microseconds / 1000000.0;
    if (game->bad.second_bad >= 0.25) {
        if (game->bad.rect_slime.left >= 150)
            game->bad.rect_slime.left = 0;
        game->bad.rect_slime.left += 50;
        sfClock_restart(game->bad.clock_bad);
    }
}

int **spawn_bad(data_t *data, game_t *game)
{
    int i;
    int x = 2500 + (100 * game->wave);
    int y = 800;
    int **pos = malloc(sizeof(int *) * (game->wave + 1));

    for (i = 0; game->wave > 0; i++) {
        pos[i] = malloc(sizeof(int) * 5);
        pos[i][0] = x;
        pos[i][1] = y;
        pos[i][2] = 100;
        pos[i][3] = game->bad.speed;
        pos[i][4] = 1;
        x -= 100;
        game->wave -= 1;
    }
    pos[i] = NULL;
    return (pos);
}

void set_bad(game_t *game)
{
    game->bad.s_slime = create_sprite("ressource/slime.png",
    (sfVector2f){2000, 800});
    game->bad.rect_slime.width = 50;
    game->bad.rect_slime.height = 50;
    game->bad.rect_slime.top = 0;
    game->bad.rect_slime.left = 0;
}
