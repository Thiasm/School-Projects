/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_bzero.c
*/

#include "my.h"

void my_bzero(void *s, size_t n)
{
    if (n > 0)
        my_memset(s, 0, n);
}
