/*
** EPITECH PROJECT, 2019
** CPE_corewar_2018
** File description:
** asm_to_byte.c
*/

#include "asm.h"
#include "protos.h"
#include "op.h"

char get_params_size(char **tab, int j, idx_t *idx)
{
    int nb_param = op_tab[j].nbr_args;
    char size[9] = "22222222";
    char param_size = '\0';
    int k = 0;

    for (int i = 1; i != nb_param + 1; i++) {
        if (tab[(idx->line) + i][0] == 'r') {
            size[k] = '0';
            size[k + 1] = '1';
        } else if (tab[(idx->line) + i][0] == '%') {
            size[k] = '1';
            size[k + 1] = '0';
        } else {
            size[k] = '1';
            size[k + 1] = '1';
        }
        k += 2;
    }
    fill_with_zeros(size);
    param_size = put_in_dec(param_size, size);
    return param_size;
}

char *add_instruct(char *byte, idx_t *idx, char hex)
{
    if (byte)
        byte = realloc(byte, sizeof(char) * (idx->i + 2));
    else
        byte = malloc(sizeof(char) * 2);
    byte[idx->i] = hex;
    (idx->i)++;
    byte[idx->i] = '\0';
    return byte;
}

char *add_register(char *byte, char *line, idx_t *idx)
{
    int len = 0;
    char *nb = NULL;
    int j = 0;
    int nbr = 0;
    char c;

    len = my_strlen(line);
    nb = malloc(sizeof(char) * len);
    for (int i = 1; line[i] != '\0'; i++) {
        nb[j] = line[i];
        j++;
    }
    nb[j] = '\0';
    nbr = my_atoi(nb);
    c = nbr;
    free(nb);
    byte = realloc(byte, sizeof(char) * (idx->i + 2));
    byte[idx->i] = c;
    (idx->i)++;
    byte[idx->i] = '\0';
    return byte;
}

char *add_params(char *byte, char *line, idx_t *idx)
{
    if (line[0] == 'r')
        byte = add_register(byte, line, idx);
    else if (line[0] == '%' && line[1] != ':' && line[2] != '-')
        byte = add_dir(byte, line, idx);
    return byte;
}

char *asm_to_byte(char **tab, char *byte, idx_t *idx)
{
    int j = 0;
    char hex;
    char param_size;

    for (; op_tab[j].nbr_cycles != 0; j++) {
        if (my_strcmp(op_tab[j].mnemonique, tab[idx->line]) == 0)
            break;
    }
    if (j == 15) {
        idx->line++;
        return byte;
    }
    hex = op_tab[j].code;
    byte = add_instruct(byte, idx, hex);
    param_size = get_params_size(tab, j, idx);
    byte = realloc(byte, sizeof(char) * (idx->i + 2));
    byte = add_size(byte, param_size, idx);
    for (int i = 1; i != op_tab[j].nbr_args + 1; i++)
        byte = add_params(byte, tab[(idx->line) + i], idx);
    idx->line += op_tab[j].nbr_args + 1;
    return byte;
}