/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** cycles.c
*/

#include "corewar.h"

void champs_alive(vm_t *vm)
{
    int alives = 0;

    for (int i = 0; vm->chmps[i].pc != -1; i++) {
        alives += vm->chmps[i].alive;
        vm->chmps[i].alive = false;
    }
    vm->arena.champ_nbr = alives;
    vm->arena.cycle_die = 0;
}

void display_arena(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (vm->arena.arena[i] < 16)
            my_printf("0");
        if (vm->arena.arena[i] == 0) {
            my_printf("0 ");
            if (i != 0 && (i + 1) % 32 == 0)
                my_printf("\n");
            continue;
        }
        my_printf("%X ", vm->arena.arena[i]);
        if (i != 0 && (i + 1) % 32 == 0)
            my_printf("\n");
    }
    my_printf("\n");
}

void check_cycles(vm_t *vm)
{
    if (vm->arena.cycle_die == CYCLE_TO_DIE) {
        champs_alive(vm);
    }
    if (vm->arena.cycle_dump == vm->arena.dump)
        display_arena(vm);
    vm->arena.cycle_dump++;
    vm->arena.cycle_die++;
}