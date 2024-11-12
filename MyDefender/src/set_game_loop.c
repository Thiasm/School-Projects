/*
** EPITECH PROJECT, 2019
** set_game_loop
** File description:
** defender
*/

#include "../include/my.h"

void set_game_loop(data_t *data, game_t *game)
{
    set_level(data, game);
    set_bad(game);
    set_game_setting(game, data);
    set_game_pause(game, data);
    set_tower(game, data);
    sfMusic_play(game->setting.game_music);
    sfMusic_setLoop(game->setting.game_music, sfTrue);
}

void set_level(data_t *data, game_t *game)
{
    if (data->step == 3)
        game->setting.s_map = create_sprite(
            "ressource/map_land.png", (sfVector2f){0, 0});
    else if (data->step == 2)
        game->setting.s_map = create_sprite(
            "ressource/sand_map.png", (sfVector2f){0, 0});
    data->step = 0;
}

void set_tower(game_t *game, data_t *data)
{
    data->tower_pos = malloc(sizeof(int *) * 10);
    for (int i = 0; i < 9; i++) {
        data->tower_pos[i] = malloc(sizeof(int) * 4);
        data->tower_pos[i][0] = 0;
        data->tower_pos[i][1] = 0;
        data->tower_pos[i][2] = 0;
        data->tower_pos[i][3] = 0;
    }
    data->tower_pos[9] = NULL;
    more_set_tower(game, data);
}

void set_game_setting(game_t *game, data_t *data)
{
    game->bad.clock_bad = sfClock_create();
    game->bad.clock_move_bad = sfClock_create();
    game->wave = 5;
    game->bad.speed = 3.0;
    game->bad.wave_tmp = 5;
    game->life = 10;
    game->money = 1000;
    game->bad.clock_shoot = sfClock_create();
    game->bad.big = sfClock_create();
    game->bad.slow = sfClock_create();
    game->bad.mine_clock = sfClock_create();
    game->setting.volume = 100;
    game->setting.argent = sfMusic_createFromFile("ressource/argent.wav");
    game->setting.die = sfMusic_createFromFile("ressource/Roblox.wav");
    more_setting(game, data);
}
