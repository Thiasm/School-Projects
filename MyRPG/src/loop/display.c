/*
** EPITECH PROJECT, 2019
** display.c
** File description:
** display
*/

#include "rpg.h"

void display_world(general_t *general, world_t *world)
{
    map_t *map = world->next_m;

    sfSprite_setPosition(map->sprite, map->position);
    sfRenderWindow_drawSprite(general->window, map->sprite, NULL);
}

void display_player(general_t *general, player_t *player)
{
    if (general->mov == 0) {
    sfSprite_setPosition(player->sprite, player->position);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfRenderWindow_drawSprite(general->window, player->sprite, NULL);
    }
}

void display_monster(sfRenderWindow *window, world_t *world)
{
    monster_t *monster = world->next_e;

    while (monster != NULL) {
        sfSprite_setPosition(monster->sprite, monster->position);
        sfSprite_setTextureRect(monster->sprite, monster->rect);
        sfRenderWindow_drawSprite(window, monster->sprite, NULL);
        monster = monster->next;
    }
}

void display_quest(general_t *general, other_t *other, player_t *player)
{
    other->vector.x = player->position.x - 580;
    other->vector.y = player->position.y - 390;
    sfSprite_setPosition(other->sprite, other->vector);
    sfRenderWindow_drawSprite(general->window, other->sprite, NULL);
    sfText_setString(other->text, other->quest[other->quest_nb]);
    sfText_setPosition(other->text,
    (sfVector2f) { other->vector.x + 30, other->vector.y + 100 });
    sfRenderWindow_drawText(general->window, other->text, NULL);
}

void display_game(general_t *general, world_t *world,
player_t *player, other_t *other)
{
    sfView_move(general->view, general->move);
    reset_move(general);
    get_position_by_name(player, general->view);
    sfRenderWindow_setView(general->window, general->view);
    display_world(general, world);
    display_monster(general->window, world);
    display_player(general, player);
    if (general->next_d->name != NULL) {
        sfSprite_setPosition(other->dialogs, general->bar_pos);
        sfRenderWindow_drawSprite(general->window, other->dialogs, NULL);
        sfRenderWindow_drawText(general->window, general->next_d->text, NULL);
    }
    if (other->display == 0)
        display_quest(general, other, player);
    if (other->display_inventory == 0)
        display_inventory(general, other, player);
}
