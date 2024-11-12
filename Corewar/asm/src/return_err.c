/*
** EPITECH PROJECT, 2019
** return_err.c
** File description:
** Print the error in the error canal and return 84.
*/

#include "asm.h"

int return_err(char * const str)
{
    write(2, str, my_strlen(str));
    return (84);
}