/*
** EPITECH PROJECT, 2019
** pause_game
** File description:
** defender
*/

#include "../include/my.h"

void pause_game(data_t *data, game_t *game, menu_t *menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        data->step = 1;
        while (data->step == 1) {
            display_pause(data, game);
            sfRenderWindow_display(data->window);
            if (sfKeyboard_isKeyPressed(sfKeyA))
                data->step = 0;
            click_pause(data, game, menu);
        }
    }
}

void display_pause(data_t *data, game_t *game)
{
    sfRenderWindow_clear(data->window, sfBlack);
    sfRenderWindow_drawSprite(data->window, game->pause.s_background, NULL);
    sfRenderWindow_drawSprite(data->window, game->pause.s_sound_button, NULL);
    sfRenderWindow_drawSprite(data->window, game->pause.s_pause, NULL);
    sfRenderWindow_drawText(data->window, game->pause.resume_text, NULL);
    sfRenderWindow_drawText(data->window, game->pause.quit_text, NULL);
    sfRenderWindow_drawText(data->window, game->pause.restart_text, NULL);
    cursor(data, data->s_cursor);
}

void set_game_pause(game_t *game, data_t *data)
{
    game->pause.s_background = create_sprite("ressource/Background.png",
    (sfVector2f){0, 0});
    game->pause.s_sound_button = create_sprite("ressource/sound_button.png",
    (sfVector2f){10, 10});
    game->pause.s_pause = create_sprite("ressource/pause.png",
    (sfVector2f){800, 150});
    game->pause.resume_text = create_text(
        game->pause.resume_text, "Resume", data, (sfVector2f){750, 350});
    game->pause.restart_text = create_text(
        game->pause.restart_text, "Restart", data, (sfVector2f){750, 500});
    game->pause.quit_text = create_text(
        game->pause.quit_text, "Quit", data, (sfVector2f){750, 650});
}
