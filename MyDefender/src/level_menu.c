/*
** EPITECH PROJECT, 2019
** level_menu.c
** File description:
** level_menu
*/

#include "../include/my.h"

void set_level_menu(data_t *data, menu_t *menu)
{
    menu->ice_text = sfText_create();
    sfText_setString(menu->ice_text, "DESERT");
    sfText_setFont(menu->ice_text, data->font);
    sfText_setCharacterSize(menu->ice_text, 50);
    sfText_setPosition(menu->ice_text, (sfVector2f){900, 500});
    menu->land_text = sfText_create();
    sfText_setString(menu->land_text, "LAND");
    sfText_setFont(menu->land_text, data->font);
    sfText_setCharacterSize(menu->land_text, 50);
    sfText_setPosition(menu->land_text, (sfVector2f){900, 700});
    menu->select_level_text = sfText_create();
    sfText_setString(menu->select_level_text, "SELECT   LEVEL");
    sfText_setFont(menu->select_level_text, data->font);
    sfText_setCharacterSize(menu->select_level_text, 120);
    sfText_setPosition(menu->select_level_text, (sfVector2f){500, 200});
}

void level_menu(data_t *data, menu_t *menu)
{
    set_level_menu(data, menu);
    while (sfRenderWindow_isOpen(data->window) && data->step == 1) {
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_drawSprite(data->window, menu->s_background, NULL);
        sfRenderWindow_drawText(data->window, menu->select_level_text, NULL);
        sfRenderWindow_drawText(data->window, menu->ice_text, NULL);
        sfRenderWindow_drawText(data->window, menu->land_text, NULL);
        cursor(data, data->s_cursor);
        sfRenderWindow_display(data->window);
        while (sfRenderWindow_pollEvent(data->window, &data->event)) {
            closed_window(data->window, data->event);
            click_level_menu(data, menu, data->event);
        }
    }
}

void click_level_menu(data_t *data, menu_t *menu, sfEvent event)
{
    if (data->mouse_y <= 570 && data->mouse_y >= 480
    && data->mouse_x >= 870 && data->mouse_x <= 1000) {
        sfText_setColor(menu->ice_text, sfRed);
        if (event.type == sfEvtMouseButtonPressed)
            data->step = 2;
    } else
        sfText_setColor(menu->ice_text, sfWhite);
    if (data->mouse_y <= 770 && data->mouse_y >= 680
        && data->mouse_x >= 870 && data->mouse_x <= 1000) {
        sfText_setColor(menu->land_text, sfRed);
        if (event.type == sfEvtMouseButtonPressed) {
            data->step = 3;
        }
    } else
        sfText_setColor(menu->land_text, sfWhite);
}
