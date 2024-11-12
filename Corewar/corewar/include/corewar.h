/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "op.h"

static const char extension[] = ".cor";
static const char USAGE_STR[] = "./corewar [-dump nbr_cycle] "
    "[[-n prog_number] [-a load_adress] prog_name] ...\n";
static const char HELP_STR[] = "\nDESCRIPTION\n\t-dump nbr_cycle\t"
    "dumps the memory after the nbr_cycle execution (if the round isn't "
    "already over) with the following format: 32 bytes/line in hexadecimal "
    "(A0BCDEFE1DD3...)\n\t-n prog_number\tsets the next program's number.\t"
    "By default, the first free number in the parameter order\n\t"
    "-a load-address\tsets the next program's loading address. "
    "When no address is specified, optimize the addresses so that the "
    "processes are as far away from each other as possible. "
    "The addresses are MEM_SIZE modulo\n";

static const int CHAMP_MIN = 1;
static const int CHAMP_MAX = 4;

struct chmp_info_s
{
    char name[PROG_NAME_LENGTH + 1];
    char comment[COMMENT_LENGTH + 1];
    int prog_nbr;
    int load_add;
    int prog_size;
};

typedef struct chmp_info_s chmp_info_t;

struct champ_s
{
    bool carry;
    bool alive;
    int pc;
    int reg[REG_NUMBER];
};

typedef struct champ_s champ_t;

struct arena_s
{
    unsigned char arena[MEM_SIZE];
    int champ_nbr;
    int dump;
    int cycle_dump;
    int cycle_die;
    int cycle;
};

typedef struct arena_s arena_t;

struct vm_s
{
    chmp_info_t *infos;
    champ_t *chmps;
    arena_t arena;
};

typedef struct vm_s vm_t;

#endif /* COREWAR_H_ */