##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compiles files
##

SRC_DIR		=	$(realpath ./src)

tests_run: CFLAGS	+=	--coverage

SRC		=	main.c								\
			$(SRC_DIR)/minishell.c				\
			$(SRC_DIR)/init_env.c				\
			$(SRC_DIR)/prompt.c					\
			$(SRC_DIR)/builtins/builtins.c		\
			$(SRC_DIR)/builtins/builtins_cmds.c	\
			$(SRC_DIR)/builtins/echo.c			\
			$(SRC_DIR)/builtins/history.c		\
			$(SRC_DIR)/builtins/env.c			\
			$(SRC_DIR)/builtins/execution.c		\
			$(SRC_DIR)/builtins/cd.c			\
			$(SRC_DIR)/builtins/setenv.c		\
			$(SRC_DIR)/builtins/unsetenv.c		\
			$(SRC_DIR)/signal/signal_handling.c	\
			$(SRC_DIR)/signal/signal_init.c		\
			$(SRC_DIR)/tree/create_token.c		\
			$(SRC_DIR)/tree/create_tree.c		\
			$(SRC_DIR)/tree/my_cmd_to_tab.c		\
			$(SRC_DIR)/tree/my_cmd_to_exec.c	\
			$(SRC_DIR)/tree/read_tree.c			\
			$(SRC_DIR)/operator/double_pipe.c	\
			$(SRC_DIR)/operator/perluette.c		\
			$(SRC_DIR)/operator/semicolon.c		\
			$(SRC_DIR)/operator/redir.c			\
			$(SRC_DIR)/operator/pipe.c			\
			$(SRC_DIR)/tree/tree_tool.c			\
			$(SRC_DIR)/tool.c					\
			$(SRC_DIR)/builtins/alias.c			\
			$(SRC_DIR)/builtins/check_alias.c	\

T_SRC	=	tests/unit_tests.c					\
			$(SRC_DIR)/minishell.c				\
			$(SRC_DIR)/init_env.c				\
			$(SRC_DIR)/prompt.c					\
			$(SRC_DIR)/builtins/builtins.c		\
			$(SRC_DIR)/builtins/builtins_cmds.c	\
			$(SRC_DIR)/builtins/echo.c			\
			$(SRC_DIR)/builtins/history.c		\
			$(SRC_DIR)/builtins/env.c			\
			$(SRC_DIR)/builtins/execution.c		\
			$(SRC_DIR)/builtins/cd.c			\
			$(SRC_DIR)/builtins/setenv.c		\
			$(SRC_DIR)/builtins/unsetenv.c		\
			$(SRC_DIR)/signal/signal_handling.c	\
			$(SRC_DIR)/signal/signal_init.c		\
			$(SRC_DIR)/tree/create_token.c		\
			$(SRC_DIR)/tree/create_tree.c		\
			$(SRC_DIR)/tree/my_cmd_to_tab.c		\
			$(SRC_DIR)/tree/my_cmd_to_exec.c	\
			$(SRC_DIR)/tree/read_tree.c			\
			$(SRC_DIR)/operator/double_pipe.c	\
			$(SRC_DIR)/operator/perluette.c		\
			$(SRC_DIR)/operator/semicolon.c		\
			$(SRC_DIR)/operator/redir.c			\
			$(SRC_DIR)/operator/pipe.c			\
			$(SRC_DIR)/tree/tree_tool.c			\
			$(SRC_DIR)/tool.c					\
			$(SRC_DIR)/builtins/alias.c			\
			$(SRC_DIR)/builtins/check_alias.c	\

OBJ		=	$(SRC:.c=.o)

TOBJ	=	$(T_SRC:.c=.o)

GCNAO	=	$(T_SRC:.c=.gcda) $(T_SRC:.c=.gcno)

NAME	=	42sh

NAME_T	=	unit_tests

CFLAGS	=	-W -Wall -Wextra -g3			\
			-I./include

LFLAGS	=	-L./lib -lmy

TFLAGS	=	-lcriterion --coverage

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C./lib/my re
		gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		make -C./lib/my clean
		rm -f $(OBJ)
		rm -f $(TOBJ)
		rm -f $(GCNAO)

fclean:		clean
		make -C./lib/my fclean
		rm -f $(NAME)
		rm -f $(NAME_T)
		rm -f ./lib/libmy.a

re: fclean all

tests_run: fclean $(NAME_T)

$(NAME_T): 	$(TOBJ)
			make -C./lib/my re
			gcc -o $(NAME_T) $(TOBJ) $(LFLAGS) $(TFLAGS)
			./unit_tests
			gcovr -e tests/unit_tests.c

.PHONY: all fclean clean re tests_run
