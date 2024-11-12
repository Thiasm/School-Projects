/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_putchar.c
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
