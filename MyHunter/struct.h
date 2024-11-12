/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** my_hunter
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


struct set_texture_music {
    sfTexture *texture;
    sfTexture *bird;
    sfTexture *bullet_texture;
    sfTexture *hearth_texture;
    sfTexture *cloud_texture;
    sfTexture *sun_texture;
    sfTexture *reticle_texture;
    sfMusic *music;
    sfMusic *tir;
    sfMusic *reload;
    sfMusic *death;
    sfMusic *no_ammo;
    sfMusic *lose;
};

typedef struct set_texture_music texture_t;

struct set_sprite {
    sfSprite *bullet_sprite1;
    sfSprite *bullet_sprite2;
    sfSprite *bullet_sprite3;
    sfSprite *bullet_sprite4;
    sfSprite *hearth_sprite1;
    sfSprite *hearth_sprite2;
    sfSprite *hearth_sprite3;
    sfSprite *bird_sprite;
    sfSprite *cloud_sprite;
    sfSprite *sun_sprite;
    sfSprite *reticle_sprite;
    sfSprite *sprite;
};

typedef struct set_sprite sprite_t;

struct other_var {
    sfIntRect rect;
    sfEvent event;
    sfFont *font;
    sfText *score;
    sfText *over;
    sfClock *clock;
    sfClock *delay_shoot;
    sfClock *delay_reload;
    sfTime time;
    sfTime shoot_time;
    sfTime reload_time;
    sfRenderWindow *window;
};

typedef struct other_var else_t;

struct variables {
    int life;
    int mun;
    int sco;
    float seconds;
    float seconds_shoot;
    float seconds_reload;
};

typedef struct variables var_t;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char *str1, char *str2);
char *my_itoc(int number);
void game_over(var_t *var, sprite_t *spr, else_t *v, texture_t *tex);
void set_music(sprite_t *spr, texture_t *tex, else_t *v);
void set_bird_sprite(sprite_t *spr, texture_t *tex);
void set_background(sprite_t *spr, texture_t *tex);
void set_hearth_sprite(sprite_t *spr, texture_t *tex);
void set_bullet_sprite(sprite_t *spr, texture_t *tex);
void display_sprite(else_t *v, sprite_t *spr, var_t *var);
void health_point(var_t *var, sprite_t *spr, else_t *v, texture_t *tex);
void display_background(else_t *v, var_t *var, sprite_t *spr);
void close_window(else_t *v);
void destroy_sprite(texture_t *tex, sprite_t *spr, else_t *v);
void anime_bird(else_t *v, var_t *var, sprite_t *spr);
void shoot(var_t *var, texture_t *tex, else_t *v, sprite_t *spr);
void check_hitbox(sprite_t *spr, var_t *var, else_t *v);
void display_bullet(var_t *var, sprite_t *spr);
void reload(sprite_t *spr, texture_t *tex, var_t *var, else_t *v);
int main(int argc, char **argv, char **env);
void game_boucle(else_t *v, sprite_t *spr, var_t *var, texture_t *tex);
void set_game_design(sprite_t *spr, texture_t *tex, else_t *v, var_t *var);
void var_init(var_t *var, else_t *v);
