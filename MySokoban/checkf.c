/*
** EPITECH PROJECT, 2018
** checkf
** File description:
** math
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
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

int my_strlen(var_t *var)
{
    int rng = 0;

    while (rng != var->size) {
        rng++;
    }
    return (rng);
}

void find_longer(pos_t *pos, var_t *var)
{
    int i = 0;
    int j = 0;

    var->longer = 0;
    while (i < my_strlen(var)) {
        if (var->buffer[i] != '\n') {
            j++;
            i++;
        }
        check_longer_line(var, &i, &j);
    }
}

void check_longer_line(var_t *var, int *i, int *j)
{
    if (var->buffer[*i] == '\n') {
        if (*j > var->longer)
            var->longer = *j;
        *j = 0;
        *i = *i + 1;
    }
}
