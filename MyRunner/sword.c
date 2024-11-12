/*
** EPITECH PROJECT, 2019
** sword
** File description:
** runner
*/

#include "my.h"

void check_sword(var_t *var, back_t *back, map_t *map)
{
    check_hitbox(var, back);
    while (back->player.rect_sword.top < 300) {
        while (back->player.rect_sword.left <= 1300) {
            sword_background(var, back, map);
            cut_sword_rect(var, back);
        }
    }
    var->timer.time_sword = sfClock_getElapsedTime(var->timer.clock_sword);
    var->timer.seconds_sword = var->timer.time_sword.microseconds / 1000000.0;
    back->player.rect_sword.left = 0;
    back->player.rect_sword.top = 0;
}

void sword_background(var_t *var, back_t *back, map_t *map)
{
    var->timer.time_sword = sfClock_getElapsedTime(var->timer.clock_sword);
    var->timer.seconds_sword = var->timer.time_sword.microseconds / 1000000.0;
    sfRenderWindow_display(var->window);
    create_parallax(var, back, map);
    sfSprite_setTextureRect(back->player.sword_spr, back->player.rect_sword);
    if (map->ground == -200)
        sfSprite_setPosition(back->player.sword_spr, (sfVector2f) {0, -200});
    else
        sfSprite_setPosition(back->player.sword_spr, (sfVector2f) {0,   0});
    sfRenderWindow_drawSprite(var->window, back->player.sword_spr, NULL);
}

void cut_sword_rect(var_t *var, back_t *back)
{
    if (var->timer.seconds_sword >= 0.03) {
        if (back->player.rect_sword.top == 0 &&
            back->player.rect_sword.left == 1120) {
            back->player.rect_sword.left = 0;
            back->player.rect_sword.top = 300;
        }
        else
            back->player.rect_sword.left += 280;
        sfClock_restart(var->timer.clock_sword);
    }
}

void check_hitbox(var_t *var, back_t *back)
{
    sfMusic_setVolume(back->music.sword_sound, 30);
    if (sfSprite_getPosition(back->bad_spr).x < -1500 &&
        sfSprite_getPosition(back->bad_spr).x > -1800) {
        sfSprite_setPosition(back->bad_spr, (sfVector2f) {2000, 0});
        sfMusic_setVolume(back->music.cut_sound, 15);
        sfMusic_play(back->music.cut_sound);
    }
    else
        sfMusic_play(back->music.sword_sound);
}
