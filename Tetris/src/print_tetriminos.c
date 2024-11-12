/*
** EPITECH PROJECT, 2019
** print_tetriminos
** File description:
** tetris
*/

#include "tetris.h"
#include "proto.h"

void swap_block(block_t *first, block_t *second, data_t *data)
{
    if (first == data->first_block)
        data->first_block = second;
    first->next = second->next;
    second->next = first;
    if (data->last_block != NULL)
        data->last_block->next = second;
}

int compare(char *str1, char *str2)
{
    while (*str1 == *str2) {
        if (*str1 == '\0')
            return (*str1 - *str2);
        *str1 += 1;
        *str2 += 1;
    }
    return (*str1 - *str2);
}

void alpha_order(data_t *data)
{
    block_t *block;

    for (int i = 0; i < data->size; i++) {
        block = data->first_block;
        data->last_block = NULL;
        while (block->next != NULL) {
            if (compare(block->name, block->next->name) > 0)
                swap_block(block, block->next, data);
            data->last_block = block;
            if (block->next != NULL)
                block = block->next;
            else
                continue;
        }
    }
}

void print_loop(block_t *block, data_t *data)
{
    if (block->check == -1 || block->check == 0) {
        my_printf("Tetriminos : Name %s : ", block->name);
        if (block->check == -1)
            my_printf("Error\n");
        else if (block->check == 0) {
            my_printf("Size %d*%d : ", block->width, block->height);
            my_printf("Color %d :\n", block->color);
            for (int i = 0; block->form[i]; i++)
                    my_printf("%s\n", block->form[i]);
        }
    }
}

void print_tetriminos(data_t *data)
{
    block_t *block;

    alpha_order(data);
    block = data->first_block;
    if (block == NULL)
        exit(84);
    my_printf("Tetriminos : %d\n", data->size);
    while (block != NULL) {
        print_loop(block, data);
        block = block->next;
    }
    my_printf("Press any key to start Tetris\n");
}
