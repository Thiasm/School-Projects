/*
** EPITECH PROJECT, 2019
** read_map
** File description:
** runner
*/

#include "my.h"

int create_map(int argc, char **argv, map_t *map)
{
    map->fp = fopen(argv[1], "r");
    if (map->fp == NULL)
        return (84);
    read_map(map->fp, map);
    parse_map(map);
    return (0);
}

void read_map(FILE *fp, map_t *map)
{
    size_t o = 2;
    int line_size = 0;
    char *tmp = malloc(sizeof(char) * 500);

    map->map = malloc(sizeof(char *) * 3);
    for (int x = 0; x < 3; x++) {
        line_size = getline(&tmp, &o, fp);
        map->map[x] = malloc(sizeof(char) * line_size);
        map->map[x] = tmp;
        tmp = malloc(sizeof(char) * 500);
    }
    free(tmp);
}

void parse_map(map_t *map)
{
    map->nb = 0;

    map->block_x = malloc(sizeof(int) * 999);
    for (int x = 0; map->map[1][x]; x++) {
        if (map->map[1][x] == '1') {
            map->block_x[map->nb] = (x * 200) + 1000;
            map->nb++;
        }
    }
}
