##
## EPITECH PROJECT, 2019
## 
## File description:
## 
##

SRC     =   src/defender.c \
			src/menu_loop.c \
			src/tool.c \
			src/base_menu.c \
			src/level_menu.c \
			src/game_loop.c \
			src/set_game_loop.c \
			src/destroy.c \
			src/pause_game.c \
			src/pause_button.c \
			src/display_bad.c \
			src/set_price.c \
			src/get_pos.c \
			src/shoot.c \
			src/my_realloc.c \
			src/is_path.c \
			src/end_loop.c \
			src/set_tower.c \
			src/move_bad.c \

CC      =        gcc

OBJ     =    $(SRC:.c=.o)

NAME    =    my_defender

all :   $(NAME)

$(NAME):        $(OBJ)
	$(CC) $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-network -lcsfml-audio -lcsfml-system

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f include/*~

re:     fclean all
