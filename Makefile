# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 17:49:32 by pkorsako          #+#    #+#              #
#    Updated: 2023/01/26 19:08:14 by pkorsako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------minishell------------------
NAME = minishell
SRC_DIR = obj/
SRC_FILE = main.c
SRC = $(addprefix$(SRC_DIR), $(SRC_FILE))
OBJ = $(SRC:.c=.o)

#--------------------libft--------------------
LIBFTPATH = libft/
LIBFT = libft/libft.a

#------------------headers---------------------
HEADER_SRC = includes/minitalk.h includes/libft.h
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

#------------------rules--------------------
all: M_libft $(NAME)

M_libft:
	$(MAKE) -C $(LIBFTPATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJ)
#	mv $(OBJ) obj

%.o: %.c $(HEADER_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd $(LIBFTPATH) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFTPATH) && $(MAKE) fclean

re: fclean all

.PHONY: M_libft, clean, fclean