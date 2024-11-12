/*
** EPITECH PROJECT, 2019
** tree_tool
** File description:
** 42sh
*/

#include "minishell.h"

list_t *create_mark(void)
{
    list_t *list;

    list = malloc(sizeof(list_t));
    list->first = NULL;
    list->last = NULL;
    list->root = NULL;
    list->nb_ope = 0;
    return (list);
}

int find_type(char *str)
{
    if (my_strcmp(str, ";") == 0)
        return (1);
    if (my_strcmp(str, "|") == 0)
        return (2);
    if (my_strcmp(str, ">") == 0)
        return (3);
    if (my_strcmp(str, ">>") == 0)
        return (4);
    if (my_strcmp(str, "<") == 0)
        return (5);
    if (my_strcmp(str, "<<") == 0)
        return (6);
    if (my_strcmp(str, "&&") == 0)
        return (7);
    if (my_strcmp(str, "||") == 0)
        return (8);
    return (0);
}
