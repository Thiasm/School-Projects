/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** funct_lib.c
*/

#include "tetris.h"
#include "proto.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int my_strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

int my_strcmp(char *s1, char *s2)
{
    int comp = 0;

    for (int i = 0; s2[i] != '\0'; i++) {
        if (s1[i] == '\0')
            return 1;
        if (s1[i] == s2[i])
            comp++;
    }
    if (comp == my_strlen(s1) && comp == my_strlen(s2))
        return 0;
    else
        return 1;
}

char *my_str_dup(char *str)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}