/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(char const *str)
{
    int len = my_strlen(str);
    char *dup = malloc(sizeof(char) * len + 1);

    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len] = '\0';
    return (dup);
}