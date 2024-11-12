/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main file for my_printf.c
*/

#include "my_printf.h"

void my_put_un_int(unsigned long long int nb)
{
    long long int nbr = nb / 10;
    if (nbr > 0)
        my_put_nbr(nbr);
    my_putchar((nb % 10) + '0');
}

void arg_case_begin(char arg, va_list ap, int j)
{
    switch (arg) {
    case 'd' :
    case 'i' : my_put_nbr(va_arg(ap, int));
        break;
    case 'b' : my_put_base(va_arg(ap, unsigned int), "01");
        break;
    case 'o' : my_put_base(va_arg(ap, int), "01234567");
        break;
    case 'u' : my_put_un_int(va_arg(ap, int));
        break;
    case 'x' : my_put_base(va_arg(ap, int), "0123456789abcdef");
        break;
    case 'X' : my_put_base(va_arg(ap, int), "0123456789ABCDEF");
        break;
    default : arg_case_end(arg, ap, j);
    }
}

void arg_case_end(char arg, va_list ap, int j)
{
    switch (arg) {
    case 'c' : my_putchar(va_arg(ap, int));
        break;
    case 's' : my_putstr(va_arg(ap, char *));
        break;
    case 'S' : my_put_str_octal(va_arg(ap, char *));
        break;
    case 'p' : my_put_add(va_arg(ap, long long int));
        break;
    case 'n' : my_put_count(va_arg(ap, int *), j);
        break;
    case '%' : my_putchar('%');
        break;
    default : my_putchar('%');
        my_putchar(arg);
    }
}

int my_printf(char *str, ...)
{
    va_list ap;
    char *to_print = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i;
    int j = 0;

    va_start(ap, str);
    for (i = 0; str[i] != '\0'; i++, j++) {
        if (str[i] == '%') {
            i++;
            arg_case_begin(str[i], ap, j);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
    free(to_print);
    return (0);
}