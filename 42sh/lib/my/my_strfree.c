/*
** EPITECH PROJECT, 2018
** PSU_minishell_2018
** File description:
** my_strfree.c
*/

#include <unistd.h>
#include <stdlib.h>

void my_strfree(char **str)
{
    if (*str) {
        free(*str);
        *str = NULL;
    }
}