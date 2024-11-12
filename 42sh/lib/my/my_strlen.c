/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strlen.c
*/

#include "my.h"

size_t my_strlen(const char *s)
{
    size_t i = 0;

    while (s[i])
        i++;
    return (i);
}
