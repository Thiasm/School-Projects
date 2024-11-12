/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** init.c
*/

#include "corewar.h"
#include "protos.h"

void init_reg_pc(vm_t *vm, int pos)
{
    vm->chmps[pos].pc = vm->infos[pos].load_add;
    vm->chmps[pos].reg[0] = vm->infos[pos].prog_nbr;
    for (int i = 1; i < REG_NUMBER; i++) {
        vm->chmps[pos].reg[i] = 0;
        vm->chmps[pos].alive = true;
    }
}

int init_args(vm_t *vm, char **av, int ac, int *i)
{
    if (load_dump(&vm->arena, av, i))
        return 84;
    for (vm->arena.champ_nbr = 0; *i < ac; *i += 1, vm->arena.champ_nbr++) {
        if (vm->arena.champ_nbr > 3)
            return exit_prog(84, "error: too many champions.");
        if (load_add(vm->infos, av, i))
            return 84;
        if (load_prog_nbr(vm->infos, av, i))
            return 84;
        if (is_champion(av[*i]) == false)
            return exit_prog(84, "error: not a champion.");
    }
    if (vm->arena.champ_nbr < CHAMP_MIN)
        return exit_prog(84, "error: not enough champion.");
    if (vm->arena.champ_nbr > CHAMP_MAX)
        return exit_prog(84, "error: too many champions.");
    return 0;
}

int init_vm(vm_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++)
        vm->arena.arena[i] = 0;
    if ((vm->infos = malloc(5 * sizeof(chmp_info_t))) == NULL)
        return exit_prog(84, "error: cannot malloc champ infos.");
    vm->infos[4].prog_nbr = -1;
    vm->arena.champ_nbr = 0;
    vm->arena.cycle = 0;
    vm->arena.cycle_die = 0;
    vm->arena.cycle_dump = 0;
    return 0;
}
