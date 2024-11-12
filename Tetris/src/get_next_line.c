/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** returns the next line in a file
*/

#include "tetris.h"
#include "proto.h"

idx_t stop_read(idx_t index, char *buff)
{
    while (index.i != READ_SIZE) {
        if (buff[index.i] == '\n'|| buff[index.i] == '\0') {
            index.stop++;
            break;
        }
        index.i++;
    }
    return (index);
}

char *str_add_char(char *str, char *buff, idx_t *index)
{
    if (index->stop == 0) {
        for (int j = 0; j != READ_SIZE; j++) {
            str[index->k] = buff[j];
            index->k++;
        }
    }
    return (str);
}

char *loop_get_line(int fd, char *str)
{
    idx_t index = {0, 0, 0};
    char *buff = malloc(sizeof(char) * READ_SIZE);

    while (index.stop == 0) {
        index.i = 0;
        if (read(fd, buff, READ_SIZE) <= 0)
            return (NULL);
        index = stop_read(index, buff);
        str = str_add_char(str, buff, &index);
    }
    free(buff);
    return (str);
}

char *get_next_line(int fd)
{
    char *str = malloc(sizeof(char) * 10000);

    for (int i = 0; i != 10000; i++)
        str[i] = '\0';
    if (str == NULL) {
        free(str);
        return (NULL);
    }
    if (fd < 0 || READ_SIZE <= 0) {
        free(str);
        return (NULL);
    }
    str = loop_get_line(fd, str);
    return (str);
}

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = NULL;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}