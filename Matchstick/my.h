/*
** EPITECH PROJECT, 2019
** my0h
** File description:
** task 2
*/

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

struct data {
    char **map;
    int height;
    int width;
    int line;
    int matchs;
    int nb_stick;
    int max_matchs;
    int print_matches;
    int print_line;
    int ask_matches;
};

typedef struct data data_t;

void my_putchar(char c);
void my_putstr(char *str);
int game_init(data_t *data, char **argv);
int main(int argc, char **argv);
void create_map(data_t *data);
void ia_line(data_t *data);
void free_map(data_t *data);
int my_atoi(char *str);
void print_map(data_t *data);
void create_ia(data_t *data);
int my_strlen(char const *str);
void empty_line(data_t *data, int where);
int player_turn(data_t *data);
void put_matches(data_t *data, int y, int nb_matches);
int get_data(data_t *data);
int find_line(data_t *data);
int how_many_stick(char *str);
int find_match(data_t *data);
void my_put_nbr(int nb);
int error(int argc, char **argv);
int check_if_number(char *str);
void print_action(data_t *data, char *who);
int ia_turn(data_t *data);
int game_loop(data_t *data);
void matches_error(int tmp, data_t *data, char *matches);
void error_line(data_t *data, int tmp, char *line);
void last_matches_error(int tmp, data_t *data);