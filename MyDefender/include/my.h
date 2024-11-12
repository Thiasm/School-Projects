/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** include for the defender
*/

#ifndef _MY_H
#define _MY_H

#include <stdlib.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <time.h>
#include <SFML/Audio.h>

#define ELAPSED_TIME    sfTime_asSeconds(sfClock_getElapsedTime(game->bad.clock_shoot))

struct data {
    int mouse_x;
    int mouse_y;
    int step;
    sfRenderWindow *window;
    sfEvent event;
    sfFont *font;
    sfSprite *s_cursor;
    int **bad_pos;
    int **tower_pos;
};

typedef struct data data_t;
    
    
struct menu {
    sfSprite *help_background;
    sfText *help_text;
    sfSprite *s_background;
    sfSprite *s_logo;
    sfSprite *s_game_over;
    sfText *play_text;
    sfText *quit_text;
    sfText *select_level_text;
    sfText *ice_text;
    sfText *land_text;
    sfMusic *menu_music;
};

typedef struct menu menu_t;

struct game {
    struct setting {
        sfSprite *s_hud;
        sfSprite *s_map;
        sfSprite *s_money;
        sfSprite *s_hearth;
        sfSprite *s_wave;
        sfText *life_text;
        sfText *wave_text;
        sfText *money_text;
        sfMusic *game_music;
        sfMusic *argent;
        sfMusic *die;
        int volume;
    } setting;
    struct pause {
        sfSprite *s_background;
        sfSprite *s_sound_button;
        sfSprite *s_pause;
        sfText *resume_text;
        sfText *quit_text;
        sfText *restart_text;
    } pause;
    struct tower {
        sfSprite *s_canon;
        sfSprite *s_laser;
        sfSprite *s_big;
        sfSprite *s_wall;
        sfText *price_canon;
        sfText *price_big;
        sfText *price_laser;
        sfText *price_wall;
        sfSprite *shop_one;
        sfSprite *shop_two;
        sfSprite *shop_three;
        sfSprite *shop_for;
        sfSprite *range;
        char **map;
    } tower;
    struct bad {
        float speed;
        int wave_tmp;
        float second_bad;
        sfTime time_bad;
        sfClock *clock_bad;
        sfTime time_move_bad;
        sfClock *clock_move_bad;
        float second_move_bad;
        sfSprite *s_slime;
        sfClock *clock_shoot;
        sfIntRect rect_slime;
        sfTime shoot;
        float shoot_sec;
        sfClock *big;
        sfClock *slow;
        sfClock *mine_clock;
        sfTime time_mine;
        sfTime shoot_big;
        float mine_sec;
        float big_sec;
        sfTime shoot_slow;
        float slow_sec;
    } bad;
    int life;
    int wave;
    int money;
    int choice;
};

typedef struct game game_t;

#endif

sfText *create_text(sfText *tmp, char *str, data_t *data, sfVector2f co);
void menu_loop(data_t *data, menu_t *menu);
void set_tower(game_t *game, data_t *data);
void place_tower(data_t *data, game_t *game);
void display_setting(data_t *data, game_t *game);
int main(int ac, char **av, char **env);
int **spawn_bad(data_t *data, game_t *game);
void base_menu(data_t *data, menu_t *menu);
void set_base_menu(data_t *data, menu_t *menu);
void level_menu(data_t *data, menu_t *menu);
void set_level_menu(data_t *data, menu_t *menu);
void pause_game(data_t *data, game_t *game, menu_t *menu);
void display_bad(data_t *data, game_t *game);
void set_bad(game_t *game);
void click_level_menu(data_t *data, menu_t *menu, sfEvent event);   
void sound_button(data_t *data, game_t *game);
void click_base_menu(data_t *data, menu_t *menu, sfEvent event);
void create_window(data_t *data);
void set_game_pause(game_t *game, data_t *data);
void move_ajax(data_t *data, game_t *game);
sfSprite *create_sprite(char *path, sfVector2f co);
void resume_quit_button(data_t *data, game_t *game, menu_t *menu);
void destroy_menu(menu_t *menu);
void anime_bad(data_t *data, game_t *game);
void fill_tower_tab(data_t *data, game_t *game);
void destroy_game(game_t *game);
void click_pause(data_t *data, game_t *game, menu_t *menu);
void display_pause(data_t *data, game_t *game);
int is_path(data_t *data, game_t *game);
void set_game_setting(game_t *game, data_t *data);
void cursor(data_t *data, sfSprite *choice);
void set_game_loop(data_t *data, game_t *game);
void destroy_all(data_t *data, game_t *game, menu_t *menu);
void turn_turret(data_t *data, game_t *game);
int end_wave(data_t *data, game_t *game);
void set_level(data_t *data, game_t *game);
void closed_window(sfRenderWindow *window, sfEvent event);
void game_loop(data_t *data, game_t *game, menu_t *menu);
void first_cursor(data_t *data, sfSprite *choice);
void draw_turret(data_t *data, game_t *game);
char *my_itoc(int number);
void set_price(data_t *data, game_t *game);
void detect_spot(data_t *data, sfSprite *choice);
char **malloc_map(void);
char **modif_map(data_t *data, char **map);
int get_pos(data_t *data, game_t *game);
void check_way(data_t *data, game_t *game, int i);
void other_setting(game_t *game, data_t *data);
void check_way(data_t *data, game_t *game, int i);
void other_setting(game_t *game, data_t *data);
void help_menu(data_t *data, menu_t *menu);
sfSprite *tower_cursor(int choice, game_t *game, data_t *data);
void parcours_bad(data_t *data, int i, game_t *game);
void canon_shoot(data_t *data, game_t *game);
void kill_bad_normal(data_t *data, game_t *game, int k, int i);
void kill_bad_aoe(data_t *data, game_t *game, int k);
void display_tower(data_t *data, game_t *game);
int check_death(data_t *data, game_t *game, int i);
void destroy_data(data_t *data);
void end_loop(data_t *data, menu_t *menu);
void click_end_menu(data_t *data, menu_t *menu, sfEvent event);
void kill_big(data_t *data, game_t *game, int k, int i);
void slow_enemi(data_t *data, game_t *game, int k, int i);
void other_tower(game_t *game, data_t *data);
void more_set_tower(game_t *game, data_t *data);
void more_setting(game_t *game, data_t *data);
int pos_t(game_t *game, data_t *data);

