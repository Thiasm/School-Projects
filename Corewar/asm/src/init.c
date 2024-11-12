/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** init.c
*/

#include "asm.h"
#include "protos.h"

bool is_champion(char *name)
{
    int i = -1;

    if (!count_researched(name, '.'))
        return false;
    for (i = my_strlen(name); i != 0 && name[i] != '.'; i--);
    if (my_strncmp(name + i, ".s\0", 3))
        return false;
    return true;
}

bool get_chmp_name(char **name, char *filepath)
{
    int i;

    for (i = my_strlen(filepath); i != 0 && filepath[i] != '/'; i--);
    if (filepath[i] == '/')
        i++;
    *name = my_strnew(my_strlen(filepath) + my_strlen(extension) + 1);
    *name = my_strncat(*name, &filepath[i], my_strlen(&filepath[i]) - 2);
    *name = my_strcat(*name, extension);
    return true;
}

bool init_file(file_t *file, char *filepath)
{
    if (is_champion(filepath) == false)
        return exit_prog(0, "error: not a .s file.");
    if (get_chmp_name(&file->name, filepath) == false)
        return false;
    for (int i = 0; i != PROG_NAME_LENGTH; i++)
        file->hd.prog_name[i] = '\0';
    for (int i = 0; i != COMMENT_LENGTH + 4; i++)
        file->hd.comment[i] = '\0';
    for (int i = 0; i != 4; i++)
        file->hd.prog_name[i] = EXEC_MAGIC_CHR[i];
    file->hd.prog_size = 0;
    return true;
}
