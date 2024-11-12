##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infinadd
##

SRC	=	my_sokoban.c \
		create_tab.c \
		read_file.c \
		init_game.c \
		move_player.c \
		check_o.c \
		checkf.c \

CC	=	gcc

OBJ	=    $(SRC:.c=.o)

NAME	=	my_sokoban

all :	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f include/*~

re:	fclean all
