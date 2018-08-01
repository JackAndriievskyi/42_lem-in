#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yandriie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 11:21:35 by yandriie          #+#    #+#              #
#    Updated: 2018/08/01 09:20:46 by yandriie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC_FILES = check_data.c find_fin_paths.c get_paths.c lemin.c print_ants.c set_ants.c set_next_link.c set_next_room.c sort_paths.c ut1.c ut2.c
SRC_PATH = sources/
SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ_PATH = objectives/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_FILES:.c=.o))

HDR_FILES = lemin.h
HDR_PATH = includes/
HDR = $(addprefix $(HDR_PATH), $(HDR_FILES))

LIB_NAME = libft.a
LIB_PATH = libft/
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HDR_PATH)

all: $(OBJ_PATH) $(NAME)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	make -C $(LIB_PATH) clean
	/bin/rm -fdR $(OBJ_PATH)

fclean: clean
	/bin/rm -f $(LIB)
	/bin/rm -f $(NAME)

re: fclean all