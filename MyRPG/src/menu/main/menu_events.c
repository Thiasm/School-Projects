/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** menu_events
*/

#include "rpg.h"

int check_button(text_t *head, sfEvent event)
{
    text_t *current = head;
    sfVector2i mouse;

    mouse.x = event.mouseButton.x;
    mouse.y = event.mouseButton.y;
    while (current != NULL) {
        if (mouse.y <= current->position.y + 100 && mouse.y >=
        current->position.y && mouse.x >= current->position.x && mouse.x
        <= current->position.x + 250) {
            if (my_strcompare(current->name, "Play"))
                return (1);
            if (my_strcompare(current->name, "Settings"))
                return (2);
            if (my_strcompare(current->name, "Quit"))
                return (3);
        }
        current = current->next;
    }
    return (0);
}

void colore_button(sfRenderWindow *window, text_t *head, int k, int size)
{
    text_t *text = head;
    sfVector2i mouse;
    int space = 0;

    mouse.x = sfMouse_getPosition((const struct sfWindow *)window).x;
    mouse.y = sfMouse_getPosition((const struct sfWindow *)window).y;
    for (int i = 0; i < k; i++) {
        space = my_strlen(text->name) * (size * 0.7);
        if (mouse.y <= text->position.y + size && mouse.y >= text->position.y
        && mouse.x >= text->position.x && mouse.x <= text->position.x + space)
            sfText_setColor(text->text, sfRed);
        else
            sfText_setColor(text->text, sfWhite);
        space = 250;
        text = text->next;
    }
}

int check_event(sfRenderWindow *window, sfEvent event, text_t **text,
other_t *other)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfMusic_destroy(other->background_music);
            sfMusic_destroy(other->click_sound);
            sfRenderWindow_close(window);
            return (0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            sfMusic_play(other->click_sound);
            return (check_button(*text, event));
        }
        colore_button(window, *text, 2, 100);
    }
    return (0);
}
