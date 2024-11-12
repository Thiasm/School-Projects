/*
** EPITECH PROJECT, 2019
** verification.c
** File description:
** verif array
*/

#include "rpg.h"

void kill_boss(general_t *general, int x, int y)
{
    general->array[y][x] = 0;
    general->array[y + 1][x] = 0;
    general->array[y][x + 1] = 0;
    general->array[y + 1][x + 1] = 0;
}

int array_second(player_t *player, monster_t *monster, general_t *general)
{
    if (player->direct == 2 && player->pos_x < 99 && player->pos_x > 0
    && general->array[player->pos_y][player->pos_x + 1] == 6
    && monster->x == player->pos_x + 1) {
        kill_boss(general, monster->x, monster->y);
        return (1);
    } else if (player->direct == 4 && player->pos_x > 0
    && player->pos_x < 99
    && general->array[player->pos_y][player->pos_x - 1] == 6
    && monster->x + 1 == player->pos_x - 1) {
        kill_boss(general, monster->x, monster->y);
        return (1);
    }
    return (0);
}

int array_boss(player_t *player, monster_t *monster, general_t *general)
{
    if (player->direct == 1 && player->pos_y > 0 && player->pos_y < 149
    && general->array[player->pos_y - 1][player->pos_x] == 6
    && monster->y + 1 == player->pos_y - 1) {
        kill_boss(general, monster->x, monster->y);
        return (1);
    } else if (player->direct == 3 && player->pos_y < 149 
    && player->pos_y > 0
    && general->array[player->pos_y + 1][player->pos_x] == 6
    && monster->y == player->pos_y + 1) {
        kill_boss(general, monster->x, monster->y);
        return (1);
    }
    return (array_second(player, monster, general));
}

int array_monster(player_t *player, monster_t *monster, general_t *general)
{
    if (player->direct == 1 && player->pos_y > 0 && player->pos_y < 149
    && monster->y == player->pos_y - 1  && player->pos_x == monster->x) {
        general->array[player->pos_y - 1][player->pos_x] = 0;
        return (1);
    } else if (player->direct == 2 && player->pos_x < 99 && player->pos_x > 0
    && monster->y == player->pos_y && player->pos_x + 1 == monster->x) {
        general->array[player->pos_y][player->pos_x + 1] = 0;
        return (1);
    }
    if (player->direct == 3 && player->pos_y < 149 && player->pos_y > 0
    && monster->y == player->pos_y + 1 && player->pos_x == monster->x) {
        general->array[player->pos_y + 1][player->pos_x] = 0;
        return (1);
    } else if (player->direct == 4 && player->pos_x > 0  && player->pos_x < 99
    && monster->y == player->pos_y  && player->pos_x - 1 == monster->x) {
        general->array[player->pos_y][player->pos_x - 1] = 0;
        return (1);
    }
    return (0);
}

int check_pos(int x, int y, int *pos_pnj)
{
    if (x == pos_pnj[0] && y == pos_pnj[1])
        return (0);
    return (84);
}
