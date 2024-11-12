/*
** EPITECH PROJECT, 2019
** pause_tool
** File description:
** my_rpg
*/

#include "rpg.h"

int back_to_game(general_t *general, other_t *other, int check)
{
    if (check == 1)
        general->check = 1;
    other->pause = 0;
    sfRenderWindow_setView(general->window, general->view);
    return (1);
}

void display_how_to_play(texture_t *texture_head, general_t *general)
{
    texture_t *texture = texture_head;

    for (int i = 0; i < 1; i++) {
        sfSprite_setPosition(texture->sprite, texture->position);
        sfRenderWindow_drawSprite(general->window, texture->sprite, NULL);
        texture = texture->next;
    }
}

void how_to_play(general_t *general)
{
    int how = 1;
    texture_t *texture;
    sfEvent event;

    add_texture(&texture, "assets/menu/howtoplay.png",
    "guide", (sfVector2f){0, 0});
    while (how == 1) {
        display_how_to_play(texture, general);
        while (sfRenderWindow_pollEvent(general->window, &event))
            if (event.type == sfEvtMouseButtonPressed)
                how = 0;
        sfRenderWindow_display(general->window);
    }
}

void restart_game(general_t *general, other_t *other)
{
    general_t *general_new = malloc(sizeof(general_t));
    other_t *other_new = malloc(sizeof(other_t));
    player_t *player_new = malloc(sizeof(player_t));
    world_t *world_new = malloc(sizeof(world_t));

    sfRenderWindow_close(general->window);
    sfMusic_destroy(other->background_music);
    sfMusic_destroy(other->click_sound);
    sfMusic_destroy(other->step_sound);
    menu_main_initiliaze(general_new, world_new, player_new, other_new);
}
