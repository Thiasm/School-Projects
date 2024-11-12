##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##


SRC     =	src/main.c			\
		src/funct_lib.c			\
		src/parse_tetriminos.c		\
		src/debug_mode.c		\
		src/disp_debug.c		\
		src/more_lib_funct.c		\
		src/simple_opt.c		\
		src/long_opt.c			\
		src/modify_size.c		\
		src/get_block.c			\
		src/get_next_line.c 		\
		src/parser_tool.c 		\
		src/my_printf.c			\
		src/error.c			\
		src/print_tetriminos.c  	\
		src/opt.c			\
		src/free_all.c			\

CC      =       gcc

OBJ     =    $(SRC:.c=.o)

NAME    =    tetris

CFLAGS += -I include

all :	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

tests_run:
	(cd tests/ && gcc -o test  ../*.c *.c --coverage -lcriterion)
	(cd tests/ && ./test)

re:	fclean all
