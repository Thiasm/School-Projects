/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** inventory_init
*/

#include "rpg.h"

void initialisation_inventory_font(other_t *other)
{
    sfText_setFont(other->text_inv->class, other->font);
    sfText_setFont(other->text_inv->pv, other->font);
    sfText_setFont(other->text_inv->mana, other->font);
    sfText_setFont(other->text_inv->xp, other->font);
    sfText_setFont(other->text_inv->xp_next, other->font);
    sfText_setFont(other->text_inv->smart, other->font);
    sfText_setFont(other->text_inv->crit, other->font);
    sfText_setFont(other->text_inv->strg, other->font);
    sfText_setFont(other->text_inv->dex, other->font);
    sfText_setFont(other->text_inv->lvl, other->font);
}

void initialisation_inventory_character_size(other_t *other)
{
    sfText_setCharacterSize(other->text_inv->class, 15);
    sfText_setCharacterSize(other->text_inv->pv, 15);
    sfText_setCharacterSize(other->text_inv->mana, 15);
    sfText_setCharacterSize(other->text_inv->xp, 15);
    sfText_setCharacterSize(other->text_inv->xp_next, 15);
    sfText_setCharacterSize(other->text_inv->smart, 15);
    sfText_setCharacterSize(other->text_inv->crit, 15);
    sfText_setCharacterSize(other->text_inv->strg, 15);
    sfText_setCharacterSize(other->text_inv->dex, 15);
    sfText_setCharacterSize(other->text_inv->lvl, 15);
}

void initialisation_inventory_stats(other_t *other)
{
    other->text_inv->class = sfText_create();
    other->text_inv->pv = sfText_create();
    other->text_inv->mana = sfText_create();
    other->text_inv->xp = sfText_create();
    other->text_inv->xp_next = sfText_create();
    other->text_inv->smart = sfText_create();
    other->text_inv->crit = sfText_create();
    other->text_inv->strg = sfText_create();
    other->text_inv->dex = sfText_create();
    other->text_inv->lvl = sfText_create();
}

void initialisation_inventory(other_t *other)
{
    other->inventory = malloc(sizeof(texture_game_t));
    other->inventory->name = "inventory";
    other->inventory->position = (sfVector2f) { 0, 0 };
    other->inventory->sprite = sfSprite_create();
    other->inventory->texture = sfTexture_createFromFile
    ("assets/item/inventory.png", NULL);
    sfSprite_setTexture(other->inventory->sprite, other->inventory->texture,
    sfTrue);
    other->text_inv = malloc(sizeof(text_inventory_t));
    initialisation_inventory_stats(other);
    initialisation_inventory_font(other);
    initialisation_inventory_character_size(other);
}
