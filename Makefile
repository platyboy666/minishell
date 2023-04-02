SRCS = main.c\
		parsing.c\
		envp_path.c\
		cmd_utils.c\
		builtins.c\

SRCS_DIR = srcs_camille/

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

INC = inc/minishell.h



# ------------- COMPILING INFO ----------------

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = minishell


# ----------- LIBFT ----------------

LIBFT_DIR = ./lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LFLAGS = -L $(LIBFT_DIR) -lft


# ------------ COMPILING -----------------

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INC)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -lreadline -o $@



# -------------- UTILS --------------------

clean:
	rm -rfv $(OBJS_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all 
