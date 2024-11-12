/*
** EPITECH PROJECT, 2019
** init_stat
** File description:
** initialisation
*/

#include "rpg.h"

void init_attack(stat_player_t *stat) 
{
    stat->texture = sfTexture_createFromFile(
    "assets/attack/normal_attack.png", NULL);
    stat->sprite = sfSprite_create();
    stat->position.x = 855;
    stat->position.y = 405;
    stat->rect.top = 0;
    stat->rect.left = 0;
    stat->rect.width = 200;
    stat->rect.height = 200;
    sfSprite_setTexture(stat->sprite, stat->texture, sfTrue);
}

void stat_player(player_t *player)
{
    stat_player_t *stat = malloc(sizeof(stat_player_t));

    stat->pv = 250;
    stat->pv_max = stat->pv;
    stat->mana = 250;
    stat->dex = 3;
    stat->smart = 3;
    stat->strg = 3;
    stat->crit = 10;
    stat->xp = 0;
    stat->xp_next = 100;
    stat->lvl = 1;
    stat->class = "novice";
    init_attack(stat);
    stat->sound_attack = sfMusic_createFromFile(
    "assets/sounds/damage_sound.ogg");
    player->next = stat;
}
