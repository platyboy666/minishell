# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 17:49:32 by pkorsako          #+#    #+#              #
#    Updated: 2023/01/26 18:08:50 by pkorsako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------minishell------------------
$(NAME) = minishell
$(SRC) = 
$(OBJ) = $(SRC:.c=.o)

#--------------------libft--------------------
$(LIBFTPATH) = libft/
$(LIBFT) = libft/libft.a

#------------------headers---------------------
$(HEADER_SRC) = minitalk.h libft/libft.h
$(CC) = cc
$(CFLAGS) = -g -Wall -Wextra -Werror

#------------------rules--------------------
all: M_libft $(NAME)

M_libft:
	$(MAKE) -C $(LIBFTPATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
#	mv $(OBJ) obj

%.o: %.c $(HEADER_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	cd $(LIBFTPATH) && $(MAKE) clean

fclean: clean
	rm -f %(NAME)
	cd $(LIBFTPATH) && $(MAKE) fclean

re: fclean all

.PHONY: M_libft, clean, fclean