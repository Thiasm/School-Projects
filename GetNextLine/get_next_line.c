/*
** EPITECH PROJECT, 2018
** getnextline.c
** File description:
** getnextline
*/

#include "get_next_line.h"

char *check_read(int fd)
{
    char *new;
    int i = 0;

    if (tmp) {
        for (int j = 0; tmp[j]; j++) {
            if (tmp[j] == '\n')
                return (resize_tmp(new));
            rest[j] = tmp[j];
        }
    }
    new = malloc(sizeof(char) * (READ_SIZE));
    read (fd, new, READ_SIZE);
    for (int i = 0; i < READ_SIZE; i++)
        if (new[i] == '\n' || new[i] == '\0')
            return (create_tmp(new, i));
    stock_rest(new, i);
    check_read(fd);
}

char *stock_rest(char *new, int i)
{
    while (rest[i])
        i++;
    for (int j = 0; j < READ_SIZE; j++) {
        rest[i] = new[j];
        i++;
    }
}

char *create_tmp(char *new, int i)
{
    int o = 0;
    int p = 0;

    i++;
    tmp = malloc(sizeof(char) * READ_SIZE - i);
    while (new[i] != '\0') {
        tmp[o] = new[i];
        i++;
        o++;
    }
    while (rest[p])
        p++;
    for (int j = 0; new[j] != '\n'; j++) {
        if (new[j] == '\0')
            return (rest);
        rest[p] = new[j];
        p++;
    }
    rest[p] = '\0';
    return (rest);
}

char *resize_tmp(char *new)
{
    int i = 0;
    int j = 0;
    char *str;

    while (tmp[i] != '\n')
        i++;
    i++;
    while (tmp[i + j] != '\0')
        j++;
    str = malloc(sizeof(char) * j);
    for (int o = 0; tmp[i]; i++) {
        str[o] = tmp[i];
        o++;
    }
    tmp = malloc(sizeof(char) * j);
    for (int o = 0; str[o]; o++)
        tmp[o] = str[o];
    return (rest);
}

char *get_next_line(int fd)
{
    char *content;

    if (fd == -1)
        return (NULL);
    if (READ_SIZE < 1 || READ_SIZE > 12000000000)
        return (NULL);
    rest = malloc(sizeof(char) * 99999);
    return (check_read(fd));
}

int main(int argc, char **argv)
{
    int fd;
    
    fd = open(argv[1], O_RDONLY);
    printf("%s|", get_next_line(fd));
    return (0);
}
