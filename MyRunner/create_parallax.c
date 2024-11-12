/*
** EPITECH PROJECT, 2018
** create_parallax
** File description:
** runner
*/

#include "my.h"

void create_parallax(var_t *var, back_t *back, map_t *map)
{
    var->menu.sco += 1;
    draw_background(var, back);
    move_background(var, back);
    move_display_block(map, var, back);
    respawn_background(var, back);
    sfText_setString(var->menu.score, my_itoc(var->menu.sco));
    sfRenderWindow_drawText(var->window, var->menu.score, NULL);
    anime_bad(var, back);
}

void respawn_background(var_t *var, back_t *back)
{
    if (sfSprite_getPosition(back->background.sand_spr).x <= -1920)
        sfSprite_setPosition(back->background.sand_spr, (sfVector2f) {0, 0});
    if (sfSprite_getPosition(back->background.rock_spr).x <= -1920)
        sfSprite_setPosition(back->background.rock_spr, (sfVector2f) {0, 0});
    if (sfSprite_getPosition(back->background.night_spr).x <= -1920)
        sfSprite_setPosition(back->background.night_spr, (sfVector2f) {0, 0});
    if (sfSprite_getPosition(back->background.sky_spr).x <= -1920)
        sfSprite_setPosition(back->background.sky_spr, (sfVector2f) {0, 0});
}

void move_background(var_t *var, back_t *back)
{
    sfSprite_move(back->background.sand_spr, (sfVector2f) {-6, 0});
    sfSprite_move(back->background.rock_spr, (sfVector2f) {-10, 0});
    sfSprite_move(back->background.night_spr, (sfVector2f) {-3, 0});
    sfSprite_move(back->background.sky_spr, (sfVector2f) {-4, 0});
}

void draw_background(var_t *var, back_t *back)
{
    sfRenderWindow_drawSprite(var->window, back->background.night_spr, NULL);
    sfRenderWindow_drawSprite(var->window, back->background.sky_spr, NULL);
    sfRenderWindow_drawSprite(var->window, back->background.sand_spr, NULL);
    sfRenderWindow_drawSprite(var->window, back->background.rock_spr, NULL);
}
