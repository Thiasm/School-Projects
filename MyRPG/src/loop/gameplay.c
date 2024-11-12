/*
** EPITECH PROJECT, 2019
** gameplay
** File description:
** gamerplay
*/

#include "rpg.h"

void your_class(stat_player_t *stat)
{
    if (my_strcmp(stat->class, "novice") == 0)
            amelioration(stat, 1, 1, 1);
        if (my_strcmp(stat->class, "wizard") == 0) {
            amelioration(stat, 1, 4, 1);
            stat->mana += 50;
        } if (my_strcmp(stat->class, "archer") == 0)
            amelioration(stat, 3, 2, 1);
        if (my_strcmp(stat->class, "paladin") == 0) {
            amelioration(stat, 2, 2, 2);
            stat->pv += 150;
        } if (my_strcmp(stat->class, "warrior") == 0)
            amelioration(stat,2, 1, 3);
    stat->pv_max = stat->pv;
    return;
}

void up_level(stat_player_t *stat)
{
    if (stat->xp >= stat->xp_next){
        stat->lvl++;
        stat->xp = stat->xp - stat->xp_next;
        stat->xp_next = stat->xp_next * 3;
        stat->pv += 100;
        stat->mana += 25;
        your_class(stat);
    }
    return;
}

void mov_monster(world_t *world)
{
    monster_t *monster = world->next_e;

    while (monster != NULL) {
        if (monster->type == 0 && monster->rect.left >= 62)
            monster->rect.left = 0;
        if (monster->type == 0 && monster->rect.left < 62)
            monster->rect.left += 31;
        if (monster->type == 1 && monster->rect.left >= 128)
            monster->rect.left = 0;
        if (monster->type == 1 && monster->rect.left < 128)
            monster->rect.left += 64;
        monster = monster->next;
    }
}

void you_dead(general_t *general, other_t *other)
{
    sfEvent event;

    sfRenderWindow_setView(general->window,
    sfRenderWindow_getDefaultView(general->window));
    sfMusic_destroy(other->background_music);
    other->background_music = sfMusic_createFromFile("assets/sounds/died.ogg");
    sfMusic_setLoop(other->background_music, sfTrue);
    sfMusic_play(other->background_music);
    while (1) {
        sfRenderWindow_clear(general->window, sfBlack);
        sfSprite_setPosition(general->sprite, general->position);
        sfRenderWindow_drawSprite(general->window, general->sprite, NULL);
        while (sfRenderWindow_pollEvent(general->window, &event)) {
            if (event.type == sfEvtClosed)
                return;
        }
        sfRenderWindow_display(general->window);
    }
}

void gameplay(other_t *other, world_t *world, player_t *player,
general_t *general)
{
    if (general->check == 1)
        destroy_exit(general, other, player);
    player->next->pv = player->next->pv_max;
    other->time_m = sfClock_getElapsedTime(other->clock_m);
    other->second_m = other->time_m.microseconds/1000000.0;
    if (other->second_m > 0.15) {
        mov_monster(world);
        if (general->mov == 1 || general->mov == 2)
            mov_door(general);
        sfClock_restart(other->clock_m);
    }
    up_level(player->next);
    if (general->live == 1) {
        you_dead(general, other);
        sfMusic_destroy(other->background_music);
        sfMusic_destroy(other->step_sound);
        sfMusic_destroy(other->click_sound);
        sfMusic_destroy(player->next->sound_attack);
        sfRenderWindow_close(general->window);
    }
}
