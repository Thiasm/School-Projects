/*
** EPITECH PROJECT, 2019
** reverse_int.c
** File description:
** Reverse a int bytecode.
*/

#include "my.h"

int rev_int(int nbr)
{
    int oct_a = nbr & 0xFF;
    int oct_b = (nbr >> 8) & 0xFF;

    return (oct_a * 256 + oct_b);
}