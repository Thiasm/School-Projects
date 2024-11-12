/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_ssscmp.c
*/

#include "my.h"

int my_ssscmp(char *s, char *s1, char *s2, char *s3)
{
    if (!my_strcmp(s, s1) || !my_strcmp(s, s2) || !my_strcmp(s, s3))
        return (1);
    return (0);
}
