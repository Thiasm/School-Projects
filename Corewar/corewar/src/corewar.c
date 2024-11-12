/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** corewar.c
*/

#include "corewar.h"
#include "protos.h"

void main_loop(vm_t *vm)
{
    while (vm->arena.champ_nbr) {
        for (int i = 0; i < vm->arena.champ_nbr; i++) {
        }
        check_cycles(vm);
    }
}

void launch_vm(vm_t *vm)
{
    my_printf("RUNNIG...\n");
    for (int i = 0; i < vm->arena.champ_nbr; i++) {
        init_reg_pc(vm, i);
        my_printf("Champ %d: %s; add: %d.\n", vm->infos[i].prog_nbr,
            vm->infos[i].name, vm->infos[i].load_add);
    }
    main_loop(vm);
}

int corewar(char **av, int ac)
{
    vm_t vm;
    int i = 1;

    if (init_vm(&vm))
        return 84;
    if (init_args(&vm, av, ac, &i))
        return 84;
    if (!init_champs(&vm, av))
        return 84;
    launch_vm(&vm);
    return 0;
}