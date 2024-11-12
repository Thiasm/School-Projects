/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** asm.c
*/

#include "asm.h"
#include "protos.h"

int count_researched(char *str, char researched)
{
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == researched) {
            j++;
        }
    }
    return j;
}

bool is_comment(char *line)
{
    if (!line || line[0] == '\0')
        return false;
    for (int i = 0; line[i] != '\0'; i++) {
        if (!my_isspace(line[i]))
            if (line[i] == COMMENT_CHAR)
                return false;
    }
    return true;
}

bool parse_file(FILE *fd, file_t *file)
{
    char *line = NULL;
    size_t buff_size = 1;

    for (int i = 0; getline(&line, &buff_size, fd) != -1; i++) {
        if (!is_comment(line))
            continue;
        if (!is_header(&file->hd, line))
            return free(line), false;
        if (file->hd.prog_name[4] != '\0' && file->hd.comment[0] != '\0')
            return free(line), true;
    }
    return free(line), true;
}

char **get_asm(FILE *fd, char **tab)
{
    char *line = NULL;
    char *buff = NULL;
    size_t buff_size = 1;

    if (getline(&line, &buff_size, fd) == -1)
        exit(84);
    while (getline(&buff, &buff_size, fd) != -1) {
        for (int i = 0; buff[i] != '\0'; i++)
            if (buff[i] == '#')
                buff[i] = '\0';
        line = realloc(line, my_strlen(line) + my_strlen(buff) + 1);
        line = my_strcat(line, buff);
    }
    if (line == NULL)
        return NULL;
    tab = parse_command(line);
    fclose(fd);
    return tab;
}

void handle_file(char *filepath)
{
    FILE *fd = 0;
    file_t file;
    char **tab = NULL;

    if (init_file(&file, filepath) == false)
        return;
    if (file.hd.prog_size != 0)
        return;
    if ((fd = fopen(filepath, "r")) == NULL) {
        exit_prog(0, "error: failed to open file.");
        return;
    }
    parse_file(fd, &file);
    tab = get_asm(fd, tab);
    error_handling(tab);
    if (file.hd.prog_name[4] == '\0' || file.hd.comment[0] == '\0') {
        exit_prog(0, "error: no name or comment.");
        return;
    }
    asm_champ(&file, tab);
}
