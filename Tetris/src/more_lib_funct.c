/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** more_lib_funct.c
*/

#include "tetris.h"
#include "proto.h"

int my_atoi(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        nb = nb * 10 + str[i] - '0';
    }
    return nb;
}

int my_strncmp(char *s1, char *s2, int n)
{
    int comp = 0;

    for (int i = 0; i != n; i++) {
        if (s2[i] == '\0')
            return (1);
        if (s1[i] == s2[i]) {
            comp++;
        }
    }
    if (comp == my_strlen(s1))
        return (0);
    else
        return (1);
}

char *my_strcat(char *s1, char *s2)
{
    char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int j = my_strlen(s1);

    for (int i = 0; s1[i] != '\0'; i++)
        str[i] = s1[i];
    for (int i = 0; s2[i] != '\0'; i++) {
        str[j] = s2[i];
        j++;
    }
    str[j] = '\0';
    return (str);
}