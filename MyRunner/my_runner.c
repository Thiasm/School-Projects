/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** MUL_2018
*/

#include "my.h"

void init_var(var_t *var, back_t *back, map_t *map)
{
    init_rect(var, back);
    var->menu.menu = 0;
    back->player.y = -1500;
    var->timer.clock_bad = sfClock_create();
    var->timer.clock_player = sfClock_create();
    var->timer.clock_sword = sfClock_create();
    map->ground = 0;
}

void init_rect(var_t *var, back_t *back)
{
    back->player.rect_player.top = 300;
    back->player.rect_player.left = 0;
    back->player.rect_player.width = 215;
    back->player.rect_player.height = 300;
    back->player.rect_sword.top = 0;
    back->player.rect_sword.left = 0;
    back->player.rect_sword.width = 280;
    back->player.rect_sword.height = 300;
}

void game_loop(var_t *var, back_t *back, map_t *map)
{
    sfRenderWindow_display(var->window);
    check_lose(var, back, map);
    create_parallax(var, back, map);
    display_player(var, back, map);
    gravity(var, back, map);
    while (sfRenderWindow_pollEvent(var->window, &var->event)) {
        close_window(var);
        check_jump(var, back, map);
    }
}

void launch_game(var_t *var, back_t *back, map_t *map)
{
    set_origin(var, back, map);
    init_var(var, back, map);
    sfMusic_play(back->music.menu);
    while (var->menu.menu == 0 && sfRenderWindow_isOpen(var->window))
        game_menu(var, back);
    while (var->menu.menu == 1)
        game_loop(var, back, map);
    while (var->menu.menu == 2)
        lose_menu(var, back, map);
}

int main(int argc, char **argv, char **env)
{
    var_t var;
    back_t back;
    map_t map;

    sfVideoMode mode = {1920, 1080, 32};
    var.window = sfRenderWindow_create(mode, "MyRunner", sfClose, NULL);
    if (argc == 2)
        if (my_strcmp(argv[1], "-h") == 0)
            return (0);
    if (argc != 2 || !env[0] || create_map(argc, argv, &map) == 84) {
        write (2, "Invalid Argument\n", 20);
        return (84);
    }
    sfRenderWindow_setFramerateLimit(var.window, 80);
    set_game_texture(&var, &back, &map);
    launch_game(&var, &back, &map);
    destroy_all(&var, &back);
    return (0);
}
