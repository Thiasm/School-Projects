/*
** EPITECH PROJECT, 2019
** game_loop
** File description:
** defender
*/

#include "../include/my.h"

void game_loop(data_t *data, game_t *game, menu_t *menu)
{
    sfEvent event;

    set_game_loop(data, game);
    set_price(data, game);
    while (sfRenderWindow_isOpen(data->window) && game->life > 0) {
        display_setting(data, game);
        display_tower(data, game);
        display_bad(data, game);
        cursor(data, data->s_cursor);
        canon_shoot(data, game);
        sfRenderWindow_display(data->window);
        while (sfRenderWindow_pollEvent(data->window, &event)) {
            place_tower(data, game);
            closed_window(data->window, event);
            pause_game(data, game, menu);
        }
    }
    data->step = 0;
}

void display_tower(data_t *data, game_t *game)
{
    sfSprite *new;

    for (int i = 0; data->tower_pos[i] != NULL; i++) {
        new = tower_cursor(data->tower_pos[i][2], game, data);
        if (data->tower_pos[i][0] != 0) {
            sfSprite_setPosition(new, (sfVector2f){data->tower_pos[i][0]
                        , data->tower_pos[i][1]});
            sfRenderWindow_drawSprite(data->window, new, NULL);
        } else {
            sfSprite_setPosition(new, (sfVector2f){100, 200});
        }
    }
}

void display_setting(data_t *data, game_t *game)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_drawSprite(data->window, game->setting.s_map, NULL);
    sfRenderWindow_drawSprite(data->window, game->setting.s_hud, NULL);
    sfRenderWindow_drawSprite(data->window, game->setting.s_wave, NULL);
    sfRenderWindow_drawSprite(data->window, game->setting.s_money, NULL);
    sfRenderWindow_drawSprite(data->window, game->setting.s_hearth, NULL);
    sfRenderWindow_drawSprite(data->window, game->tower.shop_one, NULL);
    sfRenderWindow_drawSprite(data->window, game->tower.shop_two, NULL);
    sfRenderWindow_drawSprite(data->window, game->tower.shop_three, NULL);
    sfRenderWindow_drawSprite(data->window, game->tower.shop_for, NULL);
    sfRenderWindow_drawText(data->window, game->setting.money_text, NULL);
    sfRenderWindow_drawText(data->window, game->setting.life_text, NULL);
    sfRenderWindow_drawText(data->window, game->setting.wave_text, NULL);
    sfRenderWindow_drawText(data->window, game->tower.price_canon, NULL);
    sfRenderWindow_drawText(data->window, game->tower.price_big, NULL);
    sfRenderWindow_drawText(data->window, game->tower.price_laser, NULL);
    sfRenderWindow_drawText(data->window, game->tower.price_wall, NULL);
}
