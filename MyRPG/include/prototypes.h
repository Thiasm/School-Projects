/*
** EPITECH PROJECT, 2019
** prototypes.h
** File description:
** prototypes.h
*/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

#include "struct.h"
#include "struct_menu.h"

char *itoa(int);
char **get_file(char *filepath);
char *chose_background(int x, int y);
void fight_loop(player_t *player, monster_t *monster, general_t *general);
void init_quest(general_t *general, other_t *other);
void fight_gameplay(sfEvent, text_t *, player_t *, monster_t *);
int check_dead(stat_player_t *, monster_t *, fight_t *, general_t *);
void add_game_stat(fight_t *fight, stat_player_t *info, monster_t *monster);
void init_game_stat(fight_t *fight, int x, int y, char *name);
void attack(stat_player_t *info, monster_t *monster, player_t *player);
void display_fight(fight_t *, monster_t *, general_t *, text_t *);
int check_pos(int x, int y, int *pos_pnj);
void sprite_boss(monster_t *monster);
void init_fight(fight_t *, monster_t *, text_t **, player_t *);
void volume_change(int *volume, int option);
void menu_main_initiliaze(general_t *, world_t *, player_t *, other_t *);
void initialisation_world(world_t *world, char *location);
void initialisation_player(player_t *player, char *location, int genre);
void display_game(general_t *, world_t *, player_t *, other_t *);
void my_rpg(general_t *, world_t *, player_t *, other_t *);
void display_world(general_t *general, world_t *world);
void initialisation(general_t *, world_t *, player_t *, other_t *);
void display_player(general_t *general, player_t *player);
void sound_rpg(general_t *, world_t *, player_t *, other_t *);
void reset_move(general_t *general);
void get_position_by_name(player_t *player, sfView *view);
void player_events(general_t *, player_t *, other_t *, sfEvent *);
void analyse_events(general_t *, sfEvent *, other_t *, player_t *);
void map_binary(general_t *general);
int check_case(int **array, int dir, player_t *player);
void initialisation_music(other_t *other);
int pause_menu(general_t *, other_t *);
void read_pnj(world_t *world);
bool verify_all_files(void);
void interaction_events(general_t *, player_t *, world_t *, sfEvent *);
void check_dialog(int x, int y, general_t *general, world_t *world);
int modif_move(int dir, int top, player_t *player, general_t *general);
void initialisation_dialog(general_t *general, other_t *other);
void initialisation_monster(general_t *general, world_t *world);
void gameplay(other_t *, world_t *, player_t *, general_t *);
void add_monster(int x, int y, int **array, world_t *world);
int random_nb(int min, int max);
void restart_game(general_t *general, other_t *other);
void how_to_play(general_t *general);
void init_boss(general_t *general, world_t *world);
void stat_player(player_t *player);
void initialisation_inventory(other_t *other);
void sand_particles(sfVertexArray *);
void select_class(general_t *general, player_t *player, other_t *other);
void initialisation_class(texture_t **, text_t **, other_t *);
void edit_class_text(text_t *text);
void display_inventory(general_t *general, other_t *other, player_t *player);
void read_monster(world_t *world);
void stock_monster(world_t *world, monster_t *monster);
int array_monster(player_t *player, monster_t *monster, general_t *general);
void fight_loop(player_t *player, monster_t *monster, general_t *general);
int array_boss(player_t *player, monster_t *monster, general_t *general);
void add_info(char *name, monster_t *monster, info_t *info);
void intialisation_general(general_t *general);
void mov_door(general_t *general);
void chose_class(stat_player_t *stat);
void up_level(stat_player_t *stat);
void amelioration(stat_player_t *stat, int dex, int smart, int strg);
void your_class(stat_player_t *stat);
void display_attack(general_t *general, player_t *player);
void snow_particles(sfVertexArray *test);
void destroy_exit(general_t *general, other_t *other, player_t *player);

#endif
