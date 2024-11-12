/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** file_verifications
*/

#include "rpg.h"
#include <sys/stat.h>
#include <stdbool.h>

static bool check_file(char *filepath)
{
    struct stat buffer;
    int exist = 0;

    exist = stat(filepath, &buffer);
    if (exist == false && buffer.st_size > 0)
        return (true);
    return (false);
}

static bool check_every_file(void)
{
    int fd = 0;
    char *str = NULL;
    int abort = 0;

    fd = open(".file_list.txt", O_RDONLY);
    str = get_next_line(fd);
    while (str) {
        if (str[0] != '#' && str[0] != ' ')
            if (check_file(str) == false) {
                my_printf("File %s not found\n", str);
                abort = 1;
            }
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    if (abort == 1)
        return (false);
    return (true);
}

static bool check_file_list(void)
{
    struct stat buffer;
    int exist = 0;

    exist = stat(".file_list.txt", &buffer);
    if (exist == false)
        return (true);
    return (false);
}

bool verify_all_files(void)
{
    if (check_file_list() == false) {
        my_printf("File 'file_list' not found");
        return (false);
    }
    if (check_every_file() == false)
        return (false);
    return (true);
}
