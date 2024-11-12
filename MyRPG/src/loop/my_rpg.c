/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** rpg
*/

#include "rpg.h"

void sand_manage(sfClock *clock, sfVertexArray *test)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) >= 20) {
        sfVertexArray_clear(test);
        sand_particles(test);
        snow_particles(test);
        sfClock_restart(clock);
    }
}

void init_game(general_t *general, world_t *world, other_t *other,
player_t *player)
{
    sfWindow_setTitle((sfWindow *) general->window, "RPG - Game");
    initialisation(general, world, player, other);
    initialisation_inventory(other);
}

void my_rpg(general_t *general, world_t *world,
player_t *player, other_t *other)
{
    sfEvent event;
    sfVertexArray *test = sfVertexArray_create();
    sfClock *clock = sfClock_create();

    sfVertexArray_setPrimitiveType(test, sfPoints);
    init_game(general, world, other, player);
    while (sfRenderWindow_isOpen(general->window)) {
        sfRenderWindow_clear(general->window, sfBlack);
        gameplay(other, world, player, general);
        display_game(general, world, player, other);
        sand_manage(clock, test);
        while (sfRenderWindow_pollEvent(general->window, &event)) {
            analyse_events(general, &event, other, player);
            player_events(general, player, other, &event);
            interaction_events(general, player, world, &event);
            if (pause_menu(general, other) == 84)
                restart_game(general, other);
        }
        sfRenderWindow_drawVertexArray(general->window, test, NULL);
        sfRenderWindow_display(general->window);
    }
}
