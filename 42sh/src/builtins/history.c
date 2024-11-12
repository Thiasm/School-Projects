/*
** EPITECH PROJECT, 2019
** history
** File description:
** 42sh
*/

#include "minishell.h"
#include <time.h>

int check_file(void)
{
    FILE *fd;
    char *home = getenv("HOME");
    char *path = NULL;

    if (home == NULL || !is_directory(home))
        return 0;
    path = my_strjoin(home, "/.historic.txt");
    fd = fopen(path, "r");
    if (fd == NULL) {
        fd = fopen(path, "a");
        fclose(fd);
    }
    return 0;
}

char *get_command_time(void)
{
    time_t rawtime;
    struct tm *info;
    char *the_time = NULL;

    time(&rawtime);
    info = localtime(&rawtime);
    the_time = my_strjoin(my_itoc(info->tm_hour), ":");
    the_time = my_strjoin(the_time, my_itoc(info->tm_min));
    the_time = my_strjoin(the_time, "   ");
    return (the_time);
}

char *find_historic_pos(void)
{
    int pos = 1;
    FILE *fd;
    char *ret = NULL;
    char *str = NULL;
    size_t size = 0;
    char *home = getenv("HOME");

    if (home == NULL)
        return NULL;
    fd = fopen(my_strjoin(home, "/.historic.txt"), "r");
    if (fd == NULL)
        return NULL;
    while (getline(&str, &size, fd) != -1)
        pos += 1;
    fclose(fd);
    ret = my_itoc(pos);
    ret = my_strjoin(ret, "  ");
    return ret;
}

void add_to_history(char *cmd)
{
    FILE *fd;
    char *command_time = get_command_time();
    char *pos_nb = find_historic_pos();
    char *line = NULL;
    char *home = getenv("HOME");

    if (command_time == NULL || pos_nb == NULL || home == NULL)
        return;
    fd = fopen(my_strjoin(home, "/.historic.txt"), "a");
    if (fd == NULL)
        return;
    line = my_strdup(pos_nb);
    line = my_strjoin(line, command_time);
    line = my_strjoin(line, cmd);
    line = my_strjoin(line, "\n");
    fwrite(line, 1, strlen(line), fd);
    fclose(fd);
    free(command_time);
    free(pos_nb);
    free(line);
}

void history(char **av)
{
    (void)av;
    FILE *fd;
    char *str = NULL;
    size_t size = 0;
    char *home = getenv("HOME");
    char *path = NULL;

    if (home == NULL)
        return;
    path = my_strjoin(home, "/.historic.txt");
    fd = fopen(path, "r");
    while (getline(&str, &size, fd) != -1)
        printf("   %s", str);
    fclose(fd);
}
