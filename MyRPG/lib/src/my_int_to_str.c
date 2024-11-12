/*
** EPITECH PROJECT, 2018
** itostr
** File description:
** returns an int given as parameter as a string of char malloc'd
*/

#include <stdlib.h>

char *itoa(int nb)
{
    char *str = NULL;
    int neg = 0;
    int i = 1;
    int j = 1;

    if (nb < 0) {
        neg = 1;
        nb = nb * -1;
    }
    for (; nb / i > 9; i = i * 10)
        j++;
    str = malloc(sizeof(char) * (j + neg + 1));
    str[j + neg] = '\0';
    str[0] = neg == 1 ? '-' : str[0];
    for (int j = neg == 1 ? 1 : 0; i >= 1; j++) {
        str[j] = (nb / i + '0');
        nb = nb % i;
        i = i / 10;
    }
    return (str);
}
