/*
** EPITECH PROJECT, 2019
** fight
** File description:
** fight
*/

#include "rpg.h"

void sprite_boss(monster_t *monster)
{
    sfTexture_destroy(monster->texture);
    sfSprite_destroy(monster->sprite);
    if (my_strcmp("Ogre", monster->name) == 0)
        monster->texture = sfTexture_createFromFile(
        "assets/monster/Ogre.png", NULL);
    if (my_strcmp("Lampa", monster->name) == 0)
        monster->texture = sfTexture_createFromFile(
        "assets/monster/Lamia.png", NULL);
    if (my_strcmp("Evilking", monster->name) == 0)
        monster->texture = sfTexture_createFromFile(
        "assets/monster/Evilking.png", NULL);
    if (my_strcmp("Kerberos", monster->name) == 0)
        monster->texture = sfTexture_createFromFile(
        "assets/monster/Kerberos.png", NULL);
    monster->sprite = sfSprite_create();
    sfSprite_setTexture(monster->sprite, monster->texture, sfTrue);
    monster->position.x = 850;
    monster->position.y = 400;
    return;
}

void fight_gameplay(sfEvent event, text_t *text, player_t *player,
monster_t *monster)
{
    text_t *tmp = text;
    sfVector2i mouse;

    if (event.type == sfEvtMouseButtonPressed) {
        mouse.x = event.mouseButton.x;
        mouse.y = event.mouseButton.y;
        for (int i = 0; i < 2; i++) {
            if (mouse.y <= tmp->position.y + 100 && mouse.y >= tmp->position.y
            && mouse.x >= tmp->position.x &&
            mouse.x <= tmp->position.x + 400) {
                if (my_strcompare(tmp->name, "Attack") == 1 &&
                player->tour == 0)
                    attack(player->next, monster, player);
                if (my_strcompare(tmp->name, "Spells"))
                    return;
            }
            tmp = tmp->next;
        }
    }
    return;
}

void fight_loop(player_t *player, monster_t *monster, general_t *general)
{
    sfEvent event;
    fight_t *fight = malloc(sizeof(fight_t));
    text_t *text = malloc(sizeof(text_t));

    sfRenderWindow_setView(general->window,
    sfRenderWindow_getDefaultView(general->window));
    general->clock = sfClock_create();
    init_fight(fight, monster, &text, player);
    while (1) {
        sfRenderWindow_clear(general->window, sfBlack);
        display_fight(fight, monster, general, text);
        display_attack(general, player);
        colore_button(general->window, text, 2, 100);
        if (check_dead(player->next, monster, fight, general) == 1)
            return;
        while (sfRenderWindow_pollEvent(general->window, &event))
            fight_gameplay(event, text, player, monster);
        sfRenderWindow_display(general->window);
    }
}
