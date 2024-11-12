/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    unsigned char *ch1 = (unsigned char *)s1;
    unsigned char *ch2 = (unsigned char *)s2;

    while (*ch1 && *ch1 == *ch2) {
        ch1++;
        ch2++;
    }
    return (*ch1 - *ch2);
}
