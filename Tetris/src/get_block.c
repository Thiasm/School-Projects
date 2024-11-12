/*
** EPITECH PROJECT, 2019
** get_block
** File description:
** tetris
*/

#include "tetris.h"
#include "proto.h"

int get_block_form(int fd, block_t *block)
{
    int line = 0;

    block->form = malloc(sizeof(char *) * (block->height + 1));
    block->form[line] = get_next_line(fd);
    while (block->form[line] != NULL) {
        line += 1;
        block->form[line] = get_next_line(fd);
    }
    if (block->form[0] == NULL)
        block->check = -1;
    return (0);
}

int get_block_size(char *str, block_t *block)
{
    int i = 0;

    block->width = get_width(str, &i);
    i++;
    block->height = get_height(str, &i);
    i++;
    block->color = get_color(str, &i);
    if (block->width == -1 || block->height == -1 ||
        (block->color < 1 || block->color > 7))
        block->check = -1;
    return (0);
}

int get_width(char *str, int *i)
{
    char *width = malloc(sizeof(char) * 5);
    int j = 0;

    while (str[*i] != ' ') {
        if (str[*i] == '\0')
            return (-1);
        width[j] = str[*i];
        j += 1;
        *i += 1;
    }
    width[j] = '\0';
    return (my_atoi(width));
}

int get_height(char *str, int *i)
{
    char *height = malloc(sizeof(char) * 5);
    int j = 0;

    while (str[*i] != ' ') {
        if (str[*i] == '\0')
            return (-1);
        height[j] = str[*i];
        j += 1;
        *i += 1;
    }
    height[j] = '\0';
    return (my_atoi(height));
}

int get_color(char *str, int *i)
{
    char *color = malloc(sizeof(char) * 5);
    int j = 0;

    while (str[*i] != '\0') {
        color[j] = str[*i];
        j += 1;
        *i += 1;
    }
    color[j] = '\0';
    return (my_atoi(color));
}
