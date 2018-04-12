# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:51:13 by acouturi          #+#    #+#              #
#    Updated: 2018/03/07 12:19:56 by acouturi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./

SRC_NAME = main.c traitement.c

SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

LIBFT = biglib/biglib.a

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

INCL = -I /usr/local/include

CFLAGS = -Werror -Wall -Wextra
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
MLXLIB = -L /usr/local/lib/

# Colors
_GREY	= "\033[0;30m"
_RED	= "\033[0;31m"
_GREEN	= "\033[0;32m"
_YELLOW	= "\033[0;33m"
_BLUE	= "\033[0;34m"
_PURPLE	= "\033[0;35m"
_CYAN	= "\033[0;36m"
_WHITE	= "\033[0;37m"
_NONE	= "\033[0m"

all : $(NAME)

$(NAME) : $(OBJ)
	@echo $(_BLUE) "Created :	" $(_NONE) $(NAME)
	@gcc $(CFLAGS) $(INCL) $(MLXLIB) -o $(NAME) $(SRC) $(LIBFT) $(MLXFLAGS)
	@echo $(_GREEN) "DONE" $(_NONE)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@make -C biglib
	@mkdir -p $(OBJ_DIR)
	@echo $(_BLUE) "Compiling :	" $(_NONE) $<
	@gcc $(CFLAGS) -o $@ -c $<

clean: cleano
	@make clean -C biglib

cleano :
	@echo $(_RED) "Remove :" $(OBJ_DIR) $(_NONE)
	@/bin/rm -rf $(OBJ_DIR)
	@echo $(_GREEN) "DONE" $(_NONE)

fclean: cleano
	@make fclean -C biglib
	@echo $(_RED) "Remove :" $(NAME) $(_NONE)
	@/bin/rm -f $(NAME)
	@echo $(_GREEN) "DONE" $(_NONE)

re: fclean all

exe: all clean
