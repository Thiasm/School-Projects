/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** main
*/

#include "my.h"

void check_window_size(WINDOW *sokoban, var_t *var, pos_t *pos)
{
    mvprintw((LINES /2), (COLS / 2) - 9.5, "Terminal too small");
    var->key = getch();
    quit_game(var, pos);
    refresh();
}

void init_var(var_t *var, pos_t *pos, char *file)
{
    var->game = 1;
    var->obj = 0;
    pos->y_o = 0;
    var->nb_x = 0;
    get_size(file, var);
    load_map(file, var);
    find_line(var);
    find_longer(pos, var);
    map_to_tab(var);
    find_p(pos, var);
    find_o_pos(pos, var);
}

void game_boucle(var_t *var, pos_t *pos)
{
    display_map(var);
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    mvprintw(pos->y, pos->x, "P");
    attroff(COLOR_PAIR(1));
    var->key = getch();
    move_player(var, pos);
    back_mark(pos, var);
    win_game(pos, var);
    reset_game(var, pos);
    refresh();
}

int main(int argc, char **argv)
{
    pos_t pos;
    var_t var;
    WINDOW *sokoban;
    char *file = argv[1];

    if (argc != 2)
        exit(84);
    my_strcmp(file);
    init_var(&var, &pos, file);
    error(&var, &pos, argc);
    initscr();
    while (var.game == 1)
        game_on(&var, &pos, sokoban);
    endwin();
    free_tab(&var, &pos);
    return (0);
}
