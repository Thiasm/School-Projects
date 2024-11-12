##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##


SRC     =	main.c	\
		algo.c	\
		error.c \
		tool.c \
		add_node.c \

CC      =       gcc

OBJ     =    $(SRC:.c=.o)

NAME    =    solver

all :	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
