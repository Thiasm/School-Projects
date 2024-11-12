/*
** EPITECH PROJECT, 2019
** pause_button
** File description:
** defender
*/

#include "../include/my.h"

void click_pause(data_t *data, game_t *game, menu_t *menu)
{
    if (data->mouse_y <= 600 && data->mouse_y >= 500
    && data->mouse_x >= 700 && data->mouse_x <= 1200) {
        sfText_setColor(game->pause.restart_text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            data->step = 0;
            menu_loop(data, menu);
            game_loop(data, game, menu);
        }
    } else
        sfText_setColor(game->pause.restart_text, sfWhite);
    sound_button(data, game);
    resume_quit_button(data, game, menu);
}

void resume_quit_button(data_t *data, game_t *game, menu_t *menu)
{
    if (data->mouse_y <= 450 && data->mouse_y >= 350
    && data->mouse_x >= 700 && data->mouse_x <= 1200) {
        sfText_setColor(game->pause.resume_text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            data->step = 0;
    } else
        sfText_setColor(game->pause.resume_text, sfWhite);
    if (data->mouse_y <= 750 && data->mouse_y >= 650
    && data->mouse_x >= 700 && data->mouse_x <= 1050) {
        sfText_setColor(game->pause.quit_text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (sfEvtMouseButtonPressed)
                sfRenderWindow_close(data->window);
            data->step = 0;
        }
    } else
        sfText_setColor(game->pause.quit_text, sfWhite);
}

void sound_button(data_t *data, game_t *game)
{
    sfEvent mouse;

    if (data->mouse_y <= 200 && data->mouse_y >= 0
    && data->mouse_x >= 0 && data->mouse_x <= 200) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            if (game->setting.volume == 100) {
                sfMusic_pause(game->setting.game_music);
                game->setting.volume = 0;
            }
            else if (game->setting.volume == 0) {
                sfMusic_play(game->setting.game_music);
                game->setting.volume = 100;
            }
        }
    }
}
