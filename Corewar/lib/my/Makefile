##
## EPITECH PROJECT, 2018
## lib_my
## File description:
## Makefile
##

NAME = libmy.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	exit_prog.c			\
		my_nbrlen.c			\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_strdup.c			\
		my_strfree.c		\
		my_strjoin.c		\
		my_strlen.c			\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c			\
		my_strsub.c			\
		my_memset.c			\
		my_isalnum.c		\
		my_isalpha.c		\
		my_isdigit.c		\
		my_putchar.c		\
		my_putstr.c			\
		my_put_nbr.c		\
		my_putchar_fd.c		\
		my_putstr_fd.c		\
		my_put_nbr_fd.c		\
		my_memalloc.c		\
		my_strnew.c			\
		my_strsplit.c		\
		my_isspace.c		\
		my_strndup.c		\
		get_next_line.c		\
		my_tablen.c			\
		my_freetab.c		\
		my_sscmp.c			\
		my_ssscmp.c			\
		my_bzero.c			\
		my_printf_main.c	\
		my_printf_fcts.c	\
		my_str_isnum.c		\
		my_getnbr.c			\
		my_str_to_word_array.c	\

OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS) -I.
	ar r $(NAME) $(OBJS)
	ranlib $(NAME)
	cp libmy.a ..

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
