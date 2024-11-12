/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** prototypes_menu
*/

#ifndef PROTOTYPES_MENU_H_
#define PROTOTYPES_MENU_H_

int check_button(text_t *head, sfEvent event);
int check_event(sfRenderWindow *, sfEvent, text_t **, other_t *);
void colore_button(sfRenderWindow *window, text_t *head, int i, int size);
void add_texture(texture_t **head, char *location, char *name, sfVector2f pos);
void display_all(sfRenderWindow *window, texture_t *head, text_t *text_head);
void menu_main_initiliaze(general_t *, world_t *, player_t *, other_t *);
void load_sprite_menu(texture_t **head, text_t **text_head, other_t *other);
void clear_and_display(sfRenderWindow *, texture_t *, text_t *);
void settings(general_t *general);
int my_strcompare(char *s1, char *s2);
void add_text(text_t **head, char *name, sfFont *font, sfVector2f pos);
sfRenderWindow *create_my_window(void);
char *my_getenv(char **envp, char *to_compare);
void infinity_background(texture_t *current);
void select_hero(general_t *general, player_t *player, other_t *other);
bool check_event_selec(sfRenderWindow *, sfEvent, text_t **, player_t *);
void display_selection(sfRenderWindow *, texture_t *, text_t *);
void free_select(texture_t *texture, text_t *text);
void load_sprite_selection(texture_t **, text_t **, other_t *);
int back_to_game(general_t *general, other_t *other, int check);
void load_sprite_settings(texture_t **, text_value_t **);

#endif /* !PROTOTYPES_MENU_H_ */
