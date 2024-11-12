/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_putstr.c
*/

#include "my.h"

void my_putstr(char const *s)
{
    write(1, s, my_strlen(s));
}
