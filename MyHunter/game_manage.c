/*
** EPITECH PROJECT, 2018
** game_manage
** File description:
** my_hunter
*/

#include "struct.h"

void anime_bird(else_t *v, var_t *var, sprite_t *spr)
{
    v->time = sfClock_getElapsedTime(v->clock);
    var->seconds = v->time.microseconds / 1000000.0;
    if (var->seconds >= 0.1  && var->seconds <= 0.20) {
        v->rect.left = 110;
    }
    if (var->seconds >= 0.25  && var->seconds <= 0.35) {
        v->rect.left = 220;
    }
    if (var->seconds >= 0.40  && var->seconds <= 0.50) {
        v->rect.left = 110;
    }
    if (var->seconds >= 0.55  && var->seconds <= 1.05) {
        v->rect.left = 0;
        sfSprite_setTextureRect(spr->bird_sprite, v->rect);
        sfClock_restart(v->clock);
    }
    sfSprite_setTextureRect(spr->bird_sprite, v->rect);
    sfSprite_setOrigin(spr->bird_sprite, (sfVector2f) {0, 0});
    sfSprite_move(spr->bird_sprite, (sfVector2f) {7, 0});
}

void shoot(var_t *var, texture_t *tex, else_t *v, sprite_t *spr)
{
    v->shoot_time = sfClock_getElapsedTime(v->delay_shoot);
    var->seconds_shoot = v->shoot_time.microseconds / 1000000.0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && (var->seconds_shoot > 1)) {
        if (var->mun < 4) {
            var->mun += 1;
            sfMusic_play(tex->tir);
            check_hitbox(spr, var, v);
            sfClock_restart(v->delay_shoot);
        }
        else if (var->mun >= 4)
            sfMusic_play(tex->no_ammo);
        display_bullet(var, spr);
    }
}

void check_hitbox(sprite_t *spr, var_t *var, else_t *v)
{
    int mx = sfMouse_getPositionRenderWindow(v->window).x;
    int my = sfMouse_getPositionRenderWindow(v->window).y;
    int sx = sfSprite_getPosition(spr->bird_sprite).x;
    int sy = sfSprite_getPosition(spr->bird_sprite).y;

    if (mx - 100 <= sx && sx <= mx + 100) {
        if (my - 100 <= sy && sy <= my + 100) {
            sfSprite_setPosition(spr->bird_sprite,
                                 (sfVector2f) {-300, rand()%700});
            var->sco += 10;
        }
    }
}

void display_bullet(var_t *var, sprite_t *spr)
{
    if (var->mun == 1)
        sfSprite_setPosition(spr->bullet_sprite4, (sfVector2f) {-500, 0});
    if (var->mun == 2)
        sfSprite_setPosition(spr->bullet_sprite3, (sfVector2f) {-600, 0});
    if (var->mun == 3)
        sfSprite_setPosition(spr->bullet_sprite2, (sfVector2f) {-700, 0});
    if (var->mun == 4)
        sfSprite_setPosition(spr->bullet_sprite1, (sfVector2f) {-800, 0});
}

void reload(sprite_t *spr, texture_t *tex, var_t *var, else_t *v)
{
    v->reload_time = sfClock_getElapsedTime(v->delay_reload);
    var->seconds_reload = v->reload_time.microseconds / 1000000.0;
    if (var->seconds_reload > 5) {
        if (sfKeyboard_isKeyPressed(sfKeyR)) {
            sfSprite_setPosition(spr->bullet_sprite1, (sfVector2f) {20, 750});
            sfSprite_setPosition(spr->bullet_sprite2, (sfVector2f) {70, 750});
            sfSprite_setPosition(spr->bullet_sprite3, (sfVector2f) {120, 750});
            sfSprite_setPosition(spr->bullet_sprite4, (sfVector2f) {170, 750});
            sfMusic_play(tex->reload);
            var->mun = 0;
            sfClock_restart(v->delay_reload);
        }
    }
}
