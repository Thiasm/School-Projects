/*
** EPITECH PROJECT, 2019
** interaction_events.c
** File description:
** interaction
*/

#include "rpg.h"

void check_boss(player_t *player, world_t *world, general_t *general)
{
    monster_t *tmp = world->next_e;
    monster_t *prec = tmp;

    while (prec != NULL) {
        if (prec->type == 1 && (array_boss(player, prec, general) == 1)) {
            fight_loop(player, prec, general);
            player->next->xp += prec->xp;
            tmp->next = prec->next;
            free(prec);
            return;
        }
        tmp = prec;
        prec = prec->next;
    }
    return;
}

void check_enemy(player_t *player, world_t *world, general_t *general)
{
    monster_t *tmp = world->next_e;
    monster_t *prec = tmp;

    if (tmp != NULL && tmp->type == 0
    && (array_monster(player, tmp, general) == 1)) {
        fight_loop(player, tmp, general);
        world->next_e = tmp->next;
        free(tmp);
    }
    while (prec != NULL) {
        if (prec->type == 0 && (array_monster(player, prec, general) == 1)) {
            fight_loop(player, prec, general);
            player->next->xp += prec->xp;
            tmp->next = prec->next;
            free(prec);
            return;
        }
        tmp = prec;
        prec = prec->next;
    }
    return;
}

void dialog_pnj(general_t *general, player_t *player, world_t *world)
{
    if (player->direct == 1)
        check_dialog(player->pos_x, player->pos_y - 1, general, world);
    if (player->direct == 2)
        check_dialog(player->pos_x + 1, player->pos_y, general, world);
    if (player->direct == 3)
        check_dialog(player->pos_x, player->pos_y + 1, general, world);
    if (player->direct == 4)
        check_dialog(player->pos_x - 1, player->pos_y, general, world);
    return;
}

void check_door(general_t *general, player_t *player)
{
    if (player->direct == 1 && player->pos_y == 30 && player->pos_x == 125) {
        general->array[player->pos_y][player->pos_x] = 0;
        player->pos_y = 20;
        player->pos_x = 117;
        general->array[20][117] = 9;
        general->mov = 1;
    }
    if (player->direct == 3 && player->pos_y == 20 && player->pos_x == 117) {
        general->array[player->pos_y][player->pos_x] = 0;
        player->pos_y = 30;
        player->pos_x = 125;
        general->array[30][125] = 9;
        general->mov = 2;
    }
}

void interaction_events(general_t *general, player_t *player, world_t *world,
sfEvent *event)
{
    if (event->type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue) {
            dialog_pnj(general, player, world);
            check_enemy(player, world, general);
            check_boss(player, world, general);
            check_door(general, player);
        }
    }
    return;
}
