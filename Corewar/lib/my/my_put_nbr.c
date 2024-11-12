/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** Displays the number given as parameter
*/

#include "my.h"

void my_put_nbr(long long int nb)
{
    long long int nbr;
    if (nb < 0) {
        my_putchar('-');
        nb = -1 * nb;
    }
    nbr = nb / 10;
    if (nbr > 0)
        my_put_nbr(nbr);
    my_putchar((nb % 10) + '0');
}
