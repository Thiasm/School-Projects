/*
** EPITECH PROJECT, 2019
** events_wolrd
** File description:
** world
*/

#include "rpg.h"

void reset_move(general_t *general)
{
    general->move.x = 0;
    general->move.y = 0;
    return;
}

void get_position_by_name(player_t *player, sfView *view)
{
    sfVector2f test = sfView_getCenter((const sfView *) view);

    player->position.x = test.x;
    player->position.y = test.y;
    return;
}

int random_nb(int min, int max)
{
    return (rand() % (max - min) + min);
}
