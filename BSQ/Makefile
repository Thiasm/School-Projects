##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## bsq
##

SRC	=	bsq.c \
		create_buffer.c \
		create_tab.c \
		create_square.c \
		lib_functions.c \
		add_int.c \

CC	=	gcc

OBJ	=    $(SRC:.c=.o)

NAME	=    bsq

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
