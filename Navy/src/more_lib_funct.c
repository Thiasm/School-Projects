/*
** EPITECH PROJECT, 2019
** more lib funct
** File description:
** more functions from the libmy
*/

#include "navy.h"

int str_compare(char *str1, char *str2)
{
    int size_1 = my_strlen(str1);
    int size_2 = my_strlen(str2);

    if (size_1 != size_2)
        return (1);
    for (int i = 0; i < size_1; i++) {
        if (str1[i] != str2[i])
            return (1);
    }
    return (0);
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