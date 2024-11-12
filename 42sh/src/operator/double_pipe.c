/*
** EPITECH PROJECT, 2019
** double_pipe
** File description:
** 42sh
*/

#include "minishell.h"

void exec_double_pipe(room_t *room, list_t *list)
{
    int a = 0;

    a = exec_room(room->left);
    if (a == 0)
        return;
    if (room->right != NULL && room->right->type > 0)
        exec_ope(room->right, list);
    else if (room->right != NULL)
        exec_room(room->right);
}
