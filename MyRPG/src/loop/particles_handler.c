/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** No description
*/

#include "rpg.h"

int my_rand(int a, int b)
{
    return rand()%(b-a) +a;
}

void sand_particles(sfVertexArray *test)
{
    int i = 0;
    int j = 0;
    int start_x = 1300;
    int start_y = 3300;
    int end_x = 2760;
    int end_y = 5000;
    sfVertex sand;

    sand.color = sfColor_fromRGB(255, 221, 0);
    sand.position.x = start_x;
    sand.position.y = start_y;
    while (i != end_y) {
        while (j != 400) {
            sand.position.x = my_rand(start_x, end_x);
            sfVertexArray_append(test, sand);
            j++;
        }
        sand.position.y = my_rand(start_y, end_y);
        j = 0;
        i++;
    }
}

void snow_particles(sfVertexArray *test)
{
    int i = 0;
    int j = 0;
    int start_x = 4000;
    int start_y = 0;
    int end_x = 5400;
    int end_y = 1800;
    sfVertex sand;

    sand.color = sfColor_fromRGB(147, 231, 251);
    sand.position.x = start_x;
    sand.position.y = start_y;
    while (i != end_y) {
        while (j != 400) {
            sand.position.x = my_rand(start_x, end_x);
            sfVertexArray_append(test, sand);
            j++;
        }
        sand.position.y = my_rand(start_y, end_y);
        j = 0;
        i++;
    }
}
