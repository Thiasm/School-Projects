/*
** EPITECH PROJECT, 2019
** moving_player
** File description:
** moving
*/

#include "rpg.h"

int modif_move(int dir, int top, player_t *player, general_t *general)
{
    if (player->direct != dir) {
        player->direct = dir;
        player->rect.left = 0;
        player->rect.top = top;
    } else {
        if (player->rect.left >= 96)
            player->rect.left = 0;
        else
            player->rect.left += 32;
        return (check_case(general->array, dir, player));
    }
    return (0);
}

int check_down_left(int **array, int dir, player_t *player)
{
    if (dir == 3) {
        if (player->pos_y < 99 &&
        array[player->pos_y + 1][player->pos_x] == 0) {
            array[player->pos_y + 1][player->pos_x] = 9;
            array[player->pos_y][player->pos_x] = 0;
            player->pos_y = player->pos_y + 1;
            return (1);
        } else
            return (0);
    } else {
        if (player->pos_x > 0 &&
        array[player->pos_y][player->pos_x - 1] == 0) {
            array[player->pos_y][player->pos_x - 1] = 9;
            array[player->pos_y][player->pos_x] = 0;
            player->pos_x = player->pos_x - 1;
            return (1);
        } else
            return (0);
    }
}

int check_case(int **array, int dir, player_t *player)
{
    if (dir == 1) {
        if (player->pos_y > 0 &&
        array[player->pos_y - 1][player->pos_x] == 0) {
            array[player->pos_y - 1][player->pos_x] = 9;
            array[player->pos_y][player->pos_x] = 0;
            player->pos_y = player->pos_y - 1;
            return (1);
        } else
            return (0);
    } else if (dir == 2) {
        if (player->pos_x < 149 &&
        array[player->pos_y][player->pos_x + 1] == 0) {
            array[player->pos_y][player->pos_x + 1] = 9;
            array[player->pos_y][player->pos_x] = 0;
            player->pos_x = player->pos_x + 1;
            return (1);
        } else
            return (0);
    }
    return (check_down_left(array, dir, player));
}
