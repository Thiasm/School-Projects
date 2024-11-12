/*
** EPITECH PROJECT, 2019
** main
** File description:
** defender
*/

#include "../include/my.h"

int main(int ac, char **av, char **env)
{
    data_t data;
    game_t game;
    menu_t menu;

    create_window(&data);
    menu_loop(&data, &menu);
    game_loop(&data, &game, &menu);
    sfMusic_stop(game.setting.game_music);
    end_loop(&data, &menu);
    destroy_all(&data, &game, &menu);
    return (0);
}

void create_window(data_t *data)
{
    sfVideoMode mode = {1920, 1080, 32};

    data->window = sfRenderWindow_create(mode, "MyDefender", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(data->window, 60);
    data->s_cursor = create_sprite("ressource/cursor.png", (sfVector2f){0, 0});
}
