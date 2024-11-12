/*
** EPITECH PROJECT, 2019
** my_rpg.c
** File description:
** initialise all informations used to fight
*/

#include "rpg.h"

void init_fonts(fight_t *fight, text_t **text_head, sfFont *font,
monster_t *monster)
{
    fight->next = NULL;
    init_game_stat(fight, 300, 125, "PV");
    init_game_stat(fight, 300, 250, "PM");
    init_game_stat(fight, 1500, 125, "EN");
    add_text(text_head, "Player", font, (sfVector2f){0, 0});
    add_text(text_head, "PV =", font, (sfVector2f){0, 125});
    add_text(text_head, "PM =", font, (sfVector2f){0, 250});
    add_text(text_head, monster->name, font, (sfVector2f){1380, 0});
    add_text(text_head, "Attack", font, (sfVector2f){775, 670});
    add_text(text_head, "Spells", font, (sfVector2f){800, 820});
    fight->sprite = sfSprite_create();
    fight->position.x = 0;
    fight->position.y = 0;
    monster->position.x = 960;
    monster->position.y = 540;
}

void init_fight(fight_t *fight, monster_t *monster, text_t **text_head,
player_t *player)
{
    char *location = chose_background(monster->x, monster->y);
    sfFont *font = sfFont_createFromFile("assets/menu/game_font.otf");

    player->tour = 0;
    fight->texture = sfTexture_createFromFile(location, NULL);
    init_fonts(fight, text_head, font, monster);
    if (monster->type == 0) {
        fight->texture_s = sfTexture_createFromFile(
        "assets/fight_background/square.png", NULL);
        fight->sprite_s = sfSprite_create();
        fight->position_s.x = 948;
        fight->position_s.y = 525;
        sfSprite_setTexture(fight->sprite_s, fight->texture_s, sfTrue);
    } else
        sprite_boss(monster);
    sfSprite_setTexture(fight->sprite, fight->texture, sfTrue);
    add_game_stat(fight, player->next, monster);
}
