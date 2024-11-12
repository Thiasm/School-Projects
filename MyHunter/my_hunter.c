/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** graphic 01
*/

#include "struct.h"

void var_init(var_t *var, else_t *v)
{
    v->rect.top = 0;
    v->rect.left = 0;
    v->rect.width = 110;
    v->rect.height = 110;
    var->mun = 0;
    var->sco = 0;
    var->life = 3;
}

void set_game_design(sprite_t *spr, texture_t *tex, else_t *v, var_t *var)
{
    set_background(spr, tex);
    set_hearth_sprite(spr, tex);
    set_bullet_sprite(spr, tex);
    set_bird_sprite(spr, tex);
    set_music(spr, tex, v);
    var_init(var, v);
}

void game_boucle(else_t *v, sprite_t *spr, var_t *var, texture_t *tex)
{
    while (sfRenderWindow_isOpen(v->window)) {
        display_sprite(v, spr, var);
        health_point(var, spr, v, tex);
        while (sfRenderWindow_pollEvent(v->window, &v->event))
        {
            shoot(var, tex, v, spr);
            reload(spr, tex, var, v);
            close_window(v);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    texture_t tex;
    sprite_t spr;
    else_t v;
    var_t var;

    if (argc == 2) {
         if (my_strcmp(argv[1], "-h") == 84);
            return (0);
    }
    if (!env[0])
        return (84);
    sfVideoMode mode = {1250, 900, 32};
    v.window = sfRenderWindow_create(mode, "MyHunter", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(v.window, 100);
    set_game_design(&spr, &tex, &v, &var);
    game_boucle(&v, &spr, &var, &tex);
    destroy_sprite(&tex, &spr, &v);
    return (0);
}