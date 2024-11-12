/*
** EPITECH PROJECT, 2019
** destroy
** File description:
** defender
*/

#include "../include/my.h"

void destroy_all(data_t *data, game_t *game, menu_t *menu)
{
    destroy_game(game);
    destroy_menu(menu);
    destroy_data(data);
}

void destroy_data(data_t *data)
{
    sfSprite_destroy(data->s_cursor);
    sfFont_destroy(data->font);
    sfRenderWindow_destroy(data->window);
}

void destroy_game(game_t *game)
{
    sfMusic_stop(game->setting.game_music);
    sfMusic_destroy(game->setting.game_music);
    sfSprite_destroy(game->setting.s_hud);
    sfSprite_destroy(game->setting.s_map);
    sfSprite_destroy(game->setting.s_hearth);
    sfSprite_destroy(game->setting.s_wave);
    sfSprite_destroy(game->setting.s_money);
    sfText_destroy(game->setting.life_text);
    sfText_destroy(game->setting.money_text);
    sfText_destroy(game->setting.wave_text);
    sfSprite_destroy(game->bad.s_slime);
    sfSprite_destroy(game->pause.s_background);
    sfSprite_destroy(game->pause.s_pause);
    sfSprite_destroy(game->pause.s_sound_button);
    sfSprite_destroy(game->tower.s_big);
    sfSprite_destroy(game->tower.s_canon);
    sfSprite_destroy(game->tower.s_laser);
    sfSprite_destroy(game->tower.s_wall);
    sfMusic_destroy(game->setting.argent);
    sfMusic_destroy(game->setting.die);
}

void destroy_menu(menu_t *menu)
{
    sfText_destroy(menu->quit_text);
    sfText_destroy(menu->play_text);
    sfText_destroy(menu->land_text);
    sfText_destroy(menu->ice_text);
    sfText_destroy(menu->select_level_text);
    sfSprite_destroy(menu->s_logo);
    sfSprite_destroy(menu->s_background);
    sfMusic_destroy(menu->menu_music);
}
