/*
** EPITECH PROJECT, 2018
** my_strcmp.c
** File description:
** Compare two strings and return 0 is it matches.
*/

#include "../include/my.h"

int my_strcmp(char *string, char *str)
{
    for (int i = 0; string[i] == str[i]; i++)
        if (string[i] == '\0' && str[i] == '\0')
            return (1);
    return (0);
}
