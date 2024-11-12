/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strndup.c
*/

#include "my.h"

char *my_strndup(char const *s1, size_t len)
{
    char *scpy;

    if (!(scpy = (char *)malloc(sizeof(char) * len + 1)))
        return (NULL);
    return (my_strncpy(scpy, s1, len));
}
