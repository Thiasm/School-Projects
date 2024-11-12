/*
** EPITECH PROJECT, 2019
** base_menu
** File description:
** defender
*/

#include "../include/my.h"

void set_base_menu(data_t *data, menu_t *menu)
{
    menu->s_background = create_sprite("ressource/Background.png",
    (sfVector2f){0, 0});
    data->font = sfFont_createFromFile("ressource/Spacetime.ttf");
    menu->play_text = create_text(menu->play_text, "PLAY",
    data, (sfVector2f) {880, 500});
    sfText_setCharacterSize(menu->play_text, 50);
    menu->quit_text = create_text(menu->quit_text, "QUIT",
    data, (sfVector2f) {880, 700});
    sfText_setCharacterSize(menu->quit_text, 50);
    menu->s_logo = create_sprite("ressource/logo.png", (sfVector2f) {600, 100});
    menu->help_text = create_text(menu->play_text, "HELP",
    data, (sfVector2f) {1650, 0});
    menu->help_background = create_sprite("ressource/help.png",
    (sfVector2f) {0, 0});
}

void base_menu(data_t *data, menu_t *menu)
{
    set_base_menu(data, menu);
    while (sfRenderWindow_isOpen(data->window) && data->step == 0) {
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_drawSprite(data->window, menu->s_background, NULL);
        sfRenderWindow_drawSprite(data->window, menu->s_logo, NULL);
        sfRenderWindow_drawText(data->window, menu->play_text, NULL);
        sfRenderWindow_drawText(data->window, menu->quit_text, NULL);
        sfRenderWindow_drawText(data->window, menu->help_text, NULL);
        cursor(data, data->s_cursor);
        sfRenderWindow_display(data->window);
        while (sfRenderWindow_pollEvent(data->window, &data->event)) {
            closed_window(data->window, data->event);
            click_base_menu(data, menu, data->event);
        }
    }
}

void help_menu(data_t *data, menu_t *menu)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(data->window) && data->step == 5) {
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_drawSprite(data->window, menu->help_background, NULL);
        cursor(data, data->s_cursor);
        sfRenderWindow_display(data->window);
        while (sfRenderWindow_pollEvent(data->window, &event)) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                data->step = 0;
                base_menu(data, menu);
            }
        }
    }
}

void click_base_menu(data_t *data, menu_t *menu, sfEvent event)
{
    if (data->mouse_y <= 570 && data->mouse_y >= 480
        && data->mouse_x >= 870 && data->mouse_x <= 1000) {
        sfText_setColor(menu->play_text, sfRed);
        if (event.type == sfEvtMouseButtonPressed)
            data->step = 1;
    } else
        sfText_setColor(menu->play_text, sfWhite);
    if (data->mouse_y <= 870 && data->mouse_y >= 680
        && data->mouse_x >= 870 && data->mouse_x <= 1000) {
        sfText_setColor(menu->quit_text, sfRed);
        if (event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(data->window);
    } else
        sfText_setColor(menu->quit_text, sfWhite);
    if (data->mouse_y <= 100 && data->mouse_y >= 0
        && data->mouse_x >= 1650 && data->mouse_x <= 1880) {
        sfText_setColor(menu->help_text, sfRed);
        if (event.type == sfEvtMouseButtonPressed)
            data->step = 5;
    } else
        sfText_setColor(menu->help_text, sfWhite);
}
