##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for navy
##

SRC	=	src/lemin.c \
		src/parse.c \
		src/tool.c \
		src/find_ant_nbr.c \
		src/lib_function.c \
		src/parse_rooms.c \
		src/parse_tunnels.c \
		src/clear_comments.c \
		src/rooms_error.c \
		src/my_printf.c \
		src/count_start_end.c	\
		src/my_strcmp.c	\
		src/create_list.c \
		src/how_many_next.c	\
		src/rooms_error_bis.c \
		src/create_graph.c \
		src/pathfinding.c	\
		src/pathfinding_tools.c	\
		src/print_way.c \

TEST =	src/my_printf.c	\
	src/lib_function.c

TEST2 =	src/parse_tunnels.c \
	src/parse_rooms.c \
	src/my_strcmp.c	\
	src/tool.c \
	src/rooms_error_bis.c \
	src/rooms_error.c \
	src/lib_function.c

OBJ	=    $(SRC:.c=.o)

NAME =    lem_in

NAME1 = unit_tests

NAME2 = unit_tests_2

CFLAGS += -I include/ -g

all :	$(OBJ)
	gcc -o $(NAME) $(OBJ)

tests_run:
	gcc -o $(NAME1) $(TEST) tests/criterion.c --coverage -lcriterion
	./unit_tests
	gcc -o $(NAME2) $(TEST2) tests/lemin/criterion_lemin.c --coverage -lcriterion
	./unit_tests_2
clean:
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno
fclean:	clean
	rm -f $(NAME)
re:	fclean all

.PHONY: all clean fclean re
