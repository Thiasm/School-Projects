/*
** EPITECH PROJECT, 2018
** create_bad.c
** File description:
** runner
*/

#include "my.h"

void anime_bad(var_t *var, back_t *back)
{
    sfRenderWindow_drawSprite(var->window, back->bad_spr, NULL);
    sfSprite_move(back->bad_spr, (sfVector2f) {-10, 0});
}
