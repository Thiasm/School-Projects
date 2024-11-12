/*
** EPITECH PROJECT, 2019
** hms
** File description:
** matchstick
*/

#include "my.h"

int how_many_stick(char *str)
{
    int nb = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] == '|')
            nb += 1;
    }
    return (nb);
}
