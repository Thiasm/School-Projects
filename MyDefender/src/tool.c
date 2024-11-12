/*
** EPITECH PROJECT, 2019
** tool
** File description:
** defender
*/

#include "../include/my.h"

void cursor(data_t *data, sfSprite *choice)
{
    data->mouse_x = sfMouse_getPositionRenderWindow(data->window).x;
    data->mouse_y = sfMouse_getPositionRenderWindow(data->window).y;
    sfRenderWindow_setMouseCursorVisible(data->window, sfFalse);
    sfSprite_setPosition(choice, (sfVector2f){data->mouse_x, data->mouse_y});
    sfRenderWindow_drawSprite(data->window, choice, NULL);
}

void closed_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}

sfText *create_text(sfText *tmp, char *str, data_t *data, sfVector2f co)
{
    tmp = sfText_create();
    sfText_setString(tmp, str);
    sfText_setFont(tmp, data->font);
    sfText_setCharacterSize(tmp, 80);
    sfText_setPosition(tmp, co);
    return (tmp);
}

sfSprite *create_sprite(char *path, sfVector2f co)
{
    sfSprite *spr;
    sfTexture *tex;

    tex = sfTexture_createFromFile(path, NULL);
    spr = sfSprite_create();
    sfSprite_setTexture(spr, tex, sfTrue);
    sfSprite_setPosition(spr, co);
    return (spr);
}

char *my_itoc(int number)
{
    int tmp = number;
    int size = 1;
    char *score;

    if (number < 0)
        return (0);
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
