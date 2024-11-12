##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##


SRC     =	main.c	\
			tool.c 	\
			perfect_maze.c  \
			imperfect_maze.c \

CC      =       gcc

OBJ     =    $(SRC:.c=.o)

NAME    =    generator

all :	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

tests_run:
	(cd tests/ && gcc -o test  ../*.c *.c --coverage -lcriterion)
	(cd tests/ && ./test)

re:	fclean all
