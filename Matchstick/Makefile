##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infinadd
##

SRC	=	matchstick.c \
		create_map.c \
		lib_functions.c \
		get_data.c \
		ia.c \
		error.c \
		how_many_sticks.c \
		find_matches.c \
		find_line.c \

CC	=	gcc

OBJ	=    $(SRC:.c=.o)

NAME	=	matchstick

all :	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)


clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.o
	rm -f *~
	rm -f *#
	rm -f include/*~

re:	fclean all
