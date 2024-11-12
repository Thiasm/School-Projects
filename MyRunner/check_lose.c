/*
** EPITECH PROJECT, 2018
** create_parallax
** File description:
** runner
*/

#include "my.h"

void check_lose(var_t *var, back_t *back, map_t *map)
{
    for (int i = 0; i < map->nb; i++) {
        if (map->block_x[i] < 400 && map->block_x[i] > 100) {
            if (map->ground == 0) {
                parse_map(map);
                sfMusic_stop(back->music.music);
                var->menu.sco = 0;
                var->menu.menu = 2;
            }
        }
    }
    check_lose_bad(var, back, map);
}

void check_lose_bad(var_t *var, back_t *back, map_t *map)
{
    int x = 0;

    while (x < 2000)
        x = rand() % 4000;
    if (sfSprite_getPosition(back->bad_spr).x < -1750 &&
        sfSprite_getPosition(back->bad_spr).x > -2000)
        if (back->player.y >= -200) {
            sfSprite_setPosition(back->bad_spr, (sfVector2f) {2000, 0});
            sfMusic_stop(back->music.music);
            parse_map(map);
            var->menu.sco = 0;
            var->menu.menu = 2;
        }
    if (sfSprite_getPosition(back->bad_spr).x < -2300)
        sfSprite_setPosition(back->bad_spr, (sfVector2f) {x, 0});
}
