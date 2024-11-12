/*
** EPITECH PROJECT, 2018
** convert
** File description:
** my_hunter
*/

#include "struct.h"

char *my_itoc(int number)
{
    int tmp = number;
    int size = 1;
    char *score;

    while (tmp >= 10) {
        tmp = tmp / 10;
        size++;
    }
    score = malloc(sizeof(char) * size + 1);
    tmp = number;
    score[size] = '\0';
    size--;
    while (size >= 0) {
        score[size] = tmp % 10 + 48;
        tmp = tmp / 10;
        size--;
    }
    return (score);
}

void game_over(var_t *var, sprite_t *spr, else_t *v, texture_t *tex)
{
    if (sfSprite_getPosition(spr->bird_sprite).x > 1250 && var->life == 1) {
        sfSprite_setPosition(spr->hearth_sprite1, (sfVector2f) {-500, 0});
        sfSprite_setPosition(spr->bullet_sprite4, (sfVector2f) {-500, 0});
        sfSprite_setPosition(spr->bullet_sprite3, (sfVector2f) {-500, 0});
        sfSprite_setPosition(spr->bullet_sprite2, (sfVector2f) {-500, 0});
        sfSprite_setPosition(spr->bullet_sprite1, (sfVector2f) {-500, 0});
        sfMusic_stop(tex->music);
        sfRenderWindow_drawText(v->window, v->over, NULL);
        sfText_setPosition(v->score, (sfVector2f) {-150, -450});
        sfText_setPosition(v->over, (sfVector2f) {150, 450});
        if (sfMouse_isButtonPressed(sfMouseLeft))
            sfRenderWindow_close(v->window);
    }
}
