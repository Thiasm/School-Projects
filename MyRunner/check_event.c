/*
** EPITECH PROJECT, 2018
** create_bonus
** File description:
** runner
*/

#include "my.h"

void close_window(var_t *var)
{
    if (var->event.type == sfEvtClosed)
        sfRenderWindow_close(var->window);
}

void check_jump(var_t *var, back_t *back, map_t *map)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        sfSound_play(back->music.jump_sound);
        jump(var, back, map);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && var->timer.seconds_sword >= 1)
        check_sword(var, back, map);
    var->timer.time_sword = sfClock_getElapsedTime(var->timer.clock_sword);
    var->timer.seconds_sword = var->timer.time_sword.microseconds / 1000000.0;
}

void jump(var_t *var, back_t *back, map_t *map)
{
    int y = -30;
    int obj = back->player.y;

    while (back->player.y >= obj - 460) {
        back->player.y += y;
        sfSprite_setPosition(back->player.jump_spr,
        (sfVector2f) {0, back->player.y});
        create_parallax(var, back, map);
        sfRenderWindow_drawSprite(var->window, back->player.jump_spr, NULL);
        y += 1;
        sfRenderWindow_display(var->window);
    }
    move_display_block(map, var, back);
    gravity(var, back, map);
}

void gravity(var_t *var, back_t *back, map_t *map)
{
    float x = 0;

    display_block(map, var, back);
    map->ground = 0;
    while (back->player.y < map->ground) {
        check_block_down(map);
        if (map->ground == 0 ||
        (map->ground == -200 && back->player.y <= -200)) {
            sfRenderWindow_display(var->window);
            create_parallax(var, back, map);
            x += 2.5;
            back->player.y += x;
            sfSprite_setPosition(back->player.jump_spr,
            (sfVector2f) {0, back->player.y});
            sfRenderWindow_drawSprite(var->window, back->player.jump_spr, NULL);
        }
    }
    sfSprite_setPosition(back->player.run_spr,
    (sfVector2f) {0, map->ground});
    sfRenderWindow_drawSprite(var->window, back->player.run_spr, NULL);
}

void check_block_down(map_t *map)
{
    for (int i = 0; i < map->nb; i++) {
        if (map->block_x[i] < 300 && map->block_x[i] > 0) {
            if (map->ground == 0)
                map->ground = -200;
        }
    }
}
