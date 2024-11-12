/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** Verify is the given str is num
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!my_isdigit(str[i]))
            return 1;
    return 0;
}
