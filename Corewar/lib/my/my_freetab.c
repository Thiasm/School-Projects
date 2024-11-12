/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_freetab.c
*/

#include "my.h"

void my_freetab(char **tab)
{
    int i;
    int len;

    if (tab) {
        if (*tab) {
            i = -1;
            len = my_tablen(tab);
            while (++i < len)
                free(tab[i]);
        }
        free(tab);
        tab = NULL;
    }
}
