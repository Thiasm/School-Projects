##
## EPITECH PROJECT, 2018
## Lemin
## File description:
## Makefile
##

FILE_DIR	=	src/file_verifications/

LOOP_DIR	=	src/loop/

CLASS_BOSS_DIR	=	src/class_boss/

INVENTORY_DIR	=	src/inventory/

MENU_DIR	=	src/menu/

INIT_DIR	=	src/initialisation/

EVENTS_DIR	=	src/events/

TOOLS_DIR	=	src/tools/

DIR 	=		src/

FIGHT_DIR	=	src/fight/

SRC		=	$(CLASS_BOSS_DIR)change_class.c	\
			$(CLASS_BOSS_DIR)creation_boss.c	\
			$(CLASS_BOSS_DIR)creation_monster.c	\
			$(CLASS_BOSS_DIR)select_class.c \
			$(INVENTORY_DIR)inventory_init.c \
			$(INVENTORY_DIR)inventory_display.c \
			$(MENU_DIR)functions/menu_env_checker.c \
			$(MENU_DIR)functions/menu_lang.c \
			$(MENU_DIR)functions/menu_lists.c \
			$(MENU_DIR)main/menu_sprites.c \
			$(MENU_DIR)main/menu_window.c \
			$(MENU_DIR)character_selection/menu_selection.c \
			$(MENU_DIR)settings/menu_settings.c \
			$(MENU_DIR)settings/text_edit.c \
			$(MENU_DIR)main/menu_main.c \
			$(MENU_DIR)main/menu_events.c \
			$(MENU_DIR)pause_menu.c	\
			$(INIT_DIR)initialisation.c	\
			$(INIT_DIR)initialisation_world.c	\
			$(INIT_DIR)initialisation_quest.c	\
			$(INIT_DIR)initialisation_stat.c	\
			$(EVENTS_DIR)interaction_events.c	\
			$(EVENTS_DIR)events_player.c	\
			$(EVENTS_DIR)general_events.c	\
			$(TOOLS_DIR)pause_menu_tool.c	\
			$(TOOLS_DIR)basic_tools.c	\
			$(TOOLS_DIR)reader.c	\
			$(TOOLS_DIR)class_tool.c \
			$(TOOLS_DIR)check.c	\
			$(FIGHT_DIR)fight.c	\
			$(FIGHT_DIR)background_manage.c	\
			$(FIGHT_DIR)stat_manage.c	\
			$(FIGHT_DIR)fight_tools.c	\
			$(FIGHT_DIR)display_fight.c	\
			$(FIGHT_DIR)init_fight.c	\
			$(FILE_DIR)file_verifications.c \
			$(LOOP_DIR)my_rpg.c	\
			$(LOOP_DIR)display.c	\
			$(LOOP_DIR)player_moving.c	\
			$(LOOP_DIR)dialog_pnj.c	\
			$(LOOP_DIR)gameplay.c	\
			$(LOOP_DIR)particles_handler.c \
			$(DIR)main.c \

SRC_TEST	=	tests/tests_function.c \
			tests/tests_generic.c \

OBJ		=	$(SRC:.c=.o)

OBJ_TEST	=	$(SRC_TEST:.c=.o)

FLAGS		=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include/

LIB		=	-L./lib/my/ -lmy

NAME		=	my_rpg

NAME_TEST	=	unit_tests

DEPS		=	include/rpg.h

CC		=	gcc

RM		=	rm -rf

all:			lib $(NAME)

debug:			CFLAGS += -g3
debug: 			re

$(NAME):		$(OBJ)
			$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB) $(FLAGS)
			$(RM) assets
			unzip assets.zip

clean:
			$(RM) $(OBJ)

fclean:			clean lib_clean tests_clean
			$(RM) $(NAME)
			$(RM) *.dSYM
			$(RM) .vscode/
			$(RM) assets

re:			fclean all

lib:
			@make --no-print-directory re -C ./lib
			@make --no-print-directory clean -C ./lib

lib_clean:
			@make --no-print-directory fclean -C ./lib

tests_run: 		lib $(OBJ)
			$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LIB)
			$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(LIB) --coverage -lcriterion
			./$(NAME_TEST)

rm_test:
			$(RM) $(NAME_TEST)
			$(RM) *.gcda
			$(RM) *.gcno

tests_clean:		rm_test

all_clean: 		fclean rm_test

.PHONY:			all clean fclean re lib lib_clean tests_run tests_clean rm_test
