/*
** EPITECH PROJECT, 2019
** .h
** File description:
** protos and structures for the navy
*/

#ifndef NAVY_H_
#define NAVY_H_
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <signal.h>

#define READ_SIZE 1

typedef struct idx_s {
    int k;
    int i;
    int stop;
}idx_t;

typedef struct game_var_s {
    int life;
    int enemy_life;
    char **map;
    char **enemy_map;
}game_var_t;

typedef struct info_s {
    int other_pid;
    char play[3];
    int turn;
    int step;
}info_t;

extern info_t info;

char *my_str_dup(char *str);
void my_putchar(char c);
void my_putstr(const char *str);
void my_put_nbr(int nb);
char *get_next_line(int fd);
int error(int argc, char **argv);
char **add_boats(char **map, char **pos);
int my_strlen(const char *str);
int str_compare(char *str1, char *str2);
int my_atoi(char const *str);
void get_pid(struct sigaction action, game_var_t *game_var);
void have_pid(int other, struct sigaction action, game_var_t *game_var);
void init_struct(struct sigaction action);
int game_loop(struct sigaction action, game_var_t *game_var);
int send_pos(int i, siginfo_t *signal, void *s);
int your_turn(struct sigaction action, game_var_t *game_var);
void send_number(char *input, int second);
void is_hit(game_var_t *game_var);
void print_my_map(char **map);
void print_enemy_map(char **enemy_map);
void handler_step_1(int i, siginfo_t *signal, void *s);
void handler_step_2(int i, siginfo_t *signal, void *s);
int game_turn_1(struct sigaction action, game_var_t *game_var);
void game_turn_2(struct sigaction action, game_var_t *game_var);
void add_hit(game_var_t *game_var);
void add_missed(game_var_t *game_var);
int check_boats(char **pos);
int check_len(char *pos);
int count_boats(char **pos);
int check_win(game_var_t *game_var);
void print_all(int *print, game_var_t *game_var);
#endif
