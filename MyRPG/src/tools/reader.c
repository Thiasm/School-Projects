/*
** EPITECH PROJECT, 2019
** reader.c
** File description:
** read the file
*/

#include "rpg.h"

void read_monster(world_t *world)
{
    int fd = open(".monster.txt", O_RDONLY);
    info_t *info = malloc(sizeof(info_t));

    world->next_i = info;
    for (int b = 0; b < 11; b++) {
        info->name = get_next_line(fd);
        info->pv = my_getnbr(get_next_line(fd));
        info->deg = my_getnbr(get_next_line(fd));
        info->xp = my_getnbr(get_next_line(fd));
        get_next_line(fd);
        if (b != 10){
            info->next = malloc(sizeof(info_t));
            info = info->next;
        }
    }
    info->next = NULL;
    close (fd);
}

void read_pnj(world_t *world)
{
    int fd = open(".pnj.txt", O_RDONLY);
    pnj_t *pnj = malloc(sizeof(pnj_t));

    world->next_p = pnj;
    for (int b = 0; b < 14; b++) {
        pnj->name = get_next_line(fd);
        pnj->x = my_getnbr(get_next_line(fd));
        pnj->y = my_getnbr(get_next_line(fd));
        pnj->text_a = get_next_line(fd);
        pnj->text_b = get_next_line(fd);
        pnj->meet = 0;
        get_next_line(fd);
        if (b != 13) {
            pnj->next = malloc(sizeof(pnj_t));
            pnj = pnj->next;
        }
    }
    pnj->next = NULL;
    close (fd);
}

void map_binary(general_t *general)
{
    int fd = open(".block.txt", O_RDONLY);
    char buffer[15150];
    int **array;
    int k = 0;
    int a = 0;

    read(fd, buffer, 15150);
    array = malloc(sizeof(int *) * 101);
    for (int b = 0; b != 101; b++)
        array[b] = malloc(sizeof(int) * 150);
    for (int t = 0; t < 15149; t++) {
        if (buffer[t] == '\n') {
            k++;
            a = 0;
        } else {
            array[k][a] = buffer[t] - 48;
            a++;
        }
    }
    general->array = array;
    close(fd);
}
