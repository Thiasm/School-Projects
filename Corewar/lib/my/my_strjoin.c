/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_strjoin.c
*/

#include "my.h"

char *my_strjoin(char const *s1, char const *s2)
{
    int len = my_strlen(s1) + my_strlen(s2) + 1;
    char *str = my_strnew(len);

    if (str != NULL) {
        my_strcat(str, s1);
        my_strcat(str, s2);
    }
    return (str);
}
