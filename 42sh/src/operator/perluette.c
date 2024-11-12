/*
** EPITECH PROJECT, 2019
** perluette
** File description:
** 42sh
*/

#include "minishell.h"

void exec_double_perluette(room_t *room, list_t *list)
{
    int a;

    a = exec_room(room->left);
    if (a != 0 && room->right->type == 0)
        return;
    if (room->right != NULL && room->right->type > 0)
        exec_ope(room->right, list);
    else if (room->right != NULL)
        exec_room(room->right);
}
