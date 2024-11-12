/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** Concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return (dest);
}
