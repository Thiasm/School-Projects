/*
** EPITECH PROJECT, 2019
** free_all
** File description:
** tetris
*/

#include "tetris.h"
#include "proto.h"

static void free_form(block_t *block)
{
    if (block->form != NULL) {
        for (int i = 0; block->form[i] != NULL; i++)
            free(block->form[i]);
        free(block->form);
    }
}

void free_info(char **info)
{
    for (int i = 0; info[i] != NULL; i++)
        free(info[i]);
    free(info);
}

void free_all(data_t *data)
{
    block_t *block = data->first_block;

    if (block == NULL)
        return;
    while (block->next != NULL) {
        free_form(block);
        free(block->name);
        free(block->file_name);
        data->first_block = block->next;
        free(block);
        block = data->first_block;
    }
    free(block);
}
