/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** PSU 01
*/

#include <stdarg.h>
#include "../include/my.h"

void my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, *str);
    while (str[i]) {
        if (str[i] == '%') {
            test_flag(str, &i, ap);
            test_flag_nb(str, &i, ap);
        }
        else {
            my_putchar(str[i]);
            i = i + 1;
        }
    }
    va_end(ap);
}

void my_put_nbr_int(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb > 9) {
        my_put_nbr_int(nb / 10);
        my_put_nbr_int(nb % 10);
    }
    else {
        my_putchar(nb + '0');
    }
}

void test_flag_nb(char *str, int *i, va_list ap)
{
    switch (str[*i + 1]) {
    case 'd' :
        my_put_nbr_int(va_arg(ap, int));
        *i = *i + 2;
        break;
    }
}

void test_flag(char *str, int *i, va_list ap)
{
    switch (str[*i + 1]) {
    case 'c' :
        my_putstr(va_arg(ap, char*));
        *i += 2;
        break;
    case 's' :
        my_putstr(va_arg(ap, char*));
        *i += 2;
        break;
    }
}
