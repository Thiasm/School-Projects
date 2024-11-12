/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** events
*/

#include "rpg.h"

void mov_door(general_t *general)
{   if (general->mov == 1) {
        for (int a = 0; a < 8; a++)
            general->move.x += -32;
        for (int b = 0; b < 10; b++)
            general->move.y += -32;
    } else {
        for (int a = 0; a < 8; a++)
            general->move.x += 32;
        for (int b = 0; b < 10; b++)
            general->move.y += 32;
    }
    general->mov = 0;
}

void analyse_events(general_t *general, sfEvent *event, other_t *other, player_t *player)
{
    if (event->type == sfEvtClosed) {
        sfMusic_destroy(other->background_music);
        sfMusic_destroy(other->step_sound);
        sfMusic_destroy(other->click_sound);
        sfMusic_destroy(player->next->sound_attack);
        sfRenderWindow_close(general->window);
    }
}
