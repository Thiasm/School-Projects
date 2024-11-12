/*
** EPITECH PROJECT, 2019
** end_loop
** File description:
** defender
*/

#include "../include/my.h"

void end_loop(data_t *data, menu_t *menu)
{
    menu->s_game_over = create_sprite
        ("ressource/gameover.png", (sfVector2f){700, 500});
    while (sfRenderWindow_isOpen(data->window) && data->step == 0) {
        sfRenderWindow_clear(data->window, sfBlack);
        sfRenderWindow_drawSprite(data->window, menu->s_background, NULL);
        sfRenderWindow_drawSprite(data->window, menu->s_logo, NULL);
        sfRenderWindow_drawSprite(data->window, menu->s_game_over, NULL);
        sfRenderWindow_drawText(data->window, menu->quit_text, NULL);
        cursor(data, data->s_cursor);
        sfRenderWindow_display(data->window);
        while (sfRenderWindow_pollEvent(data->window, &data->event)) {
            closed_window(data->window, data->event);
            click_end_menu(data, menu, data->event);
        }
    }
}

void click_end_menu(data_t *data, menu_t *menu, sfEvent event)
{
    if (data->mouse_y <= 870 && data->mouse_y >= 680
        && data->mouse_x >= 870 && data->mouse_x <= 1000) {
        sfText_setColor(menu->quit_text, sfRed);
        if (event.type == sfEvtMouseButtonPressed)
            sfRenderWindow_close(data->window);
    } else
        sfText_setColor(menu->quit_text, sfWhite);
}
