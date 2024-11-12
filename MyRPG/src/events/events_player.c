/*
** EPITECH PROJECT, 2019
** events_player
** File description:
** events
*/

#include "rpg.h"

void move_player(general_t *general, player_t *player, other_t *other)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        if (modif_move(1, 144, player, general) == 1)
            general->move.y = -32;
        sfMusic_play(other->step_sound);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        if (modif_move(3, 0, player, general) == 1)
            general->move.y = 32;
        sfMusic_play(other->step_sound);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        if (modif_move(2, 96, player, general) == 1)
            general->move.x = 32;
        sfMusic_play(other->step_sound);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        if (modif_move(4, 48, player, general) == 1)
            general->move.x = -32;
        sfMusic_play(other->step_sound);
    }
    return;
}

int good_pos(player_t *player, int *pnj_pos)
{
    if (player->direct == 1)
        if (check_pos(player->pos_x, (player->pos_y - 1), pnj_pos) != 84)
            return (0);
    if (player->direct == 2)
        if (check_pos((player->pos_x + 1), player->pos_y, pnj_pos) != 84)
            return (0);
    if (player->direct == 3)
        if (check_pos(player->pos_x, (player->pos_y + 1), pnj_pos) != 84)
            return (0);
    if (player->direct == 4)
        if (check_pos((player->pos_x - 1), player->pos_y, pnj_pos) != 84)
            return (0);
    return (84);
}

void quests_events(general_t *general, player_t *player, other_t *other)
{
    if (other->quest_nb == 3) {
        if (good_pos(player, other->main_pnj[2]) != 84)
            other->quest_nb += 1;
    } else if (other->quest_nb == 4)
        if (good_pos(player, other->main_pnj[2]) != 84 &&
        general->array[64][66] == 0)
            other->quest_nb += 1;
    if (other->quest_nb == 5) {
        if (good_pos(player, other->main_pnj[3]) != 84)
            other->quest_nb += 1;
    } else if (other->quest_nb == 6)
        if (good_pos(player, other->main_pnj[3]) != 84 &&
        general->array[86][136] == 0)
            other->quest_nb += 1;
    if (other->quest_nb == 7)
        if (good_pos(player, other->main_pnj[0]) != 84 &&
        general->array[23][125] == 0)
            other->quest_nb += 1;
}

void events_quest(general_t *general, player_t *player, other_t *other,
sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyX) == sfTrue) {
        if (other->quest_nb == 0)
            if (good_pos(player, other->main_pnj[0]) != 84)
                other->quest_nb += 1;
        if (other->quest_nb == 1) {
            if (good_pos(player, other->main_pnj[1]) != 84)
                other->quest_nb += 1;
        } else if (other->quest_nb == 2)
            if (good_pos(player, other->main_pnj[1]) != 84 &&
            general->array[94][5] == 0)
                other->quest_nb += 1;
        quests_events(general, player, other);
    }
}

void player_events(general_t *general, player_t *player, other_t *other,
sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyO) == sfTrue) {
        other->display = !other->display;
    }
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyI) == sfTrue) {
        other->display_inventory = !other->display_inventory;
    }
    if (event->type == sfEvtKeyPressed &&
    sfTime_asMilliseconds(sfClock_getElapsedTime(player->deplacement)) > 80) {
        move_player(general, player, other);
        sfClock_restart(player->deplacement);
    }
    if (sfKeyboard_isKeyPressed(sfKeyX) == sfTrue && player->direct == 1
    && general->chose == 0 && general->array[87][6] == 9) {
            general->chose = 1;
            select_class(general, player, other);
    }
    events_quest(general, player, other, event);
}
