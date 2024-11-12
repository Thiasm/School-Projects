/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_memalloc.c
*/

#include "my.h"

void *my_memalloc(size_t size)
{
    unsigned char *alloc;

    if (size == 0)
        return (NULL);
    alloc = (unsigned char *)malloc(size);
    if (alloc)
        my_bzero(alloc, size);
    return ((void *)alloc);
}
