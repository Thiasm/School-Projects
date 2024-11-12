/*
** EPITECH PROJECT, 2019
** My RPG
** File description:
** menu_main
*/

#include "rpg.h"

void free_all(texture_t *menu_texture, text_t *menu_text)
{
    texture_t *tmp = NULL;
    text_t *text_tmp = NULL;

    while (menu_texture != NULL)
    {
        tmp = menu_texture;
        menu_texture = menu_texture->next;
        free(tmp);
    }
    while (menu_text != NULL)
    {
        text_tmp = menu_text;
        menu_text = menu_text->next;
        free(text_tmp);
    }
}

void initialise_menu(general_t *general)
{
    sfRenderWindow *window = NULL;

    general->window = window;
    general->window = create_my_window();
    return;
}

void my_destroy(general_t *general, other_t *other)
{
    sfMusic_destroy(other->background_music);
    sfMusic_destroy(other->step_sound);
    sfMusic_destroy(other->click_sound);
    sfRenderWindow_close(general->window);
    return;
}

void value(int return_value, general_t *general, other_t *other)
{
    if (return_value == 3)
        my_destroy(general, other);
    if (return_value == 2)
        settings(general);
}

void menu_main_initiliaze(general_t *general, world_t *world,
player_t *player, other_t *other)
{
    text_t *menu_text = NULL;
    texture_t *menu_texture = NULL;
    sfEvent event;
    int return_value = 0;

    initialise_menu(general);
    load_sprite_menu(&menu_texture, &menu_text, other);
    while (sfRenderWindow_isOpen(general->window)) {
        clear_and_display(general->window, menu_texture, menu_text);
        infinity_background(menu_texture);
        return_value = check_event(general->window, event, &menu_text, other);
        if (return_value == 1) {
            select_hero(general, player, other);
            sfMusic_destroy(other->background_music);
            my_rpg(general, world, player, other);
        }
        value(return_value, general, other);
        return_value = 0;
        sfRenderWindow_display(general->window);
    }
}
