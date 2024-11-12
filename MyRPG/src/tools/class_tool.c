/*
** EPITECH PROJECT, 2019
** class_tool
** File description:
** rpg
*/

#include "rpg.h"

void edit_text(text_t *text, char *name, int size, int color)
{
    text_t *head = text;

    for (int i = 0; i < 5; i++) {
        if (my_strcompare(name, head->name)) {
            sfText_setCharacterSize(head->text, size);
            if (color == 2)
                sfText_setColor(head->text, sfBlack);
        }
        head = head->next;
    }
}

void edit_class_text(text_t *text)
{
    edit_text(text, "Paladins", 70, 1);
    edit_text(text, "Wizard", 70, 1);
    edit_text(text, "Warrior", 70, 1);
    edit_text(text, "Archer", 70, 1);
    edit_text(text, "Select your class", 125, 2);
}

void initialisation_class(texture_t **texture_head, text_t **text_head,
other_t *other)
{
    add_text(text_head, "Select your class", other->game_font, (sfVector2f)
    {300, 0});
    add_text(text_head, "Wizard", other->game_font, (sfVector2f){50, 800});
    add_text(text_head, "Archer", other->game_font, (sfVector2f){500, 800});
    add_text(text_head, "Paladins", other->game_font, (sfVector2f){950, 800});
    add_text(text_head, "Warrior", other->game_font, (sfVector2f){1400, 800});
    add_texture(texture_head, "assets/classes/select_class.png",
    "select", (sfVector2f){0, 0});
}
