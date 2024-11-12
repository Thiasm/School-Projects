##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## evalexpr
##

SRC	=	my_hunter.c \
		convert.c \
		create_texture.c \
		game_in.c \
		game_manage.c \
		checkf.c \

CC	=	gcc

OBJ	=    $(SRC:.c=.o)

NAME	=    my_hunter

all :	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f include/*~

re:	fclean all
