/*
** EPITECH PROJECT, 2018
** convert
** File description:
** my_hunter
*/

#include "my.h"

void set_score(var_t *var, back_t *back)
{
    var->menu.score = sfText_create();
    var->menu.font = sfFont_createFromFile("./Texture/font.ttf");
    sfText_setFont(var->menu.score, var->menu.font);
    sfText_setCharacterSize(var->menu.score, 80);
    var->menu.play = sfText_create();
    sfText_setCharacterSize(var->menu.play, 80);
    sfText_setFont(var->menu.play, var->menu.font);
}

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
