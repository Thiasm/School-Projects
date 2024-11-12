/*
** EPITECH PROJECT, 2019
** menu_loop
** File description:
** defender
*/

#include "../include/my.h"

void menu_loop(data_t *data, menu_t *menu)
{
    data->step = 0;
    menu->menu_music = sfMusic_createFromFile("ressource/menu_music.ogg");
    sfMusic_play(menu->menu_music);
    base_menu(data, menu);
    help_menu(data, menu);
    level_menu(data, menu);
    sfMusic_stop(menu->menu_music);
}
