# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/10 11:38:26 by eleclet           #+#    #+#              #
#    Updated: 2016/03/13 19:50:23 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CFLAGS = -Werror -Wextra -Wall
CC = gcc

SRC = minishell.c lst_to_tab.c builtin.c list.c sys_utils.c ext_lst.c cd_cmd.c \
tools.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	@make -C libft/
	@gcc -c $(SRC)
	@gcc $(CFLAGS) $(OBJ) -Llibft -lft -o $(NAME)
	@echo "$(NAME) built"
clean :
	@make clean -C libft/
	@rm $(OBJ)
fclean : clean
	rm $(NAME)
re : fclean all

.PHONY: all, clean, re ,fclean
