/*
** EPITECH PROJECT, 2019
** dialog_pnj.c
** File description:
** dialog
*/

#include "rpg.h"

void edit_text_size(dialog_t *dialog)
{
    char *str = (char *) sfText_getString(dialog->text);
    char *new = NULL;
    int size = my_strlen(str);
    int j = 0;
    int i = 0;
    int x = size / 30;

    if (size > 30) {
        new = malloc(sizeof(char) * (size + (x + 1)));
        while (i < (size + 1)) {
            if (i == 30 || i == 60) {
                new[i] = '\n';
                i++;
            }
            new[i] = str[j];
            j += 1;
            i += 1;
        }
        new[i] = '\0';
        sfText_setString(dialog->text, new);
    }
}

void start_dialog(pnj_t *pnj, dialog_t *dialog, general_t *genral)
{
    dialog->name = pnj->text_a;
    dialog->position.x = (pnj->x * 32) + 520;
    dialog->position.y = (pnj->y * 32) + 500;
    if (pnj->meet == 1) {
        dialog->name = pnj->text_b;
        sfText_setString(dialog->text, pnj->text_b);
    } else
        sfText_setString(dialog->text, pnj->text_a);
    edit_text_size(dialog);
    pnj->meet = 1;
    sfText_setPosition(dialog->text, dialog->position);
    dialog->position.y -= 20;
    dialog->position.x -= 10;
    genral->bar_pos = dialog->position;
    return;
}

void check_dialog(int x, int y, general_t *general, world_t *world)
{
    pnj_t *pnj = world->next_p;

    if (x < 1 || y < 1 || x > 98 || y > 148)
        return;
    while (pnj != NULL) {
        if (pnj->x == x && pnj->y == y) {
            start_dialog(pnj, general->next_d, general);
        }
        pnj = pnj->next;
    }
    return;
}