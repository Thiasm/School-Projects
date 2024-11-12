/*
** EPITECH PROJECT, 2018
** CPE_corewar_2018
** File description:
** protos.h
*/

#define registr 0
#define direct 1
#define indirect 2

/* asm.c */
void handle_file(char *filepath);
int count_researched(char *str, char researched);
void asm_champ(file_t *file, char **tab);
char *asm_to_byte(char **tab, char *byte, idx_t *idx);
int rev_int(int nbr);

/* init.c */
bool init_file(file_t *file, char *filepath);

/* header.c */
bool is_header(header_t *hd, char *line);
char *concat_header(char *s1, const char *s2, int m);

/* parse_command.c */
char **parse_command(char const *str);

/* asm_to_byte.c */
char *asm_to_byte(char **tab, char *byte, idx_t *idx);
char *add_dir(char *byte, char *line, idx_t *idx);
int count_lines(char **tab);
char *add_size(char *byte, char param_size, idx_t *idx);

/* utils_byte.c */
int my_atoi(char const *str);
int my_compute_power_rec(int nb, int power);
char put_in_dec(char param_size, char *size);
void fill_with_zeros(char *size);
int my_natoi(char const *str);

/* error handling */

void error_handling(char **command);
char **parse_command(char const *str);
int return_err(char * const str);
int nbr_arg(char **command, int y);