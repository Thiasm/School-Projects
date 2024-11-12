/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** No description
*/

#include "rpg.h"

int check_button_setting(text_value_t *head, sfEvent event,
general_t *general)
{
    text_value_t *current = head;
    sfVector2i mouse;

    mouse.x = event.mouseButton.x;
    mouse.y = event.mouseButton.y;
    while (current != NULL) {
        if (mouse.y <= current->position.y + 60 && mouse.y >=
        current->position.y && mouse.x >= current->position.x && mouse.x
        <= current->position.x + 60) {
            if (my_strcompare(current->name, "Volume_up"))
                volume_change(&general->option.volume, 1);
            if (my_strcompare(current->name, "Volume_down"))
                volume_change(&general->option.volume, 2);
            if (my_strcompare(current->name, "Back"))
                return (1);
        }
        current = current->next;
    }
    return (0);
}

void display_settings(sfRenderWindow *window, texture_t *head,
text_value_t *head_text)
{
    texture_t *current = head;
    text_value_t *current_text = head_text;

    while (current != NULL) {
        infinity_background(current);
        sfSprite_setPosition(current->sprite, current->position);
        sfRenderWindow_drawSprite(window, current->sprite, NULL);
        current = current->next;
    }
    while (current_text != NULL) {
        sfText_setString(current_text->text, current_text->value);
        sfText_setPosition(current_text->text, current_text->position);
        sfRenderWindow_drawText(window, current_text->text, NULL);
        current_text = current_text->next;
    }
}

int check_event_settings(general_t *general, sfEvent event,
text_value_t *text)
{
    while (sfRenderWindow_pollEvent(general->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(general->window);
        }
        if (event.type == sfEvtMouseButtonPressed)
            if (check_button_setting(text, event, general) == 1)
                return (1);
    }
    return (0);
}

void update_volume(general_t *general, text_value_t *text)
{
    text_value_t *current = text;

    while (current != NULL) {
        if (my_strcompare(current->name, "Volume")) {
            current->value = my_strdup(itoa(general->option.volume));
            return;
        }
        current = current->next;
    }
}

void settings(general_t *general)
{
    sfEvent event;
    texture_t *menu_texture = NULL;
    text_value_t *settings_text = NULL;

    general->option.volume = 50;
    load_sprite_settings(&menu_texture, &settings_text);
    while (sfRenderWindow_isOpen(general->window)) {
        if (check_event_settings(general, event, settings_text) == 1)
            return;
        update_volume(general, settings_text);
        sfRenderWindow_clear(general->window, sfBlack);
        display_settings(general->window, menu_texture, settings_text);
        sfRenderWindow_display(general->window);
    }
}