/*
** EPITECH PROJECT, 2019
** creation_boss
** File description:
** creation
*/

#include "rpg.h"

void info_boss(int type, monster_t *monster, world_t *world)
{
    if (type == 0)
        add_info("Ogre", monster, world->next_i);
    if (type == 1)
        add_info("Evilking", monster, world->next_i);
    if (type == 2)
        add_info("Kerberos", monster, world->next_i);
    if (type == 3)
        add_info("Lamia", monster, world->next_i);
    return;
}

void add_boss(int x, int y, world_t *world, int type)
{
    monster_t *monster = malloc(sizeof(monster_t));

    monster->texture = sfTexture_createFromFile("assets/monster/boss.png",
    NULL);
    monster->rect.top = type * 64;
    monster->rect.left = 0;
    monster->rect.width = 64;
    monster->rect.height = 64;
    monster->sprite = sfSprite_create();
    monster->x = x;
    monster->y = y;
    monster->type = 1;
    monster->position.x = (x * 32) + 640;
    monster->position.y = (y * 32) + 610;
    info_boss(type, monster, world);
    sfSprite_setTexture(monster->sprite, monster->texture, sfTrue);
    monster->next = NULL;
    stock_monster(world, monster);
}

void boss_array(int **array, int x, int y)
{
    array[y][x] = 6;
    array[y + 1][x] = 6;
    array[y][x + 1] = 6;
    array[y + 1][x + 1] = 6;
}

void init_boss(general_t *general, world_t *world)
{
    boss_array(general->array, 5, 94);
    add_boss(5, 94, world, 0);
    boss_array(general->array, 136, 86);
    add_boss(136, 86, world, 2);
    boss_array(general->array, 125, 15);
    add_boss(125, 15, world, 1);
    boss_array(general->array, 66, 64);
    add_boss(66, 64, world, 3);
}
