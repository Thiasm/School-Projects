/*
** EPITECH PROJECT, 2019
** tetris
** File description:
** get_file functions that take a fd and transform it in to char tab
*/

#include <stdlib.h>
#include <fcntl.h>
int my_strlen(char *);
char *get_next_line(int);

int get_size(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        i++;
    }
    return (i + 1);
}

char *my_strdup(char *tmp)
{
    char *str = malloc(sizeof(char) * (my_strlen(tmp) + 1));
    int i = 0;

    while (tmp[i] != '\0') {
        str[i] = tmp[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char **my_realloc(char **tab, char *str)
{
    int a = get_size(tab);
    char **tmp = malloc(sizeof(char *) * (a + 1));
    int i = 0;

    while (tab[i] != NULL) {
        tmp[i] = my_strdup(tab[i]);
        i++;
    }
    tmp[i] = my_strdup(str);
    tmp[i + 1] = NULL;
    free (tab);
    return (tmp);
}

char **get_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *str;
    char **tab = malloc(sizeof(char *) * 2);

    tab[0] = get_next_line(fd);
    tab[1] = NULL;
    while ((str = get_next_line(fd)) != NULL) {
        tab = my_realloc(tab, str);
    }
    free(str);
    return (tab);
}