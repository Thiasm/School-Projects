/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strncat.c
*/

#include "my.h"

char *my_strncat(char *s1, const char *s2, size_t n)
{
    size_t i = 0;
    size_t j = my_strlen(s1);

    while (s2[j] && j < n) {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    return (s1);
}
