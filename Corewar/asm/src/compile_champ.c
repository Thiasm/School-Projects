/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** compile_champ.c
*/

#include "asm.h"
#include "protos.h"

void prog_failled(file_t *file)
{
    int fd;

    if ((fd = open(file->name, O_WRONLY | O_CREAT, 0666)) < 0)
        write(2, "error: OH NO.\n", 14);
    write(fd, &file->hd.prog_name, PROG_NAME_LENGTH);
    for (int i = 0; i < (12 - my_nbrlen(file->hd.prog_size / 16)); i++)
        my_putchar_fd(0, fd);
    write(fd, &file->hd.prog_size, my_nbrlen(file->hd.prog_size / 16));
    write(fd, &file->hd.comment, COMMENT_LENGTH);
}

void asm_champ(file_t *file, char **tab)
{
    int fd;
    char *byte = NULL;
    idx_t idx = {0, 0};

    if (tab == NULL)
        return prog_failled(file);
    while (idx.line < count_lines(tab) - 1)
        byte = asm_to_byte(tab, byte, &idx);
    file->hd.prog_size = idx.i;
    if ((fd = open(file->name, O_WRONLY | O_CREAT, 0666)) < 0)
        write(2, "error: OH NO.\n", 14);
    write(fd, &file->hd.prog_name, PROG_NAME_LENGTH);
    for (int i = 0; i < (12 - my_nbrlen(file->hd.prog_size / 16)); i++)
        my_putchar_fd(0, fd);
    write(fd, &file->hd.prog_size, my_nbrlen(file->hd.prog_size / 16));
    write(fd, &file->hd.comment, COMMENT_LENGTH + 4);
    write(fd, byte, idx.i);
    close(fd);
    free(byte);
}
