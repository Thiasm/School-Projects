##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## This one, called by the main Makefile with the command make lib, make the
## libmy.a
##

SRC	=	src/advanced_flags_management.c	\
		src/my_print_special.c	\
		src/easy_flags_management.c	\
		src/flags_with_base_management.c	\
		src/my_put_nbr_base.c	\
		src/my_add_to_dest.c	\
		src/none_signed_flags.c	\
		src/my_printf.c	\
		src/get_next_line.c	\
		src/my_getnbr.c	\
		src/my_putstr.c	\
		src/my_strlen.c	\
		src/my_putchar.c	\
		src/my_strncpy.c	\
		src/my_atoi.c	\
		src/my_putnbr.c	\
		src/my_str_isnum.c	\
		src/my_put_nbr.c	\
		src/my_strcompare.c	\
		src/my_str_to_wordtab.c	\
		src/my_strcat.c \
		src/my_int_to_str.c \
		src/get_file.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my/libmy.a

CC	=	gcc

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
