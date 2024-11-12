/*
** EPITECH PROJECT, 2018
** delivery
** File description:
** lib_functions.c
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    for (int rng = 0; str[rng] != '\0'; rng++)
        my_putchar(str[rng]);
}

int my_atoi(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + str[i] - '0';
        if (str[i] >= 'a' && str[i] <= 'z')
            return (-84);
        else if (str[i] >= 'A' && str[i] <= 'Z')
            return (-84);
    }
    return (nb);
}

int my_strlen(char const *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        rng++;
    }
    return (rng);
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else {
        my_putchar(nb + '0');
    }
}
