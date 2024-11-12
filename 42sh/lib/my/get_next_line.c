/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line.c
*/

#include "my.h"

char *ft_realloc(char *dest, int len)
{
    int i = 0;
    char *new;

    for (i = 0; dest[i] != '\0'; i++);
    if ((new = malloc(sizeof(*new) * (i + len))) == NULL)
        return (NULL);
    for (i = 0; dest[i] != '\0'; i++)
        new[i] = dest[i];
    free(dest);
    return (new);
}

int read_str(const int fd, char *c)
{
    static char buffer[READ_SIZE + 1];
    static int len = READ_SIZE;
    static int i = 0;

    if (i >= len || i == 0) {
        i = 0;
        len = read(fd, buffer, READ_SIZE);
    }
    buffer[len + 1] = '\0';
    if (len == 0) {
        *c = '\0';
        i -= 1;
    } else if (buffer[i] == '\n')
        *c = '\0';
    else
        *c = buffer[i];
    i += 1;
    return (len);
}

char *get_next_line(const int fd)
{
    char *next_line;
    int len = 0;
    int i = 0;

    if ((next_line = malloc((READ_SIZE + 1) * sizeof(*next_line))) == NULL)
        return (NULL);
    if ((len = read_str(fd, &next_line[i])) <= 0) {
        free(next_line);
        return (NULL);
    }
    next_line[i + 1] = '\0';
    while (next_line[i] != '\0') {
        if (i % READ_SIZE == 0)
            next_line = ft_realloc(next_line, i + READ_SIZE + 1);
        if ((len = read_str(fd, &next_line[++i])) <= 0)
            return (NULL);
        next_line[i + 1] = '\0';
    }
    next_line[i] = '\0';
    return (next_line);
}
