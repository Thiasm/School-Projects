/*
** EPITECH PROJECT, 2019
** initialisation_monster
** File description:
** init_monster
*/

#include "rpg.h"

void intialisation_general(general_t *general)
{
    general->texture = sfTexture_createFromFile(
    "assets/fight_background/dead.jpg", NULL);
    general->sprite = sfSprite_create();
    general->position.x = 0;
    general->position.y = 0;
    general->mov = 0;
    general->check = 0;
    sfSprite_setTexture(general->sprite, general->texture, sfTrue);
}

void initialisation_world(world_t *world, char *location)
{
    map_t *tmp = malloc(sizeof(map_t));

    tmp->texture = sfTexture_createFromFile(location, NULL);
    tmp->sprite = sfSprite_create();
    tmp->position.x = 0;
    tmp->position.y = 0;
    sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
    world->next_m = tmp;
}

void initialisation_monster(general_t *general, world_t *world)
{
    int nb = 0;

    srand(rand());
    for (int b = 0; b < 100; b++) {
        nb = random_nb(1, 11);
        if (nb == 1 || nb == 2)
            add_monster(random_nb(42, 105), random_nb(29, 75),
            general->array, world);
        if (nb == 3 || nb == 4)
            add_monster(random_nb(66, 97), random_nb(80, 98),
            general->array, world);
        if (nb == 5 || nb == 6)
            add_monster(random_nb(2, 41), random_nb(44, 63),
            general->array, world);
        if (nb == 7 || nb == 8)
            add_monster(random_nb(96, 148), random_nb(38, 55),
            general->array, world);
        if (nb == 9 || nb == 10)
            add_monster(random_nb(78, 105), random_nb(2, 37),
            general->array, world);
    }
    init_boss(general, world);
    return;
}

void destroy_exit(general_t *general, other_t *other, player_t *player)
{
    sfMusic_destroy(other->background_music);
    sfMusic_destroy(other->step_sound);
    sfMusic_destroy(other->click_sound);
    sfMusic_destroy(player->next->sound_attack);
    sfRenderWindow_close(general->window);
}