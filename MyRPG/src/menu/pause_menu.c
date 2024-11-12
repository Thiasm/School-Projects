/*
** EPITECH PROJECT, 2019
** pause_menu
** File description:
** rpg
*/

#include "rpg.h"

void initialise_pause(text_t **text_head,
texture_t **texture_head, other_t *other)
{
    add_text(text_head, "PAUSE", other->game_font, (sfVector2f){750, 50});
    add_text(text_head, "How to Play",
other->game_font, (sfVector2f){620, 200});
    add_text(text_head, "Continue", other->game_font, (sfVector2f){700, 400});
    add_text(text_head, "Restart", other->game_font,(sfVector2f){700, 600});
    add_text(text_head, "Quit", other->game_font, (sfVector2f){800, 800});
    add_texture(texture_head, "assets/menu/menu_background.png",
"background", (sfVector2f){0, 0});
}

void display_pause(general_t *general, text_t *text_head,
texture_t *texture_head)
{
    texture_t *texture = texture_head;
    text_t *text = text_head;

    for (int i = 0; i < 1; i++) {
        infinity_background(texture);
        sfSprite_setPosition(texture->sprite, texture->position);
        sfRenderWindow_drawSprite(general->window, texture->sprite, NULL);
        texture = texture->next;
    }
    for (int j = 0; j < 5; j++) {
        sfText_setPosition(text->text, text->position);
        sfRenderWindow_drawText(general->window, text->text, NULL);
        text = text->next;
    }
}

int pause_event(general_t *general, sfEvent event, text_t *text, other_t *other)
{
    text_t *tmp = text;
    sfVector2i mouse;

    mouse.x = event.mouseButton.x;
    mouse.y = event.mouseButton.y;
    for (int i = 0; i < 4; i++) {
        if (mouse.y <= tmp->position.y + 100 && mouse.y >= tmp->position.y
        && mouse.x >= tmp->position.x && mouse.x <= tmp->position.x + 400) {
            if (my_strcompare(tmp->name, "Continue"))
                return (back_to_game(general, other, 0));
            if (my_strcompare(tmp->name, "Quit"))
                return (back_to_game(general, other, 1));
            if (my_strcompare(tmp->name, "How to Play"))
                how_to_play(general);
            if (my_strcompare(tmp->name, "Restart"))
                return (84);
        }
        tmp = tmp->next;
    }
    return (0);
}

int launch_pause(general_t *general, other_t *other)
{
    text_t *text;
    texture_t *texture;
    sfEvent event;

    sfRenderWindow_setView(general->window,
    sfRenderWindow_getDefaultView(general->window));
    initialise_pause(&text, &texture, other);
    while (other->pause == 1) {
        sfRenderWindow_clear(general->window, sfBlack);
        display_pause(general, text, texture);
        colore_button(general->window, text, 4, 100);
        while (sfRenderWindow_pollEvent(general->window, &event)) {
            if (event.type == sfEvtMouseButtonPressed) {
                if (pause_event(general, event, text, other) == 84)
                    return (84);
            }
        }
        sfRenderWindow_display(general->window);
    }
    return (0);
}

int pause_menu(general_t *general, other_t *other)
{
     if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        other->pause = 1;
        if (launch_pause(general, other) == 84)
            return (84);
     }
     return (0);
}
