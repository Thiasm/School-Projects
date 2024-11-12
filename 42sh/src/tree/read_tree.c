/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** minishell.c
*/

#include "minishell.h"

void exec_double_ope(room_t *room, list_t *list)
{
    switch (room->type) {
    case 4:
        redir_double(room);
        break;
    case 6:
        double_redir_left(room);
        break;
    case 7:
        exec_double_perluette(room, list);
        break;
    case 8:
        exec_double_pipe(room, list);
        break;
    default:
        printf("Where the fuck I am?\n");
        list->root = NULL;
        break;
    }
}

void exec_ope(room_t *room, list_t *list)
{
    switch (room->type) {
    case 1:
        exec_semicolon(room, list);
        break;
    case 2:
        pipe_handle(room, list);
        break;
    case 3:
        redir(room);
        break;
    case 5:
        redir_left(room);
        break;
    default:
        exec_double_ope(room, list);
        break;
    }
}

void free_tree(list_t *list)
{
    room_t *room = list->first;
    room_t *tmp = NULL;

    while (room != NULL) {
        tmp = room->next;
        free(room);
        room = tmp;
    }
}

int read_tree(list_t *list)
{
    room_t *room = list->root;
    int ret = 0;

    if (list->first == NULL)
        return -1;
    if (list->root->type == 0)
        ret = exec_room(room);
    else
        exec_ope(room, list);
    free_tree(list);
    return ret;
}