/*
** EPITECH PROJECT, 2018
** Corewar
** File description:
** corewar.h
*/

#ifndef ASM_H_
#define ASM_H_

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

struct file_s
{
    char *name;
    header_t hd;
};

typedef struct file_s file_t;

struct idx_s
{
    int i;
    int line;
};

typedef struct idx_s idx_t;

#endif /* ASM */