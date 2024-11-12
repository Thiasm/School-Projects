/*
** EPITECH PROJECT, 2019
** create_tree
** File description:
** minishell2
*/

#include "minishell.h"

void complete_tree(list_t *list, room_t *room)
{
    room_t *place = list->root;
    room_t *chain = list->last;
    int last = chain->type;

    while (place->right != NULL)
        place = place->right;
    place->right = chain;
    place = place->right;
    chain = chain->previous;
    while (chain != room) {
        if (last > 0) {
            place->right = NULL;
            break;
        }
        else {
            place->left = chain;
            place = place->left;
            chain = chain->previous;
        }
    }
}

void add_to_branch(room_t *room)
{
    if (room->next->left == NULL) {
        room->back = room->next;
        room->next->left = room;
    }
    else if (room->next->right == NULL) {
        room->back = room->next;
        room->next->right = room;
    }
}

void add_ope(room_t *ope, list_t *list, room_t *room, room_t *last_ope)
{
    room_t *check = NULL;

    list->nb_ope += 1;
    if (list->root == NULL)
        list->root = ope;
    else {
        check = list->root;
        while (check->right != NULL)
            check = check->right;
        if (check->left == NULL)
            check->left = ope;
        else
            check->right = ope;
        ope->back = last_ope;
        room->back = ope;
    }
}

void new_branch(room_t *ope, list_t *list, room_t *last_ope)
{
    room_t *room = ope->previous;

    add_ope(ope, list, room, last_ope);
    while (room != last_ope) {
        add_to_branch(room);
        room = room->previous;
    }
}

list_t *generate_tree(char **cmd)
{
    room_t *room = NULL;
    room_t *tmp = NULL;
    list_t *list = create_list(cmd);

    if (list->first == NULL)
        return (NULL);
    room = list->first;
    while (room != NULL) {
        if (room->type > 0) {
            new_branch(room, list, tmp);
            tmp = room;
        }
        room = room->next;
    }
    if (tmp == NULL)
        simple_command(list);
    else
        complete_tree(list, tmp);
    return (list);
}
