/*
** EPITECH PROJECT, 2018
** my h
** File description:
** sokoban
*/

#include <criterion/criterion.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

struct pos {
    int x;
    int y;
    int **tab_pos_o;
    int y_o;
};

typedef struct pos pos_t;

struct var {
    int obj;
    int nb_x;
    int game;
    int size;
    char *buffer;
    int lines;
    int longer;
    int key;
    char **map;
};

typedef struct var var_t;

void game_on(var_t *var, pos_t *pos, WINDOW *sokoban);
void free_tab(var_t *var, pos_t *pos);
int win_game(pos_t *pos, var_t *var);
void find_o_pos(pos_t *pos, var_t *var);
void back_mark(pos_t *pos, var_t *var);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(var_t *var);
void find_longer(pos_t *pos, var_t *var);
void check_longer_line(var_t *var, int *i, int *j);
char **map_to_tab(var_t *var);
void find_line(var_t *var);
int my_strline(char *str);
void error(var_t *var, pos_t *pos, int argc);
void display_map(var_t *var);
void find_p(pos_t *pos, var_t *var);
void check_map(pos_t *pos, var_t *var, int y, int x);
void reset_game(var_t *var, pos_t *pos);
void quit_game(var_t *var, pos_t *pos);
void move_player(var_t *var, pos_t *pos);
void move_top(var_t *var, pos_t *pos);
void move_down(var_t *var, pos_t *pos);
void move_left(var_t *var, pos_t *pos);
void move_right(var_t *var, pos_t *pos);
void init_var(var_t *var, pos_t *pos, char *file);
void check_window_size(WINDOW *sokoban, var_t *var, pos_t *pos);
void game_boucle(var_t *var, pos_t *pos);
int main(int argc, char **argv);
void get_size(char *filepath, var_t *var);
void *load_map(char *filepath, var_t *var);
int my_strcmp(char *str1);
