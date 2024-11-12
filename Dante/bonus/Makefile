##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##


SRC     =	main.c	\
			algo.c	\
			error.c \

CC      =       gcc -g3

OBJ     =    $(SRC:.c=.o)

NAME    =    solver

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
