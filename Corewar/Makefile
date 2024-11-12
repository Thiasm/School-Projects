##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Compiles files
##

ASM_DIR		=	$(realpath ./asm/src)

CORE_DIR	=	$(realpath ./corewar/src)

SRC_ASM		=	$(ASM_DIR)/main.c					\
				$(ASM_DIR)/asm.c					\
				$(ASM_DIR)/compile_champ.c			\
				$(ASM_DIR)/init.c					\
				$(ASM_DIR)/header.c					\
				$(ASM_DIR)/op.c						\
				$(ASM_DIR)/parse_commands.c			\
				$(ASM_DIR)/asm_to_byte.c			\
				$(ASM_DIR)/utils_byte.c				\
				$(ASM_DIR)/error_handling.c			\
				$(ASM_DIR)/return_err.c				\
				$(ASM_DIR)/reverse_int.c			\
				$(ASM_DIR)/add_dir.c				\
				$(ASM_DIR)/check_nbr_arg.c			\

SRC_CORE	=	$(CORE_DIR)/main.c					\
				$(CORE_DIR)/corewar.c				\
				$(CORE_DIR)/cycles.c				\
				$(CORE_DIR)/init.c					\
				$(CORE_DIR)/parse_command.c			\
				$(CORE_DIR)/load_champs.c			\
				$(CORE_DIR)/utils.c					\
				$(CORE_DIR)/op.c

OBJ_ASM		=	$(SRC_ASM:.c=.o)

OBJ_CORE	=	$(SRC_CORE:.c=.o)

NAME_ASM	=	asm/asm

NAME_CORE	=	corewar/corewar

CFLAGS	=	-W -Wall -Wextra			\

make_asm: CFLAGS += -I./asm/include -g3

make_core: CFLAGS += -I./corewar/include -g3

LFLAGS	=	-L./lib -lmy

all:
		make -C./lib/my re
		cp lib/my/my.h asm/include/
		cp lib/my/my.h corewar/include/
		make make_core
		make make_asm

make_asm: $(NAME_ASM)

$(NAME_ASM):	$(OBJ_ASM)
		gcc -o $(NAME_ASM) $(OBJ_ASM) $(LFLAGS)

make_core: $(NAME_CORE)

$(NAME_CORE):	$(OBJ_CORE)
		gcc -o $(NAME_CORE) $(OBJ_CORE) $(LFLAGS)

clean:
		make -C./lib/my clean
		rm -f $(OBJ_ASM)
		rm -f $(OBJ_CORE)

fclean:		clean
		make -C./lib/my fclean
		rm -f ./lib/libmy.a
		rm -f $(NAME_ASM)
		rm -f $(NAME_CORE)

re: fclean all

.PHONY: all fclean clean re
