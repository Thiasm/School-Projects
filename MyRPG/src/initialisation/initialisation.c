/*
** EPITECH PROJECT, 2019
** intisialisation
** File description:
** init
*/

#include "rpg.h"

void initialisation(general_t *general, world_t *world, player_t *player,
other_t *other)
{
    general->rect = (sfFloatRect) { 0, 0, 1216, 784};
    general->move = (sfVector2f) { 640, 610 };
    general->chose = 0;
    general->live = 0;
    general->view = sfView_createFromRect(general->rect);
    intialisation_general(general);
    initialisation_dialog(general, other);
    sfRenderWindow_setFramerateLimit(general->window, 80);
    sfView_zoom(general->view, 1);
    world->next_e = NULL;
    other->clock_m = sfClock_create();
    initialisation_world(world, "assets/world/start.png");
    initialisation_music(other);
    map_binary(general);
    read_pnj(world);
    read_monster(world);
    init_quest(general, other);
    initialisation_monster(general, world);
    stat_player(player);
}

void initialisation_dialog(general_t *general, other_t *other)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    dialog->text = sfText_create();
    sfText_setCharacterSize(dialog->text, 15);
    sfText_setColor(dialog->text, sfWhite);
    sfText_setFont(dialog->text, other->game_font);
    dialog->name = NULL;
    general->next_d = dialog;
    other->dialogt = sfTexture_createFromFile("assets/pnj/dialogue.png", NULL);
    other->dialogs = sfSprite_create();
    sfSprite_setTexture(other->dialogs, other->dialogt, sfTrue);
    return;
}

void initialisation_music(other_t *other)
{
    other->background_music = sfMusic_createFromFile(
    "assets/sounds/game_music.ogg");
    sfMusic_setVolume(other->background_music, 50);
    other->step_sound = sfMusic_createFromFile("assets/sounds/step.wav");
    sfMusic_setVolume(other->step_sound, 10);
    sfMusic_play(other->background_music);
}

void initialisation_player(player_t *player, char *location, int genre)
{
    player->texture = sfTexture_createFromFile(location, NULL);
    player->sprite = sfSprite_create();
    player->position.x = 0;
    player->position.y = 0;
    player->rect.top = 0;
    player->rect.left = 0;
    player->rect.width = 32;
    player->rect.height = 48;
    player->pos_y = 13;
    player->pos_x = 19;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->direct = 3;
    player->deplacement = sfClock_create();
    player->genre = genre;
}
