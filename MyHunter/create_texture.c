/*
** EPITECH PROJECT, 2018
** create_texture
** File description:
** my_hunter
*/

#include "struct.h"

void set_bullet_sprite(sprite_t *spr, texture_t *tex)
{
    tex->bullet_texture = sfTexture_createFromFile("./texture/bulle.png", NULL);
    spr->bullet_sprite1 = sfSprite_create();
    spr->bullet_sprite2 = sfSprite_create();
    spr->bullet_sprite3 = sfSprite_create();
    spr->bullet_sprite4 = sfSprite_create();
    sfSprite_setPosition(spr->bullet_sprite1, (sfVector2f) {20, 750});
    sfSprite_setPosition(spr->bullet_sprite2, (sfVector2f) {70, 750});
    sfSprite_setPosition(spr->bullet_sprite3, (sfVector2f) {120, 750});
    sfSprite_setPosition(spr->bullet_sprite4, (sfVector2f) {170, 750});
    sfSprite_setPosition(spr->hearth_sprite1, (sfVector2f) {950, 750});
    sfSprite_setPosition(spr->hearth_sprite2, (sfVector2f) {1020, 750});
    sfSprite_setPosition(spr->hearth_sprite3, (sfVector2f) {1090, 750});
}

void set_hearth_sprite(sprite_t *spr, texture_t *tex)
{
    tex->texture = sfTexture_createFromFile("./texture/back.jpg", NULL);
    tex->hearth_texture = sfTexture_createFromFile("./texture/coeur.png", NULL);
    spr->bird_sprite = sfSprite_create();
    spr->hearth_sprite1 = sfSprite_create();
    spr->hearth_sprite2 = sfSprite_create();
    spr->hearth_sprite3 = sfSprite_create();
    sfSprite_setTexture(spr->hearth_sprite1, tex->hearth_texture, sfTrue);
    sfSprite_setTexture(spr->hearth_sprite2, tex->hearth_texture, sfTrue);
    sfSprite_setTexture(spr->hearth_sprite3, tex->hearth_texture, sfTrue);
}

void set_background(sprite_t *spr, texture_t *tex)
{
    tex->cloud_texture = sfTexture_createFromFile("./texture/cloud.png", NULL);
    spr->cloud_sprite = sfSprite_create();
    sfSprite_setTexture(spr->cloud_sprite, tex->cloud_texture, sfTrue);
    tex->sun_texture = sfTexture_createFromFile("./texture/sun.png", NULL);
    spr->sun_sprite = sfSprite_create();
    sfSprite_setTexture(spr->sun_sprite, tex->sun_texture, sfTrue);
    tex->reticle_texture = sfTexture_createFromFile("./texture/curs.png", NULL);
    spr->reticle_sprite = sfSprite_create();
    sfSprite_setTexture(spr->reticle_sprite, tex->reticle_texture, sfTrue);
    sfSprite_scale(spr->reticle_sprite, (sfVector2f) {0.25, 0.25});
}

void set_bird_sprite(sprite_t *spr, texture_t *tex)
{
    tex->bird = sfTexture_createFromFile("./texture/bird.png", NULL);
    spr->sprite = sfSprite_create();
    sfSprite_setTexture(spr->sprite, tex->texture, sfTrue);
    sfSprite_setTexture(spr->bird_sprite, tex->bird, sfTrue);
    sfSprite_setTexture(spr->bullet_sprite1, tex->bullet_texture, sfTrue);
    sfSprite_setTexture(spr->bullet_sprite2, tex->bullet_texture, sfTrue);
    sfSprite_setTexture(spr->bullet_sprite3, tex->bullet_texture, sfTrue);
    sfSprite_setTexture(spr->bullet_sprite4, tex->bullet_texture, sfTrue);
}

void set_music(sprite_t *spr, texture_t *tex, else_t *v)
{
    tex->music = sfMusic_createFromFile("./music/music.ogg");
    tex->death = sfMusic_createFromFile("./music/death.ogg");
    tex->tir = sfMusic_createFromFile("./music/tir.ogg");
    tex->reload = sfMusic_createFromFile("./music/reload.ogg");
    tex->no_ammo = sfMusic_createFromFile("./music/no_ammo.ogg");
    v->font = sfFont_createFromFile("./texture/duckhunt.ttf");
    sfSprite_setTexture(spr->sprite, tex->texture, sfTrue);
    sfMusic_play(tex->music);
    sfMusic_setLoop(tex->music, sfTrue);
    sfMusic_setVolume(tex->music, 100);
    v->clock = sfClock_create();
    v->delay_shoot = sfClock_create();
    v->delay_reload = sfClock_create();
    v->score = sfText_create();
    v->over = sfText_create();
}
