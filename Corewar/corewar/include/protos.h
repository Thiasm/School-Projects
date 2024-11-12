/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** protos.h
*/

/* corewar.c */
int corewar(char **av, int ac);
bool is_champion(char *name);
int load_dump(arena_t *arena, char **av, int *i);
int load_add(chmp_info_t *infos, char **av, int *i);
int load_prog_nbr(chmp_info_t *infos, char **av, int *i);

/* cycles.c */
void check_cycles(vm_t *vm);

/* init.c */
int init_args(vm_t *vm, char **av, int ac, int *i);
void init_reg_pc(vm_t *vm, int pos);
int init_vm(vm_t *vm);

/* load_champs.c */
bool init_champs(vm_t *vm, char **av);
bool load_champ(vm_t *vm, char *file);

/* utils.c */
int reverse_int(int nb);
int count_researched(char *str, char researched);