/*
** EPITECH PROJECT, 2019
** change_class
** File description:
** change
*/

#include "rpg.h"

void amelioration(stat_player_t *stat, int dex, int smart, int strg)
{
    stat->dex += dex;
    stat->smart += smart;
    stat->strg += strg;
    return;
}

void attack_class(stat_player_t *stat)
{
    if (my_strcmp(stat->class, "archer") == 0) {
        stat->crit = 50;
        stat->sound_attack = sfMusic_createFromFile(
        "assets/sounds/bow_sound.ogg");
    } if (my_strcmp(stat->class, "paladin") == 0)
        stat->sound_attack = sfMusic_createFromFile(
        "assets/sounds/slash_sound.ogg");
    if (my_strcmp(stat->class, "warrior") == 0)
        stat->sound_attack = sfMusic_createFromFile(
        "assets/sounds/slash_sound.ogg");
    return;
}

void chose_class(stat_player_t *stat)
{
    int level = stat->lvl - 1;

    stat->pv = 250;
    stat->pv_max = stat->pv;
    stat->mana = 250;
    stat->dex = 3;
    stat->smart = 3;
    stat->strg = 3;
    attack_class(stat);
    for (int b = 0; b != level; b++)
       your_class(stat);
    return;
}
