/*
** EPITECH PROJECT, 2019
** parser_tool
** File description:
** tetsris
*/

#include "tetris.h"
#include "proto.h"

int get_tetriminos_info(struct dirent *info, block_t *block)
{
    size_t size = 0;
    char *tmp = NULL;
    int fd = open(stradd("tetriminos/", block->file_name), O_RDONLY);

    if (fd == -1) {
        block->check = -2;
        return (84);
    }
    tmp = get_next_line(fd);
    if (tmp == NULL) {
        block->check = -1;
        return (0);
    }
    get_block_size(tmp, block);
    if (block->check == 0) {
        get_block_form(fd, block);
        verify_form(block);
    }
    free(tmp);
    return (0);
}

char *get_name(char *str, block_t *block)
{
    int where = 0;
    int size = my_strlen(str) - 1;
    char *name;

    for (where = size; str[where] != '.' && str[where] != '\0'; where--);
    if (my_strcmp(".tetrimino", str + where) == 1) {
        block->check = -2;
        return (NULL);
    }
    name = malloc(sizeof(char) * (where + 1));
    for (int i = 0; i < where; i++)
        name[i] = str[i];
    name[where] = '\0';
    if (where == 0) {
        block->check = -2;
        return (NULL);
    }
    return (name);
}

void init_block(block_t *block, struct dirent *info)
{
    block->color = 0;
    block->file_name = NULL;
    block->form = NULL;
    block->height = 0;
    block->name = NULL;
    block->next = NULL;
    block->width = 0;
    block->check = 0;
}

int add_block(struct dirent *info, data_t *data)
{
    block_t *block = malloc(sizeof(block_t));

    init_block(block, info);
    block->file_name = my_strcpy(info->d_name);
    block->name = get_name(info->d_name, block);
    if (block->check == -2)
        return (84);
    get_tetriminos_info(info, block);
    if (data->first_block == NULL)
        data->first_block = block;
    if (data->last_block != NULL)
        data->last_block->next = block;
    data->last_block = block;
    data->size += 1;
    return (0);
}
