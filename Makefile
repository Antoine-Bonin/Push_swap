NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = process/
OBJ_DIR = obj/

SRCS = $(addprefix $(SRC_DIR), \
		pa_b.c \
		ra_b.c \
		rra_b.c \
		sa_b.c \
		sort.c \
		sort_large.c \
		parsing.c \
		check_param.c \
		push_swap.c)

OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

DEPS = $(LIBFT_DIR)ressource/libft.h

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)libft/*.c $(DEPS)
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all

.PHONY: all clean fclean re