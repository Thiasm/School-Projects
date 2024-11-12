/*
** EPITECH PROJECT, 2019
** select_class
** File description:
** my_rpg
*/

#include "rpg.h"

void display_class(texture_t *texture, text_t *text, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, texture->sprite, NULL);
    for (int i = 0; i < 5; i++) {
        sfText_setPosition(text->text, text->position);
        sfRenderWindow_drawText(window, text->text, NULL);
        text = text->next;
    }
}

void apply_class(player_t *player, char *class, int genre)
{
    char *path = my_strcat("assets/classes/", class);

    sfTexture_destroy(player->texture);
    sfSprite_destroy(player->sprite);
    player->next->class = class;
    chose_class(player->next);
    if (genre == 1)
        path = my_strcat(path, "_m.png");
    else if (genre == 2)
        path = my_strcat(path, "_w.png");
    player->texture = sfTexture_createFromFile(path, NULL);
    player->sprite = sfSprite_create();
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
}

bool class_event(text_t *text, player_t *player, sfEvent event)
{
    text_t *tmp = text;
    sfVector2i mouse;

    mouse.x = event.mouseButton.x;
    mouse.y = event.mouseButton.y;
    for (int i = 0; i < 4; i++) {
        if (mouse.y <= tmp->position.y + 100 && mouse.y >= tmp->position.y
        && mouse.x >= tmp->position.x && mouse.x <= tmp->position.x + 400) {
            if (my_strcompare(tmp->name, "Wizard"))
                apply_class(player, "wizard", player->genre);
            if (my_strcompare(tmp->name, "Archer"))
                apply_class(player, "archer", player->genre);
            if (my_strcompare(tmp->name, "Paladins"))
                apply_class(player, "paladin", player->genre);
            if (my_strcompare(tmp->name, "Warrior"))
                apply_class(player, "warrior", player->genre);
            return (true);
        }
    tmp = tmp->next;
    }
    return (false);
}

void select_class(general_t *general, player_t *player, other_t *other)
{
    texture_t *texture;
    text_t *text;
    sfEvent event;

    sfRenderWindow_setView(general->window,
    sfRenderWindow_getDefaultView(general->window));
    initialisation_class(&texture, &text, other);
    edit_class_text(text);
    while (sfRenderWindow_isOpen(general->window)) {
        sfRenderWindow_clear(general->window, sfBlack);
        colore_button(general->window, text, 4, 70);
        display_class(texture, text, general->window);
        while (sfRenderWindow_pollEvent(general->window, &event)) {
            if (class_event(text, player, event) == true)
                return;
        }
        sfRenderWindow_display(general->window);
    }
    sfRenderWindow_setView(general->window, general->view);
}
