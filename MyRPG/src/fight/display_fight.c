/*
** EPITECH PROJECT, 2019
** my_rpg.c
** File description:
** functions used to display the fight
*/

#include "rpg.h"

void display_attack(general_t *general, player_t *player)
{
    stat_player_t *stat = player->next;

    general->time = sfClock_getElapsedTime(general->clock);
    general->second = general->time.microseconds/1000000.0;
    if (player->tour == 1) {
        sfSprite_setPosition(stat->sprite, stat->position);
        sfSprite_setTextureRect(stat->sprite, stat->rect);
        sfRenderWindow_drawSprite(general->window, stat->sprite, NULL);
    }
    if (player->tour == 1 && general->second > 1) {
        if (player->rect.left < 400) {
            stat->rect.left = 0;
            player->tour = 0;
        } else
            stat->rect.left += 200;
        sfClock_restart(general->clock);
    }
    return;
}

void advance_linked_list(text_t *text, general_t *general, st_game_t *stat)
{
    for (int j = 0; j <= 5; j++) {
        sfText_setPosition(text->text, text->position);
        sfRenderWindow_drawText(general->window, text->text, NULL);
        text = text->next;
    }
    while (stat != NULL) {
        sfText_setPosition(stat->text, stat->position);
        sfRenderWindow_drawText(general->window, stat->text, NULL);
        stat = stat->next;
    }
    return;
}

void display_fight(fight_t *fight, monster_t *monster, general_t *general,
text_t *text)
{
    st_game_t *stat = fight->next;

    sfSprite_setPosition(fight->sprite, fight->position);
    sfRenderWindow_drawSprite(general->window, fight->sprite, NULL);
    if (monster->type == 0) {
        sfSprite_setPosition(monster->sprite, monster->position);
        sfSprite_setTextureRect(monster->sprite, monster->rect);
        sfRenderWindow_drawSprite(general->window, monster->sprite, NULL);
        sfSprite_setPosition(fight->sprite_s, fight->position_s);
        sfRenderWindow_drawSprite(general->window, fight->sprite_s, NULL);
    } else {
        sfSprite_setPosition(monster->sprite, monster->position);
        sfRenderWindow_drawSprite(general->window, monster->sprite, NULL);
    }
    advance_linked_list(text, general, stat);
}
