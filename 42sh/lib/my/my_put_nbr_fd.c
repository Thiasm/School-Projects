/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** my_put_nbr_fd.c
*/

#include "my.h"

void my_put_nbr_fd(int n, int fd)
{
    if (n == -2147483648)
        my_putstr_fd("-2147483648", fd);
    else {
        if (n < 0) {
            my_putchar_fd('-', fd);
            n = -n;
        }
        if (n >= 10)
            my_put_nbr_fd((n / 10), fd);
        my_putchar_fd((n % 10 + '0'), fd);
    }
}
