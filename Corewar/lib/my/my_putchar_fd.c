/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** ft_putchar_fd.c
*/

#include "my.h"

void my_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
