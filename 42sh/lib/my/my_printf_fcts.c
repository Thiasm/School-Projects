/*
** EPITECH PROJECT, 2018
** printf.c
** File description:
** recode printf and fue flags
*/

#include "my_printf.h"

void my_put_count(int *val, int j)
{
    *val = j;
}

void my_put_base(long long int nbr, char *base)
{
    int base_len = my_strlen(base);
    int result;
    if (nbr < 0) {
        my_putchar('-');
        nbr *= -1;
    }
    if (nbr >= base_len) {
        result = nbr % base_len;
        nbr /= base_len;
        my_put_base(nbr, base);
    } else if (nbr > 0) {
        result = nbr % base_len;
        nbr /= base_len;
    }
    my_putchar(base[result]);
}

void my_put_str_octal_calc(unsigned char nb)
{
    int res[3];
    int nbr;
    res[0] = 0;
    res[1] = 0;
    res[2] = 0;
    for (int i = 2; nb > 0; i--) {
        nbr = nb % 8;
        nb /= 8;
        res[i] = nbr;
    }
    my_put_nbr(res[0]);
    my_put_nbr(res[1]);
    my_put_nbr(res[2]);
}

void my_put_str_octal(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            my_put_str_octal_calc(str[i]);
        } else
            my_putchar(str[i]);
    }
}

void my_put_add(long long int nbr)
{
    my_putstr("0x");
    my_put_base(nbr, "0123456789abcdef");
}
