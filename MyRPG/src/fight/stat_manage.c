/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** functions used to manage stat on fight
*/

#include "rpg.h"

void init_stat(st_game_t *stat, int x, int y, char *name)
{
    stat->name = name;
    stat->text = sfText_create();
    sfText_setFont(stat->text,
    sfFont_createFromFile("assets/menu/game_font.otf"));
    stat->position.x = x;
    stat->position.y = y;
    sfText_setPosition(stat->text, stat->position);
    sfText_setColor(stat->text, sfRed);
    sfText_setCharacterSize(stat->text, 100);
    stat->next = NULL;
}

void init_game_stat(fight_t *fight, int x, int y, char *name)
{
    st_game_t *stat = malloc(sizeof(st_game_t));
    st_game_t *tmp = fight->next;

    init_stat(stat, x, y, name);
    if (fight->next == NULL) {
        fight->next = stat;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = stat;
    return;
}

void add_game_stat(fight_t *fight, stat_player_t *info, monster_t *monster)
{
    st_game_t *tmp = fight->next;

    while (tmp != NULL) {
        if (my_strcompare(tmp->name, "PV"))
            sfText_setString(tmp->text, itoa(info->pv));
        if (my_strcompare(tmp->name, "PM"))
            sfText_setString(tmp->text, itoa(info->mana));
        if (my_strcompare(tmp->name, "EN"))
            sfText_setString(tmp->text, itoa(monster->pv));
        tmp = tmp->next;
    }
    return;
}
