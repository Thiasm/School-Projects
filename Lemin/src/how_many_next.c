/*
** EPITECH PROJECT, 2019
** how_many_next.c
** File description:
** Return the number of tunnels link to the room
*/

#include "../include/my.h"

int how_many_next(char *name, char **link)
{
    int nbr = 0;

    for (int y = 0; link[y] != NULL; y++)
        if (my_strcmp(name, link[y]) == 1)
            nbr++;
    return (nbr);
}
