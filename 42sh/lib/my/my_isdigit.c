/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_isdigit.c
*/

#include "my.h"

int my_isdigit(int c)
{
    return ((c >= '0' && c <= '9') ? 1 : 0);
}
