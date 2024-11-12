/*
** EPITECH PROJECT, 2018
** lib_my
** File description:
** ft_putstr_fd.c
*/

#include "my.h"

void my_putstr_fd(char const *s, int fd)
{
    write(fd, s, my_strlen(s));
}
