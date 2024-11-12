/*
** EPITECH PROJECT, 2019
** semicolon
** File description:
** 42sh
*/

#include "minishell.h"

void exec_semicolon(room_t *room, list_t *list)
{
    if (room->left->type != -1) {
        exec_room(room->left);
        if (room->right != NULL && room->right->type > 0)
            exec_ope(room->right, list);
        else if (room->right != NULL)
            exec_room(room->right);
    }
}
