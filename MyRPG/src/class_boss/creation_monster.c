/*
** EPITECH PROJECT, 2019
** creation_monster.c
** File description:
** initialisation of the monster
*/

#include "rpg.h"

void stock_monster(world_t *world, monster_t *monster)
{
    monster_t *tmp = world->next_e;

    if (tmp == NULL)
        world->next_e = monster;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = monster;
    }
}

void add_info(char *name, monster_t *monster, info_t *info)
{
    while (info != NULL) {
        if (my_strcmp(info->name, name) == 0) {
            monster->name = info->name;
            monster->deg = info->deg;
            monster->pv = info->pv;
            monster->xp = info->xp;
        }
        info = info->next;
    }
    return;
}

void info_monster(int type, monster_t *monster, world_t *world)
{
    if (type == 1)
        add_info("bee", monster, world->next_i);
    if (type == 2)
        add_info("mouse", monster, world->next_i);
    if (type == 5)
        add_info("plant", monster, world->next_i);
    if (type == 6)
        add_info("slim", monster, world->next_i);
    if (type == 0)
        add_info("bat", monster, world->next_i);
    if (type == 4)
        add_info("spider", monster, world->next_i);
    if (type == 3)
        add_info("scorpion", monster, world->next_i);
    return;
}

void add_monster(int x, int y, int **array, world_t *world)
{
    monster_t *monster = malloc(sizeof(monster_t));
    int type = random_nb(0, 7);

    monster->texture = sfTexture_createFromFile("assets/monster/monster4.png",
    NULL);
    monster->rect.top = type * 35;
    monster->rect.left = 0;
    monster->rect.width = 31;
    monster->rect.height = 35;
    monster->sprite = sfSprite_create();
    monster->x = x;
    monster->y = y;
    monster->type = 0;
    monster->position.x = (x * 32) + 640;
    monster->position.y = (y * 32) + 610;
    info_monster(type, monster, world);
    array[y][x] = 4;
    sfSprite_setTexture(monster->sprite, monster->texture, sfTrue);
    monster->next = NULL;
    stock_monster(world, monster);
}
