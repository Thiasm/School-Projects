/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** menu_window
*/

#include "rpg.h"

sfRenderWindow *create_my_window()
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {MENU_WINDOW_SIZE_X, MENU_WINDOW_SIZE_Y,
    MENU_WINDOW_COLORS};

    window = sfRenderWindow_create(video_mode, MENU_WINDOW_NAME, sfResize |
                                   sfClose, NULL);
    if (window == NULL)
        sfRenderWindow_close(window);
    sfRenderWindow_setFramerateLimit(window, GAME_FRAMERATE_LIMIT);
    return (window);
}
