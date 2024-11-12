/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_isspace.c
*/

#include "my.h"

int my_isspace(int c)
{
    c = (unsigned char)c;
    if (c == ' ' || c == '\n' || c == '\f' || c == '\r'
        || c == '\v' || c == '\t' || c == '\0')
        return (1);
    else
        return (0);
}
