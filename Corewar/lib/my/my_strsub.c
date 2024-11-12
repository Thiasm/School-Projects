/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strsub.c
*/

#include "my.h"

char *my_strsub(char const *s, unsigned int start, size_t len)
{
    char *str = (char *)malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        return (NULL);
    my_strncpy(str, &(s[start]), len);
    str[len] = '\0';
    return (str);
}
