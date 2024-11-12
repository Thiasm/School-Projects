/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strcpy.c
*/

#include "my.h"

char *my_strcpy(char *dst, const char *src)
{
    int i = 0;

    while (src[i]) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
