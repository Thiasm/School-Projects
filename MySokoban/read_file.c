/*
** EPITECH PROJECT, 2018
** read_file
** File description:
** sokoban
*/

#include "my.h"

void get_size(char *filepath, var_t *var)
{
    char *buffer;
    struct stat map;

    stat(filepath, &map);
    var->size = map.st_size;
}

void *load_map(char *filepath, var_t *var)
{
    int fd;

    var->buffer = malloc(sizeof(char) * var->size);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    read(fd, var->buffer, var->size);
    close(fd);
    if (var->buffer[0] =='\0')
        exit(84);
}

int my_strcmp(char *str1)
{
    if (str1[0] == '-' && str1[1] == 'h') {
        my_putstr("USAGE\n    ./my_sokoban map\nDESCRIPTION\n\
    map file representing the warehouse map,\
containing ‘#’ for walls,\n        ‘P’ for the player, ‘X’\
for boxes and ‘O’ for storage locations.\n");
        exit(0);
    }
}

void free_tab(var_t *var, pos_t *pos)
{
    for (int y = 0; y < var->lines; y++)
        free(var->map[y]);
    for (int i = 0; i < pos->y_o; i++)
        free(pos->tab_pos_o[i]);
}
