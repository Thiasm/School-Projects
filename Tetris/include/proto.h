/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

void free_info(char **info);
void free_all(data_t *data);
void parse_tetriminos(data_t *data);
int my_strcmp(char *s1, char *s2);
void my_putstr(const char *str);
char **debug_mode(int ac, char **av, char **info);
char *my_str_dup(char *str);
void my_putchar(char c);
void disp_debug(char **info);
int my_atoi(char const *str);
int my_strlen(const char *str);
char **modify_info(char **info, int ac, char **av);
char **long_opt(char **info, char **av, int *i);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcat(char *s1, char *s2);
char *modify_wnd(char *line, char *opt);
int get_tetriminos_info(struct dirent *info, block_t *block);
char *get_next_line(int fd);
int get_block_form(int fd, block_t *block);
int get_width(char *str, int *i);
int get_height(char *str, int *i);
int get_color(char *str, int *i);
int get_block_size(char *str, block_t *block);
void print_tetriminos(data_t *data);
int get_tetriminos_info(struct dirent *info, block_t *block);
char *get_name(char *str, block_t *block);
int add_block(struct dirent *info, data_t *data);
void init_tetriminos(data_t *data);
void my_printf(char *str, ...);
char *stradd(char *origin, char *add);
void print_help(char **av);
void free_all(data_t *data);
char *my_strcpy(char *src);
int verify_form(block_t *block);
char *delete_dot(char *str);
int change_key_right(int *i, char **av, char ***info);
char *modify_key(char *line, char *new_str);
int see_next(int *i, char **av, char ***info);
int long_key_sides(char ***info, char **av, int *i);
char *long_modify_key(char *line, char *opt);
int modify_num(char ***info, char **av, int *i);
char **check_caps(char **info);
