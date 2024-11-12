##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile for navy
##

SRC	=	src/navy.c \
		src/funct_lib.c \
		src/more_lib_funct.c \
		src/get_next_line.c \
		src/boats.c \
		src/error_handling.c \
		src/connect.c \
		src/game.c \
		src/your_turn.c \
		src/is_hit.c \
		src/print_map.c \
		src/get_pid.c \

OBJ	=    $(SRC:.c=.o)

NAME =    navy

CFLAGS += -I include/

all :	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
