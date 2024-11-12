/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** inventory_display
*/

#include "rpg.h"

static void set_string(other_t *other, player_t *player)
{
    sfText_setString(other->text_inv->class, my_strcat("Class: ",
    player->next->class));
    sfText_setString(other->text_inv->crit, my_strcat("Crit: ", itoa
    (player->next->crit)));
    sfText_setString(other->text_inv->pv, my_strcat("PV: ", itoa
    (player->next->pv)));
    sfText_setString(other->text_inv->mana, my_strcat("Mana: ", itoa
    (player->next->mana)));
    sfText_setString(other->text_inv->xp, my_strcat("XP: ", itoa(player->next->
    xp)));
    sfText_setString(other->text_inv->xp_next, my_strcat("XP next: ", itoa
    (player->next->xp_next)));
    sfText_setString(other->text_inv->smart, my_strcat("Smart: ", itoa(player->
    next->smart)));
    sfText_setString(other->text_inv->strg, my_strcat("Strengh: ", itoa(player
    ->next->strg)));
    sfText_setString(other->text_inv->dex, my_strcat("Dexterity: ", itoa
    (player->next->dex)));
    sfText_setString(other->text_inv->dex, my_strcat("Level: ", itoa
    (player->next->lvl)));
}

static void set_position(other_t *other, player_t *player)
{
    sfText_setPosition(other->text_inv->class,
    (sfVector2f) { player->position.x + 400, player->position.y - 340 });
    sfText_setPosition(other->text_inv->crit,
    (sfVector2f) { player->position.x + 400, player->position.y - 320 });
    sfText_setPosition(other->text_inv->pv,
    (sfVector2f) { player->position.x + 400, player->position.y - 300 });
    sfText_setPosition(other->text_inv->mana,
    (sfVector2f) { player->position.x + 400, player->position.y - 280 });
    sfText_setPosition(other->text_inv->xp,
    (sfVector2f) { player->position.x + 400, player->position.y - 260 });
    sfText_setPosition(other->text_inv->xp_next,
    (sfVector2f) { player->position.x + 400, player->position.y - 240 });
    sfText_setPosition(other->text_inv->smart,
    (sfVector2f) { player->position.x + 400, player->position.y - 220 });
    sfText_setPosition(other->text_inv->strg,
    (sfVector2f) { player->position.x + 400, player->position.y - 200 });
    sfText_setPosition(other->text_inv->dex,
    (sfVector2f) { player->position.x + 400, player->position.y - 180 });
    sfText_setPosition(other->text_inv->lvl,
    (sfVector2f) { player->position.x + 400, player->position.y - 160 });
}

static void draw_text(sfRenderWindow *window, other_t *other)
{
    sfRenderWindow_drawText(window, other->text_inv->class, NULL);
    sfRenderWindow_drawText(window, other->text_inv->crit, NULL);
    sfRenderWindow_drawText(window, other->text_inv->pv, NULL);
    sfRenderWindow_drawText(window, other->text_inv->mana, NULL);
    sfRenderWindow_drawText(window, other->text_inv->xp, NULL);
    sfRenderWindow_drawText(window, other->text_inv->xp_next, NULL);
    sfRenderWindow_drawText(window, other->text_inv->smart, NULL);
    sfRenderWindow_drawText(window, other->text_inv->strg, NULL);
    sfRenderWindow_drawText(window, other->text_inv->dex, NULL);
    sfRenderWindow_drawText(window, other->text_inv->lvl, NULL);
}

void display_inventory(general_t *general, other_t *other, player_t *player)
{
    sfSprite_setPosition(other->inventory->sprite, (sfVector2f)
    { player->position.x + 300,  player->position.y - 390});
    sfRenderWindow_drawSprite(general->window, other->inventory->sprite, NULL);
    set_string(other, player);
    set_position(other, player);
    draw_text(general->window, other);
}
