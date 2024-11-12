/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** load_champs.c
*/

#include "corewar.h"
#include "protos.h"

bool load_prog(vm_t *vm, int fd, int pos)
{
    char tmp[1];

    if (vm->infos[pos].load_add == -1) {
        vm->infos[pos].load_add = (MEM_SIZE / vm->arena.champ_nbr) * pos;
    }
    for (int i = vm->infos[pos].load_add; read(fd, tmp, 1) > 0; i++) {
        if (vm->arena.arena[i] != 0)
            return exit_prog(false, "error: load add already used.");
        vm->arena.arena[i] = tmp[0];
    }
    return true;
}

bool load_champ(vm_t *vm, char *file)
{
    static int pos = 0;
    int fd;
    header_t hd;

    if ((fd = open(file, O_RDONLY)) < 0)
        return exit_prog(false, "error: cannot open file.");
    if ((read(fd, &hd, sizeof(header_t))) <= 0)
        return exit_prog(false, "error: cannot read file.");
    if (reverse_int(hd.magic) != EXEC_MAGIC_INT)
        return exit_prog(false, "error: magic number isn't good.");
    if (!my_strcpy(vm->infos[pos].name, hd.prog_name) ||
        !my_strcpy(vm->infos[pos].comment, hd.comment))
        return exit_prog(false, "error: name or comment failed.");
    vm->infos[pos].prog_size = reverse_int(hd.prog_size);
    if (!load_prog(vm, fd, pos))
        return false;
    close(fd);
    pos++;
    return true;
}

bool init_champs(vm_t *vm, char **av)
{
    if ((vm->chmps = malloc((vm->arena.champ_nbr + 1)
        * sizeof(champ_t))) == NULL)
        return exit_prog(false, "error: malloc of champs failed.");
    vm->chmps[4].pc = -1;
    for (int i = 0; i < vm->arena.champ_nbr; i++) {
        vm->chmps[i].carry = 0;
        vm->chmps[i].pc = 0;
        vm->chmps[i].reg[1] = vm->infos[i].prog_nbr;
    }
    for (int i = 0; av[i] != NULL; i++) {
        if (is_champion(av[i]))
            if (!load_champ(vm, av[i]))
                return false;
    }
    return true;
}
