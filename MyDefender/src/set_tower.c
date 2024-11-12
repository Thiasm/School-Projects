/*
** EPITECH PROJECT, 2019
** set_tower.c
** File description:
** set tower
*/

#include "../include/my.h"

void more_set_tower(game_t *game, data_t *data)
{
    sfVector2f pos_one;
    sfVector2f pos_two;

    pos_one.x = 1700;
    pos_one.y = 30;
    pos_two.x = 1700;
    pos_two.y = 350;
    game->tower.s_canon = create_sprite("ressource/canon.png", pos_one);
    game->tower.shop_one = create_sprite("ressource/canon.png", pos_one);
    game->tower.s_laser = create_sprite("ressource/laser.png", pos_two);
    game->tower.shop_three = create_sprite("ressource/laser.png", pos_two);
    other_tower(game, data);
}

void other_tower(game_t *game, data_t *data)
{
    sfVector2f pos_three;
    sfVector2f pos_for;

    pos_three.x = 1700;
    pos_three.y = 200;
    pos_for.x = 1625;
    pos_for.y = 500;
    game->tower.s_big =  create_sprite("ressource/big.png", pos_three);
    game->tower.s_wall =  create_sprite("ressource/1.png", pos_for);
    game->tower.shop_two =  create_sprite("ressource/big.png", pos_three);
    game->tower.shop_for = create_sprite("ressource/1.png", pos_for);
}

void more_setting(game_t *game, data_t *data)
{
    sfVector2f pos_item;

    pos_item.x = 400;
    pos_item.y = -10;
    game->setting.money_text = create_text(game->setting.money_text,
    my_itoc(game->money), data, pos_item);
    pos_item.x = 100;
    game->setting.life_text = create_text(game->setting.life_text,
    my_itoc(game->life), data, pos_item);
    pos_item.x = 800;
    game->setting.wave_text = create_text(game->setting.wave_text,
    my_itoc(game->wave), data,    pos_item);
    game->setting.game_music = sfMusic_createFromFile("ressource/g_music.ogg");
    other_setting(game, data);
}

void other_setting(game_t *game, data_t *data)
{
    sfVector2f pos_item;

    pos_item.x = 1920;
    pos_item.y = 0;
    game->setting.s_hud = create_sprite("ressource/hud.png", pos_item);
    pos_item.x = 700;
    pos_item.y = 10;
    game->setting.s_wave = create_sprite("ressource/wave.png", pos_item);
    pos_item.x = 0;
    game->setting.s_hearth = create_sprite("ressource/hearth.png", pos_item);
    pos_item.x = 300;
    game->setting.s_money = create_sprite("ressource/money.png", pos_item);
    sfSprite_setRotation(game->setting.s_hud, 90.00);

}

int pos_t(game_t *game, data_t *data)
{
    for (int i = 0; data->tower_pos[i] != NULL; i++)
        if (data->mouse_x > data->tower_pos[i][0] - 300
            && data->mouse_x < data->tower_pos[i][0] + 300
            && data->mouse_y > data->tower_pos[i][1] - 300
            && data->mouse_y < data->tower_pos[i][0] + 300)
            return (0);
    return (1);
}
