/*
** EPITECH PROJECT, 2019
** block
** File description:
** my_runner
*/

#include "my.h"

void display_block(map_t *map, var_t *var, back_t *back)
{
    for (int i = 0; i < map->nb; i++) {
        sfSprite_setPosition(back->background.block_spr,
        (sfVector2f) {map->block_x[i], 0});
        sfRenderWindow_drawSprite(var->window,
        back->background.block_spr, NULL);
    }
}

void move_block(map_t *map, back_t *back, var_t *var)
{
    for (int i = 0; i < map->nb; i++) {
        map->block_x[i] -= 10;
        sfSprite_setPosition(back->background.block_spr,
        (sfVector2f) {map->block_x[i], 0});
        sfRenderWindow_drawSprite(var->window,
        back->background.block_spr, NULL);
    }
}

void move_display_block(map_t *map, var_t *var, back_t *back)
{
    display_block(map, var, back);
    move_block(map, back, var);
}
