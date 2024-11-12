/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_sscmp.c
*/

#include "my.h"

int my_sscmp(char *s, char *s1, char *s2)
{
    if (!my_strcmp(s, s1) || !my_strcmp(s, s2))
        return (1);
    return (0);
}
