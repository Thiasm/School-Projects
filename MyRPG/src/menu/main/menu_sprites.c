/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** menu_sprites
*/

#include "rpg.h"

void load_sprite_menu(texture_t **head, text_t **text_head, other_t *other)
{
    other->game_font = sfFont_createFromFile("assets/menu/game_font.otf");
    other->click_sound = sfMusic_createFromFile
    ("assets/sounds/click_sound.ogg");
    other->background_music = sfMusic_createFromFile
    ("assets/sounds/menu_music.ogg");
    sfMusic_setLoop(other->background_music, sfTrue);
    sfMusic_play(other->background_music);
    add_text(text_head, "Play", other->game_font, (sfVector2f){800, 400});
    add_text(text_head, "Quit", other->game_font, (sfVector2f){800, 600});
    add_texture(head, (char * ) "assets/menu/logo.png", (char * ) "logo",
    (sfVector2f){830, -200});
    add_texture(head, (char * ) MENU_BACKGROUND_LOCATION, (char * )
    MENU_BUTTON_BACKGROUND, (sfVector2f){0, 0});
}

void load_sprite_selection(texture_t **head, text_t **text_head,
other_t *other)
{
    add_text(text_head, "woman", other->game_font, (sfVector2f){400, 600});
    add_text(text_head, "man", other->game_font, (sfVector2f){1100, 600});
    add_texture(head, "assets/trash/male.png", "male_symbol",
    (sfVector2f){1100, 200});
    add_texture(head, "assets/trash/female.png", "female_symbol",
    (sfVector2f){400, 200});
    add_texture(head, (char * ) MENU_BACKGROUND_LOCATION, (char * )
    MENU_BUTTON_BACKGROUND, (sfVector2f){0, 0});
}

void clear_and_display(sfRenderWindow *window, texture_t *head, text_t
*text_head)
{
    sfRenderWindow_clear(window, sfBlack);
    display_all(window, head, text_head);
}
