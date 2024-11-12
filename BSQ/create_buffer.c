/*
** EPITECH PROJECT, 2018
** create_buffer
** File description:
** BSQ
*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

struct var_replace
{
    int i;
    int j;
};

typedef struct var_replace var_replace_t;

int get_size(char *filepath)
{
    char *buffer;
    struct stat map;

    stat(filepath, &map);
    buffer = malloc(sizeof(map.st_size));
    return (map.st_size);
}

void replace_char(int **tab_int, char *final, int final_i, var_replace_t *v)
{
    if (tab_int[v->i][v->j] < 0)
        final[final_i] = 'x';
    if (tab_int[v->i][v->j] == 0)
        final[final_i] = 'o';
    if (tab_int[v->i][v->j] > 0)
        final[final_i] = '.';
}

void create_final(int **tab_int, int *nb_rows, int *nb_cols, char *final)
{
    int final_i = 0;
    var_replace_t v;

    for (v.i = 0; v.i < *nb_rows; v.i++) {
        for (v.j = 0; v.j < *nb_cols; v.j++) {
            replace_char(tab_int, final, final_i, &v);
            final_i++;
        }
        final[final_i] = '\n';
        final_i++;
    }
    final[final_i] = '\0';
}
