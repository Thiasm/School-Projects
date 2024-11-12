/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** functions used to edit the txt on settings
*/

#include "rpg.h"

void add_text_value(text_value_t **head, char *name, char *value,
sfVector2f pos)
{
    text_value_t *node;
    sfFont* font = sfFont_createFromFile("assets/menu/game_font.otf");

    node = malloc(sizeof(text_t));
    node->name = name;
    node->value = value;
    node->position.x = pos.x;
    node->position.y = pos.y;
    node->text = sfText_create();
    sfText_setString(node->text, value);
    sfText_setCharacterSize(node->text, 100);
    sfText_setFont(node->text, font);
    node->next = *head;
    *head = node;
}

void change_size_text(text_value_t *head, char *name, int new_size)
{
    text_value_t *current = head;

    while (current != NULL) {
        if (my_strcompare(current->name, name)) {
            sfText_setCharacterSize(current->text, new_size);
            return;
        }
        current = current->next;
    }
    return;
}

void load_sprite_settings(texture_t **head, text_value_t **text_head)
{
    add_text_value(text_head, "Volume_text", "Change the volume",
    (sfVector2f) {400, 100});
    add_text_value(text_head, "Volume_change", "Volume : ",
    (sfVector2f) {400, 300});
    add_text_value(text_head, "Volume", "0", (sfVector2f) {650, 300});
    add_text_value(text_head, "Volume_up", ">", (sfVector2f) {500, 400});
    add_text_value(text_head, "Volume_down", "<", (sfVector2f) {600, 400});
    add_text_value(text_head, "Back", "Back", (sfVector2f) {0, 0});
    add_texture(head, (char * ) MENU_BACKGROUND_LOCATION, (char * )
    MENU_BUTTON_BACKGROUND, (sfVector2f){0, 0});
    change_size_text(*text_head, "Volume", 50);
    change_size_text(*text_head, "Volume_change", 50);
    change_size_text(*text_head, "Volume_up", 80);
    change_size_text(*text_head, "Volume_down", 80);
}

void volume_change(int *volume, int option)
{
    if (option == 1)
        if (*volume + 1 < 101)
            *volume += 1;
    if (option == 2)
        if (*volume - 1 > -1)
            *volume -= 1;
}
