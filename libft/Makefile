# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkorsako <pkorsako@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/20 21:27:10 by pkorsako          #+#    #+#              #
#    Updated: 2023/01/26 18:57:29 by pkorsako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = ../includes/libft.h

SRC =	ft_isalpha.c	\
		ft_isalnum.c	\
		ft_isdigit.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_tolower.c	\
		ft_toupper.c	\
		ft_memset.c		\
		ft_memcpy.c		\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memmove.c	\
		ft_strlen.c		\
		ft_bzero.c		\
		ft_atoi.c		\
		ft_strdup.c		\
		ft_strchr.c		\
		ft_striteri.c	\
		ft_strrchr.c	\
		ft_strlcat.c	\
		ft_strlcpy.c	\
		ft_strncmp.c	\
		ft_strnstr.c	\
		ft_calloc.c		\
		ft_substr.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_itoa.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putnbr_fd.c	\
		ft_split.c		\
		ft_strmapi.c	\
		ft_putendl_fd.c	\
		ft_printf.c

OBJ =	$(SRC:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

%.o	: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean	:
	rm -f *.o

fclean	: clean
	rm -f $(NAME)

re	: fclean all
