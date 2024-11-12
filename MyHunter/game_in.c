/*
** EPITECH PROJECT, 2018
** game_in
** File description:
** my_hunter
*/

#include "struct.h"

void display_sprite(else_t *v, sprite_t *spr, var_t *var)
{
    sfRenderWindow_display(v->window);
    sfRenderWindow_drawSprite(v->window, spr->sprite, NULL);
    sfRenderWindow_drawSprite(v->window, spr->sun_sprite, NULL);
    sfRenderWindow_drawSprite(v->window, spr->cloud_sprite, NULL);
    sfRenderWindow_drawSprite(v->window, spr->bullet_sprite1, NULL);
    sfRenderWindow_drawSprite(v->window, spr->bird_sprite, NULL);
    sfRenderWindow_drawSprite(v->window, spr->bullet_sprite2, NULL);
    sfRenderWindow_drawSprite(v->window, spr->bullet_sprite3, NULL);
    sfRenderWindow_drawSprite(v->window, spr->bullet_sprite4, NULL);
    sfRenderWindow_drawSprite(v->window, spr->hearth_sprite1, NULL);
    sfRenderWindow_drawSprite(v->window, spr->hearth_sprite2, NULL);
    sfRenderWindow_drawSprite(v->window, spr->hearth_sprite3, NULL);
    display_background(v, var, spr);
    anime_bird(v, var, spr);
}

void health_point(var_t *var, sprite_t *spr, else_t *v, texture_t *tex)
{
    int mx = sfMouse_getPositionRenderWindow(v->window).x;
    int my = sfMouse_getPositionRenderWindow(v->window).y;

    if (sfSprite_getPosition(spr->bird_sprite).x > 1260 && var->life > 1) {
        sfSprite_setPosition(spr->bird_sprite, (sfVector2f) {0, rand()%600});
        var->life--;
        sfMusic_play(tex->death);
    }
    game_over(var, spr, v, tex);
    if (var->life == 2)
        sfSprite_setPosition(spr->hearth_sprite3, (sfVector2f) {-500, 0});
    if (var->life == 1)
        sfSprite_setPosition(spr->hearth_sprite2, (sfVector2f) {-500, 0});
    sfRenderWindow_setMouseCursorVisible(v->window, sfFalse);
    sfRenderWindow_drawSprite(v->window, spr->reticle_sprite, NULL);
    sfSprite_setPosition(spr->reticle_sprite, (sfVector2f) {mx, my});
}

void display_background(else_t *v, var_t *var, sprite_t *spr)
{
    sfText_setString(v->score, my_itoc(var->sco));
    sfText_setFont(v->score, v->font);
    sfText_setCharacterSize(v->score, 50);
    sfRenderWindow_drawText(v->window, v->score, NULL);
    sfText_setString(v->over, "GAME OVER");
    sfText_setFont(v->over, v->font);
    sfText_setCharacterSize(v->over, 150);
    sfSprite_setOrigin(spr->cloud_sprite, (sfVector2f) {0, 100});
    sfSprite_move(spr->cloud_sprite, (sfVector2f) {0.025, 0.0001});
    sfSprite_setOrigin(spr->sun_sprite, (sfVector2f) {-800, 0});
    sfSprite_move(spr->sun_sprite, (sfVector2f) {-0.00010, 0.0001});
}

void close_window(else_t *v)
{
    if (v->event.type == sfEvtClosed)
        sfRenderWindow_close(v->window);
}

void destroy_sprite(texture_t *tex, sprite_t *spr, else_t *v)
{
    sfMusic_destroy(tex->music);
    sfMusic_destroy(tex->tir);
    sfMusic_destroy(tex->death);
    sfMusic_destroy(tex->reload);
    sfMusic_destroy(tex->no_ammo);
    sfSprite_destroy(spr->sprite);
    sfSprite_destroy(spr->hearth_sprite1);
    sfSprite_destroy(spr->hearth_sprite2);
    sfSprite_destroy(spr->hearth_sprite3);
    sfSprite_destroy(spr->bird_sprite);
    sfSprite_destroy(spr->bullet_sprite1);
    sfSprite_destroy(spr->bullet_sprite2);
    sfSprite_destroy(spr->bullet_sprite3);
    sfSprite_destroy(spr->bullet_sprite4);
    sfTexture_destroy(tex->texture);
    sfTexture_destroy(tex->bullet_texture);
    sfTexture_destroy(tex->hearth_texture);
    sfTexture_destroy(tex->bird);
    sfFont_destroy(v->font);
    sfRenderWindow_destroy(v->window);
}
