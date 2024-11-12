/*
** EPITECH PROJECT, 2019
** create_token
** File description:
** miishell2
*/

#include "minishell.h"

void add_token(char *str, list_t *list)
{
    room_t *room;

    room = malloc(sizeof(room_t));
    room->left = NULL;
    room->right = NULL;
    room->next = NULL;
    room->back = NULL;
    room->previous = NULL;
    room->token = my_strdup(str);
    room->type = find_type(str);
    if (list->first == NULL)
        list->first = room;
    else {
        room->previous = list->last;
        room->previous->next = room;
    }
    list->last = room;
}

list_t *create_list(char **cmd)
{
    list_t *list = create_mark();

    for (int i = 0; cmd[i] != NULL; i++) {
        add_token(cmd[i], list);
    }
    return (list);
}

void simple_command(list_t *list)
{
    room_t *chain = list->first;
    room_t *room = chain;

    list->root = room;
    while (chain->next) {
        add_to_branch(chain);
        chain = chain->next;
    }
}
