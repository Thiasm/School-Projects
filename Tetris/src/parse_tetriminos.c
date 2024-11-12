/*
** EPITECH PROJECT, 2019
** parser
** File description:
** tetris
*/

#include "tetris.h"
#include "proto.h"

DIR *open_tetriminos(data_t *data)
{
    DIR *dir;

    if ((dir = opendir("./tetriminos")) == NULL) {
        write(2, "Can't open repository\n", 22);
        exit(84);
    }
    return (dir);
}

void init_tetriminos(data_t *data)
{
    data->size = 0;
    data->level = 1;
    data->first_block = NULL;
    data->last_block = NULL;
}

void parse_tetriminos(data_t *data)
{
    DIR *dir = open_tetriminos(data);
    struct dirent *info;

    init_tetriminos(data);
    while ((info = readdir(dir))) {
        if (add_block(info, data) == 84)
            continue;
    }
}
