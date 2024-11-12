/*
** EPITECH PROJECT, 2018
** menu
** File description:
** runner
*/

#include "my.h"

void game_menu(var_t *var, back_t *back)
{
    sfRenderWindow_display(var->window);
    draw_background(var, back);
    sfSprite_setPosition(var->menu.menu_spr, (sfVector2f) {0, -50});
    sfRenderWindow_drawSprite(var->window, var->menu.menu_spr, NULL);
    sfText_setPosition(var->menu.play, (sfVector2f) {0, 0});
    sfText_setString(var->menu.play, "SPACE : PLAY");
    sfRenderWindow_drawText(var->window, var->menu.play, NULL);
    sfSprite_setPosition(var->menu.menu_spr, (sfVector2f) {0, 250});
    sfRenderWindow_drawSprite(var->window, var->menu.menu_spr, NULL);
    sfText_setPosition(var->menu.play, (sfVector2f) {65, 310});
    sfText_setString(var->menu.play, "Q : QUIT");
    sfRenderWindow_drawText(var->window, var->menu.play, NULL);
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        init_music(back);
        var->menu.menu = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        var->menu.menu = 3;
}

void init_music(back_t *back)
{
    sfMusic_stop(back->music.menu);
    sfMusic_setVolume(back->music.music, 50);
    sfMusic_setLoop(back->music.music, sfTrue);
    sfMusic_play(back->music.music);
}

void lose_menu(var_t *var, back_t *back, map_t *map)
{
    sfRenderWindow_display(var->window);
    draw_background(var, back);
    sfSprite_setPosition(var->menu.menu_spr, (sfVector2f) {0, -50});
    sfSprite_scale(var->menu.menu_spr, (sfVector2f) {1.0, 1.0});
    sfRenderWindow_drawSprite(var->window, var->menu.menu_spr, NULL);
    sfText_setPosition(var->menu.play, (sfVector2f) {0, 0});
    sfText_setString(var->menu.play, "SPACE : PLAY");
    sfRenderWindow_drawText(var->window, var->menu.play, NULL);
    sfSprite_setPosition(var->menu.menu_spr, (sfVector2f) {0, 250});
    sfRenderWindow_drawSprite(var->window, var->menu.menu_spr, NULL);
    sfText_setPosition(var->menu.play, (sfVector2f) {65, 310});
    sfText_setString(var->menu.play, "Q : QUIT");
    sfRenderWindow_drawText(var->window, var->menu.play, NULL);
    if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        var->menu.menu = 1;
        launch_game(var, back, map);
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        var->menu.menu = 3;
}