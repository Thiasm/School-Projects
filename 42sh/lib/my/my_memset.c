/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_memset.c
*/

#include "my.h"

void *my_memset(void *b, int c, size_t len)
{
    size_t i = 0;
    unsigned char ch = (unsigned char)c;
    unsigned char *s = (unsigned char *)b;

    while (i < len) {
        s[i] = ch;
        i++;
    }
    return (b);
}
