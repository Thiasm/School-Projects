/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** liitle functions used to manage fights
*/

#include "rpg.h"

void attack(stat_player_t *info, monster_t *monster, player_t *player)
{
    int nb = 0;

    nb = random_nb(info->strg, (info->strg + info->dex));
    monster->pv = monster->pv - nb;
    info->pv = info->pv - monster->deg;
    sfMusic_play(info->sound_attack);
    player->tour = 1;
    if (info->pv < 0)
        info->pv = 0;
    if (monster->pv < 0)
        monster->pv = 0;
}

int check_dead(stat_player_t *info, monster_t *monster, fight_t *fight,
general_t *general)
{
    add_game_stat(fight, info, monster);
    if (info->pv == 0) {
        general->live = 1;
        return (1);
    }
    if (monster->pv == 0)
        return (1);
    return (0);
}
