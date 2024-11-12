/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** utils_byte.c
*/

#include "asm.h"
#include "protos.h"
#include "op.h"

int my_natoi(char const *str)
{
    int nb = 0;

    for (int i = 1; str[i] != '\0'; i++)
        nb = nb * 10 + str[i] - '0';
    return (nb);
}

int my_atoi(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb = nb * 10 + str[i] - '0';
    return (nb);
}

int my_compute_power_rec(int nb, int power)
{
    if (power == 0)
        return (1);
    if (power < 0)
        return (0);
    nb = nb * my_compute_power_rec(nb, power - 1);
    return (nb);
}

char put_in_dec(char param_size, char *size)
{
    int dec = 0;
    int rank = 7;

    for (int i = 0; i != 8; i++) {
        dec += ((int)size[i] - '0') * my_compute_power_rec(2, rank);
        rank--;
    }
    param_size = dec;
    return param_size;
}

void fill_with_zeros(char *size)
{
    for (int i = 0; i != 9; i++) {
        if (size[i] == '2')
            size[i] = '0';
    }
}