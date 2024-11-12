/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strnew.c
*/

#include "my.h"

char *my_strnew(size_t size)
{
    char *s = NULL;

    if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
        return (NULL);
    if (s) {
        my_bzero(s, size + 1);
        return (s);
    }
    free(s);
    return (NULL);
}
