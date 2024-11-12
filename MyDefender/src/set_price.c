/*
** EPITECH PROJECT, 2019
** set_price.c
** File description:
** set price
*/

#include "../include/my.h"

void set_price(data_t *data, game_t *game)
{
    game->tower.price_canon = create_text(
        game->tower.price_canon, "700$", data, (sfVector2f){1725, 400});
    game->tower.price_big = create_text(
        game->tower.price_big, "500$", data, (sfVector2f){1725, 250});
    game->tower.price_laser = create_text(
        game->tower.price_laser, "250$", data, (sfVector2f){1725, 100});
    game->tower.price_wall = create_text(
        game->tower.price_wall, "1000$", data, (sfVector2f){1725, 600});
    sfText_setCharacterSize(game->tower.price_wall, 30);
    sfText_setCharacterSize(game->tower.price_canon, 30);
    sfText_setCharacterSize(game->tower.price_big, 30);
    sfText_setCharacterSize(game->tower.price_laser, 30);

}
