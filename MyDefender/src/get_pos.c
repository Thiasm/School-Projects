/*
** EPITECH PROJECT, 2019
** get_pos.c
** File description:
** get position
*/

#include "../include/my.h"

int get_pos(data_t *data, game_t *game)
{
    int choice = 0;

    if (data->mouse_x > 1700 && data->mouse_x < 1920
        && data->mouse_y > 00 && data->mouse_y < 150)
        choice = 1;
    if (data->mouse_x > 1700 && data->mouse_x < 1920
        && data->mouse_y > 151 && data->mouse_y < 300)
        choice = 2;
    if (data->mouse_x > 1700 && data->mouse_x < 1920
        && data->mouse_y > 301 && data->mouse_y < 450)
        choice = 3;
    if (data->mouse_x > 1700 && data->mouse_x < 1920
        && data->mouse_y > 451 && data->mouse_y < 600)
        choice = 4;
    return (choice);
}

sfSprite *tower_cursor(int choice, game_t *game, data_t *data)
{
    if (choice == 0)
        return (data->s_cursor);
    if (choice == 1)
        return (game->tower.s_canon);
    if (choice == 2)
        return (game->tower.s_big);
    if (choice == 3)
        return (game->tower.s_laser);
    if (choice == 4)
        return (game->tower.s_wall);
}

void place_tower(data_t *data, game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        game->choice = get_pos(data, game);
        while (sfMouse_isButtonPressed(sfMouseLeft)) {
            display_setting(data, game);
            display_tower(data, game);
            move_ajax(data, game);
            canon_shoot(data, game);
            sfText_setString(game->setting.life_text, my_itoc(game->life));
            sfText_setString(game->setting.money_text, my_itoc(game->money));
            anime_bad(data, game);
            cursor(data, tower_cursor(game->choice, game, data));
            sfRenderWindow_display(data->window);
        }
        if (game->choice >= 1 && game->choice <= 4)
            fill_tower_tab(data, game);
    }
}

int check_money(game_t *game, data_t *data)
{
    if (game->money >= 250 && game->choice == 1) {
        game->money -= 250;
        return (0);
    }
    if (game->money >= 500 && game->choice == 2) {
        game->money -= 500;
        return (0);
    }
    if (game->money >= 750 && game->choice == 3) {
        game->money -= 750;
        return (0);
    }
    if (game->money >= 1000 && game->choice == 4) {
        game->money -= 1000;
        return (0);
    }
    return (1);
}

void fill_tower_tab(data_t *data, game_t *game)
{
    int i = 0;

    if (pos_t(game, data) == 1 &&
        data->tower_pos[8][0] == 0 && check_money(game, data) == 0) {
        for (i = 0; data->tower_pos[i][0] != 0;)
            i++;
        data->tower_pos[i][0] = data->mouse_x;
        data->tower_pos[i][1] = data->mouse_y;
        data->tower_pos[i][2] = game->choice;
        data->tower_pos[i][3] = 0;
        sfMusic_play(game->setting.argent);
    }
}
