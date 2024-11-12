/*
** EPITECH PROJECT, 2019
** funct_lib
** File description:
** functions from the libmy
*/

#include "navy.h"

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
    return (len);
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

int my_atoi(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb = nb * 10 + str[i] - '0';
    return (nb);
}