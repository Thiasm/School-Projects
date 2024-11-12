/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_tablen.c
*/

#include "my.h"

int my_tablen(char **tab)
{
    int len = 0;

    if (tab && *tab) {
        while (tab[len])
            len++;
        return (len);
    }
    return (0);
}
