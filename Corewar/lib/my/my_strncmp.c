/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *ch1 = (unsigned char *)s1;
    unsigned char *ch2 = (unsigned char *)s2;

    while (*ch1 != '\0' && *ch1 == *ch2 && n > 0) {
        ch1++;
        ch2++;
        n--;
    }
    if (n == 0)
        return (0);
    else
        return (*ch1 - *ch2);
}
