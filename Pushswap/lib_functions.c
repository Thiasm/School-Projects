/*
** EPITECH PROJECT, 2018
** lib_functions
** File description:
** pushswap
*/

#include "my.h"

int my_strlen(char const *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        rng++;
    }
    return (rng);
}

int my_atoi(char *str)
{
    int lenght = 0;
    int result = 0;
    int neg;

    lenght = my_strlen(str);
    for (int i = 0; i < lenght; i++) {
        if (str[i] == '-')
            neg = 1;
        else
            result = result * 10 + (str[i] - 48);
    }
    if (neg == 1) {
    result *= -1;
    neg = 0;
    }
    return (result);
}

int my_putstr(char const *str)
{
    int rng = 0;

    while (str[rng] != '\0') {
        my_putchar(str[rng]);
        rng++;
    }
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}