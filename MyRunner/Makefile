##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## evalexpr
##

SRC	=	my_runner.c \
		set_score.c \
		create_texture.c \
		check_event.c \
		create_bad.c \
		create_parallax.c \
		origin.c \
		check_lose.c \
		game_menu.c \
		sword.c \
		read_map.c \
		block.c \
		checkf.c \

CC	=	gcc

OBJ	=    $(SRC:.c=.o)

NAME	=    my_runner

all :	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.o
	rm -f *~

re:	fclean all
