/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_isalnum.c
*/

#include "my.h"

int my_isalnum(int c)
{
    return ((my_isalpha(c) || my_isdigit(c)) ? 1 : 0);
}
