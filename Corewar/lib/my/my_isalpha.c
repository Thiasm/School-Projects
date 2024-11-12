/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_isalpha.c
*/

#include "my.h"

int my_isalpha(int c)
{
    return (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0);
}
