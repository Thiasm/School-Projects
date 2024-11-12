/*
** EPITECH PROJECT, 2019
** selection
** File description:
** rpg menu
*/

#include "rpg.h"

void display_selection(sfRenderWindow *window, texture_t *head, text_t
*text_head)
{
    texture_t *current = head;
    text_t *text = text_head;

    while (current != NULL) {
        infinity_background(current);
        sfSprite_setPosition(current->sprite, current->position);
        sfRenderWindow_drawSprite(window, current->sprite, NULL);
        current = current->next;
    }
    while (text != NULL) {
        sfText_setPosition(text->text, text->position);
        sfRenderWindow_drawText(window, text->text, NULL);
        text = text->next;
    }
}

bool check_button_selec(text_t *head, sfEvent event, player_t *player)
{
    text_t *current = head;
    sfVector2i mouse;

    mouse.x = event.mouseButton.x;
    mouse.y = event.mouseButton.y;
    for (int i = 0; i < 2; i++) {
        if (mouse.y <= current->position.y + 100 && mouse.y >=
        current->position.y && mouse.x >= current->position.x && mouse.x <=
        current->position.x + 350) {
            if (my_strcompare(current->name, "man")) {
                initialisation_player(player, "assets/player/boy.png", 1);
                return (true);
            }
            else if (my_strcompare(current->name, "woman")) {
                initialisation_player(player, "assets/player/girl.png", 2);
                return (true);
            }
        }
        current = current->next;
    }
    return (false);
}

bool check_event_selec(sfRenderWindow *window, sfEvent event, text_t **text,
player_t *player)
{
    sfMusic *click_tmp;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            click_tmp = sfMusic_createFromFile(
            "assets/sounds/click_sound.ogg");
            sfMusic_play(click_tmp);
            if (check_button_selec(*text, event, player) == true) {
                sfMusic_destroy(click_tmp);
                return (true);
            }
        }
        colore_button(window, *text, 2, 100);
    }
    return (false);
}

void free_select(texture_t *texture, text_t *text)
{
    texture_t *tmp = texture;
    text_t *tmp_text = text;

    while (texture != NULL) {
        tmp = texture;
        texture = texture->next;
        free(tmp);
    }
    while (text != NULL) {
        tmp_text = text;
        text = text->next;
        free(tmp_text);
    }
}

void select_hero(general_t *general,
player_t *player, other_t *other)
{
    sfEvent event;
    texture_t *menu_texture = NULL;
    text_t *menu_text = NULL;

    load_sprite_selection(&menu_texture, &menu_text, other);
    while (sfRenderWindow_isOpen(general->window)) {
        sfRenderWindow_clear(general->window, sfBlack);
        display_selection(general->window, menu_texture, menu_text);
        sfRenderWindow_display(general->window);
        if (check_event_selec(general->window, event, &menu_text, player)
        == true) {
            free_select(menu_texture, menu_text);
            return;
        }
    }
}
