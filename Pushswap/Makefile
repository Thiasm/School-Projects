##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## infinadd
##

SRC	=	pushswap.c \
		lib_functions.c \
		pushswap_functions.c \
		swap_loop.c \

CC	=	gcc

OBJ	=    $(SRC:.c=.o)

NAME	=	push_swap

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
