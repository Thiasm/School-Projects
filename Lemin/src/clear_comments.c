/*
** EPITECH PROJECT, 2019
** clean_comments
** File description:
** Remove all comments in the char **file.
*/

#include "../include/my.h"
#include <string.h>

char *clear_space(char *new_line, char *line, int x)
{
    for (; line[x - 1] == ' '; x--)
        new_line[x - 1] = '\0';
    return (new_line);
}

char *verify_comment_and_cpy_line(char *new_line, char *line, int i)
{
    int x = 0;

    if (line[0] == '#' && line[1] != '#')
        return (NULL);
    for (x = 0; line[x] != '\0'; x++) {
        if (line[x] == '#' && line[x + 1] != '#' && line[x - 1] != '#') {
            new_line[x] = '\0';
            new_line = clear_space(new_line, line, x);
            return (new_line);
        }
        if (line[x] == '\n') {
            new_line[x] = '\0';
            return (new_line);
        }
        new_line[x] = line[x];
    }
    new_line[x] = '\0';
    return (new_line);
}

char **clear_comment(char **file)
{
    int y = 0;
    int i = 0;
    char **new_file;

    for (y = 0; file[y] != NULL; y++);
    new_file = malloc(sizeof(char *) * (y + 1));
    for (y = 0; file[y] != NULL; y++) {
        new_file[i] = malloc(sizeof(char) * (my_strlen(file[y]) + 1));
        new_file[i] = verify_comment_and_cpy_line(new_file[i], file[y], i);
        if (new_file[i] != NULL)
            i++;
        else
            free(new_file[i]);
    }
    new_file[i] = NULL;
    for (int i = 0; file[i] != NULL; i++)
        free(file[i]);
    free(file);
    return (new_file);
}
