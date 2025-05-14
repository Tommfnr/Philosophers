# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfournie <tfournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 17:04:06 by tfournie          #+#    #+#              #
#    Updated: 2025/05/14 12:10:33 by tfournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -MMD -MP
NAME = philo
MAKEFLAGS += --no-print-directory


INCLUDE_PATH = -I./include

SRC_FILES = main.c \
			parsing.c \
			init.c \
			routine.c \
			lib_utils/ft_atoi.c \
			lib_utils/ft_isdigit.c \
			lib_utils/ft_isnumber_pos.c \
			lib_utils/ft_time.c \


SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/,$(SRC_FILES))


OBJ_DIR = build
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
DEPS = $(OBJ:.o=.d)


$(shell mkdir -p $(OBJ_DIR))

GREEN = \033[32m
RED = \033[31m
RESET = \033[0m


all: $(NAME)

$(NAME): $(OBJ) Makefile
	@$(CC) $(OBJ) -o $(NAME)
	@echo "${GREEN}Le programme est prêt !${RESET}"

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_PATH) -c $< -o $@


clean:
	@rm -rf $(OBJ_DIR)
	@echo "${RED}Fichiers objets du programme supprimés.${RESET}"

fclean: clean
	@rm -f $(NAME)
	@echo "${RED}programme supprimé et répertoire build supprimé.${RESET}"

FORCE:

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re

-include $(DEPS)
