/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** menu_lists
*/

#include "rpg.h"

void add_texture(texture_t **head, char *location, char *name, sfVector2f pos)
{
    texture_t *new_node;

    new_node = malloc(sizeof(texture_t));
    new_node->name = name;
    new_node->texture = sfTexture_createFromFile(location, NULL);
    new_node->sprite = sfSprite_create();
    new_node->position.x = pos.x;
    new_node->position.y = pos.y;
    sfSprite_setTexture(new_node->sprite, new_node->texture, sfTrue);
    new_node->next = *head;
    *head = new_node;
}

void add_text(text_t **head, char *name, sfFont *font, sfVector2f pos)
{
    text_t *node;

    node = malloc(sizeof(text_t));
    node->name = name;
    node->position.x = pos.x;
    node->position.y = pos.y;
    node->text = sfText_create();
    sfText_setString(node->text, name);
    sfText_setCharacterSize(node->text, 100);
    sfText_setFont(node->text, font);
    node->next = *head;
    *head = node;
}

void infinity_background(texture_t *current)
{
    if (my_strcompare("background", current->name) == 1) {
        current->position.x -= 1;
        if (current->position.x == -1920)
            current->position.x = 0;
    }
}

void spawn_logo(texture_t *current)
{
    if (my_strcompare("logo", current->name) == 1) {
        if (current->position.y < 150)
            current->position.y += 3;
    }
}

void display_all(sfRenderWindow *window, texture_t *head, text_t *text_head)
{
    texture_t *current_texture = head;
    text_t *current_text = text_head;

    while (current_texture != NULL) {
        infinity_background(current_texture);
        spawn_logo(current_texture);
        sfSprite_setPosition(current_texture->sprite,
        current_texture->position);
        sfRenderWindow_drawSprite(window, current_texture->sprite, NULL);
        current_texture = current_texture->next;
    }
    while (current_text != NULL) {
        sfText_setPosition(current_text->text, current_text->position);
        sfRenderWindow_drawText(window, current_text->text, NULL);
        current_text = current_text->next;
    }
}
