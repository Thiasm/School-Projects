/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** functions used to initialize quests
*/

#include "rpg.h"

void get_pos(other_t *other)
{
    other->main_pnj = malloc(sizeof(int *) * 4);
    for (int i = 0; i <= 3; i++) {
        other->main_pnj[i] = malloc(sizeof(int) * 2);
    }
    other->main_pnj[0][0] = 24;
    other->main_pnj[0][1] = 13;
    other->main_pnj[1][0] = 5;
    other->main_pnj[1][1] = 69;
    other->main_pnj[2][0] = 47;
    other->main_pnj[2][1] = 97;
    other->main_pnj[3][0] = 124;
    other->main_pnj[3][1] = 83;
}

void get_str(char *str)
{
    int i = 0;
    int j = 0;

    if (str == NULL)
        return;
    while (str[i]) {
        j = 0;
        while (j != 4 && str[i] != '\0') {
            if (str[i] == ' ')
                j++;
            i++;
        }
        if (str[i] == '\0')
            return;
        str[i - 1] = '\n';
        i++;
    }
}

void manage(other_t *other)
{
    int i = 0;

    while (other->quest[i] != NULL) {
        get_str(other->quest[i]);
        i++;
    }
}

void init_quest(general_t *general, other_t *other)
{
    other->display_inventory = 1;
    other->quest = get_file(".quest.txt");
    manage(other);
    other->quest_nb = 0;
    other->display = 1;
    other->font = sfFont_createFromFile("assets/menu/game_font.otf");
    other->text = sfText_create();
    sfText_setFont(other->text, other->font);
    sfText_setColor(other->text, sfBlack);
    sfText_setCharacterSize(other->text, 20);
    other->vector = (sfVector2f) { general->rect.width, general->rect.height };
    other->texture = sfTexture_createFromFile("assets/trash/parch.png", NULL);
    get_pos(other);
    other->sprite = sfSprite_create();
    sfSprite_setTexture(other->sprite, other->texture, sfTrue);
}
