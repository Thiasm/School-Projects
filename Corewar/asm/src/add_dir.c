/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** add_dir.c
*/

#include "asm.h"
#include "protos.h"
#include "op.h"

char *add_size(char *byte, char param_size, idx_t *idx)
{
    byte[idx->i] = param_size;
    (idx->i)++;
    byte[idx->i] = '\0';
    return byte;
}

int count_lines(char **tab)
{
    int lines = 0;

    while (tab[lines] != NULL)
        lines++;
    return lines;
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char buff = '\0';

    while (i < len) {
        buff = str[i];
        str[i] = str[len];
        str[len] = buff;
        i++;
        len--;
    }
    return (str);
}

char *convert_hex(int nb)
{
    char *result;
    char *basis = "0123456789abcdef";
    int rank = 0;
    int i = 0;
    int len = 0;
    int nb_len = nb;

    while (nb_len > 0) {
        nb_len = nb_len / 10;
        len++;
    }
    result = malloc(sizeof(char) * (len + 1));
    while (nb > 0) {
        rank = nb % 16;
        nb = nb / 16;
        result[i] = basis[rank];
        i++;
    }
    result[i] = '\0';
    result = my_revstr(result);
    return result;
}

char *add_dir(char *byte, char *line, idx_t *idx)
{
    int nb = my_natoi(line);
    char *hex = convert_hex(nb);
    int i = 0;
    int len = my_strlen(hex);
    int size[4] = {4, 3, 2, 1};

    if (len > 4)
        return byte;
    for (; i < size[len - 1] - 1; i++) {
        byte = realloc(byte, sizeof(char) * (idx->i + 2));
        byte[idx->i] = 0;
        idx->i++;
        byte[idx->i] = '\0';
    }
    byte = realloc(byte, sizeof(char) * (idx->i + 2));
    byte[idx->i] = nb;
    idx->i++;
    byte[idx->i] = '\0';
    free(hex);
    return byte;
}